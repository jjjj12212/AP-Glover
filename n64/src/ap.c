#include "ap.h"
u8 single_garib_counter = 0;

u8 life_counter = 0;
u32 dialog_addr = 0;
u8 timer = 0;
u16 trap_timer = 0;
u16 trap_counter = 0;
bool frogt = false;

u32 display_dialog(u16 x_screen, u16 y_screen, u8 R, u8 G, u8 B, u8 alpha, float x_scale, float y_scale, u8 zero,
      char *ptr, u8 alignment);

void InitAPWorlds()
{
    ap_memory.pc.worlds[AP_TRAINING_WORLD].hub_entrance = 7;
    ap_memory.pc.worlds[AP_TRAINING_WORLD].door = 0;

    ap_memory.pc.worlds[AP_ATLANTIS_L1].hub_entrance = 1;
    ap_memory.pc.worlds[AP_ATLANTIS_L1].door = 1;
    ap_memory.pc.max_garib_totals[AP_ATLANTIS_L1] = 50;
    ap_memory.pc.worlds[AP_ATLANTIS_L2].hub_entrance = 1;
    ap_memory.pc.worlds[AP_ATLANTIS_L2].door = 2;
    ap_memory.pc.max_garib_totals[AP_ATLANTIS_L2] = 60;
    ap_memory.pc.worlds[AP_ATLANTIS_L3].hub_entrance = 1;
    ap_memory.pc.worlds[AP_ATLANTIS_L3].door = 3;
    ap_memory.pc.max_garib_totals[AP_ATLANTIS_L3] = 80;
    ap_memory.pc.worlds[AP_ATLANTIS_BOSS].hub_entrance = 1;
    ap_memory.pc.worlds[AP_ATLANTIS_BOSS].door = 4;
    ap_memory.pc.worlds[AP_ATLANTIS_BONUS].hub_entrance = 1;
    ap_memory.pc.worlds[AP_ATLANTIS_BONUS].door = 5;
    ap_memory.pc.max_garib_totals[AP_ATLANTIS_BONUS] = 25;

    ap_memory.pc.worlds[AP_CARNIVAL_L1].hub_entrance = 2;
    ap_memory.pc.worlds[AP_CARNIVAL_L1].door = 1;
    ap_memory.pc.max_garib_totals[AP_CARNIVAL_L1] = 65;
    ap_memory.pc.worlds[AP_CARNIVAL_L2].hub_entrance = 2;
    ap_memory.pc.worlds[AP_CARNIVAL_L2].door = 2;
    ap_memory.pc.max_garib_totals[AP_CARNIVAL_L2] = 80;
    ap_memory.pc.worlds[AP_CARNIVAL_L3].hub_entrance = 2;
    ap_memory.pc.worlds[AP_CARNIVAL_L3].door = 3;
    ap_memory.pc.max_garib_totals[AP_CARNIVAL_L3] = 80;
    ap_memory.pc.worlds[AP_CARNIVAL_BOSS].hub_entrance = 2;
    ap_memory.pc.worlds[AP_CARNIVAL_BOSS].door = 4;
    ap_memory.pc.worlds[AP_CARNIVAL_BONUS].hub_entrance = 2;
    ap_memory.pc.worlds[AP_CARNIVAL_BONUS].door = 5;
    ap_memory.pc.max_garib_totals[AP_CARNIVAL_BONUS] = 20;

    ap_memory.pc.worlds[AP_PIRATES_L1].hub_entrance = 3;
    ap_memory.pc.worlds[AP_PIRATES_L1].door = 3;
    ap_memory.pc.max_garib_totals[AP_PIRATES_L1] = 70;
    ap_memory.pc.worlds[AP_PIRATES_L2].hub_entrance = 3;
    ap_memory.pc.worlds[AP_PIRATES_L2].door = 2;
    ap_memory.pc.max_garib_totals[AP_PIRATES_L2] = 60;
    ap_memory.pc.worlds[AP_PIRATES_L3].hub_entrance = 3;
    ap_memory.pc.worlds[AP_PIRATES_L3].door = 3;
    ap_memory.pc.max_garib_totals[AP_PIRATES_L3] = 80;
    ap_memory.pc.worlds[AP_PIRATES_BOSS].hub_entrance = 3;
    ap_memory.pc.worlds[AP_PIRATES_BOSS].door = 4;
    ap_memory.pc.worlds[AP_PIRATES_BONUS].hub_entrance = 3;
    ap_memory.pc.worlds[AP_PIRATES_BONUS].door = 5;
    ap_memory.pc.max_garib_totals[AP_PIRATES_BONUS] = 50;

    ap_memory.pc.worlds[AP_PREHISTORIC_L1].hub_entrance = 4;
    ap_memory.pc.worlds[AP_PREHISTORIC_L1].door = 1;
    ap_memory.pc.max_garib_totals[AP_PREHISTORIC_L1] = 80;
    ap_memory.pc.worlds[AP_PREHISTORIC_L2].hub_entrance = 4;
    ap_memory.pc.worlds[AP_PREHISTORIC_L2].door = 2;
    ap_memory.pc.max_garib_totals[AP_PREHISTORIC_L2] = 80;
    ap_memory.pc.worlds[AP_PREHISTORIC_L3].hub_entrance = 4;
    ap_memory.pc.worlds[AP_PREHISTORIC_L3].door = 3;
    ap_memory.pc.max_garib_totals[AP_PREHISTORIC_L3] = 80;
    ap_memory.pc.worlds[AP_PREHISTORIC_BOSS].hub_entrance = 4;
    ap_memory.pc.worlds[AP_PREHISTORIC_BOSS].door = 4;
    ap_memory.pc.worlds[AP_PREHISTORIC_BONUS].hub_entrance = 4;
    ap_memory.pc.worlds[AP_PREHISTORIC_BONUS].door = 5;
    ap_memory.pc.max_garib_totals[AP_PREHISTORIC_BONUS] = 60;


    ap_memory.pc.worlds[AP_FORTRESS_L1].hub_entrance = 5;
    ap_memory.pc.worlds[AP_FORTRESS_L1].door = 1;
    ap_memory.pc.max_garib_totals[AP_FORTRESS_L1] = 60;
    ap_memory.pc.worlds[AP_FORTRESS_L2].hub_entrance = 5;
    ap_memory.pc.worlds[AP_FORTRESS_L2].door = 2;
    ap_memory.pc.max_garib_totals[AP_FORTRESS_L2] = 60;
    ap_memory.pc.worlds[AP_FORTRESS_L3].hub_entrance = 5;
    ap_memory.pc.worlds[AP_FORTRESS_L3].door = 3;
    ap_memory.pc.max_garib_totals[AP_FORTRESS_L3] = 70;
    ap_memory.pc.worlds[AP_FORTRESS_BOSS].hub_entrance = 5;
    ap_memory.pc.worlds[AP_FORTRESS_BOSS].door = 4;
    ap_memory.pc.worlds[AP_FORTRESS_BONUS].hub_entrance = 5;
    ap_memory.pc.worlds[AP_FORTRESS_BONUS].door = 5;
    ap_memory.pc.max_garib_totals[AP_FORTRESS_BONUS] = 56;


    ap_memory.pc.worlds[AP_SPACE_L1].hub_entrance = 6;
    ap_memory.pc.worlds[AP_SPACE_L1].door = 1;
    ap_memory.pc.max_garib_totals[AP_SPACE_L1] = 50;
    ap_memory.pc.worlds[AP_SPACE_L2].hub_entrance = 6;
    ap_memory.pc.worlds[AP_SPACE_L2].door = 2;
    ap_memory.pc.max_garib_totals[AP_SPACE_L2] = 50;
    ap_memory.pc.worlds[AP_SPACE_L3].hub_entrance = 6;
    ap_memory.pc.worlds[AP_SPACE_L3].door = 3;
    ap_memory.pc.max_garib_totals[AP_SPACE_L3] = 80;

    ap_memory.pc.worlds[AP_SPACE_BOSS].hub_entrance = 6;
    ap_memory.pc.worlds[AP_SPACE_BOSS].door = 4;
    ap_memory.pc.worlds[AP_SPACE_BONUS].hub_entrance = 6;
    ap_memory.pc.worlds[AP_SPACE_BONUS].door = 5;
    ap_memory.pc.max_garib_totals[AP_SPACE_BONUS] = 50;
}

