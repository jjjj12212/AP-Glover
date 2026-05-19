#ifndef DKR_FN_MAPS_H
#define DKR_FN_MAPS_H
    typedef enum {
        WAYROOM_ATLANTIS_HUB = 0x06,
        WAYROOM_CARNIVAL_HUB = 0x07,
        WAYROOM_PIRATES_HUB = 0x08,
        WAYROOM_PREHISTORIC_HUB = 0x09,
        WAYROOM_FORTRESS_HUB = 0x0A,
        WAYROOM_SPACE_HUB = 0x0B,
        WAYROOM_CAVE = 0x0C,
        WAYROOM_TRAINING = 0x15
    } WAYROOMS;
    // 0x0F = MENU
    // 0x0E = HUB1
    // 0x0D = HUB2
    #define gvr_wayroom_type (*(u8*)0x801E7541)

    typedef enum {
        MAP_HUB1 = 0x00,
        MAP_HUB2,
        MAP_HUB3,
        MAP_HUB4,
        MAP_HUB5,
        MAP_HUB6,
        MAP_HUB7,
        MAP_HUB8,
        MAP_CASTLE_CAVE,
        MAP_TRAINING,
        MAP_ATLANTIS_1,
        MAP_ATLANTIS_2,
        MAP_ATLANTIS_3,
        MAP_ATLANTIS_BOSS,
        MAP_ATLANTIS_BONUS,
        MAP_CARNIVAL_1,
        MAP_CARNIVAL_2,
        MAP_CARNIVAL_3,
        MAP_CARNIVAL_BOSS,
        MAP_CARNIVAL_BONUS,
        MAP_PIRATES_1,
        MAP_PIRATES_2,
        MAP_PIRATES_3,
        MAP_PIRATES_BOSS,
        MAP_PIRATES_BONUS,
        MAP_PREHISTORIC_1,
        MAP_PREHISTORIC_2,
        MAP_PREHISTORIC_3,
        MAP_PREHISTORIC_BOSS,
        MAP_PREHISTORIC_BONUS,
        MAP_FORTRESS_1,
        MAP_FORTRESS_2,
        MAP_FORTRESS_3,
        MAP_FORTRESS_BOSS,
        MAP_FORTRESS_BONUS,
        MAP_SPACE_1,
        MAP_SPACE_2,
        MAP_SPACE_3,
        MAP_SPACE_BOSS_1,
        MAP_SPACE_BOSS_2,
        MAP_SPACE_BOSS_3,
        MAP_SPACE_BONUS,
        MAP_WAYROOM = 0x2A,
        MAP_WIN = 0x2F
    } MAPS;


    #define gvr_current_map (*(u8*)0x801E7531)
    #define gvr_prev_map (*(u8*)0x801E7532)
    #define gvr_map_transistion (*(u8*)0x801E75C4)
    #define gvr_atlantis_bonus_completed (*(u8*)0x801E7584)
#endif
