#include <iostream>
using namespace std;

#include <string>

// 定义结果体
struct Person{
	string name;
	int age;
} p1; // 1，定义结构体的时候同时声明变量


// 结构体嵌套结构体
struct student
{
	//成员列表
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
};
//教师结构体定义
struct teacher
{
    //成员列表
	int id; //职工编号
	string name;  //教师姓名
	int age;   //教师年龄
	struct student stu; //子结构体 学生
};


// 结构体做参数
//值传递
void printStudent(student stu )
{
	stu.age = 28;
	cout << "子函数中 姓名：" << stu.name << " 年龄： " << stu.age  << " 分数：" << stu.score << endl;
}
//地址传递
void printStudent2(student *stu)
{
	stu->age = 28;
	cout << "子函数中 姓名：" << stu->name << " 年龄： " << stu->age  << " 分数：" << stu->score << endl;
}



// 使用const做误操作限制
void printStudent(const student *stu) //加const防止函数体中的误操作，常量指针限制了通过指针修改地址中的值
{
	//! stu->age = 100; //操作失败，因为加了const修饰
	cout << "姓名：" << stu->name << " 年龄：" << stu->age << " 分数：" << stu->score << endl;
}

int main(){

	
	
	// 2.直接初始化结构体
	Person p2 = {"lili", 12};
	cout << p2.name << p2.age << endl;	
	
	
	// 3.创建结构体，随后再进行初始化
	struct Person p3;
	p3.name = "zhangsan";
	p3.age = 33;
	cout << p3.name << p3.age << endl;	
	
	// 创建结构体变量的时候，最前面的struct可以省略
	
	
	// 结构体数组
	struct Person p_list[3]=
	{
		{"张三",18 },
		{"李四",19 },
		{"王五",20 }
	};
	
	for (int i = 0; i < 3; i++)
	{
		cout << "姓名：" << p_list[i].name << " 年龄：" << p_list[i].age << endl;
	}
	
	
	// 结构体指针
	Person * pp = &p2;
	pp->age = 20;
	pp->name = "lisi";
	cout << p2.name << p2.age << endl;	
	
	
	// 结构体嵌套结构体
	struct teacher t1;
	t1.id = 10000;
	t1.name = "老王";
	t1.age = 40;
	// 嵌套内容赋值
	t1.stu.name = "张三";
	t1.stu.age = 18;
	t1.stu.score = 100;
	cout << "教师 职工编号： " << t1.id << " 姓名： " << t1.name << " 年龄： " << t1.age << endl;
	
	cout << "辅导学员 姓名： " << t1.stu.name << " 年龄：" << t1.stu.age << " 考试分数： " << t1.stu.score << endl;
	
	
	// 结构体做参数
	student stu = { "张三",18,100};
	//值传递
	printStudent(stu);
	cout << "主函数中 姓名：" << stu.name << " 年龄： " << stu.age << " 分数：" << stu.score << endl;
	cout << endl;
	//地址传递
	printStudent2(&stu);
	cout << "主函数中 姓名：" << stu.name << " 年龄： " << stu.age  << " 分数：" << stu.score << endl;
	
	
	system("pause");
	return 0;

	
}
