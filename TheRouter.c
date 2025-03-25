#include "../TheRouter/TheRouter.h"
#include "../TheNetworkAdapter/TheNetworkAdapter.h"
SetupTM(TheRouter,0,0,253,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255)
static void ReviewPacket(struct ReviewPacketData *rpd){
    if(!rpd)return;

    printk (KERN_INFO "TheRouter: SlowReviewPacket has been called.\n");
}   
static void TMStart(void){
    GetTheRouterTM();
    SetTM(TheRouterTM,ReviewPacket);
    //GetRouterTM();
    //TheRouterTM
}
static void TMEnd(void*data){

}
