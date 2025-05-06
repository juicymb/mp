#pragma once

#include <sstream>
#include <iomanip>

std::string strRank[] = {
    "Warrior III * 1",
    "Warrior III * 2",
    "Warrior III * 3",
    "Warrior II * 0",
    "Warrior II * 1",
    "Warrior II * 2",
    "Warrior II * 3",
    "Warrior I * 0",
    "Warrior I * 1",
    "Warrior I * 2",
    "Warrior I * 3",
    "Elite III * 0",
    "Elite III * 1",
    "Elite III * 2",
    "Elite III * 3",
    "Elite III * 4",
    "Elite II * 0",
    "Elite II * 1",
    "Elite II * 2",
    "Elite II * 3",
    "Elite II * 4",
    "Elite I * 0",
    "Elite I * 1",
    "Elite I * 2",
    "Elite I * 3",
    "Elite I * 4",
    "Master IV * 0",
    "Master IV * 1",
    "Master IV * 2",
    "Master IV * 3",
    "Master IV * 4",
    "Master III * 0",
    "Master III * 1",
    "Master III * 2",
    "Master III * 3",
    "Master III * 4",
    "Master II * 0",
    "Master II * 1",
    "Master II * 2",
    "Master II * 3",
    "Master II * 4",
    "Master I * 0",
    "Master I * 1",
    "Master I * 2",
    "Master I * 3",
    "Master I * 4",
    "Grandmaster V * 0",
    "Grandmaster V * 1",
    "Grandmaster V * 2",
    "Grandmaster V * 3",
    "Grandmaster V * 4",
    "Grandmaster V * 5",
    "Grandmaster IV * 0",
    "Grandmaster IV * 1",
    "Grandmaster IV * 2",
    "Grandmaster IV * 3",
    "Grandmaster IV * 4",
    "Grandmaster IV * 5",
    "Grandmaster III * 0",
    "Grandmaster III * 1",
    "Grandmaster III * 2",
    "Grandmaster III * 3",
    "Grandmaster III * 4",
    "Grandmaster III * 5",
    "Grandmaster II * 0",
    "Grandmaster II * 1",
    "Grandmaster II * 2",
    "Grandmaster II * 3",
    "Grandmaster II * 4",
    "Grandmaster II * 5",
    "Grandmaster I * 0",
    "Grandmaster I * 1",
    "Grandmaster I * 2",
    "Grandmaster I * 3",
    "Grandmaster I * 4",
    "Grandmaster I * 5",
    "Epic V * 0",
    "Epic V * 1",
    "Epic V * 2",
    "Epic V * 3",
    "Epic V * 4",
    "Epic V * 5",
    "Epic IV * 0",
    "Epic IV * 1",
    "Epic IV * 2",
    "Epic IV * 3",
    "Epic IV * 4",
    "Epic IV * 5",
    "Epic III * 0",
    "Epic III * 1",
    "Epic III * 2",
    "Epic III * 3",
    "Epic III * 4",
    "Epic III * 5",
    "Epic II * 0",
    "Epic II * 1",
    "Epic II * 2",
    "Epic II * 3",
    "Epic II * 4",
    "Epic II * 5",
    "Epic I * 0",
    "Epic I * 1",
    "Epic I * 2",
    "Epic I * 3",
    "Epic I * 4",
    "Epic I * 5",
    "Legend V * 0",
    "Legend V * 1",
    "Legend V * 2",
    "Legend V * 3",
    "Legend V * 4",
    "Legend V * 5",
    "Legend IV * 0",
    "Legend IV * 1",
    "Legend IV * 2",
    "Legend IV * 3",
    "Legend IV * 4",
    "Legend IV * 5",
    "Legend III * 0",
    "Legend III * 1",
    "Legend III * 2",
    "Legend III * 3",
    "Legend III * 4",
    "Legend III * 5",
    "Legend II * 0",
    "Legend II * 1",
    "Legend II * 2",
    "Legend II * 3",
    "Legend II * 4",
    "Legend II * 5",
    "Legend I * 0",
    "Legend I * 1",
    "Legend I * 2",
    "Legend I * 3",
    "Legend I * 4",
    "Legend I * 5",
    
};

