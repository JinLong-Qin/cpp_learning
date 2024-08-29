#include <iostream>
using namespace std;

// 1.默认参数
//1.1 如果某个位置参数有默认值，那么从这个位置往后的参数，必须都要有默认值
int func(int a, int b = 10, int c = 10) {
	return a + b + c;
}

//1.2. 函数声明和实现，只能有一个有默认参数，不能同时有默认参数
int func2(int a = 10, int b = 10);
int func2(int a, int b) {
	return a + b;
}


// 2.函数占位参数
// 写一个数据类型来占位，
void func3(int a, int){
	cout << "占位参数" << endl;
}
// 占位参数可以有默认值
void func4(int a, int = 10){
	cout << "占位参数给定默认值" << endl;
}

// 3.函数重载
void func5()
{
	cout << "func 的调用！" << endl;
}
void func5(int a)
{
	cout << "func (int a) 的调用！" << endl;
}
void func5(double a)
{
	cout << "func (double a)的调用！" << endl;
}
void func5(int a ,double b)
{
	cout << "func (int a ,double b) 的调用！" << endl;
}
void func5(double a ,int b)
{
	cout << "func (double a ,int b)的调用！" << endl;
}

// 引用作为函数重载的参数
void func6(int &a)
{
	cout << "func (int &a) 调用 " << endl;
}

void func6(const int &a)
{
	cout << "func (const int &a) 调用 " << endl;
}

// 函数重载碰到默认函数
void func7(int a, int b = 10)
{
	cout << "func2(int a, int b = 10) 调用" << endl;
}

void func7(int a)
{
	cout << "func2(int a) 调用" << endl;
}

int main(){
	
	// 函数
	// 1. 函数默认参数
	cout << "ret = " << func(20, 20) << endl;
	cout << "ret = " << func2(100) << endl;
	
	// 2. 函数占位参数
	// 尽管占位参数没有变量名，但是也必须给传递参数
	func3(10, 10);
	// 如果设置了默认参数，则可以不用传递参数
	func4(10);
	
	// 3. 函数重载
	// 条件
	/*
	 * 1. 同一作用域
	 * 2. 函数名称相同
	 * 3. 函数参数类型不同，或者个数不同，或者顺序不同
	 * */
	func5();
	func5(10);
	func5(3.14);
	func5(10,3.14);
	func5(3.14 , 10);
	
	// 3.1 函数重载的注意事项
	// 3.1.1 引用作为重载的参数
	int a = 10;
	func6(a); // 会调用func6(int &a)
	// 如何调用func6(const int &a)呢
	func6(10); // 传入字面量，
	// 这是由于，当传入字面量的时候，func6(int &a)相当于 int &a = 10;这是不合法的
	// 但是func6(const int &a)中相当于，const int &a = 10; 这是合法的
	
	// 3.1.2 函数重载碰到默认参数
	//func7(10); // 这里函数func7中的参数b给了默认值，所以编译器无法识别调用哪一个func7，故此会出现问题
	// 解决办法就在函数重载的时候，避免使用产生二义性的默认参数
	
	system("pause");
	return 0;
}
