#include "gui.h"

void menuSen(){
	int choice = menu();  //进入主菜单 
	printf("\n\t----> 		程序在进行		<----|\n");
	switch(choice){
		case 1:
			printf("\n\t程序将于2秒后跳转到管理员菜单界面......");
			Sleep(2000);
			system("cls");
			adminMenuSen();  //进入管理员驻点页面 
			break;
		case 2:
			printf("\n\t程序将于2秒后跳转到游客团菜单界面......");
			Sleep(2000);
			system("cls");
			userMenuSen();
			break;
		case 3:
			printf("\t程序结束，谢谢使用！\n");
		default:
			break; 
			
	}
	return;
}


int menu(){         
	int choice;
	printf ( "\n" );
	printf ( "\n" );
    
    printf("\t\t\t _       __     __  \n");
    printf("\t\t\t| |     / /__  / /________  ____ ___  ___  \n");
    printf("\t\t\t| | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\ \n");
    printf("\t\t\t| |/ |/ /  __/ / /__/ /_/ / / / / / /  __/ \n");
    printf("\t\t\t|__/|__/\\___/_/\\___/\\____/_/ /_/ /_/\\___/  \n");
    
	printf ( "            	    ***************欢迎来到"YELLOW"团体游订票订购系统"NONE"*************\n" );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       请选择输入你要操作的选择                    <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[1]"NONE": 管理员                                                       <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[2]"NONE": 游客团                                                       <----|\n" );
    printf ( "	|----> "LIGHT_GREEN"[3]"NONE": 退出程序                                                     <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t请输入你想进行的操作：");
	choice = MyInput(1, 3);
	return choice;
	
}


void adminMenuSen(){     //管理员登录菜单响应 
	int choice = adminMenu();
	printf("\n\t----> 		程序在进行		<----|\n");	
	switch (choice)
	{
		case 1:
			AdminLogin();  //验证管理员登录 
			break;
		case 2:
			printf("\n\t将于2秒后跳转到初始界面......");
            Sleep(2000);
            system("cls");
            menuSen();
            break;	
		case 3:
			printf("\n\t程序结束，感谢您的使用谢谢！\n");	
			break;				
		default:
			break;
	}
	return ;
}

int adminMenu() // 管理员登录菜单
{
	int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf("\t\t\t\t    ___       __          _     \n");
    printf("\t\t\t\t   /   | ____/ /___ ___  (_)___ \n");
    printf("\t\t\t\t  / /| |/ __  / __ `__ \\/ / __ \\\n");
    printf("\t\t\t\t / ___ / /_/ / / / / / / / / / /\n");
    printf("\t\t\t\t/_/  |_\\__,_/_/ /_/ /_/_/_/ /_/ \n");
	printf ( "            	    ***************欢迎来到"YELLOW"管理员"NONE"的登录界面*************\n" );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       请选择输入你要操作的选择                    <----|\n" );	
	printf ( "	|----> "LIGHT_GREEN"[1]"NONE": 管理员登录                                                   <----|\n" );	
    printf ( "	|----> "LIGHT_GREEN"[2]"NONE"：返回上一级                                                   <----|\n" );
    printf ( "	|----> "LIGHT_GREEN"[3]"NONE"：退出程序                                                     <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t请输入你想进行的操作：");
	choice = MyInput(1, 3);
	return choice;
}


void adminGuiSen()  //管理员操作界面响应 
{
    int choice = adminGui();

	// 先给新用户注册
    switch (choice)
    {
        case 1:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到订单管理页面......");
			Sleep(3000);
            showOrderByAdmin();
            system("cls");
            adminGuiSen();
            break;
        case 2:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到统计用户订单信息页面......");
			Sleep(3000);
            OrderStatistics(); //统计用户订单情况 
            break;
        case 3:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到景点信息管理页面.....\n");
			Sleep(3000);
            printf("\t请输入要查询还是删除景点\n"); 
            printf("\t"LIGHT_GREEN"[1]"NONE" 查询景点\n"); 
            printf("\t"LIGHT_GREEN"[2]"NONE" 添加景点\n\t");
			int input = MyInput(1,2);
			if(input == 1){
				showScenicByAdmin();
				adminGuiSen();
			}else if(input == 2){
				addScenic();
				adminGuiSen(); 
			}
			 
            break;
        case 4:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到用户个人信息管理页面......");
			Sleep(3000);
        	ChangeInfoOfUserByAdmin();
			break;
        case 5:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到查看现有用户......");
			Sleep(3000);
			system("cls");
			showUser(); 
        case 6:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到初始界面......");
			Sleep(3000);
			system("cls");
			menuSen();
        case 7:
        	printf("\n\t----> 		程序在进行		<----|\n");
        	printf("\t将于3秒后跳转到修改管理员信息......");
			Sleep(3000);
			ChangeInfoOfAdminByAdmin();
            break;
        case 8:
			printf("\n\t程序即将退出......");
			Sleep(3000);
            exit(0);
        default:
            break;
    }
	return ;
}


