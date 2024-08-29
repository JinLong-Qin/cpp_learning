#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

void printList(const list<int>& L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

// 1. 构造函数
/*
    功能描述：
    ● 创建list容器
    函数原型：
    ● list<T> lst;                               //list采用采用模板类实现,对象的默认构造形式：
    ● list(beg,end);                           //构造函数将[beg, end)区间中的元素拷贝给本身。
    ● list(n,elem);                             //构造函数将n个elem拷贝给本身。
    ● list(const list &lst);            //拷贝构造函数。
*/
void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);
    // 区间构造
	list<int>L2(L1.begin(),L1.end());
	printList(L2);
    // 拷贝构造
	list<int>L3(L2);
	printList(L3);
    // n个elem构造
	list<int>L4(10, 1000);
	printList(L4);
}

// 2. 赋值和交换
/*
    功能描述：
    ● 给list容器进行赋值，以及交换list容器
    函数原型：
    ● assign(beg, end);            //将[beg, end)区间中的数据拷贝赋值给本身。
    ● assign(n, elem);              //将n个elem拷贝赋值给本身。
    ● list& operator=(const list &lst);         //重载等号操作符
    ● swap(lst);                         //将lst与本身的元素互换。
*/
//赋值
void test02()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);
	// operator=
	list<int>L2;
	L2 = L1;
	printList(L2);
    // 区间赋值
	list<int>L3;
	L3.assign(L2.begin(), L2.end());
	printList(L3);
    // n个elem赋值
	list<int>L4;
	L4.assign(10, 100);
	printList(L4);
}
//交换
void test03()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	list<int>L2;
	L2.assign(10, 100);
	cout << "交换前： " << endl;
	printList(L1);
	printList(L2);
	cout << endl;
	L1.swap(L2);
	cout << "交换后： " << endl;
	printList(L1);
	printList(L2);
}

// 3. 大小操作
/*
    功能描述：
    ● 对list容器的大小进行操作
    函数原型：
    ● size();                             //返回容器中元素的个数
    ● empty();                           //判断容器是否为空
    ● resize(num);                   //重新指定容器的长度为num，若容器变长，则以默认值0填充新位置。
                            //如果容器变短，则末尾超出容器长度的元素被删除。
    ● resize(num, elem);       //重新指定容器的长度为num，若容器变长，则以elem值填充新位置
*/
void test04()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	if (L1.empty())
	{
		cout << "L1为空" << endl;
	}
	else
	{
		cout << "L1不为空" << endl;
		cout << "L1的大小为： " << L1.size() << endl;
	}
	//重新指定大小
	L1.resize(10);
	printList(L1);
	L1.resize(2);
	printList(L1);
}
// 4, 插入和删除
/*
    功能描述：
    ● 对list容器进行数据的插入和删除
    函数原型：
    ● push_back(elem);//在容器尾部加入一个元素
    ● pop_back();//删除容器中最后一个元素
    ● push_front(elem);//在容器开头插入一个元素
    ● pop_front();//从容器开头移除第一个元素
    ● insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
    ● insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
    ● insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
    ● clear();//移除容器的所有数据
    ● erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
    ● erase(pos);//删除pos位置的数据，返回下一个数据的位置。
    ● remove(elem);//删除容器中所有与elem值匹配的元素。
*/
void test05()
{
	list<int> L;
	//尾插
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	//头插
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);
	printList(L);
	//尾删
	L.pop_back();
	printList(L);
	//头删
	L.pop_front();
	printList(L);
	//插入
	list<int>::iterator it = L.begin();
	L.insert(++it, 1000);
	printList(L);
	//删除
	it = L.begin();
	L.erase(++it);
	printList(L);
	//移除
	L.push_back(10000);
	L.push_back(10000);
	L.push_back(10000);
	printList(L);
	L.remove(10000);
	printList(L);
    
    //清空
	L.clear();
	printList(L);
}

// 5 数据存取
/*
    功能描述：
    ● 对list容器中数据进行存取
    函数原型：
    ● front();        //返回第一个元素。
    ● back();         //返回最后一个元素
*/
void test06()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	
	//cout << L1.at(0) << endl;//错误 不支持at访问数据
	//cout << L1[0] << endl; //错误  不支持[]方式访问数据
	cout << "第一个元素为： " << L1.front() << endl;
	cout << "最后一个元素为： " << L1.back() << endl;
	//list容器的迭代器是双向迭代器，不支持随机访问,只能按顺序访问
	list<int>::iterator it = L1.begin();
	//it = it + 1;//错误，不可以跳跃访问，即使是+1
    it++; // 后面一个元素
    it--; // 前面一个元素 因为是双向循环链表,所以可以--
}

// 6.反转和排序
/*
    功能描述：
    ● 将容器中的元素反转，以及将容器中的数据进行排序
    函数原型：
    ● reverse();   //反转链表
    ● sort();        //链表排序
*/
// 提供两个数的对比,
bool myCompare(int val1 , int val2)
{   // 降序,使第一个数大于第二个数
	return val1 > val2;
}
//反转和排序
void test07()
{
	list<int> L;
	L.push_back(90);
	L.push_back(30);
	L.push_back(20);
	L.push_back(70);
	printList(L);
	//反转容器的元素
	L.reverse();
	printList(L);

    // sort(L.begin(), L.end()); // 不支持随机访问的迭代器的容器,都会再内部提供对应的成员函数以实现算法内容
	//排序
	L.sort(); //默认的排序规则 从小到大
	printList(L);
	L.sort(myCompare); //指定规则，从大到小
	printList(L);
}

// 7. 排序案例
class Person{
public:
    int age;
    int height;
    string name;

    Person(string name, int age, int height){
        this->name = name;
        this->age = age;
        this->height=height;
    }

};

bool comparePerson(Person& p1, Person& p2){
    // 按照年龄进行升序，如果年龄相同按照身高进行降序
    if(p1.age == p2.age){
        return p1.height > p2.height;
    }else{
        return p1.age < p2.age;
    }
}

void test(){
    Person p1("liming", 12, 120);
    Person p2("zhangsan", 33, 120);
    Person p3("wangwu", 24, 120);
    Person p4("zhaosi", 24, 150);

    list<Person> lst;
    lst.push_back(p1);
    lst.push_back(p2);
    lst.push_back(p3);
    lst.push_back(p4);

    lst.sort(comparePerson);

    for (list<Person>::iterator it = lst.begin(); it != lst.end(); it++)
    {
        cout << it->name << "  " << it->age << "  " << it->height << endl ;
    }
    
}

int main(){
    // list 链表
    /*
    功能：将数据进行链式存储
    链表（list）是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的
    链表的组成：链表由一系列结点组成
    结点的组成：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域
    
    [STL中的链表是一个双向循环链表]
    
    
    由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于双向迭代器
    list的优点：
    ● 采用动态存储分配，不会造成内存浪费和溢出
    ● 链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素
    list的缺点：
    ● 链表灵活，但是空间(指针域) 和 时间（遍历）额外耗费较大
    List有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的。
    总结：STL中List和vector是两个最常被使用的容器，各有优缺点
    */
    // 1. 构造函数
    test01();

    // 2. 赋值和交换
    test02();
    test03();
    // 3. 大小操作
    test04();

    // 4, 插入和删除
    test05();
    // 5 数据存取
    test06();
    // 6.反转和排序
    test07();
    // 7. 排序案例
    // 案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
    // 排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序
    test();
    return 0;
}