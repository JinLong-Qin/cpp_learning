#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
// copy
/*
    功能描述：
    ● 容器内指定范围的元素拷贝到另一容器中
    函数原型：
    ● copy(iterator beg, iterator end, iterator dest);
    // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
    // beg  开始迭代器
    // end  结束迭代器
    // dest 目标起始迭代器
*/
void test01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i + 1);
	}
	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;
}

// replace
/*
    功能描述：
    ● 将容器内指定范围的旧元素修改为新元素
    函数原型：
    ● replace(iterator beg, iterator end, oldvalue, newvalue);
    // 将区间内旧元素 替换成 新元素
    // beg 开始迭代器
    // end 结束迭代器
    // oldvalue 旧元素
    // newvalue 新元素
*/
void test02()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);
	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
	//将容器中的20 替换成 2000
	cout << "替换后：" << endl;
	replace(v.begin(), v.end(), 20,2000);
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

// replace_if
/*
    功能描述:
    ● 将区间内满足条件的元素，替换成指定元素
    函数原型：
    ● replace_if(iterator beg, iterator end, _pred, newvalue);
    // 按条件替换元素，满足条件的替换成指定元素
    // beg 开始迭代器
    // end 结束迭代器
    // _pred 谓词
    // newvalue 替换的新元素

    replace_if按条件查找，可以利用仿函数灵活筛选满足的条件
*/
class ReplaceGreater30
{
public:
	bool operator()(int val)
	{
		return val >= 30;
	}
};
void test03()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);
	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
	//将容器中大于等于的30 替换成 3000
	cout << "替换后：" << endl;
	replace_if(v.begin(), v.end(), ReplaceGreater30(), 3000); // 区间，替换条件筛选，替换的值
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

// swap
/*
    功能描述：
    ● 互换两个同类型的容器的元素 
    函数原型：
    ● swap(container c1, container c2);
    // 互换两个容器的元素
    // c1容器1
    // c2容器2
*/
void test04()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i+100);
	}
	cout << "交换前： " << endl;
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;
	cout << "交换后： " << endl;
	swap(v1, v2);
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;
}


int main(){
    // 常用拷贝和替换算法
    /*
    ● copy                      // 容器内指定范围的元素拷贝到另一容器中
    ● replace                // 将容器内指定范围的旧元素修改为新元素
    ● replace_if          // 容器内指定范围满足条件的元素替换为新元素
    ● swap                     // 互换两个容器的元素
    */

    // copy
    test01();

    // replace
    test02();

    // replace_if
    test03();

    // swap
    test04();
    return 0;
}