void CheckReceivedAPItems()
{
    for(int item = 0; item <= AP_MAX_ITEM; item++)
    {
        switch (item)
        {
        case AP_ATLANTIS_L1_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_ATLANTIS_L1])
            {
                ap_memory.pc.garib_totals[AP_ATLANTIS_L1] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED ATLS-1 GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_ATLANTIS_L2_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_ATLANTIS_L2])
            {
                ap_memory.pc.garib_totals[AP_ATLANTIS_L2] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED ATLS-2 GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_ATLANTIS_L3_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_ATLANTIS_L3])
            {
                ap_memory.pc.garib_totals[AP_ATLANTIS_L3] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED ATLS-3 GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_ATLANTIS_BONUS_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_ATLANTIS_BONUS])
            {
                ap_memory.pc.garib_totals[AP_ATLANTIS_BONUS] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED ATLS-BONUS GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;

        case AP_CARNIVAL_L1_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_CARNIVAL_L1])
            {
                ap_memory.pc.garib_totals[AP_CARNIVAL_L1] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED CARNIVAL-1 GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CARNIVAL_L2_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_CARNIVAL_L2])
            {
                ap_memory.pc.garib_totals[AP_CARNIVAL_L2] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED CARNIVAL-2 GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CARNIVAL_L3_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_CARNIVAL_L3])
            {
                ap_memory.pc.garib_totals[AP_CARNIVAL_L3] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED CARNIVAL-3 GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CARNIVAL_BONUS_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_CARNIVAL_BONUS])
            {
                ap_memory.pc.garib_totals[AP_CARNIVAL_BONUS] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED CARNIVAL-BONUS GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;

        case AP_PIRATES_L1_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_PIRATES_L1])
            {
                ap_memory.pc.garib_totals[AP_PIRATES_L1] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED PIRATES-1 GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L2_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_PIRATES_L2])
            {
                ap_memory.pc.garib_totals[AP_PIRATES_L2] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED PIRATES-2 GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L3_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_PIRATES_L3])
            {
                ap_memory.pc.garib_totals[AP_PIRATES_L3] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED PIRATES-3 GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_BONUS_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_PIRATES_BONUS])
            {
                ap_memory.pc.garib_totals[AP_PIRATES_BONUS] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED PIRATES-BONUS GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;

        case AP_PREHISTORIC_L1_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_PREHISTORIC_L1])
            {
                ap_memory.pc.garib_totals[AP_PREHISTORIC_L1] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED PREHIST-1 GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PREHISTORIC_L2_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_PREHISTORIC_L2])
            {
                ap_memory.pc.garib_totals[AP_PREHISTORIC_L2] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED PREHIST-2 GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PREHISTORIC_L3_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_PREHISTORIC_L3])
            {
                ap_memory.pc.garib_totals[AP_PREHISTORIC_L3] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED PREHIST-3 GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PREHISTORIC_BONUS_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_PREHISTORIC_BONUS])
            {
                ap_memory.pc.garib_totals[AP_PREHISTORIC_BONUS] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED PREHIST-B GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;

        case AP_FORTRESS_L1_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_FORTRESS_L1])
            {
                ap_memory.pc.garib_totals[AP_FORTRESS_L1] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED FORTRESS-1 GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_FORTRESS_L2_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_FORTRESS_L2])
            {
                ap_memory.pc.garib_totals[AP_FORTRESS_L2] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED FORTRESS-2 GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_FORTRESS_L3_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_FORTRESS_L3])
            {
                ap_memory.pc.garib_totals[AP_FORTRESS_L3] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED FORTRESS-3 GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_FORTRESS_BONUS_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_FORTRESS_BONUS])
            {
                ap_memory.pc.garib_totals[AP_FORTRESS_BONUS] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED FORTRESS-BONUS GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;

        case AP_SPACE_L1_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_SPACE_L1])
            {
                ap_memory.pc.garib_totals[AP_SPACE_L1] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED SPACE-1 GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_SPACE_L2_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_SPACE_L2])
            {
                ap_memory.pc.garib_totals[AP_SPACE_L2] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED SPACE-2 GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_SPACE_L3_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_SPACE_L3])
            {
                ap_memory.pc.garib_totals[AP_SPACE_L3] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED SPACE-3 GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_SPACE_BONUS_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.garib_totals[AP_SPACE_BONUS])
            {
                ap_memory.pc.garib_totals[AP_SPACE_BONUS] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED SPACE-BONUS GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;

        case AP_JUMP:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED JUMP";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_DOUBLE_JUMP:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED DOUBLE JUMP";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CARTWHEEL:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED CARTWHEEL";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CRAWL:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED CRAWL";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_FISTSLAM:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED FIST SLAM";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PUSH:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED PUSH";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;

        case AP_LEDGEGRAB:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED LEDGE GRAB";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_LOCATE_GARIB:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED LOCATE GARIB";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_DRIBBLE:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED DRIBBLE";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_QUICKSWAP:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED QUICKSWAP";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_SLAP:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED SLAP";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_THROW:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED THROW";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_TOSS:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED TOSS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_RUBBER_BALL:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED RUBBER BALL";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_BOWLING_BALL:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED BOWLING BALL";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_POWER_BALL:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED POWER BALL";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_BEARING_BALL:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED BEARING BALL";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CRYSTAL_BALL:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED CRYSTAL BALL";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_HERCULES_POTION:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED HERCULES POTION";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_SPEED_POTION:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED SPEED POTION";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_STICKY_POTION:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED STICKY POTION";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_FROG_POTION:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED FROG POTION";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_BOOMERANG_POTION:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED BOOMERANG POTION";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_HELICOPTER_POTION:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT ROTOR BLADES POTION";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_DEATH_POTION:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT DEATH POTION";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_ATLANTIS_L1_GATE:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT ATLANTIS-1 GATE";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_ATLANTIS_L2_RAISE_WATER:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT ATLANTIS-2 RAISE WATER";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_ATLANTIS_L2_WATER_DRAIN:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT ATLANTIS-2 DRAIN WATER";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_ATLANTIS_L2_GATE:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT ATLANTIS-2 GATE";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_ATLANTIS_L3_SPIN_WHEEL:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT ATLANTIS-3 WATER WHEEL";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_ATLANTIS_L3_CAVE:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT ATLS-3 CAVE PLATFORM";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CARNIVAL_L1_CONVEYOR:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT CARNIVAL-1 CONVEYOR";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CARNIVAL_L1_GATE:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT CARNIVAL-1 GATE";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
            case AP_CARNIVAL_L1_DOORA:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT CARNIVAL-1 DOOR A";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
            case AP_CARNIVAL_L1_DOORB:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT CARNIVAL-1 DOOR B";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
            case AP_CARNIVAL_L1_DOORC:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT CARNIVAL-1 DOOR C";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
            case AP_CARNIVAL_L1_ROCKET_RAMP:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text;
                if(ap_memory.pc.items[item] == 1)
                {
                    text = "YOU GOT CARN-1 ROCKET-RAMP 1/3";
                }
                else if(ap_memory.pc.items[item] == 2)
                {
                    text = "YOU GOT CARN-1 ROCKET-RAMP 2/3";
                }
                else if(ap_memory.pc.items[item] == 3)
                {
                    text = "YOU GOT CARN-1 ROCKET-RAMP 3/3";
                }
                else
                {
                     text = "ERROR TOO MANY RAMPS";
                }
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CARNIVAL_L2_TEETH:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT CARNIVAL-2 GARIB SPAWN";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CARNIVAL_L2_FAN:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT CARNIVAL-2 FAN";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CARNIVAL_L3_SPIN_DOOR:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT CARNIVAL-3 SPIN DOOR";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CARNIVAL_L3_HANDS:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT CARNIVAL-3 DOOR HANDS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L1_RAISE_BEACH:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-1 RAISE BEACH";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L1_ELEVATOR:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-1 ELEVATOR";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L1_CHEST:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-1 CHEST";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L1_SANDPILE:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-1 SAND PILE";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L1_WATERSPOUT:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-1 WATER SPOUT";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L1_LIGHTHOUSE:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-1 LIGHTHOUSE";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L1_RAISE_SHIP:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-1 RAISE SHIP";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L1_BRIDGE:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-1 BRIDGE";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L2_LOWER_WATER:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-2 DRAIN WATER";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L2_RAMP:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-2 RAMP";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L2_GATE:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-2 GATE";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L3_TRAMPOLINE:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-3 TRAMPOLINE";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L3_STAIRS:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-3 STAIRS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L3_ELEVATOR:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-3 ELEVATOR";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PREHISTORIC_L1_LIFE_DROP:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PREHIST-1 LIFE DROP";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
        break;
        case AP_PREHISTORIC_L2_PLATFORM_1:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PREHIST-2 PLATFORM 1";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PREHISTORIC_L2_PLATFORM_2:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PREHIST-2 PLATFORM 2";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PREHISTORIC_L2_LOWER_BALL_SWITCH:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "GOT PREHIST-2 LOWER SWITCHES";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PREHISTORIC_L3_DROP_GARIBS:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PREHIST-3 DROP GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            case AP_PREHISTORIC_L3_SPIN_STONES:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PREHIST-3 SPIN STONES";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PREHISTORIC_L3_PROGRESSIVE_LOWER_MONOLITH:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text;
                if(ap_memory.pc.items[item] == 1)
                {
                    text = "YOU GOT PREHIST-3 MONOLITH 1/4";
                }
                else if(ap_memory.pc.items[item] == 2)
                {
                    text = "YOU GOT PREHIST-3 MONOLITH 2/4";
                }
                else if(ap_memory.pc.items[item] == 3)
                {
                    text = "YOU GOT PREHIST-3 MONOLITH 3/4";
                }
                else if(ap_memory.pc.items[item] == 4)
                {
                    text = "YOU GOT PREHIST-3 MONOLITH 4/4";
                }
                else
                {
                    text = "ERROR TOO MANY MONOLITH";
                }
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PREHISTORIC_L3_FLOATING_PLATFORMS:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "GOT PREHIST-3 FLOAT PLATFORMS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PREHISTORIC_L3_LAVA_SPINNING:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "GOT PREHIST-3 SPIN PLATFORMS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PREHISTORIC_L3_DIRT_ELEVATOR:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PREHIST-3 ELEVATOR";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_FORTRESS_L1_COFFIN:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT FEAR-1 COFFINS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_FORTRESS_L1_PROGRESSIVE_DOORWAY_KEY:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text;
                if(ap_memory.pc.items[item] == 1)
                {
                    text = "YOU GOT FEAR-1 DOOR KEY 1/2";
                }
                else if(ap_memory.pc.items[item] == 2)
                {
                    text = "YOU GOT FEAR-1 DOOR KEY 2/2";
                }
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_FORTRESS_L1_COFFIN_LIGHTNING:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT FEAR-1 COFFIN BOOM";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_FORTRESS_L1_DRAWBRIDGE:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT FEAR-1 DRAWBRIDGE";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_FORTRESS_L2_GARIBS_FALL:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT FEAR-2 DROP GARIBS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_FORTRESS_L2_CHECKPOINT_GATES:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text;
                if(ap_memory.pc.items[item] == 1)
                {
                    text = "YOU GOT FEAR-2 GATES 1/2";
                }
                else if(ap_memory.pc.items[item] == 2)
                {
                    text = "YOU GOT FEAR-2 GATES 2/2";
                }
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_FORTRESS_L2_MUMMY_GATE:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT FEAR-2 MUMMY GATE";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_FORTRESS_L3_GATE:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT FEAR-3 GATE";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_FORTRESS_L3_SPIKES:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT FEAR-3 REMOVE SPIKES";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_SPACE_L1_FANS:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT SPACE-1 FANS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
        case AP_SPACE_L1_FLYING_PLATFORMS:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT SPACE-1 PLATFORMS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
        case AP_SPACE_L1_GOO_PLATFORMS:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT SPACE-1 GOO PLATFORMS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
        case AP_SPACE_L1_UFO:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT SPACE-1 UFO";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
        case AP_SPACE_L1_MISSILE:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT SPACE-1 MISSILE";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_SPACE_L2_MASHERS:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT SPACE-2 MASHER";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_SPACE_L2_RAMP:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT SPACE-2 RAMP";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_SPACE_L3_HAZARD_GATE:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT SPACE-3 HAZARD GATE";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_SPACE_L3_SIGN:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT SPACE-3 SIGN";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_SPACE_L3_FAN:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT SPACE-3 FAN";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_SPACE_L3_BRIDGE:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT SPACE-3 BRIDGE";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_SPACE_L3_GLASS_GATE:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT SPACE-3 GLASS GATE";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_TRAINING_WORLD_SANDPIT:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT TRAINING-WORLD SANDPIT";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_TRAINING_WORLD_LOWER_TARGET:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT TRAINING-WORLD TARGET";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_TRAINING_WORLD_STAIRS:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT TRAINING-WORLD STAIRS";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_GLOVER_DEATH:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                if(gvr_current_map == 0xFF)
                {
                    ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                }
                else if(gvr_cutscene == 0)
                {
                    ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                    gvr_fn_respawn();
                }
            }
            break;
        case AP_CHICKEN_SOUND:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                if(gvr_cutscene == 0)
                {
                    ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                    if(ap_memory.pc.n64_items[item] % 4 == 0)
                    {
                        gvr_fn_sounds(0x6F, 0x0FFF, 0x80, 0x0);
                        break;
                    }
                    else if(ap_memory.pc.n64_items[item] % 3 == 0)
                    {
                        gvr_fn_sounds(0x49, 0x0FFF, 0x80, 0x0);
                        break;
                    }
                    else if(ap_memory.pc.n64_items[item] % 2 == 0)
                    {
                        gvr_fn_sounds(0x6E, 0x0FFF, 0x80, 0x0);
                        break;
                    }
                    else
                    {
                        gvr_fn_sounds(0x181, 0x0FFF, 0x80, 0x0);
                        break;
                    }
                }
            }
            break;
        case AP_GLOVER_TAG:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                if(gvr_cutscene == 0 && animation_ptr->animations->current_animation == 0x0003)
                {
                    ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                    ap_memory.pc.n64_taglink++;
                    switch (gvr_current_ball)
                    {
                    case CURRENT_RUBBER_BALL:
                        if(ap_memory.pc.items[AP_BOWLING_BALL])
                            return gvr_fn_change_ball(TRANSFORM_BOWLING_BALL, 0xFFFFFFFF, 0x01, 0x18);
                        else if(ap_memory.pc.items[AP_POWER_BALL])
                            return gvr_fn_change_ball(TRANSFORM_POWER_BALL, 0xFFFFFFFF, 0x01, 0x18);
                        else if(ap_memory.pc.items[AP_BEARING_BALL])
                            return gvr_fn_change_ball(TRANSFORM_BEARING_BALL, 0xFFFFFFFF, 0x01, 0x18);
                        else if(ap_memory.pc.items[AP_CRYSTAL_BALL])
                            return gvr_fn_change_ball(TRANSFORM_CRYSTAL_BALL, 0xFFFFFFFF, 0x01, 0x18);
                        break;
                    case CURRENT_BOWLING_BALL:
                        if(ap_memory.pc.items[AP_POWER_BALL])
                            return gvr_fn_change_ball(TRANSFORM_POWER_BALL, 0xFFFFFFFF, 0x01, 0x18);
                        else if(ap_memory.pc.items[AP_BEARING_BALL])
                            return gvr_fn_change_ball(TRANSFORM_BEARING_BALL, 0xFFFFFFFF, 0x01, 0x18);
                        else if(ap_memory.pc.items[AP_CRYSTAL_BALL])
                            return gvr_fn_change_ball(TRANSFORM_CRYSTAL_BALL, 0xFFFFFFFF, 0x01, 0x18);
                        else if(ap_memory.pc.items[AP_RUBBER_BALL])
                            return gvr_fn_change_ball(TRANSFORM_RUBBER_BALL, 0xFFFFFFFF, 0x01, 0x18);
                        else
                        return;
                    case CURRENT_POWER_BALL:
                        if(ap_memory.pc.items[AP_BEARING_BALL])
                        return gvr_fn_change_ball(TRANSFORM_BEARING_BALL, 0xFFFFFFFF, 0x01, 0x18);
                        else if(ap_memory.pc.items[AP_CRYSTAL_BALL])
                        return gvr_fn_change_ball(TRANSFORM_CRYSTAL_BALL, 0xFFFFFFFF, 0x01, 0x18);
                        else if(ap_memory.pc.items[AP_RUBBER_BALL])
                        return gvr_fn_change_ball(TRANSFORM_RUBBER_BALL, 0xFFFFFFFF, 0x01, 0x18);
                        else if(ap_memory.pc.items[AP_BOWLING_BALL])
                        return gvr_fn_change_ball(TRANSFORM_BOWLING_BALL, 0xFFFFFFFF, 0x01, 0x18);
                        else
                        return;
                    case CURRENT_BEARING_BALL:
                        if(ap_memory.pc.items[AP_CRYSTAL_BALL])
                        return gvr_fn_change_ball(TRANSFORM_CRYSTAL_BALL, 0xFFFFFFFF, 0x01, 0x18);
                        else if(ap_memory.pc.items[AP_RUBBER_BALL])
                        return gvr_fn_change_ball(TRANSFORM_RUBBER_BALL, 0xFFFFFFFF, 0x01, 0x18);
                        else if(ap_memory.pc.items[AP_BOWLING_BALL])
                        return gvr_fn_change_ball(TRANSFORM_BOWLING_BALL, 0xFFFFFFFF, 0x01, 0x18);
                        else if(ap_memory.pc.items[AP_POWER_BALL])
                        return gvr_fn_change_ball(TRANSFORM_POWER_BALL, 0xFFFFFFFF, 0x01, 0x18);
                        else
                        return;
                    case CURRENT_CRYSTAL_BALL:
                        if(ap_memory.pc.items[AP_RUBBER_BALL])
                        return gvr_fn_change_ball(TRANSFORM_RUBBER_BALL, 0xFFFFFFFF, 0x01, 0x18);
                        else if(ap_memory.pc.items[AP_BOWLING_BALL])
                        return gvr_fn_change_ball(TRANSFORM_BOWLING_BALL, 0xFFFFFFFF, 0x01, 0x18);
                        else if(ap_memory.pc.items[AP_POWER_BALL])
                        return gvr_fn_change_ball(TRANSFORM_POWER_BALL, 0xFFFFFFFF, 0x01, 0x18);
                        else if(ap_memory.pc.items[AP_BEARING_BALL])
                        return gvr_fn_change_ball(TRANSFORM_BEARING_BALL, 0xFFFFFFFF, 0x01, 0x18);
                        else
                        return;
                    }
                    return;
                }
            }
            break;
        case AP_HERCULES_TRANSFORM:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                if(gvr_current_map == 0xFF)
                {
                    ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                }
                else if(gvr_cutscene == 0)
                {
                    ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                    return gvr_fn_change_ball(TRANSFORM_HERCULES_POTION, 0xFF, 0x01, 0x18);
                }
            }
            break;
        case AP_SPEED_TRANSFORM:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                if(gvr_current_map == 0xFF)
                {
                    ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                }
                else if(gvr_cutscene == 0)
                {
                    ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                    return gvr_fn_change_ball(TRANSFORM_SPEED_POTION, 0xFF, 0x01, 0x18);
                }
            }
            break;
        case AP_STICKY_TRANSFORM:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                if(gvr_current_map == 0xFF)
                {
                    ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                }
                else if(gvr_cutscene == 0)
                {
                    ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                    return gvr_fn_change_ball(TRANSFORM_STICKY_POTION, 0xFF, 0x01, 0x18);
                }
            }
            break;
        case AP_FROG_TRANSFORM:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                if(gvr_current_map == 0xFF)
                {
                    ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                }
                else if(gvr_cutscene == 0)
                {
                    ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                    return gvr_fn_change_ball(TRANSFORM_FROG_POTION, 0xFF, 0x01, 0x18);
                }
            }
            break;
        case AP_BOOMERANG_TRANSFORM:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                if(gvr_current_map == 0xFF)
                {
                    ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                }
                else if(gvr_cutscene == 0)
                {
                    ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                    return gvr_fn_change_ball(TRANSFORM_BOOMERANG_POTION, 0xFF, 0x01, 0x18);
                }
            }
            break;
        case AP_BEACHBALL_TRANSFORM:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                if(gvr_current_map == 0xFF)
                {
                    ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                }
                else if(gvr_cutscene == 0)
                {
                    ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                    return gvr_fn_change_ball(TRANSFORM_BEACH_BALL, 0xFF, 0x01, 0x18);
                }
            }
            break;
        case AP_HELICOPTER_TRANSFORM:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                if(gvr_current_map == 0xFF)
                {
                    ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                }
                else if(gvr_cutscene == 0)
                {
                    ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                    return gvr_fn_change_ball(TRANSFORM_HELICOPTER_POTION, 0xFF, 0x01, 0x18);
                }
            }
            break;
        case AP_DEATH_TRANSFORM:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                if(gvr_current_map == 0xFF)
                {
                    ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                }
                else if(gvr_cutscene == 0)
                {
                    ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                    return gvr_fn_change_ball(TRANSFORM_DEATH_POTION, 0xFF, 0x01, 0x18);
                }
            }
            break;
        case AP_LIFE_UP:
            if(ap_memory.pc.items[item] != life_counter)
            {
                gvr_current_lives = gvr_current_lives + (ap_memory.pc.items[item] - life_counter);
                life_counter = ap_memory.pc.items[item];
                char *text = "YOU RECEIVED A 1-UP";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_FROG_TRAP:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                if(trap_counter == 0)
                {
                    trap_counter = gvr_loaded_timer;
                    break;
                }
                if(gvr_current_map != 0xFF && gvr_current_map != 0x2B && gvr_current_map != 0x2C && gvr_current_map != 0x2E)
                {
                    if(gvr_loaded_timer > 0 && trap_counter != gvr_loaded_timer)
                    {
                        if(!frogt)
                        {
                            ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                            gvr_fn_glover_cheat(0x14, 1);
                            char *text = "YOU RECEIVED A FROG TRAP";
                            DialogQueue(text);
                            ap_memory.pc.send_text++;
                            trap_timer = 500;
                            frogt = true;
                            trap_counter = 0;
                        }
                    }
                }
                else
                {
                    trap_counter = 0;
                }
            }
            break;
        case AP_CAMERA_TRAP:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                if(trap_counter == 0)
                {
                    trap_counter = gvr_loaded_timer;
                    break;
                }
                if(gvr_current_map != 0xFF && gvr_current_map != 0x2B && gvr_current_map != 0x2C && gvr_current_map != 0x2E)
                {
                    if(gvr_loaded_timer > 0 && trap_counter != gvr_loaded_timer)
                    {
                        ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                        gvr_fn_glover_cheat(0x0C, 1);
                        char *text = "YOU RECEIVED A CAMERA TRAP";
                        DialogQueue(text);
                        ap_memory.pc.send_text++;
                        trap_timer = 500;
                        trap_counter = 0;
                    }
                }
                else
                {
                    trap_counter = 0;
                }
            }
            break;
        case AP_CURSE_BALL:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                if(trap_counter == 0)
                {
                    trap_counter = gvr_loaded_timer;
                    break;
                }
                if(gvr_current_map != 0xFF && gvr_current_map != 0x2B && gvr_current_map != 0x2C && gvr_current_map != 0x2E)
                {
                    if(gvr_loaded_timer > 0 && trap_counter != gvr_loaded_timer)
                    {
                        ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                        gvr_fn_curse_ball(0x1F4, 0x80, 0x01, 0x18);
                        char *text = "YOU RECEIVED A CURSE BALL";
                        DialogQueue(text);
                        ap_memory.pc.send_text++;     
                    }
                }
            }
            break;
        case AP_CBALL_TRAP:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                if(trap_counter == 0)
                {
                    trap_counter = gvr_loaded_timer;
                    break;
                }
                if(gvr_current_map != 0xFF && gvr_current_map != 0x2B && gvr_current_map != 0x2C && gvr_current_map != 0x2E)
                {
                    if(gvr_loaded_timer > 0 && trap_counter != gvr_loaded_timer)
                    {
                        ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                        gvr_fn_change_ball(TRANSFORM_CRYSTAL_BALL, 0x80, 0x1, 0x18);
                        char *text = "YOU RECEIVED CRYSTAL B TRAP";
                        DialogQueue(text);
                        ap_memory.pc.send_text++;     
                    }
                }
            }
            break;
        case AP_ATLANTIS_L1_CHECKPOINT1:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT ATLS-1 CHECKPOINT 1";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_ATLANTIS_L1_CHECKPOINT2:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT ATLS-1 CHECKPOINT 2";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_ATLANTIS_L2_CHECKPOINT1:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT ATLS-2 CHECKPOINT 1";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_ATLANTIS_L2_CHECKPOINT2:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT ATLS-2 CHECKPOINT 2";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_ATLANTIS_L2_CHECKPOINT3:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT ATLS-2 CHECKPOINT 3";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_ATLANTIS_L3_CHECKPOINT1:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT ATLS-3 CHECKPOINT 1";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_ATLANTIS_L3_CHECKPOINT2:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT ATLS-3 CHECKPOINT 2";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_ATLANTIS_L3_CHECKPOINT3:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT ATLS-3 CHECKPOINT 3";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CARNIVAL_L1_CHECKPOINT1:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT CARN-1 CHECKPOINT 1";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CARNIVAL_L1_CHECKPOINT2:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT CARN-1 CHECKPOINT 2";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CARNIVAL_L1_CHECKPOINT3:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT CARN-1 CHECKPOINT 3";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CARNIVAL_L1_CHECKPOINT4:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT CARN-1 CHECKPOINT 4";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CARNIVAL_L2_CHECKPOINT1:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT CARN-2 CHECKPOINT 1";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CARNIVAL_L2_CHECKPOINT2:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT CARN-2 CHECKPOINT 2";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CARNIVAL_L2_CHECKPOINT3:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT CARN-2 CHECKPOINT 3";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CARNIVAL_L2_CHECKPOINT4:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT CARN-2 CHECKPOINT 4";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CARNIVAL_L2_CHECKPOINT5:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT CARN-2 CHECKPOINT 5";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CARNIVAL_L3_CHECKPOINT1:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT CARN-3 CHECKPOINT 1";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CARNIVAL_L3_CHECKPOINT2:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT CARN-3 CHECKPOINT 2";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CARNIVAL_L3_CHECKPOINT3:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT CARN-3 CHECKPOINT 3";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_CARNIVAL_L3_CHECKPOINT4:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT CARN-3 CHECKPOINT 4";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L1_CHECKPOINT1:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-1 CHECKPOINT 1";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L1_CHECKPOINT2:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-1 CHECKPOINT 2";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L1_CHECKPOINT3:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-1 CHECKPOINT 3";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L2_CHECKPOINT1:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-2 CHECKPOINT 1";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L2_CHECKPOINT2:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-2 CHECKPOINT 2";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L2_CHECKPOINT3:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-2 CHECKPOINT 3";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L3_CHECKPOINT1:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-3 CHECKPOINT 1";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L3_CHECKPOINT2:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-3 CHECKPOINT 2";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L3_CHECKPOINT3:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-3 CHECKPOINT 3";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PIRATES_L3_CHECKPOINT4:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PIRATES-3 CHECKPOINT 4";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PREHISTORIC_L1_CHECKPOINT1:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PREHIST-1 CHECKPOINT 1";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PREHISTORIC_L1_CHECKPOINT2:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PREHIST-1 CHECKPOINT 2";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PREHISTORIC_L1_CHECKPOINT3:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PREHIST-1 CHECKPOINT 3";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PREHISTORIC_L2_CHECKPOINT1:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PREHIST-2 CHECKPOINT 1";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PREHISTORIC_L2_CHECKPOINT2:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PREHIST-2 CHECKPOINT 2";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PREHISTORIC_L2_CHECKPOINT3:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PREHIST-2 CHECKPOINT 3";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
        case AP_PREHISTORIC_L2_CHECKPOINT4:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PREHIST-2 CHECKPOINT 4";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PREHISTORIC_L3_CHECKPOINT1:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PREHIST-3 CHECKPOINT 1";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PREHISTORIC_L3_CHECKPOINT2:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PREHIST-3 CHECKPOINT 2";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_PREHISTORIC_L3_CHECKPOINT3:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PREHIST-3 CHECKPOINT 3";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
        case AP_PREHISTORIC_L3_CHECKPOINT4:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT PREHIST-3 CHECKPOINT 4";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_FORTRESS_L1_CHECKPOINT1:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT FEAR-1 CHECKPOINT 1";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_FORTRESS_L1_CHECKPOINT2:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT FEAR-1 CHECKPOINT 2";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_FORTRESS_L1_CHECKPOINT3:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT FEAR-1 CHECKPOINT 3";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
        case AP_FORTRESS_L2_CHECKPOINT1:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT FEAR-2 CHECKPOINT 1";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_FORTRESS_L2_CHECKPOINT2:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT FEAR-2 CHECKPOINT 2";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_FORTRESS_L2_CHECKPOINT3:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT FEAR-2 CHECKPOINT 3";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
        case AP_FORTRESS_L3_CHECKPOINT1:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT FEAR-3 CHECKPOINT 1";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_FORTRESS_L3_CHECKPOINT2:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT FEAR-3 CHECKPOINT 2";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
            break;
        case AP_FORTRESS_L3_CHECKPOINT3:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT FEAR-3 CHECKPOINT 3";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
        case AP_FORTRESS_L3_CHECKPOINT4:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT FEAR-3 CHECKPOINT 4";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
        case AP_FORTRESS_L3_CHECKPOINT5:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT FEAR-3 CHECKPOINT 5";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
        case AP_SPACE_L1_CHECKPOINT1:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT SPACE-1 CHECKPOINT 1";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
        case AP_SPACE_L1_CHECKPOINT2:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT SPACE-1 CHECKPOINT 2";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
        case AP_SPACE_L3_CHECKPOINT1:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT SPACE-3 CHECKPOINT 1";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
        case AP_SPACE_L3_CHECKPOINT2:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT SPACE-3 CHECKPOINT 2";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
        case AP_SPACE_L3_CHECKPOINT3:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT SPACE-3 CHECKPOINT 3";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
        case AP_SPACE_L3_CHECKPOINT4:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.n64_items[item] = ap_memory.pc.items[item];
                char *text = "YOU GOT SPACE-3 CHECKPOINT 4";
                DialogQueue(text);
                ap_memory.pc.send_text++;
            }
        case AP_DEBUG:
            if(ap_memory.pc.items[item] != ap_memory.pc.n64_items[item])
            {
                ap_memory.pc.items[AP_BOWLING_BALL] = 1;
                ap_memory.pc.items[AP_RUBBER_BALL] = 1;
                ap_memory.pc.items[AP_BEARING_BALL] = 1;
                ap_memory.pc.items[AP_CRYSTAL_BALL] = 1;
                ap_memory.pc.items[AP_JUMP] = 1;
                ap_memory.pc.items[AP_DOUBLE_JUMP] = 1;
                ap_memory.pc.items[AP_QUICKSWAP] = 1;
                ap_memory.pc.items[AP_CARTWHEEL] = 1;
                ap_memory.pc.items[AP_CRAWL] = 1;
                ap_memory.pc.items[AP_LOCATE_BALL] = 1;
                ap_memory.pc.items[AP_PUSH] = 1;
                ap_memory.pc.items[AP_FISTSLAM] = 1;
                ap_memory.pc.items[AP_LEDGEGRAB] = 1;
                ap_memory.pc.items[AP_LOCATE_GARIB] = 1;
                ap_memory.pc.items[AP_DRIBBLE] = 1;
                ap_memory.pc.items[AP_TOSS] = 1;
                ap_memory.pc.items[AP_THROW] = 1;
                ap_memory.pc.items[AP_SLAP] = 1;
                ap_memory.pc.items[AP_DEATH_POTION] = 1;
                ap_memory.pc.items[AP_FROG_POTION] = 1;
                ap_memory.pc.items[AP_BOOMERANG_POTION] = 1;
                ap_memory.pc.items[AP_HELICOPTER_POTION] = 1;
                ap_memory.pc.items[AP_SPEED_POTION] = 1;
                ap_memory.pc.items[AP_STICKY_POTION] = 1;
                ap_memory.pc.items[AP_HERCULES_POTION] = 1;
                ap_memory.pc.items[AP_BEACHBALL_POTION] = 1;
                ap_memory.pc.items[AP_ATLANTIS_L1_CHECKPOINT1] = 1;
                ap_memory.pc.items[AP_ATLANTIS_L1_CHECKPOINT2] = 1;
                ap_memory.pc.items[AP_ATLANTIS_L2_CHECKPOINT1] = 1;
                ap_memory.pc.items[AP_ATLANTIS_L2_CHECKPOINT2] = 1;
                ap_memory.pc.items[AP_ATLANTIS_L2_CHECKPOINT3] = 1;
                ap_memory.pc.items[AP_ATLANTIS_L3_CHECKPOINT1] = 1;
                ap_memory.pc.items[AP_ATLANTIS_L3_CHECKPOINT2] = 1;
                ap_memory.pc.items[AP_ATLANTIS_L3_CHECKPOINT3] = 1;
                ap_memory.pc.items[AP_CARNIVAL_L1_CHECKPOINT1] = 1;
                ap_memory.pc.items[AP_CARNIVAL_L1_CHECKPOINT2] = 1;
                ap_memory.pc.items[AP_CARNIVAL_L1_CHECKPOINT3] = 1;
                ap_memory.pc.items[AP_CARNIVAL_L1_CHECKPOINT4] = 1;
                ap_memory.pc.items[AP_CARNIVAL_L2_CHECKPOINT1] = 1;
                ap_memory.pc.items[AP_CARNIVAL_L2_CHECKPOINT2] = 1;
                ap_memory.pc.items[AP_CARNIVAL_L2_CHECKPOINT3] = 1;
                ap_memory.pc.items[AP_CARNIVAL_L2_CHECKPOINT4] = 1;
                ap_memory.pc.items[AP_CARNIVAL_L2_CHECKPOINT5] = 1;
                ap_memory.pc.items[AP_CARNIVAL_L3_CHECKPOINT1] = 1;
                ap_memory.pc.items[AP_CARNIVAL_L3_CHECKPOINT2] = 1;
                ap_memory.pc.items[AP_CARNIVAL_L3_CHECKPOINT3] = 1;
                ap_memory.pc.items[AP_CARNIVAL_L3_CHECKPOINT4] = 1;
                ap_memory.pc.items[AP_PIRATES_L1_CHECKPOINT1] = 1;
                ap_memory.pc.items[AP_PIRATES_L1_CHECKPOINT2] = 1;
                ap_memory.pc.items[AP_PIRATES_L1_CHECKPOINT3] = 1;
                ap_memory.pc.items[AP_PIRATES_L2_CHECKPOINT1] = 1;
                ap_memory.pc.items[AP_PIRATES_L2_CHECKPOINT2] = 1;
                ap_memory.pc.items[AP_PIRATES_L2_CHECKPOINT3] = 1;
                ap_memory.pc.items[AP_PIRATES_L3_CHECKPOINT1] = 1;
                ap_memory.pc.items[AP_PIRATES_L3_CHECKPOINT2] = 1;
                ap_memory.pc.items[AP_PIRATES_L3_CHECKPOINT3] = 1;
                ap_memory.pc.items[AP_PIRATES_L3_CHECKPOINT4] = 1;
                ap_memory.pc.items[AP_PREHISTORIC_L1_CHECKPOINT1] = 1;
                ap_memory.pc.items[AP_PREHISTORIC_L1_CHECKPOINT2] = 1;
                ap_memory.pc.items[AP_PREHISTORIC_L1_CHECKPOINT3] = 1;
                ap_memory.pc.items[AP_PREHISTORIC_L2_CHECKPOINT1] = 1;
                ap_memory.pc.items[AP_PREHISTORIC_L2_CHECKPOINT2] = 1;
                ap_memory.pc.items[AP_PREHISTORIC_L2_CHECKPOINT3] = 1;
                ap_memory.pc.items[AP_PREHISTORIC_L2_CHECKPOINT4] = 1;
                ap_memory.pc.items[AP_PREHISTORIC_L3_CHECKPOINT1] = 1;
                ap_memory.pc.items[AP_PREHISTORIC_L3_CHECKPOINT2] = 1;
                ap_memory.pc.items[AP_PREHISTORIC_L3_CHECKPOINT3] = 1;
                ap_memory.pc.items[AP_PREHISTORIC_L3_CHECKPOINT4] = 1;
                ap_memory.pc.items[AP_FORTRESS_L1_CHECKPOINT1] = 1;
                ap_memory.pc.items[AP_FORTRESS_L1_CHECKPOINT2] = 1;
                ap_memory.pc.items[AP_FORTRESS_L1_CHECKPOINT3] = 1;
                ap_memory.pc.items[AP_FORTRESS_L2_CHECKPOINT1] = 1;
                ap_memory.pc.items[AP_FORTRESS_L2_CHECKPOINT2] = 1;
                ap_memory.pc.items[AP_FORTRESS_L2_CHECKPOINT3] = 1;
                ap_memory.pc.items[AP_FORTRESS_L3_CHECKPOINT1] = 1;
                ap_memory.pc.items[AP_FORTRESS_L3_CHECKPOINT2] = 1;
                ap_memory.pc.items[AP_FORTRESS_L3_CHECKPOINT3] = 1;
                ap_memory.pc.items[AP_FORTRESS_L3_CHECKPOINT4] = 1;
                ap_memory.pc.items[AP_FORTRESS_L3_CHECKPOINT5] = 1;
                ap_memory.pc.items[AP_SPACE_L1_CHECKPOINT1] = 1;
                ap_memory.pc.items[AP_SPACE_L1_CHECKPOINT2] = 1;
                ap_memory.pc.items[AP_SPACE_L3_CHECKPOINT1] = 1;
                ap_memory.pc.items[AP_SPACE_L3_CHECKPOINT2] = 1;
                ap_memory.pc.items[AP_SPACE_L3_CHECKPOINT3] = 1;
                ap_memory.pc.items[AP_SPACE_L3_CHECKPOINT4] = 1;
            }
            break;
        default:
            break;
        }
    }
}

