#include <iostream>
#include <string>
#include <utility>

using namespace std;


class Phone{

public:
    Phone(string bname){
        cout << "Phone构造函数" << endl;
        b_name = bname;
    }

    ~Phone(){
        cout << "Phone 析构函数" << endl;
    }

    string b_name;
};


class Person{

public:
    Person(string pname, string bname): p_name(pname), ph(bname){
        cout << "Person构造函数" << endl;
    }

    ~Person(){
        cout << "Person析构函数" << endl;
    }

    string p_name;
    Phone ph;
};



void test01(){
	Person p("张三", "三星");
}
	
	
int main(){

	// 当类对象成为类成员
    //当类中成员是其他类对象时，我们称该成员为 对象成员
    //构造的顺序是 ：先调用对象成员的构造，再调用本类构造
    //析构顺序与构造相反
    //! 其原因为：构造整体对象时候，要先初始化对象中的所有组件，才能组装成一个整体
    //! 在销毁时，先销毁使用局部对象的主体，没有人调用这个局部了，才销毁局部； 或者理解为，这些变量存放在栈区中，栈区的规则是先进后出，后进先出
	test01();
	
	system("pause");
	return 0;
}
