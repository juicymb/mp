//method
/*
#define Screen_get_width (uintptr_t) Il2CppGetMethodOffset(_enc("UnityEngine.CoreModule.dll"), _enc("UnityEngine"), _enc("Display"), _enc("get_systemWidth"))
#define Screen_get_height (uintptr_t) Il2CppGetMethodOffset(_enc("UnityEngine.CoreModule.dll"), _enc("UnityEngine"), _enc("Display"), _enc("get_systemHeight"))
#define Screen_SetResolution (uintptr_t) Il2CppGetMethodOffset(_enc("UnityEngine.dll"), _enc("UnityEngine"), _enc("Screen"), _enc("SetResolution"), 3)
#define Screen_get_dpi (uintptr_t) Il2CppGetMethodOffset("UnityEngine.dll", "UnityEngine", "Screen", _enc("get_dpi"))
*/

uintptr_t Screen_get_width() {
	return (uintptr_t) Il2CppGetMethodOffset(_enc("UnityEngine.CoreModule.dll"), _enc("UnityEngine"), _enc("Display"), _enc("get_systemWidth"));
}

uintptr_t Screen_get_height() {
	return (uintptr_t) Il2CppGetMethodOffset(_enc("UnityEngine.CoreModule.dll"), _enc("UnityEngine"), _enc("Display"), _enc("get_systemHeight"));
}

uintptr_t Screen_SetResolution() {
    return (uintptr_t) Il2CppGetMethodOffset(_enc("UnityEngine.dll"), _enc("UnityEngine"), _enc("Screen"), _enc("SetResolution"), 3);
}

uintptr_t Screen_get_dpi(){
	return (uintptr_t) Il2CppGetMethodOffset(_enc("UnityEngine.dll"), _enc("UnityEngine"), _enc("Screen"), _enc("get_dpi"));
}

class Screen {
    public:
    static void SetResolution(int width, int height, bool fullscreen) {
        auto _ = reinterpret_cast<void(*)(int , int , bool )>((uintptr_t)Screen_SetResolution());
        return _(width,height,fullscreen);
    }
    static int get_width() {
        auto _ = reinterpret_cast<int(*)()>((uintptr_t)Screen_get_width());
        return _();
    }
    static int get_height() {
        auto _ = reinterpret_cast<int(*)()>((uintptr_t)Screen_get_height());
        return _();
    }
	static int get_dpi() {
        auto _ = reinterpret_cast<float(*)()>((uintptr_t)Screen_get_dpi());
        return _();
    }
};
/*
#define Camera_get_main (uintptr_t) Il2CppGetMethodOffset(_enc("UnityEngine.dll"), _enc("UnityEngine"), _enc("Camera"), _enc("get_main"))
#define Camera_WorldToScreenPoint (uintptr_t) Il2CppGetMethodOffset(_enc("UnityEngine.dll"), _enc("UnityEngine"), _enc("Camera"), _enc("WorldToScreenPoint"), 1)
#define Camera_get_fieldOfView (uintptr_t) Il2CppGetMethodOffset(_enc("UnityEngine.dll"), _enc("UnityEngine"), _enc("Camera"), _enc("get_fieldOfView"))
#define Camera_set_fieldOfView (uintptr_t) Il2CppGetMethodOffset(_enc("UnityEngine.dll"), _enc("UnityEngine"), _enc("Camera"), _enc("set_fieldOfView"), 1)
*/

uintptr_t Camera_get_main() {
    return (uintptr_t) Il2CppGetMethodOffset(_enc("UnityEngine.dll"), _enc("UnityEngine"), _enc("Camera"), _enc("get_main"));
}

// Function to replace Camera_WorldToScreenPoint
uintptr_t Camera_WorldToScreenPoint() {
    return (uintptr_t) Il2CppGetMethodOffset(_enc("UnityEngine.dll"), _enc("UnityEngine"), _enc("Camera"), _enc("WorldToScreenPoint"), 1);
}

// Function to replace Camera_get_fieldOfView
uintptr_t Camera_get_fieldOfView() {
    return (uintptr_t) Il2CppGetMethodOffset(_enc("UnityEngine.dll"), _enc("UnityEngine"), _enc("Camera"), _enc("get_fieldOfView"));
}

// Function to replace Camera_set_fieldOfView
uintptr_t Camera_set_fieldOfView() {
    return (uintptr_t) Il2CppGetMethodOffset(_enc("UnityEngine.dll"), _enc("UnityEngine"), _enc("Camera"), _enc("set_fieldOfView"), 1);
}

