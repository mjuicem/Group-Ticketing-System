#include "order.h"

void loadOrder(){
	// 打开文件
    FILE* fp_input = fopen("orderData.txt", "r");

    // while 死循环读取文件内容
    while (1) {
        // 如果达到文件结尾就跳出循环
        if (feof(fp_input)) {
            break;
        }

        // 依次扫描六个字段
        char ID[30]; //订单编号
		char ReserveTime[30]; //预定时间
		int State; 
		int age[10]; //年龄段
		int numberOfGroup; //出行人数 
		int price; //订单价格 
		int OrderIndex; //订单索引
		int UserIndex; //用户索引 
		int ScenicIndex[5]; //景点索引
		int NumberOfScenicIndex; //所存景点数量 
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
        //判断景点索引个数 
		fscanf(fp_input, "%d ", &NumberOfScenicIndex); 
		for(int i = 0;i < 5;i ++){
        	fscanf(fp_input, "%s ", &OrderList[NumberOfOrder].GoTime[i][0]);
		}
		
        // 将读取的数据保存到游客团结构体数组中
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
		
        // 更新管理员数量计数器
        NumberOfOrder ++;
    }

    // 关闭文件
    fclose(fp_input);

    printf(""YELLOW"@Test"NONE": 初始化库：从订单文件中加载了 "LIGHT_GREEN"%d"NONE" 条订单信息\n", NumberOfOrder);
}

void showOrderByAdmin(){
	for (int i = 0; i < NumberOfOrder; i++) {
        printf("\n第 "LIGHT_GREEN"%d"NONE" 个订单的信息如下：\n", i + 1);
        printf("订单编号: "LIGHT_GREEN"%s"NONE"\n", OrderList[i].ID);
        printf("订单所属游客团ID: "YELLOW"%s"NONE"\n",g_groups[OrderList[i].UserIndex].ID);
        //printf("预定时间: %s\n", OrderList[i].ReserveTime);
        printf("订单创建时间: %s\n", OrderList[i].ReserveTime);
		printf("订单状态: %d\n", OrderList[i].State);
		for(int t = 0;t < 10;t ++){
			printf("年龄段 %d0 - %d0 有 %d 人\n",t,t+1,OrderList[i].age[t]);
		}
		printf("订单人数: "LIGHT_GREEN"%d"NONE"\n", OrderList[i].numberOfGroup);
		printf("订单价格: "LIGHT_RED"%d"NONE"\n", OrderList[i].price);
		printf("订单索引: %d\n", OrderList[i].OrderIndex);
		printf("用户索引: %d\n", OrderList[i].UserIndex);
		for(int j = 0;j < 5;j ++){
			printf("第 "LIGHT_GREEN"%d"NONE" 个景点名称: "LIGHT_GREEN"%s"NONE"  "LIGHT_GREEN"%s"NONE"",j + 1,scenicList[OrderList[i].ScenicIndex[j]].ID,scenicList[OrderList[i].ScenicIndex[j]].Name);
			printf("\t预定出行时间: %s\n",OrderList[i].GoTime[j]);
		}
		printf("已预定的景点的数量: "LIGHT_GREEN"%d"NONE"\n",OrderList[i].NumberOfScenicIndex);
        printf("-----------------------------------------------------\n");
    }
    system("\t pause");
    system("cls");
}

