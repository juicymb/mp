#pragma once

#include <limits>

void (*orig_TryUseSkill2)(...);
void TryUseSkill2(void *instance, int skillId, Vector3 dir, bool dirDefault, Vector3 pos, bool bCommonAttack, bool bAlong, bool isInFirstDragRange, bool bIgnoreQueue, uint32_t dragTime) {
    //printf("SkillId: %d, Position: (%f, %f, %f)\n", skillId, pos.x, pos.y, pos.z);
    return orig_TryUseSkill2(instance, skillId, dir, dirDefault, pos, bCommonAttack, bAlong, isInFirstDragRange, bIgnoreQueue, dragTime);
}