std::string SplitGrade(const int uiRankLevel){
    if (uiRankLevel <= 136) {
        std::string rankWithStars = strRank[uiRankLevel];
        std::size_t starPos = rankWithStars.find('-');
        if (starPos != std::string::npos) {
            std::string Rowgrade = rankWithStars.substr(starPos + 2);
            std::size_t awd = Rowgrade.find('*');
            std::string grade = Rowgrade.substr(0, awd - 1);
            return grade;
        }
    }
    if(uiRankLevel > 136){
        int Star = uiRankLevel - 136;
        if ((int)Star > 24)  return "Honor";
        if ((int)Star > 49)  return "Glory";
        if ((int)Star > 99)  return "Immortal";
    }
}

std::tuple<std::string, std::string> SplitRankAndStars(const int uiRankLevel, const int iMythPoint) {
    if (uiRankLevel <= 136) {
        std::string rankWithStars = strRank[uiRankLevel];
        std::size_t starPos = rankWithStars.find('*');
        if (starPos != std::string::npos) {
            std::string rankName = rankWithStars.substr(0, starPos - 1);
            std::string starCount = rankWithStars.substr(starPos + 2);
            return std::make_tuple(rankName, starCount);
        }
    }
    std::string nameMythic = "Mythic";
    if(uiRankLevel > 136){
        float starMythic = (float)iMythPoint * (50.0 / 600.0);
        int Star = uiRankLevel - 136;
        if ((int)Star > 24)  nameMythic = "Mythical Honor";
        if ((int)Star > 49)  nameMythic = "Mythical Glory";
        if ((int)Star > 99)  nameMythic = "Mythical Immortal";
        return std::make_tuple(nameMythic, std::to_string(Star));
    }
}

std::string VerifiedToString(int iCertify) {
    std::string str = std::string("-");
    if (iCertify == 0) {
        str = std::string("No");
    } else {
        str = std::string("Yes");
    }
    return str;
}

std::string GenderToString(int sGender){
    std::string str = std::string("-");
    if (sGender == 0){
        str = std::string("Hidden");
    } else if (sGender == 1){
        str = std::string("Male");
    } else if (sGender == 2){
        str = std::string("Female");
    } else {
        str = std::string("No Sett");
    }
    return str;
}

std::string RoomInfoToString(int iRoomOrder){
    std::string str = std::string("-");
    if (iRoomOrder == 0) {
        str = std::string("0");
    } else if (iRoomOrder == 1){
        str = std::string("Solo");
    } else if (iRoomOrder == 2){
        str = std::string("Duo");
    } else if (iRoomOrder == 3){
        str = std::string("Trio");
    } else if (iRoomOrder == 4){
        str = std::string("Fourth");
    } else if (iRoomOrder == 5){
        str = std::string("Full");
    } else {
        str = std::string("Undifined");
    }
}

const char ascii_hex_4bit[23] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0, 10, 11, 12, 13, 14, 15};

static inline char to_upper(char c)
{
    if ((c >= 'a') && (c <= 'z')) return c ^ 0x20;
    return c;
}

char * urldecode(const char * str)
{
    size_t i, j, len = strlen(str);
    char c, d, url_hex;
    char * decoded = (char*)malloc(len + 1);
    if (decoded == NULL) return NULL;
    i = 0;
    j = 0;
    do {
        c = str[i];
        d = 0;
        if (c == '%') {
            url_hex = to_upper(str[++i]);
            if (((url_hex >= '0') && (url_hex <= '9')) || ((url_hex >= 'A') && (url_hex <= 'F'))) {
                d = ascii_hex_4bit[url_hex - 48] << 4;

                url_hex = to_upper(str[++i]);
                if (((url_hex >= '0') && (url_hex <= '9')) || ((url_hex >= 'A') && (url_hex <= 'F'))) {
                    d |= ascii_hex_4bit[url_hex - 48];
                } else {
                    d = 0;
                }
            }
        }
        else if (c == '+') {
            d = ' ';
        }
        else if ((c == '*') || (c == '-') || (c == '.') || ((c >= '0') && (c <= '9')) || ((c >= 'A') && (c <= 'Z')) || (c == '_')  || ((c >= 'a') && (c <= 'z'))) {
            d = c;
        }
        decoded[j++] = d;
        ++i;
    } while ((i < len) && (d != 0));

    decoded[j] = 0;
    return decoded;
}