//Class Transform
/*
#define Transform_get_position (uintptr_t) Il2CppGetMethodOffset(_enc("UnityEngine.CoreModule.dll"), _enc("UnityEngine"), _enc("Transform"), _enc("get_position"))
#define Transform_get_localPosition (uintptr_t) Il2CppGetMethodOffset(_enc("UnityEngine.CoreModule.dll"), _enc("UnityEngine"), _enc("Transform"), _enc("get_localPosition"))
#define Transform_set_position (uintptr_t) Il2CppGetMethodOffset(_enc("UnityEngine.CoreModule.dll"), _enc("UnityEngine"), _enc("Transform"), _enc("set_position"), 1)
*/
uintptr_t Transform_get_position(){
	return (uintptr_t) Il2CppGetMethodOffset(_enc("UnityEngine.CoreModule.dll"), _enc("UnityEngine"), _enc("Transform"), _enc("get_position"));
}

uintptr_t Transform_get_localPosition(){
	return (uintptr_t) Il2CppGetMethodOffset(_enc("UnityEngine.CoreModule.dll"), _enc("UnityEngine"), _enc("Transform"), _enc("get_localPosition"));
}

uintptr_t Transform_set_position(){
	return (uintptr_t) Il2CppGetMethodOffset(_enc("UnityEngine.CoreModule.dll"), _enc("UnityEngine"), _enc("Transform"), _enc("set_position"), 1);
}

//Class Bullet
/*
#define Bullet_m_Id (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("Bullet"), _enc("m_Id"))
#define Bullet_m_Target (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("Bullet"), _enc("m_Target"))
#define Bullet_transform (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("Bullet"), _enc("transform"))
//#define EqualBulletSkillOwner (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("Bullet"), _enc("EqualBulletSkillOwner"), 1)
*/
uintptr_t Bullet_m_Id(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("Bullet"), _enc("m_Id"));
}

uintptr_t Bullet_m_Target(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("Bullet"), _enc("m_Target"));
}

uintptr_t Bullet_transform(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("Bullet"), _enc("transform"));
}

//Class LogicPlayer
uintptr_t LogicPlayer_KillWildTimes(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("LogicPlayer"), _enc("_KillWildTimes"));
}
uintptr_t LogicPlayer_m_PlayerData(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("LogicPlayer"), _enc("m_PlayerData"));
}
//#define LogicPlayer_KillWildTimes (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("LogicPlayer"), _enc("_KillWildTimes"))
//#define LogicPlayer_m_PlayerData (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("LogicPlayer"), _enc("m_PlayerData"))
#define LogicPlayer_LogicUpdate (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("LogicPlayer"), _enc("LogicUpdate"), 1)
#define LogicPlayer__QuadraKillTimes (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("LogicPlayer"), _enc("_QuadraKillTimes"))

class Transform {
public:
    Vector3 get_position() {
        auto get_position = (Vector3 (*)(Transform *)) (Transform_get_position());
        return get_position(this);
    }
    Vector3 get_localPosition() {
        auto get_localPosition = (Vector3 (*)(Transform *)) (Transform_get_localPosition());
        return get_localPosition(this);
    }
	
	void set_position(Vector3 value){
		auto set_position = (void (*)(Transform *)) (Transform_set_position());
		return set_position(this);
	}
};


//#define LogicBattleEndCtrl_get_logicBattleManager (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("LogicBattleEndCtrl"),_enc("get_logicBattleManager"))
uintptr_t LogicBattleEndCtrl_get_logicBattleManager(){
	return (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("LogicBattleEndCtrl"),_enc("get_logicBattleManager"));
}
uintptr_t LogicBattleManager_GetBattleState(){
	return (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("LogicBattleManager"), _enc("GetBattleState"));
}

uintptr_t LogicBattleManager_GetPlayerLogic() {
    return (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "LogicBattleManager", _enc("GetPlayerLogic"), 1);
}

uintptr_t LogicBattleManager_Instan() {
    return (uintptr_t) Il2CppGetStaticFieldOffset("Assembly-CSharp.dll", "", "LogicBattleManager", _enc("Instance"));
}

uintptr_t LogicBattleManager_GetPlayerRealSelf(){
	return (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("LogicBattleManager"), _enc("GetPlayerRealSelf"));
}

uintptr_t LogicBattleManager_mState(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("LogicBattleManager"), _enc("m_iMemState"));
}

uintptr_t BattleData_m_BattleBridge, BattleData_battleManager;
void loadBattleData(std::string bData) {
    if(bData == "true"){
		BattleData_m_BattleBridge = (uintptr_t) Il2CppGetStaticFieldOffset("Assembly-CSharp.dll", "", _enc("BattleData"), _enc("m_BattleBridge"));
        BattleData_battleManager = (uintptr_t) Il2CppGetStaticFieldOffset("Assembly-CSharp.dll", "", _enc("BattleData"), _enc("battleManager"));
    }
}

