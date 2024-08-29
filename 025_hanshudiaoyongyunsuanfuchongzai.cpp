#include <iostream>
#include <string>

using namespace std;

class MyPrint
{
public:
    // 函数重载调用函数
	void operator()(string text)
	{
		cout << text << endl;
	}

};
void test01()
{
	//重载的（）操作符 也称为仿函数
	MyPrint myFunc;
	myFunc("hello world"); // 执行操作很想函数调用，所以才叫仿函数
}


class MyAdd
{
public:
    // 仿函数没有固定写法，形式十分灵活
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

void test02()
{
	MyAdd add;
	int ret = add(10, 10);
	cout << "ret = " << ret << endl;

	//匿名对象调用  
    // MyAdd()创建了一个匿名对象，(100, 100)传递参数
	cout << "MyAdd()(100,100) = " << MyAdd()(100, 100) << endl;
}

int main() {

    // 运算符重载
    // 对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
	// 总结1：对于[内置的数据类型]的表达式的的运算符是不可能改变的
    
    // 函数调用运算符重载
    // 由于重载后使用的方式非常像函数的调用，因此称为[仿函数]
    // 仿函数没有固定写法，非常灵活
	test01();

    test02();

	system("pause");

	return 0;
}