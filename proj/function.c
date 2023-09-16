#include "function.h"

int MyInput(int low, int high) {
    int choice = 0, // ѡ��
        result = 0, // ÿһ�ֵĽ��
        flagNum = 0, // �Ƿ���������
        total = 0, // ѭ������
        flagChar = 0; // �Ƿ������ַ�
    char ch;

    do {
        result = 0;
        flagChar = 0;
        flagNum = 0;
        total++;

        if (total >= 2) {
            printf("\t���������������������룺 ");
        }

        ch = getchar();

        // �����ո�
        while (ch == ' ') {
            ch = getchar();
        }

        while (ch != '\n') {
            if (ch >= '0' && ch <= '9') {
                flagNum = 1;
                if (flagChar == 0) {
                    // ����Ѿ����������룬�ҵ�ǰ����Ϊ0�������ǰ��0
                    if (result != 0 || ch != '0') {
                        result = result * 10 + ch - '0';
                        choice = result;
                    }
                }
            } else {
                if ((ch < '0' || ch > '9') && ch != '\n') {
                    flagChar = 1;
                }
            }
            ch = getchar();
        }
    } while (((choice < low || choice > high) && flagChar == 0) || flagChar == 1);
    return choice;
}


//��֤ID���� 
bool validateID(const char* id) {
    size_t len = strlen(id);
    if (len < 6 || len > 10) {
        return false;
    }

    for (size_t i = 0; i < len; i++) {
        char c = id[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))) {
            return false;
        }
    }
	while(getchar() != '\n');
    return true;
}

//��֤�ֻ�����Ϊ11λ
bool validatePhoneNumber(const char* phoneNumber) {
    size_t len = strlen(phoneNumber);
	
	
    if (len != 11) {
        return false;
    }


    for (size_t i = 0; i < len; i++) {
        if (phoneNumber[i] < '0' || phoneNumber[i] > '9') {
            return false;
        }
    }
    return true;
}


//��֤�����ʽ�Ƿ���ȷ 
bool validateEmail(const char* email) {
    int length = strlen(email);
    int atIndex = -1;
    int dotIndex = -1;

    if (length < 5) {
        return false;
    }

    // ����@��.
    for (int i = 0; i < length; i++) {
        if (email[i] == '@') {
            if (atIndex != -1 || dotIndex != -1 || i == 0 || i == length - 1 || i > length - 3) {
                // ���@���ţ�����@����λ�ڿ�ͷ����β������λ��@֮���������ַ���λ��
                return false;
            }
            atIndex = i;
        } else if (email[i] == '.') {
            if (dotIndex != -1 || i == 0 || i == length - 1 || i == atIndex + 1) {
                // ���.���ţ�����.����λ�ڿ�ͷ����β������λ��@֮��
                return false;
            }
            dotIndex = i;
        }
    }

    // �������ҽ���һ��@��һ��.
    if (atIndex == -1 || dotIndex == -1) {
        return false;
    }
	while(getchar() != '\n');
    return true;
}


//�ж������ʽ�Ƿ���ȷ 
bool validatePassWord(const char* password) {
    size_t len = strlen(password);
    bool hasDigit = false;
    bool hasLetter = false;
	
	if(len < 6 || len > 16){
		return false;
	} 

    for (size_t i = 0; i < len; i++) {
        if (isalpha(password[i])) {
            hasLetter = true;
        } else if (isdigit(password[i])) {
            hasDigit = true;
        } else if (!isspace(password[i])) {
            return false;  // ����Ȳ�������Ҳ������ĸ���Ҳ��ǿհ��ַ�����������Ч
        }
    }

    return hasDigit && hasLetter;
}


void ValidateID(const char* id){
	while(!validateID(id)){
		CLEANBUFF();
		printf("\t�������ʽ��ȷ��ID,����Ϊ6-10λ: "); 
		scanf("%s", id);
		}
}

void ValidatePassWord(const char* PassWord){
	while(!validatePassWord(PassWord)){
        printf("\t�������ʽ��ȷ�����룬����λ6-16λ,ֻ�ܰ�����ĸ������: ");
        scanf("%s",PassWord);
		}
}

