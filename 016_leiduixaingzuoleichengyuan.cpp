#include <iostream>
#include <string>
#include <utility>

using namespace std;


class Phone{

public:
    Phone(string bname){
        cout << "Phone���캯��" << endl;
        b_name = bname;
    }

    ~Phone(){
        cout << "Phone ��������" << endl;
    }

    string b_name;
};


class Person{

public:
    Person(string pname, string bname): p_name(pname), ph(bname){
        cout << "Person���캯��" << endl;
    }

    ~Person(){
        cout << "Person��������" << endl;
    }

    string p_name;
    Phone ph;
};



void test01(){
	Person p("����", "����");
}
	
	
int main(){

	// ��������Ϊ���Ա
    //�����г�Ա�����������ʱ�����ǳƸó�ԱΪ �����Ա
    //�����˳���� ���ȵ��ö����Ա�Ĺ��죬�ٵ��ñ��๹��
    //����˳���빹���෴
    //! ��ԭ��Ϊ�������������ʱ��Ҫ�ȳ�ʼ�������е����������������װ��һ������
    //! ������ʱ��������ʹ�þֲ���������壬û���˵�������ֲ��ˣ������پֲ��� �������Ϊ����Щ���������ջ���У�ջ���Ĺ������Ƚ����������ȳ�
	test01();
	
	system("pause");
	return 0;
}
