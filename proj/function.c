#include "function.h"

int MyInput(int low, int high) {
    int choice = 0, // 选择
        result = 0, // 每一轮的结果
        flagNum = 0, // 是否输入数字
        total = 0, // 循环次数
        flagChar = 0; // 是否输入字符
    char ch;

    do {
        result = 0;
        flagChar = 0;
        flagNum = 0;
        total++;

        if (total >= 2) {
            printf("\t您的输入有误，请重新输入： ");
        }

        ch = getchar();

        // 跳过空格
        while (ch == ' ') {
            ch = getchar();
        }

        while (ch != '\n') {
            if (ch >= '0' && ch <= '9') {
                flagNum = 1;
                if (flagChar == 0) {
                    // 如果已经有数字输入，且当前输入为0，则忽略前导0
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


//验证ID长度 
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

//验证手机号码为11位
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


//验证邮箱格式是否正确 
bool validateEmail(const char* email) {
    int length = strlen(email);
    int atIndex = -1;
    int dotIndex = -1;

    if (length < 5) {
        return false;
    }

    // 查找@和.
    for (int i = 0; i < length; i++) {
        if (email[i] == '@') {
            if (atIndex != -1 || dotIndex != -1 || i == 0 || i == length - 1 || i > length - 3) {
                // 多个@符号，或者@符号位于开头、结尾，或者位于@之后不足两个字符的位置
                return false;
            }
            atIndex = i;
        } else if (email[i] == '.') {
            if (dotIndex != -1 || i == 0 || i == length - 1 || i == atIndex + 1) {
                // 多个.符号，或者.符号位于开头、结尾，或者位于@之后
                return false;
            }
            dotIndex = i;
        }
    }

    // 必须有且仅有一个@和一个.
    if (atIndex == -1 || dotIndex == -1) {
        return false;
    }
	while(getchar() != '\n');
    return true;
}


//判断密码格式是否正确 
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
            return false;  // 如果既不是数字也不是字母，且不是空白字符，则密码无效
        }
    }

    return hasDigit && hasLetter;
}


void ValidateID(const char* id){
	while(!validateID(id)){
		CLEANBUFF();
		printf("\t请输入格式正确的ID,长度为6-10位: "); 
		scanf("%s", id);
		}
}

void ValidatePassWord(const char* PassWord){
	while(!validatePassWord(PassWord)){
        printf("\t请输入格式正确的密码，长度位6-16位,只能包含字母与数字: ");
        scanf("%s",PassWord);
		}
}

void ValidatePhoneNumber(const char* contactNumber){
	while(!validatePhoneNumber(contactNumber)){
        	printf("\t请输入正确的"LIGHT_RED"11"NONE"位手机号: ");
        	scanf("%s",contactNumber);
        	CLEANBUFF();
		}
}	

void ValidateEmail(const char* Email){
	while(!validateEmail(Email)){	
			printf("\t请输入正确格式的邮箱，正确格式为***@***.*** : ");
			scanf("%s",Email);
		}
}

int calculateDayDifference(const char* date1,const char* date2){
int year1, month1, day1;
    int year2, month2, day2;
    
    sscanf(date1, "%d:%d:%d", &year1, &month1, &day1);
    sscanf(date2, "%d:%d:%d", &year2, &month2, &day2);
    
    // 计算两个日期的总天数差异
    int totalDays1 = year1 * 365 + month1 * 30 + day1;
    int totalDays2 = year2 * 365 + month2 * 30 + day2;
    int diff = abs(totalDays2 - totalDays1);
    
    // 根据天数差异返回相应的结果
    return diff; 
}


void parseTime(const char* timeStr, int* year, int* month, int* day, int* hour) {
    sscanf(timeStr, "%d:%d:%d:%d", year, month, day, hour);
}

//判断月份  1-3月返回0   4-6月返回2   7-9月返回4   10-12月返回6
int getMonth(const char* timeStr) {
    int month;
    sscanf(timeStr, "%*d:%d", &month);  // 从时间字符串中解析月份

    if (month >= 1 && month <= 3) {
        return 0;
    } else if (month >= 4 && month <= 6) {
        return 2;
    } else if (month >= 7 && month <= 9) {
        return 4;
    } else if (month >= 10 && month <= 12) {
        return 6;
    }

    return -1;  // 月份无效
}







void searchByRegion() {
    char searchRegion[50];
    printf("\n\t请输入区域名称（例如：北京市东城区等）：");
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
            printf("\n\tid:"LIGHT_GREEN"%s"NONE"\n\t名称:%s\n\t简介:%s\n\t旺季价格:"LIGHT_RED"%d"NONE"\n\t淡季价格:"LIGHT_RED"%d"NONE"\n\t当前景点上午游览时间：%s\n\t当前景点下午游览时间：%s\n\t学生折扣:%.1f\n\t军人折扣:%.1f\n\t所属区域:%s\n",
                   scenicList[i].ID, scenicList[i].Name, scenicList[i].Description, scenicList[i].off_season_price,
                   scenicList[i].peak_season_price, scenicList[i].SeasonTimeRange[temp_Index],scenicList[i].SeasonTimeRange[temp_Index + 1], scenicList[i].StudentAccount,
                   scenicList[i].SoldierAccount, scenicList[i].Range);
            // allowbooking();
            printf("\n-----------------------------------------------------\n");
            scenicList[i].Views ++;
        }
    }
    if(!flag){
        printf("\t暂时无法查询到与%s相关的景点......", searchRegion);
	}
	dumpScenic(); //因为增加了景点的浏览量,所以要保存景点~ 
	printf("\t");
	system("pause");
	system("cls");
	getchar();
	findScenic();
}