std::string GetNickName(std::string UserId, std::string ZoneId)
{
    std::string Result = "Connecting...";
    struct MemoryStruct chunk {};
    chunk.memory = (char*)malloc(1);
    chunk.size = 0;

    CURL * curl = curl_easy_init();
    if (curl != NULL) {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_URL, "https://order-sg.codashop.com/initPayment.action");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");

        struct curl_slist * headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, "Origin: https://www.codashop.com");
        headers = curl_slist_append(headers, "Referer: https://www.codashop.com/");
        headers = curl_slist_append(headers, "User-Agent: Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/102.0.5005.63 Mobile Safari/537.36");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        std::string PostData = "{\"voucherPricePoint.id\": \"27670\", \"voucherPricePoint.price\": \"242535.0\", \"voucherPricePoint.variablePrice\": \"0\", \"n\": \"12/7/2022-2046\", \"email\": \"\", \"userVariablePrice\": \"0\", \"order.data.profile\": \"eyJuYW1lIjoiICIsImRhdGVvZmJpcnRoIjoiIiwiaWRfbm8iOiIifQ==\", \"user.userId\": \"" + UserId + "\", \"user.zoneId\": \"" + ZoneId + "\", \"msisdn\": \"\", \"voucherTypeName\": \"MOBILE_LEGENDS\", \"shopLang\": \"id_ID\", \"voucherTypeId\": \"5\", \"gvtId\": \"19\", \"checkoutId\": \"\", \"affiliateTrackingId\": \"\", \"impactClickId\": \"\", \"anonymousId\": \"\"}";

        curl_easy_setopt(curl, CURLOPT_POST, true);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, PostData.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&chunk);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        CURLcode res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            try {
                json Response = json::parse(chunk.memory);
                if (Response["success"]) {
                    std::string Encrypt = Response["confirmationFields"]["username"].get<std::string>();
                    Result = urldecode(Encrypt.c_str());
                }
            } catch (json::exception & e) {
            }
        }
    }
    curl_easy_cleanup(curl);

    return Result;
}

const char * TextFormat(const char * Str, ...)
{
    char buf[10000] = { 0 };
    va_list arg;
    va_start(arg, Str);
    vsprintf(buf, Str, arg);
    va_end(arg);
    return buf;
}

std::string Nick[10];

void * DoThreadGetNickName(void*)
{
    List<uintptr_t> *m_RoomPlayerInfo = GetBattlePlayerInfo();
    if (!m_RoomPlayerInfo) nullptr;
    for (int i = 0; i < m_RoomPlayerInfo->getSize(); i++) {
        auto roomData = m_RoomPlayerInfo->getItems()[i];
        if (roomData != NULL) {
            auto lUid = *(int *) ((uintptr_t)roomData + RoomData_lUid());
            auto uiZoneId = *(int *) ((uintptr_t)roomData + RoomData_uiZoneId());
			if (lUid < 9999){
				if (uiZoneId < 999){
					Nick[i] = "Server Bot";
				}
			}
            Nick[i] = GetNickName(TextFormat("%d", lUid), TextFormat("%d", uiZoneId));
        }
    }
    pthread_exit(nullptr);
    return nullptr;
}
//end name

struct PlayerData {
    std::string Name;
    std::string UserID;
    std::string Verified;
    std::string Rank;
    std::string Star;
    std::string grade;
    int uiRank;
    int HeroID;
    int Spell;
    int Country;
    std::string Version;
    std::string Gender;
    std::string Elo;
    std::string MPL;
    std::string Ip;
    std::string RoleLevel;
    std::string BattleCount;
    std::string RoomDataIn;
	std::string RobotBukan;
	std::string Winrate;
	
	std::string LastHero;
	std::string PlayedHero;
	std::string TotalMatches;
	std::string TotalWin;
};

struct {
    PlayerData PlayerB[10];
    PlayerData PlayerR[10];
} RoomInfo;

static bool InitializeNick = false;

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision

// ... (Your other includes and definitions)