uintptr_t VirtualButton_m_States(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("VirtualButton"), _enc("m_States"));
}

#define ShowSelfPlayer_TryUseSkill2 (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowSelfPlayer"), _enc("TryUseSkill"), 9)
#define ShowSelfPlayer_TryUseSkill (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowSelfPlayer"), _enc("TryUseSkill"), 11)
#define ShowSelfPlayer_OnUpdate (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowSelfPlayer"), _enc("Unity_OnUpdate"),0)

uintptr_t NewSelfPlayer_OnUpdate(){
	return (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowSelfPlayer"), _enc("Unity_OnUpdate"),0);
}
uintptr_t SystemData_GetBattlePlayerInfo() {
    return (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData"), _enc("GetBattlePlayerInfo"), 0);
}

uintptr_t SystemData_m_uiID() {
    return (uintptr_t) Il2CppGetStaticFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData"), _enc("m_uiID"));
}

List<uintptr_t> *GetBattlePlayerInfo() {
    return reinterpret_cast<List<uintptr_t> *(__fastcall *)(void *)>(SystemData_GetBattlePlayerInfo())((void *)0);
}

uintptr_t RoomData_uiHeroIDChoose(){
	return (uintptr_t) Il2CppGetStaticFieldOffset(_enc("Assembly-CSharp.dll"),"", _enc("SystemData/RoomData"), _enc("uiHeroIDChoose"));
}

uintptr_t RoomData_iCertify(){
	return (uintptr_t) Il2CppGetStaticFieldOffset(_enc("Assembly-CSharp.dll"),"", _enc("SystemData/RoomData"), _enc("iCertify"));
}

uintptr_t RoomData_iCamp(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData/RoomData"), _enc("iCamp"));
}

uintptr_t SystemData_RoomData_sThisLoginCountry(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"),"", _enc("SystemData/RoomData"), _enc("sThisLoginCountry"));
}

uintptr_t SystemData_RoomData_country(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData/RoomData"), _enc("country"));
}

uintptr_t SystemData_RoomData_sCreateRoleCountry(){
	return (uintptr_t)Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData/RoomData"), _enc("sThisLoginCountry"));
}

uintptr_t SystemData_RoomData_sClientVersion(){
	return (uintptr_t)Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData/RoomData"), _enc("sClientVersion"));
}

uintptr_t SystemData_RoomData_uiSex(){
	return (uintptr_t)Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData/RoomData"), _enc("uiSex"));
}

uintptr_t SystemData_RoomData_sClientIp(){
	return (uintptr_t)Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData/RoomData"), _enc("sClientIp"));
}

uintptr_t SystemData_RoomData_iElo(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData/RoomData"), _enc("iElo"));
}

uintptr_t RoomData_uiRankLevel(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData/RoomData"), _enc("uiRankLevel"));
}

uintptr_t RoomData_iMythPoint(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData/RoomData"), _enc("iMythPoint"));
}

uintptr_t RoomData_heroid(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData/RoomData"), _enc("heroid"));
}

uintptr_t RoomData_summonSkillId(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData/RoomData"), _enc("summonSkillId"));
}

uintptr_t RoomData_lUid(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData/RoomData"), _enc("lUid"));
}

uintptr_t RoomData_uiZoneId(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData/RoomData"), _enc("uiZoneId"));
}

uintptr_t RoomData_bRobot(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData/RoomData"), _enc("bRobot"));
}

uintptr_t RoomData__steamSimpleName(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData/RoomData"), _enc("_steamSimpleName"));
}

uintptr_t RoomData__steamName(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData/RoomData"), _enc("_steamName"));
}

uintptr_t RoomData_sName(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData/RoomData"), _enc("_sName"));
}

uintptr_t SystemData_RoomData_iMPLCertifyTime(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData/RoomData"), _enc("iMPLCertifyTime"));
}

uintptr_t SystemData_RoomData_uiRoleLevel(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData/RoomData"), _enc("uiRoleLevel"));
}

uintptr_t SystemData_RoomData_uiBattleCount(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData/RoomData"), _enc("uiBattleCount"));
}

uintptr_t SystemData_RoomData_iRoomOrder(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData/RoomData"), _enc("iRoomOrder"));
}

uintptr_t RoomData_get_strName() {
    return (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("SystemData/RoomData"), _enc("get_strName"));
}

#define RoadData_iRealRoad (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "MTTDProto", "PlayerRealRoadInfo", OBFUSCATE("iRealRoad"))
#define RoadData_iTotalNum (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "MTTDProto", "PlayerRealRoadInfo", OBFUSCATE("iTotalNum"))
#define RoadData_iWinNum (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "MTTDProto", "PlayerRealRoadInfo", OBFUSCATE("iWinNum"))
#define RoomData_RoadInfo (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "", "SystemData/RoomData", OBFUSCATE("vCurSeasonRealRoadInfo"))

//-----> NEW DATA ROOM INFO <------\\

uintptr_t BattleDataByType_iTotalNum(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("MTTDProto"), _enc("BattleDataByType"), _enc("iTotalNum"));
}

uintptr_t RoomData_vCultivateRoadShow(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("SystemData/RoomData"), _enc("vCultivateRoadShow"));
}

