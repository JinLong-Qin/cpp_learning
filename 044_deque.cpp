#include <iostream>
#include <deque>

using namespace std;

// 若是只想做读操作，可以在参数中增加const关键字，
void printDeque(const deque<int>& d) 
{
    // 对应的迭代器就也要进行修改，变为const_iterator
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        // 此时，迭代器读取出的内容就是不可修改的了
        // *it = 100;
		cout << *it << " ";
	}
	cout << endl;
}

// 构造函数
/*
    功能描述：
    ● deque容器构造
    函数原型：
    ● deque<T> deqT;                      //默认构造形式
    ● deque(beg, end);                  //构造函数将[beg, end)区间中的元素拷贝给本身。
    ● deque(n, elem);                    //构造函数将n个elem拷贝给本身。
    ● deque(const deque &deq);   //拷贝构造函数
*/

//deque构造
void test01() {
	deque<int> d1; //无参构造函数
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
    // 区间赋值
	deque<int> d2(d1.begin(),d1.end());
	printDeque(d2);
    // n个ele赋值
	deque<int>d3(10,100);
	printDeque(d3);
    // 拷贝构造
	deque<int>d4 = d3;
	printDeque(d4);
}

// 赋值操作
/*
    功能描述：
    ● 给deque容器进行赋值
    函数原型：
    ● deque& operator=(const deque &deq);         //重载等号操作符
    ● assign(beg, end);                                           //将[beg, end)区间中的数据拷贝赋值给本身。
    ● assign(n, elem);                                             //将n个elem拷贝赋值给本身。
*/
void test02(){
    deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
    // operator=
	deque<int>d2;
	d2 = d1;
	printDeque(d2);
    // 区间赋值
	deque<int>d3;
	d3.assign(d1.begin(), d1.end());
	printDeque(d3);
    // n和ele赋值
	deque<int>d4;
	d4.assign(10, 100);
	printDeque(d4);
}

// 大小操作
/*
    功能描述：
    ● 对deque容器的大小进行操作
    函数原型：
    ● deque.empty();                       //判断容器是否为空
    ● deque.size();                         //返回容器中元素的个数
    ● deque.resize(num);                //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
                                            //如果容器变短，则末尾超出容器长度的元素被删除。
    ● deque.resize(num, elem);     //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
                                                        //如果容器变短，则末尾超出容器长度的元素被删除。

    // 没有容量的操作，
*/
void test03(){
    deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	//判断容器是否为空
	if (d1.empty()) {
		cout << "d1为空!" << endl;
	}
	else {
		cout << "d1不为空!" << endl;
		//统计大小
		cout << "d1的大小为：" << d1.size() << endl;
	}
	//重新指定大小,以1为默认填充值
	d1.resize(15, 1);
	printDeque(d1);
    // 重新指定大小，变小了会丢弃多的值
	d1.resize(5);
	printDeque(d1);
}

// 插入和删除
/*
    功能描述：
    ● 向deque容器中插入和删除数据
    函数原型：
    两端插入操作：
    ● push_back(elem);          //在容器尾部添加一个数据
    ● push_front(elem);        //在容器头部插入一个数据
    ● pop_back();                   //删除容器最后一个数据
    ● pop_front();                 //删除容器第一个数据
    指定位置操作：
    ● insert(pos,elem);         //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
    ● insert(pos,n,elem);     //在pos位置插入n个elem数据，无返回值。
    ● insert(pos,beg,end);    //在pos位置插入[beg,end)区间的数据，无返回值。
    ● clear();                           //清空容器的所有数据
    ● erase(beg,end);             //删除[beg,end)区间的数据，返回下一个数据的位置。
    ● erase(pos);                    //删除pos位置的数据，返回下一个数据的位置。
*/
// 两端操作
void test04(){
    deque<int> d;
	//尾插
	d.push_back(10);
	d.push_back(20);
	//头插
	d.push_front(100);
	d.push_front(200);
	printDeque(d);
	//尾删
	d.pop_back();
	//头删
	d.pop_front();
	printDeque(d);
}
// 插入
void test05(){

    deque<int> d;
    // 尾插
	d.push_back(10);
	d.push_back(20);
    // 头插
	d.push_front(100);
	d.push_front(200);
	printDeque(d);
    // 在begin迭代器的位置增加
	d.insert(d.begin(), 1000);
	printDeque(d);
    // 在begin迭代器的位置增加2个10000
	d.insert(d.begin(), 2,10000);
	printDeque(d);

	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);
    // 在begin的位置,增加d2.begin和d2.end之间的值
	d.insert(d.begin(), d2.begin(), d2.end());
	printDeque(d);
}
//删除
void test06(){
    deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque(d);
    // 擦除begin的值
	d.erase(d.begin());
	printDeque(d);
    // 擦除begin和end之间的值 这样相当于clear
	d.erase(d.begin(), d.end());
	d.clear();
	printDeque(d);
}

// 数据存取
/*
    功能描述：
    ● 对deque 中的数据的存取操作
    函数原型：
    ● at(int idx);     //返回索引idx所指的数据
    ● operator[];      //返回索引idx所指的数据
    ● front();            //返回容器中第一个数据元素
    ● back();              //返回容器中最后一个数据元素
*/
void test07(){
    deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < d.size(); i++) {
		cout << d.at(i) << " ";
	}
	cout << endl;
	cout << "front:" << d.front() << endl;
	cout << "back:" << d.back() << endl;
}

// 排序
/*
    功能描述：
    ● 利用算法实现对deque容器进行排序
    算法：
    ● sort(iterator beg, iterator end)  //对beg和end区间内元素进行排序
*/
#include <algorithm> // 标准算法头文件
void test08(){

    deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque(d);
	sort(d.begin(), d.end());
	printDeque(d);
}

int main(){
    // deque 双端数组，可以对两头都进行插入删除操作
    /*
    deque与vector区别：
        ● vector对于头部的插入删除效率低，数据量越大，效率越低
        ● deque相对而言，对头部的插入删除速度回比vector快
        ● vector访问元素时的速度会比deque快,这和两者内部实现有关  vector是连续空间先行存储的

    deque内部工作原理:
        deque内部有个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据
        中控器维护的是每个缓冲区的地址，使得[使用deque时像一片连续的内存空间]
        没有容量的概念，因为可以不断地增加缓冲区中的地址，

    deque容器的迭代器也是支持随机访问的
    */

    // 1. 构造函数
    test01();

    // 2. 赋值操作
    test02();

    // 3. 大小操作
    test03();

    // 4. 插入和删除
    test04();
    test05();
    test06();

    // 5. 数据存取
    test07();

    // 6. 排序
    test08();

    return 0;
}