void showOrderByUser(){
        printf("\n游客团用户 "YELLOW"%s"NONE" 的订单信息如下：\n",g_groups[UserIndex].ID);
        printf("订单编号: "LIGHT_GREEN"%s"NONE"\n", OrderList[g_groups[UserIndex].orderNumber].ID);
        printf("订单所属游客团ID: %s\n",g_groups[OrderList[g_groups[UserIndex].orderNumber].UserIndex].ID);
        printf("游客团密码: %s\n",g_groups[OrderList[g_groups[UserIndex].orderNumber].UserIndex].password);
        printf("游客团电话: %s\n",g_groups[OrderList[g_groups[UserIndex].orderNumber].UserIndex].contactNumber);
        printf("游客团邮箱: %s\n",g_groups[OrderList[g_groups[UserIndex].orderNumber].UserIndex].Email);
        printf("订单创建时间: "LIGHT_GREEN"%s"NONE"\n", OrderList[g_groups[UserIndex].orderNumber].ReserveTime);
        //printf("出行时间: %s\n", OrderList[g_groups[UserIndex].orderNumber].GoTime);
		printf("订单状态: %d\n", OrderList[g_groups[UserIndex].orderNumber].State);
		for(int t = 0;t < 10;t ++){
			printf("年龄段 %d0 - %d0 有 "LIGHT_GREEN"%d"NONE" 人\n",t,t+1,OrderList[g_groups[UserIndex].orderNumber].age[t]);
		}
		printf("订单人数: "LIGHT_GREEN"%d"NONE"\n", OrderList[g_groups[UserIndex].orderNumber].numberOfGroup);
		printf("订单价格: "LIGHT_RED"%d"NONE"\n", OrderList[g_groups[UserIndex].orderNumber].price);
		printf("订单索引: %d\n", OrderList[g_groups[UserIndex].orderNumber].OrderIndex);
		printf("用户索引: %d\n", OrderList[g_groups[UserIndex].orderNumber].UserIndex);
		for(int j = 0;j < 5;j ++){
			printf("第 "LIGHT_GREEN"%d"NONE" 个景点名称: "LIGHT_GREEN"%s"NONE"  "LIGHT_GREEN"%s"NONE"\n",j + 1, scenicList[OrderList[g_groups[UserIndex].orderNumber].ScenicIndex[j]].ID
												,scenicList[OrderList[g_groups[UserIndex].orderNumber].ScenicIndex[j]].Name);
			printf("预定出行时间: %s\n\n",OrderList[g_groups[UserIndex].orderNumber].GoTime[j]);
		}
		printf("已预定的景点的数量: "LIGHT_GREEN"%d"NONE"\n",OrderList[g_groups[UserIndex].orderNumber].NumberOfScenicIndex);
        printf("-----------------------------------------------------\n");
    
    system("\t pause");
}


