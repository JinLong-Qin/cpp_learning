#include <iostream>
using namespace std;

int main(){
	
	// 指针
	cout << "sizeof(int *):" << sizeof(int *) << endl;
	cout << "sizeof(float *):" << sizeof(float *) << endl;
	cout << "sizeof(double *):" << sizeof(double *) << endl;
	cout << "sizeof(char *):" << sizeof(char *) << endl;
	
	
	// 32位系统下，所有指针都占用4个字节
	// 64位系统下，所有指针都占用8个字节
	
	
	// 空指针，指向内存编号为0的
	// 用途一般为初始化指针
	//int *p = NULL;
	
	//cout << p << endl;
	// 0-255地址下的内存是系统占用内存，不允许用户进行修改
	
	// 野指针，指向非法的内存地址
	// 即，指向了非自己申请的地址，只能够操纵自己申请的内存地址
	//int * ppp = (int *)0x1100;
	
	//cout << *ppp << endl;
	
	
	//! const 修饰指针，看const的位置和谁挨得近，就是限制谁
	// const在*之前，不能修改指针指向的数据，实际上是限制了使用*p去修改值
	// const在*之后，不能修改指针本身
	/*
	1. const修饰指针 --- 常量指针
	2. const修饰常量 --- 指针常量
	3. const既修饰指针又修饰常量 
	*/
	
	/*
	int a = 10;
	int b = 20;
	int * pp = &a;
	// 1. const修饰指针 --- 常量指针  const修饰了int 指针指向的值不可以改，但是指针的指向可以改
	const int * pp1 = &a;
	// 则
	pp1 = &b; // 是可以的
	*pp1 = 20; // 不可以，因为限制了*p的操作，但是a=20;还是可以的
	
	// 2. const修饰常量 --- 指针常量 const修饰了p  指针的指向不可以改，但是指针指向的值可以改
	int * const pp2 = &a;
	*pp2 = 20; // 可以
	pp2 = &b; // 不可以
	
	
	// 3. const既修饰指针又修饰常量 则既限制了通过*p去修改值，也限制了修改指针指向
	const int * const pp3 = &a;
	pp3 = &b; //错误
	*pp3 = 20; //错误
	*/
	
	
	// 数组和指针
	int arr[3] = {1, 2, 3};
	//int * p = arr;
	cout << *arr << endl;
	
	

	system("pause");
	return 0;

	
}