void searchByName() {
    char searchName[50];
    printf("\n\t请输入景点名称：");
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
            printf ("\tid:"LIGHT_GREEN"%s"NONE"\n\t名称:%s\n\t简介:%s\n\t旺季价格:"LIGHT_RED"%d"NONE"\n\t淡季价格:"LIGHT_RED"%d"NONE"\n\t上午游览时间：%s\n\t下午游览时间：%s\n\t学生折扣:%.1f\n\t军人折扣:%.1f\n\t所属区域:%s\n" 
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
        printf("\t未找到与 %s 相关的景点......", searchName);
    }
    dumpScenic(); //因为增加了景点的浏览量,所以要保存景点~ 
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
				printf ("\n\tid:"LIGHT_GREEN"%s"NONE"\n\t名称:%s\n\t简介:%s\n\t旺季价格:"LIGHT_RED"%d"NONE"\n\t淡季价格:"LIGHT_RED"%d"NONE"\n\t上午游览时间：%s\n\t下午游览时间：%s\n\t学生折扣:%.1f\n\t军人折扣:%.1f\n\t所属区域:%s\n" 
		    	,scenicList[i].ID,scenicList[i].Name,scenicList[i].Description
				,scenicList[i].off_season_price,scenicList[i].peak_season_price
				,scenicList[i].SeasonTimeRange[temp_Index],scenicList[i].SeasonTimeRange[temp_Index + 1],scenicList[i].StudentAccount
				,scenicList[i].SoldierAccount,scenicList[i].Range);
				found = 1;
				scenicList[i].Views ++;
			}
			
			if(found == 1){
				for(int j = 0;j < 10;j ++){
					printf("\n\t之后第"LIGHT_RED"%d"NONE"天剩余票数: 上午: "LIGHT_RED"%d"NONE" , 下午: "LIGHT_RED"%d"NONE"",j+1,scenicList[i].Tickets_M[j],scenicList[i].Tickets_A[j]);
				}
				printf("\n-----------------------------------------------------\n");
				break;
			}
		}
	}
	if(found == 0){
		printf("\n\t所有景点10天内的票全卖完啦"); 
	}
	dumpScenic(); //因为增加了景点的浏览量,所以要保存景点~ 
	printf("\t");
	system("pause");
	system("cls");
	findScenic();
}
// 0 2 4 6
void PriceSort(){
	//获取当前时间 


    int Index[100];
    for(int i = 0;i < NumberOfScenic;i ++){
    	Index[i] = i; 
	}
   
    for(int i = 0;i < NumberOfScenic;i ++){  //旺季 
		for(int j = i + 1;j < NumberOfScenic;j ++){
			if(scenicList[Index[j]].peak_season_price < scenicList[Index[i]].peak_season_price){
				int temp = Index[i];
				Index[i] = Index[j];
				Index[j] = temp;
			}
		}
	}
    printf("\n\t旺季的景点票价降序排行\n");
	for(int i = 0;i < NumberOfScenic;i ++){
		printf("\t"LIGHT_GREEN"%s"NONE" %s "LIGHT_RED"%d"NONE" \n",scenicList[Index[i]].ID,scenicList[Index[i]].Name,scenicList[Index[i]].peak_season_price);
	}
	
	for(int i = 0;i < NumberOfScenic;i ++){
    	Index[i] = i; 
	}
	for(int i = 0;i < NumberOfScenic;i ++){  //旺季 
		for(int j = i + 1;j < NumberOfScenic;j ++){
			if(scenicList[Index[j]].off_season_price < scenicList[Index[i]].off_season_price){
				int temp = Index[i];
				Index[i] = Index[j];
				Index[j] = temp;
			}
		}
	}
	printf("\t淡季的景点票价降序排行\n");
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
    initOrder();  //初始化订单 
	}else if(TEMP_INDEX >= 1 && TEMP_INDEX <5){
		addOrder();   //添加订单 
	}else{
	printf(""LIGHT_RED"您的订单已满"NONE"");
	}
	printf("\t");
	system("pause");
	system("cls");
}


