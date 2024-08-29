#include <iostream>
#include <string>
#include <cmath>
#include "012_Circle2.h"
using namespace std;

const double PI = 3.14;

// 1. 封装
// class关键字表示创建一个类
class Circle{
	// 访问权限
	public: // 公共权限
		// 属性 半径
		int m_r;
		
		// 行为
		// 圆的周长
		double calculateZC(){
			return 2 * PI * m_r;
		}
		
};

// 封装练习:设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
class Student{
	//! 类中的属性和行为，都被称为成员
	// 属性又被称为 成员属性 或 成员变量
	// 行为又被称为 成员函数 或 成员方法
	public:
		string sname;
		int sid;
		
		void showStudent(){
			cout << "姓名是：" << sname << " 学号是：" << sid << endl;
		}
		
		void setName(string name){
			sname = name;
		}
};


// 访问权限
class Person{
	public:
	string m_Name;

	protected:
		string m_Car;

	private:
		int m_Password;

	public:
		void func1()
		{
			m_Name = "张三";
			m_Car = "拖拉机";
			m_Password = 123456;
		}
	protected:
		void func2()
		{
			m_Name = "张三";
			m_Car = "拖拉机";
			m_Password = 123456;
		}
};

// 成员属性私有化的好处
class Person2 {
public: // 构建公共方法来限制读写权限
	
	//姓名设置可读可写
	void setName(string name) {
		m_Name = name;
	}
	string getName()
	{
		return m_Name;
	}


	//获取年龄 
	int getAge() {
		return m_Age;
	}
	//设置年龄
	//! 在写入的时候，检测输入内容的有效性
	void setAge(int age) {
		if (age < 0 || age > 150) {
			cout << "你个老妖精!" << endl;
			return;
		}
		m_Age = age;
	}

	//偶像设置为只写
	void setIdol(string idol) {
		m_Idol = idol;
	}

private:
	string m_Name; //可读可写  姓名
	
	int m_Age; //只读  年龄

	string m_Idol; //只写  偶像
};


// 练习1
// 求出立方体的面积和体积；
// 分别用全局函数和成员函数判断两个立方体是否相等
class Cube{
	public:
		int get_H(){
			return m_H;
		}
		
		int get_L(){
			return m_L;
		}
		
		int get_W(){
			return m_W;
		}
		
		void set_H(int H){
			m_H = H;
		}
		
		void set_L(int L){
			m_L = L;
		}
		
		void set_W(int W){
			m_W = W;
		}
		
		// 计算面积
		int calculateS(){
			return 2 * (m_H * m_L + m_L * m_W + m_W * m_H);
		}
		
		// 计算体积
		int calculateV(){
			return m_H * m_L * m_W;
		}
		
		// 成员函数判断两个立方体是否相等
		bool isSameInsideClass(Cube c){
			if(m_H==c.get_H() && m_L==c.get_L() && m_W==c.get_W()){
				return 1;
			}
			return 0;
		}
		
	private:
		int m_H; // 高
		int m_L; // 长
		int m_W; // 宽
};
// 全局函数判断两个立方体是否相等
// 使用引用传递，可以在一定程度上节省内存，尤其是数据量大的时候
// 因为值传递会复制一个备份进入函数内
bool isSame(Cube & c1, Cube & c2){
	if(c1.get_H()==c2.get_H() && c1.get_L()==c2.get_L() && c1.get_W()==c2.get_W()){
		return 1;
	}
	return 0;
}

// 练习2.设计一个圆形类和一个点类，判断点和圆的关系
/*
class Point{
	public:
		int get_X(){
			return m_x;
		}
		
		int get_Y(){
			return m_y;
		}
		
		void set_X(int x){
			m_x = x;
		}
		
		void set_Y(int y){
			m_y = y;
		}
	private:
		int m_x;
		int m_y; 
};

class Circle2{
	public:
		int get_R(){
			return m_r;
		}
		
		void set_R(int r){
			m_r = r;
		}
		
		Point getCenter(){
			return m_center;
		}
		
		void setCenter(Point p){
			m_center = p;
		}
		
	private:
		int m_r;
		Point m_center;
};
* 将代码拆分为头文件，见012_Point和012_Circle2相关文件，并最后引入012_Circle2.h问及那
*/
// 判断点和圆的关系
void isInCircle(Circle2 & c, Point & p){
	//int dis = sqrt(pow(c.getCenter().get_X()-p.get_X(), 2) + pow(c.getCenter().get_Y()-p.get_Y(), 2));
	// 避免使用sqrt提高效率，比较平方
	int dx = c.getCenter().get_X()-p.get_X();
	int dy = c.getCenter().get_Y()-p.get_Y();
	int distSquared = dx * dx + dy * dy;
	if(distSquared == c.get_R()*c.get_R()){
		cout << "在圆上" << endl;
	}else if(distSquared > c.get_R()*c.get_R()){
		cout << "在圆外" << endl;
	}else{
		cout << "在圆内" << endl;
	}
		
}

