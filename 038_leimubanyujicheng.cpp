#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

template<class T>
class Base
{
	T m;
};
//class Son:public Base  //错误，c++编译需要给子类分配内存，必须知道父类中T的类型才可以向下继承
// 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
class Son :public Base<int> //必须指定一个类型
{
};
void test01()
{
	Son c;
}

// 如果想灵活指定出父类中T的类型，子类也需变为类模板
//类模板继承类模板 ,可以用T2指定父类中的T类型
template<class T1, class T2>
class Son2 :public Base<T2>
{
public:
	Son2()
	{
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
};
void test02()
{
	Son2<int, char> child1;
}

// 成员函数的类外实现
//类模板中成员函数类外实现
template<class T1, class T2>
class Person {
public:
	//成员函数类内声明
	Person(T1 name, T2 age);
	void showPerson();
public:
	T1 m_Name;
	T2 m_Age;
};
//构造函数 类外实现
// 要将构造函数写成模板函数，首先要增加作用域Person：：，并增加尖括号以表示这是一个模板类型的类外实现<T1, T2>
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	this->m_Name = name;
	this->m_Age = age;
}
//成员函数 类外实现
// 增加尖括号的参数列表表示是一个类模板的类外实现
template<class T1, class T2>
void Person<T1, T2>::showPerson() {
	cout << "姓名: " << this->m_Name << " 年龄:" << this->m_Age << endl;
}
void test03()
{
	Person<string, int> p("Tom", 20);
	p.showPerson();
}

int main() {
	test01();
	test02();

    // 类模板与继承
    /*
    当类模板碰到继承时，需要注意一下几点：
    ● 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
    ● 如果不指定，编译器无法给子类分配内存
    ● 如果想灵活指定出父类中T的类型，子类也需变为类模板
    */

    // 成员函数的类外实现
    // 类模板中成员函数类外实现时，需要加上模板参数列表
    test03();
    return 0;
}