#include<iostream>
using namespace std;

/*
    类中的重写重载重定义
    多态的原理
    vptr指针
*/

//重定义
class p1{
    public:
        void test1(){
        cout<<"old"<<endl;
    }
};

class c1:public p1
{
    public:
        void test1(){
        cout<<"new"<<endl;  //子类中的test1函数重定义，对父类中的test1覆盖
    }
};

//重载
void test2(int a,char b){
    ;
}

void test2(int a,char b,double c){   
    ;
}

//重写
class t{
    public:
        virtual void test(){
            ;
        }
};

class t_c:public t
{
    public:
        void test(){               //对父类中的虚函数进行覆盖
            ;
        }
};

/*
    多态的原理
    1.联编方式 ->动态联编
    2.vptr指针 ->通过vptr调用虚函数
    3.普通函数与虚函数 ->虚函数的调用取决于具体的内存布局
    所以父类指针或引用要指向子类对象(实际的内存布局)

父类指针 ->父类对象 -> 父类普通方法                               静态联编
		->父类对象 -> 父类vptr访问父类虚函数表 -> 父类虚函数       动态联编
        ->子类对象 -> 子类vptr访问子类虚函数表 -> 子类虚函数       动态联编
*/

/*
    虚函数会带来额外的时间和空间开销(和vbptr同理)
    vptr指针的分布初始化：子类对象构造时,首先会初始化父类
    构造父类部分时vptr暂时指向父类的虚函数表，构造子类时vptr再指向子类的虚函数表
*/

class Parent{
    public:
        int a;
        int b;

        virtual void test()
        {
            ;
        }
};

class Child:public Parent
{
    public:
        /*
            假设采用64位机器,子类的内存布局:
            vptr     0-7 
            int a    8-11
            int b    12-15
            最大对齐数4,0-15共16,所以最终大小为16字节
        */
};

class t1{
    public:
        int a;

        virtual void PrintT(){
            ;
        }

        t1(int a){
            this->a=a;
        }
};

class t2:public t1
{
    public:
        int b;

        void PrintT(){
            ;
        }

        t2(int a,int b):t1(a)//构造父类部分时，vptr暂时指向父类虚函数表
        {
            this->b=b;       //构造子类部分时，vptr指向子类虚函数表
        }
};

void test1(){
    cout<<sizeof(Child)<<endl;
}

int main(){
    test1();

    return 0;
}