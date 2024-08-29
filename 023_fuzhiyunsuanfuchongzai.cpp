#include <iostream>

using namespace std;

class Person
{
public:

	Person(int age)
	{
		//将年龄数据开辟到堆区
		m_Age = new int(age);
	}

	//重载赋值运算符 
    // 返回值设置为引用形式，进而实现连等操作
	Person& operator=(Person &p)
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		//编译器提供的代码是浅拷贝
		//m_Age = p.m_Age;

		//提供深拷贝 解决浅拷贝的问题
		m_Age = new int(*p.m_Age);

		//返回自身
		return *this;
	}

    // 对象在运行接收后通过调用析构函数释放内存
	~Person()
	{
		if (m_Age != NULL) // 堆区的内存是程序员申请，程序员释放
		{
			delete m_Age;
			m_Age = NULL;
		}
	}

	//年龄的指针
	int *m_Age;

};


void test01()
{
	Person p1(18);

	Person p2(20);

	Person p3(30);

	p3 = p2 = p1; //赋值操作

	cout << "p1的年龄为：" << *p1.m_Age << endl;

	cout << "p2的年龄为：" << *p2.m_Age << endl;

	cout << "p3的年龄为：" << *p3.m_Age << endl;
}

int main() {

    // 运算符重载
    // 对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
	// 总结1：对于[内置的数据类型]的表达式的的运算符是不可能改变的
    
    // 赋值运算符重载

	test01();


    
	//int a = 10;
	//int b = 20;
	//int c = 30;

	//c = b = a; // 内置数据类型可以实现连等
	//cout << "a = " << a << endl;
	//cout << "b = " << b << endl;
	//cout << "c = " << c << endl;

	system("pause");

	return 0;
}