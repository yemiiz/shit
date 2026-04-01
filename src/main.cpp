#include <iostream>
#include "speechmanager.h"
#include "speaker.h"
using namespace std;

int main()
{
    // 设置演讲管理类
    speechmanager sm;
    /*用于测试是否有正确创建选手，输出选手编号和姓名
    for(map<int,speaker>::iterator it = sm.m_speaker.begin(); it != sm.m_speaker.end(); it++)
    {
        cout << "选手编号： " << it->first << " 选手姓名： " << it->second.m_name << endl;
    }
    */

    // 调用菜单函数
    int choice = 0;
    while (true)
    {
        sm.show_menu();
        cout << "请输入您的选择： " << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            // 处理开始演讲比赛的逻辑
            break;
        case 2:
            // 处理查看往届记录的逻辑
            break;
        case 3:
            // 处理清空比赛记录的逻辑
            break;
        case 0:
            sm.exit_system(); // 处理退出比赛系统的逻辑
            return 0;
        default:
            cout << "输入有误，请重新输入！" << endl;
            break;
        }
    }

} 
