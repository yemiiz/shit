#pragma once
#include <vector>
#include <map>
#include "speaker.h"
// 设置演讲管理类
class speechmanager
{
public:
    //第一轮选手
    std::vector<int> pre_speaker;
    //晋级选手
    std::vector<int> final_speaker;
    //前三名选手
    std::vector<int> win_speaker;
    //选手编号和选手对象的映射
    std::map<int, speaker> m_speaker;
    //初始化数据
    int m_index;
    void init_speech(); 
    // 构造函数
    speechmanager();
    // 菜单
    void show_menu();
    void exit_system();
    //创建选手
    void create_speaker();
    // 析构函数
    ~speechmanager();
};