//
// Created by 47551 on 2024/8/21.
//

#ifndef _CPP_POINT_H
#define _CPP_POINT_H

#endif //_CPP_POINT_H

#pragma once // 这行代码保证只引入一次 防止文件重复包含
#include <iostream>

using namespace std;

//! 在头文件中，所有类中的成员函数都只要 声明
class Point{
public:
    int get_X();

    int get_Y();

    void set_X(int x);

    void set_Y(int y);
private:
    int m_x;
    int m_y;
};
