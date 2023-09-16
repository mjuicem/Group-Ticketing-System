#include "scenic.h"

void loadScenic() {  

    // ���ļ�
    FILE* fp_input = fopen("scenicData.txt", "r");
    // while ��ѭ����ȡ�ļ�����
    while (1) {
        // ����ﵽ�ļ���β������ѭ��
        if (feof(fp_input)) {
            break;
        }

        // ����ɨ�������ֶ�
        char ID[8];  //������Ϣ 
		char Name[20]; //���� 
		char Description[100]; //�������� 
		int peak_season_price;  //�߷��ڼ۸� 
    	int off_season_price; //�͹��ڼ۸� 
		char level[10]; //���㼶�� 
		float StudentAccount;  //ѧ���ۿ� 
		float SoldierAccount;  //�����ۿ�
		int Spring_M;
		int Spring_A;
		int Summer_M;
		int Summer_A;
		int Autumn_A;
		int Autumn_M;
		int Winter_A;
		int Winter_M; 
		
		char Range[20];  //������������ 
		float Costs; //����ά������ 
		float Profit;
		int Tickets_M[10];
		int Tickets_A[10];
		//int Tickets[30]; //30���ڵ�Ʊ 
		//int RemainTickets[30];  //30����ʣ���Ʊ 
		//char startTime[30]; //���㿪ʼ��Ʊ���� 
        fscanf(fp_input, "%s ", ID);
        fscanf(fp_input, "%s ", Name);
        fscanf(fp_input, "%s ", Description);
        fscanf(fp_input, "%d ", &peak_season_price);
        fscanf(fp_input, "%d ", &off_season_price);
        fscanf(fp_input, "%s ", level);
        fscanf(fp_input, "%f ", &StudentAccount);
        fscanf(fp_input, "%f ", &SoldierAccount);
		fscanf(fp_input, "%d ", &Spring_M);
		fscanf(fp_input, "%d ", &Spring_A);
		fscanf(fp_input, "%d ", &Summer_M);
		fscanf(fp_input, "%d ", &Summer_A);
		fscanf(fp_input, "%d ", &Autumn_M);
		fscanf(fp_input, "%d ", &Autumn_A);
		fscanf(fp_input, "%d ", &Winter_M);
		fscanf(fp_input, "%d ", &Winter_A);
		for(int i = 0;i < 8;i ++){
        	fscanf(fp_input, "%s ", &scenicList[NumberOfScenic].SeasonTimeRange[i][0]);  //���벻ͬ���ڵ�ʱ������ 
		}
		fscanf(fp_input, "%s ", Range);
		fscanf(fp_input, "%f ",&Costs);
		fscanf(fp_input, "%f ",&Profit);
		for(int i = 0;i < 10;i ++){
			fscanf(fp_input, "%d ",&Tickets_M[i]);
		}
		for(int i = 0;i < 10;i ++){
			fscanf(fp_input, "%d ",&Tickets_A[i]);
		}
		fscanf(fp_input, "%d ",&scenicList[NumberOfScenic].Views); 
        // ����ȡ�����ݱ��浽����ṹ��������
        strcpy(scenicList[NumberOfScenic].ID,ID);
        strcpy(scenicList[NumberOfScenic].Name,Name);
        strcpy(scenicList[NumberOfScenic].Description,Description);
        scenicList[NumberOfScenic].peak_season_price = peak_season_price;
        scenicList[NumberOfScenic].off_season_price = off_season_price;
        strcpy(scenicList[NumberOfScenic].level,level);
        scenicList[NumberOfScenic].StudentAccount = StudentAccount;
        scenicList[NumberOfScenic].SoldierAccount = SoldierAccount;
        
        scenicList[NumberOfScenic].Spring_M = Spring_M;
        scenicList[NumberOfScenic].Spring_A = Spring_A;
        
        scenicList[NumberOfScenic].Summer_M = Summer_M;
        scenicList[NumberOfScenic].Summer_A = Summer_A;
        
        scenicList[NumberOfScenic].Autumn_M = Autumn_M;
        scenicList[NumberOfScenic].Autumn_A = Autumn_A;
        
        scenicList[NumberOfScenic].Winter_M = Winter_M;
        scenicList[NumberOfScenic].Winter_A = Winter_A;
        strcpy(scenicList[NumberOfScenic].Range,Range);
 		scenicList[NumberOfScenic].Costs = Costs;
		scenicList[NumberOfScenic].Profit = Profit;
		for(int i = 0;i < 10;i ++){
			scenicList[NumberOfScenic].Tickets_M[i] = Tickets_M[i];
			scenicList[NumberOfScenic].Tickets_A[i] = Tickets_A[i];
		} 
        // ���¾�������������
        NumberOfScenic ++;
    }

    // �ر��ļ�
    fclose(fp_input);
    printf(""YELLOW"@Test"NONE": ��ʼ���⣺�Ӿ����ļ��м����� "LIGHT_GREEN"%d"NONE" ��������Ϣ\n", NumberOfScenic);
}


