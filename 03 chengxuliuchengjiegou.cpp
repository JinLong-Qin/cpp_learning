#include <iostream>
using namespace std;

#include <ctime>
#include <cmath>

int main(){
	
	// ˳��ṹ
	// ������˳�����ִ��
	
	// ѡ��ṹ
	// if - else
	// if - else if
	// ���ʽ0 ? ���ʽ1 : ���ʽ2
	// switch - case
	
	/*
	int score = 0;
	
	cin >> score;
	
	switch(score){
		case 10: 
			cout << "�߷�" << endl;
			break;
		case 5:
			cout << "�ͷ�" << endl;
			break;
		default:
			cout << "default" << endl;
			break;
	}
	*/
	// if �� switch������
	// switchֻ�ܹ��ж����ͻ����ַ��ͣ��������ж�һ��������
	// ���ڶ������жϵ�ʱ��switch�Ľṹ������ִ��Ч�ʸ�
	// case��Ҫ���վ�����������Ƿ�����break
	
	
	
	
	// ѭ���ṹ
	// for 
	// while
	// do-while
	
	/*
	// ʹ��ѭ�����в���������
	// ����һ������ 1 - 100֮�䣬�����ж����С��
	
	//! ���������ӣ����õ�ǰϵͳʱ���������������ֹÿ�����ɵ����������ͬ
	// ����timeϵͳʱ��ͷ�ļ� ctime
	srand((unsigned int)time(NULL));
	
	
	// ����1-100�����
	int num = rand() % 100 + 1;
	int guess = 0;
	
	
	cout << "������һ��1-100���������" << endl;
	
	while(guess != num)
	{
		cin >> guess;
		if(guess > num)
		{
			cout << "�µĴ���, ��������" << endl;
		}else if(guess < num)
		{
			cout << "�µ�С��, ��������" << endl;
		}else
		{
			cout << "�¶��ˣ�������:" << guess << endl;
		}
	}
	*/
	
	// ʹ��do-whileʵ�����3λ�������е�ˮ�ɻ���
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
	
	// ʹ��forѭ��ʵ����������Ϸ��
	// ����1-100��ÿ��7����7�ı���������ӡ�����ӣ��������ֶ���ӡ���֡�
	/*
	int i, gewei, shiwei;
	for(i=1; i<101; i++){
		gewei = i % 10;
		shiwei = i / 10 % 10;
		if(i%7==0 or gewei==7 or shiwei==7){
			cout << "������" << endl;
		}
		else{
			cout << i << endl;
		}
		
	}
	* */
	
	// ʹ��ѭ��ʵ�ֳ˷��ھ���
	int i, j;
	for(i=1; i<10; i++){
		for(j=1; j<=i; j++){
			cout << i << "*" << j << "=" << i*j << "\t";
		}
		cout << endl;
	}
	
	
	// ʹ��break����ѭ������ѡ����䣬 ֱ�ӷ�����������ѭ��
	// ʹ��continue��ѭ���������������ѭ��������ִ��continue�����ѭ����䣬ֱ��ִ����һ��ѭ����
	
	// goto ������ǵĲ���ִ�д���
	cout << 1 << endl;
	goto FLAG;
	cout << 2 << endl;
	cout << 3 << endl;
	FLAG:
	cout << 4 << endl;
	
	
	system("pause");
	return 0;
	
}
