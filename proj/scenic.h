#ifndef SCENIC_FILE
#define SCENIC_FILE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 
#include "gui.h"

/**
   _____                 _     
  / ___/________  ____  (_)____
  \__ \/ ___/ _ \/ __ \/ / ___/
 ___/ / /__/  __/ / / / / /__  
/____/\___/\___/_/ /_/_/\___/  
                              

*/

typedef struct{
	char ID[8];  //景点信息 
	char Name[20]; //名称 
	char Description[100]; //景点描述 
	int peak_season_price;  //旺季价格 
    int off_season_price; //淡季期价格  
	char level[10]; //景点级别 
	float StudentAccount;  //学生折扣 
	float SoldierAccount;  //老人折扣
	int Spring_M;  //春日上午限制人数 
	int Spring_A;  //春日下午限制人数 
	int Summer_M;  //夏日上午限制人数 
	int Summer_A;  //夏日下午限制人数 
	int Autumn_A;  //秋日上午限制人数 
	int Autumn_M;  //秋日下午限制人数 
	int Winter_A;  //冬日上午限制人数 
	int Winter_M;  //冬日下午限制人数 
	
	char SeasonTimeRange[8][20]; //存储不同季节的时间限制 
	
	char Range[20];  //景点所属区域 
	float Costs; //景点维护费用 
	float Profit;  //景点利润为景点所售门票总价格减去景点维护费用 
	int Tickets_M[10]; //10天内上午的票
	int Tickets_A[10]; //10天内下午的票 
	int Views; //浏览量 
}Scenic;


Scenic scenicList[100]; //最多100个景点
int NumberOfScenic;

void loadScenic(); //将景点链表从文件中读入 
void dumpScenic(); //将修改后的景点链表保存到文件中 
void addScenic(); //添加景点(默认管理员操作) 
void showScenic(); //展示现有景点
void showScenicByAdmin(); //管理员界面的景点信息 
void PrintScenicTicketsRemain(int i); //打印景点不同时间的剩余票数 
void PrintScenicTicketsLimit(int i); 
void PrintWarn(int i);
#endif