void showScenic(){
	for (int i = 0; i < NumberOfScenic; i++) {
        printf("\n�� "LIGHT_GREEN"%d"NONE" ���������Ϣ���£�\n", i + 1);
        PrintWarn(i); 
        printf("������: %s\n", scenicList[i].ID);
        printf("����: "YELLOW"%s"NONE"\n", scenicList[i].Name);
        printf("��������: %s\n", scenicList[i].Description);
        printf("�����ڼ۸�: "LIGHT_RED"%d"NONE"\n",scenicList[i].peak_season_price);
        printf("�����ڼ۸�: "LIGHT_RED"%d"NONE"\n",scenicList[i].off_season_price);
        printf("ѧ���ۿ�: %.1f\n", scenicList[i].StudentAccount);
        printf("�����ۿ�: %.1f\n", scenicList[i].SoldierAccount);
        printf("���㼶��: %s\n", scenicList[i].level);
        printf("�������Ǿ�����������Լ�ʱ��ε���������\n");
        PrintScenicTicketsLimit(i);
        printf("������������: %s\n", scenicList[i].Range);
		PrintScenicTicketsRemain(i); 
		printf("���������: %d\n", scenicList[i].Views);
        scenicList[i].Views ++;
        printf("-----------------------------------------------------\n");
    }
    dumpScenic(); //��Ϊ�����˾���������,����Ҫ���澰��~ 
	system("pause");
	system("cls");
}

void showScenicByAdmin(){
	for (int i = 0; i < NumberOfScenic; i++) {
        printf("\n�� "LIGHT_GREEN"%d"NONE" ���������Ϣ���£�\n", i + 1);
        printf("������: "LIGHT_GREEN"%s"NONE"\n", scenicList[i].ID);
        printf("����: "YELLOW"%s"NONE"\n", scenicList[i].Name);
        printf("��������: %s\n", scenicList[i].Description);
        printf("�����ڼ۸�: %d\n",scenicList[i].peak_season_price);
        printf("�����ڼ۸�: %d\n",scenicList[i].off_season_price);
        printf("ѧ���ۿ�: %.1f\n", scenicList[i].StudentAccount);
        printf("�����ۿ�: %.1f\n", scenicList[i].SoldierAccount);
        printf("���㼶��: %s\n", scenicList[i].level);
        PrintScenicTicketsLimit(i);
        printf("������������: %s\n", scenicList[i].Range);
        printf("����ά������: %.2f\n", scenicList[i].Costs);
        printf("��������: %.2f\n", scenicList[i].Profit); 
        printf("δ��10���ʣ��Ʊ��\n");
        PrintScenicTicketsRemain(i);
        
	
		printf("���������: %d\n", scenicList[i].Views);
        printf("-----------------------------------------------------\n");
    }
    system("pause");
    system("cls"); 
}