void ValidatePhoneNumber(const char* contactNumber){
	while(!validatePhoneNumber(contactNumber)){
        	printf("\t��������ȷ��"LIGHT_RED"11"NONE"λ�ֻ���: ");
        	scanf("%s",contactNumber);
        	CLEANBUFF();
		}
}	

void ValidateEmail(const char* Email){
	while(!validateEmail(Email)){	
			printf("\t��������ȷ��ʽ�����䣬��ȷ��ʽΪ***@***.*** : ");
			scanf("%s",Email);
		}
}

int calculateDayDifference(const char* date1,const char* date2){
int year1, month1, day1;
    int year2, month2, day2;
    
    sscanf(date1, "%d:%d:%d", &year1, &month1, &day1);
    sscanf(date2, "%d:%d:%d", &year2, &month2, &day2);
    
    // �����������ڵ�����������
    int totalDays1 = year1 * 365 + month1 * 30 + day1;
    int totalDays2 = year2 * 365 + month2 * 30 + day2;
    int diff = abs(totalDays2 - totalDays1);
    
    // �����������췵����Ӧ�Ľ��
    return diff; 
}


void parseTime(const char* timeStr, int* year, int* month, int* day, int* hour) {
    sscanf(timeStr, "%d:%d:%d:%d", year, month, day, hour);
}

//�ж��·�  1-3�·���0   4-6�·���2   7-9�·���4   10-12�·���6
int getMonth(const char* timeStr) {
    int month;
    sscanf(timeStr, "%*d:%d", &month);  // ��ʱ���ַ����н����·�

    if (month >= 1 && month <= 3) {
        return 0;
    } else if (month >= 4 && month <= 6) {
        return 2;
    } else if (month >= 7 && month <= 9) {
        return 4;
    } else if (month >= 10 && month <= 12) {
        return 6;
    }

    return -1;  // �·���Ч
}







void searchByRegion() {
    char searchRegion[50];
    printf("\n\t�������������ƣ����磺�����ж������ȣ���");
    scanf("%s", searchRegion);
    
	int temp_Index;
	time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    char timeString[20];
    strftime(timeString, sizeof(timeString), "%Y:%m:%d:%H:%M", localTime);
	temp_Index = getMonth(timeString);
	
	
	int flag = 0;
    for (int i = 0; i < NumberOfScenic; i++) {
        if (strstr(scenicList[i].Range, searchRegion) != NULL) {
        	PrintWarn(i); 
        	flag = 1;
            printf("\n\tid:"LIGHT_GREEN"%s"NONE"\n\t����:%s\n\t���:%s\n\t�����۸�:"LIGHT_RED"%d"NONE"\n\t�����۸�:"LIGHT_RED"%d"NONE"\n\t��ǰ������������ʱ�䣺%s\n\t��ǰ������������ʱ�䣺%s\n\tѧ���ۿ�:%.1f\n\t�����ۿ�:%.1f\n\t��������:%s\n",
                   scenicList[i].ID, scenicList[i].Name, scenicList[i].Description, scenicList[i].off_season_price,
                   scenicList[i].peak_season_price, scenicList[i].SeasonTimeRange[temp_Index],scenicList[i].SeasonTimeRange[temp_Index + 1], scenicList[i].StudentAccount,
                   scenicList[i].SoldierAccount, scenicList[i].Range);
            // allowbooking();
            printf("\n-----------------------------------------------------\n");
            scenicList[i].Views ++;
        }
    }
    if(!flag){
        printf("\t��ʱ�޷���ѯ����%s��صľ���......", searchRegion);
	}
	dumpScenic(); //��Ϊ�����˾���������,����Ҫ���澰��~ 
	printf("\t");
	system("pause");
	system("cls");
	getchar();
	findScenic();
}

