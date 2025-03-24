
#ifndef TheRouter_H
#define TheRouter_H
#include "../TheMaintainer/TheMaintainer.h"
struct TheRouter{
    SetupEWB;
    void(*SlowReviewPacket)(struct ReviewPacketData*);
};
#define GetRouterTM()TM(TheRouter,253,255,255,255,255,255,255,255,255,255,255,255,255,255,255)
#endif
