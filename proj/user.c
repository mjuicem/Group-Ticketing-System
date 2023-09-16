#include "user.h"
void loadUser() {
    // ���ļ�
    FILE* fp_input = fopen("userData.txt", "r");

    // while ��ѭ����ȡ�ļ�����
    while (1) {
        // ����ﵽ�ļ���β������ѭ��
        if (feof(fp_input)) {
            break;
        }

        // ����ɨ�������ֶ�
        char ID[MAX_ID_LENGTH];
        char password[MAX_PASSWORD_LENGTH];
        char Email[20];
        int numMembers;
        int ageLevel[10];
        char contactNumber[MAX_CONTACT_LENGTH];
		int selfIndex_T;
		int orderNumber_T;
        fscanf(fp_input, "%s ", ID);
        fscanf(fp_input, "%s ", password);
        fscanf(fp_input, "%s ", Email);
        fscanf(fp_input, "%d ", &numMembers);
        for(int i = 0;i < 10;i ++){
        	fscanf(fp_input,"%d ",&ageLevel[i]);
		}
        fscanf(fp_input, "%s ", contactNumber);
        fscanf(fp_input, "%d ", &selfIndex_T);
        fscanf(fp_input, "%d\n", &orderNumber_T);

        // ����ȡ�����ݱ��浽�ο��Žṹ��������
        strcpy(g_groups[g_number_of_groups].ID, ID);
        strcpy(g_groups[g_number_of_groups].password, password);
        strcpy(g_groups[g_number_of_groups].Email, Email);
        g_groups[g_number_of_groups].numMembers = numMembers;
        for(int i = 0;i < 10;i ++){
        	g_groups[g_number_of_groups].ageLevel[i] = ageLevel[i];
		}
        strcpy(g_groups[g_number_of_groups].contactNumber, contactNumber);
        g_groups[g_number_of_groups].selfIndex = selfIndex_T;
		g_groups[g_number_of_groups].orderNumber = orderNumber_T;


        // �����ο�������������
        g_number_of_groups += 1;
    }

    // �ر��ļ�
    fclose(fp_input);

    printf(""YELLOW"@Test"NONE"�����ο����ļ��м����� "LIGHT_GREEN"%d"NONE" ���ο�����Ϣ\n", g_number_of_groups);
}

void dumpUser() {
    // ���ļ�
    FILE* fp_output = fopen("userData.txt", "w");

    // �������飬������д��
    for (int i = 0; i < g_number_of_groups; i++) {
        fprintf(fp_output, "%s ", g_groups[i].ID);
        fprintf(fp_output, "%s ", g_groups[i].password);
        fprintf(fp_output, "%s ", g_groups[i].Email);
        fprintf(fp_output, "%d ", g_groups[i].numMembers);
        for(int t = 0;t < 10;t ++){
        	fprintf(fp_output, "%d ", g_groups[i].ageLevel[t]);
		}
        fprintf(fp_output, "%s ", g_groups[i].contactNumber);
        fprintf(fp_output, "%d ", g_groups[i].selfIndex);
        fprintf(fp_output, "%d\n", g_groups[i].orderNumber);
        
    }

    // �ر��ļ�
    fclose(fp_output);
}


