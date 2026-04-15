#pragma once
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <random>
#include <deque>
#include <numeric>
#include <string>
#include <fstream>
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


    //比赛
    void start_speech();
    //抽签
    void speech_draw();
    //比赛
    void speech_contest();
    //展示成绩
    void show_score();
    void show_victor();
    //保存成绩
    void save_score();
    // 析构函数
    ~speechmanager();
};