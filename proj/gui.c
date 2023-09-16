#include "gui.h"

void menuSen(){
	int choice = menu();  //�������˵� 
	printf("\n\t----> 		�����ڽ���		<----|\n");
	switch(choice){
		case 1:
			printf("\n\t������2�����ת������Ա�˵�����......");
			Sleep(2000);
			system("cls");
			adminMenuSen();  //�������Աפ��ҳ�� 
			break;
		case 2:
			printf("\n\t������2�����ת���ο��Ų˵�����......");
			Sleep(2000);
			system("cls");
			userMenuSen();
			break;
		case 3:
			printf("\t���������ллʹ�ã�\n");
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
    
	printf ( "            	    ***************��ӭ����"YELLOW"�����ζ�Ʊ����ϵͳ"NONE"*************\n" );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       ��ѡ��������Ҫ������ѡ��                    <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[1]"NONE": ����Ա                                                       <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[2]"NONE": �ο���                                                       <----|\n" );
    printf ( "	|----> "LIGHT_GREEN"[3]"NONE": �˳�����                                                     <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t������������еĲ�����");
	choice = MyInput(1, 3);
	return choice;
	
}


void adminMenuSen(){     //����Ա��¼�˵���Ӧ 
	int choice = adminMenu();
	printf("\n\t----> 		�����ڽ���		<----|\n");	
	switch (choice)
	{
		case 1:
			AdminLogin();  //��֤����Ա��¼ 
			break;
		case 2:
			printf("\n\t����2�����ת����ʼ����......");
            Sleep(2000);
            system("cls");
            menuSen();
            break;	
		case 3:
			printf("\n\t�����������л����ʹ��лл��\n");	
			break;				
		default:
			break;
	}
	return ;
}

int adminMenu() // ����Ա��¼�˵�
{
	int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf("\t\t\t\t    ___       __          _     \n");
    printf("\t\t\t\t   /   | ____/ /___ ___  (_)___ \n");
    printf("\t\t\t\t  / /| |/ __  / __ `__ \\/ / __ \\\n");
    printf("\t\t\t\t / ___ / /_/ / / / / / / / / / /\n");
    printf("\t\t\t\t/_/  |_\\__,_/_/ /_/ /_/_/_/ /_/ \n");
	printf ( "            	    ***************��ӭ����"YELLOW"����Ա"NONE"�ĵ�¼����*************\n" );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       ��ѡ��������Ҫ������ѡ��                    <----|\n" );	
	printf ( "	|----> "LIGHT_GREEN"[1]"NONE": ����Ա��¼                                                   <----|\n" );	
    printf ( "	|----> "LIGHT_GREEN"[2]"NONE"��������һ��                                                   <----|\n" );
    printf ( "	|----> "LIGHT_GREEN"[3]"NONE"���˳�����                                                     <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t������������еĲ�����");
	choice = MyInput(1, 3);
	return choice;
}


void adminGuiSen()  //����Ա����������Ӧ 
{
    int choice = adminGui();

	// �ȸ����û�ע��
    switch (choice)
    {
        case 1:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת����������ҳ��......");
			Sleep(3000);
            showOrderByAdmin();
            system("cls");
            adminGuiSen();
            break;
        case 2:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת��ͳ���û�������Ϣҳ��......");
			Sleep(3000);
            OrderStatistics(); //ͳ���û�������� 
            break;
        case 3:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת��������Ϣ����ҳ��.....\n");
			Sleep(3000);
            printf("\t������Ҫ��ѯ����ɾ������\n"); 
            printf("\t"LIGHT_GREEN"[1]"NONE" ��ѯ����\n"); 
            printf("\t"LIGHT_GREEN"[2]"NONE" ��Ӿ���\n\t");
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
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת���û�������Ϣ����ҳ��......");
			Sleep(3000);
        	ChangeInfoOfUserByAdmin();
			break;
        case 5:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת���鿴�����û�......");
			Sleep(3000);
			system("cls");
			showUser(); 
        case 6:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת����ʼ����......");
			Sleep(3000);
			system("cls");
			menuSen();
        case 7:
        	printf("\n\t----> 		�����ڽ���		<----|\n");
        	printf("\t����3�����ת���޸Ĺ���Ա��Ϣ......");
			Sleep(3000);
			ChangeInfoOfAdminByAdmin();
            break;
        case 8:
			printf("\n\t���򼴽��˳�......");
			Sleep(3000);
            exit(0);
        default:
            break;
    }
	return ;
}


int adminGui()  //����Ա�����˵� 
{
    int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf("\t\t\t\t    ___       __          _     \n");
    printf("\t\t\t\t   /   | ____/ /___ ___  (_)___ \n");
    printf("\t\t\t\t  / /| |/ __  / __ `__ \\/ / __ \\\n");
    printf("\t\t\t\t / ___ / /_/ / / / / / / / / / /\n");
    printf("\t\t\t\t/_/  |_\\__,_/_/ /_/ /_/_/_/ /_/ \n");
	printf ( "            	   ***************��ӭ����Ա"YELLOW"%s"NONE"��������Ա��������*************\n",AdminList[AdminIndex].ID );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       ������1 ~ 10��������                        <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[1]"NONE":��������                                                      <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[2]"NONE":ͳ���û�������Ϣ                                              <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[3]"NONE":�������                                                      <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[4]"NONE":�û���Ϣ����                                                  <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[5]"NONE":�鿴�����û�                                                  <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[6]"NONE":���س�ʼ����                                                  <----|\n" );
    printf ( "	|----> "LIGHT_GREEN"[7]"NONE":�޸ĸ��˹���Ա��Ϣ                                            <----|\n" );
    printf ( "	|----> "LIGHT_GREEN"[8]"NONE":�˳�����                                                     <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t������������еĲ�����");
	choice = MyInput(1, 8);
	return choice;
}

int SuperadminGui()  //����Ա�����˵� 
{
    int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf("\t\t\t\t    ___       __          _     \n");
    printf("\t\t\t\t   /   | ____/ /___ ___  (_)___ \n");
    printf("\t\t\t\t  / /| |/ __  / __ `__ \\/ / __ \\\n");
    printf("\t\t\t\t / ___ / /_/ / / / / / / / / / /\n");
    printf("\t\t\t\t/_/  |_\\__,_/_/ /_/ /_/_/_/ /_/ \n");
	printf ( "            	   ***************��ӭ"LIGHT_RED"��������Ա"NONE""YELLOW"%s"NONE"��������Ա��������*************\n",AdminList[AdminIndex].ID );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       ������1 ~ 10��������                        <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[1]"NONE":��������                                                      <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[2]"NONE":ͳ���û�������Ϣ                                              <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[3]"NONE":�������                                                      <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[4]"NONE":�û���Ϣ����                                                  <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[5]"NONE":����Աע��                                                    <----|\n" );
    printf ( "	|----> "LIGHT_GREEN"[6]"NONE":�鿴���й���Ա                                                <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[7]"NONE":�鿴�����û�                                                  <----|\n" );
	printf ( "	|----> "LIGHT_GREEN"[8]"NONE":���س�ʼ����                                                  <----|\n" );
    printf ( "	|----> "LIGHT_GREEN"[9]"NONE":�޸ĸ��˹���Ա��Ϣ                                            <----|\n" );
    printf ( "	|----> "LIGHT_GREEN"[10]"NONE":�޸ľ������Ա��Ϣ                                           <----|\n" );
    printf ( "	|----> "LIGHT_GREEN"[11]"NONE":�˳�����                                                     <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t������������еĲ�����");
	choice = MyInput(1, 11);
	return choice;
}

void userMenuSen()      //�û��˵���Ӧ 
{
	int choice = userMenu();
	// �ȸ����û�ע��
	printf("\n\t----> 		�����ڽ���		<----|\n");	
	switch (choice)
	{
		case 1:
			userLogin();
			break;
		case 2:
			userRegister();
			break;
		case 3:
			printf("\n\t����3�����ת����ʼ����......");
            Sleep(3000);
            system("cls");
            menuSen();
            break;	
		case 4:
			printf("\n\t�����������л����ʹ��лл��\n");	
			break;				
		default:
			break;
	}
	return ;	
}

int userMenu()    // �û���¼�˵� 
{
	int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf("\t\t\t\t   __  __              \n");
    printf("\t\t\t\t  / / / /_______  _____\n");
    printf("\t\t\t\t / / / / ___/ _ \\/ ___/\n");
    printf("\t\t\t\t/ /_/ (__  )  __/ /    \n");
    printf("\t\t\t\t\\____/____/\\___/_/     \n");
	printf ( "            	      ***************��ӭ����"YELLOW"�ο���"NONE"�ĵ�¼����*************\n" );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       ��ѡ��������Ҫ������ѡ��                    <----|\n" );	
	printf ( "	|---->  "LIGHT_GREEN"[1]"NONE": �ο��ŵ�¼                                                  <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[2]"NONE"���ο���ע��                                                  <----|\n" );	
    printf ( "	|---->  "LIGHT_GREEN"[3]"NONE"��������һ��                                                  <----|\n" );
    printf ( "	|---->  "LIGHT_GREEN"[4]"NONE"���˳�����                                                    <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t������������еĲ�����");
	choice = MyInput(1, 4);
	return choice;	
}


void userSen()    //�û������˵���Ӧ 
{
	system("cls");
	int choice = userGui();
	printf("\n\t----> 		�����ڽ���		<----|\n");
    switch (choice)
    {
        case 1:
			printf("\n\t����3�����ת�������ѯ����......");
            Sleep(3000);
            findScenic();
            userSen();
            break;
        case 2:
        	printf("\n\t����3�����ת��Ԥ���������......");
            Sleep(3000);
            ValidateOrderNumber();
			userSen();
            break;
        case 3:
            printf("\n\t����3�����ת����������Ϣ�������......");
            Sleep(3000);
			ChangeInfoOfUserByUser(); 
            break;
        case 4:            //ɾ��Ԥ����Ϣ 
            printf("\n\t����3�����ת��������ȡ��Ԥ������......");
            Sleep(3000);
            system("cls");
            if(OrderList[g_groups[UserIndex].orderNumber].NumberOfScenicIndex == 0){
				printf("����ʱ��û�ж���");
				Sleep(3000);
				system("cls");
			}else{
            	system("cls");
            	printf("�鿴��Ķ������\n"); 
				showOrderByUser(); // ��������Ϣ���� 
				DeleteOrder();  //ɾ������ 
				system("cls"); 
			}
			
			system("cls");
			userSen();
		case 5:
			printf("\n\t����3�����ת����ѯԤ����Ϣ����......");
			if(OrderList[g_groups[UserIndex].orderNumber].NumberOfScenicIndex == 0){
				printf("\n\t"LIGHT_RED"����ʱ��û�ж���"NONE"");
				Sleep(3000);
				system("cls");
			}else{
				Sleep(3000);
            	system("cls");
				showOrderByUser(); // ��������Ϣ����  
			} 
			userSen();
		case 6:
		 	printf("\n\t����3�����ת���鿴������Ϣ����......");
            Sleep(3000);
            system("cls");
            showPersonalUser();
			userSen(); 
		case 7:
		 	printf("\n\t����3�����ת���û�����......");
            Sleep(3000);
            system("cls");
			userMenuSen();
		case 8:
		 	printf("\n\t������3����˳�......");
            Sleep(3000);
            system("cls");
            exit(0);
			break;
        default:
        	printf("\n\t�����������л����ʹ��лл��\n");	
			break;
    }		
	return ;
}


int userGui()      //�û������˵� 
{
    int choice;
	printf ( "\n" );
	printf ( "\n" );
	printf("\t\t\t\t   __  __              \n");
    printf("\t\t\t\t  / / / /_______  _____\n");
    printf("\t\t\t\t / / / / ___/ _ \\/ ___/\n");
    printf("\t\t\t\t/ /_/ (__  )  __/ /    \n");
    printf("\t\t\t\t\\____/____/\\___/_/     \n");
	printf ( "            	     ***************��ӭ�ο���"YELLOW"%s"NONE"�����ο��Ų�������*************\n",g_groups[UserIndex].ID );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       ��ѡ��������Ҫ������ѡ��                    <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[1]"NONE":�����ѯ                                                     <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[2]"NONE":Ԥ��������Ʊ                                                 <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[3]"NONE":��������Ϣ����                                               <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[4]"NONE":ȡ��Ԥ��                                                     <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[5]"NONE":��ѯԤ������Ʊ                                               <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[6]"NONE":�鿴������������Ϣ                                           <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[7]"NONE":�����û��˵�                                                 <----|\n" );
    printf ( "	|---->  "LIGHT_GREEN"[8]"NONE":�˳�����                                                     <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t������������еĲ���: ");
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
	printf ( "            	     ***************��ӭ�ο���"YELLOW"%s"NONE"���������ѯ����*************\n",g_groups[UserIndex].ID );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                      ��ѡ�񾰵��ѯ��ʽ                           <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[1]"NONE":�������Ʋ�ѯ                                                 <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[2]"NONE":�����Ƿ���Ʊ��ѯ                                             <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[3]"NONE":���ݾ��������ѯ                                             <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[4]"NONE":���ռ۸���������Ƽ�                                         <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[5]"NONE":���վ�����ƱԤ���������Ƽ�                                   <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[6]"NONE":���վ����ȶȺͼ۸��ۺ�����                                   <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[7]"NONE":�鿴���о���                                                 <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[8]"NONE":�鿴�������ۿ۵ľ���                                         <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[9]"NONE":Ԥ��                                                         <----|\n" );
    printf ( "	|---->  "LIGHT_GREEN"[10]"NONE":������һ�ο��Ų�������                                      <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t������������еĲ���: ");
	choice = MyInput(1, 10);
	return choice;	
}

void findScenic()   //�����ѯ��Ӧ 
{
	system("cls");
	int choice = userGuiback();
	printf("\n\t----> 		�����ڽ���		<----|");
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
			PriceSort(); //���ݼ۸�������� 
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
            printf("\t��Ч��ѡ�����������:");
	}
}



