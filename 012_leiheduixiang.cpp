#include <iostream>
#include <string>
#include <cmath>
#include "012_Circle2.h"
using namespace std;

const double PI = 3.14;

// 1. ��װ
// class�ؼ��ֱ�ʾ����һ����
class Circle{
	// ����Ȩ��
	public: // ����Ȩ��
		// ���� �뾶
		int m_r;
		
		// ��Ϊ
		// Բ���ܳ�
		double calculateZC(){
			return 2 * PI * m_r;
		}
		
};

// ��װ��ϰ:���һ��ѧ���࣬������������ѧ�ţ����Ը�������ѧ�Ÿ�ֵ��������ʾѧ����������ѧ��
class Student{
	//! ���е����Ժ���Ϊ��������Ϊ��Ա
	// �����ֱ���Ϊ ��Ա���� �� ��Ա����
	// ��Ϊ�ֱ���Ϊ ��Ա���� �� ��Ա����
	public:
		string sname;
		int sid;
		
		void showStudent(){
			cout << "�����ǣ�" << sname << " ѧ���ǣ�" << sid << endl;
		}
		
		void setName(string name){
			sname = name;
		}
};


// ����Ȩ��
class Person{
	public:
	string m_Name;

	protected:
		string m_Car;

	private:
		int m_Password;

	public:
		void func1()
		{
			m_Name = "����";
			m_Car = "������";
			m_Password = 123456;
		}
	protected:
		void func2()
		{
			m_Name = "����";
			m_Car = "������";
			m_Password = 123456;
		}
};

// ��Ա����˽�л��ĺô�
class Person2 {
public: // �����������������ƶ�дȨ��
	
	//�������ÿɶ���д
	void setName(string name) {
		m_Name = name;
	}
	string getName()
	{
		return m_Name;
	}


	//��ȡ���� 
	int getAge() {
		return m_Age;
	}
	//��������
	//! ��д���ʱ�򣬼���������ݵ���Ч��
	void setAge(int age) {
		if (age < 0 || age > 150) {
			cout << "���������!" << endl;
			return;
		}
		m_Age = age;
	}

	//ż������Ϊֻд
	void setIdol(string idol) {
		m_Idol = idol;
	}

private:
	string m_Name; //�ɶ���д  ����
	
	int m_Age; //ֻ��  ����

	string m_Idol; //ֻд  ż��
};


// ��ϰ1
// ��������������������
// �ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����
class Cube{
	public:
		int get_H(){
			return m_H;
		}
		
		int get_L(){
			return m_L;
		}
		
		int get_W(){
			return m_W;
		}
		
		void set_H(int H){
			m_H = H;
		}
		
		void set_L(int L){
			m_L = L;
		}
		
		void set_W(int W){
			m_W = W;
		}
		
		// �������
		int calculateS(){
			return 2 * (m_H * m_L + m_L * m_W + m_W * m_H);
		}
		
		// �������
		int calculateV(){
			return m_H * m_L * m_W;
		}
		
		// ��Ա�����ж������������Ƿ����
		bool isSameInsideClass(Cube c){
			if(m_H==c.get_H() && m_L==c.get_L() && m_W==c.get_W()){
				return 1;
			}
			return 0;
		}
		
	private:
		int m_H; // ��
		int m_L; // ��
		int m_W; // ��
};
// ȫ�ֺ����ж������������Ƿ����
// ʹ�����ô��ݣ�������һ���̶��Ͻ�ʡ�ڴ棬���������������ʱ��
// ��Ϊֵ���ݻḴ��һ�����ݽ��뺯����
bool isSame(Cube & c1, Cube & c2){
	if(c1.get_H()==c2.get_H() && c1.get_L()==c2.get_L() && c1.get_W()==c2.get_W()){
		return 1;
	}
	return 0;
}

// ��ϰ2.���һ��Բ�����һ�����࣬�жϵ��Բ�Ĺ�ϵ
/*
class Point{
	public:
		int get_X(){
			return m_x;
		}
		
		int get_Y(){
			return m_y;
		}
		
		void set_X(int x){
			m_x = x;
		}
		
		void set_Y(int y){
			m_y = y;
		}
	private:
		int m_x;
		int m_y; 
};

class Circle2{
	public:
		int get_R(){
			return m_r;
		}
		
		void set_R(int r){
			m_r = r;
		}
		
		Point getCenter(){
			return m_center;
		}
		
		void setCenter(Point p){
			m_center = p;
		}
		
	private:
		int m_r;
		Point m_center;
};
* ��������Ϊͷ�ļ�����012_Point��012_Circle2����ļ������������012_Circle2.h�ʼ���
*/
// �жϵ��Բ�Ĺ�ϵ
void isInCircle(Circle2 & c, Point & p){
	//int dis = sqrt(pow(c.getCenter().get_X()-p.get_X(), 2) + pow(c.getCenter().get_Y()-p.get_Y(), 2));
	// ����ʹ��sqrt���Ч�ʣ��Ƚ�ƽ��
	int dx = c.getCenter().get_X()-p.get_X();
	int dy = c.getCenter().get_Y()-p.get_Y();
	int distSquared = dx * dx + dy * dy;
	if(distSquared == c.get_R()*c.get_R()){
		cout << "��Բ��" << endl;
	}else if(distSquared > c.get_R()*c.get_R()){
		cout << "��Բ��" << endl;
	}else{
		cout << "��Բ��" << endl;
	}
		
}