uintptr_t CmdHeroCultivateRoadShow_iRoad(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("MTTDProto"), _enc("CmdHeroCultivateRoadShow"), _enc("iRoad"));
}

uintptr_t RecentRoadInfoSdp_iRoadLevel(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("MTTDProto"), _enc("CmdHeroCultivateRoadShow"), _enc("iRoadLevel"));
}

uintptr_t RecentRoadInfoSdp_iTitle(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("MTTDProto"), _enc("CmdHeroCultivateRoadShow"), _enc("iTitle"));
}

#define UiHeadInfo_LateUpdate (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("UIHeadInfo"), _enc("Update"))
//#define UiHeadInfo_Update (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("BattleManager"), _enc("UnityLateUpdate"))
uintptr_t BattleBridge_ShowHeadEquip(){
	return (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("BattleBridge"), _enc("ShowHeadEquip"), 3);
}

uintptr_t BattleBridge_bStartBattle(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("BattleBridge"), _enc("bStartBattle"));
}

//--------------------------------> TEST NEW MAPHACK <--------------------------------
#define MapEntityContainer_SetMapEntityIconPos (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("MapEntityContainer"), _enc("SetMapEntityIconPos"), 3)

#define BattleBridge_SetMapEntityIconPos (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("BattleBridge"), _enc("SetMapEntityIconPos"), 3)
#define BattleBridge_SetMapInvisibility (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("BattleBridge"), _enc("SetMapInvisibility"), 3)
#define BattleBridge_SetBloodInvisibility (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("BattleBridge"), _enc("SetBloodInvisibility"), 5)
//#define BattleBridge_SynBloodAttr (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("BattleBridge"), _enc("SynBloodAttr"), 2)
//#define BattleBridge_UpdateBloodPos (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("BattleBridge"), _enc("UpdateBloodPos"), 2)
uintptr_t BattleBridge_SynBloodAttr(){
	return (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("BattleBridge"), _enc("SynBloodAttr"), 2);
}
uintptr_t BattleBridge_UpdateBloodPos(){
	return (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("BattleBridge"), _enc("UpdateBloodPos"), 2);
}

uintptr_t BattleManager_m_LocalPlayerShow(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("BattleManager"), _enc("m_LocalPlayerShow"));
}

//#define BattleManager_m_LocalPlayerShow (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("BattleManager"), _enc("m_LocalPlayerShow"))
#define BattleManager_m_dicPlayerShow2 (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("BattleManager"), _enc("_dicPlayerShow"))
//#define BattleManager_m_dicMonsterShow (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("BattleManager"), _enc("_dicMonsterShow"))
uintptr_t BattleManager_m_ShowPlayers(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("BattleManager"), _enc("_showPlayers"));
}

uintptr_t BattleManager_m_ShowMonsters(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("BattleManager"), _enc("_showMonsters"));
}

//#define BattleManager_m_ShowPlayers (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("BattleManager"), _enc("_showPlayers")) //m_ShowPlayerSummons
//#define BattleManager_m_ShowMon2sters (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("BattleManager"), _enc("_showMonsters"))
//#define BattleManager_Update (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("BattleManager"), _enc("Update"))

uintptr_t BattleManager_m_dicPlayerShow() {
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("BattleManager"), _enc("_dicPlayerShow"));
}

uintptr_t BattleManager_m_dicMonsterShow() {
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("BattleManager"), _enc("_dicMonsterShow"));
}

//Class PlayerData (retri req)
uintptr_t PlayerData__killNum(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("PlayerData"), _enc("_killNum"));
}

uintptr_t PlayerData__assistNum(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("PlayerData"), _enc("_assistNum"));
}
//#define PlayerData__killNum (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("PlayerData"), _enc("_killNum"))
//#define PlayerData__assistNum (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("PlayerData"), _enc("_assistNum"))

