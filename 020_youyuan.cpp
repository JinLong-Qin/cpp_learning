#include <iostream>
#include <string>
using namespace std;

class Building;
// 类做友元
class Person{

    public:

        Person(){
            b = new Building;
        }

        void visit();
        void visit2(); //只让visit函数作为Building的好朋友，可以发访问Building中私有内容

        Building * b;
};

// 成员函数做友元
class Person1{

    public:

        Person1(){
            b = new Building;
        }

        void visit(); //只让visit函数作为Building的好朋友，可以发访问Building中私有内容 
        void visit1(); 

        Building * b;
};


void Person1::visit(){
    cout << b->woshi << endl; // 可以访问Building的私有属性，因为这个方法对于Building是友元
}

void Person1::visit1(){
    // cout << b->woshi << endl; // 会报错，因为对于Building类来说，针对Person1类，只有visit方法是友元，因此visit1方法不能访问私有属性
}

class Building{

    // 全局函数做友元
    friend void visit();

    // 类做友元
    friend class Person;

    // 成员函数做友元
    friend void Person1::visit();

    public:
        Building(){
            keting = "keting";
            woshi = "卧室";
        }

        string keting;
    private:
        string woshi;
};

// 类外实现类内函数
// 使用Building::来限定作用域
Building::Building(){
    keting = "keting";
    woshi = "卧室";
}

void Person::visit(){
    cout << b->woshi << endl;
}


// 全局函数做友元
void visit(){
    Building b;
    cout << b.woshi << endl;
}

int main(){

    // 友元
    // 友元的目的是让一个函数或者类去访问[另一个类]中的[私有成员]
    // 程序中可能会有一些私有属性需要被类外特殊的函数或者类进行访问，使用友元技术可以实现这一点
    // 友元的关键字是friend

    // 友元的三种实现
    /*
        1. 全局函数做友元
            1.1. 将全局函数的函数头放置在本类实现的最上面
            1.2. 增加friend关键字
        2. 类做友元
            2.1. 将类头放置在本类实现的最上面
            2.2. 增加friend关键字
        3. 成员函数做友元
            3.1. 将要作为友元的成员函数放置在本类的最上面
            3.2. 增加friend关键字
    */

    

    system("pause");
    return 0;
}