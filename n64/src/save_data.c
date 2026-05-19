#include "save_data.h"

void SaveData(int item, u8 amt) 
{
    switch (item)
    {
    case AP_FROG_TRAP:
        gvr_save.ap_save_data.frog_trap[GetCurrentSave()] = amt;
        break;
    case AP_CURSE_BALL:
        gvr_save.ap_save_data.curse_ball[GetCurrentSave()] = amt;
        break;
    case AP_CBALL_TRAP:
        gvr_save.ap_save_data.cball_trap[GetCurrentSave()] = amt;
        break;
    case AP_FISH_EYE_TRAP:
        gvr_save.ap_save_data.fish_eye_trap[GetCurrentSave()] = amt;
        break;
    case AP_ENEMY_BALL_TRAP:
        gvr_save.ap_save_data.enemy_ball_trap[GetCurrentSave()] = amt;
        break;
    case AP_CONTROL_BALL_TRAP:
        gvr_save.ap_save_data.control_ball_trap[GetCurrentSave()] = amt;
        break;
    case AP_INVIS_BALL_TRAP:
        gvr_save.ap_save_data.invis_ball_trap[GetCurrentSave()] = amt;
        break;
    case AP_BIG_BALL:
        gvr_save.ap_save_data.big_ball[GetCurrentSave()] = amt;
        break;
    case AP_LOW_GRAV:
        gvr_save.ap_save_data.low_grav[GetCurrentSave()] = amt;
        break;
    case AP_MAD_GARIBS:
        gvr_save.ap_save_data.mad_garb_trap[GetCurrentSave()] = amt;
        break;
    case AP_CAMERA_TRAP:
        gvr_save.ap_save_data.camera_trap[GetCurrentSave()] = amt;
        break;
    case AP_CAMERA_90_TRAP:
        gvr_save.ap_save_data.camera_90_trap[GetCurrentSave()] = amt;
        break;
    case AP_CAMERA_135_TRAP:
        gvr_save.ap_save_data.camera_135_trap[GetCurrentSave()] = amt;
        break;
    case AP_CAMERA_180_TRAP:
        gvr_save.ap_save_data.camera_180_trap[GetCurrentSave()] = amt;
        break;
    case AP_CAMERA_225_TRAP:
        gvr_save.ap_save_data.camera_225_trap[GetCurrentSave()] = amt;
        break;
    case AP_CAMERA_270_TRAP:
        gvr_save.ap_save_data.camera_270_trap[GetCurrentSave()] = amt;
        break;
    case AP_CAMERA_315_TRAP:
        gvr_save.ap_save_data.camera_315_trap[GetCurrentSave()] = amt;
        break;
    case AP_CHICKEN_SOUND:
        gvr_save.ap_save_data.chicken_sound[GetCurrentSave()] = amt;
        break;
    case AP_HERCULES_TRANSFORM:
        gvr_save.ap_save_data.hercules_transform[GetCurrentSave()] = amt;
        break;
    case AP_SPEED_TRANSFORM:
        gvr_save.ap_save_data.speed_transform[GetCurrentSave()] = amt;
        break;
    case AP_STICKY_TRANSFORM:
        gvr_save.ap_save_data.sticky_transform[GetCurrentSave()] = amt;
        break;
    case AP_FROG_TRANSFORM:
        gvr_save.ap_save_data.frog_transform[GetCurrentSave()] = amt;
        break;
    case AP_BOOMERANG_TRANSFORM:
        gvr_save.ap_save_data.boomerang_transform[GetCurrentSave()] = amt;
        break;
    case AP_BEACHBALL_TRANSFORM:
        gvr_save.ap_save_data.beachball_transform[GetCurrentSave()] = amt;
        break;
    case AP_HELICOPTER_TRANSFORM:
        gvr_save.ap_save_data.helicopter_transform[GetCurrentSave()] = amt;
        break;
    case AP_DEATH_TRANSFORM:
        gvr_save.ap_save_data.death_transform[GetCurrentSave()] = amt;
        break;
    default:
        break;
    }
}

