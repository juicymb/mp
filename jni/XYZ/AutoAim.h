/*Vector3 Predict(Vector3 AimEnemy, Vector3 getLocalPlayerPos, Vector3 EnemyMovePos, float BulletSpeed) {
    if (EnemyMovePos == Vector3::zero()) return AimEnemy;
    Vector3 RealCoords = AimEnemy;
    float TotalDistance = Vector3::Distance(RealCoords, getLocalPlayerPos);
    float TimeToTravel = TotalDistance / BulletSpeed;
    RealCoords += EnemyMovePos * TimeToTravel;
    RealCoords.x = RealCoords.x + EnemyMovePos.x * TimeToTravel;
    RealCoords.y = RealCoords.y + EnemyMovePos.y * TimeToTravel;
    RealCoords.z = RealCoords.z + EnemyMovePos.z * TimeToTravel + 0.0f * TimeToTravel * TimeToTravel;
    
    return RealCoords;
}*/

Vector3 Predict(Vector3 AimEnemy, Vector3 getLocalPlayerPos, Vector3 EnemyMovePos, float BulletSpeed, float gravity = 0.0f) {
    if (EnemyMovePos == Vector3::zero()) return AimEnemy;

    Vector3 RealCoords = AimEnemy;

    // Calculate the distance between the shooter and the enemy
    float TotalDistance = Vector3::Distance(RealCoords, getLocalPlayerPos);

    // Calculate the time for the bullet to travel that distance
    float TimeToTravel = TotalDistance / BulletSpeed;

    // Apply the enemy's velocity to predict where they will be when the bullet arrives
    RealCoords += EnemyMovePos * TimeToTravel;

    // Optionally simulate gravity by affecting the Z-axis (projectile drop)
    RealCoords.z += gravity * TimeToTravel * TimeToTravel * 1.0f;  // Adjust gravity impact if needed

    return RealCoords;
}


