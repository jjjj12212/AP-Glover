#ifndef SAVED_H
#define SAVED_H
    #include "glover.h"
    void SaveData(int item, u8 amt);
    u8 GetSaveData(int item);
    void SaveDataBonusGoal(int world);
    void CleanSave();
    u16 GetCurrentSave();
    u8 GetDifficulty();
    void SetDifficulty(u8 value);
#endif