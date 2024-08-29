#include <iostream>
#include <string>

using namespace std;


// new申请内存保存数据
int * func(){
	// 要避免手动返回局部变量的地址，因为局部变量保存在栈区，由编译器决定其生命周期
	// 即，在函数运行结束后会自动销毁局部变量
	//int a = 10;
	//int * p1 = &a;
	
	// 使用new关键字申请地址保存数据，可以将数据保存在堆区
	//! new返回的是对应数据类型的指针
	// 堆区中的内存由程序员进行申请和释放
	// 使用new关键字创建的局部变量的地址可以被返回
	//! 要注意的是，这个指针p本质上也是局部变量，它保存在栈上，
	//! 但是其保存的数据10是保存在堆区的，不会被编译器销毁
	int * p = new int(10);
	return p;
}

// 使用new申请内存保存数组
void funcArray(){
	// 创建数组要使用中括号
	// 返回的是数组的首地址
	int * arr = new int[10]; // 10表示数组有10个元素
	
	for(int i=0; i<10; i++){
		arr[i] = i;
	}
	
	for(int i=0; i<10; i++){
		cout << arr[i] << endl;
	}
	
	// 使用delete释放数组，释放的时候要加中括号，不然就只会释放arr这个首地址
	delete[] arr;
}

int main(){
	
	// 使用new关键字申请的局部变量的地址 
	int * p = func();
	cout << *p << endl;
	
	// ------------------------------------
	// 使用new在堆区中申请内存
	
	// 堆区的数据由程序员进行管理开辟和释放
	// 使用delete关键字释放内存
	delete p;
	cout << *p << endl;
	
	
	// 使用new申请地址保存数组
	funcArray();
	
	
	
	system("pause");
	return 0;
}
