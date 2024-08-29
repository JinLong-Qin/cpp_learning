#include <iostream>
#include <map>
#include <string>

using namespace std;

void printMap(map<int,int>&m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}

// 1.构造和赋值
/*
    功能描述：
    ● 对map容器进行构造和赋值操作
    函数原型：
    构造：
    ● map<T1, T2> mp;                     //map默认构造函数:
    ● map(const map &mp);             //拷贝构造函数
    赋值：
    ● map& operator=(const map &mp);    //重载等号操作符
*/
void test01()
{
	map<int,int>m; //默认构造
    // map中每一个元素都是pair,所以insert的时候也要构造pair
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	printMap(m);
	map<int, int>m2(m); //拷贝构造
	printMap(m2);
	map<int, int>m3;
	m3 = m2; //赋值
	printMap(m3);
}

// 2.大小和交换
/*
    功能描述：
    ● 统计map容器大小以及交换map容器
    函数原型：
    ● size();          //返回容器中元素的数目
    ● empty();        //判断容器是否为空
    ● swap(st);      //交换两个集合容器
*/
void test02()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	if (m.empty())
	{
		cout << "m为空" << endl;
	}
	else
	{
		cout << "m不为空" << endl;
		cout << "m的大小为： " << m.size() << endl;
	}
}
//交换
void test03()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	map<int, int>m2;
	m2.insert(pair<int, int>(4, 100));
	m2.insert(pair<int, int>(5, 200));
	m2.insert(pair<int, int>(6, 300));
	cout << "交换前" << endl;
	printMap(m);
	printMap(m2);
	cout << "交换后" << endl;
	m.swap(m2);
	printMap(m);
	printMap(m2);
}
// 3.插入和删除
/*
    功能描述：
    ● map容器进行插入数据和删除数据
    函数原型：
    ● insert(elem);           //在容器中插入元素。
    ● clear();                    //清除所有元素
    ● erase(pos);              //删除pos迭代器所指的元素，返回下一个元素的迭代器。
    ● erase(beg, end);    //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
    ● erase(key);            //删除容器中值为key的元素。
*/
void test04()
{
	//插入
	map<int, int> m;
	//第一种插入方式
	m.insert(pair<int, int>(1, 10));
	//第二种插入方式
	m.insert(make_pair(2, 20));
	//第三种插入方式
	m.insert(map<int, int>::value_type(3, 30));
	//第四种插入方式
	m[4] = 40; // 不要用中括号去插入数据,但是可以使用中括号通过key去访问到value
	printMap(m);
	//删除
	m.erase(m.begin());
	printMap(m);
	m.erase(3); // 删除的是key为3的值
	printMap(m);
	//清空
	m.erase(m.begin(),m.end());
	m.clear();
	printMap(m);
}

// 4.查找和统计
/*
    功能描述：
    ● 对map容器进行查找数据以及统计数据
    函数原型：
    ● find(key);                  //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
    ● count(key);                //统计key的元素个数
*/
void test05()
{
	map<int, int>m; 
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	//查找
	map<int, int>::iterator pos = m.find(3);
	if (pos != m.end())
	{
		cout << "找到了元素 key = " << (*pos).first << " value = " << (*pos).second << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}
	//统计
	int num = m.count(3);
	cout << "num = " << num << endl;
}
// 5.map排序
/*
    学习目标：
    ● map容器默认排序规则为 按照key值进行 从小到大排序，掌握如何改变排序规则
    主要技术点:
    ● 利用仿函数，可以改变排序规则

    ● 利用仿函数可以指定map容器的排序规则
    ● 对于[自定义数据类型]，map[必须要指定排序规则],同set容器
*/
class MyCompare {
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};
void test06() 
{
	//默认从小到大排序
	//利用仿函数实现从大到小排序
	map<int, int, MyCompare> m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));
	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
}
int main(){
    // map和multimap
    /*
    ● map中所有元素都是pair
    ● pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
    ● 所有元素都会[默认根据元素的键值自动排序]
    本质
    map/multimap属于关联式容器，底层结构是用二叉树实现。
    优点：
    ● 可以根据key值快速找到value值
    map和multimap区别：
    ● map不允许容器中有重复key值元素
    ● multimap允许容器中有重复key值元素


    */
    // 1.构造和赋值
    test01();
    // 2.大小和交换
    test02();
    test03();
    // 3.插入和删除
    test04();
    // 4.查找和统计
    test05();
    // 5.map排序
    test06();
    return 0;
}