bool showMenu = true;
bool bFullChecked = false;

static struct android_app* i_App = NULL;

int OpenURL(JavaVM *vm, const char* url, jobject context){
    JNIEnv* java_env = NULL;
	auto object = getJNIContext(java_env);
    jint jni_return = vm->GetEnv((void**)&java_env, JNI_VERSION_1_6);
    if (jni_return == JNI_ERR)
        return -1;

    jni_return = vm->AttachCurrentThread(&java_env, NULL);
    if (jni_return != JNI_OK)
        return -2;

    jclass native_activity_clazz = java_env->GetObjectClass(object);
    if (native_activity_clazz == NULL)
        return -3;

    jmethodID method_id = java_env->GetMethodID(native_activity_clazz, "AndroidThunkJava_LaunchURL", "(Ljava/lang/String;)V");
    if (method_id == NULL)
        return -4;
        
    jstring retStr = java_env->NewStringUTF(url);
    java_env->CallVoidMethod(i_App->activity->clazz, method_id, retStr);

    jni_return = vm->DetachCurrentThread();
    if (jni_return != JNI_OK)
        return -5;

    return 0;
}

void OpenURL(JNIEnv* env, const std::string& url) {
    g_vm->AttachCurrentThread(&env, NULL);
	
	jobject context = getJNIContext(env);
	
    // Convert the std::string to a JNI string.
    jstring jUrlString = env->NewStringUTF(url.c_str());
    
    // Get the Classes and Methods IDs.
    jclass uriClass = env->FindClass(OBFUSCATE("android/net/Uri"));
    jclass intentClass = env->FindClass(OBFUSCATE("android/content/Intent"));
    jmethodID parseMethod = env->GetStaticMethodID(uriClass, "parse", "(Ljava/lang/String;)Landroid/net/Uri;");
    jmethodID intentConstructor = env->GetMethodID(intentClass, "<init>", "(Ljava/lang/String;Landroid/net/Uri;)V");
	jclass jcContext = env->FindClass(OBFUSCATE("android/content/Context"));
    jmethodID startActivityMethod = env->GetMethodID(jcContext, "startActivity", "(Landroid/content/Intent;)V");
    
    // Check if we successfully obtained all required method and class IDs.
    if (parseMethod == nullptr || intentConstructor == nullptr || startActivityMethod == nullptr) {
        env->DeleteLocalRef(jUrlString);
        return; // Handle error.
    }

    // Parse the URL.
    jobject uriObject = env->CallStaticObjectMethod(uriClass, parseMethod, jUrlString);
    
    // Create the Intent object.
    jstring actionView = env->NewStringUTF("android.intent.action.VIEW");
    jobject intentObject = env->NewObject(intentClass, intentConstructor, actionView, uriObject);
    
    // Start the activity with the intent.
    env->CallObjectMethod(context, startActivityMethod, intentObject);
    
    // Clean up local references.
    env->DeleteLocalRef(jUrlString);
    env->DeleteLocalRef(uriObject);
    env->DeleteLocalRef(intentObject);
    env->DeleteLocalRef(actionView);
	
	g_vm->DetachCurrentThread();
}

void openURL(JNIEnv* env, jobject obj, const std::string& url) {
  // Create an Intent object
  jclass intentClass = env->FindClass("android/content/Intent");
  jmethodID intentCtor = env->GetMethodID(intentClass, "<init>", "(Ljava/lang/String;)V");
  jstring urlString = env->NewStringUTF(url.c_str());
  jobject intent = env->NewObject(intentClass, intentCtor, urlString);
  env->DeleteLocalRef(urlString);
  if (!intent) {
    env->DeleteLocalRef(intentClass);
    return; // Handle intent creation error
  }

  // Set the Intent action and data
  jclass intentClassWithFlags = env->FindClass("android/content/Intent");
  if (!intentClassWithFlags) {
    env->DeleteLocalRef(intent);
    env->DeleteLocalRef(intentClass);
    return; // Handle class not found error
  }

  jmethodID setAction = env->GetMethodID(intentClassWithFlags, "setAction", "(Ljava/lang/String;)V");
  if (!setAction) {
    env->DeleteLocalRef(intent);
    env->DeleteLocalRef(intentClass);
    env->DeleteLocalRef(intentClassWithFlags);
    return; // Handle setAction method not found error
  }

  jstring actionView = env->NewStringUTF("android.intent.action.VIEW");
  if (!actionView) {
    env->DeleteLocalRef(intent);
    env->DeleteLocalRef(intentClass);
    env->DeleteLocalRef(intentClassWithFlags);
    return; // Handle action string creation error
  }

  env->CallVoidMethod(intent, setAction, actionView);
  env->DeleteLocalRef(actionView);
  env->DeleteLocalRef(intentClassWithFlags);

  // Get the current activity (assuming the function is called from an Activity context)
  jclass activityThreadClass = env->FindClass("android/app/ActivityThread");
  jmethodID currentActivityThreadMethod = env->GetStaticMethodID(activityThreadClass, "currentActivityThread", "()Landroid/app/ActivityThread;");
  jobject activityThreadObj = env->CallStaticObjectMethod(activityThreadClass, currentActivityThreadMethod);

  // Start the activity
  jclass activityClass = env->GetObjectClass(activityThreadObj);
  if (!activityClass) {
    env->DeleteLocalRef(intent);
    return; // Handle activity class not found error
  }

  jmethodID startActivity = env->GetMethodID(activityClass, "startActivity", "(Landroid/content/Intent;)V");
  if (!startActivity) {
    env->DeleteLocalRef(intent);
    env->DeleteLocalRef(activityClass);
    return; // Handle startActivity method not found error
  }

  env->CallVoidMethod(activityThreadObj, startActivity, intent);
  env->DeleteLocalRef(intent);
  env->DeleteLocalRef(activityClass);
}

