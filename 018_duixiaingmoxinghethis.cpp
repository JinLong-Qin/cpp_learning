#include <iostream>


using namespace std;


class Person{

};


void test01(){

    Person p;
    cout << "sizeof p :" << sizeof(p) << endl; 
    // 对于一个空对象，其占用内存空间为1
    // 原因是编译器会给每一个空对象分一个字节的空间，是为了区分空对象占内存的位置，每一个空对象都有一个唯一的内存地址
}


class Person1{
    int a; // 非静态成员变量
};

void test02(){

    Person1 p;
    cout << "sizeof p :" << sizeof(p) << endl; 
    
}

class Person2{
    int a; // 非静态成员变量
    static int b;
};
int Person2::b = 0;

void test03(){

    Person2 p;
    cout << "sizeof p :" << sizeof(p) << endl; 
    // 增加了一个静态变量，但是size大小不变，表示静态成员变量并不属于类对象上
}

class Person3{
    int a; // 非静态成员变量
    static int b;

    // 函数也不占对象空间，所有函数共享一个函数实例， 通过this来明确是哪一个对象在调用函数
    void func(){
        cout << a << endl;
    }
};
int Person3::b = 0;

void test04(){

    Person3 p;
    cout << "sizeof p :" << sizeof(p) << endl; 
    // 增加了一个非静态成员函数，size依旧不变,即 非静态成员函数也不属于对象中
}

class Person4{
    int a; // 非静态成员变量
    static int b;

    // 函数也不占对象空间，所有函数共享一个函数实例， 通过this来明确是哪一个对象在调用函数
    void func(){
        cout << a << endl;
    }
    
    // 静态成员函数也不占对象空间
    // 不论是静态成员函数还是静态成员变量，都是只有一份，所有对象共享，因此静态成员函数也不属于对象
    static void func2(){
        cout << "静态成员函数" << endl;
    }
};
int Person4::b = 0;

void test05(){

    Person4 p;
    cout << "sizeof p :" << sizeof(p) << endl; 
    // 增加了一个静态成员函数，size依旧不变,即 静态成员函数也不属于对象中
}


// this指针用途
class Person5{
public:
    // 1. 解决命名冲突 当形参和成员变量命名相同
	Person5(int age){
		//1、当形参和成员变量同名时，可用this指针来区分
		this->age = age;
	}

    // 2. 
    // 返回的是本体，返回值使用引用的方式
    // 必须要用引用的方式，如果不使用引用的方式而使用值返回的方式，则返回的内容是一个Person5的对象副本，和进行运算的对象不是一个，每次返回的都是一个新对象
	// 使用引用的方式返回，则每次返回的都是对象本体，
    // 链式编程的思想，调用此函数的对象可以一直点来执行方法
    Person5 & PersonAddPerson(Person5 p)
	{
		this->age += p.age;
		// *this指向的是调用这个方法的对象本身
		return *this;
	}

	int age;
};

void test06()
{
	Person5 p1(10);
	cout << "p1.age = " << p1.age << endl;

	Person5 p2(10);
    // 链式编程思想
	p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1); // 由于返回值是p2本身，所以可以一直点方法
	cout << "p2.age = " << p2.age << endl;
}


class Person6{
    public:

        void ShowClassName() {
            // 不涉及到this的方法，都是可以正常运行的
            cout << "我是Person6类!" << endl;
        }

        void ShowPerson() {
            // 对指针进行健壮性判断
            if (this == NULL) {
                return;
            }
            cout << mAge << endl; // 对于成员属性的访问，一般前面都隐含着一个this->， 当是空指针的时候，即对象没有实例化，也就没有成员属性，所以会报错，需要增加上面的代码以增强代码的健壮性
        }

    public:
        int mAge;

};
void test07(){

    Person6 *p;
    p->ShowClassName();

    p->ShowPerson();
}





int main(){
    // C++对象模型和this指针

    // 1. 成员变量和成员函数是分开存储的
    //! 只有非静态成员变量才属于类创建的对象 
    test01();

    test02();

    test03();

    test04();

    test05();

    cout << "-----------" << endl;

    // 2. this指针
    // 每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码
    // 通过this指针来区分到底是哪一个对象调用的函数
    // this指针是隐含每一个[非静态成员函数]内的一种指针
    //! this指针指向的是 被调用的成员函数 所属的对象
    //! this指针不需要定义，直接使用即可
    // 用途
    /*
         1.当形参和成员变量同名时，可用this指针来区分(解决名称冲突)
         2.在类的非静态成员函数中返回对象本身，可使用return *this
    */ 

   test06();

   // 空指针访问成员函数
   // C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针

    test07();
}