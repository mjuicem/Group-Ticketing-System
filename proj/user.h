#ifndef USER_H_
#define USER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 
#include "gui.h"
#define MAX_GROUPS 1000  // ����ο�������
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

// �ο��Žṹ��
typedef struct {
    char ID[MAX_ID_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char Email[20];
    int numMembers;
    int ageLevel[10];
    char contactNumber[MAX_CONTACT_LENGTH];
    int selfIndex;
	int orderNumber; //Ĭ��Ϊ-1 ��û�ж��� 
} TouristGroup;

// �ο��Žṹ������
TouristGroup g_groups[MAX_GROUPS];
int g_number_of_groups;  // �ο�������
int UserIndex; //�ο������� 
//int UserOfNumberOfScenic; //�ο��ŵľ������ 

void loadUser(); //���û�������ļ��ж��� 
void dumpUser(); //���޸ĺ���û������浽�ļ��� 
void addUser(); //����û�(����Ա����) 
void showUser(); //չʾ�����û�(����Ա����) 
void showPersonalUser();


void userLogin();  //�û���¼ 
void userRegister(); //�û�ע�� 

void ChangeInfoOfUserByUser(); //�޸ĸ�����Ϣ 
void ChangeInfoOfUserByAdmin(); // ����Ա�޸ĸ�����Ϣ


#endif
