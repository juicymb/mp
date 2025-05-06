#define DefineHook(RET, NAME, ARGS) \
    RET (*o ## NAME) ARGS; \
    RET NAME ARGS

DefineHook (Vector3, getLocalPlayerPos, ()) {
    void *Instance = 0;
    Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleManager", "Instance", &Instance);
    if (Instance) {
        auto m_LocalPlayerShow = *(uintptr_t *)((uintptr_t) Instance + BattleManager_m_LocalPlayerShow());
        if (m_LocalPlayerShow) {
            return *(Vector3 *)((uintptr_t) m_LocalPlayerShow + ShowEntity__Position());
        }
    }
    return {0, 0, 0};
}

Vector3 EnemyMovePos() {
    void *Instance = 0;
    Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleManager", "Instance", &Instance);
    if (Instance) {
        auto m_ShowPlayers = *(List<void *> **) ((uintptr_t) Instance + BattleManager_m_ShowPlayers());
		if (m_ShowPlayers) {
			for (int i = 0; i < m_ShowPlayers->getSize(); i++) {
				auto Pawn2 = m_ShowPlayers->getItems()[i];
                if (!Pawn2) continue;
				
				auto m_bSameCampType =  *(bool *)((uintptr_t)Pawn2 + EntityBase_m_bSameCampType());
            	auto m_bDeath = *(bool *) ((uintptr_t)Pawn2 + EntityBase_m_bDeath());
            	//auto m_IsDeathProgress = *(bool *) ((uintptr_t) m_Items[i] + EntityBase_m_IsDeathProgress);
            	if (!m_bSameCampType && !m_bDeath) {
                	return *(Vector3 *)((uintptr_t)Pawn2 + ShowEntity_MoveDir());
            	}
				
			}
		}
        auto m_Items = m_ShowPlayers->getItems();
        for (int i = 0; i < m_ShowPlayers->getSize(); i++) {
            
        }
    }
    return {0, 0, 0};
}

Vector3 GetEnemyPosAimPredict(void *instance) {
    Vector3 Dist;
    Vector3 Hp;
    float MaxDist = std::numeric_limits<float>::infinity();
    float MaxEnemyHP = std::numeric_limits<float>::infinity();
    if (instance != NULL) {
        void *BattleManager_Instance;
        Il2CppGetStaticFieldValue("Assembly-CSharp.dll", "", "BattleManager", "Instance", &BattleManager_Instance);
        if (BattleManager_Instance) {
            auto m_LocalPlayerShow = *(uintptr_t *) ((uintptr_t)BattleManager_Instance + BattleManager_m_LocalPlayerShow());
            if (m_LocalPlayerShow) {
                auto selfPos = *(Vector3 *) ((uintptr_t)m_LocalPlayerShow + ShowEntity__Position());
                if (selfPos != Vector3::zero()) {
                    List<void **> *mShowPlayers = *(List<void **> **) ((uintptr_t)BattleManager_Instance + BattleManager_m_ShowPlayers());
                    if (mShowPlayers) {
                        for (int i = 0; i < mShowPlayers->getSize(); i++) {
                            auto playerEntity = mShowPlayers->getItems()[i];
                            if (!playerEntity) continue;
                            
                            auto m_bSameCampType = *(bool *) ((uintptr_t)playerEntity + EntityBase_m_bSameCampType());
                            if (m_bSameCampType) continue;
                            auto m_bDeath = *(bool *) ((uintptr_t)playerEntity + EntityBase_m_bDeath());
                            if (m_bDeath) continue;
                            
                            auto _Position = *(Vector3 *) ((uintptr_t)playerEntity + ShowEntity__Position());
                            
                            auto CurHP = *(int *) ((uintptr_t)playerEntity + EntityBase_m_Hp());
                            auto DarahKita = *(int *) ((uintptr_t)m_LocalPlayerShow + EntityBase_m_Hp());
                            auto MaxHP = *(int *) ((uintptr_t)playerEntity + EntityBase_m_HpMax());
                            auto PercentHP = CurHP * 100 / MaxHP;
                            
                            auto Distance = (int) Vector3::Distance(selfPos, _Position);
                            if (Distance < RangePredict) {
                                if (Aim.Helper.Priority.Target == ETargetPriority::Dist && Distance < MaxDist) {
                                    Dist = _Position;
                                    MaxDist = Distance;
                                }
                                if (Aim.Helper.Priority.Target == ETargetPriority::LowHP && CurHP < MaxEnemyHP) {
                                    Hp = _Position;
                                    MaxEnemyHP = CurHP;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (Hp != Vector3::zero()) return Hp;
    return Dist;
}

Vector3 dir_ , dirdwi;
Vector3 iSelfPos;

