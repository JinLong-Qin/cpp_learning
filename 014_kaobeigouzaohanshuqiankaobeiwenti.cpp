#include <iostream>
using namespace std;

class Person{
	public:
		Person(){
			cout << "Person �޲ι��캯��ִ��" << endl;
		}
		
		Person(int age, int height){
			p_age = age;
			p_height = new int(height); // �ڶ��������ڴ汣��height��ֵ��new�᷵�������ڴ���׵�ַ
			cout << "Person �вι��캯��ִ��" << endl;
		}
		
		Person(const Person &p){ // Ϊ�˿�����Ӱ��ԭʼֵ����˼���const��Ϊ�˽�Լ�ڴ棬��������&�����÷�ʽ��Ϊ����
			p_age = p.p_age;
			// �������ṩ�ļ򵥿������캯��ֻ�ܹ����һЩ�򵥵ĸ�ֵ������ֻ�����ֽڵİ����ݴ洢���µĶ����������
			// ���������ַ���͵����ԣ�Ҳֻ�Ὣ��ַ���͵������б���ĵ�ַͬ���ĸ��Ƶ��¶����������
			// ������ʾ
			//p_height = p.p_height; // ����Ĭ�ϵ�ǳ�������캯��ִ�еĲ�������ԭ���� p_height �б���ĵ�ַ �����䶯�ĸ��Ƶ��¶����е� p_height ������
			// Ҳ�������������������е� p_height����ָ����ͬһƬ��ַ
			
			// ��ô���ڵ�һ���������ٵ�ʱ�򣬶� p_height ָ��ĵ�ַ�����ͷţ������������е����ݣ���
			// ���ǣ��ڶ�������Ҫ���ٵ�ʱ��p_height ָ��Ļ��ǵ�һ�������p_heightָ��ĵ�ַ��������Ƭ��ַ�Ѿ����ͷ��ˣ�����Ȩ�޲��������ˣ��ͻᱨ��
			
			//! ��ȷ�����ǣ��ڶ�������������һ���ַ��������ԭ��p��p_heightָ���ַ�е�ֵ
			p_height = new int(*p.p_height);
			
			
			
			cout << "Person �������캯��ִ��" << endl;
		}
		
		
		~Person(){
			// �������룬������������ĵ�ַ���ͷŲ���
			if(p_height!=NULL){
				delete p_height; // �ͷ�����ĵ�ַ
				p_height = NULL; // ��ֹҰָ�����
			}
			cout << "Person ��������ִ��" << endl;
		}
	
	
		int p_age;
		// һ�������˵�ַ���͵�����
		int * p_height;
		
};

void test01(){
	Person p(10, 160);
	
	Person pp(p);
	
	// ��ȷ������������ָ�����Դ洢��������ͬ�����Ǵ洢��ַ��ͬ����������
	cout << "p��height�ĵ�ַ�ǣ�" << &p.p_height << endl;
	cout << "p��height��ֵ�ǣ�" << *p.p_height << endl;
	cout << "p��height�ĵ�ַ�ǣ�" << &p.p_height << endl;
	cout << "pp��height��ֵ�ǣ�" << *pp.p_height << endl;
}

int main(){
	
	// ���п������캯����ǳ��������
	// ������û���ṩ�������캯����ʱ�򣬱��������Զ����һ���������캯���������򵥵Ľ������Ը�ֵ
	// ���������Զ��Ǽ򵥵ĸ�ֵ������ʱ�򣬲������
	test01();
	
	system("pause");
	return 0;
}
