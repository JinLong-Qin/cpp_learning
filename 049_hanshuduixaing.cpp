#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// 函数对象的调用
class MyAdd
{
public :
	int operator()(int v1,int v2)
	{
		return v1 + v2;
	}
};
void test01()
{
	MyAdd myAdd;
	cout << myAdd(10, 10) << endl;
}
//2、函数对象可以有自己的状态
class MyPrint
{
public:
	MyPrint()
	{
		count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		count++; //统计使用次数
	}
	int count; //内部自己的状态
};
void test02()
{
	MyPrint myPrint;
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	cout << "myPrint调用次数为： " << myPrint.count << endl;
}
//3、函数对象可以作为参数传递
void doPrint(MyPrint &mp , string test)
{
	mp(test);
}
void test03()
{
	MyPrint myPrint;
	doPrint(myPrint, "Hello C++");
}

// 谓词
//1.一元谓词
struct GreaterFive{
	bool operator()(int val) {
		return val > 5;
	}
};
void test04() {
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end()) {
		cout << "没找到!" << endl;
	}
	else {
		cout << "找到:" << *it << endl;
	}
}

//二元谓词
class MyCompare
{
public:
	bool operator()(int num1, int num2)
	{
		return num1 > num2;
	}
};
void test05()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	//默认从小到大
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "----------------------------" << endl;
	//使用函数对象改变算法策略，排序从大到小
	sort(v.begin(), v.end(), MyCompare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

// 算数仿函数
// negate 一元仿函数 取反
//negate
void test06()
{
	negate<int> n;
	cout << n(50) << endl;
}
//plus
void test07()
{
	plus<int> p;
	cout << p(10, 20) << endl;
}

// 关系仿函数
class MyCompare2
{
public:
	bool operator()(int v1,int v2)
	{
		return v1 > v2;
	}
};
void test08()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(40);
	v.push_back(20);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	//自己实现仿函数
	//sort(v.begin(), v.end(), MyCompare2());
	//STL内建仿函数  大于仿函数greater
	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

// 逻辑仿函数
void test09()
{
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);
	for (vector<bool>::iterator it = v.begin();it!= v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//逻辑非  将v容器搬运到v2中，并执行逻辑非运算
	vector<bool> v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(),  v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main(){
    // 函数对象
    /*
    概念：
    ● 重载函数调用操作符的类，其对象常称为函数对象
    ● 函数对象使用重载的()时，行为类似函数调用，也叫仿函数
    本质：
    函数对象(仿函数)是一个类，不是一个函数
    */

    // 1.函数对象的调用
    /*
    特点：
    ● 函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
    ● 函数对象超出普通函数的概念，函数对象可以有自己的状态
    ● 函数对象可以作为参数传递
    */
    test01();
    test02();
    test03();

    // 2. 谓词
    /*
    概念：
    ● 返回bool类型的仿函数称为谓词
    ● 如果operator()接受一个参数，那么叫做一元谓词
    ● 如果operator()接受两个参数，那么叫做二元谓词
    */
    test04();
    test05();
   

    // 内建函数对象
    /*
    分类:
    ● 算术仿函数
    ● 关系仿函数
    ● 逻辑仿函数
    用法：
    ● 这些仿函数所产生的对象，用法和一般函数完全相同
    ● 使用内建函数对象，需要引入头文件 #include<functional>
    */

    // 算数仿函数
    /*
    功能描述：
    ● 实现四则运算
    ● 其中negate是一元运算，其他都是二元运算
    仿函数原型：
    ● template<class T> T plus<T>                //加法仿函数
    ● template<class T> T minus<T>              //减法仿函数
    ● template<class T> T multiplies<T>    //乘法仿函数
    ● template<class T> T divides<T>         //除法仿函数
    ● template<class T> T modulus<T>         //取模仿函数
    ● template<class T> T negate<T>           //取反仿函数
    */

    // 一元 negate
	test06();
	// 二元 加法
	test07();

	// 关系仿函数
	/*
	功能描述：
	● 实现关系对比
	仿函数原型：
	● template<class T> bool equal_to<T>                    //等于
	● template<class T> bool not_equal_to<T>            //不等于
	● template<class T> bool greater<T>                      //大于
	● template<class T> bool greater_equal<T>          //大于等于
	● template<class T> bool less<T>                           //小于
	● template<class T> bool less_equal<T>               //小于等于
	*/

	test08();

	// 逻辑仿函数
	/*
	功能描述：
	● 实现逻辑运算
	函数原型：
	● template<class T> bool logical_and<T>              //逻辑与
	● template<class T> bool logical_or<T>                //逻辑或
	● template<class T> bool logical_not<T>              //逻辑非
	*/
	test09();

    return 0;
}