unsigned int gpCrash = 0xfa91b9cd;
static int crash(int randomval){
    volatile int *p = (int *)gpCrash;
    p += randomval;
    p += *p + randomval;
    p = 0;
    p += *p;
    return *p;
}

void CenteredText(ImColor color, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    const char *text, *text_end;
    ImFormatStringToTempBufferV(&text, &text_end, fmt, args);
    ImGui::SetCursorPosX((ImGui::GetWindowSize().x - ImGui::CalcTextSize(text, text_end).x) * 0.5);
    ImGui::TextColoredV(color, fmt, args);
    va_end(args);
}

inline ImVec4 RGBA2ImVec4(int r, int g, int b, int a) {
    float newr = (float)r / 255.0f;
    float newg = (float)g / 255.0f;
    float newb = (float)b / 255.0f;
    float newa = (float)a / 255.0f;
    return ImVec4(newr, newg, newb, newa);
}

void HideMenu(bool& bShow) {
    if (bShow) {
        ImGui::OpenPopup(OBFUSCATE("ConfirmHide"));
    }

    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    if (ImGui::BeginPopupModal(OBFUSCATE("ConfirmHide"), 0, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse))
    {
        ImGui::Text(OBFUSCATE("Are you sure you want to hide the menu?"));
        if (ImGui::Button(OBFUSCATE("Yes"), ImVec2(ImGui::GetContentRegionAvail().x / 2, 0)))
        {
            showMenu = false;
            bShow = false;
            ImGui::CloseCurrentPopup();
        }
        ImGui::SameLine();
        if (ImGui::Button(OBFUSCATE("No"), ImVec2(ImGui::GetContentRegionAvail().x, 0)))
        {
            bShow = false;
            ImGui::CloseCurrentPopup();
        }
        ImGui::EndPopup();
    }
}

void loadConfig() {
    int fd = open(OBFUSCATE("/storage/emulated/0/Android/data/com.mobile.legends/xyz.ini"), O_RDONLY);
        read(fd, &Config, sizeof(Config));
        read(fd, &Aim, sizeof(Aim));
        read(fd, &SetFieldOfView, sizeof(SetFieldOfView));
        close(fd);
}
void saveConfig(){
    int fd = open(OBFUSCATE("/storage/emulated/0/Android/data/com.mobile.legends/xyz.ini"), O_WRONLY | O_CREAT);
    system(OBFUSCATE("chmod 777 /storage/emulated/0/Android/data/com.mobile.legends/xyz.ini"));
    write(fd, &Config , sizeof(Config));
    write(fd, &Aim, sizeof(Aim));
    write(fd, &SetFieldOfView, sizeof(SetFieldOfView));
    close(fd);
}

void loadCFG(){
    loadConfig();
}
void saveCFG(){
    saveConfig();
}

struct sTheme {
    bool TemaAsik;
    bool Color;
};
sTheme Theme{0};

std::string msg;
void LoginThread(const std::string &user_key, bool *success) {
    msg = Login(g_vm, user_key.c_str(), success);
}

