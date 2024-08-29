#include <iostream>
using namespace std;

class AbstractDrink{

    public:
        virtual void zhushui() = 0;
        virtual void chongpao() = 0;
        virtual void daoshui() = 0;
        virtual void jiafuliao() = 0;

        void makeDrink(){
            zhushui();
            chongpao();
            daoshui();
            jiafuliao();

        }
};

class Coffee: public AbstractDrink{

    public:
        virtual void zhushui(){
            cout << "coffee zhushui" << endl;
        }
        virtual void chongpao(){
            cout << "coffee chongpao" << endl;
        }
        virtual void daoshui(){
            cout << "coffee daoshui" << endl;
        }
        virtual void jiafuliao(){
            cout << "coffee daoshui" << endl;
        }

};

class Tea: public AbstractDrink{

    public:
        void zhushui(){
            cout << "Tea zhushui" << endl;
        }
        void chongpao(){
            cout << "Tea chongpao" << endl;
        }
        void daoshui(){
            cout << "Tea daoshui" << endl;
        }
        void jiafuliao(){
            cout << "Tea daoshui" << endl;
        }

};

void doWork(AbstractDrink* abd){
    abd->makeDrink();
    delete abd;
}

void test01(){
    AbstractDrink* abd = new Coffee;
    abd->makeDrink();
    delete abd;
}

void test02(){
    doWork(new Coffee);
    doWork(new Tea);
}

int main(){

    // 制作饮品的大致流程为：煮水 -  冲泡 - 倒入杯中 - 加入辅料
    // 利用多态技术实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶
    // test01();
    test02();
    return 0;
}