//#define ShowMonster_m_Config (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowMonster"), _enc("m_Config"))

//Class ShowEntity
uintptr_t ShowEntity_m_States() {
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowEntity"), _enc("m_States"));
}

uintptr_t ShowEntity__Position(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowEntity"), _enc("m_vCachePosition"));
}

uintptr_t ShowEntity_getPosition(){
	return (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("get_Position"), 0);
}


//#define ShowEntity_getPosition (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("get_Position"), 0)

uintptr_t ShowEntity_MoveDir(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("_MoveDir"));
}

uintptr_t ShowEntity_ResetLayer(){
	return (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowEntity"), _enc("ResetLayer"), 1);
}

uintptr_t ShowEntity_m_id(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("m_ID"));
}

//#define ShowEntity_MoveDir (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("_MoveDir"))
//#define ShowEntity_ResetLayer (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowEntity"), _enc("ResetLayer"), 1)
#define ShowEntity_OnUpdate (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity") , _enc("Unity_OnUpdate"), 0)
#define ShowEntity_get_InTransformation (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowEntity"), _enc("get_InTransformation"))
#define ShowEntity_bShowEntityLayer (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowEntity"), _enc("bShowEntityLayer"))
#define ShowEntity_m_OwnSkillComp (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowEntity"), _enc("m_OwnSkillComp"))
#define ShowEntity_m_RoleName (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowEntity"), _enc("m_RoleName"))
#define ShowEntity_m_HeadIcon (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("m_HeadIconDefault"))
#define ShowEntity_CanSight (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("CanSight"), 1)
//class LogicEntityBase
#define LogicEntityBase_get_m_Level (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("LogicEntityBase"), _enc("m_Level"))

//#define ShowOwnSkillComp_m_SkillList (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("ShowOwnSkillComp"), _enc("m_SkillList"))
//#define ShowOwnSkillComp_skillUseTypeList (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("ShowOwnSkillComp"), _enc("skillUseTypeList"))
uintptr_t ShowOwnSkillComp_m_SkillList(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("ShowOwnSkillComp"), _enc("m_SkillList"));
}
uintptr_t ShowOwnSkillComp_skillUseTypeList(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("ShowOwnSkillComp"), _enc("skillUseTypeList"));
}

//#define ShowSkillData_m_TranID (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowSkillData"), _enc("m_TranID"))

//#define ShowPlayer_m_iSummonSkillId (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowPlayer"), _enc("m_iSummonSkillId"))

uintptr_t ShowSkillData_m_TranID(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowSkillData"), _enc("m_TranID"));
}

uintptr_t ShowPlayer_m_iSummonSkillId(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowPlayer"), _enc("m_iSummonSkillId"));
}

uintptr_t ShowPlayer_m_HeroName(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowPlayer"), _enc("m_HeroName"));
}

uintptr_t ShowPlayer_Unity_OnUpdate(){
	return (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("OnUpdate"));
}

//#define ShowPlayer_m_HeroName (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowPlayer"), _enc("m_HeroName"))
//#define ShowPlayer_m_killNum (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowPlayer"), _enc("m_killNum"))
//#define ShowPlayer_m_assistNum (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowPlayer"), _enc("m_assistNum"))
//#define ShowPlayer_m_KillWildTimes (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowPlayer"), _enc("m_KillWildTimes"))
#define ShowPlayer_m_bInBattle (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowPlayer"), _enc("m_bInBattle"))
//#define ShowPlayer__KillWildTimes (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowPlayer"), _enc("m_KillWildTimes"))

#define ShowPlayer_m_QuadraKillTimes (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowPlayer"), _enc("m_QuadraKillTimes"))
#define ShowPlayer_m_PentaKillTimes (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowPlayer"), _enc("m_PentaKillTimes"))
#define ShowPlayer_m_TripleKillTimes (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowPlayer"), _enc("m_TripleKillTimes"))

#define ShowEntityBase_m_dMoveSpeed (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("m_dMoveSpeed"))
#define EntityBase_m_iType (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("m_iType"))
/*#define EntityBase_m_bSameCampType (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("m_bSameCampType"))
#define EntityBase_m_EntityCampType (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("m_EntityCampType"))
*/
uintptr_t EntityBase_m_bSameCampType(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("m_bSameCampType"));
}

uintptr_t EntityBase_m_EntityCampType(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("m_EntityCampType"));
}

uintptr_t EntityBase_m_bDeath(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("m_bDeath"));
}

uintptr_t EntityBase_canSight(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("canSight"));
}

uintptr_t EntityBase_m_Hp(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("m_Hp"));
}

uintptr_t EntityBase_m_HpMax(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("m_HpMax"));
}

