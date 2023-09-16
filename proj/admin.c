#include "admin.h"
#include "user.h"
void loadAdmin() {
    // 打开文件
    FILE* fp_input = fopen("adminData.txt", "r");

    // while 死循环读取文件内容
    while (1) {
        // 如果达到文件结尾就跳出循环
        if (feof(fp_input)) {
            break;
        }

        // 依次扫描六个字段
        char ID[20];
        char password[20];
        char PhoneNumber[20];
        char Email[20];
        fscanf(fp_input, "%s ", ID);
        fscanf(fp_input, "%s ", password);
        fscanf(fp_input, "%s ", PhoneNumber);
        fscanf(fp_input, "%s\n", Email);

        // 将读取的数据保存到游客团结构体数组中
        strcpy(AdminList[NumberOfAdmin].ID,ID);
        strcpy(AdminList[NumberOfAdmin].password,password);
        strcpy(AdminList[NumberOfAdmin].contactNumber,PhoneNumber);
        strcpy(AdminList[NumberOfAdmin].Email,Email);

        // 更新管理员数量计数器
        NumberOfAdmin ++;
    }

    // 关闭文件
    fclose(fp_input);

    printf(""YELLOW"@Test"NONE"：从管理员文件中加载了 "LIGHT_GREEN"%d"NONE" 条管理员信息\n", NumberOfAdmin);
}




void dumpAdmin() {
    // 打开文件
    FILE* fp_output = fopen("adminData.txt", "w");

    // 遍历数组，并依次写入
    for (int i = 0; i < NumberOfAdmin; i++) {
        fprintf(fp_output, "%s ", AdminList[i].ID);
        fprintf(fp_output, "%s ", AdminList[i].password);
        fprintf(fp_output, "%s ", AdminList[i].contactNumber);
        fprintf(fp_output, "%s\n", AdminList[i].Email);
    }

    // 关闭文件
    fclose(fp_output);
}


