#include "admin.h"
#include "user.h"
void loadAdmin() {
    // ���ļ�
    FILE* fp_input = fopen("adminData.txt", "r");

    // while ��ѭ����ȡ�ļ�����
    while (1) {
        // ����ﵽ�ļ���β������ѭ��
        if (feof(fp_input)) {
            break;
        }

        // ����ɨ�������ֶ�
        char ID[20];
        char password[20];
        char PhoneNumber[20];
        char Email[20];
        fscanf(fp_input, "%s ", ID);
        fscanf(fp_input, "%s ", password);
        fscanf(fp_input, "%s ", PhoneNumber);
        fscanf(fp_input, "%s\n", Email);

        // ����ȡ�����ݱ��浽�ο��Žṹ��������
        strcpy(AdminList[NumberOfAdmin].ID,ID);
        strcpy(AdminList[NumberOfAdmin].password,password);
        strcpy(AdminList[NumberOfAdmin].contactNumber,PhoneNumber);
        strcpy(AdminList[NumberOfAdmin].Email,Email);

        // ���¹���Ա����������
        NumberOfAdmin ++;
    }

    // �ر��ļ�
    fclose(fp_input);

    printf(""YELLOW"@Test"NONE"���ӹ���Ա�ļ��м����� "LIGHT_GREEN"%d"NONE" ������Ա��Ϣ\n", NumberOfAdmin);
}




void dumpAdmin() {
    // ���ļ�
    FILE* fp_output = fopen("adminData.txt", "w");

    // �������飬������д��
    for (int i = 0; i < NumberOfAdmin; i++) {
        fprintf(fp_output, "%s ", AdminList[i].ID);
        fprintf(fp_output, "%s ", AdminList[i].password);
        fprintf(fp_output, "%s ", AdminList[i].contactNumber);
        fprintf(fp_output, "%s\n", AdminList[i].Email);
    }

    // �ر��ļ�
    fclose(fp_output);
}


void addAdmin(){
	// ��ӹ���Ա 
    while (1) {
    	printf(""LIGHT_GREEN"\n\tTIPS:����Ա������Ϊ6-10,��������Ϊ6-16λ,�������Ϊ���ֺ���ĸ�����,���벻�ܰ����ո�\n"NONE"");
        printf("\t��ӹ���Ա��Ϣ��\n");

        printf("\t������Ҫ��ӵĹ���Ա��ID: ");
        char ID[MAX_ID_LENGTH];
        scanf("%s", ID);
		ValidateID(ID);
        int found = 0;
        // �������У��������ң����β��Ҵ�ID�Ƿ����
        for (int i = 0; i < NumberOfAdmin; i++) {
            // ����
            if (strcmp(AdminList[i].ID, ID) == 0) {
                // ���
                found = 1;
                // ����ѭ��
                break;
            }
        }
        // ��������ظ���ID��������ʾ���� continue ������һ�� while ѭ����
        if (found) {
            printf("\tID�ظ����޷����\n");
            system("cls");
            continue;
        }
        printf("\t����������: ");
        char password[MAX_PASSWORD_LENGTH];
        scanf("%s", password);
		ValidatePassWord(password);
		
        printf("\t������绰����: ");
        char contactNumber[MAX_CONTACT_LENGTH];
        scanf("%s", contactNumber);
        ValidatePhoneNumber(contactNumber);
        printf("\t����������: ");
        char Email[MAX_CONTACT_LENGTH];
        scanf("%s", Email);
		ValidateEmail(Email);
        // ����������ݱ��浽����Ա�ṹ��������
        strcpy(AdminList[NumberOfAdmin].ID,ID);
        strcpy(AdminList[NumberOfAdmin].password,password);
        strcpy(AdminList[NumberOfAdmin].contactNumber,contactNumber);
        strcpy(AdminList[NumberOfAdmin].Email,Email);
	
		printf("\t�Ƿ�ȷ����ӹ���Ա?  [1]ȷ�� [2]ȡ��");
    	int choice = MyInput(1,3);
    	if(choice == 1){
    		// ���¹���Ա����������
        	NumberOfAdmin++;
			dumpAdmin(); 
        	printf("\t����ɹ����Ƿ�������(Y/N): ");
        	char yes_no[2];
        	scanf("%s", yes_no);
        	getchar();
        	// û������Y����y��������ѭ��
        	if (strcasecmp(yes_no, "Y") != 0) {
            	break;
        	}
        	system("cls");
		}else if(choice == 2){
			printf("\t"LIGHT_GREEN"�ɹ�ȡ���޸�!"NONE"");
			Sleep(3000);
			break; 
		}
        
    } 
    system("cls");
    SuperadminGuiSen();
    
}

void showAdmin(){
	for (int i = 0; i < NumberOfAdmin; i++) {
        printf("\n�� "LIGHT_RED"%d"NONE" ������Ա����Ϣ���£�\n", i + 1);
        printf("ID: "LIGHT_GREEN"%s"NONE"\n", AdminList[i].ID);
        printf("����: %s\n", AdminList[i].password);
        printf("��ϵ��ʽ: %s\n", AdminList[i].contactNumber);
		printf("����: %s\n", AdminList[i].Email);
        printf("-----------------------------------------------------\n");
    }
    system("pause");
    system("cls");
    SuperadminGuiSen();
}

