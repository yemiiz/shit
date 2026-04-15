#include "speechmanager.h"
using namespace std;
speechmanager::speechmanager() // 不能加分号
{
    this->init_speech();
    this->create_speaker();
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

speechmanager::~speechmanager() {

};

void speechmanager::init_speech()
{
    this->pre_speaker.clear();
    this->final_speaker.clear();
    this->win_speaker.clear();
    this->m_speaker.clear();

    this->m_index = 1;
};

void speechmanager::create_speaker()
{
    string nameseed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameseed.size(); i++)
    {
        string name = "选手";
        name += nameseed[i];
        speaker sp;
        sp.m_name = name;
        for (int j = 0; j < 2; j++)
        {
            sp.m_score[j] = 0;
        }
        this->pre_speaker.push_back(100001 + i);
        this->m_speaker.insert(std::make_pair(100001 + i, sp));
        // this->m_index++;  这我tm什么时候加的  又是AI自动补全
    }
}

void speechmanager::speech_draw()
{
    cout << "第" << this->m_index << "轮抽签正在进行中..." << endl;
    cout << "------------------" << endl;
    if (this->m_index == 1)
    {

        /*std::random_shuffle(this->pre_speaker.begin(), this->pre_speaker.end());
        C++17已经废弃了random_shuffle函数，可以使用shuffle函数来替代，下面是示例代码：
        */
        random_device rd;
        mt19937 g(rd());
        std::shuffle(this->pre_speaker.begin(), this->pre_speaker.end(), g);
        for (auto it : this->pre_speaker)
        {
            cout << "选手编号： " << it << " 选手姓名： " << this->m_speaker[it].m_name << endl;
        }
        cout << "------------------" << endl;
        system("pause");
    }
    else
    {
        random_device rd;
        mt19937 g(rd());
        std::shuffle(this->final_speaker.begin(), this->final_speaker.end(), g);
        for (auto it : this->final_speaker)
        {
            cout << "选手编号： " << it << " 选手姓名： " << this->m_speaker[it].m_name << endl;
        }
        cout << "------------------" << endl;
        system("pause");
    }
}

void speechmanager::start_speech()
{
    // 第一轮
    this->m_index = 1;  
    // 1.抽签
    this->speech_draw();
    // 2.比赛
    speech_contest();
    // 3.显示晋级结果
    this->show_score();
    // 第二轮
    this->m_index++;
    // 1.抽签
    this->speech_draw();
    // 2.比赛
    speech_contest(); // this->speech_contest() 也可以，this可以省略，因为没有同名成员变量，编译器不会混淆
    // 3.显示前三名结果
    this->show_victor();
    // 三.保存分数到文件中
    this->save_score();

    cout << "本届比赛结束！" << endl;  
    system("pause");
    system("cls"); // 清屏，准备下一轮比赛
}

void speechmanager::speech_contest()
{

    cout << "第" << this->m_index << "轮比赛正在进行中..." << endl;

    multimap<double, int, greater<int>> groupscore;     

    int num = 0; // 记录比赛人数

    vector<int> v;
    if (this->m_index == 1) // 这里的this可以省略，因为没有同名成员变量，编译器不会混淆
    {
        v = pre_speaker; // this可以省略
    }
    else
    {
        v = final_speaker;
    }
    // 遍历所有选手比赛
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 评委打分
        deque<double> d;
        num++;
        for (int i = 0; i < 10; i++)
        {
            double score = (rand() % 401 + 600) / 10.f;
            // cout << score << " ";   打印每个评委的分数，测试用
            d.push_back(score);
        }

        sort(d.begin(), d.end(), greater<double>()); // 从大到小排序
        d.pop_front();                               // 删除最高分
        d.pop_back();                                // 删除最低分

        double sum = accumulate(d.begin(), d.end(), 0.0);      // 求和   最好是0.0 而不是0，因为如果是0的话，结果会被当成整数，最终结果会被截断成整数，导致精度丢失。
        double avg = sum / (d.size() * 1.0);                   // 求平均分
        this->m_speaker[*it].m_score[this->m_index - 1] = avg; // 将平均分存储到选手的score数组中

        groupscore.insert(make_pair(avg, *it)); // 将平均分和选手编号存储到multimap中，自动排序
        if (num % 6 == 0)
        {
            cout << "第" << num / 6 << "组比赛名次：" << endl;
            for (auto it : groupscore)
            {
                cout << "选手编号： " << it.second << " 选手姓名： " << this->m_speaker[it.second].m_name << " 平均分： " << it.first << endl;
            }

            // 根据平均分从大到小排序，选出前3名晋级
            for (multimap<double, int, greater<double>>::iterator it = groupscore.begin(); it != groupscore.end(); it++)    
            {
                if (this->m_index == 1)
                {
                    if (this->final_speaker.size() < 6) // 第一轮晋级6人
                    {
                        this->final_speaker.push_back(it->second);
                    }
                }
                else
                {
                    if (this->win_speaker.size() < 3)
                    {
                        this->win_speaker.push_back(it->second);
                    }
                }
            }
            groupscore.clear(); // 清空multimap，准备下一组比赛
            system("pause");
        }
    }

    cout << "------------第" << this->m_index << "轮比赛结束！------------" << endl;
    system("pause");
};

void speechmanager::show_score()
{
    cout << "------------第" << this->m_index << "轮比赛成绩如下：------------" << endl;
    vector<int> v;
    if (this->m_index == 1)
    {
        v = pre_speaker;
    }
    else
    {
        v = final_speaker;
    }
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "选手编号： " << *it << " 选手姓名： " << this->m_speaker[*it].m_name << " 平均分： " << this->m_speaker[*it].m_score[this->m_index - 1] << endl;
    }
    cout << "---------------------------------------------" << endl;
    system("pause");
    system("cls"); // 清屏，准备下一轮比赛
    // this->show_menu();    不需要在这里调用菜单，因为在main函数中已经调用了菜单，这里只需要清屏就可以了，准备下一轮比赛
};
void speechmanager::show_victor() {
    cout << "------------本届比赛前三名如下：------------" << endl;
    for (vector<int>::iterator it = win_speaker.begin(); it != win_speaker.end(); it++)
    {
        cout << "选手编号： " << *it << " 选手姓名： " << this->m_speaker[*it].m_name << " 平均分： " << this->m_speaker[*it].m_score[1] << endl;
    }
    cout << "---------------------------------------------" << endl;
    system("pause");
};
void speechmanager::save_score() {
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);    //用追加方式写文件

    for (vector<int>::iterator it = win_speaker.begin(); it != win_speaker.end();it++)
    {
        ofs << *it << "," << this->m_speaker[*it].m_score[1] << ",";
    }
    ofs <<endl;
    ofs.close();
};