void ReserveSort(){
	int Reserve[100] = {0}; //创建一个十天内预定量的数组
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
	for(int i = 0;i < NumberOfScenic;i ++){  //旺季 
		for(int j = i + 1;j < NumberOfScenic;j ++){
			if(Reserve[Index[j]] > Reserve[Index[i]]){
				int temp = Index[i];
				Index[i] = Index[j];
				Index[j] = temp;
			}
		}
	}
	printf("\n\t门票预定量升序排行\n");
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
	for(int i = 0;i < NumberOfScenic;i ++){  //旺季 
		for(int j = i + 1;j < NumberOfScenic;j ++){
			if(scenicList[Index[j]].Views > scenicList[Index[i]].Views){
				int temp = Index[i];
				Index[i] = Index[j];
				Index[j] = temp;
			}
		}
	}
	printf("\n\t景点浏览量升序排行\n");
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
			printf("\n\t"LIGHT_GREEN"%s"NONE" %s 热门预定时间:"YELLOW"%s"NONE"",scenicList[i].ID,scenicList[i].Name,scenicList[i].SeasonTimeRange[4]);
		}else if(Reserve_M[i] < Reserve_A[i]){
			printf("\n\t"LIGHT_GREEN"%s"NONE" %s 热门预定时间:"YELLOW"%s"NONE"",scenicList[i].ID,scenicList[i].Name,scenicList[i].SeasonTimeRange[5]);
		}else{
			printf("\n\t"LIGHT_GREEN"%s"NONE" %s 热门预定时间:"YELLOW"%s"NONE" and "YELLOW"%s"NONE"",scenicList[i].ID,scenicList[i].Name,scenicList[i].SeasonTimeRange[4],scenicList[i].SeasonTimeRange[5]);
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
    printf("\n\t景点利润降序排行\n");
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
		printf("\n\t"LIGHT_GREEN"%s"NONE" "YELLOW"%s"NONE"景点的年龄层次:\n",scenicList[i].ID,scenicList[i].Name);
		for(int j = 0;j < 10;j ++){
			printf("\t第 "LIGHT_GREEN"%d0"NONE" 到 "LIGHT_GREEN"%d0"NONE" 年龄层次的人数: %d\n",j,j+1,ageLevel[i][j]);
		}
	} 
	printf("\t");
	system("pause");
	system("cls");
}