u8 GetSaveData(int item) 
{
    switch (item)
    {
    case AP_FROG_TRAP:
        return gvr_save.ap_save_data.frog_trap[GetCurrentSave()];
    case AP_CURSE_BALL:
        return gvr_save.ap_save_data.curse_ball[GetCurrentSave()];
    case AP_CBALL_TRAP:
        return gvr_save.ap_save_data.cball_trap[GetCurrentSave()];
    case AP_FISH_EYE_TRAP:
        return gvr_save.ap_save_data.fish_eye_trap[GetCurrentSave()];
    case AP_ENEMY_BALL_TRAP:
        return gvr_save.ap_save_data.enemy_ball_trap[GetCurrentSave()];
    case AP_CONTROL_BALL_TRAP:
        return gvr_save.ap_save_data.control_ball_trap[GetCurrentSave()];
    case AP_INVIS_BALL_TRAP:
        return gvr_save.ap_save_data.invis_ball_trap[GetCurrentSave()];
    case AP_BIG_BALL:
        return gvr_save.ap_save_data.big_ball[GetCurrentSave()];
    case AP_LOW_GRAV:
        return gvr_save.ap_save_data.low_grav[GetCurrentSave()];
    case AP_MAD_GARIBS:
        return gvr_save.ap_save_data.mad_garb_trap[GetCurrentSave()];
    case AP_CAMERA_TRAP:
        return gvr_save.ap_save_data.camera_trap[GetCurrentSave()];
    case AP_CAMERA_90_TRAP:
        return gvr_save.ap_save_data.camera_90_trap[GetCurrentSave()];
    case AP_CAMERA_135_TRAP:
        return gvr_save.ap_save_data.camera_135_trap[GetCurrentSave()];
    case AP_CAMERA_180_TRAP:
        return gvr_save.ap_save_data.camera_180_trap[GetCurrentSave()];
    case AP_CAMERA_225_TRAP:
        return gvr_save.ap_save_data.camera_225_trap[GetCurrentSave()];
    case AP_CAMERA_270_TRAP:
        return gvr_save.ap_save_data.camera_270_trap[GetCurrentSave()];
    case AP_CAMERA_315_TRAP:
        return gvr_save.ap_save_data.camera_315_trap[GetCurrentSave()];
    case AP_CHICKEN_SOUND:
        return gvr_save.ap_save_data.chicken_sound[GetCurrentSave()];
    case AP_HERCULES_TRANSFORM:
        return gvr_save.ap_save_data.hercules_transform[GetCurrentSave()];
    case AP_SPEED_TRANSFORM:
        return gvr_save.ap_save_data.speed_transform[GetCurrentSave()];
    case AP_STICKY_TRANSFORM:
        return gvr_save.ap_save_data.sticky_transform[GetCurrentSave()];
    case AP_FROG_TRANSFORM:
        return gvr_save.ap_save_data.frog_transform[GetCurrentSave()];
    case AP_BOOMERANG_TRANSFORM:
        return gvr_save.ap_save_data.boomerang_transform[GetCurrentSave()];
    case AP_BEACHBALL_TRANSFORM:
        return gvr_save.ap_save_data.beachball_transform[GetCurrentSave()];
    case AP_HELICOPTER_TRANSFORM:
        return gvr_save.ap_save_data.helicopter_transform[GetCurrentSave()];
    case AP_DEATH_TRANSFORM:
        return gvr_save.ap_save_data.death_transform[GetCurrentSave()];
    default:
        break;
    }
}

