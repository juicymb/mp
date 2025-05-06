#include <limits>
typedef unsigned long dword;

int delayZ;
float lingSkillControl2;
float skillSpeedNew;

int delay = 0;
bool gusion_combo = false, start_combo = false;
bool gusion_recall = false, start_comboGs = false;

bool paquito_combo = false, start_comboPaquito = false;
bool paquito_recall = false, start_comboPaq = false;

Vector3 iTargetEnemy;
Vector3 EntityPos = Vector3::zero();
float Distance5 = 6;

uintptr_t OffsetFunc_ShowSelfPlayer_TryUseSkill;

int CalculateMartisUlt(int m_Level){
    if ((m_Level) <= 4) {
        return 815 + (100 * m_Level);
    } else if ((m_Level) <= 9) {
        return 1.350 * (810 + (100 * m_Level));
    } else{
		return 1.350 * (740 + (100 * m_Level));
	}
}

int CalculateKarinaUlt(int mLevel){
	if (mLevel == 4){
		return 350 + (28 * mLevel);
	} else if (mLevel == 8){
		return 550 + (36 * mLevel);
	} else {
		return 1.550 * (550 + (36 * mLevel));
	}
}

void (*orig_TryUseSkill2)(...);
void TryUseSkill2(void *instance, int skillId, Vector3 dir, bool dirDefault, Vector3 pos, bool bCommonAtk, bool bAlong, bool isInFirstDragRange, bool bIgnoreQueue, int dragTime) {
    
}

