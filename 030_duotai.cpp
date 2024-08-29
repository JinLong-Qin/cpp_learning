#include <iostream>

using namespace std;

class Animal
{
public:
	//Speak函数就是虚函数
	//函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了。
	virtual void speak() 
	{
		cout << "动物在说话" << endl;
	}
};

class Cat :public Animal
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};

class Dog :public Animal
{
public:

	void speak()
	{
		cout << "小狗在说话" << endl;
	}

};
//我们希望传入什么对象，那么就调用什么对象的函数
//如果函数地址在编译阶段就能确定，那么静态联编
//如果函数地址在运行阶段才能确定，就是动态联编

void DoSpeak(Animal & animal) //! 允许父子类之间的类型转换，因此可以父类的引用或者指针可以接收子类作为参数
{
	animal.speak(); 
    //! 如果animal类中的speak方法没有增加vitual，那么在编译前这个speak就知道了是哪一个函数体要执行，即地址早绑定，就会直接执行父类中的speak函数
    //! 如果在父类增加了virtual关键字，那么编译器就不会在编译的时候确定要执行的函数调用，会在执行的时候再具体确定执行哪一个函数，即地址晚绑定
}
//
//! 多态满足条件： 
//1、有继承关系
//2、子类重写父类中的虚函数  重写：返回值类型 函数名 参数列表 都完全相同
//! 多态使用：
//父类指针或引用指向子类对象

void test01()
{
	Cat cat;
	DoSpeak(cat);


	Dog dog;
	DoSpeak(dog);
}


	

int main(){

    // 多态，面向对象三大特性之一
    // 分两类:
    // 1. 静态多态: 函数重载 和 运算符重载属于静态多态，复用函数名
    // 2. 动态多态: 派生类和虚函数实现运行时多态
    /* 区别：
        静态多态的函数地址早绑定  -  编译阶段确定函数地址
        动态多态的函数地址晚绑定  -  运行阶段确定函数地址
    
    */

    test01();


    system("pause");
    return 0;
}
// 虚函数表指针，即函数指针的指针

// 当子类重写父类中的虚函数的时候，子类中的虚函数表就会将继承的父类中的虚函数表
// 当运行程序的时候，给入的对象是什么类，就会去类寻找这个调用的虚函数表中的地址，进而确定执行的代码体
// 这就是多态的本质