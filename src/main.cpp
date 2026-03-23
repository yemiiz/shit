#include <iostream>
#include "speech.h"
using namespace std;
int main()
{
    // 设置演讲管理类
    speechmanager sm;
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

} // namespace std;
