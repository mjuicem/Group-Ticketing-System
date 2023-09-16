#include "order.h"

void loadOrder(){
	// ���ļ�
    FILE* fp_input = fopen("orderData.txt", "r");

    // while ��ѭ����ȡ�ļ�����
    while (1) {
        // ����ﵽ�ļ���β������ѭ��
        if (feof(fp_input)) {
            break;
        }

        // ����ɨ�������ֶ�
        char ID[30]; //�������
		char ReserveTime[30]; //Ԥ��ʱ��
		int State; 
		int age[10]; //�����
		int numberOfGroup; //�������� 
		int price; //�����۸� 
		int OrderIndex; //��������
		int UserIndex; //�û����� 
		int ScenicIndex[5]; //��������
		int NumberOfScenicIndex; //���澰������ 
        fscanf(fp_input, "%s ", ID);
        fscanf(fp_input, "%s ", ReserveTime);
        fscanf(fp_input, "%d ", &State);
        for(int i = 0;i < 10;i ++){
        	fscanf(fp_input, "%d ",&age[i]);
		}
        fscanf(fp_input, "%d ", &numberOfGroup);
        fscanf(fp_input, "%d ", &price);
        fscanf(fp_input, "%d ", &OrderIndex);
        fscanf(fp_input, "%d ", &UserIndex);
        for(int i = 0;i < 5;i ++){
        	fscanf(fp_input, "%d ", &ScenicIndex[i]);
		}
        //�жϾ����������� 
		fscanf(fp_input, "%d ", &NumberOfScenicIndex); 
		for(int i = 0;i < 5;i ++){
        	fscanf(fp_input, "%s ", &OrderList[NumberOfOrder].GoTime[i][0]);
		}
		
        // ����ȡ�����ݱ��浽�ο��Žṹ��������
        strcpy(OrderList[NumberOfOrder].ID,ID);
        strcpy(OrderList[NumberOfOrder].ReserveTime,ReserveTime);
        OrderList[NumberOfOrder].State = State;
		for(int i = 0;i < 10;i ++){
			OrderList[NumberOfOrder].age[i] = age[i];
		}
		OrderList[NumberOfOrder].numberOfGroup = numberOfGroup;
		OrderList[NumberOfOrder].price = price;
		OrderList[NumberOfOrder].OrderIndex = OrderIndex;
		OrderList[NumberOfOrder].UserIndex = UserIndex;
		for(int i = 0;i < 5;i ++){
			OrderList[NumberOfOrder].ScenicIndex[i] = ScenicIndex[i];
		}
		OrderList[NumberOfOrder].NumberOfScenicIndex = NumberOfScenicIndex;
		
        // ���¹���Ա����������
        NumberOfOrder ++;
    }

    // �ر��ļ�
    fclose(fp_input);

    printf(""YELLOW"@Test"NONE": ��ʼ���⣺�Ӷ����ļ��м����� "LIGHT_GREEN"%d"NONE" ��������Ϣ\n", NumberOfOrder);
}

void showOrderByAdmin(){
	for (int i = 0; i < NumberOfOrder; i++) {
        printf("\n�� "LIGHT_GREEN"%d"NONE" ����������Ϣ���£�\n", i + 1);
        printf("�������: "LIGHT_GREEN"%s"NONE"\n", OrderList[i].ID);
        printf("���������ο���ID: "YELLOW"%s"NONE"\n",g_groups[OrderList[i].UserIndex].ID);
        //printf("Ԥ��ʱ��: %s\n", OrderList[i].ReserveTime);
        printf("��������ʱ��: %s\n", OrderList[i].ReserveTime);
		printf("����״̬: %d\n", OrderList[i].State);
		for(int t = 0;t < 10;t ++){
			printf("����� %d0 - %d0 �� %d ��\n",t,t+1,OrderList[i].age[t]);
		}
		printf("��������: "LIGHT_GREEN"%d"NONE"\n", OrderList[i].numberOfGroup);
		printf("�����۸�: "LIGHT_RED"%d"NONE"\n", OrderList[i].price);
		printf("��������: %d\n", OrderList[i].OrderIndex);
		printf("�û�����: %d\n", OrderList[i].UserIndex);
		for(int j = 0;j < 5;j ++){
			printf("�� "LIGHT_GREEN"%d"NONE" ����������: "LIGHT_GREEN"%s"NONE"  "LIGHT_GREEN"%s"NONE"",j + 1,scenicList[OrderList[i].ScenicIndex[j]].ID,scenicList[OrderList[i].ScenicIndex[j]].Name);
			printf("\tԤ������ʱ��: %s\n",OrderList[i].GoTime[j]);
		}
		printf("��Ԥ���ľ��������: "LIGHT_GREEN"%d"NONE"\n",OrderList[i].NumberOfScenicIndex);
        printf("-----------------------------------------------------\n");
    }
    system("\t pause");
    system("cls");
}

