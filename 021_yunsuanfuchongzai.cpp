#include <iostream>

using namespace std;

class Person {
	friend void test();
	friend Person operator+(const Person& p2, int val);
	friend ostream& operator<<(ostream& out, Person& p);
public:
	Person() {};
	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}
	//成员函数实现 + 号运算符重载
    // 参数使用引用方式，可以节约内存
	Person operator+(const Person& p) {
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}
    // 本质上调用方法的时候是


// public:
// 	int m_A;
// 	int m_B;
private: // 类中的属性一般都要设置为私有，操作符重载操作，要使用友元
	int m_A;
	int m_B;
};

//全局函数实现 + 号运算符重载
//Person operator+(const Person& p1, const Person& p2) {
//	Person temp(0, 0);
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}

//运算符重载 可以发生函数重载 
Person operator+(const Person& p2, int val)  
{
	Person temp;
	temp.m_A = p2.m_A + val;
	temp.m_B = p2.m_B + val;
	return temp;
}

void test() {

	Person p1(10, 10);
	Person p2(20, 20);

	// 由于operator+的存在，其调用方式可以简化为直接相加
	Person p3 = p2 + p1;  //相当于 p2.operaor+(p1)
    // 对于成员函数的实现方式，其本质调用是 p2.operaor+(p1)
    // 全局函数的实现方式其本质调用是      operaor(p1, p2)
    // 这是由于全局函数无法使用this指针的缘故
	cout << "mA:" << p3.m_A << " mB:" << p3.m_B << endl;


	Person p4 = p3 + 10; //相当于 operator+(p3,10)
	cout << "mA:" << p4.m_A << " mB:" << p4.m_B << endl;

}

// 左移运算符重载
//全局函数实现左移重载
//ostream对象只能有一个 输出流对象
ostream& operator<<(ostream& out, Person& p) {
	out << "a:" << p.m_A << " b:" << p.m_B;
	return out; // 返回一个输出流对象，保证能够连续的调用 << 进行输出，链式编程思想
}

void test01(){
	Person p1(10, 20);
	cout << p1 << "hello world" << endl; //链式编程
}

int main(){
    // 运算符重载
    // 对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
	// 总结1：对于[内置的数据类型]的表达式的的运算符是不可能改变的
    
    // 加号重载
	test();

	// 左移运算符重载  输出流
	test01();

    // system("pause");
    return 0;
}