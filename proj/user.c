#include "user.h"
void loadUser() {
    // 打开文件
    FILE* fp_input = fopen("userData.txt", "r");

    // while 死循环读取文件内容
    while (1) {
        // 如果达到文件结尾就跳出循环
        if (feof(fp_input)) {
            break;
        }

        // 依次扫描六个字段
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

        // 将读取的数据保存到游客团结构体数组中
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


        // 更新游客团数量计数器
        g_number_of_groups += 1;
    }

    // 关闭文件
    fclose(fp_input);

    printf(""YELLOW"@Test"NONE"：从游客团文件中加载了 "LIGHT_GREEN"%d"NONE" 条游客团信息\n", g_number_of_groups);
}

void dumpUser() {
    // 打开文件
    FILE* fp_output = fopen("userData.txt", "w");

    // 遍历数组，并依次写入
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

    // 关闭文件
    fclose(fp_output);
}


void addUser() {
    // 添加游客团
    while (1) {
        printf("\t添加游客团信息：\n");

        printf("\t请输入ID: ");
        char ID[MAX_ID_LENGTH];
        scanf("%s", ID);
		ValidateID(ID);
        int found = 0;
        // 在数组中，从左往右，依次查找此ID是否存在
        for (int i = 0; i < g_number_of_groups; i++) {
            // 存在
            if (strcmp(g_groups[i].ID, ID) == 0) {
                // 标记
                found = 1;
                // 结束循环
                break;
            }
        }

        // 如果存在重复的ID，给出提示，并 continue 进入下一次 while 循环。
        if (found) {
            printf("ID重复，无法添加\n");
            continue;
        }
	
        printf("请输入密码: ");
        char password[MAX_PASSWORD_LENGTH];
        scanf("%s", password);
		ValidatePassWord(password);
		
		printf("请输入邮箱: ");
		char Email[20];
		scanf("%s",Email);
		ValidateEmail(Email);
		
        printf("请输入人数: ");
        int numMembers;
        scanf("%d", &numMembers);
		while(numMembers <= 0 || numMembers >= 100){
    		printf("\t请输入正确的人数,人数限制为1-100: ");
			scanf("%d",&numMembers); 
		}
		int ageLevel[10];
		int temp_numMembers;
        for(int i = 0;i < 10;i ++){
        	printf("请输入第 %d 年龄段的人数: ",i);
        	scanf("%d",&ageLevel[i]);
        	//validate()
        	temp_numMembers += ageLevel[i]; 
		}
		if(numMembers != temp_numMembers){
			printf("人数不符,请重新输入\n");
			system("cls");
			addUser();
		}
		
        printf("请输入联系方式: ");
        char contactNumber[MAX_CONTACT_LENGTH];
        scanf("%s", contactNumber);
		ValidatePhoneNumber(contactNumber);
        // 将输入的数据保存到游客团结构体数组中
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

        // 更新游客团数量计数器
        g_number_of_groups+=1;

        printf("保存成功。是否继续添加(Y/N): ");
        char yes_no[2];
        scanf("%s", yes_no);
        // 没有输入Y或者y，就跳出循环
        if (strcasecmp(yes_no, "Y") != 0) {
            break;
        }
    } // end of while loop
}
//		printf("订单人数: %d\n", OrderList[g_groups[UserIndex].orderNumber].numberOfGroup);
//		printf("订单价格: %d\n", OrderList[g_groups[UserIndex].orderNumber].price);
void showUser() {
    for (int i = 0; i < g_number_of_groups; i++) {
        printf("第 "YELLOW"%d"NONE" 个游客团的信息如下：\n", i + 1);
        printf("ID: "LIGHT_GREEN"%s"NONE"\n", g_groups[i].ID);
        printf("密码: %s\n", g_groups[i].password);
        printf("邮箱: %s\n",g_groups[i].Email);
        printf("人数: %d\n", g_groups[i].numMembers);
        printf("游客团需支付的总费用: "LIGHT_RED"%d"NONE"\n", OrderList[g_groups[i].orderNumber].price);
        for(int j = 0;j < 5;j ++){
			printf("第 "LIGHT_GREEN"%d"NONE" 个景点名称: "YELLOW"%s"NONE"  %s\n",j + 1, scenicList[OrderList[g_groups[i].orderNumber].ScenicIndex[j]].ID
												,scenicList[OrderList[g_groups[i].orderNumber].ScenicIndex[j]].Name);
			printf("预定出行时间: %s\n\n",OrderList[g_groups[i].orderNumber].GoTime[j]);
		}
        for(int t = 0;t < 10;t ++){
        	printf("第 %d 年龄层次的人数是: "LIGHT_RED"%d"NONE"\n",t,g_groups[i].ageLevel[t]);
		}
        printf("联系方式: %s\n", g_groups[i].contactNumber);
        printf("游客团编号: %d\n", g_groups[i].selfIndex);
        printf("订单编号: %d\n", g_groups[i].orderNumber);
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
    // 添加游客团
        printf("\t欢迎来到用户注册界面：\n");
		printf(""LIGHT_GREEN"\tTIPS:用户名限制为6-10,密码限制为6-16位,密码必须为数字和字母的组合,输入不能包含空格\n"NONE"");
        printf("\t请输入你想注册的游客团ID: ");
        char ID[MAX_ID_LENGTH];
        scanf("%s",ID);
		ValidateID(ID); 
        int found = 0;
        // 在数组中，从左往右，依次查找此ID是否存在
        for (int i = 0; i < g_number_of_groups; i++) {
            // 存在
            if (strcmp(g_groups[i].ID, ID) == 0) {
                // 标记
                found = 1;
                // 结束循环
                break;
            }
        }
        while (found) {
            printf("\tID重复，请重试\n");
            Sleep(3000);
            userRegister(); 
        }

        printf("\t请输入密码: ");
        char password[MAX_PASSWORD_LENGTH];
        char confirmPassword[MAX_PASSWORD_LENGTH];
        scanf("%s",password);
        CLEANBUFF();  //清理缓存 
        ValidatePassWord(password);
		printf("\t请确认你的密码: ");
    	scanf("%s",confirmPassword);
    	CLEANBUFF();
   		while(strcmp(password, confirmPassword) != 0) // 判断两个字符串是否相等
    	{
       		printf("\t密码不正确，请重新输入你的密码: ");
       	 	scanf("%s",password);
       	 	ValidatePassWord(password);
        	printf("\t请确认你的密码: ");
        	scanf("%s",confirmPassword);
        	CLEANBUFF();
   		}
   		printf("\t请输入你的邮箱: ");
   		char Email[20];
   		scanf("%s",Email);
   		ValidateEmail(Email);
        printf("\t请输入人数(人数限制为1-100): ");
        int numMembers = MyInput(1,100);
        printf("\t请输入年龄层次:\n ");
        int ageLevel[10];
        int temp_count_ageLevel = 0;
        for(int i = 0;i < 10;i ++){
        	printf("\t第 %d0 到 %d0 年龄层次的人数: ",i,i+1);
        	scanf("%d",&ageLevel[i]);
        	CLEANBUFF();
        	while(ageLevel[i] < 0){
        		printf("\t请输入有效的人数: ");
        		scanf("%d",&ageLevel[i]);
        		CLEANBUFF();
			}
        	temp_count_ageLevel += ageLevel[i]; 
        	if(temp_count_ageLevel > numMembers){
        		printf("\n\t"LIGHT_RED"您前后输入的人数不匹配,注册失败,请重新输入"NONE"\n");
        		printf("\t");
				system("pause");
				userRegister(); 
			}
		}
		if(temp_count_ageLevel != numMembers){
			printf("\n\t"LIGHT_RED"您前后输入的人数不匹配,注册失败,请重新输入"NONE"\n");
			printf("\t");
			system("pause");
			userRegister();
		}
		 
        printf("\t请输入联系方式: ");
        char contactNumber[MAX_CONTACT_LENGTH];
        scanf("%s", contactNumber);
        CLEANBUFF();
        ValidatePhoneNumber(contactNumber);
		
        // 将输入的数据保存到游客团结构体数组中
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
		
		dumpUser(); //保存 
		
   	 	printf("\n\t"LIGHT_GREEN"注册成功！"NONE"等待5秒后跳转到用户菜单界面......");
    	Sleep(5000);
    	system("cls");
    	userMenuSen();
        
     // end of while loop
}


void userLogin(){ 
	printf("\t欢迎来到用户登录界面：\n");

        printf("\t请输入您的游客团ID: ");
        char ID[MAX_ID_LENGTH];
        char password[MAX_PASSWORD_LENGTH];
        scanf("%s", ID);

        int found = 0;
        int temp_Index;
        // 在数组中，从左往右，依次查找此ID是否存在
        for (int i = 0; i < g_number_of_groups; i++) {
            // 存在
            if (strcmp(g_groups[i].ID, ID) == 0) {
                // 标记
                found = 1;
                temp_Index = i;
                // 结束循环
                break;
            }
        }

        if (!found) {
            printf("\t该游客团ID不存在，请先注册再登录");
            Sleep(3000);
    		system("cls"); 
    		getchar();
            userMenuSen(); 
        }
        printf("\t请输入密码: ");
        scanf("%s", password);
        int found2 = 0;
        if(strcmp(g_groups[temp_Index].password,password) == 0){
        	found2 = 1;
		} 
		if(found2){
			getchar();
            printf("\n\t"LIGHT_GREEN"登录成功！"NONE"等待5秒后跳转到用户功能界面......");
            Sleep(2000);
            system("cls");
            UserIndex =  temp_Index; 
            userSen();
		}else{
			getchar();
            printf("\n\t"LIGHT_RED"密码错误，"NONE"等待5秒后跳转到用户菜单界面......");
            Sleep(5000);
            system("cls");
            userMenuSen();
		} 
}


void ChangeInfoOfUserByUser(){
	char T[20];
	printf("\n\t请输入你想修改的信息(电话 密码 邮箱): "); 
	scanf("%s",T);
	char changeTemp[30];
	if(strcmp(T,"电话") == 0){
		printf("\t请输入你要修改的电话号码: "); 
		scanf("%s",changeTemp);
		ValidatePhoneNumber(changeTemp);
		strcpy(g_groups[UserIndex].contactNumber,changeTemp); 
	}else if(strcmp(T,"密码") == 0){
		printf("\t请输入你要修改的密码: ");
		scanf("%s",changeTemp);
		ValidatePassWord(changeTemp);
		strcpy(g_groups[UserIndex].password,changeTemp); 
	}else if(strcmp(T,"邮箱") == 0){
		printf("\t请输入你要修改的邮箱: ");
		scanf("%s",changeTemp);
		ValidateEmail(changeTemp);
		strcpy(g_groups[UserIndex].Email,changeTemp); 
	}else{
		printf("\t您的输入有误,请重新输入");
		Sleep(2000);
		system("cls");
		ChangeInfoOfUserByUser(); 
	}
	printf("\t是否确定修改?  [1]确定 [2]取消 [3]修改:");
    int choice = MyInput(1,3);
    if(choice == 1){
    	dumpUser();
		printf("\t"LIGHT_GREEN"修改成功!"NONE"");
		Sleep(3000);
		system("cls");
		userSen();
	}else if(choice == 2){
		printf("\t"LIGHT_GREEN"成功取消修改!"NONE"");
		Sleep(3000);
		system("cls");
		userSen();
	}else if(choice == 3){
		ChangeInfoOfUserByUser();
	} 
	
	
}


void ChangeInfoOfUserByAdmin(){
	char Name[30];
	printf("\n\t请输入你想修改的用户的名称:");
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
		printf("找不到用户ID,请重新输入\n");
		Sleep(2000);
		system("cls");
		ChangeInfoOfUserByAdmin();
	}
	
	 
	char T[20];
	printf("\n\t请输入你想修改的信息("YELLOW"电话"NONE" "YELLOW"密码"NONE" "YELLOW"邮箱"NONE"): "); 
	scanf("%s",T);
	char changeTemp[30];
	if(strcmp(T,"电话") == 0){
		printf("\t请输入你要修改的电话号码: "); 
		scanf("%s",changeTemp);
		ValidatePhoneNumber(changeTemp);
		strcpy(g_groups[Index].contactNumber,changeTemp); 
	}else if(strcmp(T,"密码") == 0){
		printf("\t请输入你要修改的密码: ");
		scanf("%s",changeTemp);
		ValidatePassWord(changeTemp);
		strcpy(g_groups[Index].password,changeTemp); 
	}else if(strcmp(T,"邮箱") == 0){
		printf("\t请输入你要修改的邮箱: ");
		scanf("%s",changeTemp);
		ValidateEmail(changeTemp);
		strcpy(g_groups[Index].Email,changeTemp); 
	}else{
		printf("\t您的输入有误,请重新输入");
		ChangeInfoOfUserByAdmin();
		Sleep(3000);
		system("cls"); 
	}
	
	printf("\t是否确定修改?  [1]确定 [2]取消 [3]修改:");
    int choice = MyInput(1,3);
    if(choice == 1){
    	dumpUser();
		printf("\t"LIGHT_GREEN"修改成功!"NONE"");
		Sleep(3000);
		system("cls");
	}else if(choice == 2){
		printf("\t"LIGHT_GREEN"成功取消修改!"NONE"");
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
	printf("\n游客团用户 "YELLOW"%s"NONE" 的信息如下：\n",g_groups[UserIndex].ID);
    printf("订单编号: "LIGHT_GREEN"%s"NONE"\n", OrderList[g_groups[UserIndex].orderNumber].ID);
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
	
	system("pause");
	system("cls");
}
