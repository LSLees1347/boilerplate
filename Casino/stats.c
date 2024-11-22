#include "stats.h"

static int moneyCount = 0;
static int jackpotCount = 0;

void initStats()
{
    moneyCount = 0;
    jackpotCount = 0;
}

void incrementJackpots()
{
    jackpotCount++;
}

void addMoney(int toAdd)
{
    moneyCount = moneyCount + toAdd;
}

int getMoney()
{
    return moneyCount;
}

int getJackpot()
{
    return jackpotCount;
}