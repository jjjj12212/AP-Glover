#ifndef DKR_FN_SAVE_H
#define DKR_FN_SAVE_H


    typedef struct { 
        u8 unused1: 1; //801EAA4C
        u8 unused2: 1;
        u8 spc_bonus: 1;
        u8 spc_boss: 1;
        u8 spc_3: 1;
        u8 spc_2: 1;
        u8 spc_1: 1;
        u8 fof_bonus: 1;

        u8 fof_boss: 1; //801EAA4D
        u8 fof_3: 1;
        u8 fof_2: 1;
        u8 fof_1: 1;
        u8 pre_bonus: 1;
        u8 pre_boss: 1;
        u8 pre_3: 1;
        u8 pre_2: 1;

        u8 pre_1: 1; //801EAA4E
        u8 pir_bonus: 1;
        u8 pir_boss: 1;
        u8 pir_3: 1;
        u8 pir_2: 1;
        u8 pir_1: 1;
        u8 carn_bonus: 1;
        u8 carn_boss: 1;

        u8 carn_3: 1; //801EAA4F
        u8 carn_2: 1;
        u8 carn_1: 1;
        u8 atl_bonus: 1;
        u8 atl_boss: 1;
        u8 atl_3: 1;
        u8 atl_2: 1;
        u8 atl_1: 1;
    } perfect_t;

    typedef struct {
        u8 none1: 1;
        u8 none2: 1;
        u8 spc_door_bonus: 1;
        u8 spc_boss_defeated: 1;
        u8 spc_door_boss: 1;
        u8 spc_door_3: 1;
        u8 spc_door_2: 1;
        u8 fort_door_bonus: 1;

        u8 fort_boss_defeated: 1;
        u8 fort_door_boss: 1;
        u8 fort_door_3: 1;
        u8 fort_door_2: 1;
        u8 pre_door_bonus: 1;
        u8 pre_boss_defeated: 1;
        u8 pre_door_boss: 1;
        u8 pre_door_3: 1;

        u8 pre_door_2: 1;
        u8 pir_door_bonus: 1;
        u8 pir_boss_defeated: 1;
        u8 pir_door_boss: 1;
        u8 pir_door_3: 1;
        u8 pir_door_2: 1;
        u8 carn_door_bonus: 1;
        u8 carn_boss_defeated: 1;

        u8 carn_door_boss: 1;
        u8 carn_door_3: 1;
        u8 carn_door_2: 1;
        u8 atl_door_bonus: 1;
        u8 atl_boss_defeated: 1;
        u8 atl_door_boss: 1;
        u8 atl_door_3: 1;
        u8 atl_door_2: 1;
    } doors_t;

    typedef struct {
        u32 save_name;
        doors_t gates;
        perfect_t star_worlds;
        u32 current_score;
        u8 lives;
        u8 difficulty; //0 = easy, 1 = normal
        u8 spawn_ball;
        u8 ball_at_fountain;
        doors_t visited_worlds; //Entered World?
        u32 unknown6;
    } savestructure_t;

    typedef struct {
        u8 spc_boss_goal: 1;
        u8 spc_door_goal_3: 1;
        u8 spc_door_goal_2: 1;
        u8 spc_door_goal_1: 1;
        u8 fort_boss_goal: 1;
        u8 fort_door_goal_3: 1;
        u8 fort_door_goal_2: 1;
        u8 fort_door_goal_1: 1;
        
        u8 pre_boss_goal: 1;
        u8 pre_door_goal_3: 1;
        u8 pre_door_goal_2: 1;
        u8 pre_door_goal_1: 1;
        u8 pir_boss_goal: 1;
        u8 pir_door_goal_3: 1;
        u8 pir_door_goal_2: 1;
        u8 pir_door_goal_1: 1;
        
        u8 carn_boss_goal:1;
        u8 carn_door_goal_3: 1;
        u8 carn_door_goal_2: 1;
        u8 carn_door_goal_1: 1;
        u8 atl_boss_goal: 1;
        u8 atl_door_goal_3: 1;
        u8 atl_door_goal_2: 1;
        u8 atl_door_goal_1: 1;

    } ap_goals_t;

    typedef struct {

        u32 ap_name3;

        ap_goals_t goals[2];
        u8 frog_trap[2];
        // 8 bytes ^

        u8 curse_ball[2];
        u8 cball_trap[2];
        u8 fish_eye_trap[2];
        u8 enemy_ball_trap[2];
        u8 control_ball_trap[2];
        u8 invis_ball_trap[2];
        u8 big_ball[2];
        u8 low_grav[2];

        u32 ap_name4;

        u8 mad_garb_trap[2];
        u8 camera_trap[2];
        u8 camera_90_trap[2];
        u8 camera_135_trap[2];
        u8 camera_180_trap[2];
        u8 camera_225_trap[2];
        u8 camera_270_trap[2];
        u8 camera_315_trap[2];
        u8 chicken_sound[2];
        u8 hercules_transform[2];
        u8 speed_transform[2];
        u8 sticky_transform[2];

        u32 ap_name5;
        
        u8 frog_transform[2];
        u8 boomerang_transform[2];
        u8 beachball_transform[2];
        u8 helicopter_transform[2];
        u8 death_transform[2];
        u8 empty[2];
        u32 empty1[3];

        u32 ap_name6;
        u32 empty4[6];

    } apsave_t;

    typedef struct {
        savestructure_t savefile[2];
        apsave_t ap_save_data;
        savestructure_t unusedsavefile[2];
        u16 current_savefile;
    } savefile_t;

    #define gvr_save (*(savefile_t*)0x801EAA44)

    typedef void (*gvr_fnt_new_save)(u32 save, u32 size);
    #define gvr_fn_new_save ((gvr_fnt_new_save)0x8013FBC0)

#endif