int adminGui()  //管理员操作菜单 
{
    int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf("\t\t\t\t    ___       __          _     \n");
    printf("\t\t\t\t   /   | ____/ /___ ___  (_)___ \n");
    printf("\t\t\t\t  / /| |/ __  / __ `__ \\/ / __ \\\n");
    printf("\t\t\t\t / ___ / /_/ / / / / / / / / / /\n");
    printf("\t\t\t\t/_/  |_\\__,_/_/ /_/ /_/_/_/ /_/ \n");
	printf ( "            	   ***************欢迎管理员"YELLOW"%s"NONE"来到管理员操作界面*************\n",AdminList[AdminIndex].ID );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       请输入1 ~ 10继续操作                        <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[1]"NONE":订单管理                                                      <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[2]"NONE":统计用户订单信息                                              <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[3]"NONE":景点管理                                                      <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[4]"NONE":用户信息管理                                                  <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[5]"NONE":查看现有用户                                                  <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[6]"NONE":返回初始界面                                                  <----|\n" );
    printf ( "	|----> "LIGHT_GREEN"[7]"NONE":修改个人管理员信息                                            <----|\n" );
    printf ( "	|----> "LIGHT_GREEN"[8]"NONE":退出程序                                                     <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t请输入你想进行的操作：");
	choice = MyInput(1, 8);
	return choice;
}

int SuperadminGui()  //管理员操作菜单 
{
    int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf("\t\t\t\t    ___       __          _     \n");
    printf("\t\t\t\t   /   | ____/ /___ ___  (_)___ \n");
    printf("\t\t\t\t  / /| |/ __  / __ `__ \\/ / __ \\\n");
    printf("\t\t\t\t / ___ / /_/ / / / / / / / / / /\n");
    printf("\t\t\t\t/_/  |_\\__,_/_/ /_/ /_/_/_/ /_/ \n");
	printf ( "            	   ***************欢迎"LIGHT_RED"超级管理员"NONE""YELLOW"%s"NONE"来到管理员操作界面*************\n",AdminList[AdminIndex].ID );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       请输入1 ~ 10继续操作                        <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[1]"NONE":订单管理                                                      <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[2]"NONE":统计用户订单信息                                              <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[3]"NONE":景点管理                                                      <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[4]"NONE":用户信息管理                                                  <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[5]"NONE":管理员注册                                                    <----|\n" );
    printf ( "	|----> "LIGHT_GREEN"[6]"NONE":查看所有管理员                                                <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[7]"NONE":查看现有用户                                                  <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[8]"NONE":返回初始界面                                                  <----|\n" );
    printf ( "	|----> "LIGHT_GREEN"[9]"NONE":修改个人管理员信息                                            <----|\n" );
    printf ( "	|----> "LIGHT_GREEN"[10]"NONE":修改具体管理员信息                                           <----|\n" );
    printf ( "	|----> "LIGHT_GREEN"[11]"NONE":退出程序                                                     <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t请输入你想进行的操作：");
	choice = MyInput(1, 11);
	return choice;
}

void userMenuSen()      //用户菜单响应 
{
	int choice = userMenu();
	// 先给新用户注册
	printf("\n\t----> 		程序在进行		<----|\n");	
	switch (choice)
	{
		case 1:
			userLogin();
			break;
		case 2:
			userRegister();
			break;
		case 3:
			printf("\n\t将于3秒后跳转到初始界面......");
            Sleep(3000);
            system("cls");
            menuSen();
            break;	
		case 4:
			printf("\n\t程序结束，感谢您的使用谢谢！\n");	
			break;				
		default:
			break;
	}
	return ;	
}

