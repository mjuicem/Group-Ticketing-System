#include "scenic.h"

void loadScenic() {  

    // 打开文件
    FILE* fp_input = fopen("scenicData.txt", "r");
    // while 死循环读取文件内容
    while (1) {
        // 如果达到文件结尾就跳出循环
        if (feof(fp_input)) {
            break;
        }

        // 依次扫描六个字段
        char ID[8];  //景点信息 
		char Name[20]; //名称 
		char Description[100]; //景点描述 
		int peak_season_price;  //高峰期价格 
    	int off_season_price; //低谷期价格 
		char level[10]; //景点级别 
		float StudentAccount;  //学生折扣 
		float SoldierAccount;  //军人折扣
		int Spring_M;
		int Spring_A;
		int Summer_M;
		int Summer_A;
		int Autumn_A;
		int Autumn_M;
		int Winter_A;
		int Winter_M; 
		
		char Range[20];  //景点所属区域 
		float Costs; //景点维护费用 
		float Profit;
		int Tickets_M[10];
		int Tickets_A[10];
		//int Tickets[30]; //30天内的票 
		//int RemainTickets[30];  //30天内剩余的票 
		//char startTime[30]; //景点开始售票日期 
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
        	fscanf(fp_input, "%s ", &scenicList[NumberOfScenic].SeasonTimeRange[i][0]);  //读入不同季节的时间限制 
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
        // 将读取的数据保存到景点结构体数组中
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
        // 更新景点数量计数器
        NumberOfScenic ++;
    }

    // 关闭文件
    fclose(fp_input);
    printf(""YELLOW"@Test"NONE": 初始化库：从景点文件中加载了 "LIGHT_GREEN"%d"NONE" 条景点信息\n", NumberOfScenic);
}


void showScenic(){
	for (int i = 0; i < NumberOfScenic; i++) {
        printf("\n第 "LIGHT_GREEN"%d"NONE" 个景点的信息如下：\n", i + 1);
        PrintWarn(i); 
        printf("景点编号: %s\n", scenicList[i].ID);
        printf("名称: "YELLOW"%s"NONE"\n", scenicList[i].Name);
        printf("景点描述: %s\n", scenicList[i].Description);
        printf("旺季期价格: "LIGHT_RED"%d"NONE"\n",scenicList[i].peak_season_price);
        printf("淡季期价格: "LIGHT_RED"%d"NONE"\n",scenicList[i].off_season_price);
        printf("学生折扣: %.1f\n", scenicList[i].StudentAccount);
        printf("老人折扣: %.1f\n", scenicList[i].SoldierAccount);
        printf("景点级别: %s\n", scenicList[i].level);
        printf("接下来是景点各个季节以及时间段的限制人数\n");
        PrintScenicTicketsLimit(i);
        printf("景点所属区域: %s\n", scenicList[i].Range);
		PrintScenicTicketsRemain(i); 
		printf("景点浏览量: %d\n", scenicList[i].Views);
        scenicList[i].Views ++;
        printf("-----------------------------------------------------\n");
    }
    dumpScenic(); //因为增加了景点的浏览量,所以要保存景点~ 
	system("pause");
	system("cls");
}

void showScenicByAdmin(){
	for (int i = 0; i < NumberOfScenic; i++) {
        printf("\n第 "LIGHT_GREEN"%d"NONE" 个景点的信息如下：\n", i + 1);
        printf("景点编号: "LIGHT_GREEN"%s"NONE"\n", scenicList[i].ID);
        printf("名称: "YELLOW"%s"NONE"\n", scenicList[i].Name);
        printf("景点描述: %s\n", scenicList[i].Description);
        printf("旺季期价格: %d\n",scenicList[i].peak_season_price);
        printf("淡季期价格: %d\n",scenicList[i].off_season_price);
        printf("学生折扣: %.1f\n", scenicList[i].StudentAccount);
        printf("老人折扣: %.1f\n", scenicList[i].SoldierAccount);
        printf("景点级别: %s\n", scenicList[i].level);
        PrintScenicTicketsLimit(i);
        printf("景点所属区域: %s\n", scenicList[i].Range);
        printf("景点维护费用: %.2f\n", scenicList[i].Costs);
        printf("景点利润: %.2f\n", scenicList[i].Profit); 
        printf("未来10天的剩余票数\n");
        PrintScenicTicketsRemain(i);
        
	
		printf("景点浏览量: %d\n", scenicList[i].Views);
        printf("-----------------------------------------------------\n");
    }
    system("pause");
    system("cls"); 
}

