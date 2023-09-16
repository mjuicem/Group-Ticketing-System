#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <stdio.h>
#include <string.h>
#include <stdbool.h> 
#include <time.h>
#include <math.h>
#include "scenic.h" 

//颜色宏定义
#define NONE         "\033[m"
#define RED          "\033[0;32;31m"
#define LIGHT_RED    "\033[1;31m"
#define GREEN        "\033[0;32;32m"
#define LIGHT_GREEN  "\033[1;32m"
#define BLUE         "\033[0;32;34m"
#define LIGHT_BLUE   "\033[1;34m"
#define DARY_GRAY    "\033[1;30m"
#define CYAN         "\033[0;36m"
#define LIGHT_CYAN   "\033[1;36m"
#define PURPLE       "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BROWN        "\033[0;33m"
#define YELLOW       "\033[1;33m"
#define LIGHT_GRAY   "\033[0;37m"
#define WHITE        "\033[1;37m"



/**
    ____                 __  _           
   / __/_  ______  _____/ /_(_)___  ____ 
  / /_/ / / / __ \/ ___/ __/ / __ \/ __ \
 / __/ /_/ / / / / /__/ /_/ / /_/ / / / /
/_/  \__,_/_/ /_/\___/\__/_/\____/_/ /_/ 
                                       

*/

int MyInput(int low,int high);  //快读 
bool validateID(const char* id);  //判断ID是否有效 
bool validatePhoneNumber(const char* phoneNumber); //判断电话号码是否有效
bool validateEmail(const char* Email); //判断邮箱是否有效 
bool validatePassWord(const char* PassWord); //判断密码是否有效 
bool isDateFormatValid(const char* timeStr); //判断用户输入的时间格式是否正确 


void ValidateID(const char* id);  //判断ID是否有效 
void ValidatePhoneNumber(const char* phoneNumber); //判断电话号码是否有效
void ValidateEmail(const char* Email); //判断邮箱是否有效 
void ValidatePassWord(const char* PassWord); //判断密码是否有效 
void ValidateOrderNumber();   //判断订单数是否有效 



void parseTime(const char* timeStr, int* year, int* month, int* day, int* hour); //转换时间字符串格式 
int calculateDayDifference(const char* startTime,const char* endTime); //返回两个格式为"yyyy:mm:dd:ss"的时间的相差天数 
int getMonth(const char* timeStr); //判断月份 
int isDateTimeInRange(const char* dateTimeStr);  


void searchByName();  //根据景点名称查询
void searchByRegion();  //根据景点区域查询
void PriceSort();  //根据价格排序各个景点
void ReserveSort();   //根据预定量排序 
void searchByTickets(); //根据是否有票进行查询 
void ViewsSort();  //按访问人数进行排序 
void HotTimeSort();  //按热门时间进行统计 
void ProfitSort(); //按利润进行统计排序
void ageLevelSort();  //按用户年龄层次分布统计排序 
void SeasonSoldSort(); // 按季度对不同景点的售票情况进行排序,比较不同景点在不同季度的访问情况 
void showScenicByAccount();
void HotSort();  //预定量+浏览人数排序 


void CLEANBUFF(); //清理缓存 
#endif

