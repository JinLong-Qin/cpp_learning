#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// ● accumulate      // 计算容器区间内的元素累计总和 很常用
/*
    功能描述：
    ● 计算区间内 容器元素累计总和
    函数原型：
    ● accumulate(iterator beg, iterator end, value);
    // 计算容器元素累计总和
    // beg 开始迭代器
    // end 结束迭代器
    // value 起始值
*/
void test01()
{
	vector<int> v;
	for (int i = 0; i <= 100; i++) {
		v.push_back(i);
	}
	int total = accumulate(v.begin(), v.end(), 0);
	cout << "total = " << total << endl;
}
    
// ● fill                 // 向容器中添加元素
/*
    功能描述：
    ● 向容器中填充指定的元素
    函数原型：
    ● fill(iterator beg, iterator end, value);
    // 向容器中填充元素
    // beg 开始迭代器
    // end 结束迭代器
    // value 填充的值
*/
class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test02()
{
	vector<int> v;
	v.resize(10);
	//填充
	fill(v.begin(), v.end(), 100);
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}
int main(){
    // 算术生成算法
    // 算术生成算法属于小型算法，使用时包含的头文件为 #include <numeric>

    // ● accumulate      // 计算容器元素累计总和
    test01();
    // ● fill                 // 向容器中添加元素
    test02();
    return 0;
}