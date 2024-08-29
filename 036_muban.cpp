#include <iostream>

using namespace std;
//交换整型函数
void swapInt(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
//交换浮点型函数
void swapDouble(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}
//利用模板提供通用的交换函数
template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
void test01()
{
	int a = 10;
	int b = 20;
	
	//swapInt(a, b);
	//利用模板实现交换
	//1、自动类型推导
	mySwap(a, b);
	//2、显示指定类型
	mySwap<int>(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

// 注意事项
//利用模板提供通用的交换函数
// 1、自动类型推导，必须推导出一致的数据类型T,才可以使用
void test02()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	mySwap(a, b); // 正确，可以推导出一致的T
	//mySwap(a, c); // 错误，推导不出一致的T类型 因为一个是int类型一个是char
}
// 2、模板必须要确定出T的数据类型，才可以使用
template<class T> // typename可以替换为class，两者功能是相同的
void func()
{
	cout << "func 调用" << endl;
}
void test03()
{
	//func(); //错误，模板不能独立使用，必须确定出T的类型。函数中没有用到T，编译器无法推到T的类型，所以就要手动给定类型
	func<int>(); //利用显示指定类型的方式，给T一个类型，才可以使用该模板
}

// 练习
// 案例，使用模板实现对数组及逆行排序的函数
// 从大到小
// 选择算法
// 测试char和int数据
template <class T>
void swapTwo(T &a, T &b){
    T temp = a;
    a = b; 
    b = temp;
}

template <class T>
void sortArr(T arr[], int len){
    // int max  = 0;
    for(int i=0; i<len; i++){
        int max = i;
        for(int j=i+1; j<len; j++){
            if(arr[max] < arr[j]){
                max = j;
            }
        }
        if(max != i){
            swapTwo(arr[max], arr[i]);
        }
    }
}

template<class T>
void printArr(T arr[], int len){
    for(int i=0;i<len;i++){
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void test04(){

    int arr[] = {21,3,65,11,5,6};
    int len = sizeof(arr) / sizeof(arr[0]);
    sortArr(arr, len);
    printArr(arr, len);
}



// 函数模板也可以重载
//普通函数与函数模板调用规则
void myPrint(int a, int b)
{
	cout << "调用的普通函数" << endl;
}
template<typename T>
void myPrint(T a, T b) 
{ 
	cout << "调用的模板" << endl;
}
template<typename T>
void myPrint(T a, T b, T c) 
{ 
	cout << "调用重载的模板" << endl; 
}

void test05()
{
	//1、如果函数模板和普通函数都可以实现，优先调用普通函数
	// 注意 如果告诉编译器  普通函数是有的，但只是声明没有实现，或者不在当前文件内实现，就会报错找不到
	int a = 10;
	int b = 20;
	myPrint(a, b); //调用普通函数
	//2、可以通过空模板参数列表来强制调用函数模板
	myPrint<>(a, b); //调用函数模板
	//3、函数模板也可以发生重载
	int c = 30;
	myPrint(a, b, c); //调用重载的函数模板
	//4、 如果函数模板可以产生更好的匹配,优先调用函数模板
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2); //调用函数模板
}

// 模板的局限性
/*
template<class T>
void f(T a, T b) 
{ 
    a = b; // 若是传入两个数组，就无法实现
}

template<class T>
void f(T a, T b)
{ 
    if(a > b) { ... } // 如果不是内置的数据类型，就也不行
}
*/
// 模板重载可以为自定义的特殊数据类型提供具体化的模板
#include <string>
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
//普通函数模板
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//具体化，显示具体化的原型和定意思以template<>开头，并通过名称来指出类型
//具体化优先于常规模板
template<> bool myCompare(Person &p1, Person &p2)
{
	if ( p1.m_Name  == p2.m_Name && p1.m_Age == p2.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void test06()
{
	int a = 10;
	int b = 20;
	//内置数据类型可以直接使用通用的函数模板
	bool ret = myCompare(a, b);
	if (ret)
	{
		cout << "a == b " << endl;
	}
	else
	{
		cout << "a != b " << endl;
	}
}
void test07()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	//自定义数据类型，不会调用普通的函数模板
	//可以创建具体化的Person数据类型的模板，用于特殊处理这个类型
	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1 == p2 " << endl;
	}
	else
	{
		cout << "p1 != p2 " << endl;
	}
}


int main() {
	test01();

    
	test02();
	test03();

    // 模板
    // 泛型编程

    // 模板就是建立通用的模具，大大提高复用性
    //  模板的特点：
    // ● 模板不可以直接使用，它只是一个框架
    // ● 模板的通用并不是万能的


    // 1 函数模板
    // ● C++另一种编程思想称为 泛型编程 ，主要利用的技术就是模板
    // ● C++提供两种模板机制:函数模板和类模板
    // 作用：建立一个通用函数，其[函数返回值类型]和[形参类型]可以 不具体制定 ，用一个[虚拟的类型]来代表。

    // 语法 template<typename T>
    /*解释：
        template  ---  声明创建模板
        typename  --- 表面其后面的符号是一种数据类型，可以用class代替
        T    ---   通用的数据类型，名称可以替换，通常为大写字母
    */
    /*
    总结：
    ● 函数模板利用关键字 template
    ● 使用函数模板有两种方式：自动类型推导、显示指定类型
    ● 模板的目的是为了提高复用性，将类型参数化
    */
    /*！ 注意事项：
    ● 自动类型推导，必须推导出一致的数据类型T,才可以使用
    ● 模板必须要确定出T的数据类型，才可以使用
    */
    

    // 练习
    test04();



    // 普通函数和函数模板的区别
    /*
    普通函数与函数模板区别：
    ● 普通函数调用时可以发生自动类型转换（隐式类型转换）； 比如1+'c'会将'c'转换为其对应的askii码在进行相加
    ● 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
    ● !如果利用显示指定类型的方式，可以发生隐式类型转换

    建议使用显示指定类型的方式，调用函数模板，因为可以自己确定通用类型T
    */


    // 函数模板和普通函数的调用规则
    /*
    1. 如果函数模板和普通函数都可以实现，优先调用普通函数，但是普通函数一定要有函数实现，光有函数声明是不可以的
    2. 可以通过[空模板参数列表] 来强制调用函数模板
    3. 函数模板也可以发生重载
    4. 如果函数模板可以产生更好的匹配,优先调用函数模板

    当提供了函数模板就不要提供普通函数，以免产生调用时候的二义性
    */
    
    test05();


    // 模板的局限性
    // 模板的通用性并不万能
    // 要针对自定义的数据类型去重载为具体化的模板，这样可以解决自定义数据类型的通用化
    // 学习模板是为了更好的在STL中运用系统提供的模板
    test06();
    test07();


    return 0;
}