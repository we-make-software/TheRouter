#include "../TheRouter/TheRouter.h"
static struct TheMailConditione*tmcRouters,*tmcTheRouterAPI;
struct TheMailConditioner*GetMediaAccessControl(u8*value);
struct TheMailConditioner*GetMediaAccessControl(u8*value){
   
}
static struct list_head*GetTheRouters(void){
    return (struct list_head*)GetTheMailConditionerData(tmcRouters);
}
static void End(void){
    CancelTheMailConditioner(tmcRouters);
    CancelTheMailConditioner(tmcTheRouterAPI);
}
static void AutoDeleteRouters(void*data,struct ExpiryWorkBaseBenchmark){

}
static void AutoDeleteAPI(void* data,struct ExpiryWorkBaseBenchmark){
    kfree(data);
}
static void Start(void){
    tmcRouters=GetTheMaintainer((u8[]){254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255});
    if (!GetTheMailConditionerUnsafeData(tmcRouters)){
        if(!SetTheMailConditionerData(tmcRouters,kmalloc(sizeof(struct list_head),GFP_KERNEL))){
            printk(KERN_ERR "TheRouter: Can't allocate memory for routers list.\n");
            End();
            return;
        }
        INIT_LIST_HEAD((struct list_head*)*GetTheMailConditionerUnsafeData(tmcRouters));
        SetAutoDeleteTheMailConditioner(tmcRouters,AutoDeleteRouters);
    }
    tmcTheRouterAPI=GetTheMaintainer((u8[]){255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255});
    if (!GetTheMailConditionerUnsafeData(tmcTheRouterAPI)){
        if(!SetTheMailConditionerData(tmcTheRouterAPI,kmalloc(sizeof(struct TheRouter),GFP_KERNEL))){
            printk(KERN_ERR "TheRouter: Can't allocate memory for the router api.\n");
            End();
            return;
        }
        SetAutoDeleteTheMailConditioner(tmcTheRouterAPI,AutoDeleteAPI);
        struct TheRouter*RouterAPI=(struct TheRouter*)GetTheMailConditionerData(tmcTheRouterAPI);
        RouterAPI->GetTheRouters=GetTheRouters;
    }
    
}
Setup("TheRouter",0,0)