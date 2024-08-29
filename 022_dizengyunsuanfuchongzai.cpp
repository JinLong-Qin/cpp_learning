#include <iostream>

using namespace std;

// 定义整型类
class MyInteger {

    // 为了让重载的<<运算符可以访问私有属性，使用友元
	friend ostream& operator<<(ostream& out, MyInteger myint);

public:
	MyInteger() {
		m_Num = 0;
	}
	//前置++
    // ++操作是可以链式操作的，所以设置为引用返回
	MyInteger& operator++() {
		//先++
		m_Num++;
		//再返回
		return *this; // 这样返回的MyInteger是同一个，操作的时候是同一个对象
	}

	//后置++
	MyInteger operator++(int) { // 使用占位参数，用于区分前置还是后置递增，编译器规定的，只能是int
		//先返回
		MyInteger temp = *this; //记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
		m_Num++;
		return temp;
	}

private:
	int m_Num;
};


ostream& operator<<(ostream& out, MyInteger myint) {
	out << myint.m_Num;
	return out;
}


//前置++ 先++ 再返回
void test01() {
	MyInteger myInt;
	cout << ++myInt << endl;
	cout << myInt << endl;
}

//后置++ 先返回 再++
void test02() {

	MyInteger myInt;
	cout << myInt++ << endl;
	cout << myInt << endl;
}

int main(){
    // 运算符重载
    // 对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
	// 总结1：对于[内置的数据类型]的表达式的的运算符是不可能改变的
    
    // 递增运算符重载
    test01();
	//test02();

    // system("pause");
    return 0;
}