void DrawMenu() {
	const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
	ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(ImVec2(650, 680), ImGuiCond_FirstUseEver);

    ImGuiIO& io = ImGui::GetIO();

    static float window_scale;
    if (!window_scale) window_scale = 1.0f;
    io.FontGlobalScale = window_scale;

    static bool isLogin = false, isSave = false;
    static char s[64];
    if (isLogin && !isSave) {
        SharedPreferences sharedPref(GetJNIEnv(g_vm), OBFUSCATE("xyourzone_sharedpref"));
        SharedPreferences_Editor editor=sharedPref.edit();
        editor.putString(_enc("key"), s);
        editor.commit();
        isSave = true;
    }
	
	if (Config.MinimapIcon) {
    ImGui::SetNextWindowBgAlpha(0.9f);
    ImGui::SameLine();
    ImGui::Checkbox(OBFUSCATE("Hide Line"), &Config.HideLine);
    ImGui::BeginGroup(); {
        ImGui::BeginGroupPanel(OBFUSCATE("Minimap Settings"), ImVec2(-1.0f, 0.0f)); {
            ImGui::BeginGroupPanel(OBFUSCATE("Map Position"), ImVec2(ImGui::GetContentRegionAvail().x, 0.0f)); {
                ImGui::PushItemWidth(-1);
                ImGui::SliderFloat(OBFUSCATE("##Minimap X Position"), &StartPos.x, 10.0f, 100.0f, "%.1f");
                ImGui::PopItemWidth();
                ImGui::Spacing();
            }
            ImGui::EndGroupPanel();

            ImGui::BeginGroupPanel(OBFUSCATE("Map Size"), ImVec2(ImGui::GetContentRegionAvail().x, 0.0f)); {
                ImGui::PushItemWidth(-1);
                ImGui::SliderInt(OBFUSCATE("##Minimap Width"), &MapSize, 100.0f, 500.0f, "%.1f");
                ImGui::PopItemWidth();
                ImGui::Spacing();
            }
            ImGui::EndGroupPanel();

            ImGui::BeginGroupPanel(OBFUSCATE("Icon Size"), ImVec2(ImGui::GetContentRegionAvail().x, 0.0f)); {
                ImGui::PushItemWidth(-1);
                ImGui::SliderFloat(OBFUSCATE("##Enemy Icon Size"), &circleSize2, 20.0f, 40.0f, "%.1f");
                ImGui::PopItemWidth();
                ImGui::Spacing();
            }
            ImGui::EndGroupPanel();

            ImGui::BeginGroupPanel(OBFUSCATE("Health Circle"), ImVec2(ImGui::GetContentRegionAvail().x, 0.0f));
            {
                ImGui::PushItemWidth(-1);
                ImGui::SliderInt(OBFUSCATE("##HealthThin"), &ICHealthThin, 0, 10);
                ImGui::PopItemWidth();
                ImGui::Spacing();
            }
            ImGui::EndGroupPanel();
            ImGui::Spacing();
        }
        ImGui::EndGroupPanel();
        if (ImGui::Button(OBFUSCATE("Save Setting"), ImVec2(ImGui::GetContentRegionAvail().x / 2, 0))) {
            SharedPreferences sharedPref(GetJNIEnv(g_vm), OBFUSCATE("xyourzone_sharedpref"));
            SharedPreferences_Editor editor = sharedPref.edit();
            editor.putFloat(OBFUSCATE("StartPosX"), StartPos.x);
            editor.putFloat(OBFUSCATE("StartPosY"), StartPos.y);
            editor.putFloat(OBFUSCATE("MapSize"), MapSize);
            editor.putFloat(OBFUSCATE("ICSize"), ICSize);
            editor.putFloat(OBFUSCATE("ICHealthThin"), ICHealthThin);
            editor.commit();
        }

        ImGui::SameLine();

        if (ImGui::Button(OBFUSCATE("Load Setting"), ImVec2(ImGui::GetContentRegionAvail().x, 0))) {
            SharedPreferences sharedPref(GetJNIEnv(g_vm), OBFUSCATE("xyourzone_sharedpref"));
            StartPos.x = sharedPref.getFloat(OBFUSCATE("StartPosX"));
            StartPos.y = sharedPref.getFloat(OBFUSCATE("StartPosY"));
            MapSize = sharedPref.getFloat(OBFUSCATE("MapSize"));
            ICSize = sharedPref.getFloat(OBFUSCATE("ICSize"));
            ICHealthThin = sharedPref.getFloat(OBFUSCATE("ICHealthThin"));
        }

        if (ImGui::Button(OBFUSCATE("Restore Setting"), ImVec2(ImGui::GetContentRegionAvail().x, 0))) {
            SharedPreferences sharedPref(GetJNIEnv(g_vm), OBFUSCATE("xyourzone_sharedpref"));
            StartPos.x = 105.0f;
            StartPos.y = 0.0f;
            MapSize = 341.0f;
            ICSize = 38.0f;
            ICHealthThin = 3.0f;
        }
    }
    ImGui::EndGroup();
    ImGui::End();
}

if (ToggleRetri) {
    ImGui::SetNextWindowBgAlpha(0.9f);
    if (ImGui::Begin("Filter", 0, ImGuiWindowFlags_AlwaysAutoResize)) {
        ImGui::Checkbox(OBFUSCATE("Blue & Red"), &AutoRetribution.RedandBlue);
        ImGui::Checkbox(OBFUSCATE("Turtle & Lord"), &AutoRetribution.TurtleandLord);
        ImGui::Checkbox(OBFUSCATE("Crab"), &AutoRetribution.Crab);
        ImGui::Checkbox(OBFUSCATE("Litho"), &AutoRetribution.litho);
    }
    ImGui::End();
}

    static bool isPopUpHide = false;
    HideMenu(isPopUpHide);
    
    static bool bFlagAutoResize = true;
    static ImGuiWindowFlags window_flags;
    if (bFlagAutoResize) {
        window_flags = ImGuiWindowFlags_AlwaysAutoResize;
    } else {
        window_flags = ImGuiWindowFlags_None;
    }
    
    //if (isLogin && title == "") crash(0x3d5f);
    if (isLogin && title != "") {
        loadBattleData(battleData);
        bFullChecked = true;
    }
	
	std::string XYOURZONE;
    std::string FULLTITLE = std::string(title.c_str());
    if (!ImGui::Begin(FULLTITLE.c_str(), 0, window_flags)) {
        ImGui::End();
        return;
    }
	
    using namespace ImGui;
	ImGui::SetNextWindowSize(ImVec2((float) glWidth * 0.3f, (float) glHeight * 0.5f),ImGuiCond_Once); // 45% width 70% height
	if (!isLogin) {
        if (ImGui::BeginTabBar(OBFUSCATE("TabLogin"), ImGuiTabBarFlags_FittingPolicyScroll)) {
            if (ImGui::BeginTabItem(OBFUSCATE("Login Menu"))) {
                ImGui::BeginGroupPanel(OBFUSCATE("Please Login! (Copy Key to Clipboard)"), ImVec2(0.0f, 0.0f)); {
                    ImGui::PushItemWidth(-1);
                    ImGui::InputText(OBFUSCATE("##key"), s, sizeof s);
                    ImGui::PopItemWidth();
                    if (ImGui::Button(OBFUSCATE("Paste Key"), ImVec2(ImGui::GetContentRegionAvail().x / 2, 0))) {
                        auto key = getClipboardText(g_vm);
                        strncpy(s, key.c_str(), sizeof s);
                    }

                    ImGui::SameLine();

                    static std::string err;
                    if (ImGui::Button(OBFUSCATE("Load Saved Key"), ImVec2(ImGui::GetContentRegionAvail().x, 0))) {
                        SharedPreferences sharedPref(GetJNIEnv(g_vm), OBFUSCATE("xyourzone_sharedpref"));
                        auto key = sharedPref.getString("key");
                        strncpy(s, key.c_str(), sizeof s);
                    }

                    if (ImGui::Button(OBFUSCATE("Login"), ImVec2(ImGui::GetContentRegionAvail().x, 0))) {
                        std::thread login_thread(LoginThread, std::string(s), &isLogin);
                        login_thread.detach();
                    }
                    ImGui::TextColored(RGBA2ImVec4(255, 255, 0, 255), "%s", msg.c_str());
                    ImGui::Spacing();
                }
                ImGui::EndGroupPanel();
                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }
    } else {
		ImGui::SetNextWindowSize(ImVec2((float) glWidth * 0.3f, (float) glHeight * 0.5f),ImGuiCond_Once); // 45% width 70% height
		ImVec2 center = ImGui::GetMainViewport()->GetCenter();
		ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
        if (ImGui::BeginTabBar("Tab", ImGuiTabBarFlags_FittingPolicyScroll)) {
        	if (ImGui::BeginTabItem("Visual Menu")) {
            	if (ImGui::CollapsingHeader("ESP Player")) {
                	if (ImGui::BeginTable(OBFUSCATE("ESPPlayer"), 3)) {
                    	ImGui::TableNextColumn();	ImGui::Checkbox(OBFUSCATE(" Player Line"), &Config.ESP.Player.Line);
                        ImGui::TableNextColumn();	ImGui::Checkbox(OBFUSCATE(" Player Box"), &Config.ESP.Player.Box);
                        ImGui::TableNextColumn();	ImGui::Checkbox(OBFUSCATE(" Player Name"), &Config.ESP.Player.Name);
                        ImGui::TableNextColumn();	ImGui::Checkbox(OBFUSCATE(" Player Hero"), &Config.ESP.Player.Hero);
                        ImGui::TableNextColumn();	ImGui::Checkbox(OBFUSCATE(" Player Health"), &Config.ESP.Player.Health);
                        ImGui::TableNextColumn();	ImGui::Checkbox(OBFUSCATE(" Hero Alert"), &Config.ESP.Player.Alert);
                        ImGui::TableNextColumn();	ImGui::Checkbox(OBFUSCATE(" ESP Hero"), &Config.ESP.Player.HeroZ);
                        ImGui::TableNextColumn();	ImGui::Checkbox(OBFUSCATE(" Visible Check"), &Config.ESP.Player.Visible);
                        ImGui::TableNextColumn();	ImGui::Spacing();
                        ImGui::EndTable();
                    }
                }
                if (ImGui::CollapsingHeader("ESP Monster")) {
                	if (ImGui::BeginTable("Monster", 2)) {
                    	ImGui::TableNextColumn();	ImGui::Checkbox(OBFUSCATE("ESP Monster Round"), &Config.ESP.Monster.Rounded);
                        ImGui::TableNextColumn();	ImGui::Checkbox(OBFUSCATE("ESP Monster Health"), &Config.ESP.Monster.Health);
                        ImGui::TableNextColumn();	ImGui::Checkbox(OBFUSCATE("ESP Monster Name"), &Config.ESP.Monster.Name);
                        ImGui::TableNextColumn();	ImGui::Checkbox(OBFUSCATE("Alert Lord & Turtle"), &Config.ESP.Monster.Alert);
                        ImGui::EndTable();
                    }
                }
                if (ImGui::CollapsingHeader("Additional")) {
                	ImGui::Checkbox(OBFUSCATE("Minimap Icon"), &Config.MinimapIcon);
                    ImGui::SameLine();
                    ImGui::Checkbox("Show CD Spell", &Config.ESP.Player.CoolDown);
                    ImGui::SameLine();
                    ImGui::Checkbox("Show CD Skills", &Config.ESP.Player.CoolDown2);
				}
                if (ImGui::CollapsingHeader("Drone")) {
                 	ImGui::TextColored(ImColor(0, 255, 0, 255), ("Settings"));
                    ImGui::SliderFloat("##DroneViewHorz", &SetFieldOfView, 0, 30, "%.1f");
                }
                if (ImGui::CollapsingHeader(_enc("High Risk"))) {
                    ImGui::Spacing();
                    ImGui::Checkbox(OBFUSCATE("Unlock All Skin"), &Config.Visual.UnlockSkin);
                    ImGui::SameLine();
                    ImGui::Checkbox(OBFUSCATE("Enable Full Sight"), &Config.Visual.MapHackIcon2);
                    ImGui::SameLine();
                    //ImGui::Checkbox(OBFUSCATE("No Grass (Beta)"), &Config.Visual.NoGrass);
					ImGui::Checkbox(OBFUSCATE("Show Icon Minimap"), &Config.Visual.MaphackIcon);
                    ImGui::Checkbox(OBFUSCATE("Show Health Bar"), &Config.Visual.HealthBar);
					ImGui::SameLine();
                    ImGui::Checkbox(OBFUSCATE("Show Head Icon"), &Config.Visual.HeadIcon);
					ImGui::SameLine();
                    ImGui::Checkbox(OBFUSCATE("Show Body Only"), &Config.Visual.MapHackIcon3);
					ImGui::SameLine();
                    ImGui::Checkbox(OBFUSCATE("Show Monster Body"), &Config.Visual.ShowJungle);
				}
                ImGui::EndTabItem();
			}
            if (ImGui::BeginTabItem("Battle Menu")) {
            	if (ImGui::CollapsingHeader("Aim Skills")) {
                	if (ImGui::BeginTable(OBFUSCATE("AimSkilss"), 2)) {
                    	ImGui::TableNextColumn();
                        ImGui::Checkbox("Spell", &Aim.Helper.Skills.Spell);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox("Basic Attack", &Aim.Helper.Skills.Basic);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox("Auto Skill 1", &Aim.Helper.Skills.Skill1);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox("Auto Skill 2", &Aim.Helper.Skills.Skill2);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox("Auto Skill 3", &Aim.Helper.Skills.Skill3);
                        ImGui::TableNextColumn();
                        ImGui::Checkbox("Auto Skill 4", &Aim.Helper.Skills.Skill4);
                        ImGui::EndTable();
                    }
                    ImGui::Spacing();
                    ImGui::TextColored(ImColor(0, 255, 0, 255), OBFUSCATE("Targets"));
                 	static const char* targets[] = { OBFUSCATE("Distance"), OBFUSCATE("Low HP"), OBFUSCATE("Low HP Percent") };
                    ImGui::Combo("##Target", (int*)&Aim.Helper.Priority.Target, targets, 3, -1);
                    ImGui::Spacing();
                    ImGui::Spacing();
                    ImGui::TextColored(ImColor(0, 255, 0, 255), OBFUSCATE("Range FOV"));
                    ImGui::SliderFloat("##RangeFOV", &RangeCombo, 0, 10, "%.1fm");
                }
                if (ImGui::CollapsingHeader("Auto Retributions")) {
                    ImGui::Checkbox("Retribution", &ToggleRetri);
                    ImGui::SameLine();
                    ImGui::Checkbox(OBFUSCATE("Enemy Trigger"), &AutoTrigger.Retribution);
                    ImGui::Spacing();
                    ImGui::TextColored(ImColor(0, 255, 0, 255), OBFUSCATE("Distance Target : "));
                    ImGui::SliderFloat("##Distance", &AutoRetribution.Custom, 0, 10);
                }
				
				if (ImGui::CollapsingHeader(OBFUSCATE("Aim Predict"))) {
					Checkbox(OBFUSCATE("Active Aim Predict"), &Aim.ActivePredict);
                        
                        if (!Aim.ActivePredict) BeginDisabled();
                        
                        ImGui::SliderFloat(OBFUSCATE("Predict Speed"), &SpeedPredict, 0, 12, "%.1f");
                        SliderFloat(OBFUSCATE("Predict Range"), &RangePredict, 5, 20, "%.1f");
                        ImGui::Checkbox(OBFUSCATE("Skill 1 Predict"), &Aim.Predict.Skill1);
                        SameLine();	ImGui::Checkbox(OBFUSCATE("Skill 2 Predict"), &Aim.Predict.Skill2);
                        ImGui::Checkbox(OBFUSCATE("Skill 3 Predict"), &Aim.Predict.Skill3);
                        SameLine();	ImGui::Checkbox(OBFUSCATE("Skill 4 Predict"), &Aim.Predict.Skill4);
                        
                        if (!Aim.ActivePredict) ImGui::EndDisabled();
                }
				
                if (ImGui::CollapsingHeader(OBFUSCATE("Auto Skills (RISK)"))){
					Spacing();
                    ImGui::SliderFloat(OBFUSCATE("Speed Combo"), &speedAtt, 0, 9);
					Spacing();
					if (BeginTable(_enc("SKILLS#2"), 2)); {
						TableNextColumn();	Checkbox(OBFUSCATE("Auto Skills Kimmy (DD)"), &AutoSkills::KimmyTrigger); ImGui::SameLine();
						TableNextColumn();	Checkbox(OBFUSCATE("Auto Skills Kimmy (Creep)"), &AutoSkills::KimmyCreepTrigger); ImGui::SameLine();
						TableNextColumn();	Checkbox(OBFUSCATE("Auto Ulti Martis"), &Aim.Helper.Skills.Martis);
						TableNextColumn();	Checkbox(OBFUSCATE("Auto Skills WanWan"), &Aim.AutoSkills.WanWan);
						TableNextColumn();	Checkbox(OBFUSCATE("Auto Combo Gusion"), &AutoSkills::GusionTrigger);
						TableNextColumn();	Checkbox(OBFUSCATE("Auto Combo Paquito"), &AutoSkills::PaquitoTrigger);
						TableNextColumn();	Checkbox(OBFUSCATE("Bug Skills Atlas"), &AutoSkills::YinBugTrigger); ImGui::SameLine();
						TableNextColumn();	Checkbox(OBFUSCATE("Bug Skills Carmila"), &AutoSkills::CarmilaBug);
						TableNextColumn();	Checkbox(OBFUSCATE("Bug Skills Phoveus"), &AutoSkills::AldousBug);
						TableNextColumn();	Checkbox(OBFUSCATE("Bug Skills Khufra"), &AutoSkills::LesleyTrigger);
						TableNextColumn();	Checkbox(OBFUSCATE("Auto Combo Xavier (2+1)"), &Aim.Helper.Skills.Xavier);
						TableNextColumn();	Checkbox(OBFUSCATE("Take Sword Ling (Tap)"), &Aim.AutoTakeSword2);
						EndTable();
					}
				}
				ImGui::EndTabItem();
            }
            static int SelectInfo = 0;
            static ImGuiTableFlags flags = ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV;
            if (ImGui::BeginTabItem("Room Info")) {
                RoomInfoList();
                ImGui::RadioButton(OBFUSCATE("Versi 1"), &SelectInfo, 1);
                ImGui::SameLine();
                ImGui::RadioButton(OBFUSCATE("Versi 2"), &SelectInfo, 2);
                if (SelectInfo == 1) {
                	ImGui::TextColored(ImVec4(0.0f, 0.8f, 1.0f, 1.0f), OBFUSCATE("Team"));
                    if (ImGui::BeginTable(OBFUSCATE("##Team"), 8, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersInner)) {
                    	ImGui::TableSetupColumn(OBFUSCATE("Name"));
                        ImGui::TableSetupColumn(OBFUSCATE("ID"));
                        ImGui::TableSetupColumn(OBFUSCATE("Rank"));
                        ImGui::TableSetupColumn(OBFUSCATE("Star"));
                        ImGui::TableSetupColumn(OBFUSCATE("Hero"));
                        ImGui::TableSetupColumn(OBFUSCATE("Spell"));
                        ImGui::TableSetupColumn(OBFUSCATE("Country"));
    					ImGui::TableSetupColumn(OBFUSCATE("Status"));
                        ImGui::TableHeadersRow();
                        for (int row = 0; row < 5; row++) {
                            ImGui::TableNextRow();
                            for (int column = 0; column < 8; column++) {
                                ImGui::TableSetColumnIndex(column);
                                char buf[32];
                                if (column == 0) {
                                    sprintf(buf, "%s", RoomInfo.PlayerB[row].Name.c_str());
                                    ImGui::TextUnformatted(buf);
                                } else if (column == 1) {
                                    sprintf(buf, "%s", RoomInfo.PlayerB[row].UserID.c_str());
                                    ImGui::TextUnformatted(buf);
                                } else if (column == 2) {
                                    //RoomInfoRank(RoomInfo.PlayerB[row].uiRank);
                                    sprintf(buf, "%s", RoomInfo.PlayerB[row].Rank.c_str());
                                    ImGui::TextUnformatted(buf);
                                } else if (column == 3) {
                                    sprintf(buf, "%s", RoomInfo.PlayerB[row].Star.c_str());
                                    ImGui::TextUnformatted(buf);
                                } else if (column == 4) {
                                    RoomInfoHero(RoomInfo.PlayerB[row].HeroID);
                                } else if (column == 5) {
                                    RoomInfoSpell(RoomInfo.PlayerB[row].Spell);
                                } else if (column == 6) {
                                    sprintf(buf, "%s", RoomInfo.PlayerB[row].Country.c_str());
                                    ImGui::TextUnformatted(buf);
                                } else if (column == 7) {
                                    sprintf(buf, "%s", RoomInfo.PlayerB[row].RobotBukan.c_str());
                                    ImGui::TextUnformatted(buf);
                                }
                            }
                        }
                        ImGui::EndTable();
                    }
                    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), OBFUSCATE("Enemy"));
                    if (ImGui::BeginTable(OBFUSCATE("##Enemy"), 8, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersInner)) {
                        ImGui::TableSetupColumn(OBFUSCATE("Name"));
                        ImGui::TableSetupColumn(OBFUSCATE("ID"));
                        ImGui::TableSetupColumn(OBFUSCATE("Rank"));
                        ImGui::TableSetupColumn(OBFUSCATE("Star"));
                        ImGui::TableSetupColumn(OBFUSCATE("Hero"));
                        ImGui::TableSetupColumn(OBFUSCATE("Spell"));
                        ImGui::TableSetupColumn(OBFUSCATE("Country"));
    					ImGui::TableSetupColumn(OBFUSCATE("Status"));
                        ImGui::TableHeadersRow();
                        for (int row = 0; row < 5; row++) {
                            ImGui::TableNextRow();
                            for (int column = 0; column < 8; column++) {
                                ImGui::TableSetColumnIndex(column);
                                char buf[32];
                                if (column == 0) {
                                    sprintf(buf, "%s", RoomInfo.PlayerR[row].Name.c_str());
                                    ImGui::TextUnformatted(buf);
                                } else if (column == 1) {
                                    sprintf(buf, "%s", RoomInfo.PlayerR[row].UserID.c_str());
                                    ImGui::TextUnformatted(buf);
                                } else if (column == 2) {
                                    //RoomInfoRank(RoomInfo.PlayerR[row].uiRank);
                                    sprintf(buf, "%s", RoomInfo.PlayerR[row].Rank.c_str());
                                    ImGui::TextUnformatted(buf);
                                } else if (column == 3) {
                                    sprintf(buf, "%s", RoomInfo.PlayerR[row].Star.c_str());
                                    ImGui::TextUnformatted(buf);
                                } else if (column == 4) {
                                    RoomInfoHero(RoomInfo.PlayerR[row].HeroID);
                                } else if (column == 5) {
                                    RoomInfoSpell(RoomInfo.PlayerR[row].Spell);
                                } else if (column == 6) {
                                    sprintf(buf, "%s", RoomInfo.PlayerR[row].Country.c_str());
                                    ImGui::TextUnformatted(buf);
                                } else if (column == 7) {
                                    sprintf(buf, "%s", RoomInfo.PlayerR[row].RobotBukan.c_str());
                                    ImGui::TextUnformatted(buf);
                                }
                            }
                        }
                        ImGui::EndTable();
                    }
                 } else if(SelectInfo == 2) {
                 	if (ImGui::BeginTable(OBFUSCATE("##Team"), 5, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersInner)) {
                    	TableSetupColumn(OBFUSCATE("ELO"));
                        TableSetupColumn(OBFUSCATE("Gender"));
                        TableSetupColumn(OBFUSCATE("Level Role's"));
                        TableSetupColumn(OBFUSCATE("Level Battle"));
                        TableSetupColumn(OBFUSCATE("Party"));
                        TableHeadersRow();
                        for (int row = 0; row < 5; row++) {
                            ImGui::TableNextRow();
                            for (int column = 0; column < 5; column++) {
                                ImGui::TableSetColumnIndex(column);
                                char buf[32];
                                if (column == 0) {
                                    sprintf(buf, "%s", RoomInfo.PlayerB[row].Elo.c_str());
                                    ImGui::TextUnformatted(buf);
                                } else if (column == 1) {
                                    sprintf(buf, "%s", RoomInfo.PlayerB[row].Gender.c_str());
                                    ImGui::TextUnformatted(buf);
                                } else if (column == 2) {
                                    sprintf(buf, "%s", RoomInfo.PlayerB[row].RoleLevel.c_str());
                                    ImGui::TextUnformatted(buf);
                                } else if (column == 3) {
                                    sprintf(buf, "%s", RoomInfo.PlayerB[row].BattleCount.c_str());
                                    ImGui::TextUnformatted(buf);
                                } else if (column == 4) {
                                    sprintf(buf, "%s", RoomInfo.PlayerB[row].RoomDataIn.c_str());
                                    ImGui::TextUnformatted(buf);
                                }
                            }
                        }
                        ImGui::EndTable();
                    }
                    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), OBFUSCATE("Enemy"));
                    if (ImGui::BeginTable(OBFUSCATE("##Enemy"), 5, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersInner)) {
                    	TableSetupColumn(OBFUSCATE("ELO"));
                        TableSetupColumn(OBFUSCATE("Gender"));
                        TableSetupColumn(OBFUSCATE("Level Role's"));
                        TableSetupColumn(OBFUSCATE("Level Battle"));
                        TableSetupColumn(OBFUSCATE("Party"));
                        TableHeadersRow();
                        for (int row = 0; row < 5; row++) {
                            ImGui::TableNextRow();
                            for (int column = 0; column < 5; column++) {
                                ImGui::TableSetColumnIndex(column);
                                char buf[32];
                                if (column == 0) {
                                    sprintf(buf, "%s", RoomInfo.PlayerR[row].Elo.c_str());
                                    ImGui::TextUnformatted(buf);
                                } else if (column == 1) {
                                    sprintf(buf, "%s", RoomInfo.PlayerR[row].Gender.c_str());
                                    ImGui::TextUnformatted(buf);
                                } else if (column == 2) {
                                    sprintf(buf, "%s", RoomInfo.PlayerR[row].RoleLevel.c_str());
                                    ImGui::TextUnformatted(buf);
                                } else if (column == 3) {
                                    sprintf(buf, "%s", RoomInfo.PlayerR[row].BattleCount.c_str());
                                    ImGui::TextUnformatted(buf);
                                } else if (column == 4) {
                                    sprintf(buf, "%s", RoomInfo.PlayerR[row].RoomDataIn.c_str());
                                    ImGui::TextUnformatted(buf);
                                }
                            }
                        }
                        ImGui::EndTable();
                    }
                }
                ImGui::EndTabItem();
			}
            if (ImGui::BeginTabItem(OBFUSCATE("Setting"))) {
                ImGui::BeginGroupPanel(OBFUSCATE("Menu Setting"), ImVec2(-1.0f, 0.0f));
                {
                    ImGui::Checkbox(OBFUSCATE("Auto Resize"), &bFlagAutoResize);
                    ImGui::BeginGroupPanel(OBFUSCATE("Window Size"), ImVec2(-1.0f, 0.0f));
                    {
                        ImGui::PushItemWidth(-1);
                        ImGui::SliderFloat(OBFUSCATE("##Scale"), &window_scale, 0.5f, 2.5f, "%.1f");
                        ImGui::PopItemWidth();
                        ImGui::Spacing();
                    }
                    ImGui::EndGroupPanel();
                    
                    if (ImGui::Button(OBFUSCATE("Hide Menu"), ImVec2(ImGui::GetContentRegionAvail().x, 0))) {
                        isPopUpHide = true;
                    }

                    ImGui::BeginGroupPanel(OBFUSCATE("English"), ImVec2(-1.0f, 0.0f));
                    {
                        ImGui::TextColored(RGBA2ImVec4(255, 255, 0, 255), OBFUSCATE("To display the menu again,"));
                        ImGui::TextColored(RGBA2ImVec4(255, 255, 0, 255), OBFUSCATE("simply touch on the lower left corner of your screen."));
                        ImGui::Spacing();
                    }
                    ImGui::EndGroupPanel();

                    ImGui::BeginGroupPanel(OBFUSCATE("Indonesia"), ImVec2(-1.0f, 0.0f));
                    {
                        ImGui::TextColored(RGBA2ImVec4(255, 255, 0, 255), OBFUSCATE("Untuk menampilkan kembali menu,"));
                        ImGui::TextColored(RGBA2ImVec4(255, 255, 0, 255), OBFUSCATE("cukup sentuh di pojok kiri bawah layar Anda."));
                        ImGui::Spacing();
                    }
                    ImGui::EndGroupPanel();
                    
                    ImGui::Spacing();
                    
                    if (ImGui::Button(OBFUSCATE("Save Cheat Setting"), ImVec2(ImGui::GetContentRegionAvail().x / 2, 0))) {
                        saveCFG();
                    }
                    ImGui::SameLine();
                    if (ImGui::Button(OBFUSCATE("Load Cheat Setting"), ImVec2(ImGui::GetContentRegionAvail().x, 0))) {
                        loadCFG();
                    }
                    
                    ImGui::BeginGroupPanel(OBFUSCATE("Key Info"), ImVec2(-1.0f, 0.0f));
                    {
                        ImGui::TextColored(ImColor(0, 255, 0, 255), OBFUSCATE("Expired Date : "));
                        ImGui::SameLine();
                        ImGui::TextColored(ImColor(0, 255, 0, 255), expired.c_str());
						
                    }
                    ImGui::EndGroupPanel();
                    
                }
                ImGui::EndGroupPanel();
                ImGui::EndTabItem();
            }
        }
        ImGui::EndTabBar();
		ImGui::Separator();
        ImGui::TreePop();
	}
}

