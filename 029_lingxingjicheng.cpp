#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
	int m_Age;
};

// 在继承最大的类 即 animal 类的时候，增加:virtual关键字
//继承前加virtual关键字后，变为虚继承
//此时公共的父类Animal称为虚基类
// 虚继承
class Sheep : virtual public Animal {};
class Tuo   : virtual public Animal {};
class SheepTuo : public Sheep, public Tuo {};

void test01()
{
	SheepTuo st;
    // 增加了虚继承后，m_Age属性只保留一份
	st.Sheep::m_Age = 100;
	st.Tuo::m_Age = 200;

    // 多个父类中存在同名属性的时候，子类访问这些属性要增加作用域
	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age = " <<  st.Tuo::m_Age << endl;

    // 增加了虚继承后，直接点m_Age也不会报错，这就是因为只保留了一份m_Age属性
	cout << "st.m_Age = " << st.m_Age << endl;
}


int main() {


    // 菱形继承/ 钻石继承
    // 指的是  两个派生类继承同一个基类； 又有某个类同时继承者两个派生类； 

	test01();

	system("pause");
	return 0;
}
