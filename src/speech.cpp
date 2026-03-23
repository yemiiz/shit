#include "speech.h"
#include <iostream>
using namespace std;
speechmanager::speechmanager() // 不能加分号
{
}
void speechmanager::show_menu()
{
    cout << "************************************" << endl;
    cout << "*********  欢迎使用演讲管理系统 *****" << endl;
    cout << "*********  1.开始演讲比赛  *********" << endl;
    cout << "*********  2.查看往届记录  *********" << endl;
    cout << "*********  3.清空比赛记录  *********" << endl;
    cout << "*********  0.退出比赛系统  *********" << endl;
    cout << "************************************" << endl;
}
void speechmanager::exit_system()
{
    cout << "欢迎下次使用！" << endl;
    system("pause");
}

speechmanager::~speechmanager()
{
}
