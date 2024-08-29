#include <iostream>
#include <string>

using namespace std;

// 引用做函数参数
//1. 值传递
void mySwap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

//2. 地址传递
void mySwap02(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//3. 引用传递
void mySwap03(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}


// 引用作为函数返回值
// 1.不要返回局部变量引用
// 其原理和不要返回局部变量的地址一样
// 局部变量存储在栈区，由编译器决定其生命周期，当函数执行完毕，局部变量会被完全释放
/* warning: reference to local variable 'a' returned [-Wreturn-local-addr]
int& test01() {
	int a = 10; //局部变量
	return a;
}
*/
// 2. 函数的调用可以作为左值
// 返回静态变量引用
// 静态变量保存在全局区，当程序执行完毕后才会被释放，
int& test02() {
	static int a = 20;
	return a;
}


// 使用const修饰引用形参，来确保形参的修改不会影响到实参的值
void showValue(const int& v) {
	//v += 10; // 增加了const之后，v的值将不再可以被修改; 如果没有const，函数中的v进行修改也会影响到main函数中的v
	cout << v << endl;
}


int main(){
	
	// 引用
	//! 其本质是一个指针常量，即指针是一个常量，其指向不可以修改，但是指针指向的数据是可以修改的
	// 数据类型 &别名 = 变量原名
	int a = 10;
	int &b = a;
	
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	
	b = 100;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	
	//! 1.要注意引用一旦被声明，就必须初始化
	// int &c; // 出错
	
	//! 2. 一旦被初始化，就不可以再进行修改
	// c = 20;
	// b = c; // 出错， 初始化之后不可以再进行修改
	
	
	// --------
	// 引用做函数参数可以实现地址传递类似的结果
	int c = 10;
	int d = 20;

	mySwap01(c, d); // 值传递，形参不会影响到实参
	cout << "c:" << c << " d:" << d << endl;

	mySwap02(&c, &d); // 地址传递，形参的改变会影响到实参
	cout << "c:" << c << " d:" << d << endl;

	mySwap03(c, d); // 引用传递，形参的改变同样会影响实参
	cout << "c:" << c << " d:" << d << endl;

	
	// 引用做函数返回值
	//不能返回局部变量的引用
	//int& ref = test01();
	//cout << "ref = " << ref << endl;

	//如果函数做左值，那么必须返回引用
	// 返回的是一个引用，因此现在ref2相当于是一个别名
	// test02()返回的值和ref2互为别名，满足上述别名的特性，即修改一个另一个也会跟着进行修改
	int& ref2 = test02();
	cout << "ref2 = " << ref2 << endl;

	ref2 = 30;
	cout << "ref2 = " << ref2 << endl;
	// 所以现在ref
	test02() = 1000;

	cout << "ref2 = " << ref2 << endl;
	
	
	//! 常量引用
	// 其本质为常量指针常量，不能改变引用的指向，也不能改变引用单元中的内容 const * const
	// 主要作用为修饰形参，防止误操作
	// 即在形参列表中增加const修饰形参，防止形参改变实参
	// 引用占用的内存比
	
	/*
	// int & ref = 10; // 会报错，因为引用必须引用一个合法的地址，而10是一个整型字面量，不是地址，所以会报错
	
	// 通过增加const
	const int & ref = 10; // 这里编译器会先将代码修改为 int temp = 10; const int & ref = temp;
	ref = 20; // 会报错，因为ref增加了const之后，就不可修改了
	*/
	
	int v = 100;
	showValue(v);
	
	system("pause");
	return 0;
}