void searchByName() {
    char searchName[50];
    printf("\n\t�����뾰�����ƣ�");
    scanf("%s", searchName);

    int found = 0;
    int i;
    
    int temp_Index;
	time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    char timeString[20];
    strftime(timeString, sizeof(timeString), "%Y:%m:%d:%H:%M", localTime);
	temp_Index = getMonth(timeString);
    
	for (i = 0; i < NumberOfScenic; i++) {
        if (strstr(scenicList[i].Name, searchName)) {
        	PrintWarn(i); 
            printf ("\tid:"LIGHT_GREEN"%s"NONE"\n\t����:%s\n\t���:%s\n\t�����۸�:"LIGHT_RED"%d"NONE"\n\t�����۸�:"LIGHT_RED"%d"NONE"\n\t��������ʱ�䣺%s\n\t��������ʱ�䣺%s\n\tѧ���ۿ�:%.1f\n\t�����ۿ�:%.1f\n\t��������:%s\n" 
		    ,scenicList[i].ID,scenicList[i].Name,scenicList[i].Description
			,scenicList[i].off_season_price,scenicList[i].peak_season_price
			,scenicList[i].SeasonTimeRange[temp_Index],scenicList[i].SeasonTimeRange[temp_Index + 1],scenicList[i].StudentAccount
			,scenicList[i].SoldierAccount,scenicList[i].Range);
            found = 1;
            printf("\n-----------------------------------------------------\n");
            scenicList[i].Views ++;
        }
    }
    

    if (found == 0) {
        printf("\tδ�ҵ��� %s ��صľ���......", searchName);
    }
    dumpScenic(); //��Ϊ�����˾���������,����Ҫ���澰��~ 
	printf("\t");
	system("pause");
	system("cls");
	getchar();
	findScenic();
}


void searchByTickets(){
	
	int temp_Index;
	time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    char timeString[20];
    strftime(timeString, sizeof(timeString), "%Y:%m:%d:%H:%M", localTime);
	temp_Index = getMonth(timeString);
	
	int found = 0;
	for(int i = 0;i < NumberOfScenic;i ++){
		for(int t = 0;t < 10;t ++){
			found = 0;
			if(scenicList[i].Tickets_A[t] || scenicList[i].Tickets_M[t]){
				PrintWarn(i);
				printf ("\n\tid:"LIGHT_GREEN"%s"NONE"\n\t����:%s\n\t���:%s\n\t�����۸�:"LIGHT_RED"%d"NONE"\n\t�����۸�:"LIGHT_RED"%d"NONE"\n\t��������ʱ�䣺%s\n\t��������ʱ�䣺%s\n\tѧ���ۿ�:%.1f\n\t�����ۿ�:%.1f\n\t��������:%s\n" 
		    	,scenicList[i].ID,scenicList[i].Name,scenicList[i].Description
				,scenicList[i].off_season_price,scenicList[i].peak_season_price
				,scenicList[i].SeasonTimeRange[temp_Index],scenicList[i].SeasonTimeRange[temp_Index + 1],scenicList[i].StudentAccount
				,scenicList[i].SoldierAccount,scenicList[i].Range);
				found = 1;
				scenicList[i].Views ++;
			}
			
			if(found == 1){
				for(int j = 0;j < 10;j ++){
					printf("\n\t֮���"LIGHT_RED"%d"NONE"��ʣ��Ʊ��: ����: "LIGHT_RED"%d"NONE" , ����: "LIGHT_RED"%d"NONE"",j+1,scenicList[i].Tickets_M[j],scenicList[i].Tickets_A[j]);
				}
				printf("\n-----------------------------------------------------\n");
				break;
			}
		}
	}
	if(found == 0){
		printf("\n\t���о���10���ڵ�Ʊȫ������"); 
	}
	dumpScenic(); //��Ϊ�����˾���������,����Ҫ���澰��~ 
	printf("\t");
	system("pause");
	system("cls");
	findScenic();
}
// 0 2 4 6
void PriceSort(){
	//��ȡ��ǰʱ�� 


    int Index[100];
    for(int i = 0;i < NumberOfScenic;i ++){
    	Index[i] = i; 
	}
   
    for(int i = 0;i < NumberOfScenic;i ++){  //���� 
		for(int j = i + 1;j < NumberOfScenic;j ++){
			if(scenicList[Index[j]].peak_season_price < scenicList[Index[i]].peak_season_price){
				int temp = Index[i];
				Index[i] = Index[j];
				Index[j] = temp;
			}
		}
	}
    printf("\n\t�����ľ���Ʊ�۽�������\n");
	for(int i = 0;i < NumberOfScenic;i ++){
		printf("\t"LIGHT_GREEN"%s"NONE" %s "LIGHT_RED"%d"NONE" \n",scenicList[Index[i]].ID,scenicList[Index[i]].Name,scenicList[Index[i]].peak_season_price);
	}
	
	for(int i = 0;i < NumberOfScenic;i ++){
    	Index[i] = i; 
	}
	for(int i = 0;i < NumberOfScenic;i ++){  //���� 
		for(int j = i + 1;j < NumberOfScenic;j ++){
			if(scenicList[Index[j]].off_season_price < scenicList[Index[i]].off_season_price){
				int temp = Index[i];
				Index[i] = Index[j];
				Index[j] = temp;
			}
		}
	}
	printf("\t�����ľ���Ʊ�۽�������\n");
	for(int i = 0;i < NumberOfScenic;i ++){
		printf("\t"LIGHT_GREEN"%s"NONE" %s "LIGHT_RED"%d"NONE" \n",scenicList[Index[i]].ID,scenicList[Index[i]].Name,scenicList[Index[i]].off_season_price);
	}
	printf("\t");
	system("pause");
	system("cls");
	findScenic();
}