void showOrderByUser(){
        printf("\n�ο����û� "YELLOW"%s"NONE" �Ķ�����Ϣ���£�\n",g_groups[UserIndex].ID);
        printf("�������: "LIGHT_GREEN"%s"NONE"\n", OrderList[g_groups[UserIndex].orderNumber].ID);
        printf("���������ο���ID: %s\n",g_groups[OrderList[g_groups[UserIndex].orderNumber].UserIndex].ID);
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
        printf("-----------------------------------------------------\n");
    
    system("\t pause");
}


void initOrder(){      //��ʼ������ 
	g_groups[UserIndex].orderNumber = NumberOfOrder; //���������� 
	OrderList[NumberOfOrder].UserIndex = UserIndex;
	char temp_Scenic[20];
	int flag = 0;
	int Index;
	printf("\n\t��������ҪԤ���ľ���ID: ");
	scanf("%s",temp_Scenic);
	for(int i = 0;i < NumberOfScenic;i ++){
		if(strcmp(temp_Scenic,scenicList[i].ID) == 0){
			flag = 1;
			Index = i;
			break;
		}
	}
	if(flag == 0){
		printf("\t"LIGHT_RED"�þ���ID������,��������ȷ�ľ���ID"NONE"\n\t");
		system("pause"); 
		while(getchar() != '\n'); 
		initOrder();
	}
	getchar();
	char temp_GoTime[30];
	char temp_GoTime2[30];
	char temp_subStr[12];
	int flag3;
	int GoTime_Index;
	printf("\t����������������л����������([1]��������,[2]��������):");
	flag3 =MyInput(1,2); 
	printf("\t����"LIGHT_GREEN"%s"NONE"����Ŀ���ʱ��"YELLOW"%s"NONE"\n",scenicList[Index].Name,scenicList[Index].SeasonTimeRange[4]);
	printf("\t����"LIGHT_GREEN"%s"NONE"����Ŀ���ʱ��"YELLOW"%s"NONE"\n",scenicList[Index].Name,scenicList[Index].SeasonTimeRange[5]);
	printf("\t��������ĳ���ʱ��:(��ʽΪyyyy:mm:dd:hh):");
	scanf("%s",temp_GoTime);
	while(!isDateFormatValid(temp_GoTime) || !isDateTimeInRange(temp_GoTime)){
		printf("\t��������ȷ�ĳ���ʱ��:(��ʽΪyyyy:mm:dd:hh,��ǰֻ��Ԥ��2023:09:06-2023:09:15��֮���Ʊ):");
		scanf("%s",temp_GoTime); 
	} 
	
	strcpy(temp_GoTime2,temp_GoTime);
	
	if(flag3 == 1){
		GoTime_Index = getMonth(temp_GoTime);
		if(GoTime_Index == 0){
			strcpy(temp_GoTime,&scenicList[Index].SeasonTimeRange[0][0]);
		}else if(GoTime_Index == 2){
			strcpy(temp_GoTime,&scenicList[Index].SeasonTimeRange[2][0]);
		}else if(GoTime_Index == 4){
			strcpy(temp_GoTime,&scenicList[Index].SeasonTimeRange[4][0]);
		}else if(GoTime_Index == 6){
			strcpy(temp_GoTime,&scenicList[Index].SeasonTimeRange[6][0]);
		} 
	}else if(flag3 == 2){
		GoTime_Index = getMonth(temp_GoTime);
		if(Index == 0){
			strcpy(temp_GoTime,&scenicList[Index].SeasonTimeRange[1][0]);
		}else if(GoTime_Index == 2){
			strcpy(temp_GoTime,&scenicList[Index].SeasonTimeRange[3][0]);
		}else if(GoTime_Index == 4){
			strcpy(temp_GoTime,&scenicList[Index].SeasonTimeRange[5][0]);
		}else if(GoTime_Index == 6){
			strcpy(temp_GoTime,&scenicList[Index].SeasonTimeRange[7][0]);
	}
}
	strncpy(temp_subStr,temp_GoTime2,11);  
	temp_subStr[11] = '\0';
	const char* defaultTime = "2023:09:06";    //Ĭ��ʱ�� 
	int TimeDifference = calculateDayDifference(defaultTime,temp_subStr); // 
	strcat(temp_subStr,temp_GoTime);
	strcpy(temp_GoTime,temp_subStr);
	temp_GoTime[10] = '/';
	printf("\t���ĳ���ʱ�䱻����Ϊ: "LIGHT_GREEN"%s"NONE"\n",temp_GoTime);
	
	//���ɶ���
	
	//��ȡ��ǰʱ�� 
	time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    char timeString[20];
    strftime(timeString, sizeof(timeString), "%Y:%m:%d:%H:%M", localTime);
    strcpy(OrderList[NumberOfOrder].ReserveTime,timeString);
	
	char temp_store[50]; 
	strcpy(temp_store,g_groups[UserIndex].ID);
	strcat(temp_store,timeString);
	strcpy(OrderList[NumberOfOrder].ID,temp_store); //�������ɶ���ID 
	
	OrderList[NumberOfOrder].State = 1; //�Ѷ���״̬Ĭ��Ϊ1 
	for(int i = 0;i < 10;i ++){
		OrderList[NumberOfOrder].age[i] = g_groups[UserIndex].ageLevel[i];   //��ֵ������ 
	}
	
	OrderList[NumberOfOrder].numberOfGroup = g_groups[UserIndex].numMembers;  //��ֵ�������� 
	OrderList[NumberOfOrder].OrderIndex = NumberOfOrder;    //��ֵ����Ķ������� 

	OrderList[NumberOfOrder].ScenicIndex[0] = Index;   //��ֵ������һ������Ķ������� 
	strcpy(&OrderList[NumberOfOrder].GoTime[0][0],temp_GoTime); //������һ������ĳ���ʱ�� 
	for(int i = 1;i < 5;i ++){
		OrderList[NumberOfOrder].ScenicIndex[i] = -1;  //-1 ����δָ���κ�һ������ 
	}
	for(int i = 1;i < 5;i ++){
		strcpy(OrderList[NumberOfOrder].GoTime[i],"null");
	}
	
	int StudentNumber = OrderList[NumberOfOrder].age[0] + OrderList[NumberOfOrder].age[1];
	int OlderNumber = OrderList[NumberOfOrder].age[6] + OrderList[NumberOfOrder].age[7]
						+ OrderList[NumberOfOrder].age[8] + OrderList[NumberOfOrder].age[9];
	
	int ExceptNumber = OrderList[NumberOfOrder].numberOfGroup - StudentNumber - OlderNumber;
	//�ж�Ϊ������������
	if(getMonth(temp_GoTime) == 0 || getMonth(temp_GoTime) == 3){
		//Ϊ����
		scenicList[Index].Profit += scenicList[Index].off_season_price * ExceptNumber
								 + StudentNumber * scenicList[Index].StudentAccount * scenicList[Index].off_season_price
								 + OlderNumber * scenicList[Index].SoldierAccount * scenicList[Index].off_season_price; //���Ӿ�������
		OrderList[NumberOfOrder].price += scenicList[Index].off_season_price * ExceptNumber
								 + StudentNumber * scenicList[Index].StudentAccount * scenicList[Index].off_season_price
								 + OlderNumber * scenicList[Index].SoldierAccount * scenicList[Index].off_season_price; //���Ӷ���֧��
	}else{
		//Ϊ����
		scenicList[Index].Profit += scenicList[Index].peak_season_price * ExceptNumber
								 + StudentNumber * scenicList[Index].StudentAccount * scenicList[Index].peak_season_price
								 + OlderNumber * scenicList[Index].SoldierAccount * scenicList[Index].peak_season_price;  //���Ӿ������� 
		OrderList[NumberOfOrder].price += scenicList[Index].peak_season_price * ExceptNumber
								 + StudentNumber * scenicList[Index].StudentAccount * scenicList[Index].peak_season_price
								 + OlderNumber * scenicList[Index].SoldierAccount * scenicList[Index].peak_season_price; //���Ӷ���֧��  
	}
	
	if(flag3 == 1){
		if(scenicList[Index].Tickets_M[TimeDifference] - OrderList[NumberOfOrder].numberOfGroup >= 0){
			scenicList[Index].Tickets_M[TimeDifference] -= OrderList[NumberOfOrder].numberOfGroup;
		}else{
			printf("\t"LIGHT_RED"�þ����ʱ�ε�ԤԼ��������,��Ʊʧ��"NONE"\n");
			return; 
		}
	}else if(flag3 == 2){
		if(scenicList[Index].Tickets_A[TimeDifference] - OrderList[NumberOfOrder].numberOfGroup >= 0){
			scenicList[Index].Tickets_A[TimeDifference] -= OrderList[NumberOfOrder].numberOfGroup;
		}else{
			printf("\t"LIGHT_RED"�þ����ʱ�ε�ԤԼ��������,��Ʊʧ��"NONE"\n");
			return; 
		}
	}
	
	
	
	OrderList[NumberOfOrder].NumberOfScenicIndex ++; //��ʼ����������Ϊ1 
	NumberOfOrder ++; //�������� + 1 
	dumpScenic(); //�޸��˾��������,��Ҫ�����¾��� 
	dumpOrder();  //�޸��˶���,��Ҫ�����¶��� 
	dumpUser();   //�޸����û��Ķ�����������Ҫ�������û� 
	printf("\t");
	getchar(); 
	system("pause");
	system("cls");
	userSen(); 
}


