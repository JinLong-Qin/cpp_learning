#include <iostream>
using namespace std;

int main(){
	
	// ָ��
	cout << "sizeof(int *):" << sizeof(int *) << endl;
	cout << "sizeof(float *):" << sizeof(float *) << endl;
	cout << "sizeof(double *):" << sizeof(double *) << endl;
	cout << "sizeof(char *):" << sizeof(char *) << endl;
	
	
	// 32λϵͳ�£�����ָ�붼ռ��4���ֽ�
	// 64λϵͳ�£�����ָ�붼ռ��8���ֽ�
	
	
	// ��ָ�룬ָ���ڴ���Ϊ0��
	// ��;һ��Ϊ��ʼ��ָ��
	//int *p = NULL;
	
	//cout << p << endl;
	// 0-255��ַ�µ��ڴ���ϵͳռ���ڴ棬�������û������޸�
	
	// Ұָ�룬ָ��Ƿ����ڴ��ַ
	// ����ָ���˷��Լ�����ĵ�ַ��ֻ�ܹ������Լ�������ڴ��ַ
	//int * ppp = (int *)0x1100;
	
	//cout << *ppp << endl;
	
	
	//! const ����ָ�룬��const��λ�ú�˭���ý�����������˭
	// const��*֮ǰ�������޸�ָ��ָ������ݣ�ʵ������������ʹ��*pȥ�޸�ֵ
	// const��*֮�󣬲����޸�ָ�뱾��
	/*
	1. const����ָ�� --- ����ָ��
	2. const���γ��� --- ָ�볣��
	3. const������ָ�������γ��� 
	*/
	
	/*
	int a = 10;
	int b = 20;
	int * pp = &a;
	// 1. const����ָ�� --- ����ָ��  const������int ָ��ָ���ֵ�����Ըģ�����ָ���ָ����Ը�
	const int * pp1 = &a;
	// ��
	pp1 = &b; // �ǿ��Ե�
	*pp1 = 20; // �����ԣ���Ϊ������*p�Ĳ���������a=20;���ǿ��Ե�
	
	// 2. const���γ��� --- ָ�볣�� const������p  ָ���ָ�򲻿��Ըģ�����ָ��ָ���ֵ���Ը�
	int * const pp2 = &a;
	*pp2 = 20; // ����
	pp2 = &b; // ������
	
	
	// 3. const������ָ�������γ��� ���������ͨ��*pȥ�޸�ֵ��Ҳ�������޸�ָ��ָ��
	const int * const pp3 = &a;
	pp3 = &b; //����
	*pp3 = 20; //����
	*/
	
	
	// �����ָ��
	int arr[3] = {1, 2, 3};
	//int * p = arr;
	cout << *arr << endl;
	
	

	system("pause");
	return 0;

	
}