void addAdmin(){
	// 添加管理员 
    while (1) {
    	printf(""LIGHT_GREEN"\n\tTIPS:管理员名限制为6-10,密码限制为6-16位,密码必须为数字和字母的组合,输入不能包含空格\n"NONE"");
        printf("\t添加管理员信息：\n");

        printf("\t请输入要添加的管理员的ID: ");
        char ID[MAX_ID_LENGTH];
        scanf("%s", ID);
		ValidateID(ID);
        int found = 0;
        // 在数组中，从左往右，依次查找此ID是否存在
        for (int i = 0; i < NumberOfAdmin; i++) {
            // 存在
            if (strcmp(AdminList[i].ID, ID) == 0) {
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
        printf("\t请输入密码: ");
        char password[MAX_PASSWORD_LENGTH];
        scanf("%s", password);
		ValidatePassWord(password);
		
        printf("\t请输入电话号码: ");
        char contactNumber[MAX_CONTACT_LENGTH];
        scanf("%s", contactNumber);
        ValidatePhoneNumber(contactNumber);
        printf("\t请输入邮箱: ");
        char Email[MAX_CONTACT_LENGTH];
        scanf("%s", Email);
		ValidateEmail(Email);
        // 将输入的数据保存到管理员结构体数组中
        strcpy(AdminList[NumberOfAdmin].ID,ID);
        strcpy(AdminList[NumberOfAdmin].password,password);
        strcpy(AdminList[NumberOfAdmin].contactNumber,contactNumber);
        strcpy(AdminList[NumberOfAdmin].Email,Email);
	
		printf("\t是否确定添加管理员?  [1]确定 [2]取消");
    	int choice = MyInput(1,3);
    	if(choice == 1){
    		// 更新管理员数量计数器
        	NumberOfAdmin++;
			dumpAdmin(); 
        	printf("\t保存成功。是否继续添加(Y/N): ");
        	char yes_no[2];
        	scanf("%s", yes_no);
        	getchar();
        	// 没有输入Y或者y，就跳出循环
        	if (strcasecmp(yes_no, "Y") != 0) {
            	break;
        	}
        	system("cls");
		}else if(choice == 2){
			printf("\t"LIGHT_GREEN"成功取消修改!"NONE"");
			Sleep(3000);
			break; 
		}
        
    } 
    system("cls");
    SuperadminGuiSen();
    
}

void showAdmin(){
	for (int i = 0; i < NumberOfAdmin; i++) {
        printf("\n第 "LIGHT_RED"%d"NONE" 个管理员的信息如下：\n", i + 1);
        printf("ID: "LIGHT_GREEN"%s"NONE"\n", AdminList[i].ID);
        printf("密码: %s\n", AdminList[i].password);
        printf("联系方式: %s\n", AdminList[i].contactNumber);
		printf("邮箱: %s\n", AdminList[i].Email);
        printf("-----------------------------------------------------\n");
    }
    system("pause");
    system("cls");
    SuperadminGuiSen();
}

void AdminLogin(){
	printf("\t欢迎来到管理员登录界面：\n");

        printf("\t请输入您的ID: ");
        char ID[MAX_ID_LENGTH];
        char password[MAX_PASSWORD_LENGTH];
        scanf("%s", ID);
		int temp_Index_T = 0; 
        int found = 0;
        // 在数组中，从左往右，依次查找此ID是否存在
        for (int i = 0; i < NumberOfAdmin; i++) {
            // 存在
            if (strcmp(AdminList[i].ID, ID) == 0) {
                // 标记
                found = 1;
                temp_Index_T = i; 
                // 结束循环
                break;
            }
        }

        if (!found) {
			getchar();
            printf("\t该管理员ID不存在，请联系开发者获取管理员权限\n");
            Sleep(3000);
            system("cls");
            adminMenuSen(); 
        }
        printf("\t请输入密码: ");
        scanf("%s", password);
        int found2 = 0;
        if(strcmp(AdminList[temp_Index_T].password,password) == 0){
        	found2 = 1;
		}
		if(found2){
			getchar();
            printf("\n\t"LIGHT_GREEN"登录成功！"NONE"等待5秒后跳转到管理员功能界面......");
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
            printf("\n\t"LIGHT_RED"密码错误."NONE"等待5秒后跳转到管理员登录界面......");
            Sleep(5000);
            system("cls");
            adminMenuSen(); 
		} 
}



void ChangeInfoOfAdminByAdmin(){
	char T[20];
	printf("\n\t请输入你想修改的信息:("YELLOW"电话"NONE","YELLOW"密码"NONE","YELLOW"邮箱"NONE"): "); 
	scanf("%s",T);
	char changeTemp[30];
	if(strcmp(T,"电话") == 0){
		printf("\t请输入你要修改的电话号码: "); 
		scanf("%s",changeTemp);
		ValidatePhoneNumber(changeTemp);
		strcpy(AdminList[AdminIndex].contactNumber,changeTemp); 
	}else if(strcmp(T,"密码") == 0){
		printf("\t请输入你要修改的密码: ");
		scanf("%s",changeTemp);
		ValidatePassWord(changeTemp);
		strcpy(AdminList[AdminIndex].password,changeTemp); 
	}else if(strcmp(T,"邮箱") == 0){
		printf("\t请输入你要修改的邮箱: ");
		scanf("%s",changeTemp);
		ValidateEmail(changeTemp);
		strcpy(AdminList[AdminIndex].Email,changeTemp); 
	}else{
		printf("\t您的输入有误,请重新输入");
		Sleep(2000);;
		ChangeInfoOfAdminByAdmin();
	}
	

	printf("\t是否确定修改?  [1]确定 [2]取消 [3]修改:");
    int choice = MyInput(1,3);
    if(choice == 1){
    	dumpAdmin();
		printf("\t"GREEN"修改成功!"NONE"");
		Sleep(3000);
		system("cls");
	}else if(choice == 2){
		printf("\t"LIGHT_GREEN"成功取消修改!"NONE"");
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
	printf("\n\t请输入你想修改的管理员的名称:");
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
		printf("\t找不到用户ID,请重新输入\n");
		Sleep(2000);
		ChangeInfoOfAdmin();
	}
	
	 
	char T[20];
	printf("\n\t请输入你想修改的信息("YELLOW"电话"NONE" "YELLOW"密码"NONE" "YELLOW"邮箱"NONE"): "); 
	scanf("%s",T);
	char changeTemp[30];
	if(strcmp(T,"电话") == 0){
		printf("\t请输入你要修改的电话号码: "); 
		scanf("%s",changeTemp);
		ValidatePhoneNumber(changeTemp);
		strcpy(AdminList[Index].contactNumber,changeTemp); 
	}else if(strcmp(T,"密码") == 0){
		printf("\t请输入你要修改的密码: ");
		scanf("%s",changeTemp);
		ValidatePassWord(changeTemp);
		strcpy(AdminList[Index].password,changeTemp); 
	}else if(strcmp(T,"邮箱") == 0){
		printf("\t请输入你要修改的邮箱: ");
		scanf("%s",changeTemp);
		ValidateEmail(changeTemp);
		strcpy(AdminList[Index].Email,changeTemp); 
	}else{
		printf("\t您的输入有误,请重新输入");
		ChangeInfoOfAdmin();
		Sleep(3000);
		system("cls"); 
	}
	
	printf("\t是否确定修改?  [1]确定 [2]取消 [3]修改:");
    int choice = MyInput(1,3);
    if(choice == 1){
    	dumpAdmin();
		printf("\t"LIGHT_GREEN"修改成功!"NONE"");
		Sleep(3000);
		system("cls");
	}else if(choice == 2){
		printf("\t"LIGHT_GREEN"成功取消修改!"NONE"");
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