void addUser() {
    // ����ο���
    while (1) {
        printf("\t����ο�����Ϣ��\n");

        printf("\t������ID: ");
        char ID[MAX_ID_LENGTH];
        scanf("%s", ID);
		ValidateID(ID);
        int found = 0;
        // �������У��������ң����β��Ҵ�ID�Ƿ����
        for (int i = 0; i < g_number_of_groups; i++) {
            // ����
            if (strcmp(g_groups[i].ID, ID) == 0) {
                // ���
                found = 1;
                // ����ѭ��
                break;
            }
        }

        // ��������ظ���ID��������ʾ���� continue ������һ�� while ѭ����
        if (found) {
            printf("ID�ظ����޷����\n");
            continue;
        }
	
        printf("����������: ");
        char password[MAX_PASSWORD_LENGTH];
        scanf("%s", password);
		ValidatePassWord(password);
		
		printf("����������: ");
		char Email[20];
		scanf("%s",Email);
		ValidateEmail(Email);
		
        printf("����������: ");
        int numMembers;
        scanf("%d", &numMembers);
		while(numMembers <= 0 || numMembers >= 100){
    		printf("\t��������ȷ������,��������Ϊ1-100: ");
			scanf("%d",&numMembers); 
		}
		int ageLevel[10];
		int temp_numMembers;
        for(int i = 0;i < 10;i ++){
        	printf("������� %d ����ε�����: ",i);
        	scanf("%d",&ageLevel[i]);
        	//validate()
        	temp_numMembers += ageLevel[i]; 
		}
		if(numMembers != temp_numMembers){
			printf("��������,����������\n");
			system("cls");
			addUser();
		}
		
        printf("��������ϵ��ʽ: ");
        char contactNumber[MAX_CONTACT_LENGTH];
        scanf("%s", contactNumber);
		ValidatePhoneNumber(contactNumber);
        // ����������ݱ��浽�ο��Žṹ��������
        strcpy(g_groups[g_number_of_groups].ID, ID);
        strcpy(g_groups[g_number_of_groups].password, password);
        strcpy(g_groups[g_number_of_groups].Email, Email);
        g_groups[g_number_of_groups].numMembers = numMembers;
       	for(int i = 0;i < 10;i ++){
       		g_groups[g_number_of_groups].ageLevel[i] = ageLevel[i];
		   }
        strcpy(g_groups[g_number_of_groups].contactNumber, contactNumber);
		g_groups[g_number_of_groups].selfIndex = g_number_of_groups;
    	g_groups[g_number_of_groups].orderNumber = -1;

        // �����ο�������������
        g_number_of_groups+=1;

        printf("����ɹ����Ƿ�������(Y/N): ");
        char yes_no[2];
        scanf("%s", yes_no);
        // û������Y����y��������ѭ��
        if (strcasecmp(yes_no, "Y") != 0) {
            break;
        }
    } // end of while loop
}
//		printf("��������: %d\n", OrderList[g_groups[UserIndex].orderNumber].numberOfGroup);
//		printf("�����۸�: %d\n", OrderList[g_groups[UserIndex].orderNumber].price);
void showUser() {
    for (int i = 0; i < g_number_of_groups; i++) {
        printf("�� "YELLOW"%d"NONE" ���ο��ŵ���Ϣ���£�\n", i + 1);
        printf("ID: "LIGHT_GREEN"%s"NONE"\n", g_groups[i].ID);
        printf("����: %s\n", g_groups[i].password);
        printf("����: %s\n",g_groups[i].Email);
        printf("����: %d\n", g_groups[i].numMembers);
        printf("�ο�����֧�����ܷ���: "LIGHT_RED"%d"NONE"\n", OrderList[g_groups[i].orderNumber].price);
        for(int j = 0;j < 5;j ++){
			printf("�� "LIGHT_GREEN"%d"NONE" ����������: "YELLOW"%s"NONE"  %s\n",j + 1, scenicList[OrderList[g_groups[i].orderNumber].ScenicIndex[j]].ID
												,scenicList[OrderList[g_groups[i].orderNumber].ScenicIndex[j]].Name);
			printf("Ԥ������ʱ��: %s\n\n",OrderList[g_groups[i].orderNumber].GoTime[j]);
		}
        for(int t = 0;t < 10;t ++){
        	printf("�� %d �����ε�������: "LIGHT_RED"%d"NONE"\n",t,g_groups[i].ageLevel[t]);
		}
        printf("��ϵ��ʽ: %s\n", g_groups[i].contactNumber);
        printf("�ο��ű��: %d\n", g_groups[i].selfIndex);
        printf("�������: %d\n", g_groups[i].orderNumber);
        printf("-----------------------------------------------------\n");
    }
    system("pause");
    system("cls");
    if(AdminIndex == 5){
		SuperadminGuiSen();
	}else{
		adminGuiSen();
	} 
}


