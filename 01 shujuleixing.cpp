#include <iostream>
using namespace std;
#include <string>

// �곣��
#define Day 7

int main()
{
	// ���
	cout << "hello world" << endl;
	
	
	// ������ �������� �������� = ������ʼֵ
	int a = 10;
	cout << "a = " << a << endl;
	
	// ���� 
	// 1.�곣��
	cout << "һ����" << Day << "��" << endl;
	// 2. const���εı���
	const int hours = 24;
	cout << "һ����" << hours << "Сʱ" << endl;	
	// ����һ�����岻�����ٽ����޸�
	
	// ��ʶ����������
	/**
	 * 1. ����ʹ�ùؼ���
	 * 2. ֻ������ĸ�����֡��»������
	 * 3. ��һ���ַ���������ĸ�����»���
	 * 4. ��ĸ���ִ�Сд
	 */
	 
	 
	 
	// ��������
	// 1. ����
	 /**
	  * ��������		ռ�ÿռ�													ȡֵ��Χ
	  *  short		 2�ֽ�												-2^15 ~ 2^15-1
	  *  int		 4�ֽ�												-2^31 ~ 2^31-1
	  *  long		 4�ֽ�(windows��32λlinux); 8�ֽ�(64λlinux)			-2^31 ~ 2^31-1
	  *  long long	 8�ֽ�												-2^63 ~ 2^63-1
	  */
	
	 
	// 2. ʵ��
	 /**
	  * ��������		ռ�ÿռ�		 	ȡֵ��Χ
	  *  float		 4�ֽ�		   7λ��Ч����		������
	  *  double		 8�ֽ�		 15~16λ��Ч����		˫����
	  * 
	  * С����ǰ������ֶ�������Ч���ָ�����
	  * Ĭ������£����һ������������ʾ6λ��Ч����
	  */
	  
	float f1 = 3.14f; // ���������f��׺����3.14ת��Ϊ������ֵ
	cout << "f1 = " << f1 << endl;
	double d1 = 3.14;
	cout << "d1 = " << d1 << endl;
	
	// ��ѧ������
	float f2 = 3e2; // ��ʾ 3 x 10^2
	cout << "f2 = " << f2 << endl;
	float f3 = 3e-2; // ��ʾ 3 x 10^-2
	cout << "f3 = " << f3 << endl;
	
	
	// �ַ���: ��ʾ�����ַ�
	// ʹ�õ����ţ����ҵ�������ֻ�ܴ���һ���ַ�
	//! �ַ����������ǽ��ַ��洢���ڴ��У����ǽ��ַ���Ӧ��ASCII�������洢��Ԫ���д洢
	char ch = 'a';
	cout << "ch = " << ch << endl;
	
	// �ַ�������Ӧ��ASCII��
	cout << "the ASCII code of ch is " << int(ch) << endl;
	/**
	 * a - 97
	 * A - 65
	 */
	 
	 
	 // ת���ַ�
	 /**
	  * ת���ַ�			����	
	  *   \a 			����	
	  *   \b 			�˸�
	  *   \f			��ҳ������ǰλ���ƶ�����һҳ�Ŀ�ͷ
	  *   \n			���У�����ǰλ���ƶ�����һ�п�ͷ
	  *   \r			�س�������ǰλ���ƶ�����ǰ�п�ͷ
	  *   \t			ˮƽ�Ʊ��
	  *   \v			��ֱ�Ʊ��
	  *   \\			\
	  *   \'			'
	  *   \"			"
	  *   \?			?
	  *   \0			����0
	  *   \ddd			8����ת���ַ���d��Χ0~7
	  *   \xhh			16����ת���ַ���h��Χ 0-9 A-F
	  *  
	  * */ 
	 
	// �ַ�����, ���ڱ�ʾһ���ַ�
	// 1. c���Է���ַ���
	char str1[] = "hello world";
	cout << "str1 = " << str1 << endl;
	// 2. cpp����ַ��� Ҫ����stringͷ�ļ�
	string str = "hello world!";
	cout << "str = " << str << endl;
	
	// �������� bool
	// ֻ������ֵ true - ����Ϊ1 �� false - ����Ϊ0
	// ��0��ֵ������Ϊtrue
	bool flag = true;
	cout << "flag = " << flag << endl;
	
	
	// ���ݵ����룬���ڴӼ��̻�ȡ����
	// 1.����
	//int aa = 0;
	//cout << "input the aa: " << endl;
	//cin >> aa;
	//cout << "aa = " << aa << endl;
	
	// 2.������
	//float ff = 3.14f;
	//cout << "input the ff: " << endl;
	//cin >> ff;
	//cout << "ff = " << ff << endl;
	
	// 3.�ַ���
	//char cc = 'a';
	//cout << "input the cc: " << endl;
	//cin >> cc;
	//cout << "cc = " << cc << endl;
	
	// 4.�ַ�����
	//string ss = "hello";
	//cout << "input the ss: " << endl;
	//cin >> ss;
	//cout << "ss = " << ss << endl;
	// 5.������
	//bool bb = true;
	//cout << "input the bb: " << endl;
	//cin >> bb;
	//cout << "bb = " << bb << endl;
	
	
	// ��������ռ���ֽ���
	cout << "-------------------------" << endl;
	cout << "������������ռ���ֽ�����" << endl;
	// ʹ��sizeof�ؼ��ֿ���ͳ������������ռ�ڴ��С
	// ��������ռ��4���ֽ�
	cout << "sizeof(short) is " << sizeof(short) << endl;
	// ����ռ��4���ֽ�
	cout << "sizeof(int) is " << sizeof(int) << endl;
	// ������ռ��4���ֽ�
	cout << "sizeof(long) is " << sizeof(long) << endl;
	// long longռ��4���ֽ�
	cout << "sizeof(long long) is " << sizeof(long long) << endl;
	// ���ʹ�С�Ƚ�: short < int <= long < long long
	
	// �����ȸ�����ռ��4���ֽ�
	cout << "sizeof(float) is " << sizeof(float) << endl;
	// �����ȸ�����ռ��8���ֽ�
	cout << "sizeof(double) is " << sizeof(double) << endl;
	
	// �ַ�����ֻռ��1���ֽ�
	cout << "sizeof(char) is " << sizeof(char) << endl;
	
	
	// boolռ��1���ֽ�
	cout << "sizeof(bool) is " << sizeof(bool) << endl;
	
	
	
	
	
	system("pause");
	return 0;
}

