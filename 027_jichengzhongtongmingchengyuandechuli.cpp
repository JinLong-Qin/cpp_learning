#include <iostream>

using namespace std;

class Base01 {
public:
	Base01()
	{
		m_A = 100;
	}

	void func()
	{
		cout << "Base - func()调用" << endl;
	}

	void func(int a)
	{
		cout << "Base - func(int a)调用" << endl;
	}

public:
	int m_A;
};


class Son01 : public Base01 {
public:
	Son01()
	{
		m_A = 200;
	}

	//当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数
	//如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
	void func()
	{
		cout << "Son - func()调用" << endl;
	}
public:
	int m_A;
};

void test()
{
	Son01 s;

    // 使用子类对象调用父类成员，属性和方法要加[父类作用域]的限制
	cout << "Son01下的m_A = " << s.m_A << endl;
	cout << "Base01下的m_A = " << s.Base01::m_A << endl;

	s.func();
	s.Base01::func();
	s.Base01::func(10);

}

// 静态成员继承的操作
class Base {
public:
	static void func()
	{
		cout << "Base - static void func()" << endl;
	}
	static void func(int a)
	{
		cout << "Base - static void func(int a)" << endl;
	}

	static int m_A;
};

int Base::m_A = 100;

class Son : public Base {
public:
	static void func()
	{
		cout << "Son - static void func()" << endl;
	}
	static int m_A;
};

int Son::m_A = 200;

//同名静态成员属性
void test01()
{
	//通过对象访问
	cout << "通过对象访问： " << endl;
	Son s;
	cout << "Son  下 m_A = " << s.m_A << endl;
	cout << "Base 下 m_A = " << s.Base::m_A << endl;

	//通过类名访问
    // 这是由于静态成员不属于单独的对象，而属于类，所有的对象都共享同一份静态数据，所以可以使用类来直接访问
	cout << "通过类名访问： " << endl;
	cout << "Son  下 m_A = " << Son::m_A << endl;
	cout << "Base 下 m_A = " << Son::Base::m_A << endl;
}

//同名成员函数
void test02()
{
	//通过对象访问
	cout << "通过对象访问： " << endl;
	Son s;
	s.func();
	s.Base::func();

	cout << "通过类名访问： " << endl;
	Son::func();
	Son::Base::func();
	//出现同名，子类会隐藏掉父类中所有同名成员函数，需要加作作用域访问
	Son::Base::func(100);
}

int main() {

    // 继承中同名成员的处理
    /*
        访问子类同名成员   直接访问即可
        访问父类同名成员   需要加作用域
    */
    test();




    // 总结
    /*
    1. 子类对象可以直接访问到子类中同名成员
    2. 子类对象加作用域可以访问到父类同名成员
    3. 当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名函数
    */

    // 继承中同名的静态成员在子类对象中如何访问呢
    // 同非静态成员处理相同
    /*
        访问子类同名成员   直接访问即可
        访问父类同名成员   需要加作用域
    */

    test01();
    test02();

    system("pause");
    return 0;
}