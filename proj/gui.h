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

void menuSen();   //��ʼ�˵���Ӧ 
int menu();		//�˵� 

void adminMenuSen();  //����Ա�˵���Ӧ 
int adminMenu();   //����Ա�˵�
int adminGui();   //����Ա�����˵�
int SuperadminGui();   //��������Ա�����˵�
void adminGuiSen(); //����Ա�����˵���Ӧ
void SuperadminGuiSen(); //��������Ա�����˵���Ӧ 

void userMenuSen(); //�û��˵���Ӧ 
int userMenu(); //�û��˵� 
void userSen(); //�û����ܲ˵���Ӧ
int userGui(); //�û����ܲ˵� 

int userGuiback();  //�����ѯ�˵� 
void findScenic();  //�����ѯ����Ӧ 

int OrderStatisticsGui();  //ͳ���û���������˵� 
void OrderStatistics();  //ͳ���û����������Ӧ 



#endif