void ValidateOrderNumber(){
	int TEMP_INDEX = OrderList[g_groups[UserIndex].orderNumber].NumberOfScenicIndex;
    if(TEMP_INDEX == 0){
    initOrder();  //��ʼ������ 
	}else if(TEMP_INDEX >= 1 && TEMP_INDEX <5){
		addOrder();   //��Ӷ��� 
	}else{
	printf(""LIGHT_RED"���Ķ�������"NONE"");
	}
	printf("\t");
	system("pause");
	system("cls");
}


void ReserveSort(){
	int Reserve[100] = {0}; //����һ��ʮ����Ԥ����������
	for(int i = 0;i < NumberOfScenic;i ++){
		Reserve[i] = scenicList[i].Autumn_M * 10 + scenicList[i].Autumn_A * 10;
		for(int t = 0;t < 10;t ++){
			Reserve[i] -= (scenicList[i].Tickets_M[t] + scenicList[i].Tickets_A[t]);
		}
	} 
	
	int Index[100];
    for(int i = 0;i < NumberOfScenic;i ++){
    	Index[i] = i; 
	}
	for(int i = 0;i < NumberOfScenic;i ++){  //���� 
		for(int j = i + 1;j < NumberOfScenic;j ++){
			if(Reserve[Index[j]] > Reserve[Index[i]]){
				int temp = Index[i];
				Index[i] = Index[j];
				Index[j] = temp;
			}
		}
	}
	printf("\n\t��ƱԤ������������\n");
	for(int i = 0;i < NumberOfScenic;i ++){
		printf("\t"LIGHT_GREEN"%s"NONE" %s "LIGHT_RED"%d"NONE" \n",scenicList[Index[i]].ID,scenicList[Index[i]].Name,Reserve[Index[i]]);
	}
	
	printf("\t");
	system("pause");
	system("cls");
}

void ViewsSort(){
	int Index[100];
    for(int i = 0;i < NumberOfScenic;i ++){
    	Index[i] = i; 
	}
	for(int i = 0;i < NumberOfScenic;i ++){  //���� 
		for(int j = i + 1;j < NumberOfScenic;j ++){
			if(scenicList[Index[j]].Views > scenicList[Index[i]].Views){
				int temp = Index[i];
				Index[i] = Index[j];
				Index[j] = temp;
			}
		}
	}
	printf("\n\t�����������������\n");
	for(int i = 0;i < NumberOfScenic;i ++){
		printf("\t"LIGHT_GREEN"%s"NONE" %s "LIGHT_RED"%d"NONE" \n",scenicList[Index[i]].ID,scenicList[Index[i]].Name,scenicList[Index[i]].Views);
	}
	
	printf("\t");
	system("pause");
	system("cls");
} 


