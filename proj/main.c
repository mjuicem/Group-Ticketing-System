#include "user.h"
#include "gui.h"
#include "function.h"
#include "admin.h" 
#include "scenic.h"
#include "order.h" 

/**
                    _                   
   ____ ___  ____ _(_)___          _____
  / __ `__ \/ __ `/ / __ \        / ___/
 / / / / / / /_/ / / / / /  _    / /__  
/_/ /_/ /_/\__,_/_/_/ /_/  (_)   \___/ 


*/

int main(int argc, char *argv[]) {
	 // ���ļ��м����ο�����Ϣ
    loadUser(); //�������������� 
    loadAdmin(); //�������Ա���� 
    loadScenic(); //���뾰����Ϣ 
    loadOrder(); //���붩����Ϣ 
	menuSen();  //�������˵���Ӧҳ�� 
    return 0;
}
