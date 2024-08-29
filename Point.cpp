//
// Created by 47551 on 2024/8/21.
//

#include "Point.h"

// 在实现的源文件中，将class, public, private相关的内容全部删除，!只保留函数的实现
//! 并在函数名前增加Point:: 表示这是Point作用域下的函数
int Point::get_X(){
    return m_x;
}

int Point::get_Y(){
    return m_y;
}

void Point::set_X(int x){
    m_x = x;
}

void Point::set_Y(int y){
    m_y = y;
}