//����¾��� 
void addScenic(){
	// ��ӹ���Ա 
    while (1) {
    	printf("\t"LIGHT_RED"TIPS:����ID����Ϊ��λ,�����Ա���水�չ淶��д"NONE"\n"); 
        printf("\t��Ӿ�����Ϣ��\n");

        printf("\t������Ҫ��ӵľ����ID: ");
        
        char ID[8];  //����ID
		char Name[10]; //���� 
		char Description[100]; //�������� 
		int peak_season_price;  //�߷��ڼ۸� 
    	int off_season_price; //�͹��ڼ۸� 
		char level[10]; //���㼶�� 
		float StudentAccount;  //ѧ���ۿ� 
		float SoldierAccount;  //�����ۿ�
		int Spring_M;
		int Spring_A;
		int Summer_M;
		int Summer_A;
		int Autumn_A;
		int Autumn_M;
		int Winter_A;
		int Winter_M; 
		char Range[20];  //������������ 
		float Costs; //����ά������ 
		scanf("%s",ID); 
        int found = 0;
        // �������У��������ң����β��Ҵ�ID�Ƿ����
        for (int i = 0; i < NumberOfScenic; i++) {
            // ����
            if (strcmp(scenicList[i].ID, ID) == 0) {
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
        //����
    
        printf("\t�����뾰������: ");
        scanf("%s", Name);
        printf("\t�����뾰������: ");
        scanf("%s", Description);
        printf("\t�����뾰�������۸�: ");
        scanf("%d", &peak_season_price);
        printf("\t�����뾰�㵭���۸�: ");
        scanf("%d", &off_season_price);
        //printf("\t���������澰������: ");
        //scanf("%s", time_range);
        printf("\t�����뾰��ȼ�: ");
        scanf("%s", level);
        printf("\t������ѧ���ۿ�: ");
        scanf("%f", &StudentAccount);
        printf("\t����������ۿ�: ");
        scanf("%f", &SoldierAccount);
        
        printf("\t������1�� - 3��������������: ");
		scanf("%d", &Spring_M);
		printf("\t������1�� - 3��������������: ");
		scanf("%d", &Spring_A);
		printf("\t������4�� - 6��������������: ");
		scanf("%d", &Summer_M);
		printf("\t������4�� - 6��������������: ");
		scanf("%d", &Summer_A);
		printf("\t������7�� - 9��������������: ");
		scanf("%d", &Autumn_M);
		printf("\t������7�� - 9��������������: ");
		scanf("%d", &Autumn_A);
		printf("\t������10�� - 12��������������: ");
		scanf("%d", &Winter_M);
		printf("\t������10�� - 12��������������: ");
		scanf("%d", &Winter_A);
		
		
		printf("\t������1�� - 3������ʱ������: ");
		scanf("%s", &scenicList[NumberOfScenic].SeasonTimeRange[0][0]);
		printf("\t������1�� - 3������ʱ������: ");
		scanf("%s", &scenicList[NumberOfScenic].SeasonTimeRange[1][0]);
		printf("\t������4�� - 6������ʱ������: ");
		scanf("%s", &scenicList[NumberOfScenic].SeasonTimeRange[2][0]);
		printf("\t������4�� - 6������ʱ������: ");
		scanf("%s", &scenicList[NumberOfScenic].SeasonTimeRange[3][0]);
		printf("\t������7�� - 9������ʱ������: ");
		scanf("%s", &scenicList[NumberOfScenic].SeasonTimeRange[4][0]);
		printf("\t������7�� - 9������ʱ������: ");
		scanf("%s", &scenicList[NumberOfScenic].SeasonTimeRange[5][0]);
		printf("\t������10�� - 12������ʱ������: ");
		scanf("%s", &scenicList[NumberOfScenic].SeasonTimeRange[6][0]);
		printf("\t������10�� - 12������ʱ������: ");
		scanf("%s", &scenicList[NumberOfScenic].SeasonTimeRange[7][0]);
		printf("\t�����뾰��λ��: ");
		scanf("%s", Range);
		printf("\t�����뾰��ά�޷���: ");
		scanf("%f",&Costs); 

		
		int temp_Index;
		time_t currentTime;
   	 	time(&currentTime);
    	struct tm *localTime = localtime(&currentTime);
    	char timeString[20];
    	strftime(timeString, sizeof(timeString), "%Y:%m:%d:%H:%M", localTime);
		temp_Index = getMonth(timeString);
		if(temp_Index == 0){
			for(int t = 0;t < 10;t ++){
				scenicList[NumberOfScenic].Tickets_M[t] = Spring_M;
				scenicList[NumberOfScenic].Tickets_A[t] = Spring_A;
			} 
		}else if(temp_Index == 2){
			for(int t = 0;t < 10;t ++){
				scenicList[NumberOfScenic].Tickets_M[t] = Summer_M;
				scenicList[NumberOfScenic].Tickets_A[t] = Summer_A;
			}
		}else if(temp_Index == 4){
			for(int t = 0;t < 10;t ++){
			
				scenicList[NumberOfScenic].Tickets_M[t] = Autumn_M;
				scenicList[NumberOfScenic].Tickets_A[t] = Autumn_A;
			}
		}else if(temp_Index == 6){
			for(int t = 0;t < 10;t ++){
				scenicList[NumberOfScenic].Tickets_M[t] = Winter_M;
				scenicList[NumberOfScenic].Tickets_A[t] = Winter_A;
			}
		}
        // ����ȡ�����ݱ��浽����ṹ��������
        strcpy(scenicList[NumberOfScenic].ID,ID);
        strcpy(scenicList[NumberOfScenic].Name,Name);
        strcpy(scenicList[NumberOfScenic].Description,Description);
        scenicList[NumberOfScenic].peak_season_price = peak_season_price;
        scenicList[NumberOfScenic].off_season_price = off_season_price;
        strcpy(scenicList[NumberOfScenic].level,level);
        scenicList[NumberOfScenic].StudentAccount = StudentAccount;
        scenicList[NumberOfScenic].SoldierAccount = SoldierAccount;
        
        scenicList[NumberOfScenic].Spring_M = Spring_M;
        scenicList[NumberOfScenic].Spring_A = Spring_A;
        
        scenicList[NumberOfScenic].Summer_M = Summer_M;
        scenicList[NumberOfScenic].Summer_A = Summer_A;
        
        scenicList[NumberOfScenic].Autumn_M = Autumn_M;
        scenicList[NumberOfScenic].Autumn_A = Autumn_A;
        
        scenicList[NumberOfScenic].Winter_M = Winter_M;
        scenicList[NumberOfScenic].Winter_A = Winter_A;
        strcpy(scenicList[NumberOfScenic].Range,Range);
    	scenicList[NumberOfScenic].Costs = Costs;
    	scenicList[NumberOfScenic].Profit = -Costs;
    	scenicList[NumberOfScenic].Views = 0;
    	
    	while(getchar() != '\n');
    	printf("\t�Ƿ񷢲�����?  [1]ȷ�� [2]ȡ�� [3]�޸�:");
    	int choice = MyInput(1,3);
    	if(choice == 1){
    		NumberOfScenic ++;
			dumpScenic(); 
        	printf("\t����ɹ����Ƿ�������(Y/N): ");
        	char yes_no[2];
        	scanf("%s", yes_no);
        	getchar();
        	// û������Y����y��������ѭ��
        	if (strcasecmp(yes_no, "Y") != 0) {
            	break;
        	}
		}else if(choice == 2){
			break;
		}else if(choice == 3){
			system("cls");
		} 
    } 
    system("cls");
}

void dumpScenic(){
	// ���ļ�
    FILE* fp_input = fopen("scenicData.txt", "w");

    // �������飬������д��
    for (int i = 0; i < NumberOfScenic; i++) {
        fprintf(fp_input, "%s ", scenicList[i].ID);
    	fprintf(fp_input, "%s ", scenicList[i].Name);
    	fprintf(fp_input, "%s ", scenicList[i].Description);
    	fprintf(fp_input, "%d ", scenicList[i].peak_season_price);
    	fprintf(fp_input, "%d ", scenicList[i].off_season_price);
    	fprintf(fp_input, "%s ", scenicList[i].level);
    	fprintf(fp_input, "%f ", scenicList[i].StudentAccount);
    	fprintf(fp_input, "%f ", scenicList[i].SoldierAccount);
		fprintf(fp_input, "%d ", scenicList[i].Spring_M);
		fprintf(fp_input, "%d ", scenicList[i].Spring_A);
		fprintf(fp_input, "%d ", scenicList[i].Summer_M);
		fprintf(fp_input, "%d ", scenicList[i].Summer_A);
		fprintf(fp_input, "%d ", scenicList[i].Autumn_M);
		fprintf(fp_input, "%d ", scenicList[i].Autumn_A);
		fprintf(fp_input, "%d ", scenicList[i].Winter_M);
		fprintf(fp_input, "%d ", scenicList[i].Winter_A);
		for(int t = 0;t < 8;t ++){
			fprintf(fp_input,"%s ",scenicList[i].SeasonTimeRange[t]);
		}
		fprintf(fp_input, "%s ", scenicList[i].Range);
		fprintf(fp_input, "%f ",scenicList[i].Costs);
		fprintf(fp_input, "%f ",scenicList[i].Profit);
		for(int t = 0;t < 10;t ++){
			fprintf(fp_input,"%d ",scenicList[i].Tickets_M[t]);
		}
		for(int t = 0;t < 10;t ++){
			fprintf(fp_input,"%d ",scenicList[i].Tickets_A[t]);
		}
		fprintf(fp_input, "%d\n",scenicList[i].Views); 
    }
	
    // �ر��ļ�
    fclose(fp_input);
} 

void PrintScenicTicketsRemain(int i){
	printf("2023:09:06����%s��ʣ��Ʊ��: "LIGHT_RED"%d"NONE"\t����%s��ʣ��Ʊ��: "LIGHT_RED"%d"NONE"\n",scenicList[i].SeasonTimeRange[4]
	,scenicList[i].Tickets_M[0],scenicList[i].SeasonTimeRange[5],scenicList[i].Tickets_A[0]); 
    printf("2023:09:07����%s��ʣ��Ʊ��: "LIGHT_RED"%d"NONE"\t����%s��ʣ��Ʊ��: "LIGHT_RED"%d"NONE"\n",scenicList[i].SeasonTimeRange[4]
	,scenicList[i].Tickets_M[1],scenicList[i].SeasonTimeRange[5],scenicList[i].Tickets_A[1]);
	printf("2023:09:08����%s��ʣ��Ʊ��: "LIGHT_RED"%d"NONE"\t����%s��ʣ��Ʊ��: "LIGHT_RED"%d"NONE"\n",scenicList[i].SeasonTimeRange[4]
	,scenicList[i].Tickets_M[2],scenicList[i].SeasonTimeRange[5],scenicList[i].Tickets_A[2]);
	printf("2023:09:09����%s��ʣ��Ʊ��: "LIGHT_RED"%d"NONE"\t����%s��ʣ��Ʊ��: "LIGHT_RED"%d"NONE"\n",scenicList[i].SeasonTimeRange[4]
	,scenicList[i].Tickets_M[3],scenicList[i].SeasonTimeRange[5],scenicList[i].Tickets_A[3]);
	printf("2023:09:10����%s��ʣ��Ʊ��: "LIGHT_RED"%d"NONE"\t����%s��ʣ��Ʊ��: "LIGHT_RED"%d"NONE"\n",scenicList[i].SeasonTimeRange[4]
	,scenicList[i].Tickets_M[4],scenicList[i].SeasonTimeRange[5],scenicList[i].Tickets_A[4]);
	printf("2023:09:11����%s��ʣ��Ʊ��: "LIGHT_RED"%d"NONE"\t����%s��ʣ��Ʊ��: "LIGHT_RED"%d"NONE"\n",scenicList[i].SeasonTimeRange[4]
	,scenicList[i].Tickets_M[5],scenicList[i].SeasonTimeRange[5],scenicList[i].Tickets_A[5]);
	printf("2023:09:12����%s��ʣ��Ʊ��: "LIGHT_RED"%d"NONE"\t����%s��ʣ��Ʊ��: "LIGHT_RED"%d"NONE"\n",scenicList[i].SeasonTimeRange[4]
	,scenicList[i].Tickets_M[6],scenicList[i].SeasonTimeRange[5],scenicList[i].Tickets_A[6]);
	printf("2023:09:13����%s��ʣ��Ʊ��: "LIGHT_RED"%d"NONE"\t����%s��ʣ��Ʊ��: "LIGHT_RED"%d"NONE"\n",scenicList[i].SeasonTimeRange[4]
	,scenicList[i].Tickets_M[7],scenicList[i].SeasonTimeRange[5],scenicList[i].Tickets_A[7]);
	printf("2023:09:14����%s��ʣ��Ʊ��: "LIGHT_RED"%d"NONE"\t����%s��ʣ��Ʊ��: "LIGHT_RED"%d"NONE"\n",scenicList[i].SeasonTimeRange[4]
	,scenicList[i].Tickets_M[8],scenicList[i].SeasonTimeRange[5],scenicList[i].Tickets_A[8]);
	printf("2023:09:15����%s��ʣ��Ʊ��: "LIGHT_RED"%d"NONE"\t����%s��ʣ��Ʊ��: "LIGHT_RED"%d"NONE"\n",scenicList[i].SeasonTimeRange[4]
	,scenicList[i].Tickets_M[9],scenicList[i].SeasonTimeRange[5],scenicList[i].Tickets_A[9]);
}

void PrintScenicTicketsLimit(int i){
	    printf("1�� - 3�� ���翪��ʱ��: "LIGHT_GREEN"%s"NONE"\t��������: "LIGHT_GREEN"%d"NONE"\n"
		, scenicList[i].SeasonTimeRange[0],scenicList[i].Spring_M);
        printf("1�� - 3�� ���翪��ʱ��: "LIGHT_GREEN"%s"NONE"\t��������: "LIGHT_GREEN"%d"NONE"\n"
		, scenicList[i].SeasonTimeRange[1],scenicList[i].Spring_A);
        printf("4�� - 6�� ���翪��ʱ��: "LIGHT_GREEN"%s"NONE"\t��������: "LIGHT_GREEN"%d"NONE"\n"
		, scenicList[i].SeasonTimeRange[2],scenicList[i].Summer_M);
        printf("4�� - 6�� ���翪��ʱ��: "LIGHT_GREEN"%s"NONE"\t��������: "LIGHT_GREEN"%d"NONE"\n"
		, scenicList[i].SeasonTimeRange[3],scenicList[i].Summer_A);
        printf("7�� - 9�� ���翪��ʱ��: "LIGHT_GREEN"%s"NONE"\t��������: "LIGHT_GREEN"%d"NONE"\n"
		, scenicList[i].SeasonTimeRange[4],scenicList[i].Autumn_M);
        printf("7�� - 9�� ���翪��ʱ��: "LIGHT_GREEN"%s"NONE"\t��������: "LIGHT_GREEN"%d"NONE"\n"
		, scenicList[i].SeasonTimeRange[5],scenicList[i].Autumn_A);
        printf("10�� - 12�� ���翪��ʱ��: "LIGHT_GREEN"%s"NONE"\t��������: "LIGHT_GREEN"%d"NONE"\n"
		, scenicList[i].SeasonTimeRange[6],scenicList[i].Winter_M);
        printf("10�� - 12�� ���翪��ʱ��: "LIGHT_GREEN"%s"NONE"\t��������: "LIGHT_GREEN"%d"NONE"\n"
		, scenicList[i].SeasonTimeRange[7],scenicList[i].Winter_A);
}
		
void PrintWarn(int i){
		if(i == 1 || i == 6 || i == 8){
			printf("\t"LIGHT_RED"TIPS:�þ���������Ҫ�������˶���,������С�����Լ�����״�������ǳ���\n"NONE"");
		}
		
		if(i == 12 || i == 13){
			printf("\t"LIGHT_RED"TIPS:�õ�Ϊ��ѧУ԰,�����ѧУ����ʱ������ų���\n"NONE"");
		}
}
