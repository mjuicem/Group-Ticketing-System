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

Admin_S AdminList[10];  // ����Ա�ṹ������
int NumberOfAdmin;  // �ο�������


void loadAdmin(); //������Ա������ļ��ж��� 
void dumpAdmin(); //���޸ĺ�Ĺ���Ա�����浽�ļ��� 
void addAdmin(); //��ӹ���Ա(Ĭ�Ϲ���Ա����) 
void showAdmin(); //չʾ���й���Ա(Ĭ�Ϲ���Ա����)
void AdminLogin();  //����Ա��¼ 
//void AdminRegister(); //����Աע�� 

int AdminIndex; //����Ա���� 
void ChangeInfoOfAdminByAdmin();  //����Ա�޸�������Ϣ 
void ChangeInfoOfAdmin(); //�޸���Ҫ�޸ĵĹ���Ա����Ϣ 

#endif

