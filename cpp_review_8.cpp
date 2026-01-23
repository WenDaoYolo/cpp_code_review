#include<iostream>
#include<cstring>
using namespace std;

/*
    1.构造与析构的顺序以及过程
    2.拷贝构造发生的时机,匿名对象
    3.拷贝构造与等号赋值的区别
*/

class test{
    public:
        int a;
        int b;

        test(int a,int b){
            this->a=a;
            this->b=b;
            cout<<"test(int a,int b)..."<<endl;
        }

        test(){
            this->a=1;
            this->b=1;
            cout<<"test()..."<<endl;
        }

        test(const test& another){
            this->a=another.a;
            this->b=another.b;
            cout<<"test(const test& another)..."<<endl;
        }

        void operator=(const test& another){
            this->a=another.a;
            this->b=another.b;
            cout<<"void operator=(const test& another)..."<<endl;
        }

        ~test(){
            cout<<"~test()..."<<endl;
        }
        
        void TranObject(test another){
            cout<<"TranObject..."<<endl;
        }

        test ReturnObject(){
            cout<<"ReturnObject..."<<endl;
            return *this;
        }

};

void test1(){
    test t1;
    test t2(2,2);
    test t3(t2);
    test t4=t1;
    test t5;
    t5=t1;
    cout<<"-----------"<<endl;
    t4=t1.ReturnObject();
    t3.TranObject(t2);
}

/*
    过程分析：
    1.创建t1并调用无参构造初始化
    2.创建t2并调用有参构造初始化
    3.创建t3并调用拷贝构造初始化
    4.创建t4并调用拷贝构造初始化
    5.创建t5并调用无参构造初始化
    6.使用t1通过等号操作符重载为t5赋值
    7.函数返回一个局部变量时，此时创建匿名对象，值拷贝给匿名对象会发生拷贝构造
    8.匿名对象赋值给接收对象，匿名对象销毁，调用析构函数
    9.传参的过程中，实参对象到形参对象的值传递，也会发生拷贝构造，函数销毁时形参对象销毁也会调用析构函数
    10.对象依次销毁，调用析构

    test()...
    test(int a,int b)...
    test(const test& another)...
    test(const test& another)...
    test()...
    void operator=(const another)...
    -----------
    ReturnObject...
    test(const test& another)...
    void operator=(const another)...
    ~test()...
    test(const test& another)...
    TranObject...
    
    ~test()...
    ~test()...
    ~test()...
    ~test()...
    ~test()...
    ~test()...

*/


int main(){
    test1();

    return 0;
}