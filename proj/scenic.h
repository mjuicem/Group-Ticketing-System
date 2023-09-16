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
	char ID[8];  //������Ϣ 
	char Name[20]; //���� 
	char Description[100]; //�������� 
	int peak_season_price;  //�����۸� 
    int off_season_price; //�����ڼ۸�  
	char level[10]; //���㼶�� 
	float StudentAccount;  //ѧ���ۿ� 
	float SoldierAccount;  //�����ۿ�
	int Spring_M;  //���������������� 
	int Spring_A;  //���������������� 
	int Summer_M;  //���������������� 
	int Summer_A;  //���������������� 
	int Autumn_A;  //���������������� 
	int Autumn_M;  //���������������� 
	int Winter_A;  //���������������� 
	int Winter_M;  //���������������� 
	
	char SeasonTimeRange[8][20]; //�洢��ͬ���ڵ�ʱ������ 
	
	char Range[20];  //������������ 
	float Costs; //����ά������ 
	float Profit;  //��������Ϊ����������Ʊ�ܼ۸��ȥ����ά������ 
	int Tickets_M[10]; //10���������Ʊ
	int Tickets_A[10]; //10���������Ʊ 
	int Views; //����� 
}Scenic;


Scenic scenicList[100]; //���100������
int NumberOfScenic;

void loadScenic(); //������������ļ��ж��� 
void dumpScenic(); //���޸ĺ�ľ��������浽�ļ��� 
void addScenic(); //��Ӿ���(Ĭ�Ϲ���Ա����) 
void showScenic(); //չʾ���о���
void showScenicByAdmin(); //����Ա����ľ�����Ϣ 
void PrintScenicTicketsRemain(int i); //��ӡ���㲻ͬʱ���ʣ��Ʊ�� 
void PrintScenicTicketsLimit(int i); 
void PrintWarn(int i);
#endif