void (*oTryUseSkill)(...);
void TryUseSkill(void *instance, intptr_t *statein, int skillId, Vector3 dir, bool dirDefault, Vector3 pos, bool bCommonAtk, bool bAlong, bool isInFirstDragRange, int firstTarget, bool bIgnoreQueue, uint dragTime) {
bool isDoneAim = false;
	float MaxDist = std::numeric_limits<float>::infinity();
    float MaxEnemyHP = std::numeric_limits<float>::infinity();
    float MaxPercentHP = std::numeric_limits<float>::infinity();
    float MaxSwordDist = std::numeric_limits<float>::infinity();
    Vector3 EntityPos = Vector3::zero();
    Vector3 SwordLocation = Vector3::zero();
    Vector3 SwordPos = Vector3::zero();
    if (instance != NULL) {
		auto m_BattleBridge = *(uintptr_t *) ((uintptr_t)BattleData_m_BattleBridge);
    	if (!m_BattleBridge) return;
    	auto bStartBattle = *(bool *) ((uintptr_t)m_BattleBridge + BattleBridge_bStartBattle());
    	if (!bStartBattle) return;
		auto BattleManager_Instance = *(uintptr_t *) ((uintptr_t)BattleData_battleManager);
		auto m_LocalPlayerShow = *(uintptr_t *) ((uintptr_t)BattleManager_Instance + BattleManager_m_LocalPlayerShow());
        if (BattleManager_Instance && m_LocalPlayerShow){
			auto selfPos = *(Vector3 *) ((uintptr_t)m_LocalPlayerShow + ShowEntity__Position());
            auto HeroID = *(int *) ((uintptr_t)m_LocalPlayerShow + EntityBase_m_ID());
			if (selfPos != Vector3::zero()) {
				//auto m_ShowPlayers = *(Dictionary<int, void*> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_dicPlayerShow());
				List<void **> *m_ShowPlayers = *(List<void **> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_ShowPlayers());
            	if (m_ShowPlayers) {
					for (int i = 0; i < m_ShowPlayers->getSize(); i++) {
                        auto Pawn = m_ShowPlayers->getItems()[i];
                        if (!Pawn) continue;
                        auto m_ID = *(int *) ((uintptr_t)Pawn + EntityBase_m_ID());
                        //if (MonsterToString(m_ID) == "") continue;
                        auto m_bSameCampType = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bSameCampType());
                        if (m_bSameCampType) continue;
                        auto m_bDeath = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bDeath());
                        if (m_bDeath) continue;
                        //Vector3 _Position = ShowEntity_get_Position(Pawn);
                        auto _Position = *(Vector3 *) ((uintptr_t)Pawn + ShowEntity__Position());
                        float Distance = (int) Vector3::Distance(selfPos, _Position);
                        float MonsDist = Vector3::Distance(selfPos, _Position);
                        float CurHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_Hp());
                        float MaxHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_HpMax());
    					auto canSight = *(bool *) ((uintptr_t)Pawn + EntityBase_canSight());
                        auto playerSelf = GetPlayerRealSelf();
                        if (!playerSelf) return;
    					//auto ustate = *(int *) ((uintptr_t)Pawn + LogicBattleManager_mState);
    					//auto ustate = *(int *) ((uintptr_t)Pawn + ShowEntity_m_States);
    					float PercentHP = CurHP * 100 / MaxHP;
                        //LOGI("NEW STATE: %p", statein);
    					/*LOGI("dirDefault: %p", dirDefault);
						LOGI("DRAGTIME: %d | %p", dragTime);
						LOGI("firstTarget: %d", firstTarget);*/
						//LOGI("bIgnoreQueue: %s", bIgnoreQueue);
						LOGI("Skill ID: %d", skillId);
    					if (Distance < RangeCombo) {
                        	if (Aim.Helper.Priority.Target == ETargetPriority::Dist && Distance < MaxDist) {
                            	EntityPos = _Position;
                                MaxDist = Distance;
                            }
                            if (Aim.Helper.Priority.Target == ETargetPriority::LowHP && CurHP < MaxEnemyHP) {
                                EntityPos = _Position;
                                MaxEnemyHP = CurHP;
                            }
                            if (Aim.Helper.Priority.Target == ETargetPriority::LowHPPercent && PercentHP < MaxPercentHP) {
                                EntityPos = _Position;
                                MaxPercentHP = PercentHP;
                            }
    					}
    					
						if (AimEnemy != Vector3::zero()) {
                        	Vector3 myPos = getLocalPlayerPos();
                            auto targetLockPos = Vector3::Normalized(AimEnemy - myPos);
                            Vector3 moveDir = EnemyMovePos();
                            auto Predicted = Predict(AimEnemy, myPos, moveDir, SpeedPredict);
                            dirdwi = Vector3::Normalized(Predicted - myPos);
                            auto Predicted1 = Predict(AimEnemy, myPos, moveDir, 3);
                            dir_ = Vector3::Normalized(Predicted1 - myPos);
                                
                            if (instance != NULL && Aim.ActivePredict && Distance < RangePredict) {
                                if (Aim.Predict.Skill1) {
                                    if (skillId == 100 * HeroID + 10 || skillId == 10500 ) {
                                        isDoneAim = true;
                                        oTryUseSkill(instance, statein, skillId, dirdwi, dirDefault, pos, bCommonAtk, bAlong, isInFirstDragRange,firstTarget, bIgnoreQueue, dragTime);
                                    }
                                }
                                if (Aim.Predict.Skill2) {
                                	if (skillId == 100 * HeroID + 20) {
                                        isDoneAim = true;
                                        oTryUseSkill(instance, statein, skillId, dirdwi, dirDefault, pos, bCommonAtk, bAlong, isInFirstDragRange,firstTarget, bIgnoreQueue, dragTime);
                                    }
                                }
                                if (Aim.Predict.Skill3) {
                                    if (skillId == 100 * HeroID + 30 || skillId == 2010530 || skillId == 5230 ) {
                                        isDoneAim = true;
                                        oTryUseSkill(instance, statein, skillId, dirdwi, dirDefault, pos, bCommonAtk, bAlong, isInFirstDragRange,firstTarget, bIgnoreQueue, dragTime);
                                    }
                                }
                                if (Aim.Predict.Skill4) {
                                    if (skillId == 100 * HeroID + 40) {
                                        isDoneAim = true;
                                        oTryUseSkill(instance, statein, skillId, dirdwi, dirDefault, pos, bCommonAtk, bAlong, isInFirstDragRange,firstTarget, bIgnoreQueue, dragTime);
                                    }
                                }
                                if (Aim.Predict.Basic) {
                                	if (skillId == 100 * HeroID + 00) {
                                        isDoneAim = true;
                                        oTryUseSkill(instance, statein, skillId, dirdwi, dirDefault, pos, bCommonAtk, bAlong, isInFirstDragRange,firstTarget, bIgnoreQueue, dragTime);
                                    }
                                }
                            } else if (instance != NULL) {
                            	if (Aim.Helper.Skills.Skill1) {
                                	if (skillId == 100 * HeroID + 10) {
                                        isDoneAim = true;
                                        oTryUseSkill(instance, statein, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAlong, isInFirstDragRange,firstTarget, bIgnoreQueue, dragTime);
                                    }
                                }
                            }
                        }
						
    					if (EntityPos != Vector3::zero()) {
                        	auto AimDor = Vector3::Normalized(EntityPos - selfPos);
                            auto iTargetList = Vector3::Normalized(EntityPos - selfPos);
                                    
                            if (Aim.Helper.Skills.Xavier) {
                            	if (Distance <= RangeCombo && skillId == 11510) {
                                	oTryUseSkill(instance, statein, 11510, iTargetList, dirDefault, _Position, bCommonAtk, bAlong, isInFirstDragRange,firstTarget, bIgnoreQueue, dragTime);
                                    oTryUseSkill(instance, statein, 11520, iTargetList, dirDefault, _Position, bCommonAtk, bAlong, isInFirstDragRange,firstTarget, bIgnoreQueue, dragTime);
                                    isDoneAim = true;
                                }
    									
    							if (Distance <= RangeCombo && skillId == 11520) {
                                    oTryUseSkill(instance, statein, 11520, iTargetList, dirDefault, _Position, bCommonAtk, bAlong, isInFirstDragRange,firstTarget, bIgnoreQueue, dragTime);
                                    oTryUseSkill(instance, statein, 11510, iTargetList, dirDefault, _Position, bCommonAtk, bAlong, isInFirstDragRange,firstTarget, bIgnoreQueue, dragTime);
                                    isDoneAim = true;
                                }
                            }
    					}
    							
    					if(AutoSkills::KimmyTrigger){
							LOGI("After TryUseSkill: statein = %d\n", statein);
    						if (skillId == 7113){
								//Aim.AutoSkills.KimmyV1 = true;
    							Aim.AutoSkills.KimmyV2 = true;
    						} else if (skillId == 7170){
    							Aim.AutoSkills.KimmyV2 = false;
								//Aim.AutoSkills.KimmyV1 = false;
    						}
    					}
						
						if(AutoSkills::KimmyTriggerOnNew){
							if(skillId == 7113){
								Aim.AutoSkills.KimmyNewAim = true;
							} else if (skillId == 7170){
								Aim.AutoSkills.KimmyNewAim = false;
							}
						}
    							
    					if (AutoSkills::KimmyCreepTrigger){
    						if (skillId == 7113){
    							AutoSkills::KimmyCreep = true;
    						} else if (skillId == 7170){
    							AutoSkills::KimmyCreep = false;
    						}
    					}
						
						if (AutoSkills::Lucas){
							if(skillId == 12700){
								Aim.AutoSkills.Lucas = true;
							} else if (skillId == 12730){
								Aim.AutoSkills.Lucas = false;
							}
						}
    					
    					if (AutoSkills::PharsaTriggetUlti){
    						if (skillId == 5230){
    							Aim.AutoSkills.PharsaUlti = true;
    						}
    					}
    							
    					if (AutoSkills::GusionTrigger){
    						if (skillId == 5620){
    							Aim.Helper.Skills.Gusion = true;
    						}
    					}
    							
    					if (AutoSkills::PaquitoTrigger){
    						if (skillId == 10330){
    							Aim.Helper.Skills.Paquito = true;
    						}
    					}
    							
    					if (AutoSkills::GusionTriggerRecall){
    						if (Distance < RangeCombo && skillId == 5620){
    							Aim.Helper.Skills.Gusion = true;
    						}
    					}
    					
    					if (Aim.Helper.Skills.Yve) {
    						if (Distance < RangeCombo && skillId == 10130){
    							Aim.AutoSkills.Yve = true;
    						} else if (skillId == 10100){
    							Aim.AutoSkills.Yve = false;
    						}
    					}
    							
    					if (AutoSkills::DyrothBugTrigger){
    						if (Distance < RangeCombo && skillId == 100 * HeroID + 00){
    							AutoSkills::DyrothBugTest = false;
    						} else if (skillId == 8520){
    							AutoSkills::DyrothBugTest = true;
    						}
    					}
    							
    					if (AutoSkills::KimmyBasicAttackTrigger){
    						if (skillId == 7113){
    							Aim.AutoSkills.KimmyNewAim = true;
    						} else if (skillId == 7170){
    							Aim.AutoSkills.KimmyNewAim = false;
    						}
    					}
    							
    					if (AutoSkills::YinBugTrigger){
    						if (Distance < RangeCombo){
    							if (skillId == 100 * HeroID + 00){
    								AutoSkills::YinBrustDamage = true;
    							} else if (skillId == 20000){
    								AutoSkills::YinBrustDamage = false;
    							}
    						}
    					}
    							
    					if (AutoSkills::JoyTrigger){
    						if (skillId == 100 * HeroID + 30){
    							AutoSkills::JoyDoubleDamage = true;
    						} else if (skillId == 20000){
    							AutoSkills::JoyDoubleDamage = false;
    						}
    					} else if (AutoSkills::JoyTrigger){
    						AutoSkills::JoyDoubleDamage = false;
    					}
    							
    					if (AutoSkills::FredrinTrigger){
    						if (skillId == 100 * HeroID + 00){
    							AutoSkills::FredrinBug = true;
    						} else if (skillId == 20000){
    							AutoSkills::FredrinBug = false;
    						}
    					} else if(AutoSkills::FredrinTrigger){
    						AutoSkills::FredrinBug = false;
    					}
    							
    					if (AutoSkills::LesleyTrigger){
    						if (skillId == 100 * HeroID + 00){
    							AutoSkills::LesleyBug = true;
    						} else if (skillId == 20000){
    							AutoSkills::LesleyBug = false;
    						}
    					} 
    							
    					if (AutoSkills::JhonsonTrigger){
    						if (skillId == 100 * HeroID + 00){
    							AutoSkills::JhonsonDmg = true;
    						} else if (skillId == 20000){
    							AutoSkills::JhonsonDmg = false;
    						}
    					} else if(AutoSkills::JhonsonTrigger){
    						AutoSkills::JhonsonDmg = false;
    					}
    							
    					if (AutoSkills::AamonTrigger){
    						if (skillId == 100 * HeroID + 00){
    							AutoSkills::AamonDamage = true;
    						} else if (skillId == 20000){
    							AutoSkills::AamonDamage = false;
    						}
    					}
    							
    					if (AutoSkills::LaylaTrigger){
    						if (skillId == 100 * HeroID + 00){
    							AutoSkills::LaylaDamage = true;
    						} else if (skillId == 20000){
    							AutoSkills::LaylaDamage = false;
    						}
    					}
    							
    					if (AutoSkills::NovariaTrigger){
    						if (skillId == 100 * HeroID + 00){
    							AutoSkills::NovariaDamage = true;
    						} else if (skillId == 20000){
    							AutoSkills::NovariaDamage = false;
    						}
    					}
    							
    					if (AutoSkills::BeatrixBugTrigger){
    						if (Distance < RangeCombo){
    							if (skillId == 100 * HeroID + 00){
    								AutoSkills::BeatrixBugTest = true;
    							} else if (skillId == 20000){
    								AutoSkills::BeatrixBugTest = false;
    							}
    						}
    					} else if(AutoSkills::BeatrixBugTrigger){
    						AutoSkills::BeatrixBugTest = false;
    					}
    							
    					if (AutoSkills::MinotaurTrigger){
    						if (Distance < RangeCombo){
    							if (skillId == 100 * HeroID + 00){
    								AutoSkills::MinotaurBug = true;
    							} else if (skillId == 20000){
    								AutoSkills::MinotaurBug = false;
    							}
    						}
    					} else if(AutoSkills::MinotaurTrigger){
    						AutoSkills::BeatrixBugTest = false;
    					}
    							
    					if (AutoSkills::EsmeraldaTrigger){
    						if (skillId == 100 * HeroID + 00){
    							AutoSkills::EsmeraldaBug = true;
    						} else if (skillId == 20000){
    							AutoSkills::EsmeraldaBug = false;
    						}
    					}
    							
    					if (AutoSkills::GusionBugTrigger){
    						if(skillId == 100 * HeroID + 20){
    							AutoSkills::GusionDamage = true;
    						} else if (skillId == 20000){
    							AutoSkills::GusionDamage = false;
    						}
    					}
    				}
				}
			
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
                        	if (Aim.AutoTakeSword2 && Distance < MaxSwordDist) {
                            	SwordPos = transform->get_position();
                                MaxSwordDist = Distance;
                            }
                        }
                    }
    			}
                if (SwordPos != Vector3::zero() && HeroID == 84) {
                	auto targetLockPos = Vector3::Normalized(SwordPos - selfPos);
    				auto targetLockPost = Vector3::Normalized(EntityPos - selfPos);
                    if (skillId == 100 * HeroID + 20) {
                        isDoneAim = true;
                        oTryUseSkill(instance, statein, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAlong, isInFirstDragRange, bIgnoreQueue, dragTime);
                    }
                } else if (EntityPos != Vector3::zero()) {
                	auto targetLockPos = Vector3::Normalized(EntityPos - selfPos);
                    //Basic
                    if (Aim.Helper.Skills.Basic) {
                    	if (skillId == 100 * HeroID + 00) {
                            isDoneAim = true;
                            oTryUseSkill(instance, statein, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAlong, isInFirstDragRange,firstTarget, bIgnoreQueue, dragTime);
                        }
                    }
                    //Spell
                    if (Aim.Helper.Skills.Spell) {
						LOGI("After TryUseSkill: statein = %d\n", statein);
                    	if (skillId == 20100 || skillId == 20140) {
                            isDoneAim = true;
                            oTryUseSkill(instance, statein, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAlong, isInFirstDragRange,firstTarget, bIgnoreQueue, dragTime);
                        }
                    }
                    //Skill 1
                    if (Aim.Helper.Skills.Skill1) {
						LOGI("After TryUseSkill: statein = %d\n", statein);
    					//LOGI("STATE IN: %s", statein);
                    	if (skillId == 100 * HeroID + 10) {
                            isDoneAim = true;
                        	oTryUseSkill(instance, statein, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAlong, isInFirstDragRange,firstTarget, bIgnoreQueue, dragTime);
                        }
    				}
                    //Skill 2
                    if (Aim.Helper.Skills.Skill2) {
                    	if (skillId == 100 * HeroID + 20 || skillId == 2010520) {
                        	isDoneAim = true;
                            oTryUseSkill(instance, statein, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAlong, isInFirstDragRange,firstTarget, bIgnoreQueue, dragTime);
                        }
                    }
                    //Skill 3
                    if (Aim.Helper.Skills.Skill3) {
                    	if (skillId == 100 * HeroID + 30 || skillId == 2010530) {
                        	oTryUseSkill(instance, statein, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAlong, isInFirstDragRange,firstTarget, bIgnoreQueue, dragTime);
                        }
                    }
                    //Skill 4
                    if (Aim.Helper.Skills.Skill4) {
                    	if (skillId == 100 * HeroID + 40) {
                        	oTryUseSkill(instance, statein, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAlong, isInFirstDragRange,firstTarget, bIgnoreQueue, dragTime);
                        }
                    }
                    if (Aim.Helper.Skills.Pharsa) {
                    	if (skillId == 5230) {
                        	oTryUseSkill(instance, statein, 5230, targetLockPos, dirDefault, pos, bCommonAtk, bAlong, isInFirstDragRange,firstTarget, bIgnoreQueue, dragTime);
                           	oTryUseSkill(instance, statein, 5230, targetLockPos, dirDefault, pos, bCommonAtk, bAlong, isInFirstDragRange,firstTarget, bIgnoreQueue, dragTime);
                        }
                    }
                    if (Aim.Helper.Skills.BeatrixUlti) {
                    	if (skillId == 100 * HeroID + 30 || skillId == 201053) {
                        	isDoneAim = true;
                            oTryUseSkill(instance, statein, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAlong, isInFirstDragRange,firstTarget, bIgnoreQueue, dragTime);
                        }
                    }
                    if (Aim.Helper.Skills.BeatrixSnipper) {
                    	if (skillId == 10500) {
                        	isDoneAim = true;
                            oTryUseSkill(instance, statein, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAlong, isInFirstDragRange,firstTarget, bIgnoreQueue, dragTime);
                        }
                    }
                    if (Aim.Helper.Skills.Selena) {
                    	if (skillId == 6320) {
                        	oTryUseSkill(instance, statein, 6320, targetLockPos, true, Vector3::zero(), bCommonAtk, bAlong, isInFirstDragRange,firstTarget, bIgnoreQueue, dragTime);
                            isDoneAim = true;
                        }
                    }
                    if (Aim.Helper.Skills.Flameshot) {
                    	if (skillId == 20140) {
                        	oTryUseSkill(instance, statein, skillId, targetLockPos, dirDefault, pos, bCommonAtk, bAlong, isInFirstDragRange,firstTarget, bIgnoreQueue, dragTime);
                        }
                    }
                }
			}
		}
	}
	if (!isDoneAim) {
        oTryUseSkill(instance, statein, skillId, dir, dirDefault, pos, bCommonAtk, bAlong, isInFirstDragRange,firstTarget, bIgnoreQueue, dragTime);
    }
}

