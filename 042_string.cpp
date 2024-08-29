#include <iostream>
#include <string>

using namespace std;

// string容器
//string构造
// string的多种构造方式没有可比性，灵活使用即可
/*
    string构造函数原型：
    ● string();          				//创建一个空的字符串 例如: string str;
    ● string(const char* s);	        //使用字符串s初始化
    ● string(const string& str);    //使用一个string对象初始化另一个string对象
    ● string(int n, char c);           //使用n个字符c初始化
*/
void test01()
{
	string s1; //创建空字符串，调用无参构造函数
	cout << "str1 = " << s1 << endl;
	const char* str = "hello world";
	string s2(str); //把c_string转换成了string
	cout << "str2 = " << s2 << endl;
	string s3(s2); //调用拷贝构造函数
	cout << "str3 = " << s3 << endl;
	string s4(10, 'a');
	cout << "str4 = " << s4 << endl;
}

//string赋值
/*
    赋值的函数原型：
    ● string& operator=(const char* s);             //char*类型字符串 赋值给当前的字符串
    ● string& operator=(const string &s);         //把字符串s赋给当前的字符串
    ● string& operator=(char c);                          //字符赋值给当前的字符串
    ● string& assign(const char *s);                  //把字符串s赋给当前的字符串
    ● string& assign(const char *s, int n);     //把字符串s的前n个字符赋给当前的字符串
    ● string& assign(const string &s);              //把字符串s赋给当前字符串
    ● string& assign(int n, char c);                  //用n个字符c赋给当前字符串
*/
void test02()
{
	string str1;
	str1 = "hello world";
	cout << "str1 = " << str1 << endl;
	string str2;
	str2 = str1;
	cout << "str2 = " << str2 << endl;
	string str3;
	str3 = 'a';
	cout << "str3 = " << str3 << endl;
	string str4;
	str4.assign("hello c++");
	cout << "str4 = " << str4 << endl;
	string str5;
	str5.assign("hello c++",5);
	cout << "str5 = " << str5 << endl;
	string str6;
	str6.assign(str5);
	cout << "str6 = " << str6 << endl;
	string str7;
	str7.assign(5, 'x');
	cout << "str7 = " << str7 << endl;
}

//字符串拼接
/*
    拼接函数原型：
    ● string& operator+=(const char* str);                   //重载+=操作符
    ● string& operator+=(const char c);                         //重载+=操作符
    ● string& operator+=(const string& str);                //重载+=操作符
    ● string& append(const char *s);                               //把字符串s连接到当前字符串结尾
    ● string& append(const char *s, int n);                 //把字符串s的前n个字符连接到当前字符串结尾
    ● string& append(const string &s);                           //同operator+=(const string& str)
    ● string& append(const string &s, int pos, int n);//字符串s中从pos开始的n个字符连接到字符串结尾
*/
void test03()
{
	string str1 = "我";
	str1 += "爱玩游戏";
	cout << "str1 = " << str1 << endl;
	
	str1 += ':';
	cout << "str1 = " << str1 << endl;
	string str2 = "LOL DNF";
	str1 += str2;
	cout << "str1 = " << str1 << endl;
	string str3 = "I";
	str3.append(" love ");
	str3.append("game abcde", 4);
	//str3.append(str2);
	str3.append(str2, 4, 3); // 从下标4位置开始 ，截取3个字符，拼接到字符串末尾
	cout << "str3 = " << str3 << endl;
}