int main(){
	
	// ��Ͷ���
	// �������ﶼ��Ϊ���󣬶������������Ժ���Ϊ
		// ������ʵ����������ͬ���ʵĶ������ǿ��Գ����Ϊ�࣬���������࣬�����ڳ���
	// ����������������Ϊ����װ���̳С���̬
	
	
	// 1.��װ 
	// 1.1 ��װ������1�� �����Ժͷ�����Ϊһ�����壬������Ȩ�޿���
	//! ʵ������ͨ��һ���ഴ��һ������
	// ͨ��Բ�� ����Բ����
	Circle cl;
	// Ϊ��������Ը�ֵ
	cl.m_r = 10;
	
	// ʹ�ö������Ϊ����Բ���ܳ�
	cout << "Բ���ܳ�Ϊ��" << cl.calculateZC() << endl;
	
	
	// ��װ��ϰ�����һ��ѧ���࣬������������ѧ�ţ����Ը�������ѧ�Ÿ�ֵ��������ʾѧ����������ѧ��
	Student stu;
	stu.sname="lili";
	stu.sid = 123;
	// ��ֱ�ӶԶ����е����Խ��и�ֵ�⣬������ʹ����Ϊ�������Խ��и�ֵ
	stu.setName("zhangsan");
	
	stu.showStudent();
	
	// 1.1 ��װ������2�� �����Ժͷ��������ڲ�ͬ��Ȩ���£��Լ�ǿ��һ���Ŀ���
	// ����Ȩ�޵����ͣ���
	/*!
	 * 1. public����Ȩ�ޣ�	���ڲ����Է��ʣ����ⲿ���Է���
	 * 2. protected����Ȩ��: ���ڲ����Է��ʣ����ⲿ�����Է���; ������Է��ʸ����б�����������
	 * 3. private˽��Ȩ�ޣ�	���ڲ����Է��ʣ����ⲿ�����Է���; �����в����Է��ʸ����е�˽������
	 * */
	Person p1;
	
	p1.m_Name = "����";
	//p1.m_Car = "����";  //����Ȩ��������ʲ���
	//p1.m_Password = 123; //˽��Ȩ��������ʲ���
	
	p1.func1();
	// p1.func2(); //����Ȩ��������ʲ���
	
	// ���۷����������ԣ������з���Ȩ��
	//! struct��class ������
	/*
	 * structĬ��Ȩ��Ϊpublic
	 * classĬ��Ȩ��Ϊpriviate
	 * */
	
	// ��Ա����˽�л��ĺô�
	/*
	 * 1. �����Լ����ƶ�дȨ��
	 * 2. ����дȨ�ޣ����Լ�����ݵ���Ч��
	 * */
	 
	Person2 p2;
	//��������
	p2.setName("����");
	cout << "������ " << p2.getName() << endl;

	//��������
	p2.setAge(50);
	cout << "���䣺 " << p2.getAge() << endl;

	//��������
	p2.setIdol("gg");
	//cout << "ż�� " << p.m_Idol << endl;  //ֻд���ԣ������Զ�ȡ
	
	
	// ��ϰ1 �����������(Cube)�����������������������ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����
	Cube c1;
	c1.set_H(1);
	c1.set_W(2);
	c1.set_L(3);
	
	cout << "c1������ǣ� " << c1.calculateS() << endl;
	cout << "c1������ǣ� " << c1.calculateV() << endl;
	
	Cube c2;
	c2.set_H(1);
	c2.set_W(2);
	c2.set_L(3);
	
	cout << "c2������ǣ� " << c2.calculateS() << endl;
	cout << "c2������ǣ� " << c2.calculateV() << endl;
	
	// ȫ�ֺ����ж��Ƿ����
	if(isSame(c1, c2)){
		cout << "c1��c2����ȵ�" << endl;
	}else{
		cout << "c1��c2�ǲ����" << endl;
	}
	// �ֲ������ж��Ƿ����
	if(c1.isSameInsideClass(c2)){
		cout << "c1��c2����ȵ�" << endl;
	}else{
		cout << "c1��c2�ǲ����" << endl;
	}
	
	
	// ��ϰ2.���һ��Բ�����һ�����࣬�жϵ��Բ�Ĺ�ϵ
	// Բ�ڣ�Բ�ϣ�Բ��
	/*
	 * �㵽Բ�ĵľ��� == �뾶 Բ��
	 * �㵽Բ�ĵľ��� < �뾶 Բ��
	 * �㵽Բ�ĵľ��� > �뾶 Բ��
	 * */
	Point p;
	p.set_X(1);
	p.set_Y(2);
	
	Point center;
	p.set_X(0);
	p.set_Y(0);
	
	Circle2 cc;
	cc.set_R(3);
	cc.setCenter(center);
	
	isInCircle(cc, p);
	
	//! ��Point���Circle2����Ϊͷ�ļ���Դ�ļ��Լ�main�ļ��е�����
	// g++ -o 012_leiheduixiang 012_leiheduixiang.cpp 012_Point.cpp 012_Circle2.cpp
	
	system("pause");
	return 0;
}


