uintptr_t EntityBase_m_ID(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("m_ID"));
}

uintptr_t EntityBase_m_uGuid(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("m_uGuid"));
}

uintptr_t EntityBase_m_Level(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("m_Level"));
}

uintptr_t EntityBase_get_m_Level(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("EntityBase"), _enc("_level"));
}
/*
#define EntityBase_m_bDeath (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("m_bDeath"))
#define EntityBase_canSight (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("canSight"))
#define EntityBase_m_Hp (uintptr_t)  Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("m_Hp"))
#define EntityBase_m_HpMax (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("m_HpMax"))
#define EntityBase_m_ID (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("m_ID"))
#define EntityBase_m_uGuid (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("m_uGuid"))
#define EntityBase_m_Level (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("m_Level"))
#define EntityBase_get_m_Level (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("EntityBase"), _enc("_level"))
*/
#define ShowEntityBase_m_Mp (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("EntityBase"), _enc("<m_Mp>k__BackingField"))
#define m_dRunSpeed (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("EntityBase"), _enc("m_dRunSpeed"))
#define get_m_dAtkSpeed (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("EntityBase"), _enc("get_m_dAtkSpeed"), 0)
#define ShowEntityBase_IsCampGrassLayer (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("EntityBase"), _enc("set_m_dAtkSpeed"),1)

#define LogicFighter_m_SkillComp (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("LogicFighter"), _enc("m_SkillComp"))
#define LogicSkillComp_m_CoolDownComp (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("LogicSkillComp"), _enc("m_CoolDownComp"))

#define CoolDownComp_m_DicCoolInfo (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("CoolDownComp"), _enc("m_DicCoolInfo"))
#define CoolDownData_GetCoolTime (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("CoolDownData"), _enc("GetCoolTime"))

#define ShowWildMonster_CanSight (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowWildMonster"), _enc("CanSight"), 1)
#define ShowWildMonster_OnUpdate (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowWildMonater"), _enc("OnUpdate"))

//Unlock Skin
#define LogicFighter_m_SkillComp (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", _enc("LogicFighter"), _enc("m_SkillComp"))
#define LogicSkillComp_m_CoolDownComp (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", _enc("LogicSkillComp"), _enc("m_CoolDownComp"))
#define CoolDownComp_m_DicCoolInfo (uintptr_t) Il2CppGetFieldOffset("Assembly-CSharp.dll", "Battle", _enc("CoolDownComp"), _enc("m_DicCoolInfo"))
#define CoolDownData_GetCoolTime (uintptr_t) Il2CppGetMethodOffset("Assembly-CSharp.dll", "Battle", _enc("CoolDownData"), _enc("GetCoolTime"))

//Unlock Skin -> Mencoba
//Class//Unlock Skin -> Mencoba
#define LogicFighter__GetTotalHp (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("LogicFighter"), _enc("GetTotalHp"), 1)
#define ShowEntity_get__logicFighter (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowEntity"), _enc("get_logicFighter"))

#define CData_Monster_Element_m_ID (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("CData_Monster_Element"), _enc("m_ID"))


#define SkillComponent_m_OwnSkillDic (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("SkillComponent"), _enc("m_OwnSkillDic"))
#define SkillComponent__iSkillLearn (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("SkillComponent"), _enc("_iSkillLearn"))
#define SkillComponent_m_ComAtk (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("SkillComponent"), _enc("m_ComAtk"))

#define ShowSyncFighter_get_m_AttkSpeed (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("ShowSyncFighter"), _enc("get_m_AttkSpeed"))

void *get_main() {
    return reinterpret_cast<void *(__fastcall *)()>(Camera_get_main())();
}

float get_fieldOfView() {
    return reinterpret_cast<float(__fastcall *)(void *)>(Camera_get_fieldOfView())(get_main());
}

void *set_fieldOfView(float value) {
    return reinterpret_cast<void *(__fastcall *)(void *, float)>(Camera_set_fieldOfView())(get_main(), value);
}

Vector3 WorldToScreen(Vector3 position) {
    return reinterpret_cast<Vector3(__fastcall *)(void *, Vector3)>(Camera_WorldToScreenPoint())(get_main(), position);
}

int GetBattleState() {
	auto instance = *(uintptr_t *) ((uintptr_t)LogicBattleManager_Instan());
    if (!instance) return 0;
    return reinterpret_cast<int(__fastcall *)(void*)>(LogicBattleManager_GetBattleState())((void*)instance);
}