void HotTimeSort(){
	int Reserve_M[100];
	int Reserve_A[100];
	
	for(int i = 0;i < NumberOfScenic;i ++){
		Reserve_M[i] = scenicList[i].Autumn_M * 10;
		Reserve_A[i] = scenicList[i].Autumn_A * 10;
		for(int t = 0;t < 10;t ++){
			Reserve_M[i] -= scenicList[i].Tickets_M[t];
			Reserve_A[i] -= scenicList[i].Tickets_A[t];
		}	
	}
	
	
	for(int i = 0;i < NumberOfScenic;i ++){
		if(Reserve_M[i] > Reserve_A[i]){
			printf("\n\t"LIGHT_GREEN"%s"NONE" %s ����Ԥ��ʱ��:"YELLOW"%s"NONE"",scenicList[i].ID,scenicList[i].Name,scenicList[i].SeasonTimeRange[4]);
		}else if(Reserve_M[i] < Reserve_A[i]){
			printf("\n\t"LIGHT_GREEN"%s"NONE" %s ����Ԥ��ʱ��:"YELLOW"%s"NONE"",scenicList[i].ID,scenicList[i].Name,scenicList[i].SeasonTimeRange[5]);
		}else{
			printf("\n\t"LIGHT_GREEN"%s"NONE" %s ����Ԥ��ʱ��:"YELLOW"%s"NONE" and "YELLOW"%s"NONE"",scenicList[i].ID,scenicList[i].Name,scenicList[i].SeasonTimeRange[4],scenicList[i].SeasonTimeRange[5]);
		}
	} 
	printf("\n\t");
	system("pause");
	system("cls");
}


void ProfitSort(){
	int Index[100];
    for(int i = 0;i < NumberOfScenic;i ++){
    	Index[i] = i; 
	}
   
    for(int i = 0;i < NumberOfScenic;i ++){  
		for(int j = i + 1;j < NumberOfScenic;j ++){
			if(scenicList[Index[j]].Costs < scenicList[Index[i]].Costs){
				int temp = Index[i];
				Index[i] = Index[j];
				Index[j] = temp;
			}
		}
	}
    printf("\n\t��������������\n");
	for(int i = 0;i < NumberOfScenic;i ++){
		printf("\t"LIGHT_GREEN"[%d]"NONE" "LIGHT_GREEN"%s"NONE" %s "LIGHT_RED"%.1f"NONE" \n",i + 1,scenicList[Index[i]].ID,scenicList[Index[i]].Name,scenicList[Index[i]].Profit);
	}
	printf("\t");
	system("pause");
	system("cls");
}

void ageLevelSort(){
	int ageLevel[100][10];
	memset(ageLevel, 0, sizeof(ageLevel));
	
	
	for(int i = 0;i < NumberOfOrder;i ++){
		for(int t = 0;t < 5;t ++){
			if(OrderList[i].ScenicIndex[t] != -1){
				for(int j = 0;j < 10;j ++){
					ageLevel[OrderList[i].ScenicIndex[t]][j] += g_groups[OrderList[i].UserIndex].ageLevel[j];
				}
			}
		}
	}
	for(int i = 0;i < NumberOfScenic;i ++){
		printf("\n\t"LIGHT_GREEN"%s"NONE" "YELLOW"%s"NONE"�����������:\n",scenicList[i].ID,scenicList[i].Name);
		for(int j = 0;j < 10;j ++){
			printf("\t�� "LIGHT_GREEN"%d0"NONE" �� "LIGHT_GREEN"%d0"NONE" �����ε�����: %d\n",j,j+1,ageLevel[i][j]);
		}
	} 
	printf("\t");
	system("pause");
	system("cls");
}