void OrderStatistics()  //����Ա����������Ӧ 
{
	system("cls"); 
    int choice = OrderStatisticsGui();

    switch (choice)
    {
        case 1:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת����Ԥ����ͳ�ƽ���......");
			Sleep(3000);
			system("cls");
            ReserveSort();  //��Ԥ����ͳ�� 
            system("cls");
            OrderStatistics();
            break;
        case 2:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת��ͳ�ƾ������������Ϣҳ��......");
			Sleep(3000);
			system("cls");
			ViewsSort(); 
			system("cls");
            OrderStatistics(); //ͳ���û�������� 
            break;
        case 3:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת����������Ԥ��ʱ�����.....\n");
			Sleep(3000);
			system("cls");
			HotTimeSort(); 
			system("cls");
			OrderStatistics();
            break;
        case 4:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת������ͳ������ҳ��......");
			Sleep(3000);
        	system("cls");
			ProfitSort(); 
			system("cls");
			OrderStatistics();
			break;
        case 5:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת�����������ηֲ�ͳ��ҳ��......");
			Sleep(3000);
			system("cls"); 
			ageLevelSort();
			system("cls");
			OrderStatistics(); 
			break;
        case 6:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3��󷵻���һ������......");
			Sleep(3000);
			system("cls");
			SeasonSoldSort();
			system("cls");
			OrderStatistics(); //չʾ���й���Ա(Ĭ�Ϲ���Ա����)
            break;
        case 7:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3��󷵻���һ������......");
			Sleep(3000);
			system("cls");
			if(AdminIndex == 5){
				SuperadminGuiSen();
			}else{
				adminGuiSen();
			}
			break;  
        case 8:
			printf("\n\t���򼴽��˳�......");
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
	printf ( "            	      ***************��ӭ����Ա"YELLOW"%s"NONE"*************\n",AdminList[AdminIndex].ID );
	printf ( "	______________________________________________________________________________\n" );
	printf ( "	|---->                       ��ѡ��������Ҫ������ѡ��                    <----|\n" );	
	printf ( "	|---->  "LIGHT_GREEN"[1]"NONE": ��Ԥ�����Ծ����������                                      <----|\n" );
	printf ( "	|---->  "LIGHT_GREEN"[2]"NONE"�������������Ծ����������                                    <----|\n" );	
    printf ( "	|---->  "LIGHT_GREEN"[3]"NONE"����ͬ���������Ԥ��ʱ��                                      <----|\n" );
    printf ( "	|---->  "LIGHT_GREEN"[4]"NONE"�������������������                                          <----|\n" );
    printf ( "	|---->  "LIGHT_GREEN"[5]"NONE"����ͬ������û������ηֲ�                                  <----|\n" );
    printf ( "	|---->  "LIGHT_GREEN"[6]"NONE"�������ȶԲ�ͬ�������Ʊ�����������                          <----|\n" );
    printf ( "	|---->  "LIGHT_GREEN"[7]"NONE"��������һ������                                              <----|\n" );
    printf ( "	|---->  "LIGHT_GREEN"[8]"NONE"���˳�����                                                    <----|\n" );
	printf ( "	|_____________________________________________________________________________|\n" );
	printf("\t������������еĲ�����");
	choice = MyInput(1, 8);
	return choice;
}


void SuperadminGuiSen()  //����Ա����������Ӧ 
{
    int choice = SuperadminGui();

	// �ȸ����û�ע��
    switch (choice)
    {
        case 1:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת����������ҳ��......");
			Sleep(3000);
            showOrderByAdmin();
            system("cls");
            SuperadminGuiSen();
            break;
        case 2:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת��ͳ���û�������Ϣҳ��......");
			Sleep(3000);
            OrderStatistics(); //ͳ���û�������� 
            break;
        case 3:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת��������Ϣ����ҳ��.....\n");
			Sleep(3000);
            printf("\t������Ҫ��ѯ����ɾ������\n"); 
            printf("\t"LIGHT_GREEN"[1]"NONE" ��ѯ����\n"); 
            printf("\t"LIGHT_GREEN"[2]"NONE" ��Ӿ���\n\t");
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
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת���û�������Ϣ����ҳ��......");
			Sleep(3000);
        	ChangeInfoOfUserByAdmin();
			break;
        case 5:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת������Աע��ҳ��......");
			Sleep(3000);
			addAdmin();
			break;
        case 6:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת���鿴���й���Ա����......");
			Sleep(3000);
			system("cls");
			showAdmin(); //չʾ���й���Ա(Ĭ�Ϲ���Ա����)
            break;
        case 7:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת���鿴�����û�......");
			Sleep(3000);
			system("cls");
			showUser(); 
        case 8:
			printf("\n\t----> 		�����ڽ���		<----|\n");
			printf("\t����3�����ת����ʼ����......");
			Sleep(3000);
			system("cls");
			menuSen();
        case 9:
        	printf("\n\t----> 		�����ڽ���		<----|\n");
        	printf("\t����3�����ת���޸Ĺ���Ա��Ϣ����......");
			Sleep(3000);
			ChangeInfoOfAdminByAdmin();
            break;
        case 10:
        	printf("\n\t----> 		�����ڽ���		<----|\n");
        	printf("\t����3�����ת���޸Ĺ���Ա��Ϣ����......");
        	Sleep(3000); 
			ChangeInfoOfAdmin(); 
			break;
        case 11:
			printf("\n\t���򼴽��˳�......");
			Sleep(3000);
            exit(0);
        default:
            break;
    }
	return ;
}