void AdminLogin(){
	printf("\t��ӭ��������Ա��¼���棺\n");

        printf("\t����������ID: ");
        char ID[MAX_ID_LENGTH];
        char password[MAX_PASSWORD_LENGTH];
        scanf("%s", ID);
		int temp_Index_T = 0; 
        int found = 0;
        // �������У��������ң����β��Ҵ�ID�Ƿ����
        for (int i = 0; i < NumberOfAdmin; i++) {
            // ����
            if (strcmp(AdminList[i].ID, ID) == 0) {
                // ���
                found = 1;
                temp_Index_T = i; 
                // ����ѭ��
                break;
            }
        }

        if (!found) {
			getchar();
            printf("\t�ù���ԱID�����ڣ�����ϵ�����߻�ȡ����ԱȨ��\n");
            Sleep(3000);
            system("cls");
            adminMenuSen(); 
        }
        printf("\t����������: ");
        scanf("%s", password);
        int found2 = 0;
        if(strcmp(AdminList[temp_Index_T].password,password) == 0){
        	found2 = 1;
		}
		if(found2){
			getchar();
            printf("\n\t"LIGHT_GREEN"��¼�ɹ���"NONE"�ȴ�5�����ת������Ա���ܽ���......");
            AdminIndex = temp_Index_T;
            Sleep(2000);
            system("cls");
            if(AdminIndex == 5){
            	SuperadminGuiSen();
			}else{
				adminGuiSen();
			}
		}else{
			getchar();
            printf("\n\t"LIGHT_RED"�������."NONE"�ȴ�5�����ת������Ա��¼����......");
            Sleep(5000);
            system("cls");
            adminMenuSen(); 
		} 
}



void ChangeInfoOfAdminByAdmin(){
	char T[20];
	printf("\n\t�����������޸ĵ���Ϣ:("YELLOW"�绰"NONE","YELLOW"����"NONE","YELLOW"����"NONE"): "); 
	scanf("%s",T);
	char changeTemp[30];
	if(strcmp(T,"�绰") == 0){
		printf("\t��������Ҫ�޸ĵĵ绰����: "); 
		scanf("%s",changeTemp);
		ValidatePhoneNumber(changeTemp);
		strcpy(AdminList[AdminIndex].contactNumber,changeTemp); 
	}else if(strcmp(T,"����") == 0){
		printf("\t��������Ҫ�޸ĵ�����: ");
		scanf("%s",changeTemp);
		ValidatePassWord(changeTemp);
		strcpy(AdminList[AdminIndex].password,changeTemp); 
	}else if(strcmp(T,"����") == 0){
		printf("\t��������Ҫ�޸ĵ�����: ");
		scanf("%s",changeTemp);
		ValidateEmail(changeTemp);
		strcpy(AdminList[AdminIndex].Email,changeTemp); 
	}else{
		printf("\t������������,����������");
		Sleep(2000);;
		ChangeInfoOfAdminByAdmin();
	}
	

	printf("\t�Ƿ�ȷ���޸�?  [1]ȷ�� [2]ȡ�� [3]�޸�:");
    int choice = MyInput(1,3);
    if(choice == 1){
    	dumpAdmin();
		printf("\t"GREEN"�޸ĳɹ�!"NONE"");
		Sleep(3000);
		system("cls");
	}else if(choice == 2){
		printf("\t"LIGHT_GREEN"�ɹ�ȡ���޸�!"NONE"");
		Sleep(3000);
		system("cls");
	}else if(choice == 3){
		ChangeInfoOfAdminByAdmin();
	} 
	
	
	
	
	if(AdminIndex == 5){
		SuperadminGuiSen();
	}else{
		adminGuiSen();
	} 
	
}
	
	
void ChangeInfoOfAdmin(){
	char Name[30];
	printf("\n\t�����������޸ĵĹ���Ա������:");
	scanf("%s",Name);
	int Index;
	int found = 0;
	for(int i = 0;i < NumberOfAdmin ;i ++){
		if(strcmp(Name,AdminList[i].ID) == 0){
			Index = i;
			found = 1;
		}
	}
	
	if(found == 0){
		printf("\t�Ҳ����û�ID,����������\n");
		Sleep(2000);
		ChangeInfoOfAdmin();
	}
	
	 
	char T[20];
	printf("\n\t�����������޸ĵ���Ϣ("YELLOW"�绰"NONE" "YELLOW"����"NONE" "YELLOW"����"NONE"): "); 
	scanf("%s",T);
	char changeTemp[30];
	if(strcmp(T,"�绰") == 0){
		printf("\t��������Ҫ�޸ĵĵ绰����: "); 
		scanf("%s",changeTemp);
		ValidatePhoneNumber(changeTemp);
		strcpy(AdminList[Index].contactNumber,changeTemp); 
	}else if(strcmp(T,"����") == 0){
		printf("\t��������Ҫ�޸ĵ�����: ");
		scanf("%s",changeTemp);
		ValidatePassWord(changeTemp);
		strcpy(AdminList[Index].password,changeTemp); 
	}else if(strcmp(T,"����") == 0){
		printf("\t��������Ҫ�޸ĵ�����: ");
		scanf("%s",changeTemp);
		ValidateEmail(changeTemp);
		strcpy(AdminList[Index].Email,changeTemp); 
	}else{
		printf("\t������������,����������");
		ChangeInfoOfAdmin();
		Sleep(3000);
		system("cls"); 
	}
	
	printf("\t�Ƿ�ȷ���޸�?  [1]ȷ�� [2]ȡ�� [3]�޸�:");
    int choice = MyInput(1,3);
    if(choice == 1){
    	dumpAdmin();
		printf("\t"LIGHT_GREEN"�޸ĳɹ�!"NONE"");
		Sleep(3000);
		system("cls");
	}else if(choice == 2){
		printf("\t"LIGHT_GREEN"�ɹ�ȡ���޸�!"NONE"");
		Sleep(3000);
		system("cls");
	}else if(choice == 3){
		ChangeInfoOfAdmin();
	}
	
	if(AdminIndex == 5){
		SuperadminGuiSen();
	}else{
		adminGuiSen();
	} 		
}
