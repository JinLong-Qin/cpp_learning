#include<iostream>
#include <string>
using namespace std;
//#include "person.h"
// #include "039_person.cpp" //解决方式1，包含cpp源文件 不常用
//解决方式2，将声明和实现写到一起，文件后缀名改为.hpp 
#include "039_person.hpp"

// person.h
// template <class T1, class T2>
// class Person{
//     public:
//         Person(T1 name, T2 age);

//         void showPerson();

//         T1 name;
//         T2 age;
// };

// person.cpp
// template<class T1, class T2>
// Person<T1, T2>::Person(T1 name, T2 age){
//     this->name = name;
//     this->age = age;
// }

// template<class T1, class T2>
// void Person<T1, T2>::showPerson(){
//     cout << this->name << "  " << this->age << endl;
// }




void test01()
{
	Person<string, int> p("Tom", 10);
	p.showPerson();
}
int main() {
	test01();

    // 类模板的分文件编写
    // 类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到 
    // 之前的类分写都是不带模板的， 类中的函数实现不会有变化，在编译的时候就已经确定了，所以引用的是.h文件，但是类模板分文件编写不可以
    /*
    解决办法
    1. 直接包含.cpp源文件
    2.将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制
     .hpp 文件都是类模板
    */


    return 0;
}