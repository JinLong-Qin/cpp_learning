#include <iostream>
#include <fstream> // 1.包含头文件
#include <string>

using namespace std;

void test01()
{
    // 2.创建文件输出流对象
	ofstream ofs;
    // 3.打开文件（文件路径，打开方式）
	ofs.open("test.txt", ios::out);
    // 4.写入数据
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;
    // 5.关闭文件流
	ofs.close();
}

void test02(){
    ifstream ifs;
	ifs.open("test.txt", ios::in);

    // 对文件做判断，可能文件不存在
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//第一种方式
	//char buf[1024] = { 0 };
	//while (ifs >> buf) // 右运算符讲文件流中的内容放置到buf中
	//{
	//	cout << buf << endl;
	//}

	//第二种
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf,sizeof(buf))) // ifs对象的getline方法可以一次获取一行内容，（要将内容放置到哪里，最多读取多少个字符）
	//{
	//	cout << buf << endl;
	//}

	//第三种
	//string buf;
	//while (getline(ifs, buf)) // getline全局函数（输入流对象，读取到的内容要放置到的变量中）
	//{
	//	cout << buf << endl;
	//}

	char c;
	while ((c = ifs.get()) != EOF) // get函数按照字符一个个读取，判断每次读取到的字符是否到达文件末尾
	{
		cout << c;
	}

	ifs.close();
}


// 二进制
class Person
{
public:
	char m_Name[64];
	int m_Age;
};

//二进制文件  写文件
void test03()
{
	//1、包含头文件

	//2、创建输出流对象
	ofstream ofs("person.txt", ios::out | ios::binary); // 可以在定义ofs对象的时候就使用构造函数初始化对象，即将第二步和第三步合成一步
	
	//3、打开文件
	//ofs.open("person.txt", ios::out | ios::binary);

	Person p = {"张三"  , 18};

	//4、写文件
	ofs.write((const char *)&p, sizeof(p));

	//5、关闭文件
	ofs.close();
}


void test04()
{
    // 通过构造函数初始化ifs对象
    // 读文件in和以二进制形式binary
	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
	}

	Person p;
	ifs.read((char *)&p, sizeof(p));

	cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
}

int main() {

	// test01();
    test02();

    // 二进制
    // 二进制的操作方式可能会存在一些乱码，但是只要二进制读取是正确的就行
    // test03();

    test04();

    // 文件操作
    // 程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放
    // 通过文件操作可以将数据持久化

    /*
    文件类型分为两种：

        1. 文本文件     -  文件以文本的ASCII码形式存储在计算机中
        2. 二进制文件 -  文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂它们
    */

   /*
   操作文件的三大类:

        1. ofstream：写操作
        2. ifstream： 读操作
        3. fstream ： 读写操作
   */

    // 1. 文本文件
    // 1.1 写文件
    /*
        写作步骤
        1.  包含头文件
        #include <fstream> 
        2.  创建流对象
        ofstream ofs; 
        3.  打开文件
        ofs.open("文件路径",打开方式); 
        4.  写数据
        ofs << "写入的数据"; 
        5.  关闭文件
        ofs.close();
    */

   // 1.2 读文件
    /*
        写作步骤
        1.  包含头文件
        #include <fstream> 
        2.  创建流对象
        ifstream ifs; 
        3.  打开文件
        ofs.open("文件路径",打开方式); 
        4.  读数据
        四种方式读取 
        5.  关闭文件
        ofs.close();
    */

    /*
    文件打开方式
        ios::in	为读文件而打开文件
        ios::out	为写文件而打开文件
        ios::ate	初始位置：文件尾
        ios::app	追加方式写文件
        ios::trunc	如果文件存在先删除，再创建
        ios::binary	二进制方式

    注意： 文件打开方式可以配合使用，利用|操作符
    进制方式写文件 ios::binary | ios:: out
    */


    // 2.二进制读取文件
    // 打开方式要指定为 ios::binary
    // 2.1 二进制形式写文件
    // 二进制方式写文件主要利用流对象调用成员函数write
    // 函数原型 ：ostream& write(const char * buffer,int len);
    // 解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数
    // 二进制文件不仅可以操作原始的数据类型，还可以操作自定义的数据类型


    // 2.2 二进制读
    // 二进制方式读文件主要利用流对象调用成员函数read
    // 函数原型：istream& read(char *buffer,int len);
    // 参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数






    return 0;
}