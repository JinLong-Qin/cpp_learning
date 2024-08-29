#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;
#include <vector>

// for_each
/*
    功能描述：
    ● 实现遍历容器
    函数原型：
    ● for_each(iterator beg, iterator end, _func);
    // 遍历算法 遍历容器元素
    // beg 开始迭代器
    // end 结束迭代器
    // _func 函数或者函数对象  回调函数作用,即对遍历到的元素要做的操作
*/
//普通函数
void print01(int val) 
{
	cout << val << " ";
}
//函数对象
class print02 
{
 public:
	void operator()(int val) 
	{
		cout << val << " ";
	}
};
//for_each算法基本用法
void test01() {
	vector<int> v;
	for (int i = 0; i < 10; i++) 
	{
		v.push_back(i);
	}
	//遍历算法
	for_each(v.begin(), v.end(), print01); // 给定起始迭代器,结束迭代器,和函数对象
	cout << endl;
	for_each(v.begin(), v.end(), print02()); // 对于仿函数要加小括号才是函数对象
	cout << endl;
}

// transform
/*
    功能描述：
    ● 搬运容器到另一个容器中
    函数原型：
    ● transform(iterator beg1, iterator end1, iterator beg2, _func);
    //beg1 源容器开始迭代器
    //end1 源容器结束迭代器
    //beg2 目标容器开始迭代器
    //_func 函数或者函数对象 // 回调函数作用
*/

class TransForm
{
public:
	int operator()(int val)
	{
		return val;
	}
};
class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>vTarget; //目标容器
	vTarget.resize(v.size()); // 目标容器需要提前开辟空间
	transform(v.begin(), v.end(), vTarget.begin(), TransForm());
	for_each(vTarget.begin(), vTarget.end(), MyPrint());

    cout << endl;
}

// find
/*
    功能描述：
    ● 查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()
    函数原型：
    ● find(iterator beg, iterator end, value);
    // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
    // beg 开始迭代器
    // end 结束迭代器
    // value 查找的元素
*/
#include <string>
// 内置数据类型的查找
void test03() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i + 1);
	}
	//查找容器中是否有 5 这个元素
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end()) 
	{
		cout << "没有找到!" << endl;
	}
	else 
	{
		cout << "找到:" << *it << endl;
	}
}
// 自定义数据类型的查找
class Person {
public:
	Person(string name, int age) 
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	//重载==  做判断用
	bool operator==(const Person& p) 
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) 
		{
			return true;
		}
		return false;
	}
public:
	string m_Name;
	int m_Age;
};
void test04() {
	vector<Person> v;
	//创建数据
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	vector<Person>::iterator it = find(v.begin(), v.end(), p2);
	if (it == v.end()) 
	{
		cout << "没有找到!" << endl;
	}
	else 
	{
		cout << "找到姓名:" << it->m_Name << " 年龄: " << it->m_Age << endl;
	}
}

// find_if
/*
    功能描述：
    ● 按条件查找元素
    函数原型：
    ● find_if(iterator beg, iterator end, _Pred);
    // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
    // beg 开始迭代器
    // end 结束迭代器
    // _Pred 函数或者谓词（返回bool类型的仿函数）作为查找元素的条件
*/
//内置数据类型
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test05() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i + 1);
	}
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end()) {
		cout << "没有找到!" << endl;
	}
	else {
		cout << "找到大于5的数字:" << *it << endl;
	}
}
//自定义数据类型
class Person1 {
public:
	Person1(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	string m_Name;
	int m_Age;
};
class Greater20
{
public:
	bool operator()(Person1 &p)
	{
		return p.m_Age > 20;
	}
};
void test06() {
	vector<Person1> v;
	//创建数据
	Person1 p1("aaa", 10);
	Person1 p2("bbb", 20);
	Person1 p3("ccc", 30);
	Person1 p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	vector<Person1>::iterator it = find_if(v.begin(), v.end(), Greater20());
	if (it == v.end())
	{
		cout << "没有找到!" << endl;
	}
	else
	{
		cout << "找到姓名:" << it->m_Name << " 年龄: " << it->m_Age << endl;
	}
}

// adjacent_find
/*
	功能描述：
	● 查找相邻重复元素
	函数原型：
	● adjacent_find(iterator beg, iterator end);
	// 查找相邻重复元素,返回相邻元素的第一个位置的迭代器
	// beg 开始迭代器
	// end 结束迭代
*/
void test07()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(3);
	//查找相邻重复元素
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end()) {
		cout << "找不到!" << endl;
	}
	else {
		cout << "找到相邻重复元素为:" << *it << endl;
	}
}

// binary_search
/*
	功能描述：
	● 查找指定元素是否存在
	函数原型：
	● bool binary_search(iterator beg, iterator end, value);
	// 查找指定的元素，查到 返回true  否则false
	// 注意: 在无序序列中不可用
	// beg 开始迭代器
	// end 结束迭代器
	// value 查找的元素

	二分查找法查找效率很高，但是容器中元素必须有序
*/
void test08()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//二分查找
	bool ret = binary_search(v.begin(), v.end(), 2);
	if (ret)
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

