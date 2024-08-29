#include <iostream>
using namespace std;

#include <cmath>
#include <algorithm>

int main(){
	
	// 数组，存放相同类型元素的集合。
	// 1. 每个元素都具有相同的数据类型
	// 2. 由连续的内存空间组成的
	
	// 定义方式
	// 1. 数据类型 数组名[数组长度];
	/*
	int arr0[5];
	arr0[0] = 0;
	arr0[1] = 1;
	arr0[2] = 2;
	arr0[3] = 3;
	arr0[4] = 4;
	*/
	// 2. 数据类型 数组名[数组长度] = {元素1, 元素2 ...};
	// int arr1[5] = {0, 1, 2, 3, 4};
	// 3. 数据类型 数组名[] = {元素1, 元素2 ...};
	int arr2[] = {0, 1, 2};
	
	
	//! 一维数组中数组名的作用
	// 1. 可以统计数组在内存中的长度
	cout << "数组占用内存空间为：" << sizeof(arr2) << endl;
	cout << "数组中每个元素占用内存空间为：" << sizeof(arr2[0]) << endl;
	cout << "数组中元素个数为：" << sizeof(arr2) / sizeof(arr2[0]) << endl;
	
	// 2. 用于获取数组的首地址
	cout << "数组首地址为：" << arr2 << endl;
	// 使用&查看变量的地址 
	cout << "数组第一个元素的首地址为：" << &arr2[0] << endl;
	cout << "数组第二个元素的首地址为：" << &arr2[1] << endl;
	
	// 数组名是一个常量，保存的是数组的首地址，不可以进行修改
	
	
	// 练习1
	// 找出数组中的最大值
	
	int arr_lianxi[] = {1, 3, 2, 5, 4};
	int maxx = arr_lianxi[0];
	for(int i =1; i<(int)(sizeof(arr_lianxi)/sizeof(arr_lianxi[0])); i++){
		if(maxx < arr_lianxi[i]){
			maxx = arr_lianxi[i];
		}
	}
	cout << "最大值是：" << maxx << endl;
	
	// 使用algorithm头文件中的max_element函数完成找最大值操作
	int n = sizeof(arr_lianxi)/sizeof(arr_lianxi[0]);
	int* max_iter = max_element(arr_lianxi, arr_lianxi+n);
	cout << "最大值是：" << *max_iter << endl;
	
	// 练习2，数组逆置
	for(int i=0; i<n/2; i++){
		// 使用swap方法交换两个值
		swap(arr_lianxi[i], arr_lianxi[n-i-1]);
		
		// a=a+b; a=a-b; a=a-b;
		//arr_lianxi[i] = arr_lianxi[i] + arr_lianxi[n-i-1];
		//arr_lianxi[n-i-1] = arr_lianxi[i] - arr_lianxi[n-i-1];
		//arr_lianxi[i] = arr_lianxi[i] - arr_lianxi[n-i-1];
	}
	
	for(int i=0;i<n;i++){
		cout << arr_lianxi[i] << endl;
	}
	
	cout << "----冒泡排序----" <<  endl;
	// 练习3， 冒泡排序
	// 外层循环i<n，内层循环j<n-i-1，条件j>j+1(升序) j<j+1(降序)
	for(int i=0; i<n; i++){
		for(int j=0; j<n-1-i; j++){
			if(arr_lianxi[j]>arr_lianxi[j+1]){
				swap(arr_lianxi[j], arr_lianxi[j+1]);
			}
		}
	}
	
	for(int i=0;i<n;i++){
		cout << arr_lianxi[i] << endl;
	}
	
	
	// 二维数组
	cout << "-------二维数组-------" << endl;
	// 定义方式
	// 1. 数据类型 数组名[行数][列数];
	int arr_2wei0[2][2];
	arr_2wei0[0][0]=1;
	arr_2wei0[0][1]=2;
	arr_2wei0[1][0]=3;
	arr_2wei0[1][1]=4;
	cout << arr_2wei0[0][0] << endl;
	// 2. 数据类型 数组名[行数][列数] = {{第一行数据}, {第二行数据}};
	// int arr_2wei1[2][2] = {{1, 2}, {3, 4}};
	// 3. 数据类型 数组名[行数][列数] = {数据1, 数据2 ...};
	// int arr_2wei2[2][2] = {1, 2, 3, 4};
	// 4. 数据类型 数组名[][列数] = {数据1, 数据2 ...};
	int arr_2wei3[][2] = {1, 2, 3, 4};
	
	// 注意：列数是必须的，不可以省略
	
	//! 二维数组的数组名作用
	// 1. 查看二维数组所占空间位置
	cout << "二维数组占用内存空间为：" << sizeof(arr_2wei3) << endl;
	cout << "二维数组一行占用内存空间为：" << sizeof(arr_2wei3[0]) << endl;
	cout << "二维数组一个元素占用内存空间为：" << sizeof(arr_2wei3[0][0]) << endl;
	
	cout << "二维数组行数为：" << sizeof(arr_2wei3)/sizeof(arr_2wei3[0]) << endl;
	cout << "二维数组列数为：" << sizeof(arr_2wei3[0])/sizeof(arr_2wei3[0][0]) << endl;
	// 2. 二维数组首地址
	cout << "二维数组的首地址为：" << arr_2wei3 << endl;
	cout << "二维数组第一行的首地址为：" << &arr_2wei3[0] << endl;
	
	system("pause");
	return 0;
}
