#include <iostream>
using namespace std;

// 1.Ĭ�ϲ���
//1.1 ���ĳ��λ�ò�����Ĭ��ֵ����ô�����λ������Ĳ��������붼Ҫ��Ĭ��ֵ
int func(int a, int b = 10, int c = 10) {
	return a + b + c;
}

//1.2. ����������ʵ�֣�ֻ����һ����Ĭ�ϲ���������ͬʱ��Ĭ�ϲ���
int func2(int a = 10, int b = 10);
int func2(int a, int b) {
	return a + b;
}


// 2.����ռλ����
// дһ������������ռλ��
void func3(int a, int){
	cout << "ռλ����" << endl;
}
// ռλ����������Ĭ��ֵ
void func4(int a, int = 10){
	cout << "ռλ��������Ĭ��ֵ" << endl;
}

// 3.��������
void func5()
{
	cout << "func �ĵ��ã�" << endl;
}
void func5(int a)
{
	cout << "func (int a) �ĵ��ã�" << endl;
}
void func5(double a)
{
	cout << "func (double a)�ĵ��ã�" << endl;
}
void func5(int a ,double b)
{
	cout << "func (int a ,double b) �ĵ��ã�" << endl;
}
void func5(double a ,int b)
{
	cout << "func (double a ,int b)�ĵ��ã�" << endl;
}

// ������Ϊ�������صĲ���
void func6(int &a)
{
	cout << "func (int &a) ���� " << endl;
}

void func6(const int &a)
{
	cout << "func (const int &a) ���� " << endl;
}

// ������������Ĭ�Ϻ���
void func7(int a, int b = 10)
{
	cout << "func2(int a, int b = 10) ����" << endl;
}

void func7(int a)
{
	cout << "func2(int a) ����" << endl;
}

int main(){
	
	// ����
	// 1. ����Ĭ�ϲ���
	cout << "ret = " << func(20, 20) << endl;
	cout << "ret = " << func2(100) << endl;
	
	// 2. ����ռλ����
	// ����ռλ����û�б�����������Ҳ��������ݲ���
	func3(10, 10);
	// ���������Ĭ�ϲ���������Բ��ô��ݲ���
	func4(10);
	
	// 3. ��������
	// ����
	/*
	 * 1. ͬһ������
	 * 2. ����������ͬ
	 * 3. �����������Ͳ�ͬ�����߸�����ͬ������˳��ͬ
	 * */
	func5();
	func5(10);
	func5(3.14);
	func5(10,3.14);
	func5(3.14 , 10);
	
	// 3.1 �������ص�ע������
	// 3.1.1 ������Ϊ���صĲ���
	int a = 10;
	func6(a); // �����func6(int &a)
	// ��ε���func6(const int &a)��
	func6(10); // ������������
	// �������ڣ���������������ʱ��func6(int &a)�൱�� int &a = 10;���ǲ��Ϸ���
	// ����func6(const int &a)���൱�ڣ�const int &a = 10; ���ǺϷ���
	
	// 3.1.2 ������������Ĭ�ϲ���
	//func7(10); // ���ﺯ��func7�еĲ���b����Ĭ��ֵ�����Ա������޷�ʶ�������һ��func7���ʴ˻��������
	// ����취���ں������ص�ʱ�򣬱���ʹ�ò��������Ե�Ĭ�ϲ���
	
	system("pause");
	return 0;
}