void CleanSave()
{
    u16 current_savefile = GetCurrentSave();
    gvr_save.ap_save_data.goals[current_savefile].atl_door_goal_1 = 0;
    gvr_save.ap_save_data.goals[current_savefile].atl_door_goal_2 = 0;
    gvr_save.ap_save_data.goals[current_savefile].atl_door_goal_3 = 0;
    gvr_save.ap_save_data.goals[current_savefile].atl_boss_goal = 0;
    gvr_save.ap_save_data.goals[current_savefile].carn_door_goal_1 = 0;
    gvr_save.ap_save_data.goals[current_savefile].carn_door_goal_2 = 0;
    gvr_save.ap_save_data.goals[current_savefile].carn_door_goal_3 = 0;
    gvr_save.ap_save_data.goals[current_savefile].carn_boss_goal = 0;
    gvr_save.ap_save_data.goals[current_savefile].pir_door_goal_1 = 0;
    gvr_save.ap_save_data.goals[current_savefile].pir_door_goal_2 = 0;
    gvr_save.ap_save_data.goals[current_savefile].pir_door_goal_3 = 0;
    gvr_save.ap_save_data.goals[current_savefile].pir_boss_goal = 0;
    gvr_save.ap_save_data.goals[current_savefile].pre_door_goal_1 = 0;
    gvr_save.ap_save_data.goals[current_savefile].pre_door_goal_2 = 0;
    gvr_save.ap_save_data.goals[current_savefile].pre_door_goal_3 = 0;
    gvr_save.ap_save_data.goals[current_savefile].pre_boss_goal = 0;
    gvr_save.ap_save_data.goals[current_savefile].fort_door_goal_1 = 0;
    gvr_save.ap_save_data.goals[current_savefile].fort_door_goal_2 = 0;
    gvr_save.ap_save_data.goals[current_savefile].fort_door_goal_3 = 0;
    gvr_save.ap_save_data.goals[current_savefile].fort_boss_goal = 0;
    gvr_save.ap_save_data.goals[current_savefile].spc_door_goal_1 = 0;
    gvr_save.ap_save_data.goals[current_savefile].spc_door_goal_2 = 0;
    gvr_save.ap_save_data.goals[current_savefile].spc_door_goal_3 = 0;
    gvr_save.ap_save_data.goals[current_savefile].spc_boss_goal = 0;
    gvr_save.ap_save_data.frog_trap[current_savefile] = 0;
    gvr_save.ap_save_data.curse_ball[current_savefile] = 0;
    gvr_save.ap_save_data.cball_trap[current_savefile] = 0;
    gvr_save.ap_save_data.fish_eye_trap[current_savefile] = 0;
    gvr_save.ap_save_data.enemy_ball_trap[current_savefile] = 0;
    gvr_save.ap_save_data.control_ball_trap[current_savefile] = 0;
    gvr_save.ap_save_data.invis_ball_trap[current_savefile] = 0;
    gvr_save.ap_save_data.big_ball[current_savefile] = 0;
    gvr_save.ap_save_data.low_grav[current_savefile] = 0;
    gvr_save.ap_save_data.mad_garb_trap[current_savefile] = 0;
    gvr_save.ap_save_data.camera_trap[current_savefile] = 0;
    gvr_save.ap_save_data.camera_90_trap[current_savefile] = 0;
    gvr_save.ap_save_data.camera_135_trap[current_savefile] = 0;
    gvr_save.ap_save_data.camera_180_trap[current_savefile] = 0;
    gvr_save.ap_save_data.camera_225_trap[current_savefile] = 0;
    gvr_save.ap_save_data.camera_270_trap[current_savefile] = 0;
    gvr_save.ap_save_data.camera_315_trap[current_savefile] = 0;
    gvr_save.ap_save_data.chicken_sound[current_savefile] = 0;
    gvr_save.ap_save_data.hercules_transform[current_savefile] = 0;
    gvr_save.ap_save_data.speed_transform[current_savefile] = 0;
    gvr_save.ap_save_data.sticky_transform[current_savefile] = 0;
    gvr_save.ap_save_data.frog_transform[current_savefile] = 0;
    gvr_save.ap_save_data.boomerang_transform[current_savefile] = 0;
    gvr_save.ap_save_data.beachball_transform[current_savefile] = 0;
    gvr_save.ap_save_data.helicopter_transform[current_savefile] = 0;
    gvr_save.ap_save_data.death_transform[current_savefile] =0;
}

u16 GetCurrentSave()
{
    return gvr_save.current_savefile;
}

u8 GetDifficulty() {
    return gvr_save.savefile[GetCurrentSave()].difficulty;
}

void SetDifficulty(u8 value) {
    gvr_save.savefile[GetCurrentSave()].difficulty = value;
    return;
}
