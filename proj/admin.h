#ifndef ADMIN_H_
#define ADMIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

/**

             __          _     
  ____ _____/ /___ ___  (_)___ 
 / __ `/ __  / __ `__ \/ / __ \
/ /_/ / /_/ / / / / / / / / / /
\__,_/\__,_/_/ /_/ /_/_/_/ /_/ 
                                           

*/
typedef struct {
    char ID[11];
    char password[20];;
    char contactNumber[20];
    char Email [20];
}Admin_S;

Admin_S AdminList[10];  // 管理员结构体数组
int NumberOfAdmin;  // 游客团数量


void loadAdmin(); //将管理员链表从文件中读入 
void dumpAdmin(); //将修改后的管理员链表保存到文件中 
void addAdmin(); //添加管理员(默认管理员操作) 
void showAdmin(); //展示现有管理员(默认管理员操作)
void AdminLogin();  //管理员登录 
//void AdminRegister(); //管理员注册 

int AdminIndex; //管理员索引 
void ChangeInfoOfAdminByAdmin();  //管理员修改自身信息 
void ChangeInfoOfAdmin(); //修改需要修改的管理员的信息 

#endif

