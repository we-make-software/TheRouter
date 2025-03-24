#include "../TheRouter/TheRouter.h"
#include "../TheNetworkAdapter/TheNetworkAdapter.h"
SetupTM(TheRouter,0,0,253,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255)
static void SlowReviewPacket(struct ReviewPacketData *rpd){
    if(!rpd)return;
  
}   
static void TMStart(void){
    //GetRouterTM();
    //TheRouterTM
}
static void TMEnd(void*data){
    kfree(data);
}
