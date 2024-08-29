#include <iostream>

using namespace std;


class Person{
	public:
	
		// 传统的初始化操作
		/*
		Person(int a, int b, int c){
			p_a = a;
			p_b = b;
			p_c = c;
			cout << "有参构造函数" << endl;
		}
		*/
		
		// 初始化列表
		// 表示p_a属性由a进行初始化 ..
		// 构造函数()：属性1(值1),属性2（值2）... {}
		Person(int a, int b, int c): p_a(a), p_b(b), p_c(c) {}
		
		int p_a;
		int p_b;
		int p_c;
};

void test01(){
	Person p(10, 20, 30); 
	// 这样初始化，相当于将10 传递给了a，20 传递给了b， 30传递给了c，然后通过有参构造函数对属性进行了初始化
	
	cout << "p_a  " << p.p_a;
	cout << "p_b  " << p.p_b;
	cout << "p_c  " << p.p_c << endl;
	
}

int main(){
	
	// 初始化列表：用于初始化类中的属性
	// 语法 构造函数()：属性1(值1),属性2（值2）... {}
	
	test01();
	
	system("pause");
	return 0;
}