void SetAPGaribs()
{
    if(ap_memory.pc.settings.garib_logic != 0)
    {
        switch (ap_memory.pc.world_map){
            case MAP_ATLANTIS_1:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_ATLANTIS_L1];
                break;
            case MAP_ATLANTIS_2:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_ATLANTIS_L2];
                break;
            case MAP_ATLANTIS_3:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_ATLANTIS_L3];
                break;
            case MAP_ATLANTIS_BONUS:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_ATLANTIS_BONUS];
                break;
            case MAP_CARNIVAL_1:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_CARNIVAL_L1];
                break;
            case MAP_CARNIVAL_2:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_CARNIVAL_L2];
                break;
            case MAP_CARNIVAL_3:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_CARNIVAL_L3];
                break;
            case MAP_CARNIVAL_BONUS:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_CARNIVAL_BONUS];
                break;
            case MAP_PIRATES_1:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_PIRATES_L1];
                break;
            case MAP_PIRATES_2:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_PIRATES_L2];
                break;
            case MAP_PIRATES_3:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_PIRATES_L3];
                break;
            case MAP_PIRATES_BONUS:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_PIRATES_BONUS];
                break;
            case MAP_PREHISTORIC_1:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_PREHISTORIC_L1];
                break;
            case MAP_PREHISTORIC_2:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_PREHISTORIC_L2];
                break;
            case MAP_PREHISTORIC_3:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_PREHISTORIC_L3];
                break;
            case MAP_PREHISTORIC_BONUS:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_PREHISTORIC_BONUS];
                break;
            case MAP_FORTRESS_1:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_FORTRESS_L1];
                break;
            case MAP_FORTRESS_2:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_FORTRESS_L2];
                break;
            case MAP_FORTRESS_3:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_FORTRESS_L3];
                break;
            case MAP_FORTRESS_BONUS:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_FORTRESS_BONUS];
                break;
            case MAP_SPACE_1:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_SPACE_L1];
                break;
            case MAP_SPACE_2:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_SPACE_L2];
                break;
            case MAP_SPACE_3:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_SPACE_L3];
                break;
            case MAP_SPACE_BONUS:
                gvr_collected_garibs = ap_memory.pc.garib_totals[AP_SPACE_BONUS];
                break;
            default:
                break;
        }
    }
}

