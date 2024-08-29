#include <iostream>
#include <vector>

using namespace std;

// vector构造函数
/*
    功能描述：
    ● 创建vector容器
    函数原型：
    ● vector<T> v;               		     //采用模板实现类实现，默认构造函数
    ● vector(v.begin(), v.end());       //将v[begin(), end())区间中的元素拷贝给本身。  前闭后开区间，因为end指向的是最后一个元素的后面一个位置
    ● vector(n, elem);                            //构造函数将n个elem拷贝给本身。
    ● vector(const vector &vec);         //拷贝构造函数。
*/
void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}

    
	cout << endl;
}
void test01()
{
	vector<int> v1; //无参构造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i); // 往里面填充数据
	}
	printVector(v1);
    // 区间构造
	vector<int> v2(v1.begin(), v1.end()); // 利用区间构造vector容器，迭代器中的begin和end确定了v1中所有的数据
	printVector(v2);
    // n个elem的方式
	vector<int> v3(10, 100); // 10个100给v3
	printVector(v3);
	// 拷贝构造
	vector<int> v4(v3);
	printVector(v4);
}

// 赋值
/*
    功能描述：
    ● 给vector容器进行赋值
    函数原型：
    ● vector& operator=(const vector &vec);//重载等号操作符
    ● assign(beg, end);       //将[beg, end)区间中的数据拷贝赋值给本身。
    ● assign(n, elem);        //将n个elem拷贝赋值给本身。
*/
void test02()
{
	vector<int> v1; //无参构造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

    // operator=
	vector<int>v2;
	v2 = v1;
	printVector(v2);
    // assign(beg, end) 区间赋值
	vector<int>v3;
	v3.assign(v1.begin(), v1.end());
	printVector(v3);
    // assign(n, elem) n个elem
	vector<int>v4;
	v4.assign(10, 100);
	printVector(v4);
}

// 容量和大小
/*
    功能描述：
    ● 对vector容器的容量和大小操作
    函数原型：
    ● empty();                            //判断容器是否为空
    ● capacity();                      //容器的容量 始终大于等于容器的元素个数
    ● size();                              //返回容器中元素的个数
    ● resize(int num);             //重新指定容器的长度为num，若容器变长，则以默认值0填充新位置。
                            //如果容器变短，则末尾超出容器长度的元素被删除。
    ● resize(int num, elem);  //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
                                //如果容器变短，则末尾超出容器长度的元素被删除
*/
void test03()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	if (v1.empty()) // 判断是否为空 
	{
		cout << "v1为空" << endl;
	}
	else
	{
		cout << "v1不为空" << endl;
		cout << "v1的容量 = " << v1.capacity() << endl;
		cout << "v1的大小 = " << v1.size() << endl;
	}
	//resize 重新指定大小 ，若指定的更大，默认用0填充新位置，可以利用重载版本替换默认填充 ，
    // 当给定了第二个参数的时候，就会使用给定的第二个参数的值来做填充值
	v1.resize(15,10);
	printVector(v1);
	//resize 重新指定大小 ，若指定的更小，超出部分元素被删除
	v1.resize(5);
	printVector(v1);
}

// 插入和删除
/*
    功能描述：
    ● 对vector容器进行插入、删除操作
    函数原型：
    ● push_back(ele);                                         //尾部插入元素ele
    ● pop_back();                                                //删除最后一个元素
    ● insert(const_iterator pos, ele);        //迭代器指向位置pos插入元素ele
    ● insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele
    ● erase(const_iterator pos);                     //删除迭代器指向的元素
    ● erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
    ● clear();                                                        //删除容器中所有元素
*/
void test04(){

    vector<int> v1;
	//尾插
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector(v1);
	//尾删
	v1.pop_back();
	printVector(v1);
	//插入
    // insert方法要提供一个迭代器作为第一个参数
	v1.insert(v1.begin(), 100);
	printVector(v1);
    // 迭代器begin位置插入2个1000
	v1.insert(v1.begin(), 2, 1000);
	printVector(v1);
	//删除
	v1.erase(v1.begin());
	printVector(v1);
	//清空
    // erase清除给定两个迭代器之间的元素
	v1.erase(v1.begin(), v1.end()); // 这样写就是清除所有值 等同于下面的 clear
	v1.clear();
	printVector(v1);
}

// 数据存取
/*
    功能描述：
    ● 对vector中的数据的存取操作
    函数原型：
    ● at(int idx);     //返回索引idx所指的数据
    ● operator[];       //返回索引idx所指的数据
    ● front();            //返回容器中第一个数据元素
    ● back();              //返回容器中最后一个数据元素
*/
void test05()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " "; // 使用下标查找
	}
	cout << endl;
	cout << "v1的第一个元素为： " << v1.front() << endl;
	cout << "v1的最后一个元素为： " << v1.back() << endl;
}

// 互换容器
/*
    功能描述：
    ● 实现两个容器内元素进行互换
    函数原型：
    ● swap(vec);  // 将vec与本身的元素互换
*/
void test06()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	vector<int>v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector(v2);
	//互换容器
	cout << "互换后" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}
// 实际用途，巧用swap收缩内存空间
void test07()
{
	vector<int> v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

	v.resize(3); // 重新指定大小，只是重新制定了元素数量
	cout << "v的容量为：" << v.capacity() << endl; // resize后的容量还是不变，原本的占据的内存还在被占用
	cout << "v的大小为：" << v.size() << endl; // 但是size确实已经变了
	//收缩内存
	vector<int>(v).swap(v); //匿名对象
    // vector<int>(v)根据v做了一个匿名对象，匿名对象的特性就是执行完之后编译器会自动回收内存
    // 所以根据3个元素的v构建了一个小的vector对象，然后两者交换之后，v指向了一个容量为3的对象，以此做到收缩内存的效果
    // 而现在匿名对象就指向了之前那个很大容量的内存，然后随着匿名对象的特性，会被自动回收
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;
}

// 预留空间
/*
    功能描述：
    ● 减少vector在动态扩展容量时的扩展次数
    函数原型：
    ● reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
*/
void test08(){

    vector<int> v;
	//预留空间
	v.reserve(100000); // 增加这行代码，使程序预留这么大的内存，那么就只用开辟一次内存就够了
    
	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
		if (p != &v[0]) { // 如果p没有指向首地址，那么就是说vector开辟了一次内存， 计算总共分配了多少次内存
			p = &v[0];
			num++;
		}
	}
	cout << "num:" << num << endl; // 计算分配了多少次内存
}
int main(){
    // STL中常用容器
    // 2. vector
    /*
    功能：
        ● vector数据结构和数组非常相似，也称为[单端数组]
        vector与普通数组区别：
        ● 不同之处在于数组是静态空间，而vector可以动态扩展
    动态扩展：
        ● 并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间

    ● vector容器的迭代器是支持随机访问的迭代器

     在尾部进行操作
    */

    // 2.1 构造函数
    test01();

    // 2. 赋值操作
    test02();

    // 3. vector容量和大小
    test03();

    // 4. 插入和删除
    test04();

    // 5. 数据存取
    test05();

    // 6. 互换容器
    test06();
    test07();

    // 7. 预留空间
    test08();

    return 0;
}