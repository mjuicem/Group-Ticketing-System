#ifndef ORDER_FILE
#define ORDER_FILE
#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gui.h" 
#include <time.h> 

/**
                  __         
  ____  _________/ /__  _____
 / __ \/ ___/ __  / _ \/ ___/
/ /_/ / /  / /_/ /  __/ /    
\____/_/   \__,_/\___/_/  

*/

//订单结构体 
typedef struct{
	char ID[30]; //订单编号
	char ReserveTime[30]; //预定时间
	char GoTime[5][30];  //出行时间
	int State; 
	int age[10]; //年龄段
	int numberOfGroup; //出行人数
	int price; //订单价格 
	int OrderIndex; //订单索引
	int UserIndex; //用户索引 
	int ScenicIndex[5]; //景点索引 
	int NumberOfScenicIndex; //景点的个数 
}Order;

Order OrderList[100]; //订单链表 

int NumberOfOrder; // 订单数量 

void loadOrder(); //将订单链表从文件中读入 
void dumpOrder(); //将修改后的订单链表保存到文件中 
void initOrder();  //初始化订单 
void addOrder(); //添加订单(默认管理员操作) 
void showOrderByAdmin(); //展示现有订单(默认管理员操作)
void showOrderByUser(); //展示用户当前订单 
void DeleteOrder();  //删除订单 


#endif
