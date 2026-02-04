#include<iostream>
using namespace std;

/*
    1.类的兼容性原则
    2.子类的构造与析构
*/

/*
    根据子类与父类的内存布局
    可得出子类的5大兼容性原则：
    
    a.子类对象可以当作父类对象使用
    b.子类对象可以初始化父类对象
    c.子类对象可以给父类对象赋值
    d.父类指针可以指向子类对象
    e.父类引用可以引用子类对象
*/

class Parent{
    public:
        int a;

        Parent(){
            this->a=0;
            cout<<"Parent()..."<<endl;
        }

        Parent(int a){
            this->a=a;
            cout<<"Parent(int a)..."<<endl;
        }

        ~Parent(){
            cout<<"~Parent()..."<<endl;
        }

        void PrintParentA(){
            cout<<"Parent:"<<this->a<<endl;
        }
};

class Child_1:public Parent
{
    public:
        int b;

        //默认调用父类无参
        Child_1(int b)   
        {
            this->b=b;
            cout<<"Child_1(int b)..."<<endl;
        }

        ~Child_1(){
            cout<<"~Child_1()..."<<endl;
        }

        void PrintChidl_1(){
            cout<<"child_1"<<endl;
        }
};

class Child_2:public Parent
{
    public:
        int b;

        //显式调用父类有参
        Child_2(int a,int b):Parent(a)
        {
            this->b=b;
            cout<<"Child_2(int a,int b):Parent(a)..."<<endl;
        }

        ~Child_2(){
            cout<<"~Child_2()..."<<endl;
        }

        void PrintChidl_2(){
            cout<<"child_2"<<endl;
        }
};

void test1(){
    Parent p1;
    Child_1 c1(3);
    Child_2 c2(3,4);
    cout<<"-----------"<<endl;

    //a.子类对象可以当作父类对象使用
    p1.a;
    //p1.b
    c1.a;
    c1.b;
    c2.a;
    c2.b;

    //b.子类对象可以构造父类对象
    Parent p2(c1);
    //Child_1 c3(p1);

    //c.子类对象可以赋值父类对象
    p2=c2;
    //Child_1 c2=p2;

    //d.父类指针可以指向子类对象
    Parent* ptr=&c1;
    //Child_1* c1ptr=&p1;

    //e.父类引用可以引用子类对象
    Parent& pp=c1;
    //Child_2& cc=&p1;
}

/*
    子类的构造与析构:子类不会继承父类的构造与析构
    
    子类构造时，先调用父类构造方法构造父类
    部分，再调用子类的构造方法构造子类部分

    子类析构时，根据先进后出的原则
    先调用子类构析，再调用父类析构
*/

void test2(){
    Parent p1;
    Child_1 c1(3);
    Child_2 c2(3,4);

    /*
        Parent()...
        Parent()...
        Child_1(int b)...
        Parent(int a)...
        Child_2(int a,int b):Parent(a);
        ~Child_2()...
        ~Parent()...
        ~Child_1()...
        ~Parent()...
        ~Parent()...
    */
}

int main(){
    test1();
    test2();

    return 0;
}