void SeasonSoldSort(){
	int seasonSold[100][4];  //0������ 1�����ļ� 2�����＾ 3������ 
	memset(seasonSold, 0, sizeof(seasonSold));
	for(int i = 0;i < NumberOfScenic;i ++){
		seasonSold[i][2] = scenicList[i].Autumn_M * 10 + scenicList[i].Autumn_A * 10;
		for(int t = 0;t < 10;t ++){
			seasonSold[i][2] -= (scenicList[i].Tickets_M[t] + scenicList[i].Tickets_A[t]);
		}
	} 
	for(int i = 0;i < NumberOfScenic;i ++){
		printf("\t"LIGHT_GREEN"%s"NONE" %s ��Ʊ���ʱ��:"YELLOW"�＾"NONE",��Ʊ��: "LIGHT_RED"%d"NONE"\n",scenicList[i].ID,scenicList[i].Name,seasonSold[i][2]);
	}
	printf("\t");
	system("pause");
	system("cls");
}


bool isDateFormatValid(const char* str) {
    int year, month, day, hour;
    char delimiter1, delimiter2, delimiter3;

    // ʹ�� sscanf ���������ַ���
    if (sscanf(str, "%d%c%d%c%d%c%d", &year, &delimiter1, &month, &delimiter2, &day, &delimiter3, &hour) != 7) {
        return false;
    }

    // ���������ֵ�ͷָ����Ƿ����Ҫ��
    if (delimiter1 != ':' || delimiter2 != ':' || delimiter3 != ':' ||
        year < 0 || month < 1 || month > 12 || day < 1 || day > 31 || hour < 0 || hour > 23) {
        return false;
    }

    return true;
}

int isDateTimeInRange(const char* timeStr) {
    int year, month, day, hour;
    if (sscanf(timeStr, "%d:%d:%d:%d", &year, &month, &day, &hour) != 4) {
        return 0;  // ��ʽ����
    }

    if (year != 2023 || month != 9 || day < 6 || day > 15) {
        return 0;  // ����ָ�����ڷ�Χ��
    }

    return 1;  // ʱ����Ч
}

void showScenicByAccount(){
	for (int i = 0; i < NumberOfScenic; i++) {
	if(abs(scenicList[i].StudentAccount) < 0.95 || abs(scenicList[i].SoldierAccount) < 0.95){
		printf("\n�� "LIGHT_GREEN"%d"NONE" ���������Ϣ���£�\n", i + 1);
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
	}
	printf("\t");
	system("pause");
	system("cls");
}

void HotSort(){
	int Reserve[100] = {0}; //����һ��ʮ����Ԥ����������
	for(int i = 0;i < NumberOfScenic;i ++){
		Reserve[i] = scenicList[i].Autumn_M * 10 + scenicList[i].Autumn_A * 10 + scenicList[i].Views; 
		for(int t = 0;t < 10;t ++){
			Reserve[i] -= (scenicList[i].Tickets_M[t] + scenicList[i].Tickets_A[t]);
		}
	} 
	
	int Index[100];
    for(int i = 0;i < NumberOfScenic;i ++){
    	Index[i] = i; 
	}
	for(int i = 0;i < NumberOfScenic;i ++){  //���� 
		for(int j = i + 1;j < NumberOfScenic;j ++){
			if(Reserve[Index[j]] > Reserve[Index[i]]){
				int temp = Index[i];
				Index[i] = Index[j];
				Index[j] = temp;
			}
		}
	}
	printf("\n\t�����ۺ��ȶ�(Ԥ����+�����)��������\n");
	for(int i = 0;i < NumberOfScenic;i ++){
		printf("\t"LIGHT_GREEN"%s"NONE" %s "LIGHT_RED"%d"NONE" \n",scenicList[Index[i]].ID,scenicList[Index[i]].Name,Reserve[Index[i]]);
	}	
	printf("\t");
	system("pause");
	system("cls");
	
} 

void CLEANBUFF(){
	char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}


