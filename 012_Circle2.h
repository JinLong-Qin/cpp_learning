#pragma once // ���д��뱣ֻ֤����һ�� ��ֹ�ļ��ظ�����
#include <iostream>

using namespace std;

#include "012_Point.h"

class Circle2{
	public:
		int get_R();
		
		void set_R(int r);
		
		Point getCenter();
		
		void setCenter(Point p);
		
	private:
		int m_r;
		Point m_center;
};
