#include<iostream>
using namespace std;
/*
    1.类与类的基本关系has,use,is
    2.继承的基本概念
    3.类的继承方式
*/

//has拥有,B拥有A,B依赖于A,耦合度高
class A{
    public:
        int a;
};

class B{
    public:
        A a;
        int b;
};

//use使用,D使用C,D的部分成员方法依赖于C,耦合度较高
class C{
    public:
        int a;
};

class D{
    public:
        int b;
    
        //D的PrintC方法使用C类对象，只有在调用方法的时候才需要使用
        void PrintC(C c){       
            cout<<c.a<<endl;
        }
};

//is是，继承，F是E的子类，F继承并包含E的所有成员并且具有独立的内存布局
class E{
    public:
        int a;

    void PrintA(){
        cout<<this->a<<endl;
    }
};

//包含E的所有成员，并且是独立的内存空间
class F:public E    
{   
    public:
    int b;

    void test(){
        //子类对象可当作父类对象使用，详见类的兼容性原则
        cout<<this->a<<" "<<this->b<<endl;

        //子类对象可当作父类对象使用，详见类的兼容性原则
        this->PrintA();         
    }
};

void test1(){
    E e1;       //父类，基类
    F f1;       //子类，派生类

    e1.a;               
    e1.PrintA();
    f1.a;
    f1.PrintA();        
    f1.b;
    f1.test();
}

/*   
    子类继承父类后原成员的访问权限：

    继承方式/访问权限       public      protected       private
        public             public      protected       不可见
        protected          protected   protected       不可见         
        private            private     private         不可见
*/

class Parent{
    public:
        int a;
    protected:
        int b;
    private:
        int c;
};

class Child_1:public Parent
{
    public://共有继承，a可以在类的内外部访问，b可以在类的内部访问，c不可见
        void test(){       
            this->a;
            this->b;
            //this->c;
        }
};

class Child_2:protected Parent
{
    public://保护继承，a,b可以在类的内部访问，c不可见
        void test(){
            this->a;
            this->b;
            //this->c;
        }
};

class Child_3:private Parent
{
    public://私有继承，a,b可以在类的内部访问，c不可见
        void test(){
            this->a;
            this->b;
            //this->c;
        }
};

void test2(){
    Child_1 c1;
    c1.a;
    //c1.b;外部不可访问
    //c1.c;不可见

    Child_2 c2;
    //c2.a;外部不可访问
    //c2.b;外部不可访问
    //c2.c;不可见

    Child_3 c3;
    //c3.a;外部不可访问
    //c3.b;外部不可访问
    //c3.c;不可见
}

int main(){
    test1();
    test2();

    return 0;
}