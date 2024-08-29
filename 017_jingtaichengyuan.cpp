#include <iostream>


using namespace std;


class Person{

    public: 

        // 静态成员函数
        //1 所有对象共享一个函数
	    //2 静态成员函数只能访问静态成员变量
        static void func(){
            cout << "public访问权限下 static func调用" << endl;
            m_A = 100; // 可以访问到静态成员变量
            //m_C = 100; //错误，不可以访问非静态成员变量, 是由于对于非静态成员变量，每一个对象中都有一个对应的m_C，程序无法确定修改的是哪一个对象的m_C
        }
    
    
    
        // 静态成员变量也具有访问权限，可以使用权限关键字
        // 1.  所有对象都共享同一份数据
        // 2.  编译阶段就分配内存
        // 3.  类内声明 类外初始化
        static int m_A; //静态成员变量, 类内做声明
        int m_C;

    private:
	    static int m_B; //静态成员变量也是有访问权限的

        //静态成员函数也是有访问权限的
        static void func2(){
            cout << "private访问权限下 static func2调用" << endl;
        }
};
int Person::m_A = 10; // 类外做初始化, 使用Person::来限制m_A是Person中的变量
int Person::m_B = 20;

void test01(){

    Person p;
    cout << p.m_A << endl;

    Person p2;
    p2.m_A = 200;

    cout << p.m_A << endl; // 发现p2修改了m_A的值之后，p的m_A也变了，表示共享了m_A的数据

}

void test02(){
    // 由于静态成员变量不属于某一个特定对象，所有的对象都共享同一份数据
    // 所以静态成员变量由两种访问方式
    // 1. 通过对象访问
    Person p;
    cout << p.m_A << endl;

    // 2. 通过类名访问
    cout << Person::m_A << endl; // 直接使用类名进行访问静态变量

    // cout << Person::m_B << endl; // 访问私有权限的静态变量，会报错

}


void test03(){
    	//静态成员变量两种访问方式

        //1、通过对象
        Person p1;
        p1.func();

        //2、通过类名
        Person::func();


        // Person::func2(); //私有权限访问不到

}


int main(){
    // 静态成员 在成员变量和成员函数前加上static
    /*
        静态成员变量
            所有对象共享同一份数据
            在编译阶段就已经分配内存，分配到全局区
            在类内声明，类外初始化  必须要有一个初始值才可以正常使用
        静态成员函数
            所有对象共享同一个函数
            静态成员函数只能访问静态成员变量
    */
   test01();

   test02();

   test03();
}