void addOrder(){      //������Ӷ��� 
	//g_groups[UserIndex].orderNumber = NumberOfOrder;
	//OrderList[NumberOfOrder].UserIndex = UserIndex;
	char temp_Scenic[20];
	int flag = 0;
	int Index;
	printf("\n\t��������ҪԤ���ľ���ID: ");
	scanf("%s",temp_Scenic);
	for(int i = 0;i < NumberOfScenic;i ++){
		if(strcmp(temp_Scenic,scenicList[i].ID) == 0){
			flag = 1;
			Index = i;
			break;
		}
	}
	if(flag == 0){
		printf("\t"LIGHT_RED"�þ���ID������,��������ȷ�ľ���ID"NONE"\n\t");
		while(getchar() != '\n'); 
		system("pause");
		addOrder();
	}
	getchar();
	char temp_GoTime[30];
	char temp_GoTime2[30];
	char temp_subStr[12];
	int flag3;
	int GoTime_Index;
	printf("\t����"LIGHT_GREEN"%s"NONE"����Ŀ���ʱ��"YELLOW"%s"NONE"\n",scenicList[Index].Name,scenicList[Index].SeasonTimeRange[4]);
	printf("\t����"LIGHT_GREEN"%s"NONE"����Ŀ���ʱ��"YELLOW"%s"NONE"\n",scenicList[Index].Name,scenicList[Index].SeasonTimeRange[5]);
	printf("\t����������������л����������([1]��������,[2]��������):");
	flag3 =MyInput(1,2); 
	printf("\t��������ĳ���ʱ��:(��ʽΪyyyy:mm:dd:hh):");
	scanf("%s",temp_GoTime);
	while(!isDateFormatValid(temp_GoTime) || !isDateTimeInRange(temp_GoTime)){
		printf("\t��������ȷ�ĳ���ʱ��:(��ʽΪyyyy:mm:dd:hh,��ǰֻ��Ԥ��2023:09:06-2023:09:15��֮���Ʊ):");
		scanf("%s",temp_GoTime); 
	} 
	strcpy(temp_GoTime2,temp_GoTime);
	
	if(flag3 == 1){
		GoTime_Index = getMonth(temp_GoTime);
		if(GoTime_Index == 0){
			strcpy(temp_GoTime,&scenicList[Index].SeasonTimeRange[0][0]);
		}else if(GoTime_Index == 2){
			strcpy(temp_GoTime,&scenicList[Index].SeasonTimeRange[2][0]);
		}else if(GoTime_Index == 4){
			strcpy(temp_GoTime,&scenicList[Index].SeasonTimeRange[4][0]);
		}else if(GoTime_Index == 6){
			strcpy(temp_GoTime,&scenicList[Index].SeasonTimeRange[6][0]);
		} 
	}else if(flag3 == 2){
		GoTime_Index = getMonth(temp_GoTime);
		if(Index == 0){
			strcpy(temp_GoTime,&scenicList[Index].SeasonTimeRange[1][0]);
		}else if(GoTime_Index == 2){
			strcpy(temp_GoTime,&scenicList[Index].SeasonTimeRange[3][0]);
		}else if(GoTime_Index == 4){
			strcpy(temp_GoTime,&scenicList[Index].SeasonTimeRange[5][0]);
		}else if(GoTime_Index == 6){
			strcpy(temp_GoTime,&scenicList[Index].SeasonTimeRange[7][0]);
	}
}
	strncpy(temp_subStr,temp_GoTime2,11);  
	temp_subStr[11] = '\0';
	const char* defaultTime = "2023:09:06";    //Ĭ��ʱ�� 
	int TimeDifference = calculateDayDifference(defaultTime,temp_subStr); 
	strcat(temp_subStr,temp_GoTime);
	strcpy(temp_GoTime,temp_subStr);
	temp_GoTime[10] = '/';
	printf("\t���ĳ���ʱ�䱻����Ϊ: "LIGHT_GREEN"%s"NONE "\n",temp_GoTime);

	char TEMP_GOTIME[20];
	strncpy(TEMP_GOTIME,temp_GoTime,6);
	TEMP_GOTIME[7] = '\0';
	int currentOrderIndex = g_groups[UserIndex].orderNumber;
	OrderList[currentOrderIndex].ScenicIndex[OrderList[currentOrderIndex].NumberOfScenicIndex] = Index;  //��Ӿ�������
	strcpy(&OrderList[currentOrderIndex].GoTime[OrderList[currentOrderIndex].NumberOfScenicIndex][0],temp_GoTime); //1
	
	 
	int OrderIndex = g_groups[UserIndex].orderNumber;  //��ǰ�������� 
	int StudentNumber = OrderList[OrderIndex].age[0] + OrderList[OrderIndex].age[1];
	int OlderNumber = OrderList[OrderIndex].age[6] + OrderList[OrderIndex].age[7] 
						+ OrderList[OrderIndex].age[8] + OrderList[OrderIndex].age[9];
	
	int ExceptNumber = OrderList[OrderIndex].numberOfGroup - StudentNumber - OlderNumber;
	
	
	
	//�ж�Ϊ������������
	if(getMonth(TEMP_GOTIME) == 0 || getMonth(TEMP_GOTIME) == 6){
		//Ϊ����
		scenicList[Index].Profit += scenicList[Index].off_season_price * ExceptNumber
								 +  scenicList[Index].off_season_price * StudentNumber * scenicList[Index].StudentAccount
								 +  scenicList[Index].off_season_price * OlderNumber * scenicList[Index].SoldierAccount; //���Ӿ�������
		OrderList[currentOrderIndex].price += scenicList[Index].off_season_price * ExceptNumber
								 +  scenicList[Index].off_season_price * StudentNumber * scenicList[Index].StudentAccount
								 +  scenicList[Index].off_season_price * OlderNumber * scenicList[Index].SoldierAccount; //���Ӷ���֧��
	}else{
		//Ϊ����
		scenicList[Index].Profit += scenicList[Index].peak_season_price * ExceptNumber
								 +  scenicList[Index].peak_season_price * StudentNumber * scenicList[Index].StudentAccount
								 +  scenicList[Index].peak_season_price * OlderNumber * scenicList[Index].SoldierAccount; //���Ӿ������� 
		OrderList[currentOrderIndex].price += scenicList[Index].peak_season_price * ExceptNumber
								 +  scenicList[Index].peak_season_price * StudentNumber * scenicList[Index].StudentAccount
								 +  scenicList[Index].peak_season_price * OlderNumber * scenicList[Index].SoldierAccount;//���Ӷ���֧��  
	}
	
	if(flag3 == 1){
		if(scenicList[Index].Tickets_M[TimeDifference] - OrderList[currentOrderIndex].numberOfGroup >= 0){
			scenicList[Index].Tickets_M[TimeDifference] -= OrderList[currentOrderIndex].numberOfGroup;
		}else{
			printf("\t"LIGHT_RED"�þ����ʱ�ε�ԤԼ��������,��Ʊʧ��"NONE"\n");
			return; 
		}
	}else if(flag3 == 2){
		if(scenicList[Index].Tickets_A[TimeDifference] - OrderList[currentOrderIndex].numberOfGroup >= 0){
			scenicList[Index].Tickets_A[TimeDifference] -= OrderList[currentOrderIndex].numberOfGroup;
		}else{
			printf("\t"LIGHT_RED"�þ����ʱ�ε�ԤԼ��������,��Ʊʧ��"NONE"\n");
			return; 
		}
	}
	

	
	OrderList[currentOrderIndex].NumberOfScenicIndex++;
	dumpScenic();
	dumpOrder();
	dumpUser();
	getchar();
	printf("\t"); 
	system("pause");
	system("cls");
	userSen(); 
}


