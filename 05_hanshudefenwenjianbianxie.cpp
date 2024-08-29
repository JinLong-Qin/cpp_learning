#include <iostream>
using namespace std;

#include "05_swap.h"
int main(){
	// 函数的分文件编写
	/*
	1. 创建.h的头文件，用于保存函数的声明
	2. 创建.cpp的源文件，用于保存函数的定义
	3. 在代码文件中引入.h的头文件
	* 
	* 
	* 
	* 编译指令应该为： gcc -o output main.cpp head.cpp   其中head.cpp是分写函数的源文件，即上面步骤中第二步的文件
	* 具体到本个文件，即：gcc -o 05_hanshudefenwenjianbianxie 05_hanshudefenwenjianbianxie.cpp 05_swap.cpp 
	*/
	int num1 = 10;
	int num2 = 33;
	
	cout << summ(num1, num2) << endl;
	
	
	system("pause");
	return 0;
}
