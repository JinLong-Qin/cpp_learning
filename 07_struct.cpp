#include <iostream>
using namespace std;

#include <string>

// ��������
struct Person{
	string name;
	int age;
} p1; // 1������ṹ���ʱ��ͬʱ��������


// �ṹ��Ƕ�׽ṹ��
struct student
{
	//��Ա�б�
	string name;  //����
	int age;      //����
	int score;    //����
};
//��ʦ�ṹ�嶨��
struct teacher
{
    //��Ա�б�
	int id; //ְ�����
	string name;  //��ʦ����
	int age;   //��ʦ����
	struct student stu; //�ӽṹ�� ѧ��
};


// �ṹ��������
//ֵ����
void printStudent(student stu )
{
	stu.age = 28;
	cout << "�Ӻ����� ������" << stu.name << " ���䣺 " << stu.age  << " ������" << stu.score << endl;
}
//��ַ����
void printStudent2(student *stu)
{
	stu->age = 28;
	cout << "�Ӻ����� ������" << stu->name << " ���䣺 " << stu->age  << " ������" << stu->score << endl;
}



// ʹ��const�����������
void printStudent(const student *stu) //��const��ֹ�������е������������ָ��������ͨ��ָ���޸ĵ�ַ�е�ֵ
{
	//! stu->age = 100; //����ʧ�ܣ���Ϊ����const����
	cout << "������" << stu->name << " ���䣺" << stu->age << " ������" << stu->score << endl;
}

int main(){

	
	
	// 2.ֱ�ӳ�ʼ���ṹ��
	Person p2 = {"lili", 12};
	cout << p2.name << p2.age << endl;	
	
	
	// 3.�����ṹ�壬����ٽ��г�ʼ��
	struct Person p3;
	p3.name = "zhangsan";
	p3.age = 33;
	cout << p3.name << p3.age << endl;	
	
	// �����ṹ�������ʱ����ǰ���struct����ʡ��
	
	
	// �ṹ������
	struct Person p_list[3]=
	{
		{"����",18 },
		{"����",19 },
		{"����",20 }
	};
	
	for (int i = 0; i < 3; i++)
	{
		cout << "������" << p_list[i].name << " ���䣺" << p_list[i].age << endl;
	}
	
	
	// �ṹ��ָ��
	Person * pp = &p2;
	pp->age = 20;
	pp->name = "lisi";
	cout << p2.name << p2.age << endl;	
	
	
	// �ṹ��Ƕ�׽ṹ��
	struct teacher t1;
	t1.id = 10000;
	t1.name = "����";
	t1.age = 40;
	// Ƕ�����ݸ�ֵ
	t1.stu.name = "����";
	t1.stu.age = 18;
	t1.stu.score = 100;
	cout << "��ʦ ְ����ţ� " << t1.id << " ������ " << t1.name << " ���䣺 " << t1.age << endl;
	
	cout << "����ѧԱ ������ " << t1.stu.name << " ���䣺" << t1.stu.age << " ���Է����� " << t1.stu.score << endl;
	
	
	// �ṹ��������
	student stu = { "����",18,100};
	//ֵ����
	printStudent(stu);
	cout << "�������� ������" << stu.name << " ���䣺 " << stu.age << " ������" << stu.score << endl;
	cout << endl;
	//��ַ����
	printStudent2(&stu);
	cout << "�������� ������" << stu.name << " ���䣺 " << stu.age  << " ������" << stu.score << endl;
	
	
	system("pause");
	return 0;

	
}