//添加新景点 
void addScenic(){
	// 添加管理员 
    while (1) {
    	printf("\t"LIGHT_RED"TIPS:景点ID限制为六位,请管理员认真按照规范填写"NONE"\n"); 
        printf("\t添加景点信息：\n");

        printf("\t请输入要添加的景点的ID: ");
        
        char ID[8];  //景点ID
		char Name[10]; //名称 
		char Description[100]; //景点描述 
		int peak_season_price;  //高峰期价格 
    	int off_season_price; //低谷期价格 
		char level[10]; //景点级别 
		float StudentAccount;  //学生折扣 
		float SoldierAccount;  //军人折扣
		int Spring_M;
		int Spring_A;
		int Summer_M;
		int Summer_A;
		int Autumn_A;
		int Autumn_M;
		int Winter_A;
		int Winter_M; 
		char Range[20];  //景点所属区域 
		float Costs; //景点维护费用 
		scanf("%s",ID); 
        int found = 0;
        // 在数组中，从左往右，依次查找此ID是否存在
        for (int i = 0; i < NumberOfScenic; i++) {
            // 存在
            if (strcmp(scenicList[i].ID, ID) == 0) {
                // 标记
                found = 1;
                // 结束循环
                break;
            }
        }
        // 如果存在重复的ID，给出提示，并 continue 进入下一次 while 循环。
        if (found) {
            printf("\tID重复，无法添加\n");
            system("cls");
            continue;
        }
        //输入
    
        printf("\t请输入景点名称: ");
        scanf("%s", Name);
        printf("\t请输入景点描述: ");
        scanf("%s", Description);
        printf("\t请输入景点旺季价格: ");
        scanf("%d", &peak_season_price);
        printf("\t请输入景点淡季价格: ");
        scanf("%d", &off_season_price);
        //printf("\t请输入游玩景点限制: ");
        //scanf("%s", time_range);
        printf("\t请输入景点等级: ");
        scanf("%s", level);
        printf("\t请输入学生折扣: ");
        scanf("%f", &StudentAccount);
        printf("\t请输入军人折扣: ");
        scanf("%f", &SoldierAccount);
        
        printf("\t请输入1月 - 3月上午人数限制: ");
		scanf("%d", &Spring_M);
		printf("\t请输入1月 - 3月下午人数限制: ");
		scanf("%d", &Spring_A);
		printf("\t请输入4月 - 6月上午人数限制: ");
		scanf("%d", &Summer_M);
		printf("\t请输入4月 - 6月下午人数限制: ");
		scanf("%d", &Summer_A);
		printf("\t请输入7月 - 9月上午人数限制: ");
		scanf("%d", &Autumn_M);
		printf("\t请输入7月 - 9月下午人数限制: ");
		scanf("%d", &Autumn_A);
		printf("\t请输入10月 - 12月上午人数限制: ");
		scanf("%d", &Winter_M);
		printf("\t请输入10月 - 12月下午人数限制: ");
		scanf("%d", &Winter_A);
		
		
		printf("\t请输入1月 - 3月上午时间限制: ");
		scanf("%s", &scenicList[NumberOfScenic].SeasonTimeRange[0][0]);
		printf("\t请输入1月 - 3月下午时间限制: ");
		scanf("%s", &scenicList[NumberOfScenic].SeasonTimeRange[1][0]);
		printf("\t请输入4月 - 6月上午时间限制: ");
		scanf("%s", &scenicList[NumberOfScenic].SeasonTimeRange[2][0]);
		printf("\t请输入4月 - 6月下午时间限制: ");
		scanf("%s", &scenicList[NumberOfScenic].SeasonTimeRange[3][0]);
		printf("\t请输入7月 - 9月上午时间限制: ");
		scanf("%s", &scenicList[NumberOfScenic].SeasonTimeRange[4][0]);
		printf("\t请输入7月 - 9月下午时间限制: ");
		scanf("%s", &scenicList[NumberOfScenic].SeasonTimeRange[5][0]);
		printf("\t请输入10月 - 12月上午时间限制: ");
		scanf("%s", &scenicList[NumberOfScenic].SeasonTimeRange[6][0]);
		printf("\t请输入10月 - 12月下午时间限制: ");
		scanf("%s", &scenicList[NumberOfScenic].SeasonTimeRange[7][0]);
		printf("\t请输入景点位置: ");
		scanf("%s", Range);
		printf("\t请输入景点维修费用: ");
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
        // 将读取的数据保存到景点结构体数组中
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
    	printf("\t是否发布景点?  [1]确定 [2]取消 [3]修改:");
    	int choice = MyInput(1,3);
    	if(choice == 1){
    		NumberOfScenic ++;
			dumpScenic(); 
        	printf("\t保存成功。是否继续添加(Y/N): ");
        	char yes_no[2];
        	scanf("%s", yes_no);
        	getchar();
        	// 没有输入Y或者y，就跳出循环
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
	// 打开文件
    FILE* fp_input = fopen("scenicData.txt", "w");

    // 遍历数组，并依次写入
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
	
    // 关闭文件
    fclose(fp_input);
} 

void PrintScenicTicketsRemain(int i){
	printf("2023:09:06上午%s的剩余票数: "LIGHT_RED"%d"NONE"\t下午%s的剩余票数: "LIGHT_RED"%d"NONE"\n",scenicList[i].SeasonTimeRange[4]
	,scenicList[i].Tickets_M[0],scenicList[i].SeasonTimeRange[5],scenicList[i].Tickets_A[0]); 
    printf("2023:09:07上午%s的剩余票数: "LIGHT_RED"%d"NONE"\t下午%s的剩余票数: "LIGHT_RED"%d"NONE"\n",scenicList[i].SeasonTimeRange[4]
	,scenicList[i].Tickets_M[1],scenicList[i].SeasonTimeRange[5],scenicList[i].Tickets_A[1]);
	printf("2023:09:08上午%s的剩余票数: "LIGHT_RED"%d"NONE"\t下午%s的剩余票数: "LIGHT_RED"%d"NONE"\n",scenicList[i].SeasonTimeRange[4]
	,scenicList[i].Tickets_M[2],scenicList[i].SeasonTimeRange[5],scenicList[i].Tickets_A[2]);
	printf("2023:09:09上午%s的剩余票数: "LIGHT_RED"%d"NONE"\t下午%s的剩余票数: "LIGHT_RED"%d"NONE"\n",scenicList[i].SeasonTimeRange[4]
	,scenicList[i].Tickets_M[3],scenicList[i].SeasonTimeRange[5],scenicList[i].Tickets_A[3]);
	printf("2023:09:10上午%s的剩余票数: "LIGHT_RED"%d"NONE"\t下午%s的剩余票数: "LIGHT_RED"%d"NONE"\n",scenicList[i].SeasonTimeRange[4]
	,scenicList[i].Tickets_M[4],scenicList[i].SeasonTimeRange[5],scenicList[i].Tickets_A[4]);
	printf("2023:09:11上午%s的剩余票数: "LIGHT_RED"%d"NONE"\t下午%s的剩余票数: "LIGHT_RED"%d"NONE"\n",scenicList[i].SeasonTimeRange[4]
	,scenicList[i].Tickets_M[5],scenicList[i].SeasonTimeRange[5],scenicList[i].Tickets_A[5]);
	printf("2023:09:12上午%s的剩余票数: "LIGHT_RED"%d"NONE"\t下午%s的剩余票数: "LIGHT_RED"%d"NONE"\n",scenicList[i].SeasonTimeRange[4]
	,scenicList[i].Tickets_M[6],scenicList[i].SeasonTimeRange[5],scenicList[i].Tickets_A[6]);
	printf("2023:09:13上午%s的剩余票数: "LIGHT_RED"%d"NONE"\t下午%s的剩余票数: "LIGHT_RED"%d"NONE"\n",scenicList[i].SeasonTimeRange[4]
	,scenicList[i].Tickets_M[7],scenicList[i].SeasonTimeRange[5],scenicList[i].Tickets_A[7]);
	printf("2023:09:14上午%s的剩余票数: "LIGHT_RED"%d"NONE"\t下午%s的剩余票数: "LIGHT_RED"%d"NONE"\n",scenicList[i].SeasonTimeRange[4]
	,scenicList[i].Tickets_M[8],scenicList[i].SeasonTimeRange[5],scenicList[i].Tickets_A[8]);
	printf("2023:09:15上午%s的剩余票数: "LIGHT_RED"%d"NONE"\t下午%s的剩余票数: "LIGHT_RED"%d"NONE"\n",scenicList[i].SeasonTimeRange[4]
	,scenicList[i].Tickets_M[9],scenicList[i].SeasonTimeRange[5],scenicList[i].Tickets_A[9]);
}

void PrintScenicTicketsLimit(int i){
	    printf("1月 - 3月 上午开放时间: "LIGHT_GREEN"%s"NONE"\t限制人数: "LIGHT_GREEN"%d"NONE"\n"
		, scenicList[i].SeasonTimeRange[0],scenicList[i].Spring_M);
        printf("1月 - 3月 下午开放时间: "LIGHT_GREEN"%s"NONE"\t限制人数: "LIGHT_GREEN"%d"NONE"\n"
		, scenicList[i].SeasonTimeRange[1],scenicList[i].Spring_A);
        printf("4月 - 6月 上午开放时间: "LIGHT_GREEN"%s"NONE"\t限制人数: "LIGHT_GREEN"%d"NONE"\n"
		, scenicList[i].SeasonTimeRange[2],scenicList[i].Summer_M);
        printf("4月 - 6月 下午开放时间: "LIGHT_GREEN"%s"NONE"\t限制人数: "LIGHT_GREEN"%d"NONE"\n"
		, scenicList[i].SeasonTimeRange[3],scenicList[i].Summer_A);
        printf("7月 - 9月 上午开放时间: "LIGHT_GREEN"%s"NONE"\t限制人数: "LIGHT_GREEN"%d"NONE"\n"
		, scenicList[i].SeasonTimeRange[4],scenicList[i].Autumn_M);
        printf("7月 - 9月 下午开放时间: "LIGHT_GREEN"%s"NONE"\t限制人数: "LIGHT_GREEN"%d"NONE"\n"
		, scenicList[i].SeasonTimeRange[5],scenicList[i].Autumn_A);
        printf("10月 - 12月 上午开放时间: "LIGHT_GREEN"%s"NONE"\t限制人数: "LIGHT_GREEN"%d"NONE"\n"
		, scenicList[i].SeasonTimeRange[6],scenicList[i].Winter_M);
        printf("10月 - 12月 下午开放时间: "LIGHT_GREEN"%s"NONE"\t限制人数: "LIGHT_GREEN"%d"NONE"\n"
		, scenicList[i].SeasonTimeRange[7],scenicList[i].Winter_A);
}
		
void PrintWarn(int i){
		if(i == 1 || i == 6 || i == 8){
			printf("\t"LIGHT_RED"TIPS:该景点游玩需要大量的运动量,请老人小孩按自己身体状况合理考虑出行\n"NONE"");
		}
		
		if(i == 12 || i == 13){
			printf("\t"LIGHT_RED"TIPS:该地为大学校园,请根据学校开放时间合理安排出行\n"NONE"");
		}
}
