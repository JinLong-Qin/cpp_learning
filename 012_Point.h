#pragma once // ���д��뱣ֻ֤����һ�� ��ֹ�ļ��ظ�����
#include <iostream>

using namespace std;

//! ��ͷ�ļ��У��������еĳ�Ա������ֻҪ ����
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