void RoomInfoList() {
    auto iBattleState = GetBattleState();
    if (iBattleState == 2 || iBattleState == 3) {
		
		if (InitializeNick == false) {
            pthread_t thread;
            pthread_create(&thread, NULL, DoThreadGetNickName, NULL);
            InitializeNick = true;
        }
		
        List<uintptr_t> *m_RoomPlayerInfo = GetBattlePlayerInfo();
        if (!m_RoomPlayerInfo) return;
        int PlayerB = 0, PlayerR = 0, iSelfCamp = 1;
        int m_uiID = *(int *)(SystemData_m_uiID());
        for (int i = 0; i < m_RoomPlayerInfo->getSize(); i++) {
            auto roomData = m_RoomPlayerInfo->getItems()[i];
            if (!roomData) continue;
            auto iCamp = *(int *) ((uintptr_t)roomData + RoomData_iCamp());
            auto lUid = *(int *) ((uintptr_t)roomData + RoomData_lUid());
            if (lUid != m_uiID) continue;
            iSelfCamp = iCamp;
            break;
        }
        for (int i = 0; i < m_RoomPlayerInfo->getSize(); i++) {
            auto roomData = m_RoomPlayerInfo->getItems()[i];
            if (!roomData) continue;
            auto iCamp = *(int *) ((uintptr_t)roomData + RoomData_iCamp());
            auto lUid = *(int *) ((uintptr_t)roomData + RoomData_lUid());
            auto uiZoneId = *(int *) ((uintptr_t)roomData + RoomData_uiZoneId());
            auto heroid = *(int *) ((uintptr_t)roomData + RoomData_heroid());
            auto uiHeroIDChoose = *(int *) ((uintptr_t)roomData + RoomData_uiHeroIDChoose());
            auto summonSkillId = *(int *) ((uintptr_t)roomData + RoomData_summonSkillId());
            auto *_sName = *(String **) ((uintptr_t)roomData + RoomData_sName());
			auto *StrName = *(String **) ((uintptr_t)roomData + RoomData_get_strName());
            auto iCertify = *(int *) ((uintptr_t)roomData + RoomData_iCertify());
            auto uiRankLevel = *(int *) ((uintptr_t)roomData + RoomData_uiRankLevel());
            auto iMythPoint = *(int *) ((uintptr_t)roomData + RoomData_iMythPoint());
            auto splitRank = SplitRankAndStars(uiRankLevel, iMythPoint);
            std::string rankName = std::get<0>(splitRank);
            std::string starCount = std::get<1>(splitRank);
            auto Grade = SplitGrade(uiRankLevel);
            auto country2 = *(String **)((uintptr_t)roomData + SystemData_RoomData_sCreateRoleCountry());
			auto Country2 = *(int *) ((uintptr_t)roomData + SystemData_RoomData_country());
            auto clientVersion = *(String **)((uintptr_t)roomData + SystemData_RoomData_sClientVersion());
            auto gender = *(int *) ((uintptr_t)roomData + SystemData_RoomData_uiSex());
            auto mpl = *(int *) ((uintptr_t)roomData + SystemData_RoomData_iMPLCertifyTime());
            auto elo = *(int *) ((uintptr_t)roomData + SystemData_RoomData_iElo());
            //auto clientIp = *(String **)((uintptr_t)roomData + FightPlayerData_sClientIp());  
            auto roleLevel = *(int *)((uintptr_t)roomData + SystemData_RoomData_uiRoleLevel());
            auto battleCount = *(int *)((uintptr_t)roomData + SystemData_RoomData_uiBattleCount());
            auto iRoomOrder = *(int *)((uintptr_t)roomData + SystemData_RoomData_iRoomOrder());
			iRobotBukan = *(bool *)((uintptr_t)roomData + RoomData_bRobot());
			List<uintptr_t> *RoadInfos = *(List<uintptr_t> **)((uintptr_t)roomData + RoomData_RoadInfo);
			
            if (iCamp == iSelfCamp) {
                RoomInfo.PlayerB[PlayerB].UserID = to_string(lUid) + " (" + to_string(uiZoneId) + ")";
				if (StrName) RoomInfo.PlayerB[PlayerB].Name = StrName->toString();
                RoomInfo.PlayerB[PlayerB].Name = Nick[i].c_str();
                RoomInfo.PlayerB[PlayerB].Rank = rankName;
                RoomInfo.PlayerB[PlayerB].Star = starCount;
                RoomInfo.PlayerB[PlayerB].Verified = VerifiedToString(iCertify);
                RoomInfo.PlayerB[PlayerB].HeroID = (uiHeroIDChoose) ? uiHeroIDChoose : heroid;
                RoomInfo.PlayerB[PlayerB].Spell = summonSkillId;
                RoomInfo.PlayerB[PlayerB].uiRank = uiRankLevel;
                RoomInfo.PlayerB[PlayerB].grade = Grade;
                RoomInfo.PlayerB[PlayerB].Gender = GenderToString(gender);
                RoomInfo.PlayerB[PlayerB].RoleLevel = to_string(roleLevel);
                RoomInfo.PlayerB[PlayerB].BattleCount = to_string(battleCount);
                RoomInfo.PlayerB[PlayerB].RoomDataIn = to_string(iRoomOrder);
				RoomInfo.PlayerB[PlayerB].RobotBukan = iRobotBukan;
				//RoomInfo.PlayerB[PlayerB].Ip = clientIp->toString();
				
				if (iRobotBukan == true){
					RoomInfo.PlayerB[PlayerB].RobotBukan = "Bot";
				} else if (iRobotBukan == false) {
					RoomInfo.PlayerB[PlayerB].RobotBukan = "Players";
				} else {
					RoomInfo.PlayerB[PlayerB].RobotBukan = "Undefined";
				}
				RoomInfo.PlayerB[PlayerB].Country = Country2;
                
                if (clientVersion) {
                    RoomInfo.PlayerB[PlayerB].Version = clientVersion->toString();
                }
                        
                RoomInfo.PlayerB[PlayerB].Elo = to_string(elo);
                RoomInfo.PlayerB[PlayerB].MPL = to_string(mpl);
                /*if (clientIp) {
                    RoomInfo.PlayerB[PlayerB].Ip = clientIp->toString();
                }*/
				RoomInfo.PlayerB[PlayerB].Winrate = "No Data";
				RoomInfo.PlayerB[PlayerB].TotalMatches = "Undefined";
				RoomInfo.PlayerB[PlayerB].TotalWin = "Undefined";
				
				if (RoadInfos) {
                    for (int ii = 0; ii < RoadInfos->getSize(); ii++) {
                        auto roadData = RoadInfos->getItems()[ii];
                        if (!roadData) continue;
                        auto iTotalNum = *(int *)((uintptr_t)roadData + RoadData_iTotalNum);
                        auto iWinNum = *(int *)((uintptr_t)roadData + RoadData_iWinNum);
                        if (iTotalNum > 0) {
                            float winrate = ((float)iWinNum / iTotalNum) * 100;
                            std::stringstream stream;
                            stream << std::fixed << std::setprecision(2) << winrate;
                            RoomInfo.PlayerB[PlayerB].Winrate = stream.str() + "%";
							RoomInfo.PlayerB[PlayerB].TotalMatches = to_string(iWinNum + iTotalNum);
							RoomInfo.PlayerB[PlayerB].TotalWin = to_string(iWinNum);
                        }
                    }
                }
				/*
                if (RoadInfos) {
                    for (int ii = 0; ii < RoadInfos->getSize(); ii++) {
                        auto roadData = RoadInfos->getItems()[ii];
                        if (!roadData) continue;
                        auto iTotalNum = *(int *)((uintptr_t)roadData + RoadData_iTotalNum);
                        auto iWinNum = *(int *)((uintptr_t)roadData + RoadData_iWinNum);
                        if (iTotalNum > 0) {
                            float winrate = (iWinNum / iTotalNum) * 100;
                            std::stringstream stream;
                            stream << std::fixed << winrate;
							//stream << winrate
                            RoomInfo.PlayerB[PlayerB].Winrate = stream.str() + "%";
							RoomInfo.PlayerB[PlayerB].TotalMatches = to_string(iTotalNum);
							RoomInfo.PlayerB[PlayerB].TotalWin = to_string(iWinNum);
                        }
                    }
                }*/
				/*
				RoomInfo.PlayerB[PlayerB].LastHero = "No Data";
				RoomInfo.PlayerB[PlayerB].PlayedHero = "No Data";
				
				if (RecentRoadInfo){
					for (int i = 0; i < RoadInfos->getSize(); i++){
						auto recentRoadInfo = RoadInfos->getItems()[i];
						if (!recentRoadInfo) continue;
						
						auto iTotalNum = *(int *)((uintptr_t)recentRoadInfo + RoadData_iTotalNum());
						auto heroIds = *(int *)((uintptr_t)recentRoadInfo + RoomData_heroid());
						auto battleNum = *(int *)((uintptr_t)recentRoadInfo + RoadData_iBattleNum());
						
						if (iTotalNum > 0){
							RoomInfo.PlayerB[PlayerB].LastHero = to_string(heroIds);
							RoomInfo.PlayerB[PlayerB].PlayedHero = to_string(battleNum);
						}
					}
				}*/
				
                PlayerB++;
            } else {
                RoomInfo.PlayerR[PlayerR].UserID = to_string(lUid) + " (" + to_string(uiZoneId) + ")";
                if (StrName) RoomInfo.PlayerR[PlayerR].Name = StrName->toString();
                RoomInfo.PlayerR[PlayerR].Name = Nick[i].c_str();
                RoomInfo.PlayerR[PlayerR].Rank = rankName;
                RoomInfo.PlayerR[PlayerR].Star = starCount;
                RoomInfo.PlayerR[PlayerR].Verified = VerifiedToString(iCertify);
                RoomInfo.PlayerR[PlayerR].HeroID = (uiHeroIDChoose) ? uiHeroIDChoose : heroid;
                RoomInfo.PlayerR[PlayerR].Spell = summonSkillId;
                RoomInfo.PlayerR[PlayerR].uiRank = uiRankLevel;
                RoomInfo.PlayerR[PlayerR].grade = Grade;
                RoomInfo.PlayerR[PlayerR].RoleLevel = to_string(roleLevel);
                RoomInfo.PlayerR[PlayerR].BattleCount = to_string(battleCount);
                RoomInfo.PlayerR[PlayerR].RoomDataIn = to_string(iRoomOrder);
				//RoomInfo.PlayerR[PlayerR].Ip = clientIp->toString();
				RoomInfo.PlayerB[PlayerR].RobotBukan = iRobotBukan;
				
				if (iRobotBukan == true){
					RoomInfo.PlayerR[PlayerR].RobotBukan = "Bot";
				} else if (iRobotBukan == false) {
					RoomInfo.PlayerR[PlayerR].RobotBukan = "Players";
				} else {
					RoomInfo.PlayerR[PlayerR].RobotBukan = "Undefined";
				}
				
                RoomInfo.PlayerR[PlayerR].Country = Country2;
                if (clientVersion) {
                    RoomInfo.PlayerR[PlayerR].Version = clientVersion->toString();
                }
                RoomInfo.PlayerR[PlayerR].Gender = GenderToString(gender);
                        
                RoomInfo.PlayerR[PlayerR].Elo = to_string(elo);
                RoomInfo.PlayerR[PlayerR].MPL = to_string(mpl);
                /*if (clientIp) {
                    RoomInfo.PlayerR[PlayerR].Ip = clientIp->toString();
                }*/
				
				RoomInfo.PlayerR[PlayerR].Winrate = "No Data";
				RoomInfo.PlayerR[PlayerR].TotalMatches = "Undefined";
				RoomInfo.PlayerR[PlayerR].TotalWin = "Undifined";
				
                if (RoadInfos) {
                    for (int ii = 0; ii < RoadInfos->getSize(); ii++) {
                        auto roadData = RoadInfos->getItems()[ii];
                        if (!roadData) continue;
                        auto iTotalNum = *(int *)((uintptr_t)roadData + RoadData_iTotalNum);
                        auto iWinNum = *(int *)((uintptr_t)roadData + RoadData_iWinNum);
                        if (iTotalNum > 0) {
                            float winrate = ((float)iWinNum / iTotalNum) * 100;
                            std::stringstream stream;
                            stream << std::fixed << std::setprecision(2) << winrate;
                            RoomInfo.PlayerR[PlayerR].Winrate = stream.str() + "%";
							RoomInfo.PlayerR[PlayerR].TotalMatches = to_string(iWinNum + iTotalNum);
							RoomInfo.PlayerR[PlayerR].TotalWin = to_string(iWinNum);
                        }
                    }
                }
				
                PlayerR++;
            }
        }
    }else{
		InitializeNick = false;
        for (int i = 0; i < 10; i++) Nick[i] = "-"; //clear nick
	} if (iBattleState == 0 || iBattleState == 7 || iBattleState == 8) {
    	for (int i = 0; i < 10; i++) Nick[i] = "-";
    }
}
