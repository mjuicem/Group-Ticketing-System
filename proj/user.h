#ifndef USER_H_
#define USER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 
#include "gui.h"
#define MAX_GROUPS 1000  // 最大游客团数量
#define MAX_ID_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_CONTACT_LENGTH 20
#define MAX_ARRAY_LENGTH 10

/**
   __  __              
  / / / /_______  _____
 / / / / ___/ _ \/ ___/
/ /_/ (__  )  __/ /    
\____/____/\___/_/     
                      
*/

// 游客团结构体
typedef struct {
    char ID[MAX_ID_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char Email[20];
    int numMembers;
    int ageLevel[10];
    char contactNumber[MAX_CONTACT_LENGTH];
    int selfIndex;
	int orderNumber; //默认为-1 即没有订单 
} TouristGroup;

// 游客团结构体数组
TouristGroup g_groups[MAX_GROUPS];
int g_number_of_groups;  // 游客团数量
int UserIndex; //游客团索引 
//int UserOfNumberOfScenic; //游客团的景点个数 

void loadUser(); //将用户链表从文件中读入 
void dumpUser(); //将修改后的用户链表保存到文件中 
void addUser(); //添加用户(管理员操作) 
void showUser(); //展示现有用户(管理员操作) 
void showPersonalUser();


void userLogin();  //用户登录 
void userRegister(); //用户注册 

void ChangeInfoOfUserByUser(); //修改个人信息 
void ChangeInfoOfUserByAdmin(); // 管理员修改个人信息


#endif