int userMenu()    // 用户登录菜单 
{
	int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf("\t\t\t\t   __  __              \n");
    printf("\t\t\t\t  / / / /_______  _____\n");
    printf("\t\t\t\t / / / / ___/ _ \\/ ___/\n");
    printf("\t\t\t\t/ /_/ (__  )  __/ /    \n");
    printf("\t\t\t\t\\____/____/\\___/_/     \n");
	printf ( "            	      ***************欢迎来到"YELLOW"游客团"NONE"的登录界面*************\n" );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       请选择输入你要操作的选择                    <----|\n" );	
	printf ( "	|---->  "LIGHT_GREEN"[1]"NONE": 游客团登录                                                  <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[2]"NONE"：游客团注册                                                  <----|\n" );	
    printf ( "	|---->  "LIGHT_GREEN"[3]"NONE"：返回上一级                                                  <----|\n" );
    printf ( "	|---->  "LIGHT_GREEN"[4]"NONE"：退出程序                                                    <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t请输入你想进行的操作：");
	choice = MyInput(1, 4);
	return choice;	
}


void userSen()    //用户操作菜单响应 
{
	system("cls");
	int choice = userGui();
	printf("\n\t----> 		程序在进行		<----|\n");
    switch (choice)
    {
        case 1:
			printf("\n\t将于3秒后跳转到景点查询界面......");
            Sleep(3000);
            findScenic();
            userSen();
            break;
        case 2:
        	printf("\n\t将于3秒后跳转到预定景点界面......");
            Sleep(3000);
            ValidateOrderNumber();
			userSen();
            break;
        case 3:
            printf("\n\t将于3秒后跳转到旅游团信息管理界面......");
            Sleep(3000);
			ChangeInfoOfUserByUser(); 
            break;
        case 4:            //删除预定信息 
            printf("\n\t将于3秒后跳转到旅游团取消预订界面......");
            Sleep(3000);
            system("cls");
            if(OrderList[g_groups[UserIndex].orderNumber].NumberOfScenicIndex == 0){
				printf("您暂时还没有订单");
				Sleep(3000);
				system("cls");
			}else{
            	system("cls");
            	printf("查看你的订单情况\n"); 
				showOrderByUser(); // 旅游团信息管理 
				DeleteOrder();  //删除订单 
				system("cls"); 
			}
			
			system("cls");
			userSen();
		case 5:
			printf("\n\t将于3秒后跳转到查询预定信息界面......");
			if(OrderList[g_groups[UserIndex].orderNumber].NumberOfScenicIndex == 0){
				printf("\n\t"LIGHT_RED"您暂时还没有订单"NONE"");
				Sleep(3000);
				system("cls");
			}else{
				Sleep(3000);
            	system("cls");
				showOrderByUser(); // 旅游团信息管理  
			} 
			userSen();
		case 6:
		 	printf("\n\t将于3秒后跳转到查看自身信息界面......");
            Sleep(3000);
            system("cls");
            showPersonalUser();
			userSen(); 
		case 7:
		 	printf("\n\t将于3秒后跳转到用户界面......");
            Sleep(3000);
            system("cls");
			userMenuSen();
		case 8:
		 	printf("\n\t程序将于3秒后退出......");
            Sleep(3000);
            system("cls");
            exit(0);
			break;
        default:
        	printf("\n\t程序结束，感谢您的使用谢谢！\n");	
			break;
    }		
	return ;
}


int userGui()      //用户操作菜单 
{
    int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf("\t\t\t\t   __  __              \n");
    printf("\t\t\t\t  / / / /_______  _____\n");
    printf("\t\t\t\t / / / / ___/ _ \\/ ___/\n");
    printf("\t\t\t\t/ /_/ (__  )  __/ /    \n");
    printf("\t\t\t\t\\____/____/\\___/_/     \n");
	printf ( "            	     ***************欢迎游客团"YELLOW"%s"NONE"来到游客团操作界面*************\n",g_groups[UserIndex].ID );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       请选择输入你要操作的选择                    <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[1]"NONE":景点查询                                                     <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[2]"NONE":预定景点门票                                                 <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[3]"NONE":旅游团信息管理                                               <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[4]"NONE":取消预订                                                     <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[5]"NONE":查询预定的门票                                               <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[6]"NONE":查看自身旅游团信息                                           <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[7]"NONE":返回用户菜单                                                 <----|\n" );
    printf ( "	|---->  "LIGHT_GREEN"[8]"NONE":退出程序                                                     <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t请输入你想进行的操作: ");
	choice = MyInput(1,8);
	return choice;	
}