void DialogCheck()
{
    if(ap_memory.pc.send_text != ap_memory.pc.n64_text && ap_memory.pc.text_ready == 1)
    {
        ap_memory.pc.text_ready = 0;
        ap_memory.pc.n64_text++;
        dialog_addr = display_dialog(0x0A0, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0.75, 0.75, 0, ap_memory.pc.text_queue[ap_memory.pc.n64_text].text, 1);
        timer = 65;
        ap_memory.pc.text_queue[ap_memory.pc.n64_text].text[0] = 0x00;
        if(ap_memory.pc.n64_text == 49)
        {
            ap_memory.pc.send_text -= 48;
            ap_memory.pc.n64_text = 0;
        }
    }
}

void DialogClear()
{
    if(ap_memory.pc.send_text != ap_memory.pc.n64_text && ap_memory.pc.text_ready == 1)
    {
        ap_memory.pc.n64_text++;
        ap_memory.pc.text_queue[ap_memory.pc.n64_text].text[0] = 0x00;
        if(ap_memory.pc.n64_text == 49)
        {
            ap_memory.pc.send_text -= 48;
            ap_memory.pc.n64_text = 0;
        }
    }
}

void DialogQueue(char *text)
{
    if(ap_memory.pc.send_text + 1 == 49)
    {
        for(int i = 1; i < 49; i++)
        {
            if(ap_memory.pc.text_queue[i].text[0] == 0x00)
            {
                strcpy(ap_memory.pc.text_queue[i].text, text);
                break;
            }
        }
        return;
    }
    else{
        for(int i = ap_memory.pc.send_text + 1; i < 49; i++)
        {
            if(ap_memory.pc.text_queue[i].text[0] == 0x00)
            {
                strcpy(ap_memory.pc.text_queue[i].text, text);
                break;
            }
        }
    }
}

