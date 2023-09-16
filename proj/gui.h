#ifndef GUI_H_
#define GUI_H_
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "function.h" 
#include "user.h"
#include "admin.h"
#include "scenic.h"
#include "order.h" 

/**
                _ 
   ____ ___  __(_)
  / __ `/ / / / / 
 / /_/ / /_/ / /  
 \__, /\__,_/_/   
/____/           
*/

void menuSen();   //初始菜单响应 
int menu();		//菜单 

void adminMenuSen();  //管理员菜单响应 
int adminMenu();   //管理员菜单
int adminGui();   //管理员操作菜单
int SuperadminGui();   //超级管理员操作菜单
void adminGuiSen(); //管理员操作菜单响应
void SuperadminGuiSen(); //超级管理员操作菜单响应 

void userMenuSen(); //用户菜单响应 
int userMenu(); //用户菜单 
void userSen(); //用户功能菜单响应
int userGui(); //用户功能菜单 

int userGuiback();  //景点查询菜单 
void findScenic();  //景点查询相响应 

int OrderStatisticsGui();  //统计用户订单情况菜单 
void OrderStatistics();  //统计用户订单情况响应 



#endif