void userRegister() {
    // ����ο���
        printf("\t��ӭ�����û�ע����棺\n");
		printf(""LIGHT_GREEN"\tTIPS:�û�������Ϊ6-10,��������Ϊ6-16λ,�������Ϊ���ֺ���ĸ�����,���벻�ܰ����ո�\n"NONE"");
        printf("\t����������ע����ο���ID: ");
        char ID[MAX_ID_LENGTH];
        scanf("%s",ID);
		ValidateID(ID); 
        int found = 0;
        // �������У��������ң����β��Ҵ�ID�Ƿ����
        for (int i = 0; i < g_number_of_groups; i++) {
            // ����
            if (strcmp(g_groups[i].ID, ID) == 0) {
                // ���
                found = 1;
                // ����ѭ��
                break;
            }
        }
        while (found) {
            printf("\tID�ظ���������\n");
            Sleep(3000);
            userRegister(); 
        }

        printf("\t����������: ");
        char password[MAX_PASSWORD_LENGTH];
        char confirmPassword[MAX_PASSWORD_LENGTH];
        scanf("%s",password);
        CLEANBUFF();  //������ 
        ValidatePassWord(password);
		printf("\t��ȷ���������: ");
    	scanf("%s",confirmPassword);
    	CLEANBUFF();
   		while(strcmp(password, confirmPassword) != 0) // �ж������ַ����Ƿ����
    	{
       		printf("\t���벻��ȷ�������������������: ");
       	 	scanf("%s",password);
       	 	ValidatePassWord(password);
        	printf("\t��ȷ���������: ");
        	scanf("%s",confirmPassword);
        	CLEANBUFF();
   		}
   		printf("\t�������������: ");
   		char Email[20];
   		scanf("%s",Email);
   		ValidateEmail(Email);
        printf("\t����������(��������Ϊ1-100): ");
        int numMembers = MyInput(1,100);
        printf("\t������������:\n ");
        int ageLevel[10];
        int temp_count_ageLevel = 0;
        for(int i = 0;i < 10;i ++){
        	printf("\t�� %d0 �� %d0 �����ε�����: ",i,i+1);
        	scanf("%d",&ageLevel[i]);
        	CLEANBUFF();
        	while(ageLevel[i] < 0){
        		printf("\t��������Ч������: ");
        		scanf("%d",&ageLevel[i]);
        		CLEANBUFF();
			}
        	temp_count_ageLevel += ageLevel[i]; 
        	if(temp_count_ageLevel > numMembers){
        		printf("\n\t"LIGHT_RED"��ǰ�������������ƥ��,ע��ʧ��,����������"NONE"\n");
        		printf("\t");
				system("pause");
				userRegister(); 
			}
		}
		if(temp_count_ageLevel != numMembers){
			printf("\n\t"LIGHT_RED"��ǰ�������������ƥ��,ע��ʧ��,����������"NONE"\n");
			printf("\t");
			system("pause");
			userRegister();
		}
		 
        printf("\t��������ϵ��ʽ: ");
        char contactNumber[MAX_CONTACT_LENGTH];
        scanf("%s", contactNumber);
        CLEANBUFF();
        ValidatePhoneNumber(contactNumber);
		
        // ����������ݱ��浽�ο��Žṹ��������
        strcpy(g_groups[g_number_of_groups].ID, ID);
        strcpy(g_groups[g_number_of_groups].password, password);
        strcpy(g_groups[g_number_of_groups].Email, Email);\
        
        g_groups[g_number_of_groups].numMembers = numMembers;
        for(int i = 0;i < 10;i ++){
        	g_groups[g_number_of_groups].ageLevel[i] = ageLevel[i];
		}
        strcpy(g_groups[g_number_of_groups].contactNumber, contactNumber);
		g_groups[g_number_of_groups].selfIndex = g_number_of_groups;
    	g_groups[g_number_of_groups].orderNumber = -1;
        g_number_of_groups ++;
		
		dumpUser(); //���� 
		
   	 	printf("\n\t"LIGHT_GREEN"ע��ɹ���"NONE"�ȴ�5�����ת���û��˵�����......");
    	Sleep(5000);
    	system("cls");
    	userMenuSen();
        
     // end of while loop
}


