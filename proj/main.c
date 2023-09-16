#include "user.h"
#include "gui.h"
#include "function.h"
#include "admin.h" 
#include "scenic.h"
#include "order.h" 

/**
                    _                   
   ____ ___  ____ _(_)___          _____
  / __ `__ \/ __ `/ / __ \        / ___/
 / / / / / / /_/ / / / / /  _    / /__  
/_/ /_/ /_/\__,_/_/_/ /_/  (_)   \___/ 


*/

int main(int argc, char *argv[]) {
	 // 从文件中加载游客团信息
    loadUser(); //读入旅游团链表 
    loadAdmin(); //读入管理员链表 
    loadScenic(); //读入景点信息 
    loadOrder(); //读入订单信息 
	menuSen();  //进入主菜单响应页面 
    return 0;
}
