#include <iostream>
using namespace std;

#include "05_swap.h"
int main(){
	// �����ķ��ļ���д
	/*
	1. ����.h��ͷ�ļ������ڱ��溯��������
	2. ����.cpp��Դ�ļ������ڱ��溯���Ķ���
	3. �ڴ����ļ�������.h��ͷ�ļ�
	* 
	* 
	* 
	* ����ָ��Ӧ��Ϊ�� gcc -o output main.cpp head.cpp   ����head.cpp�Ƿ�д������Դ�ļ��������沽���еڶ������ļ�
	* ���嵽�����ļ�������gcc -o 05_hanshudefenwenjianbianxie 05_hanshudefenwenjianbianxie.cpp 05_swap.cpp 
	*/
	int num1 = 10;
	int num2 = 33;
	
	cout << summ(num1, num2) << endl;
	
	
	system("pause");
	return 0;
}
