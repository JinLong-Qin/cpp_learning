#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;
//类模板
// 当涉及到多个数据格式的时候，使用逗号分隔开
template<class NameType, class AgeType> 
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->mName = name;
		this->mAge = age;
	}
	void showPerson()
	{
		cout << "name: " << this->mName << " age: " << this->mAge << endl;
	}
public:
	NameType mName;
	AgeType mAge;
};
void test01()
{
	// 指定NameType 为string类型，AgeType 为 int类型
	Person<string, int>P1("孙悟空", 999);
	P1.showPerson();
}

// 类模板和函数模板的区别
template<class NameType, class AgeType = int> 
class Person1
{
public:
	Person1(NameType name, AgeType age)
	{
		this->mName = name;
		this->mAge = age;
	}
	void showPerson()
	{
		cout << "name: " << this->mName << " age: " << this->mAge << endl;
	}
public:
	NameType mName;
	AgeType mAge;
};
//1、类模板没有自动类型推导的使用方式
void test02()
{
	// Person p("孙悟空", 1000); // 错误 类模板使用时候，不可以用自动类型推导;必须要显示的指出数据类型
	Person1 <string ,int>p("孙悟空", 1000); //必须使用显示指定类型的方式，使用类模板
	p.showPerson();
}
//2、类模板在模板参数列表中可以有默认参数
void test03()
{
	Person1 <string> p("猪八戒", 999); //类模板中的模板参数列表 可以指定默认参数；第二个参数给了默认是int类型，所以这样写也不会报错
	p.showPerson();
}


// 类模板中，成员函数创建时间
class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};
class Person3
{
public:
	void showPerson3()
	{
		cout << "Person3 show" << endl;
	}
};
template<class T>
class MyClass
{
public:
	T obj;
	//类模板中的成员函数，并不是一开始就创建的，而是在模板调用时再生成
	void fun1() { obj.showPerson2(); }
	void fun2() { obj.showPerson3(); } 
};
void test04()
{
	MyClass<Person2> m;
	
	m.fun1();
	// m.fun2();//编译会出错，说明[函数调用才会去创建成员函数] 因为showPerson3是person3的方法，但是实例化的时候给定的是person2类，所以会报错
}


// 类模板作为函数参数
//类模板
template<class NameType, class AgeType = int> 
class Person4
{
public:
	Person4(NameType name, AgeType age)
	{
		this->mName = name;
		this->mAge = age;
	}
	void showPerson()
	{
		cout << "name: " << this->mName << " age: " << this->mAge << endl;
	}
public:
	NameType mName;
	AgeType mAge;
};
//1、指定传入的类型  最常用也最直观
void printPerson1(Person<string, int> &p) // 直接在参数小括号中，将具体的类型写出来
{
	p.showPerson();
}
void test05()
{
	Person <string, int >p("孙悟空", 100);
	printPerson1(p);
}
//2、参数模板化
template <class T1, class T2>
void printPerson2(Person<T1, T2>&p)
{
	p.showPerson();
	cout << "T1的类型为： " << typeid(T1).name() << endl;
	cout << "T2的类型为： " << typeid(T2).name() << endl;
}
void test06()
{
	Person <string, int >p("猪八戒", 90);
	printPerson2(p);
}
//3、整个类模板化
template<class T>
void printPerson3(T & p)
{
	cout << "T的类型为： " << typeid(T).name() << endl;
	p.showPerson();
}
void test07()
{
	Person <string, int >p("唐僧", 30);
	printPerson3(p);
}

int main() {
	test01();
    // 类模板
    // 建立一个通用类，类中的成员 数据类型可以不具体制定，用一个虚拟的类型来代表。

    /*
    类模板与函数模板区别主要有两点：
    1. 类模板没有自动类型推导的使用方式；只有显示的，没有隐式类型推导
    2. 类模板在模板参数列表中可以有默认参数
    */

    test02();
    test03();

    // 类模板中成员函数创建时机
    // 类模板中成员函数和普通类中成员函数创建时机是有区别的：
    // ● 普通类中的成员函数一开始就可以创建
    // ● 类模板中的成员函数在调用时才创建
    test04();


    // 类模板对象做函数参数
    // 一共有三种传入方式：
    // 1. 指定传入的类型   --- 直接显示对象的数据类型
    // 2. 参数模板化           --- 将对象中的参数变为模板进行传递
    // 3. 整个类模板化       --- 将这个对象类型 模板化进行传递

    test05();
    test06();
    test07();

    return 0;
}