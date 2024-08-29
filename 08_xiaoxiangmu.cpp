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
	cout << "1. 添加联系人" << endl;
	cout << "2. 显示联系人" << endl;
	cout << "3. 删除联系人" << endl;
	cout << "4. 查找联系人" << endl;
	cout << "5. 修改联系人" << endl;
	cout << "6. 清空联系人" << endl;
	cout << "0. 退出通讯录" << endl;
	cout << "----------------" << endl;
}

void showABS(AddressBooks * abs){
	if(abs->size == 0){
		cout << "暂无信息" << endl;
	}else{
		cout << "姓名\t年龄\t性别\t手机号" << endl;
		for(int i=0; i<abs->size; i++){
			cout << abs->pArray[i].name << "\t";
			cout << abs->pArray[i].age << "\t";
			cout << (abs->pArray[i].gender == 1 ? "男" : "女") << "\t";
			cout << abs->pArray[i].phone << endl;
		}
	}
	
	// system("pause");
	// system("cls");
}

void addPerson(AddressBooks * abs){
	if(abs->size == MAX){
		cout << "联系人已满，无法继续添加" << endl;
		return;
	}
	
	string name;
	int age;
	int gender;
	string phone;
	
	cout << "请输入姓名" << endl;
	cin >> name;
	cout << "请输入年龄" << endl;
	cin >> age;
	
	cout << "请输入性别(0为女，1为男)" << endl;
	while(1){
		cin >> gender;
		if(gender == 1 || gender == 0){
			abs->pArray[abs->size].gender = gender;
			break;
		}else{
			cout << "性别输入错误，重新输入" << endl;
		}
	}
	
	cout << "请输入手机号" << endl;
	cin >> phone;
	
	abs->pArray[abs->size].name = name;
	abs->pArray[abs->size].age = age;
	
	abs->pArray[abs->size].phone = phone;
	
	abs->size++;
	
	cout << "添加联系人成功" << endl;
	
	system("pause");
	system("cls");
}

// 按照姓名寻找通讯录信息，找到就返回下标，找不到就返回-1
int findPersonByName(AddressBooks * abs, string name){
	for(int i=0; i<abs->size; i++){
		if(name == abs->pArray[i].name){
			cout << "查找到信息" << endl;
			cout << abs->pArray[i].name << "\t";
			cout << abs->pArray[i].age << "\t";
			cout << (abs->pArray[i].gender == 1 ? "男" : "女") << "\t";
			cout << abs->pArray[i].phone << endl;
			return i;
		}
	}
	cout << "没有查找到对应信息" << endl;
	return -1;
}

void delPersonByName(AddressBooks * abs){
	showABS(abs);
	if(abs->size != 0){
		string name;
		cout << "输入要删除信息的名字" << endl;
		cin >> name;
		
		int ret = findPersonByName(abs, name);
		
		if(ret != -1){			
			for(int i=ret; i<abs->size-1; i++){
				abs->pArray[i] = abs->pArray[i+1];
			}
			abs->size--; 
			cout << "删除成功" << endl;
		}
	}
	
	system("pause");
	system("cls");
}

void updPersonByName(AddressBooks * abs){
	showABS(abs);
	if(abs->size != 0){
		string name;
		cout << "输入要修改信息的名字" << endl;
		cin >> name;
		
		int ret = findPersonByName(abs, name);
		
		if(ret != -1){
			string name;
			int age;
			int gender;
			string phone;
			
			cout << "请输入姓名" << endl;
			cin >> name;
			cout << "请输入年龄" << endl;
			cin >> age;
			
			cout << "请输入性别(0为女，1为男)" << endl;
			while(1){
				cin >> gender;
				if(gender == 1 || gender == 0){
					abs->pArray[abs->size].gender = gender;
					break;
				}else{
					cout << "性别输入错误，重新输入" << endl;
				}
			}
			
			cout << "请输入手机号" << endl;
			cin >> phone;
			
			abs->pArray[ret].name = name;
			abs->pArray[ret].age = age;
			abs->pArray[ret].gender = gender;
			abs->pArray[ret].phone = phone;
			
			
			cout << "信息修改成功" << endl;
		}
	}
	
	system("pause");
	system("cls");
}

void cleanAllPerson(AddressBooks * abs){
	abs->size = 0;
	cout << "通讯录清除成功" << endl;
	system("pause");
	system("cls");
}


int main(){
	
	struct AddressBooks abs;
	abs.size = 0;
	
	int select = 0;
	
	while(1){
		showMenu();
		
		cout << "选择你的操作：" << endl;
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
					cout << "请输入要查找的人姓名" << endl;
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
				cout << "欢迎下次使用" << endl;
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