void userLogin(){ 
	printf("\t��ӭ�����û���¼���棺\n");

        printf("\t�����������ο���ID: ");
        char ID[MAX_ID_LENGTH];
        char password[MAX_PASSWORD_LENGTH];
        scanf("%s", ID);

        int found = 0;
        int temp_Index;
        // �������У��������ң����β��Ҵ�ID�Ƿ����
        for (int i = 0; i < g_number_of_groups; i++) {
            // ����
            if (strcmp(g_groups[i].ID, ID) == 0) {
                // ���
                found = 1;
                temp_Index = i;
                // ����ѭ��
                break;
            }
        }

        if (!found) {
            printf("\t���ο���ID�����ڣ�����ע���ٵ�¼");
            Sleep(3000);
    		system("cls"); 
    		getchar();
            userMenuSen(); 
        }
        printf("\t����������: ");
        scanf("%s", password);
        int found2 = 0;
        if(strcmp(g_groups[temp_Index].password,password) == 0){
        	found2 = 1;
		} 
		if(found2){
			getchar();
            printf("\n\t"LIGHT_GREEN"��¼�ɹ���"NONE"�ȴ�5�����ת���û����ܽ���......");
            Sleep(2000);
            system("cls");
            UserIndex =  temp_Index; 
            userSen();
		}else{
			getchar();
            printf("\n\t"LIGHT_RED"�������"NONE"�ȴ�5�����ת���û��˵�����......");
            Sleep(5000);
            system("cls");
            userMenuSen();
		} 
}


void ChangeInfoOfUserByUser(){
	char T[20];
	printf("\n\t�����������޸ĵ���Ϣ(�绰 ���� ����): "); 
	scanf("%s",T);
	char changeTemp[30];
	if(strcmp(T,"�绰") == 0){
		printf("\t��������Ҫ�޸ĵĵ绰����: "); 
		scanf("%s",changeTemp);
		ValidatePhoneNumber(changeTemp);
		strcpy(g_groups[UserIndex].contactNumber,changeTemp); 
	}else if(strcmp(T,"����") == 0){
		printf("\t��������Ҫ�޸ĵ�����: ");
		scanf("%s",changeTemp);
		ValidatePassWord(changeTemp);
		strcpy(g_groups[UserIndex].password,changeTemp); 
	}else if(strcmp(T,"����") == 0){
		printf("\t��������Ҫ�޸ĵ�����: ");
		scanf("%s",changeTemp);
		ValidateEmail(changeTemp);
		strcpy(g_groups[UserIndex].Email,changeTemp); 
	}else{
		printf("\t������������,����������");
		Sleep(2000);
		system("cls");
		ChangeInfoOfUserByUser(); 
	}
	printf("\t�Ƿ�ȷ���޸�?  [1]ȷ�� [2]ȡ�� [3]�޸�:");
    int choice = MyInput(1,3);
    if(choice == 1){
    	dumpUser();
		printf("\t"LIGHT_GREEN"�޸ĳɹ�!"NONE"");
		Sleep(3000);
		system("cls");
		userSen();
	}else if(choice == 2){
		printf("\t"LIGHT_GREEN"�ɹ�ȡ���޸�!"NONE"");
		Sleep(3000);
		system("cls");
		userSen();
	}else if(choice == 3){
		ChangeInfoOfUserByUser();
	} 
	
	
}


