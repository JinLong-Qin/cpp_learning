#include <iostream>
using namespace std;
#include <string>

// 宏常量
#define Day 7

int main()
{
	// 输出
	cout << "hello world" << endl;
	
	
	// 变量。 数据类型 变量名称 = 变量初始值
	int a = 10;
	cout << "a = " << a << endl;
	
	// 常量 
	// 1.宏常量
	cout << "一周有" << Day << "天" << endl;
	// 2. const修饰的变量
	const int hours = 24;
	cout << "一天有" << hours << "小时" << endl;	
	// 常量一经定义不可以再进行修改
	
	// 标识符命名规则
	/**
	 * 1. 不能使用关键字
	 * 2. 只能由字母、数字、下划线组成
	 * 3. 第一个字符必须是字母或者下划线
	 * 4. 字母区分大小写
	 */
	 
	 
	 
	// 数据类型
	// 1. 整型
	 /**
	  * 数据类型		占用空间													取值范围
	  *  short		 2字节												-2^15 ~ 2^15-1
	  *  int		 4字节												-2^31 ~ 2^31-1
	  *  long		 4字节(windows和32位linux); 8字节(64位linux)			-2^31 ~ 2^31-1
	  *  long long	 8字节												-2^63 ~ 2^63-1
	  */
	
	 
	// 2. 实型
	 /**
	  * 数据类型		占用空间		 	取值范围
	  *  float		 4字节		   7位有效数字		单精度
	  *  double		 8字节		 15~16位有效数字		双精度
	  * 
	  * 小数点前后的数字都记在有效数字个数中
	  * 默认情况下，输出一个浮点数会显示6位有效数字
	  */
	  
	float f1 = 3.14f; // 在最后增加f后缀，将3.14转换为单精度值
	cout << "f1 = " << f1 << endl;
	double d1 = 3.14;
	cout << "d1 = " << d1 << endl;
	
	// 科学计数法
	float f2 = 3e2; // 表示 3 x 10^2
	cout << "f2 = " << f2 << endl;
	float f3 = 3e-2; // 表示 3 x 10^-2
	cout << "f3 = " << f3 << endl;
	
	
	// 字符型: 显示单个字符
	// 使用单引号，并且单引号中只能存在一个字符
	//! 字符变量并不是将字符存储到内存中，而是将字符对应的ASCII编码放入存储单元进行存储
	char ch = 'a';
	cout << "ch = " << ch << endl;
	
	// 字符变量对应的ASCII码
	cout << "the ASCII code of ch is " << int(ch) << endl;
	/**
	 * a - 97
	 * A - 65
	 */
	 
	 
	 // 转义字符
	 /**
	  * 转义字符			含义	
	  *   \a 			警报	
	  *   \b 			退格
	  *   \f			换页，将当前位置移动到下一页的开头
	  *   \n			换行，将当前位置移动到下一行开头
	  *   \r			回车，将当前位置移动到当前行开头
	  *   \t			水平制表符
	  *   \v			垂直制表符
	  *   \\			\
	  *   \'			'
	  *   \"			"
	  *   \?			?
	  *   \0			数字0
	  *   \ddd			8进制转义字符，d范围0~7
	  *   \xhh			16进制转义字符，h范围 0-9 A-F
	  *  
	  * */ 
	 
	// 字符串型, 用于表示一串字符
	// 1. c语言风格字符串
	char str1[] = "hello world";
	cout << "str1 = " << str1 << endl;
	// 2. cpp风格字符串 要引入string头文件
	string str = "hello world!";
	cout << "str = " << str << endl;
	
	// 布尔类型 bool
	// 只有两个值 true - 本质为1 和 false - 本质为0
	// 非0的值都可以为true
	bool flag = true;
	cout << "flag = " << flag << endl;
	
	
	// 数据的输入，用于从键盘获取数据
	// 1.整型
	//int aa = 0;
	//cout << "input the aa: " << endl;
	//cin >> aa;
	//cout << "aa = " << aa << endl;
	
	// 2.浮点型
	//float ff = 3.14f;
	//cout << "input the ff: " << endl;
	//cin >> ff;
	//cout << "ff = " << ff << endl;
	
	// 3.字符型
	//char cc = 'a';
	//cout << "input the cc: " << endl;
	//cin >> cc;
	//cout << "cc = " << cc << endl;
	
	// 4.字符串型
	//string ss = "hello";
	//cout << "input the ss: " << endl;
	//cin >> ss;
	//cout << "ss = " << ss << endl;
	// 5.布尔型
	//bool bb = true;
	//cout << "input the bb: " << endl;
	//cin >> bb;
	//cout << "bb = " << bb << endl;
	
	
	// 所有类型占据字节数
	cout << "-------------------------" << endl;
	cout << "所有数据类型占据字节数：" << endl;
	// 使用sizeof关键字可以统计数据类型所占内存大小
	// 单短整型占用4个字节
	cout << "sizeof(short) is " << sizeof(short) << endl;
	// 整型占用4个字节
	cout << "sizeof(int) is " << sizeof(int) << endl;
	// 长整型占用4个字节
	cout << "sizeof(long) is " << sizeof(long) << endl;
	// long long占用4个字节
	cout << "sizeof(long long) is " << sizeof(long long) << endl;
	// 整型大小比较: short < int <= long < long long
	
	// 单精度浮点型占用4个字节
	cout << "sizeof(float) is " << sizeof(float) << endl;
	// 单精度浮点型占用8个字节
	cout << "sizeof(double) is " << sizeof(double) << endl;
	
	// 字符变量只占用1个字节
	cout << "sizeof(char) is " << sizeof(char) << endl;
	
	
	// bool占用1个字节
	cout << "sizeof(bool) is " << sizeof(bool) << endl;
	
	
	
	
	
	system("pause");
	return 0;
}