// 字符串查找和替换
/*
    功能描述：
    ● 查找：查找指定字符串是否存在，返回值是出现的下标位置，没有找到就返回-1
    ● 替换：在指定的位置替换字符串
    函数原型：
    ● int find(const string& str, int pos = 0) const;              //查找str第一次出现位置,从pos开始查找
    ● int find(const char* s, int pos = 0) const;                     //查找s第一次出现位置,从pos开始查找
    ● int find(const char* s, int pos, int n) const;               //从pos位置查找s的前n个字符第一次位置
    ● int find(const char c, int pos = 0) const;                       //查找字符c第一次出现位置
    ● int rfind(const string& str, int pos = npos) const;      //查找str最后一次位置,从pos开始查找
    ● int rfind(const char* s, int pos = npos) const;              //查找s最后一次出现位置,从pos开始查找
    ● int rfind(const char* s, int pos, int n) const;              //从pos查找s的前n个字符最后一次位置
    ● int rfind(const char c, int pos = 0) const;                      //查找字符c最后一次出现位置
    ● string& replace(int pos, int n, const string& str);       //替换从pos开始n个字符为字符串str
    ● string& replace(int pos, int n,const char* s);                 //替换从pos开始的n个字符为字符串s
*/
void test04(){
    //查找
	string str1 = "abcdefgde";
	int pos = str1.find("de"); 
	if (pos == -1)
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "pos = " << pos << endl;
	}
	
	pos = str1.rfind("de");
	cout << "pos = " << pos << endl;
}
void test05(){
    //替换
	string str1 = "abcdefgde";
	str1.replace(1, 3, "1111");
	cout << "str1 = " << str1 << endl;
}

// 字符串比较
/*
    功能描述：
    ● 字符串之间的比较
    比较方式：
    ● 字符串比较是按字符的ASCII码进行对比
        = 返回   0
        > 返回   1
        < 返回  -1
    函数原型：
    ● int compare(const string &s) const;  //与字符串s比较
    ● int compare(const char *s) const;      //与字符串s比较

    字符串对比主要是用于比较两个字符串是否相等，字符串的大小并没有意义
*/
void test06(){
    string s1 = "hello";
	string s2 = "aello";
	int ret = s1.compare(s2);
	if (ret == 0) {
		cout << "s1 等于 s2" << endl;
	}
	else if (ret > 0)
	{
		cout << "s1 大于 s2" << endl;
	}
	else
	{
		cout << "s1 小于 s2" << endl;
	}
}

// 字符串存取
/*
    string中单个字符存取方式有两种
    ● char& operator[](int n);     //通过[]方式取字符
    ● char& at(int n);                    //通过at方法获取字符 小括号中是下标
*/
void test07()
{
	string str = "hello world";
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;
	//字符修改
	str[0] = 'x';
	str.at(1) = 'x';
	cout << str << endl;
	
}

// 字符串插入和删除
/*
    功能描述：
    ● 对string字符串进行插入和删除字符操作
    函数原型：
    ● string& insert(int pos, const char* s);                //插入字符串
    ● string& insert(int pos, const string& str);        //插入字符串
    ● string& insert(int pos, int n, char c);                //在指定位置插入n个字符c
    ● string& erase(int pos, int n = npos);                    //删除从Pos开始的n个字符
*/
void test08(){
    string str = "hello";
	str.insert(1, "111");
	cout << str << endl;
	str.erase(1, 3);  //从1号位置开始3个字符
	cout << str << endl;
}

// 字串
/*
    功能描述：
    ● 从字符串中获取想要的子串
    函数原型：
    ● string substr(int pos = 0, int n = npos) const;   //返回由pos开始的n个字符组成的字符串
*/
void test09(){
    string str = "abcdefg";
	string subStr = str.substr(1, 3);
	cout << "subStr = " << subStr << endl;
	string email = "hello@sina.com";
	int pos = email.find("@");
	string username = email.substr(0, pos);
	cout << "username: " << username << endl;
}

int main(){
    // STL中常用容器
    // 1. string
    /*
    本质：
    ● string是C++风格的字符串，而string本质上是一个类
    **string和char  区别：
    ● char * 是一个指针
    ● string是一个类，类内部封装了char*，管理这个字符串，是一个char*型的容器。
    特点：
    string 类内部封装了很多成员方法
    例如：查找find，拷贝copy，删除delete 替换replace，插入insert
    [string管理char*所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责]
    */

    // 字符串构造函数
    test01();
    // 字符串赋值
    test02();
    // 字符串拼接
    test03();
    // 查找和替换
    test04();
    test05();
    // 字符串比较
    test06();
    // 字符串存取
    test07();
    // 字符串插入和删除
    test08();
    // 子串
    test09();

    return 0;
}