void SeasonSoldSort(){
	int seasonSold[100][4];  //0代表春季 1代表夏季 2代表秋季 3代表冬季 
	memset(seasonSold, 0, sizeof(seasonSold));
	for(int i = 0;i < NumberOfScenic;i ++){
		seasonSold[i][2] = scenicList[i].Autumn_M * 10 + scenicList[i].Autumn_A * 10;
		for(int t = 0;t < 10;t ++){
			seasonSold[i][2] -= (scenicList[i].Tickets_M[t] + scenicList[i].Tickets_A[t]);
		}
	} 
	for(int i = 0;i < NumberOfScenic;i ++){
		printf("\t"LIGHT_GREEN"%s"NONE" %s 售票最好时期:"YELLOW"秋季"NONE",售票量: "LIGHT_RED"%d"NONE"\n",scenicList[i].ID,scenicList[i].Name,seasonSold[i][2]);
	}
	printf("\t");
	system("pause");
	system("cls");
}


bool isDateFormatValid(const char* str) {
    int year, month, day, hour;
    char delimiter1, delimiter2, delimiter3;

    // 使用 sscanf 函数解析字符串
    if (sscanf(str, "%d%c%d%c%d%c%d", &year, &delimiter1, &month, &delimiter2, &day, &delimiter3, &hour) != 7) {
        return false;
    }

    // 检查解析后的值和分隔符是否符合要求
    if (delimiter1 != ':' || delimiter2 != ':' || delimiter3 != ':' ||
        year < 0 || month < 1 || month > 12 || day < 1 || day > 31 || hour < 0 || hour > 23) {
        return false;
    }

    return true;
}

int isDateTimeInRange(const char* timeStr) {
    int year, month, day, hour;
    if (sscanf(timeStr, "%d:%d:%d:%d", &year, &month, &day, &hour) != 4) {
        return 0;  // 格式错误
    }

    if (year != 2023 || month != 9 || day < 6 || day > 15) {
        return 0;  // 不在指定日期范围内
    }

    return 1;  // 时间有效
}

void showScenicByAccount(){
	for (int i = 0; i < NumberOfScenic; i++) {
	if(abs(scenicList[i].StudentAccount) < 0.95 || abs(scenicList[i].SoldierAccount) < 0.95){
		printf("\n第 "LIGHT_GREEN"%d"NONE" 个景点的信息如下：\n", i + 1);
        printf("景点编号: %s\n", scenicList[i].ID);
        printf("名称: "YELLOW"%s"NONE"\n", scenicList[i].Name);
        printf("景点描述: %s\n", scenicList[i].Description);
        printf("旺季期价格: "LIGHT_RED"%d"NONE"\n",scenicList[i].peak_season_price);
        printf("淡季期价格: "LIGHT_RED"%d"NONE"\n",scenicList[i].off_season_price);
        printf("学生折扣: %.1f\n", scenicList[i].StudentAccount);
        printf("军人折扣: %.1f\n", scenicList[i].SoldierAccount);
        printf("景点级别: %s\n", scenicList[i].level);
        printf("接下来是景点各个季节以及时间段的限制人数\n");
        PrintScenicTicketsLimit(i);
        printf("景点所属区域: %s\n", scenicList[i].Range);
		PrintScenicTicketsRemain(i); 
		printf("景点浏览量: %d\n", scenicList[i].Views);
        scenicList[i].Views ++;
        printf("-----------------------------------------------------\n");
		}
	}
	printf("\t");
	system("pause");
	system("cls");
}

void HotSort(){
	int Reserve[100] = {0}; //创建一个十天内预定量的数组
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
	for(int i = 0;i < NumberOfScenic;i ++){  //旺季 
		for(int j = i + 1;j < NumberOfScenic;j ++){
			if(Reserve[Index[j]] > Reserve[Index[i]]){
				int temp = Index[i];
				Index[i] = Index[j];
				Index[j] = temp;
			}
		}
	}
	printf("\n\t根据综合热度(预定量+浏览量)进行排序\n");
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