void DialogTimer()
{
    if(timer != 0)
    {
        timer--;
        u32 alpha_address = dialog_addr + 0x005B;
        switch (timer)
        {
        case 9:
            (*(u8*) alpha_address) = 0xE6;
            break;
        case 8:
            (*(u8*) alpha_address) = 0xCD;
            break;
        case 7:
            (*(u8*) alpha_address) = 0xB4;
            break;
        case 6:
            (*(u8*) alpha_address) = 0x9B;
            break;
        case 5:
            (*(u8*) alpha_address) = 0x82;
            break;
        case 4:
            (*(u8*) alpha_address) = 0x69;
            break;
        case 3:
            (*(u8*) alpha_address) = 0x50;
            break;
        case 2:
            (*(u8*) alpha_address) = 0x37;
            break;
        case 1:
            (*(u8*) alpha_address) = 0x1E;
            break;
        case 0:
            (*(u8*) alpha_address) = 0x00;
            ap_memory.pc.text_ready = 1;
            break;
        default:
            break;
        }
    }
}

void TrapTimer()
{
    if(trap_timer > 0)
    {
        trap_timer--;
        if(trap_timer == 0)
        {
            gvr_fn_glover_cheat(0x16, 1);
            frogt = false;
        }
    }
}

void Goal()
{
  /*
  door 1 = always open
  door 2 = 1, 2, 3, 5, 6, 7, 9 (4,8)
  door 3 =  2, 3, 4, 5, 6, 7, (8, 9)
  boss = 4, 5, 6, 7, 8, 9
  bonus = 10 (second digit is the other doors)
  */
  u8 level = ap_memory.pc.current_world_key;
  switch(ap_memory.pc.worlds[level].hub_entrance)
  {
    case 1: // Atlantis Hub
        switch(ap_memory.pc.worlds[level].door)
        {
            case 1:
                gvr_gates.atl_door_2 = 1;
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.atl_1 = 1;
                }
                break;
            case 2:
                gvr_gates.atl_door_3 = 1;
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.atl_2 = 1;
                }
                break;
            case 3:
                gvr_gates.atl_door_boss = 1;
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.atl_3 = 1;
                }
                break;
            case 4:
                if(!ap_memory.pc.worlds[level].goal)
                {
                    gvr_wayroom_type = 0x0D;
                    spawn_ball_hub+=1;
                }
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_gates.atl_boss_defeated = 1;
                }
                break;
            case 5:
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.atl_bonus = 1;
                }
                break;
            default:
                break;
        }
        break;
    case 2: // Carnival Hub
        switch(ap_memory.pc.worlds[level].door)
        {
            case 1:
                gvr_gates.carn_door_2 = 1;
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.carn_1 = 1;
                }
                break;
            case 2:
                gvr_gates.carn_door_3 = 1;
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.carn_2 = 1;
                }
                break;
            case 3:
                gvr_gates.carn_door_boss = 1;
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.carn_3 = 1;
                }
                break;
            case 4:
                if(!ap_memory.pc.worlds[level].goal)
                {
                    gvr_wayroom_type = 0x0D;
                    spawn_ball_hub+=1;
                }
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_gates.carn_boss_defeated = 1;
                }
                break;
            case 5:
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.carn_bonus = 1;
                }
                break;
            default:
                break;
        }
        break;
    case 3: // Pirates Hub
        switch(ap_memory.pc.worlds[level].door)
        {
            case 1:
                gvr_gates.pir_door_2 = 1;
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.pir_1 = 1;
                }
                break;
            case 2:
                gvr_gates.pir_door_3 = 1;
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.pir_2 = 1;
                }
                break;
            case 3:
                gvr_gates.pir_door_boss = 1;
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.pir_3 = 1;
                }
                break;
            case 4:
                if(!ap_memory.pc.worlds[level].goal)
                {
                    gvr_wayroom_type = 0x0D;
                    spawn_ball_hub+=1;
                }
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_gates.pir_boss_defeated = 1;
                }
                break;
            case 5:
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.pir_bonus = 1;
                }
                break;
            default:
                break;
        }
        break;
    case 4: // Prehistoric Hub
        switch(ap_memory.pc.worlds[level].door)
        {
            case 1:
                gvr_gates.pre_door_2 = 1;
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.pre_1 = 1;
                }
                break;
            case 2:
                gvr_gates.pre_door_3 = 1;
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.pre_2 = 1;
                }
                break;
            case 3:
                gvr_gates.pre_door_boss = 1;
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.pre_3 = 1;
                }
                break;
            case 4:
                if(!ap_memory.pc.worlds[level].goal)
                {
                    gvr_wayroom_type = 0x0D;
                    spawn_ball_hub+=1;
                }
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_gates.pre_boss_defeated = 1;
                }
                break;
            case 5:
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.pre_bonus = 1;
                }
                break;
            default:
                break;
        }
        break;
    case 5: //Fear Hub
        switch(ap_memory.pc.worlds[level].door)
        {
            case 1:
                gvr_gates.fort_door_2 = 1;
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.fof_1 = 1;
                }
                break;
            case 2:
                gvr_gates.fort_door_3 = 1;
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.fof_2 = 1;
                }
                break;
            case 3:
                gvr_gates.fort_door_boss = 1;
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.fof_3 = 1;
                }
                break;
            case 4:
                if(!ap_memory.pc.worlds[level].goal)
                {
                    gvr_wayroom_type = 0x0D;
                    spawn_ball_hub+=1;
                }
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_gates.fort_boss_defeated = 1;
                }
                break;
            case 5:
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.fof_bonus = 1;
                }
                break;
            default:
                break;
        }
        break;
    case 6: //Space Hub
        switch(ap_memory.pc.worlds[level].door)
        {
            case 1:
                gvr_gates.spc_door_2 = 1;
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.spc_1 = 1;
                }
                break;
            case 2:
                gvr_gates.spc_door_3 = 1;
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.spc_2 = 1;
                }
                break;
            case 3:
                gvr_gates.spc_door_boss = 1;
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.spc_3 = 1;
                }
                break;
            case 4:
                if(!ap_memory.pc.worlds[level].goal)
                {
                    gvr_wayroom_type = 0x0D;
                    spawn_ball_hub+=1;
                }
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_gates.spc_boss_defeated = 1;
                }
                break;
            case 5:
                ap_memory.pc.worlds[level].goal = 1;
                if(level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
                    || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
                {
                    gvr_perfect.spc_bonus = 1;
                }
                break;
            default:
                break;
        }
        break;
    case 7: // Training Area
        switch(ap_memory.pc.worlds[level].door)
        {
            case 0:
                ap_memory.pc.worlds[level].goal = 1;
                break;
        }
    default:
        break;
    }
}


