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

//�����ṹ�� 
typedef struct{
	char ID[30]; //�������
	char ReserveTime[30]; //Ԥ��ʱ��
	char GoTime[5][30];  //����ʱ��
	int State; 
	int age[10]; //�����
	int numberOfGroup; //��������
	int price; //�����۸� 
	int OrderIndex; //��������
	int UserIndex; //�û����� 
	int ScenicIndex[5]; //�������� 
	int NumberOfScenicIndex; //����ĸ��� 
}Order;

Order OrderList[100]; //�������� 

int NumberOfOrder; // �������� 

void loadOrder(); //������������ļ��ж��� 
void dumpOrder(); //���޸ĺ�Ķ��������浽�ļ��� 
void initOrder();  //��ʼ������ 
void addOrder(); //��Ӷ���(Ĭ�Ϲ���Ա����) 
void showOrderByAdmin(); //չʾ���ж���(Ĭ�Ϲ���Ա����)
void showOrderByUser(); //չʾ�û���ǰ���� 
void DeleteOrder();  //ɾ������ 


#endif
