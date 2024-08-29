#include <iostream>
using namespace std;

#include <ctime>
#include <cmath>

int main(){
	
	// 顺序结构
	// 按代码顺序进行执行
	
	// 选择结构
	// if - else
	// if - else if
	// 表达式0 ? 表达式1 : 表达式2
	// switch - case
	
	/*
	int score = 0;
	
	cin >> score;
	
	switch(score){
		case 10: 
			cout << "高分" << endl;
			break;
		case 5:
			cout << "低分" << endl;
			break;
		default:
			cout << "default" << endl;
			break;
	}
	*/
	// if 和 switch的区别
	// switch只能够判断整型或者字符型，并不能判断一整个区间
	// 对于多条件判断的时候，switch的结构清晰，执行效率高
	// case中要按照具体情况决定是否增加break
	
	
	
	
	// 循环结构
	// for 
	// while
	// do-while
	
	/*
	// 使用循环进行猜数字任务
	// 输入一个数字 1 - 100之间，程序判断其大小，
	
	//! 添加随机种子，利用当前系统时间生成随机数，防止每次生成的随机数都相同
	// 引入time系统时间头文件 ctime
	srand((unsigned int)time(NULL));
	
	
	// 生成1-100随机数
	int num = rand() % 100 + 1;
	int guess = 0;
	
	
	cout << "请输入一个1-100的随机数：" << endl;
	
	while(guess != num)
	{
		cin >> guess;
		if(guess > num)
		{
			cout << "猜的大了, 重新输入" << endl;
		}else if(guess < num)
		{
			cout << "猜的小了, 重新输入" << endl;
		}else
		{
			cout << "猜对了，数字是:" << guess << endl;
		}
	}
	*/
	
	// 使用do-while实现求解3位数中所有的水仙花数
	/*
	int num = 100;
	int gewei, shiwei, baiwei;
	
	do{
		gewei = num % 10;
		shiwei = num /10 % 10;
		baiwei = num / 100;
		
		if(pow(gewei, 3) + pow(shiwei, 3) + pow(baiwei, 3) == num){
			cout << num  << endl;
		}
		
		num++;
	}while(num < 1000);
	*/
	
	// 使用for循环实现敲桌子游戏。
	// 数字1-100，每逢7或者7的倍数，都打印敲桌子，其余数字都打印数字。
	/*
	int i, gewei, shiwei;
	for(i=1; i<101; i++){
		gewei = i % 10;
		shiwei = i / 10 % 10;
		if(i%7==0 or gewei==7 or shiwei==7){
			cout << "敲桌子" << endl;
		}
		else{
			cout << i << endl;
		}
		
	}
	* */
	
	// 使用循环实现乘法口诀表
	int i, j;
	for(i=1; i<10; i++){
		for(j=1; j<=i; j++){
			cout << i << "*" << j << "=" << i*j << "\t";
		}
		cout << endl;
	}
	
	
	// 使用break跳出循环或者选择语句， 直接放弃接下来的循环
	// 使用continue在循环语句中跳出本次循环，放弃执行continue后面的循环语句，直接执行下一次循环。
	
	// goto 跳到标记的部分执行代码
	cout << 1 << endl;
	goto FLAG;
	cout << 2 << endl;
	cout << 3 << endl;
	FLAG:
	cout << 4 << endl;
	
	
	system("pause");
	return 0;
	
}
