#pragma once // 这行代码保证只引入一次 防止文件重复包含
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