void dumpOrder(){
	FILE* fp_output = fopen("orderData.txt", "w");
	// �������飬������д��
    for (int i = 0; i < NumberOfOrder; i++) {
        fprintf(fp_output, "%s ", OrderList[i].ID);
        fprintf(fp_output, "%s ", OrderList[i].ReserveTime);
        fprintf(fp_output, "%d ", OrderList[i].State);
        for(int t = 0;t < 10;t ++){
        	fprintf(fp_output, "%d ", OrderList[i].age[t]);
		}
		fprintf(fp_output, "%d ", OrderList[i].numberOfGroup);
		fprintf(fp_output, "%d ", OrderList[i].price);
		fprintf(fp_output, "%d ", OrderList[i].OrderIndex);
		fprintf(fp_output, "%d ", OrderList[i].UserIndex);
		for(int t = 0; t < 5;t ++){
			fprintf(fp_output, "%d ", OrderList[i].ScenicIndex[t]);
		}
		fprintf(fp_output, "%d ", OrderList[i].NumberOfScenicIndex);
		for(int t = 0;t < 5;t ++){
        	fprintf(fp_output, "%s ", OrderList[i].GoTime[t]);
		}
    }

    // �ر��ļ�
    fclose(fp_output);
}


void DeleteOrder(){
	//��ȡ��ǰʱ�� 
	time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    char timeString[20];
    strftime(timeString, sizeof(timeString), "%Y:%m:%d:%H:%M", localTime);
	int Difference = calculateDayDifference(timeString,OrderList[g_groups[UserIndex].orderNumber].ReserveTime);
	if(Difference >= 1){
		printf("\t����Ԥ���ѳ���һ��,�޷�ȡ��\n");
		printf("\t");
		system("pause");
		userSen();
		return;
	}else{
		printf("\t�Ƿ�ȷ��ȡ������?  [1]ȷ�� [2]ȡ��");
    	int choice = MyInput(1,2);
    if(choice == 1){
    	OrderList[g_groups[UserIndex].orderNumber].State = -1;
		g_groups[UserIndex].orderNumber = -1;
		for(int i = 0;i < 5 && OrderList[g_groups[UserIndex].orderNumber].ScenicIndex[i] != -1;i ++){
			int StudentNumber = OrderList[g_groups[UserIndex].orderNumber].age[0] + OrderList[g_groups[UserIndex].orderNumber].age[1];
			int OlderNumber = OrderList[g_groups[UserIndex].orderNumber].age[6] + OrderList[g_groups[UserIndex].orderNumber].age[7]
						+ OrderList[g_groups[UserIndex].orderNumber].age[8] + OrderList[g_groups[UserIndex].orderNumber].age[9];
			int ExceptNumber = OrderList[g_groups[UserIndex].orderNumber].numberOfGroup - StudentNumber - OlderNumber;
			scenicList[OrderList[g_groups[UserIndex].orderNumber].ScenicIndex[i]].Profit
		 	-= (scenicList[OrderList[g_groups[UserIndex].orderNumber].ScenicIndex[i]].peak_season_price * ExceptNumber
		 	+ StudentNumber * scenicList[OrderList[g_groups[UserIndex].orderNumber].ScenicIndex[i]].StudentAccount 
		 	* scenicList[OrderList[g_groups[UserIndex].orderNumber].ScenicIndex[i]].peak_season_price
		 	+ OlderNumber * scenicList[OrderList[g_groups[UserIndex].orderNumber].ScenicIndex[i]].SoldierAccount 
		 	* scenicList[OrderList[g_groups[UserIndex].orderNumber].ScenicIndex[i]].peak_season_price);   
			}
		printf("\tȡ��Ԥ���ɹ�!");
		dumpOrder();
		dumpUser();
		dumpScenic(); 
		printf("\t");
		system("pause");
		system("cls");
		userSen();
	}else if(choice == 2){
		printf("\t"LIGHT_GREEN"�ɹ�ȡ���޸�!"NONE"");
		Sleep(3000);
		system("cls");
		userSen();
		}	
	}
}
 

	
