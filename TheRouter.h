
#ifndef TheRouter_H
#define TheRouter_H
#include "../TheMaintainer/TheMaintainer.h"
struct ReviewPacketData;
struct TheRouter{
    SetupEWB;
    void(*ReviewPacket)(struct ReviewPacketData*);
};
#define GetTheRouterTM()TM(TheRouter,253,255,255,255,255,255,255,255,255,255,255,255,255,255,255)
#endif