void initOrder(){      //初始化订单 
	g_groups[UserIndex].orderNumber = NumberOfOrder; //订单的索引 
	OrderList[NumberOfOrder].UserIndex = UserIndex;
	char temp_Scenic[20];
	int flag = 0;
	int Index;
	printf("\n\t请输入你要预定的景点ID: ");
	scanf("%s",temp_Scenic);
	for(int i = 0;i < NumberOfScenic;i ++){
		if(strcmp(temp_Scenic,scenicList[i].ID) == 0){
			flag = 1;
			Index = i;
			break;
		}
	}
	if(flag == 0){
		printf("\t"LIGHT_RED"该景点ID不存在,请输入正确的景点ID"NONE"\n\t");
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
	printf("\t请输入您想上午出行还是下午出行([1]代表上午,[2]代表下午):");
	flag3 =MyInput(1,2); 
	printf("\t景点"LIGHT_GREEN"%s"NONE"上午的开放时间"YELLOW"%s"NONE"\n",scenicList[Index].Name,scenicList[Index].SeasonTimeRange[4]);
	printf("\t景点"LIGHT_GREEN"%s"NONE"下午的开放时间"YELLOW"%s"NONE"\n",scenicList[Index].Name,scenicList[Index].SeasonTimeRange[5]);
	printf("\t请输入你的出行时间:(格式为yyyy:mm:dd:hh):");
	scanf("%s",temp_GoTime);
	while(!isDateFormatValid(temp_GoTime) || !isDateTimeInRange(temp_GoTime)){
		printf("\t请输入正确的出行时间:(格式为yyyy:mm:dd:hh,当前只能预定2023:09:06-2023:09:15号之间的票):");
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
	const char* defaultTime = "2023:09:06";    //默认时间 
	int TimeDifference = calculateDayDifference(defaultTime,temp_subStr); // 
	strcat(temp_subStr,temp_GoTime);
	strcpy(temp_GoTime,temp_subStr);
	temp_GoTime[10] = '/';
	printf("\t您的出行时间被更改为: "LIGHT_GREEN"%s"NONE"\n",temp_GoTime);
	
	//生成订单
	
	//获取当前时间 
	time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    char timeString[20];
    strftime(timeString, sizeof(timeString), "%Y:%m:%d:%H:%M", localTime);
    strcpy(OrderList[NumberOfOrder].ReserveTime,timeString);
	
	char temp_store[50]; 
	strcpy(temp_store,g_groups[UserIndex].ID);
	strcat(temp_store,timeString);
	strcpy(OrderList[NumberOfOrder].ID,temp_store); //用来生成订单ID 
	
	OrderList[NumberOfOrder].State = 1; //把订单状态默认为1 
	for(int i = 0;i < 10;i ++){
		OrderList[NumberOfOrder].age[i] = g_groups[UserIndex].ageLevel[i];   //赋值年龄层次 
	}
	
	OrderList[NumberOfOrder].numberOfGroup = g_groups[UserIndex].numMembers;  //赋值订单人数 
	OrderList[NumberOfOrder].OrderIndex = NumberOfOrder;    //赋值自身的订单索引 

	OrderList[NumberOfOrder].ScenicIndex[0] = Index;   //赋值订单第一个景点的订单索引 
	strcpy(&OrderList[NumberOfOrder].GoTime[0][0],temp_GoTime); //拷贝第一个景点的出行时间 
	for(int i = 1;i < 5;i ++){
		OrderList[NumberOfOrder].ScenicIndex[i] = -1;  //-1 代表未指向任何一个景点 
	}
	for(int i = 1;i < 5;i ++){
		strcpy(OrderList[NumberOfOrder].GoTime[i],"null");
	}
	
	int StudentNumber = OrderList[NumberOfOrder].age[0] + OrderList[NumberOfOrder].age[1];
	int OlderNumber = OrderList[NumberOfOrder].age[6] + OrderList[NumberOfOrder].age[7]
						+ OrderList[NumberOfOrder].age[8] + OrderList[NumberOfOrder].age[9];
	
	int ExceptNumber = OrderList[NumberOfOrder].numberOfGroup - StudentNumber - OlderNumber;
	//判断为淡季还是旺季
	if(getMonth(temp_GoTime) == 0 || getMonth(temp_GoTime) == 3){
		//为淡季
		scenicList[Index].Profit += scenicList[Index].off_season_price * ExceptNumber
								 + StudentNumber * scenicList[Index].StudentAccount * scenicList[Index].off_season_price
								 + OlderNumber * scenicList[Index].SoldierAccount * scenicList[Index].off_season_price; //增加景点利润
		OrderList[NumberOfOrder].price += scenicList[Index].off_season_price * ExceptNumber
								 + StudentNumber * scenicList[Index].StudentAccount * scenicList[Index].off_season_price
								 + OlderNumber * scenicList[Index].SoldierAccount * scenicList[Index].off_season_price; //增加订单支出
	}else{
		//为旺季
		scenicList[Index].Profit += scenicList[Index].peak_season_price * ExceptNumber
								 + StudentNumber * scenicList[Index].StudentAccount * scenicList[Index].peak_season_price
								 + OlderNumber * scenicList[Index].SoldierAccount * scenicList[Index].peak_season_price;  //增加景点利润 
		OrderList[NumberOfOrder].price += scenicList[Index].peak_season_price * ExceptNumber
								 + StudentNumber * scenicList[Index].StudentAccount * scenicList[Index].peak_season_price
								 + OlderNumber * scenicList[Index].SoldierAccount * scenicList[Index].peak_season_price; //增加订单支出  
	}
	
	if(flag3 == 1){
		if(scenicList[Index].Tickets_M[TimeDifference] - OrderList[NumberOfOrder].numberOfGroup >= 0){
			scenicList[Index].Tickets_M[TimeDifference] -= OrderList[NumberOfOrder].numberOfGroup;
		}else{
			printf("\t"LIGHT_RED"该景点该时段的预约人数已满,购票失败"NONE"\n");
			return; 
		}
	}else if(flag3 == 2){
		if(scenicList[Index].Tickets_A[TimeDifference] - OrderList[NumberOfOrder].numberOfGroup >= 0){
			scenicList[Index].Tickets_A[TimeDifference] -= OrderList[NumberOfOrder].numberOfGroup;
		}else{
			printf("\t"LIGHT_RED"该景点该时段的预约人数已满,购票失败"NONE"\n");
			return; 
		}
	}
	
	
	
	OrderList[NumberOfOrder].NumberOfScenicIndex ++; //初始化景点数量为1 
	NumberOfOrder ++; //订单总数 + 1 
	dumpScenic(); //修改了景点的利润,故要保存下景点 
	dumpOrder();  //修改了订单,故要保存下订单 
	dumpUser();   //修改了用户的订单索引，故要保存下用户 
	printf("\t");
	getchar(); 
	system("pause");
	system("cls");
	userSen(); 
}


void addOrder(){      //后续添加订单 
	//g_groups[UserIndex].orderNumber = NumberOfOrder;
	//OrderList[NumberOfOrder].UserIndex = UserIndex;
	char temp_Scenic[20];
	int flag = 0;
	int Index;
	printf("\n\t请输入你要预定的景点ID: ");
	scanf("%s",temp_Scenic);
	for(int i = 0;i < NumberOfScenic;i ++){
		if(strcmp(temp_Scenic,scenicList[i].ID) == 0){
			flag = 1;
			Index = i;
			break;
		}
	}
	if(flag == 0){
		printf("\t"LIGHT_RED"该景点ID不存在,请输入正确的景点ID"NONE"\n\t");
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
	printf("\t景点"LIGHT_GREEN"%s"NONE"上午的开放时间"YELLOW"%s"NONE"\n",scenicList[Index].Name,scenicList[Index].SeasonTimeRange[4]);
	printf("\t景点"LIGHT_GREEN"%s"NONE"下午的开放时间"YELLOW"%s"NONE"\n",scenicList[Index].Name,scenicList[Index].SeasonTimeRange[5]);
	printf("\t请输入您想上午出行还是下午出行([1]代表上午,[2]代表下午):");
	flag3 =MyInput(1,2); 
	printf("\t请输入你的出行时间:(格式为yyyy:mm:dd:hh):");
	scanf("%s",temp_GoTime);
	while(!isDateFormatValid(temp_GoTime) || !isDateTimeInRange(temp_GoTime)){
		printf("\t请输入正确的出行时间:(格式为yyyy:mm:dd:hh,当前只能预定2023:09:06-2023:09:15号之间的票):");
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
	const char* defaultTime = "2023:09:06";    //默认时间 
	int TimeDifference = calculateDayDifference(defaultTime,temp_subStr); 
	strcat(temp_subStr,temp_GoTime);
	strcpy(temp_GoTime,temp_subStr);
	temp_GoTime[10] = '/';
	printf("\t您的出行时间被更改为: "LIGHT_GREEN"%s"NONE "\n",temp_GoTime);

	char TEMP_GOTIME[20];
	strncpy(TEMP_GOTIME,temp_GoTime,6);
	TEMP_GOTIME[7] = '\0';
	int currentOrderIndex = g_groups[UserIndex].orderNumber;
	OrderList[currentOrderIndex].ScenicIndex[OrderList[currentOrderIndex].NumberOfScenicIndex] = Index;  //添加景点索引
	strcpy(&OrderList[currentOrderIndex].GoTime[OrderList[currentOrderIndex].NumberOfScenicIndex][0],temp_GoTime); //1
	
	 
	int OrderIndex = g_groups[UserIndex].orderNumber;  //当前订单索引 
	int StudentNumber = OrderList[OrderIndex].age[0] + OrderList[OrderIndex].age[1];
	int OlderNumber = OrderList[OrderIndex].age[6] + OrderList[OrderIndex].age[7] 
						+ OrderList[OrderIndex].age[8] + OrderList[OrderIndex].age[9];
	
	int ExceptNumber = OrderList[OrderIndex].numberOfGroup - StudentNumber - OlderNumber;
	
	
	
	//判断为淡季还是旺季
	if(getMonth(TEMP_GOTIME) == 0 || getMonth(TEMP_GOTIME) == 6){
		//为淡季
		scenicList[Index].Profit += scenicList[Index].off_season_price * ExceptNumber
								 +  scenicList[Index].off_season_price * StudentNumber * scenicList[Index].StudentAccount
								 +  scenicList[Index].off_season_price * OlderNumber * scenicList[Index].SoldierAccount; //增加景点利润
		OrderList[currentOrderIndex].price += scenicList[Index].off_season_price * ExceptNumber
								 +  scenicList[Index].off_season_price * StudentNumber * scenicList[Index].StudentAccount
								 +  scenicList[Index].off_season_price * OlderNumber * scenicList[Index].SoldierAccount; //增加订单支出
	}else{
		//为旺季
		scenicList[Index].Profit += scenicList[Index].peak_season_price * ExceptNumber
								 +  scenicList[Index].peak_season_price * StudentNumber * scenicList[Index].StudentAccount
								 +  scenicList[Index].peak_season_price * OlderNumber * scenicList[Index].SoldierAccount; //增加景点利润 
		OrderList[currentOrderIndex].price += scenicList[Index].peak_season_price * ExceptNumber
								 +  scenicList[Index].peak_season_price * StudentNumber * scenicList[Index].StudentAccount
								 +  scenicList[Index].peak_season_price * OlderNumber * scenicList[Index].SoldierAccount;//增加订单支出  
	}
	
	if(flag3 == 1){
		if(scenicList[Index].Tickets_M[TimeDifference] - OrderList[currentOrderIndex].numberOfGroup >= 0){
			scenicList[Index].Tickets_M[TimeDifference] -= OrderList[currentOrderIndex].numberOfGroup;
		}else{
			printf("\t"LIGHT_RED"该景点该时段的预约人数已满,购票失败"NONE"\n");
			return; 
		}
	}else if(flag3 == 2){
		if(scenicList[Index].Tickets_A[TimeDifference] - OrderList[currentOrderIndex].numberOfGroup >= 0){
			scenicList[Index].Tickets_A[TimeDifference] -= OrderList[currentOrderIndex].numberOfGroup;
		}else{
			printf("\t"LIGHT_RED"该景点该时段的预约人数已满,购票失败"NONE"\n");
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
	// 遍历数组，并依次写入
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

    // 关闭文件
    fclose(fp_output);
}


void DeleteOrder(){
	//获取当前时间 
	time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    char timeString[20];
    strftime(timeString, sizeof(timeString), "%Y:%m:%d:%H:%M", localTime);
	int Difference = calculateDayDifference(timeString,OrderList[g_groups[UserIndex].orderNumber].ReserveTime);
	if(Difference >= 1){
		printf("\t订单预定已超过一天,无法取消\n");
		printf("\t");
		system("pause");
		userSen();
		return;
	}else{
		printf("\t是否确定取消订单?  [1]确定 [2]取消");
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
		printf("\t取消预订成功!");
		dumpOrder();
		dumpUser();
		dumpScenic(); 
		printf("\t");
		system("pause");
		system("cls");
		userSen();
	}else if(choice == 2){
		printf("\t"LIGHT_GREEN"成功取消修改!"NONE"");
		Sleep(3000);
		system("cls");
		userSen();
		}	
	}
}
 

	
