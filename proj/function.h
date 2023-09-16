#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <stdio.h>
#include <string.h>
#include <stdbool.h> 
#include <time.h>
#include <math.h>
#include "scenic.h" 

//��ɫ�궨��
#define NONE         "\033[m"
#define RED          "\033[0;32;31m"
#define LIGHT_RED    "\033[1;31m"
#define GREEN        "\033[0;32;32m"
#define LIGHT_GREEN  "\033[1;32m"
#define BLUE         "\033[0;32;34m"
#define LIGHT_BLUE   "\033[1;34m"
#define DARY_GRAY    "\033[1;30m"
#define CYAN         "\033[0;36m"
#define LIGHT_CYAN   "\033[1;36m"
#define PURPLE       "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BROWN        "\033[0;33m"
#define YELLOW       "\033[1;33m"
#define LIGHT_GRAY   "\033[0;37m"
#define WHITE        "\033[1;37m"



/**
    ____                 __  _           
   / __/_  ______  _____/ /_(_)___  ____ 
  / /_/ / / / __ \/ ___/ __/ / __ \/ __ \
 / __/ /_/ / / / / /__/ /_/ / /_/ / / / /
/_/  \__,_/_/ /_/\___/\__/_/\____/_/ /_/ 
                                       

*/

int MyInput(int low,int high);  //��� 
bool validateID(const char* id);  //�ж�ID�Ƿ���Ч 
bool validatePhoneNumber(const char* phoneNumber); //�жϵ绰�����Ƿ���Ч
bool validateEmail(const char* Email); //�ж������Ƿ���Ч 
bool validatePassWord(const char* PassWord); //�ж������Ƿ���Ч 
bool isDateFormatValid(const char* timeStr); //�ж��û������ʱ���ʽ�Ƿ���ȷ 


void ValidateID(const char* id);  //�ж�ID�Ƿ���Ч 
void ValidatePhoneNumber(const char* phoneNumber); //�жϵ绰�����Ƿ���Ч
void ValidateEmail(const char* Email); //�ж������Ƿ���Ч 
void ValidatePassWord(const char* PassWord); //�ж������Ƿ���Ч 
void ValidateOrderNumber();   //�ж϶������Ƿ���Ч 



void parseTime(const char* timeStr, int* year, int* month, int* day, int* hour); //ת��ʱ���ַ�����ʽ 
int calculateDayDifference(const char* startTime,const char* endTime); //����������ʽΪ"yyyy:mm:dd:ss"��ʱ���������� 
int getMonth(const char* timeStr); //�ж��·� 
int isDateTimeInRange(const char* dateTimeStr);  


void searchByName();  //���ݾ������Ʋ�ѯ
void searchByRegion();  //���ݾ��������ѯ
void PriceSort();  //���ݼ۸������������
void ReserveSort();   //����Ԥ�������� 
void searchByTickets(); //�����Ƿ���Ʊ���в�ѯ 
void ViewsSort();  //������������������ 
void HotTimeSort();  //������ʱ�����ͳ�� 
void ProfitSort(); //���������ͳ������
void ageLevelSort();  //���û������ηֲ�ͳ������ 
void SeasonSoldSort(); // �����ȶԲ�ͬ�������Ʊ�����������,�Ƚϲ�ͬ�����ڲ�ͬ���ȵķ������ 
void showScenicByAccount();
void HotSort();  //Ԥ����+����������� 


void CLEANBUFF(); //������ 
#endif

