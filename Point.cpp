//
// Created by 47551 on 2024/8/21.
//

#include "Point.h"

// ��ʵ�ֵ�Դ�ļ��У���class, public, private��ص�����ȫ��ɾ����!ֻ����������ʵ��
//! ���ں�����ǰ����Point:: ��ʾ����Point�������µĺ���
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
