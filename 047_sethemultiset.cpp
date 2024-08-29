#include <iostream>
#include <string>
#include <set>

using namespace std;

void printSet(set<int> & s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
// 构造和赋值
/*
    功能描述：创建set容器以及赋值
    构造：
    ● set<T> st;                        //默认构造函数：
    ● set(const set &st);       //拷贝构造函数
    赋值：
    ● set& operator=(const set &st);    //重载等号操作符

    set插入值的时候,会自动排序
    不允许插入重复值
*/
void test01()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);
	//拷贝构造
	set<int>s2(s1);
	printSet(s2);
	//赋值
	set<int>s3;
	s3 = s2;
	printSet(s3);
}

// 2. 大小和交换
/*
    功能描述：
    ● 统计set容器大小以及交换set容器
    函数原型：
    ● size();          //返回容器中元素的数目
    ● empty();        //判断容器是否为空
    ● swap(st);      //交换两个集合容器
*/
// 大小
void test02(){
    set<int> s1;
	
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	if (s1.empty())
	{
		cout << "s1为空" << endl;
	}
	else
	{
		cout << "s1不为空" << endl;
		cout << "s1的大小为： " << s1.size() << endl;
	}

}
//交换
void test03()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	set<int> s2;
	s2.insert(100);
	s2.insert(300);
	s2.insert(200);
	s2.insert(400);
	cout << "交换前" << endl;
	printSet(s1);
	printSet(s2);
	cout << endl;
	cout << "交换后" << endl;
	s1.swap(s2);
	printSet(s1);
	printSet(s2);
}
// 3. 插入和删除
/*
    功能描述：
    ● set容器进行插入数据和删除数据
    函数原型：
    ● insert(elem);           //在容器中插入元素。
    ● clear();                    //清除所有元素
    ● erase(pos);              //删除pos迭代器所指的元素，返回下一个元素的迭代器。
    ● erase(beg, end);    //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
    ● erase(elem);            //删除容器中值为elem的元素。
*/
//插入和删除
void test04()
{
	set<int> s1;
	//插入
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);
	//删除
	s1.erase(s1.begin());
	printSet(s1);
	s1.erase(30);
	printSet(s1);
	//清空
	//s1.erase(s1.begin(), s1.end());
	s1.clear();
	printSet(s1);
}
// 4. 查找和统计
/*
    功能描述：
    ● 对set容器进行查找数据以及统计数据
    函数原型：
    ● find(key);                  //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
    ● count(key);                //统计key的元素个数
*/
void test05()
{
	set<int> s1;
	//插入
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	
	//查找
	set<int>::iterator pos = s1.find(30); // 返回的是迭代器
	if (pos != s1.end())
	{
		cout << "找到了元素 ： " << *pos << endl; // 使用解引用拿到值
	}
	else
	{
		cout << "未找到元素" << endl;
	}
	//统计
	int num = s1.count(30);
	cout << "num = " << num << endl;
}
// 5. set和multiset区别
/*
    区别：
    ● set不可以插入重复数据，而multiset可以
    ● set插入数据的同时会返回插入结果，表示插入是否成功
    ● multiset不会检测数据，因此可以插入重复数据
*/
void test06()
{
	set<int> s;
    // insert方法会返回一个pair类型的数据类型 其结果是<增加的迭代器,增加是否成功的bool>
	pair<set<int>::iterator, bool>  ret = s.insert(10); 
	if (ret.second) {
		cout << "第一次插入成功!" << endl;
	}
	else {
		cout << "第一次插入失败!" << endl;
	}
	ret = s.insert(10);
	if (ret.second) {
		cout << "第二次插入成功!" << endl;
	}
	else {
		cout << "第二次插入失败!" << endl;
	}
    
	//multiset
    // multiset插入并不会返回上述set插入的pair的值,也就是说不会判断是否插入成功
	multiset<int> ms;
	ms.insert(10);
	ms.insert(10);
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


// 6. pair对组创建
/*
    功能描述：
    ● 成对出现的数据，利用对组可以返回两个数据
    两种创建方式：
    ● pair<type, type> p ( value1, value2 );
    ● pair<type, type> p = make_pair( value1, value2 );
*/
void test07(){
    pair<string, int> p(string("Tom"), 20);
	cout << "姓名： " <<  p.first << " 年龄： " << p.second << endl;
	pair<string, int> p2 = make_pair("Jerry", 10);
	cout << "姓名： " << p2.first << " 年龄： " << p2.second << endl;
}

// 7. set容器排序
/*
    set容器默认排序规则为从小到大 利用仿函数，可以改变排序规则
*/
class MyCompare{
    public:
        bool operator()(int v1, int v2){ // 第一个小括号,表示重载小括号
            return v1 > v2;
        }
};
void test08(){
    set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	s1.insert(50);
	//默认从小到大
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	} // 在插入数据之后,就已经是从小到大了,因此要在插入的时候就确定从大到小的排序
	cout << endl;
	// 利用仿函数指定内置数据类型排序规则
	set<int,MyCompare> s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(30);
	s2.insert(50);
	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
// 指定自定义数据类型的排序规则
class Person{
public:
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
    string name;
    int age;
};

class comparePerson
{
    public:
        bool operator()(const Person& p1, const Person& p2){
            return p1.age > p2.age;
        }
};


void test09(){
    Person p1("zhangsan", 12);
    Person p2("lisi", 11);  
    Person p3("wangwu", 23);
    Person p4("laoliu", 45);
    // set<Person> s; // 对于自定义数据类型,必须要给定排序规则,不然set本身不知道要怎么排序
    set<Person, comparePerson> s;
    
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    
    for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << it->name << " " << it->age << endl;
    }
    
}

int main(){

    // set和multiset
    // 所有元素都会在插入时自动被排序
    // set/multiset属于关联式容器，底层结构是用二叉树实现。
    /*
    set和multiset区别：
        ● set不允许容器中有重复的元素
        ● multiset允许容器中有重复的元素
    */

    // 1. 构造和赋值
    test01();
    // 2. 大小和交换
    test02();
    test03();
    // 3. 插入和删除
    test04();
    // 4. 查找和统计
    test05();
    // 5. set和multiset区别
    test06();
    // 6. pair对组创建
    test07();
    // 7. set容器排序
    test08();

    test09();

    return 0;
}