void UnlockStarWorld()
{
    for(int level = 1; level < AP_MAX_WORLDS; level++)
    {
        if (level == AP_ATLANTIS_BOSS || level == AP_CARNIVAL_BOSS || level == AP_PIRATES_BOSS || level == AP_PREHISTORIC_BOSS
            || level == AP_FORTRESS_BOSS || level == AP_SPACE_BOSS)
        {
            continue;
        }
        if(!ap_memory.pc.worlds[level].star) //No boss levels
        {
            if(ap_memory.pc.garib_totals[level] >= ap_memory.pc.max_garib_totals[level])
            {
                ap_memory.pc.worlds[level].star = 1;
                switch (ap_memory.pc.worlds[level].hub_entrance)
                {
                    case 1:
                        switch(ap_memory.pc.worlds[level].door)
                        {
                            case 1:
                                gvr_perfect.atl_1 = 1;
                                break;
                            case 2:
                                gvr_perfect.atl_2 = 1;
                                break;
                            case 3:
                                gvr_perfect.atl_3 = 1;
                                break;
                            case 4:
                                gvr_gates.atl_boss_defeated = 1;
                                break;
                            case 5:
                                gvr_perfect.atl_bonus = 1;
                                break;
                            default:
                                break;
                        }
                        break;
                    case 2:
                        switch(ap_memory.pc.worlds[level].door)
                        {
                            case 1:
                                gvr_perfect.carn_1 = 1;
                                break;
                            case 2:
                                gvr_perfect.carn_2 = 1;
                                break;
                            case 3:
                                gvr_perfect.carn_3 = 1;
                                break;
                            case 4:
                                gvr_gates.carn_boss_defeated = 1;
                                break;
                            case 5:
                                gvr_perfect.carn_bonus = 1;
                                break;
                            default:
                                break;
                        }
                        break;
                    case 3:
                        switch(ap_memory.pc.worlds[level].door)
                        {
                            case 1:
                                gvr_perfect.pir_1 = 1;
                                break;
                            case 2:
                                gvr_perfect.pir_2 = 1;
                                break;
                            case 3:
                                gvr_perfect.pir_3 = 1;
                                break;
                            case 4:
                                gvr_gates.pir_boss_defeated = 1;
                                break;
                            case 5:
                                gvr_perfect.pir_bonus = 1;
                                break;
                            default:
                                break;
                        }
                        break;
                    case 4:
                        switch(ap_memory.pc.worlds[level].door)
                        {
                            case 1:
                                gvr_perfect.pre_1 = 1;
                                break;
                            case 2:
                                gvr_perfect.pre_2 = 1;
                                break;
                            case 3:
                                gvr_perfect.pre_3 = 1;
                                break;
                            case 4:
                                gvr_gates.pre_boss_defeated = 1;
                                break;
                            case 5:
                                gvr_perfect.pre_bonus = 1;
                                break;
                            default:
                                break;
                        }
                        break;
                    case 5:
                        switch(ap_memory.pc.worlds[level].door)
                        {
                            case 1:
                                gvr_perfect.fof_1 = 1;
                                break;
                            case 2:
                                gvr_perfect.fof_2 = 1;
                                break;
                            case 3:
                                gvr_perfect.fof_3 = 1;
                                break;
                            case 4:
                                gvr_gates.fort_boss_defeated = 1;
                                break;
                            case 5:
                                gvr_perfect.fof_bonus = 1;
                                break;
                            default:
                                break;
                        }
                        break;
                    case 6:
                        switch(ap_memory.pc.worlds[level].door)
                        {
                            case 1:
                                gvr_perfect.spc_1 = 1;
                                break;
                            case 2:
                                gvr_perfect.spc_2 = 1;
                                break;
                            case 3:
                                gvr_perfect.spc_3 = 1;
                                break;
                            case 4:
                                gvr_gates.spc_boss_defeated = 1;
                                break;
                            case 5:
                                gvr_perfect.spc_bonus = 1;
                                break;
                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                }
            }
        }
    }
}

void UnlockSecret()
{
    for(int hub=1; hub < AP_MAX_HUB; hub++)
    {
        if(ap_memory.pc.secret_unlock[hub])
        {
            continue;
        }
        u8 stars = 0;
        u8 required = 0;
        for(int lvl=1; lvl< AP_MAX_WORLDS; lvl++)
        {
            if(lvl == AP_ATLANTIS_BOSS || lvl == AP_CARNIVAL_BOSS || lvl == AP_PIRATES_BOSS || lvl == AP_PREHISTORIC_BOSS
                || lvl == AP_FORTRESS_BOSS || lvl == AP_SPACE_BOSS) // No bosses
            {
                continue;
            }
            if(ap_memory.pc.worlds[lvl].hub_entrance == hub && ap_memory.pc.worlds[lvl].door != 5) // No secret level
            {
                stars += ap_memory.pc.worlds[lvl].star;
                required++;
            }
        }
        if(stars == required) //all valid worlds
        {
            switch (hub)
            {
                case 1:
                    gvr_gates.atl_door_bonus = 1;
                    ap_memory.pc.secret_unlock[hub] = 1;
                    break;
                case 2:
                    gvr_gates.carn_door_bonus = 1;
                    ap_memory.pc.secret_unlock[hub] = 1;
                    break;
                default:
                    break;
            }
        }
    }
}
