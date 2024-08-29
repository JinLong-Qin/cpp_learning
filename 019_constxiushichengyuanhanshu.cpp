#include <iostream>
using namespace std;


class Person{
    public:

        Person(){

        }

        // 1. 常函数
        void showPerson1(){
            this->m_A = 100; // 等价于m_A = 100; 隐含了一个this
            // this指针的本质是指针常量，其定义为 Person * const this; 其指向不可以修改，体现在下一行
            // this = NULL;

            // 要想让this指针指向的值也不可以修改，就要对this的定义增加const修饰，即 const Person * const this;
            // 那么体现在类中的函数，要让其使用不可修改值的this，就要在成员函数中增加const，增加的位置是成员函数的后面，见下面的showPerson函数
        }

        void showPerson() const{ 
            // this->m_A = 100; // 此时对成员属性进行修改就会报错，因为此时this指针已经变为常量
            // 此时就不允许函数修改this指针指向的值
            //! 此时成员函数就被称为常函数

            // 如果有要修改的值，就在成员属性定义的时候增加mutable关键字
            this->m_B = 20;
        }

        // 2. 常对象

        int m_A;
        mutable int m_B; // 如果要在常函数中修改成员属性的值，要在定义的时候增加mutable关键字
};


// 1. 常函数
void test01(){
    Person p;

    // p.showPerson1();
    p.showPerson();
}

// 2. 常对象
void test02(){
    // 在对象顶以前增加const，这时候定义的就是常对象了
    const Person p;
    // p.m_A = 10; // 会报错，因为常对象不允许修改普通的成员变量
    p.m_B = 20; // 因为m_B定义的时候有mutable关键字，因此可以进行修改

    // 常对象只能调用常函数
    // p.showPerson1(); // showPerson1不是常函数，在常对象中不可以调用,因为普通函数可以修改成员属性
    p.showPerson(); // 常对象只可以调用常函数

}

int main(){

    // const修饰成员函数
    // 常函数
    test01();

    cout << "--------" << endl; 
    
    // 常对象
    test02();

    system("pause");
    return 0;
}