void ChangeInfoOfUserByAdmin(){
	char Name[30];
	printf("\n\t�����������޸ĵ��û�������:");
	scanf("%s",Name);
	int Index;
	int found = 0;
	for(int i = 0;i < g_number_of_groups;i ++){
		if(strcmp(Name,g_groups[i].ID) == 0){
			Index = i;
			found = 1;
		}
	}
	
	if(found == 0){
		printf("�Ҳ����û�ID,����������\n");
		Sleep(2000);
		system("cls");
		ChangeInfoOfUserByAdmin();
	}
	
	 
	char T[20];
	printf("\n\t�����������޸ĵ���Ϣ("YELLOW"�绰"NONE" "YELLOW"����"NONE" "YELLOW"����"NONE"): "); 
	scanf("%s",T);
	char changeTemp[30];
	if(strcmp(T,"�绰") == 0){
		printf("\t��������Ҫ�޸ĵĵ绰����: "); 
		scanf("%s",changeTemp);
		ValidatePhoneNumber(changeTemp);
		strcpy(g_groups[Index].contactNumber,changeTemp); 
	}else if(strcmp(T,"����") == 0){
		printf("\t��������Ҫ�޸ĵ�����: ");
		scanf("%s",changeTemp);
		ValidatePassWord(changeTemp);
		strcpy(g_groups[Index].password,changeTemp); 
	}else if(strcmp(T,"����") == 0){
		printf("\t��������Ҫ�޸ĵ�����: ");
		scanf("%s",changeTemp);
		ValidateEmail(changeTemp);
		strcpy(g_groups[Index].Email,changeTemp); 
	}else{
		printf("\t������������,����������");
		ChangeInfoOfUserByAdmin();
		Sleep(3000);
		system("cls"); 
	}
	
	printf("\t�Ƿ�ȷ���޸�?  [1]ȷ�� [2]ȡ�� [3]�޸�:");
    int choice = MyInput(1,3);
    if(choice == 1){
    	dumpUser();
		printf("\t"LIGHT_GREEN"�޸ĳɹ�!"NONE"");
		Sleep(3000);
		system("cls");
	}else if(choice == 2){
		printf("\t"LIGHT_GREEN"�ɹ�ȡ���޸�!"NONE"");
		Sleep(3000);
		system("cls");
	}else if(choice == 3){
		ChangeInfoOfUserByAdmin();
	}
	
	if(AdminIndex == 5){
		SuperadminGuiSen();
	}else{
		adminGuiSen();
	} 		
}


void showPersonalUser(){
	printf("\n�ο����û� "YELLOW"%s"NONE" ����Ϣ���£�\n",g_groups[UserIndex].ID);
    printf("�������: "LIGHT_GREEN"%s"NONE"\n", OrderList[g_groups[UserIndex].orderNumber].ID);
    printf("�ο�������: %s\n",g_groups[OrderList[g_groups[UserIndex].orderNumber].UserIndex].password);
    printf("�ο��ŵ绰: %s\n",g_groups[OrderList[g_groups[UserIndex].orderNumber].UserIndex].contactNumber);
    printf("�ο�������: %s\n",g_groups[OrderList[g_groups[UserIndex].orderNumber].UserIndex].Email);
    printf("��������ʱ��: "LIGHT_GREEN"%s"NONE"\n", OrderList[g_groups[UserIndex].orderNumber].ReserveTime);
    //printf("����ʱ��: %s\n", OrderList[g_groups[UserIndex].orderNumber].GoTime);
	printf("����״̬: %d\n", OrderList[g_groups[UserIndex].orderNumber].State);
	for(int t = 0;t < 10;t ++){
		printf("����� %d0 - %d0 �� "LIGHT_GREEN"%d"NONE" ��\n",t,t+1,OrderList[g_groups[UserIndex].orderNumber].age[t]);
	}
	printf("��������: "LIGHT_GREEN"%d"NONE"\n", OrderList[g_groups[UserIndex].orderNumber].numberOfGroup);
	printf("�����۸�: "LIGHT_RED"%d"NONE"\n", OrderList[g_groups[UserIndex].orderNumber].price);
	printf("��������: %d\n", OrderList[g_groups[UserIndex].orderNumber].OrderIndex);
	printf("�û�����: %d\n", OrderList[g_groups[UserIndex].orderNumber].UserIndex);
	for(int j = 0;j < 5;j ++){
		printf("�� "LIGHT_GREEN"%d"NONE" ����������: "LIGHT_GREEN"%s"NONE"  "LIGHT_GREEN"%s"NONE"\n",j + 1, scenicList[OrderList[g_groups[UserIndex].orderNumber].ScenicIndex[j]].ID
											,scenicList[OrderList[g_groups[UserIndex].orderNumber].ScenicIndex[j]].Name);
	printf("Ԥ������ʱ��: %s\n\n",OrderList[g_groups[UserIndex].orderNumber].GoTime[j]);
	}
	printf("��Ԥ���ľ��������: "LIGHT_GREEN"%d"NONE"\n",OrderList[g_groups[UserIndex].orderNumber].NumberOfScenicIndex);
	
	system("pause");
	system("cls");
}
