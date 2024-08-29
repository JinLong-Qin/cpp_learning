#include <iostream>
#include <string>

using namespace std;

#define MAX 1000

struct Person{
	string name;
	int age;
	int gender;
	string phone;
};

struct AddressBooks{
	Person pArray[MAX];
	int size;
};

void showMenu(){	
	cout << "----------------" << endl;
	cout << "1. �����ϵ��" << endl;
	cout << "2. ��ʾ��ϵ��" << endl;
	cout << "3. ɾ����ϵ��" << endl;
	cout << "4. ������ϵ��" << endl;
	cout << "5. �޸���ϵ��" << endl;
	cout << "6. �����ϵ��" << endl;
	cout << "0. �˳�ͨѶ¼" << endl;
	cout << "----------------" << endl;
}

void showABS(AddressBooks * abs){
	if(abs->size == 0){
		cout << "������Ϣ" << endl;
	}else{
		cout << "����\t����\t�Ա�\t�ֻ���" << endl;
		for(int i=0; i<abs->size; i++){
			cout << abs->pArray[i].name << "\t";
			cout << abs->pArray[i].age << "\t";
			cout << (abs->pArray[i].gender == 1 ? "��" : "Ů") << "\t";
			cout << abs->pArray[i].phone << endl;
		}
	}
	
	// system("pause");
	// system("cls");
}

void addPerson(AddressBooks * abs){
	if(abs->size == MAX){
		cout << "��ϵ���������޷��������" << endl;
		return;
	}
	
	string name;
	int age;
	int gender;
	string phone;
	
	cout << "����������" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> age;
	
	cout << "�������Ա�(0ΪŮ��1Ϊ��)" << endl;
	while(1){
		cin >> gender;
		if(gender == 1 || gender == 0){
			abs->pArray[abs->size].gender = gender;
			break;
		}else{
			cout << "�Ա����������������" << endl;
		}
	}
	
	cout << "�������ֻ���" << endl;
	cin >> phone;
	
	abs->pArray[abs->size].name = name;
	abs->pArray[abs->size].age = age;
	
	abs->pArray[abs->size].phone = phone;
	
	abs->size++;
	
	cout << "�����ϵ�˳ɹ�" << endl;
	
	system("pause");
	system("cls");
}

// ��������Ѱ��ͨѶ¼��Ϣ���ҵ��ͷ����±꣬�Ҳ����ͷ���-1
int findPersonByName(AddressBooks * abs, string name){
	for(int i=0; i<abs->size; i++){
		if(name == abs->pArray[i].name){
			cout << "���ҵ���Ϣ" << endl;
			cout << abs->pArray[i].name << "\t";
			cout << abs->pArray[i].age << "\t";
			cout << (abs->pArray[i].gender == 1 ? "��" : "Ů") << "\t";
			cout << abs->pArray[i].phone << endl;
			return i;
		}
	}
	cout << "û�в��ҵ���Ӧ��Ϣ" << endl;
	return -1;
}

void delPersonByName(AddressBooks * abs){
	showABS(abs);
	if(abs->size != 0){
		string name;
		cout << "����Ҫɾ����Ϣ������" << endl;
		cin >> name;
		
		int ret = findPersonByName(abs, name);
		
		if(ret != -1){			
			for(int i=ret; i<abs->size-1; i++){
				abs->pArray[i] = abs->pArray[i+1];
			}
			abs->size--; 
			cout << "ɾ���ɹ�" << endl;
		}
	}
	
	system("pause");
	system("cls");
}

void updPersonByName(AddressBooks * abs){
	showABS(abs);
	if(abs->size != 0){
		string name;
		cout << "����Ҫ�޸���Ϣ������" << endl;
		cin >> name;
		
		int ret = findPersonByName(abs, name);
		
		if(ret != -1){
			string name;
			int age;
			int gender;
			string phone;
			
			cout << "����������" << endl;
			cin >> name;
			cout << "����������" << endl;
			cin >> age;
			
			cout << "�������Ա�(0ΪŮ��1Ϊ��)" << endl;
			while(1){
				cin >> gender;
				if(gender == 1 || gender == 0){
					abs->pArray[abs->size].gender = gender;
					break;
				}else{
					cout << "�Ա����������������" << endl;
				}
			}
			
			cout << "�������ֻ���" << endl;
			cin >> phone;
			
			abs->pArray[ret].name = name;
			abs->pArray[ret].age = age;
			abs->pArray[ret].gender = gender;
			abs->pArray[ret].phone = phone;
			
			
			cout << "��Ϣ�޸ĳɹ�" << endl;
		}
	}
	
	system("pause");
	system("cls");
}

void cleanAllPerson(AddressBooks * abs){
	abs->size = 0;
	cout << "ͨѶ¼����ɹ�" << endl;
	system("pause");
	system("cls");
}


int main(){
	
	struct AddressBooks abs;
	abs.size = 0;
	
	int select = 0;
	
	while(1){
		showMenu();
		
		cout << "ѡ����Ĳ�����" << endl;
		cin >> select;
		
		switch(select){
			case 1:
				addPerson(&abs);
				break;
			case 2:
				showABS(&abs);
				break;
			case 3:
				delPersonByName(&abs);
				break;
			case 4:
				{
					string name;
					cout << "������Ҫ���ҵ�������" << endl;
					cin >> name;
					
					findPersonByName(&abs, name);
				}
				break;
			case 5:
				updPersonByName(&abs);
				break;
			case 6:
				cleanAllPerson(&abs);
				break;
			case 0:
				cout << "��ӭ�´�ʹ��" << endl;
				system("pause");
				return 0;
				break;
			default:
				system("pause");
				return 0;
				break;
			
		}
	}
	
	system("pause");
	return 0;
}