void AutoSkillHero(void *unk) {
	auto AutoSkillHero = reinterpret_cast<void(*)(...)>(reinterpret_cast<uintptr_t>(Il2CppGetMethodOffset("Assembly-CSharp.dll", "", "ShowSelfPlayer", "TryUseSkill", 9)));
    //auto AutoSkillHero = (void (*)(void *,int ustate, int skillId, Vector3 dir, bool dirDefault, Vector3, bool, bool, bool, bool, int)) (OffsetFunc_ShowSelfPlayer_TryUseSkill);
	int state;
	
	float MaxDist = std::numeric_limits<float>::infinity();
    float MaxSwordDist = std::numeric_limits<float>::infinity();
    Vector3 SwordLocation = Vector3::zero();
    Vector3 SwordPos = Vector3::zero();
	int HoldInfinity = std::numeric_limits<int>::infinity();
	
	float stateentot = std::numeric_limits<float>::infinity();
    Vector3 EntityPos = Vector3::zero();
    Vector3 Hp;
    float MaxEnemyHP = std::numeric_limits<float>::infinity();
	float MaxPercentHP = std::numeric_limits<float>::infinity();
    int skillId;
	int target_m_uGuid = 0;
	
	auto m_BattleBridge = *(uintptr_t *) ((uintptr_t)BattleData_m_BattleBridge);
    if (!m_BattleBridge) return;
    auto bStartBattle = *(bool *) ((uintptr_t)m_BattleBridge + BattleBridge_bStartBattle());
    if (!bStartBattle) return;
	
	auto BattleManager_Instance = *(uintptr_t *) ((uintptr_t)BattleData_battleManager);
    if (BattleManager_Instance) {
        auto m_LocalPlayerShow = *(uintptr_t *) ((uintptr_t)BattleManager_Instance + BattleManager_m_LocalPlayerShow());
        if (m_LocalPlayerShow) {
			auto selfPos = *(Vector3 *) ((uintptr_t)m_LocalPlayerShow + ShowEntity__Position());
			//Vector3 selfPos = ShowEntity_GetPosition(m_LocalPlayerShow);
            auto HeroID = *(int *) ((uintptr_t)m_LocalPlayerShow + EntityBase_m_ID());
			auto m_Level = *(int *) ((uintptr_t)m_LocalPlayerShow + EntityBase_m_Level());
            if (selfPos != Vector3::zero()) {
                auto m_ShowPlayers = *(Dictionary<int, void **> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_dicPlayerShow());
            	if (m_ShowPlayers) {
            		for (int i = 0; i < m_ShowPlayers->getNumKeys(); i++) {
         				auto keys = m_ShowPlayers->getKeys()[i];
            			auto Pawn = m_ShowPlayers->getValues()[i];
            			if (!keys || !Pawn) continue;
                        auto m_ID = *(int *) ((uintptr_t)Pawn + EntityBase_m_ID());
                        auto m_bSameCampType = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bSameCampType());
                        if (m_bSameCampType) continue;
                        auto m_bDeath = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bDeath());
                        if (m_bDeath) continue;
						Vector3 _Position = ShowEntity_GetPosition(Pawn);
                        //auto _Position = *(Vector3 *) ((uintptr_t)Pawn + ShowEntity__Position());
                        float Distance = (int) Vector3::Distance(selfPos, _Position);
                        float MonsDist = Vector3::Distance(selfPos, _Position);
                        float CurHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_Hp());
                        float MaxHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_HpMax());
						auto canSight = *(bool *) ((uintptr_t)Pawn + EntityBase_canSight());
                        
						float PercentHP = CurHP * 100 / MaxHP;
                        auto iCalculateKarina = CalculateKarinaUlt(m_Level);
						
						if (Distance < RangeCombo) {
                        	if (Aim.Helper.Priority.Target == 0 && Distance < MaxDist) {
                            	EntityPos = _Position;
                                MaxDist = Distance;
                            }
                            if (Aim.Helper.Priority.Target == 1 && CurHP < MaxEnemyHP) {
                                EntityPos = _Position;
                                MaxEnemyHP = CurHP;
                            }
                            if (Aim.Helper.Priority.Target == 2 && PercentHP < MaxPercentHP) {
                                EntityPos = _Position;
                                MaxPercentHP = PercentHP;
                            }
                        }
						
						if (Aim.AutoSkills.KimmyV2){
							if (_Position != Vector3::zero() && Distance < RangeCombo){
								orig_TryUseSkill2(unk, 7170, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, false, false, true, HoldInfinity);
								orig_TryUseSkill2(unk, 7113, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, false, false, true, HoldInfinity);
								orig_TryUseSkill2(unk, 7113, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), true, true, true, true, HoldInfinity);
								//orig_TryUseSkill2(unk, 7113, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), true, true, true, true, 0);
								lingSkillControl2 = speedAtt;
							}
						}
						
						if (Aim.AutoSkills.KimmyV1){
							if (_Position != Vector3::zero()){
								orig_TryUseSkill2(unk, 7170, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, false, false, false, 1950);
								//AutoSkillHero(unk, 7170, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, false, false, false, 1650);
								orig_TryUseSkill2(unk, 7100, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, false, false, false, 1950);
								orig_TryUseSkill2(unk, 7100, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, false, false, false, 1650);
								lingSkillControl2 = speedAtt;
							}
						}
						
						if (Aim.AutoSkills.Lucas){
							if (_Position != Vector3::zero() && Distance < RangeCombo) {
								orig_TryUseSkill2(unk, 12756, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true, true, true, 1950);
								orig_TryUseSkill2(unk, 2012700, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), true, true, true, true, 1650);
								orig_TryUseSkill2(unk, 12731, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), true, false, false, 0);
								//AutoSkillHero(unk, 7113, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), true, true, true, true, 0);
								lingSkillControl2 = speedAtt;
							}
						}
						
						if (Aim.AutoSkills.SoYou){
							if (_Position != Vector3::zero() && Distance < RangeCombo) {
								orig_TryUseSkill2(unk, 12650, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, true, true, true, 1950);
								orig_TryUseSkill2(unk, 12603, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), true, true, true, true, 1650);
								orig_TryUseSkill2(unk, 12611, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), true, false, false, 0);
								lingSkillControl2 = speedAtt;
							}
						}
						
						if (Aim.AutoSkills.Yve){
    						if (_Position != Vector3::zero() && Distance < RangeCombo){
    							//if (CurHP < iCalculateKarina){
									//AutoSkillHero(unk, 10130, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), true, true, true, true, 0);
									orig_TryUseSkill2(unk, 10135, Vector3::Normalized(_Position - selfPos), true, _Position, true, true, true, true, 0);
									orig_TryUseSkill2(unk, 10173, Vector3::Normalized(_Position - selfPos), true, _Position, true, true, true, true, 0);
									//orig_TryUseSkill2(unk, 10130, Vector3::Normalized(_Position - selfPos), true, _Position, true, true, true, true, 0);
									orig_TryUseSkill2(unk, 10180, Vector3::Normalized(_Position - selfPos), true, _Position, true, true, true, true, 0);
									orig_TryUseSkill2(unk, 10100, Vector3::Normalized(_Position - selfPos), true, _Position, true, true, true, true, 0);
									
									//orig_TryUseSkill2(unk, 10180, Vector3::Normalized(_Position - selfPos), true, _Position, true, true, true, true, 0);
									//orig_TryUseSkill2(unk, 10112, Vector3::Normalized(_Position - selfPos), true, _Position, true, true, true, true, 0);
									//orig_TryUseSkill2(unk, 10136, Vector3::Normalized(_Position - selfPos), true, _Position, true, true, true, true, 0);
									
                                	lingSkillControl2 = speedAtt;
    							//}
    						}
    					}
    					
    					if (Aim.Helper.Skills.Gusion) {
         					start_combo = true;
          					gusion_combo = true;
       					}
       					if (start_combo && gusion_combo && Distance < RangeCombo) {
          					delay++;
          					switch (delay) {
             					case 1:
                					AutoSkillHero(unk, 5620, Vector3::Normalized(_Position - selfPos), _Position, true, target_m_uGuid, 0, true, false, 0, true);
    								lingSkillControl2 = speedAtt;
             					break;
             
             					case 5:
                					AutoSkillHero(unk, 5630, Vector3::Normalized(_Position - selfPos), _Position, true, target_m_uGuid, 0, true, false, 0, true);
    								lingSkillControl2 = speedAtt;
           						break;
    
             					case 10:
                					AutoSkillHero(unk, 5620, Vector3::Normalized(_Position - selfPos), _Position, true, target_m_uGuid, 0, true, false, 0, true);
    								lingSkillControl2 = speedAtt;
             					break;
    
             					case 15:
                					AutoSkillHero(unk, 5610, Vector3::Normalized(_Position - selfPos), _Position, true, target_m_uGuid, 0, true, false, 0, true);
    								lingSkillControl2 = speedAtt;
             					break;
    
             					case 20:
                					AutoSkillHero(unk, 5620, Vector3::Normalized(_Position - selfPos), _Position, true, target_m_uGuid, 0, true, false, 0, true);
    								lingSkillControl2 = speedAtt;
             					break;
    
             					case 25:
                					AutoSkillHero(unk, 5610, Vector3::Normalized(_Position - selfPos), _Position, true, target_m_uGuid, 0, true, false, 0, true);
    								lingSkillControl2 = speedAtt;
             					break;
    
             					case 35:
                					delay = 0;
                					start_combo = false;
                					gusion_combo = false;
              						Aim.Helper.Skills.Gusion = !Aim.Helper.Skills.Gusion;
             					break;
          					}
    					}
						
						if (Aim.AutoSkills.PharsaUlti){
							if (inVip == "100"){
								if (_Position != Vector3::zero() && Distance < 7){
									AutoSkillHero(unk, 5230, Vector3::Normalized(_Position - selfPos), true, _Position, false, false, false);
									AutoSkillHero(unk, 5231, Vector3::Normalized(_Position - selfPos), true, _Position, false, false, false);
									lingSkillControl2 = speedAtt;
								}
							}
						}
						
						
						
						
                    }
                }
				
				if (Aim.AutoSkills.LingLung){
					List<void **> *_RunBullets;
					Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleManager","_RunBullets", &_RunBullets);
            		if (_RunBullets) {
						for (int i = 0; i < _RunBullets->getSize(); i++) {
                			auto Pawn = _RunBullets->getItems()[i];
                    		if (!Pawn) continue;
                    		auto m_ID = *(int *) ((uintptr_t)Pawn + Bullet_m_Id());
							if (m_ID != 8452) continue;
                   		 	auto transform = *(Transform **) ((uintptr_t)Pawn + Bullet_transform());
                   		 	float Distance = (int) Vector3::Distance(selfPos, transform->get_position());
                    		if (Distance < 5) {
								EntityPos = transform->get_position();
                    		}
							
							if (EntityPos != Vector3::zero()) {
								orig_TryUseSkill2(unk, 8420, Vector3::Normalized(EntityPos - selfPos), true, Vector3::Distance(selfPos, transform->get_position()), true, true);
								lingSkillControl2 = speedAtt;
							}
                    	}
					}
				}
				
				// New Show Monsters Entity //
				auto m_ShowMonsters = *(Dictionary<int, void **> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_dicMonsterShow());
            	if (m_ShowMonsters) {
            		for (int i = 0; i < m_ShowMonsters->getNumKeys(); i++) {
         				auto keys = m_ShowMonsters->getKeys()[i];
            			auto Pawn = m_ShowMonsters->getValues()[i];
            			if (!keys || !Pawn) continue;
                        auto m_ID = *(int *) ((uintptr_t)Pawn + ShowEntity_m_id());
                        //if (MonsterToString(m_ID) == "") continue;
                        auto m_bSameCampType = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bSameCampType());
                        if (m_bSameCampType) continue;
                        auto m_bDeath = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bDeath());
                        if (m_bDeath) continue;
                        Vector3 _Position = ShowEntity_GetPosition(Pawn);
                        //auto _Position = *(Vector3 *) ((uintptr_t)Pawn + ShowEntity__Position());
                        float Distance = (int) Vector3::Distance(selfPos, _Position);
                        float MonsDist = Vector3::Distance(selfPos, _Position);
                        float CurHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_Hp());
                        float MaxHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_HpMax());
						auto canSight = *(bool *) ((uintptr_t)Pawn + EntityBase_canSight());
                        auto playerSelf = GetPlayerRealSelf();
                        if (!playerSelf) return;
						target_m_uGuid = *(int *) ((uintptr_t) Pawn + EntityBase_m_uGuid());
						//auto ustate = *(int *) ((uintptr_t)Pawn + LogicBattleManager_mState);
						//auto ustate = *(int *) ((uintptr_t)Pawn + ShowEntity_m_States);
						float PercentHP = CurHP * 100 / MaxHP;
                        /*
						#if defined(__aarch64__)
							auto stateintu = *(uintptr_t *) ((uintptr_t)Pawn + ShowEntity_m_States);
						#else
							auto stateintu = *(int *) ((int)Pawn + ShowEntity_m_States);
						#endif
						*/
						if (Distance < RangeCombo) {
                        	if (Aim.Helper.Priority.Target == 0 && Distance < MaxDist) {
                            	EntityPos = _Position;
                                MaxDist = Distance;
                            }
                            if (Aim.Helper.Priority.Target == 1 && CurHP < MaxEnemyHP) {
                                EntityPos = _Position;
                                MaxEnemyHP = CurHP;
                            }
                            if (Aim.Helper.Priority.Target == 2 && PercentHP < MaxPercentHP) {
                                EntityPos = _Position;
                                MaxPercentHP = PercentHP;
                            }
                        }
						if(KimmyAttackJungle){
							if (_Position != Vector3::zero() && Distance < 6.5) {
								AutoSkillHero(unk, 7170, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), true, true, true, true, 0);
								AutoSkillHero(unk, 7113, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), true, true, true, true, 0);
                                lingSkillControl2 = speedAtt;
                    		}
						}
						
						if (Aim.AutoSkills.KimmyV2){
							if (_Position != Vector3::zero() && Distance < RangeCombo){
								orig_TryUseSkill2(unk, 7170, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, false, false, true, HoldInfinity);
								orig_TryUseSkill2(unk, 7113, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), false, false, false, true, HoldInfinity);
								orig_TryUseSkill2(unk, 7113, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), true, true, true, true, HoldInfinity);
								//orig_TryUseSkill2(unk, 7113, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), true, true, true, true, 0);
								lingSkillControl2 = speedAtt;
							}
						}
						
						if (AutoSkills::KimmyCreep){
							if (inVip == "100"){
								if (_Position != Vector3::zero() && Distance < RangeCombo) {
									AutoSkillHero(unk, 7170, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), true, true, true, true, 0);
									AutoSkillHero(unk, 7113, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), true, true, true, true, 0);
									//AutoSkillHero(unk, ustate, 7113, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), true, true, true, true, 0);
									//AutoSkillHero(unk, ustate, 7113, Vector3::Normalized(_Position - selfPos), true, Vector3::zero(), true, true, true, true, 0);
									lingSkillControl2 = speedAtt;
								}
							} else {
								AutoSkillHero(unk);
							}
						}
                    }
                }
				//END
				
            }
        }
    }
}