uintptr_t GetPlayerLogic(uint id) {
    auto instance = *(uintptr_t *) ((uintptr_t)LogicBattleManager_Instan());
    if (!instance) return 0;
    return reinterpret_cast<uintptr_t(__fastcall *)(void *, uint)>(LogicBattleManager_GetPlayerLogic())((void *)instance, id);
}

int GetCoolTime(void* instance) {
    return reinterpret_cast<int(__fastcall *)(void *)>(CoolDownData_GetCoolTime)(instance);
}

void *ShowEntity_get_logicFighter(void *instance) {
    return reinterpret_cast<void*(__fastcall *)(void *)>(ShowEntity_get__logicFighter)(instance);
}

bool get_InTransformation(void* instance) {
    return reinterpret_cast<bool(__fastcall *)(void *)>(ShowEntity_get_InTransformation)(instance);
}

uintptr_t GetPlayerRealSelf() {
    void* instance;
    Il2CppGetStaticFieldValue(_enc("Assembly-CSharp.dll"), _enc(""), _enc("LogicBattleManager"), _enc("Instance"), &instance);
    if (instance == NULL) return 0;
    return reinterpret_cast<uintptr_t(__fastcall *)(void *)>(LogicBattleManager_GetPlayerRealSelf())((void *)instance);
}

Vector3 ShowEntity_get_Position(void *instance) {
    return reinterpret_cast<Vector3(__fastcall *)(void *)>(ShowEntity_getPosition())(instance);
}

Vector3 ShowEntity_GetPosition(void *uiy) {
	return reinterpret_cast<Vector3(__fastcall *)(void *)>(ShowEntity_getPosition())(uiy);
}

void *iLogicBattleManager(void *instance) {
    return reinterpret_cast<void * (__fastcall *)(void *)>(LogicBattleEndCtrl_get_logicBattleManager())(instance);
}

Dictionary<void*, void*> *get_Players(){
	return reinterpret_cast<Dictionary<void*, void*> *(*)()>(BattleManager_m_dicPlayerShow())();
}

Dictionary<void*, void*> *get_Monsters(){
	return reinterpret_cast<Dictionary<void*, void*> *(*)()>(BattleManager_m_dicMonsterShow())();
}

#define AntiCheatReporter_StartBattle (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("AntiCheatReporter"), _enc("StartBattle"))
#define AntiCheatReporter_EndBattle (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("AntiCheatReporter"), _enc("EndBattle"))
#define AntiCheatReporter_OnReleaseUseSkill (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("AntiCheatReporter"), _enc("OnReleaseUseSkill"), 1)
#define AntiCheatReporter_OnTryUseSkill (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("AntiCheatReporter"), _enc("OnTryUseSkill"), 2)
#define AntiCheatReporter_OnTryUseSkill2 (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("AntiCheatReporter"), _enc("OnTryUseSkill"), 3)

#define AntiCheatReporter_OnRequestSkillMsg (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("AntiCheatReporter"), _enc("OnRequestSkillMsg"), 2)
#define AntiCheatReporter_HasSkillInfo (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("AntiCheatReporter"), _enc("HasSkillInfo"))
#define AntiCheatReporter_ReportSkillInfo (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("AntiCheatReporter"), _enc("ReportSkillInfo"), 1)

#define AntiCheatReporter_ctor (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("AntiCheatReporter"), _enc(".ctor"))
#define AntiCheatReporter_cctor (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("AntiCheatReporter"), _enc(".cctor"))

#define TestCase_gp_start_anti_cheat (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc("testinterval"), _enc("TestCase"), _enc("gp_start_anti_cheat"))
#define DeviceUtil_GetRefreshRate (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("DeviceUtil"), _enc("GetRefreshRate"))
#define DeviceUtil_GetIsRoot (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("DeviceUtil"), _enc("GetIsRoot"))
#define DeviceUtil_OpenURL (uintptr_t) Il2CppGetMethodOffset(_enc("UnityEngine.CoreModule.dll"), _enc(""), _enc("Application"), _enc("OpenURL"), 1)
#define Cheat_Start (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("Cheat"), _enc("Start"))
#define Cheat_Apply (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc(""), _enc("Cheat"), _enc("Apply"))

#define ShowEntity_ResetLayer (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowEntity"), _enc("ResetLayer"), 1)
#define ShowEntityUpdateEyeLayer (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowEntity"),_enc("UpdateEyeLayer"), 3)
#define ShowEntity_InitSetEye (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowEntity"),_enc("InitSetEye"), 2)

#define BattleBridge_OnSignReport (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("BattleBridge"), _enc("OnSignReport"), 8)
#define BattleBridge_SafeSendGameReportData (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("BattleBridge"), _enc("SafeSendGameReportData"), 1)
#define BattleBridge_SendGameReportData (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("BattleBridge"), _enc("SendGameReportData"), 1)
#define BattleBridge_SendLargeGameReportData (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("BattleBridge"), _enc("SendLargeGameReportData"), 1)