void (*New_OrigTryUseSkill)(...);
void New_TryUseSkill(void *instance, int *state, int skillId, Vector3 dir, bool dirDefault, Vector3 pos, bool bCommonAtk, bool bAuto, bool bAlong, bool bInQueue, bool isInFirstDragRange, uint32_t *firstTarget, void *keyState, bool bIgnoreQueue, uint32_t dragTime){
	
}

//+++++++++++++++++++++ RETRI SKILL WITHOUT LAGGING +++++++++++++++++++++
int CalculateRetriDamage(int m_Level, int _KillWildTimes, int _killNum, int _assistNum) {
    if ((_KillWildTimes + _killNum + _assistNum) < 5) {
        return 520 + (80 * m_Level);
    } else {
        return 1.520 * (520 + (80 * m_Level));
    }
}

int m_Level, m_KillWildTimes;
int iCalculateRetriDamage(int m_Level, int _KillWildTimes, int _killNum, int _assistNum) {
    if ((_KillWildTimes + _killNum + _assistNum) < 5) {
        return 520 + (80 * m_Level);
    } else {
        return 1.520 * (520 + (80 * m_Level));
    }
}

void (*oShowSelfPlayer_OnUpdate)(void* pThis);
void iShowSelfPlayer_OnUpdate(void *pThis){
	if (pThis == NULL) return;  // Consolidate null check at the start
	
	if (Aim.AutoSkills.LingLung || Aim.AutoSkills.KimmyV2 || Aim.Helper.Skills.Irithel ||
        AutoSkills::YinBrustDamage || Aim.Helper.ComboSkill.Balmond || AutoSkills::YssBugCall ||
        Aim.AutoSkills.WanWan || AutoSkills::DyrothBugTest || Aim.AutoSkills.KimmyV3 || AutoSkills::AluBugCall ||
        Aim.Helper.Skills.Paquito || Aim.Helper.Skills.Martis || Aim.AutoSkills.Yve || AutoSkills::KimmyCreep ||
        Aim.AutoSkills.Yve || AutoSkills::KimmyBasicAttack || AutoSkills::BeatrixBugTest ||
        AutoSkills::AamonDamage || AutoSkills::LaylaDamage || AutoSkills::NovariaDamage || AutoSkills::JhonsonDmg ||
        AutoSkills::FannyCable || AutoSkills::ArgusDamage || AutoSkills::GusionDamage || AutoSkills::JoyDoubleDamage ||
        AutoSkills::FredrinBug || Aim.AutoSkills.PharsaUlti || AutoSkills::MinotaurBug || AutoSkills::EsmeraldaBug ||
        AutoSkills::EsmeraldaBug2 || AutoSkills::CarmilaBug || AutoSkills::AldousBug || Aim.Helper.Skills.Gusion ||
        Aim.AutoSkills.Karina || Aim.AutoSkills.KimmyV1 || Aim.AutoSkills.Lucas || Aim.AutoSkills.SoYou) {
        
        lingSkillControl2++;
        if (lingSkillControl2 > 21.5) {
            AutoSkillHero(pThis);
        }
    }
	int HoldInfinity = std::numeric_limits<int>::infinity();
	AimEnemy = GetEnemyPosAimPredict(pThis);
    auto stateentot = std::numeric_limits<float>::infinity();
    Vector3 SwordPos = Vector3::zero();
    float MaxDist = std::numeric_limits<float>::infinity();
    float MaxEnemyHP = std::numeric_limits<float>::infinity();
    float MaxPercentHP = std::numeric_limits<float>::infinity();
    Vector3 target = Vector3::zero();
    Vector3 target2 = Vector3::zero();
    auto target_m_uGuid = 0;
    auto target_m_uGuid2 = 0;

    auto m_BattleBridge = *(uintptr_t *) ((uintptr_t)BattleData_m_BattleBridge);
    if (!m_BattleBridge) return;
    auto bStartBattle = *(bool *) ((uintptr_t)m_BattleBridge + BattleBridge_bStartBattle());
    if (!bStartBattle) return;
    auto BattleManager_Instance = *(uintptr_t *) ((uintptr_t)BattleData_battleManager);
    if (BattleManager_Instance) {
        auto m_LocalPlayerShow = *(uintptr_t *) ((uintptr_t)BattleManager_Instance + BattleManager_m_LocalPlayerShow());
        if (m_LocalPlayerShow) {
            auto selfPos = *(Vector3 *) ((uintptr_t)m_LocalPlayerShow + ShowEntity__Position());
            auto HeroID = *(int *) ((uintptr_t)m_LocalPlayerShow + EntityBase_m_ID());
            if (selfPos != Vector3::zero()) {
                auto m_Level = *(int *) ((uintptr_t)m_LocalPlayerShow + EntityBase_m_Level());
                List<void **> *m_ShowMonsters = *(List<void **> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_ShowMonsters());
                if (m_ShowMonsters) {
                    for (int i = 0; i < m_ShowMonsters->getSize(); i++) {
                        auto Pawn = m_ShowMonsters->getItems()[i];
                        if (!Pawn) continue;
                        auto m_ID = *(int *) ((uintptr_t)Pawn + ShowEntity_m_id());
                        auto m_bSameCampType = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bSameCampType());
                        if (m_bSameCampType) continue;
                        auto m_bDeath = *(bool *) ((uintptr_t)Pawn + EntityBase_m_bDeath());
                        if (m_bDeath) continue;
                        Vector3 _Position = ShowEntity_get_Position(Pawn);
                        float Distance = (int) Vector3::Distance(selfPos, _Position);
                        float CurHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_Hp());
                        float MaxHP = *(int *) ((uintptr_t)Pawn + EntityBase_m_HpMax());
                        target = _Position;
                        target_m_uGuid = *(int *) ((uintptr_t)Pawn + EntityBase_m_uGuid());

                        auto playerSelf = GetPlayerRealSelf();
                        if (!playerSelf) return;
                        auto _KillWildTimes = *(int *) ((uintptr_t)playerSelf + LogicPlayer_KillWildTimes());
                        auto m_PlayerData = *(uintptr_t *) ((uintptr_t)playerSelf + LogicPlayer_m_PlayerData());
                        if (!m_PlayerData) return;
                        auto _killNum = *(int *) ((uintptr_t)playerSelf + PlayerData__killNum());
                        auto _assistNum = *(int *) ((uintptr_t)playerSelf + PlayerData__assistNum());
                        auto iCalculate = iCalculateRetriDamage(m_Level, _KillWildTimes, _killNum, _assistNum);

                        auto m_ShowPlayers = *(Dictionary<int, void **> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_dicPlayerShow());
                        if (m_ShowPlayers) {
                            for (int i = 0; i < m_ShowPlayers->getNumKeys(); i++) {
                                auto keys2 = m_ShowPlayers->getKeys()[i];
                                auto Pawn2 = m_ShowPlayers->getValues()[i];
                                if (!keys2 || !Pawn2) continue;
                                auto m_bSameCampType2 = *(bool *) ((uintptr_t)Pawn2 + EntityBase_m_bSameCampType());
                                if (m_bSameCampType2) continue;
                                auto m_bDeath2 = *(bool *) ((uintptr_t)Pawn2 + EntityBase_m_bDeath());
                                if (m_bDeath2) continue;
                                Vector3 _Position2 = ShowEntity_get_Position(Pawn);
                                float Distance2 = (int) Vector3::Distance(selfPos, _Position2);
                                float CurHP2 = *(int *) ((uintptr_t)Pawn2 + EntityBase_m_Hp());
                                float MaxHP2 = *(int *) ((uintptr_t)Pawn2 + EntityBase_m_HpMax());
                                float PercentHP2 = CurHP2 * 100 / MaxHP2;
                                if (Distance2 < RangeCombo) {
                                	if (Aim.Helper.Priority.Target == 0 && Distance2 < MaxDist) {
                                        EntityPos = _Position2;
                                    	MaxDist = Distance2;
                                    }
                                    if (Aim.Helper.Priority.Target == 1 && CurHP2 < MaxEnemyHP) {
                                    	EntityPos = _Position2;
                                        MaxEnemyHP = CurHP2;
                                    }
                                    if (Aim.Helper.Priority.Target == 2 && PercentHP2 < MaxPercentHP) {
                                        EntityPos = _Position2;
                                        MaxPercentHP = PercentHP2;
                                    }
                            	}
								
								if (Distance < AutoRetribution.Custom && Distance2 < AutoRetribution.Custom && CurHP < MaxHP) {
                                	if (CurHP <= iCalculate) {
										int state = 0;
                                    	if (m_ID == 2004 && AutoTrigger.Retribution /*Red Buff*/ || m_ID == 2005 && AutoTrigger.Retribution /*Blue Buff*/ || m_ID == 2002 && AutoTrigger.Retribution /*Lord*/ || m_ID == 2011 && AutoRetribution.Crab || m_ID == 2003 || m_ID == 2110 && AutoTrigger.Retribution || m_ID == 2072 && AutoRetribution.litho /*Lito*/|| m_ID == 2056 && AutoRetribution.litho /*Lito*/ ) {
                                        	if (Vector3::Normalized(_Position2 - selfPos) != Vector3::zero()) {
                                            	oTryUseSkill(pThis, &stateentot, 20020, Vector3::Normalized(_Position - selfPos));
                                            }
                                        }
                                    }
                                }
										
								if (Distance < AutoRetribution.Custom && CurHP <  MaxHP){
									int state = 0;
									if (CurHP < iCalculate){
										if (AutoRetribution.TurtleandLord && (m_ID == 2002 || m_ID == 2003 || m_ID == 2110) || AutoRetribution.RedandBlue && (m_ID == 2004 || m_ID == 2005) || AutoRetribution.Crab && (m_ID == 2011 || m_ID == 2013) || AutoRetribution.litho && (m_ID == 2056 || m_ID == 2072)){
											oTryUseSkill(pThis, &stateentot, 20020, Vector3::Normalized(_Position - selfPos));
										}
									}
								}
									
								if (Aim.AutoSkills.KimmyNewAim){
									int state = 0;
									if (_Position != Vector3::zero() && Distance < RangeCombo) {
										oTryUseSkill(pThis, &stateentot, 7170, Vector3::Normalized(_Position - selfPos));
										oTryUseSkill(pThis, &stateentot, 7113, Vector3::Normalized(_Position - selfPos));
										oTryUseSkill(pThis, &stateentot, 7113, Vector3::Normalized(_Position - selfPos));
									}
								}
								
                            }
                        }
						
						
                    }
                }
				
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
						auto firstTargets = *(int *) ((uintptr_t)Pawn + ShowAutoAtkAIComp_m_uiFirstTargetId());
						auto firstTargetz = *(int *) ((uintptr_t)Pawn + SkillIndicatorComp_m_uFirstTarget());
						
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
						
						if (Aim.AutoSkills.KimmyNewAim){
							
							int firstTarget;
							bool bCommonAtk;
							bool bAlong;
							bool isInFirstDragRange;
							bool NextTarget;
							bool dirDefault;
							bool bAuto;
							bool bInQueue;
							Vector3 pos;
							void *keyState;
							if (Distance < RangeCombo) {
								oTryUseSkill(pThis, &stateentot, 7170, Vector3::Normalized(_Position - selfPos));
								oTryUseSkill(pThis, &stateentot, 7170, Vector3::Normalized(_Position - selfPos));
								NextTarget = true;
							}
							if(NextTarget){
								oTryUseSkill(pThis, &stateentot, 7113, Vector3::Normalized(_Position - selfPos));
								oTryUseSkill(pThis, &stateentot, 7113, Vector3::Normalized(_Position - selfPos));
								NextTarget = false;
							}
						}
						
					}
				}
				
            }
        }
    }
	
	oShowSelfPlayer_OnUpdate(pThis);
}
