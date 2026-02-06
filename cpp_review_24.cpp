#include<iostream>
using namespace std;

/*
    1.继承中的注意事项
    2.多继承与虚继承
*/

/*
    1.
    父类与子类成员变量重名时，使用时需要通过公共方法或者作用域进行限定区分
    若不限定，则默认使用当前类对象的成员，多继承与虚继承中同理，但必须限定

    2.
    继承中的static变量属于类而非某个对象，父类及相关所有子类都共享该变量
*/

class Parent{
    public:
        int a;
        static int b;

        Parent(){
            this->a=666;
        }

        int GetPa(){
            return this->a;
        }

        void tpp(){
            this->b++;
        }
};

int Parent::b=0;

class Child:public Parent
{
    public:
        int a;

        Child()       //隐式调用父类的无参构造
        {
            this->a=999;
        }

        int GetCa(){
            //子类与父类成员重名，若不限定则默认使用当前类的成员a
            return this->a;
        }

        void tpp_c(){
            this->b+=2;
        }
};

class Child_Child:public Child
{
    public:
    void tpp_cc(){
        this->b+=3;
    }   
};

void test1(){
    Parent p1;
    Child c1;
    Child_Child cc1;

    cout<<c1.a<<endl;           //默认调用当前类的对象a
    cout<<c1.GetPa()<<endl;     //通过公共方法区分
    cout<<c1.Parent::a<<endl;   //通过作用域来限定

    p1.tpp();                   //继承中,父类及其相关子类共享static成员
    c1.tpp_c();
    cc1.tpp_cc();
    cout<<"p1 & c1 & cc1 b:"<<p1.b<<" "<<c1.b<<" "<<cc1.b<<endl;
}

/*
    多继承与虚继承：多继承是c++语言独有的机制，允许一个类继承多个类
    
    虚继承：用于解决多继承中的菱形问题
    菱形问题：子类继承时成员重复的问题，子类重复继承某一个基类的成员
    一个子类继承多个父类的某一成员，而父类们的这一成员又继承于同一个祖父
*/

class s1{
    public:
        int a;
        int s;
};

class s2{
    public:
        int b;
        int s;
};

class s3:public s1,public s2
{
    public:
        int c;

        void test(){
            cout<<this->s1::s<<endl;    //多继承中的重名成员，指向必须明确
        }
};

/*
    s3的内存布局：
        int s1::a;
        int s1::s;
        int s2::b;
        int s2::s;
        int c;
*/

void test2(){
    s3 s;
    cout<<sizeof(s3)<<endl;  //20
}

class Parent_1{
    public:
        int a;
};

class Parent_2:public Parent_1
{
    public:
        int b;
};

class Parent_3:public Parent_1
{
    public:
        int c;
};

class Child_1:public Parent_2,public Parent_3
{
    public:
        void test(){
            cout<<this->Parent_2::a<<endl;  //指向必须明确,但实际上是重复的
        }
};

class Parent_11{
    public:
        int a;
};

class Parent_22:virtual public Parent_11
{
    public:
        int b;
};

class Parent_33:virtual public Parent_11
{
    public:
        int c;
};

//子类可以继续采用虚继承，防止被他以后的子类
//重复继承，但会额外引入vbptr(虚基类指针,和后续的vptr同理)指针增加内
//存与时间开销，直接单虚继承会需要一个指针的大小，多虚继承时情况更复杂
class Child_11:public Parent_22,public Parent_33
{
    public:
        void test(){
            cout<<this->Parent_22::a<<endl;  //指向必须明确,但实际上是重复的
        }
};

void test3(){
    cout<<"-----"<<endl;
    cout<<"virtual before:"<<sizeof(Child_1)<<endl; 
    //16
    cout<<"virtual after:"<<sizeof(Child_11)<<endl; 
    //32 引入了vbptr指针，并且受内存对齐的影响
}

int main(){
    test1();
    test2();
    test3();

    return 0;
}