int userGuiback() {
	int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf("\t\t\t\t   __  __              \n");
    printf("\t\t\t\t  / / / /_______  _____\n");
    printf("\t\t\t\t / / / / ___/ _ \\/ ___/\n");
    printf("\t\t\t\t/ /_/ (__  )  __/ /    \n");
    printf("\t\t\t\t\\____/____/\\___/_/     \n");
	printf ( "            	     ***************欢迎游客团"YELLOW"%s"NONE"来到景点查询界面*************\n",g_groups[UserIndex].ID );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                      请选择景点查询方式                           <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[1]"NONE":根据名称查询                                                 <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[2]"NONE":根据是否有票查询                                             <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[3]"NONE":根据景点区域查询                                             <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[4]"NONE":按照价格进行排序推荐                                         <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[5]"NONE":按照景点门票预定量进行推荐                                   <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[6]"NONE":按照景点热度和价格综合排序                                   <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[7]"NONE":查看所有景点                                                 <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[8]"NONE":查看所有有折扣的景点                                         <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[9]"NONE":预定                                                         <----|\n" );
    printf ( "	|---->  "LIGHT_GREEN"[10]"NONE":返回上一游客团操作界面                                      <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t请输入你想进行的操作: ");
	choice = MyInput(1, 10);
	return choice;	
}

void findScenic()   //景点查询响应 
{
	system("cls");
	int choice = userGuiback();
	printf("\n\t----> 		程序在进行		<----|");
	switch (choice) {
       	case 1:
            Sleep(3000);
			searchByName();
            break;
        case 2:
            Sleep(3000);
			searchByTickets();
            break;
        case 3:
		    Sleep(3000);
			searchByRegion();
            break;
        case 4:
        	Sleep(3000);
			PriceSort(); //根据价格进行排序 
            break;
        case 5:
            Sleep(3000);
            ReserveSort();
			findScenic(); 
			break;
        case 6:
            Sleep(3000);
			HotSort();
			findScenic();
            break;
        case 7:
            Sleep(3000);
			showScenic();
			findScenic();
            break;
        case 8:
            Sleep(3000);
			showScenicByAccount();
			findScenic();
            break;
        case 9:
            Sleep(3000);
			ValidateOrderNumber(); 
			system("cls");
			findScenic();
            break;
		case 10:
            Sleep(3000);
            system("cls");
			userGui();
            break;    
    	default:
            printf("\t无效的选项，请重新输入:");
	}
}



void OrderStatistics()  //管理员操作界面响应 
{
	system("cls"); 
    int choice = OrderStatisticsGui();

    switch (choice)
    {
        case 1:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到按预定量统计界面......");
			Sleep(3000);
			system("cls");
            ReserveSort();  //按预定量统计 
            system("cls");
            OrderStatistics();
            break;
        case 2:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到统计景点访问人数信息页面......");
			Sleep(3000);
			system("cls");
			ViewsSort(); 
			system("cls");
            OrderStatistics(); //统计用户订单情况 
            break;
        case 3:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到经典热门预定时间界面.....\n");
			Sleep(3000);
			system("cls");
			HotTimeSort(); 
			system("cls");
			OrderStatistics();
            break;
        case 4:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到利润统计排序页面......");
			Sleep(3000);
        	system("cls");
			ProfitSort(); 
			system("cls");
			OrderStatistics();
			break;
        case 5:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到景点年龄层次分布统计页面......");
			Sleep(3000);
			system("cls"); 
			ageLevelSort();
			system("cls");
			OrderStatistics(); 
			break;
        case 6:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后返回上一个界面......");
			Sleep(3000);
			system("cls");
			SeasonSoldSort();
			system("cls");
			OrderStatistics(); //展示现有管理员(默认管理员操作)
            break;
        case 7:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后返回上一个界面......");
			Sleep(3000);
			system("cls");
			if(AdminIndex == 5){
				SuperadminGuiSen();
			}else{
				adminGuiSen();
			}
			break;  
        case 8:
			printf("\n\t程序即将退出......");
			Sleep(3000);
            break;
        default:
            break;
    }
	return ;
}