//CLASS APK SIGNATURE
#define APKSignature_GetAPKSignature (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("APKSignature"), _enc("GetAPKSignature"), 0)
#define APKSignature_IsSignatureSame (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("APKSignature"), _enc("IsSignatureSame"), 1)
#define APKSignature_SetAPKSignature (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("APKSignature"), _enc("SetAPKSignature"), 1)
#define APKSignature_GetSignature (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("APKSignature"), _enc("GetSignature"), 1)
#define APKSignature_GetApplicationClassName (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("APKSignature"), _enc("GetApplicationClassName"), 0)

#define LuaHelper_SaveActivityClientInfo (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("LuaHelper"), _enc("SaveActivityClientInfo"), 3)
#define GameReportMgr_Report_client_match_box (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("GameReportMgr"), _enc("Report_client_match_box"), 10)

//Class UIRankHero.ChangeShow
#define RunSpeedTest (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowSyncFighter"), _enc("<m_RunSpeed>k__BackingField"))
//--------------------------------> TEST NEW ANTICHEATS <--------------------------------
//--------------------------------> TEST NEW ANTICHEATS <--------------------------------
//--------------------------------> TEST NEW ANTICHEATS <--------------------------------
#define ACInterface_GetTimeOfDay (uintptr_t) Il2CppGetMethodOffset(_enc("Assebly-CSharp.dll"), "", _enc("ACInterface"), _enc("GetTimeOfDay"), 4)
#define ACInterface_GetSystemTime (uintptr_t) Il2CppGetMethodOffset(_enc("Assebly-CSharp.dll"), "", _enc("ACInterface"), _enc("GetSystemTime"), 2)
#define ACInterface_EstimateGetTimeOfDay (uintptr_t) Il2CppGetMethodOffset(_enc("Assebly-CSharp.dll"), "", _enc("ACInterface"), _enc("EstimateGetTimeOfDay"), 1)
#define ACInterface_EstimateGetSystemTime (uintptr_t) Il2CppGetMethodOffset(_enc("Assebly-CSharp.dll"), "", _enc("ACInterface"), _enc("EstimateGetSystemTime"), 1)
#define ACInterface_LoadCert (uintptr_t) Il2CppGetMethodOffset(_enc("Assebly-CSharp.dll"), "", _enc("ACInterface"), _enc("LoadCert"), 2)
#define ACInterface_GetSign (uintptr_t) Il2CppGetMethodOffset(_enc("Assebly-CSharp.dll"), "", _enc("ACInterface"), _enc("GetSign"))
#define ACInterface_ValidateCer (uintptr_t) Il2CppGetMethodOffset(_enc("Assebly-CSharp.dll"), "", _enc("ACInterface"), _enc("ValidateCer"), 1)
#define ACInterface_GetSignMapData (uintptr_t) Il2CppGetMethodOffset(_enc("Assebly-CSharp.dll"), "", _enc("ACInterface"), _enc("GetSignMapData"))
#define ACInterface_SignErrorVerify (uintptr_t) Il2CppGetMethodOffset(_enc("Assebly-CSharp.dll"), "", _enc("ACInterface"), _enc("SignErrorVerify"), 2)
#define ACInterface_CheckHook (uintptr_t) Il2CppGetMethodOffset(_enc("Assebly-CSharp.dll"), "", _enc("ACInterface"), _enc("CheckHook"))
#define ACInterface_GetHeroDefaultSkinMd5 (uintptr_t) Il2CppGetMethodOffset(_enc("Assebly-CSharp.dll"), "", _enc("ACInterface"), _enc("GetHeroDefaultSkinMd5"))

#define ShowBattleControl_SetAntiCheatReport (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowBattleControl"), _enc("SetAntiCheatReport"), 1)


uintptr_t ShowAutoAtkAIComp_m_uiFirstTargetId(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("ShowAutoAtkAIComp"), _enc("m_uiFirstTargetId"));
}

uintptr_t SkillIndicatorComp_m_uFirstTarget(){
	return (uintptr_t) Il2CppGetFieldOffset(_enc("Assembly-CSharp.dll"), "", _enc("SkillIndicatorComp"), _enc("m_uFirstTarget"));
}

#define ShowUnitAIComp_TryUseSkill (uintptr_t) Il2CppGetMethodOffset(_enc("Assembly-CSharp.dll"), _enc("Battle"), _enc("ShowUnitAIComp"), _enc("TryUseSkill"), 14)
