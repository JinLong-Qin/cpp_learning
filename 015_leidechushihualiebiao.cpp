#include <iostream>

using namespace std;


class Person{
	public:
	
		// ��ͳ�ĳ�ʼ������
		/*
		Person(int a, int b, int c){
			p_a = a;
			p_b = b;
			p_c = c;
			cout << "�вι��캯��" << endl;
		}
		*/
		
		// ��ʼ���б�
		// ��ʾp_a������a���г�ʼ�� ..
		// ���캯��()������1(ֵ1),����2��ֵ2��... {}
		Person(int a, int b, int c): p_a(a), p_b(b), p_c(c) {}
		
		int p_a;
		int p_b;
		int p_c;
};

void test01(){
	Person p(10, 20, 30); 
	// ������ʼ�����൱�ڽ�10 ���ݸ���a��20 ���ݸ���b�� 30���ݸ���c��Ȼ��ͨ���вι��캯�������Խ����˳�ʼ��
	
	cout << "p_a  " << p.p_a;
	cout << "p_b  " << p.p_b;
	cout << "p_c  " << p.p_c << endl;
	
}

int main(){
	
	// ��ʼ���б����ڳ�ʼ�����е�����
	// �﷨ ���캯��()������1(ֵ1),����2��ֵ2��... {}
	
	test01();
	
	system("pause");
	return 0;
}
