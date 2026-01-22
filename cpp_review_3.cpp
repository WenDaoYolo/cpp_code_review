#include<iostream>
using namespace std;

void test1(int a=10){
    cout<<a<<endl;
}

void test2(){
    cout<<"single defalut value:";
    test1();
    cout<<"single real value:";
    test1(666);
}

void test3(int a,int b,int c=22){
    cout<<a<<b<<c<<endl;
}

void test4(){
    //test3(123);  参数缺省
    cout<<"multiple:\n";
    test3(44,55);
    test3(44,55,66);
}

void test50(int a,int){
    cout<<a<<endl;
}

void test51(int a,int=30){        //为占位符赋默认值后则无需再传参
    cout<<a<<endl;
}

void test6(){
    test50(3,4);
    test51(777);
}   

void fun1(){
    cout<<"fun()"<<endl;
}

void fun1(int a){
    cout<<"fun(int)"<<endl;
}

void fun1(char a,int b){
    cout<<"fun(char,int)"<<endl;
}

void testfun(){
    fun1();
    fun1(3);
    fun1('A',2);
}


void fun2(int b,char c){
    //...
}

// void fun2(int c,char b){    函数重定义
    //...
// }

// void fun2(int a,char c){    函数重定义
    //...
// }


//不在同一作用域，不是函数重载
class A{
    public:
        void fun3(){
            cout<<"yes"<<endl;
        }
};

void fun3(){
    //...
}

void fun4(int a,int b){
    //...
}

void fun4(int a,int b,int =30){   //占位符和默认参数会导致重载歧义，要避免
    //...
}

void testfun2(){
    //fun4(3,4);                  出现歧义
}

void f1(int a){      //底层符号表存储：f1_i
    cout<<"fun1"<<endl;
}

void f1(double a){   //底层符号表存储：f1_d
    cout<<"fun2"<<endl;
}

void testfun3(){
    f1(3);           //严格匹配
    f1(3.2);         //隐式转换后匹配
    f1('a');         //隐式转换后匹配
    //f1("hello");   无法匹配重载
}

int main()
{
    test2();
    test4();
    test6();
    testfun();
    testfun2();
    testfun3();
    
    return 0;
}