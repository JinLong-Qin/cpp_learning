#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
// ● set_intersection          // 求两个容器的交集
/*
    功能描述：
    ● 求两个容器的交集
    函数原型：
    ● set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
    // 求两个集合的交集
    // 注意:两个集合必须是有序序列
    // beg1 容器1开始迭代器
    // end1 容器1结束迭代器
    // beg2 容器2开始迭代器
    // end2 容器2结束迭代器
    // dest 目标容器开始迭代器


    ● 求交集的两个集合必须的[有序序列]
    ● 目标容器开辟空间需要从两个容器中取小值
    ● set_intersection返回值既是交集中最后一个元素的位置
*/

void test01()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
    {
		v1.push_back(i);
		v2.push_back(i+5);
	}
	vector<int> vTarget;
	//取两个里面较小的值给目标容器开辟空间
	vTarget.resize(min(v1.size(), v2.size()));
	//返回目标容器的最后一个元素的迭代器地址
	vector<int>::iterator itEnd = 
        set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;
}
// ● set_union                       // 求两个容器的并集
/*
    功能描述：
    ● 求两个集合的并集
    函数原型：
    ● set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
    // 求两个集合的并集
    // 注意:两个集合必须是有序序列
    // beg1 容器1开始迭代器
    // end1 容器1结束迭代器
    // beg2 容器2开始迭代器
    // end2 容器2结束迭代器
    // dest 目标容器开始迭代器

    ● 求并集的两个集合必须的有序序列
    ● 目标容器开辟空间需要两个容器相加
    ● set_union返回值既是并集中最后一个元素的位置
*/
void test02()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i+5);
	}
	vector<int> vTarget;
	//取两个容器的和给目标容器开辟空间
	vTarget.resize(v1.size() + v2.size());
	//返回目标容器的最后一个元素的迭代器地址
	vector<int>::iterator itEnd = 
        set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
        // 结束的迭代器位置可能和当时申请空间的结束迭代器的位置不是一个位置，所以要单独来去获取结束位置，用以后面遍历操作
	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;
}
// ● set_difference              // 求两个容器的差集
/*
    功能描述：
    ● 求两个集合的差集
    函数原型：
    ● set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
    // 求两个集合的差集
    // 注意:两个集合必须是有序序列
    // beg1 容器1开始迭代器
    // end1 容器1结束迭代器
    // beg2 容器2开始迭代器
    // end2 容器2结束迭代器
    // dest 目标容器开始迭代器

    ● 求差集的两个集合必须的有序序列
    ● 目标容器开辟空间需要从两个容器取较大值
    ● set_difference返回值既是差集中最后一个元素的位置

    // 差集的概念是相对的，是集合1相对于集合2的差集
    // 两个集合，s1, s2；
    // s1相对于s2的差集，就看s1中，不是s1和s2的交集的内容
    // s2相对于s1的差集，就看s2中，不是s1和s2的交集的内容
*/
void test03()
{
	vector<int> v1; // 0-9
	vector<int> v2; // 5-14
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i+5);
	}
	vector<int> vTarget;
	//取两个里面较大的值给目标容器开辟空间
	vTarget.resize( max(v1.size() , v2.size()));
	//返回目标容器的最后一个元素的迭代器地址
	cout << "v1与v2的差集为： " << endl;
	vector<int>::iterator itEnd = 
        set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;
	cout << "v2与v1的差集为： " << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;
}

int main(){

    // 常用集合算法
    
    // ● set_intersection          // 求两个容器的交集
    test01();
    // ● set_union                       // 求两个容器的并集
    test02();
    // ● set_difference              // 求两个容器的差集
    test03();

    return 0;
}