int main(){
	
	// 类和对象
	// 万事万物都皆为对象，对象上有其属性和行为
		// 对象是实例；具有相同性质的对象，我们可以抽象称为类，人属于人类，车属于车类
	// 面向对象的三大特性为：封装、继承、多态
	
	
	// 1.封装 
	// 1.1 封装的意义1： 将属性和方法作为一个整体，并加以权限控制
	//! 实例化，通过一个类创建一个对象
	// 通过圆类 创建圆对象
	Circle cl;
	// 为对象的属性赋值
	cl.m_r = 10;
	
	// 使用对象的行为计算圆的周长
	cout << "圆的周长为：" << cl.calculateZC() << endl;
	
	
	// 封装练习：设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
	Student stu;
	stu.sname="lili";
	stu.sid = 123;
	// 除直接对对象中的属性进行赋值外，还可以使用行为来对属性进行赋值
	stu.setName("zhangsan");
	
	stu.showStudent();
	
	// 1.1 封装的意义2： 将属性和方法放置在不同的权限下，以加强进一步的控制
	// 访问权限的类型：；
	/*!
	 * 1. public公共权限：	类内部可以访问，类外部可以访问
	 * 2. protected保护权限: 类内部可以访问，类外部不可以访问; 子类可以访问父类中被保护的内容
	 * 3. private私有权限：	类内部可以访问，类外部不可以访问; 子类中不可以访问父类中的私有内容
	 * */
	Person p1;
	
	p1.m_Name = "李四";
	//p1.m_Car = "奔驰";  //保护权限类外访问不到
	//p1.m_Password = 123; //私有权限类外访问不到
	
	p1.func1();
	// p1.func2(); //保护权限类外访问不到
	
	// 不论方法还是属性，都具有访问权限
	//! struct和class 的区别
	/*
	 * struct默认权限为public
	 * class默认权限为priviate
	 * */
	
	// 成员属性私有化的好处
	/*
	 * 1. 可以自己控制读写权限
	 * 2. 对于写权限，可以检测数据的有效性
	 * */
	 
	Person2 p2;
	//姓名设置
	p2.setName("张三");
	cout << "姓名： " << p2.getName() << endl;

	//年龄设置
	p2.setAge(50);
	cout << "年龄： " << p2.getAge() << endl;

	//情人设置
	p2.setIdol("gg");
	//cout << "偶像： " << p.m_Idol << endl;  //只写属性，不可以读取
	
	
	// 练习1 设计立方体类(Cube)；求出立方体的面积和体积；分别用全局函数和成员函数判断两个立方体是否相等
	Cube c1;
	c1.set_H(1);
	c1.set_W(2);
	c1.set_L(3);
	
	cout << "c1的面积是： " << c1.calculateS() << endl;
	cout << "c1的体积是： " << c1.calculateV() << endl;
	
	Cube c2;
	c2.set_H(1);
	c2.set_W(2);
	c2.set_L(3);
	
	cout << "c2的面积是： " << c2.calculateS() << endl;
	cout << "c2的体积是： " << c2.calculateV() << endl;
	
	// 全局函数判断是否相等
	if(isSame(c1, c2)){
		cout << "c1和c2是相等的" << endl;
	}else{
		cout << "c1和c2是不相等" << endl;
	}
	// 局部函数判断是否相等
	if(c1.isSameInsideClass(c2)){
		cout << "c1和c2是相等的" << endl;
	}else{
		cout << "c1和c2是不相等" << endl;
	}
	
	
	// 练习2.设计一个圆形类和一个点类，判断点和圆的关系
	// 圆内，圆上，圆外
	/*
	 * 点到圆心的距离 == 半径 圆上
	 * 点到圆心的距离 < 半径 圆内
	 * 点到圆心的距离 > 半径 圆外
	 * */
	Point p;
	p.set_X(1);
	p.set_Y(2);
	
	Point center;
	p.set_X(0);
	p.set_Y(0);
	
	Circle2 cc;
	cc.set_R(3);
	cc.setCenter(center);
	
	isInCircle(cc, p);
	
	//! 将Point类和Circle2类拆分为头文件和源文件以简化main文件中的内容
	// g++ -o 012_leiheduixiang 012_leiheduixiang.cpp 012_Point.cpp 012_Circle2.cpp
	
	system("pause");
	return 0;
}


















