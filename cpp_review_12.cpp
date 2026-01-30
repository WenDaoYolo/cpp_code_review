#include<iostream>
using namespace std;

/*
    类的静态成员
    this指针
*/

//类的静态成员
class test{
    public:
        int a;
        int b;
        static int c;

        test(){
            this->a=10;
            this->b=100;
            this->c=1000;
        }

        static int t(){           //普通方法既可以返回静态也可以返回非静态对象
            cout<<"hello world!"<<endl;
            return c;             //静态方法只能返回静态对象
        }                         
};

int test::c=100;                  //类静态成员的初始化

void test1(){
    test t1;
    test t2;
    cout<<t1.c<<" "<<t2.c<<endl;  //可以通过实例对象访问
    cout<<test::c<<endl;          //也可以通过类直接访问

    t1.t();                       //静态成员方法同理
    test::t();
}

void test2(){                    //静态成员static的回顾
    static int m=999;            //虽然不会销毁，但也无法在外部访问(局部作用域)
    m++;                         //该静态成员只属于该函数
    cout<<m<<endl;
}

//this指针:指向当前对象的常指针，主要用于类方法中来区分对象，类方法的专属指针
//与当前对象绑定，指针的指向不可以改变，隐藏了this指针的参数细节，但可以使用
/*
    class test{
        public:
            int a;
            test(test* const this,int new_a){
                    this->a=new_a;
            }
    }

    ...

    test t1(3)  ->   底层：test(&t1,3)
*/

//this指针的指向不可改变，若想要指向的内容也不可改变，可用const修饰
//即const test* const this,只不过const的修饰位置，其语法有点特别

class ttt{
    public:
        int a;
        ttt()                     //注意构造和析构函数不允许使用const限定符
        {
            this->a=100;
        }

        ttt(int a){
            //a=a;               
            this->a=a;            //使用this指针，当变量重名时更好区分
        }

        void SetA() const
        {
            //this->a=33;         此时会发现this指向的对象其内容也不可改变
        }
};

int main(){
    test1();
    test2();                     //1000
    test2();                     //1001

    return 0;
}