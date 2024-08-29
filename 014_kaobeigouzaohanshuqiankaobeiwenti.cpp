#include <iostream>
using namespace std;

class Person{
	public:
		Person(){
			cout << "Person 无参构造函数执行" << endl;
		}
		
		Person(int age, int height){
			p_age = age;
			p_height = new int(height); // 在堆区申请内存保存height的值，new会返回申请内存的首地址
			cout << "Person 有参构造函数执行" << endl;
		}
		
		Person(const Person &p){ // 为了拷贝不影响原始值，因此加上const，为了节约内存，所以增加&以引用方式作为参数
			p_age = p.p_age;
			// 编译器提供的简单拷贝构造函数只能够解决一些简单的赋值操作，只会逐字节的把内容存储到新的对象的属性中
			// 如果碰到地址类型的属性，也只会将地址类型的属性中保存的地址同样的复制到新对象的属性中
			// 如下所示
			//p_height = p.p_height; // 这是默认的浅拷贝构造函数执行的操作，将原本的 p_height 中保存的地址 不做变动的复制到新对象中的 p_height 属性中
			// 也就是现在这两个对象中的 p_height属性指向了同一片地址
			
			// 那么，在第一个对象销毁的时候，对 p_height 指向的地址做了释放（见析构函数中的内容），
			// 但是，第二个对象要销毁的时候，p_height 指向的还是第一个对象的p_height指向的地址，但是这片地址已经被释放了，操作权限不在手里了，就会报错
			
			//! 正确操作是：在堆区中重新申请一块地址用来报错原本p中p_height指向地址中的值
			p_height = new int(*p.p_height);
			
			
			
			cout << "Person 拷贝构造函数执行" << endl;
		}
		
		
		~Person(){
			// 析构代码，将堆区中申请的地址做释放操作
			if(p_height!=NULL){
				delete p_height; // 释放申请的地址
				p_height = NULL; // 防止野指针出现
			}
			cout << "Person 析构函数执行" << endl;
		}
	
	
		int p_age;
		// 一旦出现了地址类型的属性
		int * p_height;
		
};

void test01(){
	Person p(10, 160);
	
	Person pp(p);
	
	// 正确操作后，这两个指针属性存储的内容相同，但是存储地址不同，这就是深拷贝
	cout << "p的height的地址是：" << &p.p_height << endl;
	cout << "p的height的值是：" << *p.p_height << endl;
	cout << "p的height的地址是：" << &p.p_height << endl;
	cout << "pp的height的值是：" << *pp.p_height << endl;
}

int main(){
	
	// 类中拷贝构造函数的浅拷贝问题
	// 当我们没有提供拷贝构造函数的时候，编译器会自动添加一个拷贝构造函数，用来简单的进行属性赋值
	// 当类中属性都是简单的赋值操作的时候，不会出错
	test01();
	
	system("pause");
	return 0;
}