int OrderStatisticsGui(){
	int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf("\t\t\t\t    ___       __          _     \n");
    printf("\t\t\t\t   /   | ____/ /___ ___  (_)___ \n");
    printf("\t\t\t\t  / /| |/ __  / __ `__ \\/ / __ \\\n");
    printf("\t\t\t\t / ___ / /_/ / / / / / / / / / /\n");
    printf("\t\t\t\t/_/  |_\\__,_/_/ /_/ /_/_/_/ /_/ \n");
	printf ( "            	      ***************欢迎管理员"YELLOW"%s"NONE"*************\n",AdminList[AdminIndex].ID );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       请选择输入你要操作的选择                    <----|\n" );	
	printf ( "	|---->  "LIGHT_GREEN"[1]"NONE": 按预定量对景点进行排序                                      <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[2]"NONE"：按访问人数对景点进行排序                                    <----|\n" );	
    printf ( "	|---->  "LIGHT_GREEN"[3]"NONE"：不同景点的热门预定时间                                      <----|\n" );
    printf ( "	|---->  "LIGHT_GREEN"[4]"NONE"：各个景点的利润排序                                          <----|\n" );
    printf ( "	|---->  "LIGHT_GREEN"[5]"NONE"：不同景点的用户年龄层次分布                                  <----|\n" );
    printf ( "	|---->  "LIGHT_GREEN"[6]"NONE"：按季度对不同景点的售票情况进行排序                          <----|\n" );
    printf ( "	|---->  "LIGHT_GREEN"[7]"NONE"：返回上一个界面                                              <----|\n" );
    printf ( "	|---->  "LIGHT_GREEN"[8]"NONE"：退出程序                                                    <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t请输入你想进行的操作：");
	choice = MyInput(1, 8);
	return choice;
}


void SuperadminGuiSen()  //管理员操作界面响应 
{
    int choice = SuperadminGui();

	// 先给新用户注册
    switch (choice)
    {
        case 1:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到订单管理页面......");
			Sleep(3000);
            showOrderByAdmin();
            system("cls");
            SuperadminGuiSen();
            break;
        case 2:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到统计用户订单信息页面......");
			Sleep(3000);
            OrderStatistics(); //统计用户订单情况 
            break;
        case 3:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到景点信息管理页面.....\n");
			Sleep(3000);
            printf("\t请输入要查询还是删除景点\n"); 
            printf("\t"LIGHT_GREEN"[1]"NONE" 查询景点\n"); 
            printf("\t"LIGHT_GREEN"[2]"NONE" 添加景点\n\t");
			int input = MyInput(1,2);
			if(input == 1){
				showScenicByAdmin();
				SuperadminGuiSen();
			}else if(input == 2){
				addScenic();
				SuperadminGuiSen(); 
			}
			 
            break;
        case 4:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到用户个人信息管理页面......");
			Sleep(3000);
        	ChangeInfoOfUserByAdmin();
			break;
        case 5:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到管理员注册页面......");
			Sleep(3000);
			addAdmin();
			break;
        case 6:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到查看所有管理员界面......");
			Sleep(3000);
			system("cls");
			showAdmin(); //展示现有管理员(默认管理员操作)
            break;
        case 7:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到查看现有用户......");
			Sleep(3000);
			system("cls");
			showUser(); 
        case 8:
			printf("\n\t----> 		程序在进行		<----|\n");
			printf("\t将于3秒后跳转到初始界面......");
			Sleep(3000);
			system("cls");
			menuSen();
        case 9:
        	printf("\n\t----> 		程序在进行		<----|\n");
        	printf("\t将于3秒后跳转到修改管理员信息界面......");
			Sleep(3000);
			ChangeInfoOfAdminByAdmin();
            break;
        case 10:
        	printf("\n\t----> 		程序在进行		<----|\n");
        	printf("\t将于3秒后跳转到修改管理员信息界面......");
        	Sleep(3000); 
			ChangeInfoOfAdmin(); 
			break;
        case 11:
			printf("\n\t程序即将退出......");
			Sleep(3000);
            exit(0);
        default:
            break;
    }
	return ;
}