// count
/*
	功能描述：
	● 统计元素个数
	函数原型：
	● count(iterator beg, iterator end, value);
	// 统计元素出现次数
	// beg 开始迭代器
	// end 结束迭代器
	// value 统计的元素
*/
//内置数据类型
void test09()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	int num = count(v.begin(), v.end(), 4);
	cout << "4的个数为： " << num << endl;
}
//自定义数据类型
class Person2
{
public:
	Person2(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	bool operator==(const Person2 & p) // 自定义数据类型做判断的时候要重载operator==
	{
		if (this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string m_Name;
	int m_Age;
};
void test010()
{
	vector<Person2> v;
	Person2 p1("刘备", 35);
	Person2 p2("关羽", 35);
	Person2 p3("张飞", 35);
	Person2 p4("赵云", 30);
	Person2 p5("曹操", 25);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
    
    Person2 p("诸葛亮",35);
	int num = count(v.begin(), v.end(), p); // 重载的相等是年龄相等
	cout << "num = " << num << endl;
}

// count_if
/*
	功能描述：
	● 按条件统计元素个数
	函数原型：
	● count_if(iterator beg, iterator end, _Pred);
	// 按条件统计元素出现次数
	// beg 开始迭代器
	// end 结束迭代器
	// _Pred 谓词
*/
class Greater4
{
public:
	bool operator()(int val)
	{
		return val >= 4;
	}
};
//内置数据类型
void test011()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	int num = count_if(v.begin(), v.end(), Greater4());
	cout << "大于4的个数为： " << num << endl;
}
//自定义数据类型
class Person3
{
public:
	Person3(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
class AgeLess35
{
public:
	bool operator()(const Person3 &p)
	{
		return p.m_Age < 35;
	}
};
void test012()
{
	vector<Person3> v;
	Person3 p1("刘备", 35);
	Person3 p2("关羽", 35);
	Person3 p3("张飞", 35);
	Person3 p4("赵云", 30);
	Person3 p5("曹操", 25);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	int num = count_if(v.begin(), v.end(), AgeLess35());
	cout << "小于35岁的个数：" << num << endl;
}

// 排序算法
/*
	功能描述：
	● 对容器内元素进行排序
	函数原型：
	● sort(iterator beg, iterator end, _Pred);
	// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
	//  beg    开始迭代器
	//  end    结束迭代器
	// _Pred  谓词
*/
void myPrint1(int val)
{
	cout << val << " ";
}
void test013() {
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);
	//sort默认从小到大排序
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint1);
	cout << endl;
	//从大到小排序
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), myPrint1);
	cout << endl;
}

// random_shuffle
/*
	功能描述：
	● 洗牌   指定范围内的元素随机调整次序
	函数原型：
	● random_shuffle(iterator beg, iterator end);
	// 指定范围内的元素随机调整次序
	// beg 开始迭代器
	// end 结束迭代器
*/
#include <ctime>
void test014(){

	srand((unsigned int)time(NULL)); // 设置随机种子，防止每次随机都是一样的结果
	vector<int> v;
	for(int i = 0 ; i < 10;i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
	//打乱顺序
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}

// merge
/*
	功能描述：
	● 两个容器元素合并，并存储到另一容器中
	函数原型：
	● merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
	// 容器元素合并，并存储到另一容器中
	// 注意: 两个容器必须是有序的
	// beg1   容器1开始迭代器
	// end1   容器1结束迭代器
	// beg2   容器2开始迭代器
	// end2   容器2结束迭代器
	// dest    目标容器开始迭代器
	
	将两个有序的容器（排序方式要相同）进行融合，并且融合后的新容器依旧是有序的

*/
void test015()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10 ; i++) 
    {
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	vector<int> vtarget;
	//目标容器需要提前开辟空间
	vtarget.resize(v1.size() + v2.size());
	//合并  需要两个有序序列  这是merge方法成功执行的基础
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());
	for_each(vtarget.begin(), vtarget.end(), MyPrint());
	cout << endl;
}

// reverse
/*
	功能描述：
	● 将容器内元素进行反转
	函数原型：
	● reverse(iterator beg, iterator end);
	// 反转指定范围的元素
	// beg 开始迭代器
	// end 结束迭代器
*/
void test016(){

	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);
	cout << "反转前： " << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
	cout << "反转后： " << endl;
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), MyPrint());
}

int main(){
    // stl常用算法
    /*
    ● 算法主要是由头文件<algorithm> <functional> <numeric>组成。
    ● <algorithm>是所有STL头文件中最大的一个，范围涉及到比较、 交换、查找、遍历操作、复制、修改等等
    ● <numeric>体积很小，只包括几个在序列上面进行简单数学运算的模板函数
    ● <functional>定义了一些模板类,用以声明函数对象。
    */

    // 1. 常用遍历算法
    // ● for_each     //遍历容器
    // ● transform   //搬运容器到另一个容器中
    test01();
    test02();

    // 常用查找算法
    /*
    ● find                     //查找元素
    ● find_if               //按条件查找元素
    ● adjacent_find    //查找相邻重复元素
    ● binary_search    //二分查找法
    ● count                   //统计元素个数
    ● count_if             //按条件统计元素个数
    */
    // find
    test03();
    test04();

    // find_if
    test05();
    test06();

	// adjacent_find
	test07();

	// binary_search
	test08();

	// count
	test09();
	test010();

	//count_if
	test011();
	test012();

	// 常用排序算法
	/*
	● sort             //对容器内元素进行排序
	● random_shuffle   //洗牌   指定范围内的元素随机调整次序
	● merge           // 容器元素合并，并存储到另一容器中
	● reverse       // 反转指定范围的元素
	*/

	// sort
	test013();

	// random_shuffle
	test014();

	// merge
	test015();

	// reverse
	test016();

    return 0;
}