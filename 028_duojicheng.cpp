#include <iostream>
#include <string>

using namespace std;

class Base1 {
public:
	Base1()
	{
		m_A = 100;
	}
public:
	int m_A;
};

class Base2 {
public:
	Base2()
	{
		m_A = 200;  // 两个父类中同样都是m_A的名称，所以在子类中会出现意义不明确的问题
	}
public:
	int m_A;
};

//语法：class 子类：继承方式 父类1 ，继承方式 父类2 
class Son : public Base2, public Base1 
{
public:
	Son()
	{
		m_C = 300;
		m_D = 400;
	}
public:
	int m_C;
	int m_D;
};


//多继承容易产生成员同名的情况
//通过使用类名作用域可以区分调用哪一个基类的成员
void test01()
{
	Son s;
	cout << "sizeof Son = " << sizeof(s) << endl;
	cout << s.Base1::m_A << endl;
	cout << s.Base2::m_A << endl;
}

int main() {

    // 多继承
    // 语法：class 子类 ：继承方式 父类1 ， 继承方式 父类2...
    // 要注意：多继承可能会引发父类中有同名成员出现，需要加作用域区分，
    // 正是由于存在这样的问题，所以实际开发中很少使用
    
	test01();



	system("pause");
	return 0;
}
