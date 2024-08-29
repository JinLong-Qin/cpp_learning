#include <iostream>
using namespace std;

class Base
{
public:
	//纯虚函数
	//类中只要有一个纯虚函数就称为抽象类
	//抽象类无法实例化对象
	//子类必须重写父类中的纯虚函数，否则也属于抽象类
	virtual void func() = 0;
};

class Son :public Base
{
public:
	virtual void func() 
	{
		cout << "func调用" << endl;
	};
};

void test01()
{
	//! 多态就是让函数的接口更加通用化，使用一个父类的指针，通过实例化的对象不同，可以执行不同的函数
	Base * base = NULL;
	//base = new Base; // 错误，抽象类无法实例化对象
	base = new Son;
	base->func();
	delete base;//记得销毁
}


int main(){

    // 纯虚函数和抽象类
    // 在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
    // 因此可以将虚函数改为纯虚函数
    // 语法：virtual 返回值类型 函数名 （参数列表）= 0 ;
    // 当类中有了纯虚函数，这个类也称为[抽象类]

    // 抽象类特点：
    // 1. 无法实例化对象
    // 2. 子类必须重写抽象类中的纯虚函数，不然这个子类也是一个抽象类

	test01();

    return 0;
}