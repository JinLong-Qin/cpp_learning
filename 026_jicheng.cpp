#include <iostream>
#include <string>

using namespace std;

//公共页面
// 包含所有成员中都包含的内容
class BasePage
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
	}

	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}

	void left()
	{
		cout << "Java,Python,C++...(公共分类列表)" << endl;
	}

};

// 这里的继承方式使用的public
//Java页面
class Java : public BasePage
{
public:
	void content()
	{
		cout << "JAVA学科视频" << endl;
	}
};
//Python页面
class Python : public BasePage
{
public:
	void content()
	{
		cout << "Python学科视频" << endl;
	}
};
//C++页面
class CPP : public BasePage
{
public:
	void content()
	{
		cout << "C++学科视频" << endl;
	}
};

void test01()
{
	//Java页面
	cout << "Java下载视频页面如下： " << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "--------------------" << endl;

	//Python页面
	cout << "Python下载视频页面如下： " << endl;
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout << "--------------------" << endl;

	//C++页面
	cout << "C++下载视频页面如下： " << endl;
	CPP cp;
	cp.header();
	cp.footer();
	cp.left();
	cp.content();


}


// 继承方式
class Base1
{
public: 
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

//公共继承
class Son1 :public Base1
{
public:
	void func()
	{
		m_A; //可访问 public权限
		m_B; //可访问 protected权限
		//m_C; //不可访问
	}
};
// 公共继承
void myClass()
{
	Son1 s1;
	s1.m_A; //其他类只能访问到公共权限
}

//保护继承
class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son2:protected Base2
{
public:
	void func()
	{
		m_A; //可访问 protected权限
		m_B; //可访问 protected权限
		//m_C; //不可访问
	}
};
// 保护继承
void myClass2()
{
	Son2 s;
	//s.m_A; //不可访问
}

//私有继承
class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son3:private Base3
{
public:
	void func()
	{
		m_A; //可访问 private权限
		m_B; //可访问 private权限
		//m_C; //不可访问
	}
};
class GrandSon3 :public Son3
{
public:
	void func()
	{
		//Son3是私有继承，所以继承Son3的属性在GrandSon3中都无法访问到
		//m_A;
		//m_B;
		//m_C;
	}
};



int main() {

    // 继承是三大特性之一
    // 当下级别的成员都包含上一级的一些共性，但是又存在一些各自本身的特性
    // 那么就可以把公共特性都拿出来单独做一个类用以继承，让各下级别的成员去专注实现自身的特性，
    // 提升代码的可复用性

    /*
    继承的好处：可以减少重复的代码，提高代码的复用性

    语法：class A : 继承方式 B; 
        继承方式包含：
            1. 公共继承 public
                父类中的public权限下的内容，在子类中依旧是public权限
                父类中的protected权限下的内容，在子类中依旧是protected权限
                即，public继承的内容，不会改变其访问权限
            2. 保护继承
                父类中public访问权限下的内容，在子类中都变成protected权限
                父类中protected全县辖的内容，在子类中还是protected权限
            3. 私有继承
                父类中public访问权限下的内容，在子类中都变成private权限
                父类中protected全县辖的内容，在子类中还是private权限
        !要注意：父类中private下的属性，无论使用什么继承方式，子类中都无法访问
		[父类中私有成员也是被子类继承下去了，只是由编译器给隐藏后访问不到]
		[当构建子类对象的时候，先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反；]

    A 类称为子类 或 派生类

    B 类称为父类 或 基类

    派生类中的成员，包含两大部分：

    一类是从基类继承过来的，一类是自己增加的成员。

    从基类继承过过来的表现其共性，而新增的成员体现了其个性。
    */
	test01();

    cout << "-----------" << endl;

	system("pause");

	return 0;
}
