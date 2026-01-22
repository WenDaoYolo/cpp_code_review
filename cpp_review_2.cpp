#include<iostream>
using namespace std;

void test1(){
    int a=20;
    int& a0=a;
    int& a1=a;
    int& a2=a1;
    a2=333;
    cout<<"test:"<<a0<<" "<<a1<<" "<<a2<<" a:"<<a<<endl; 
}

void test2(int& arr){
    cout<<"test2:"<<arr<<endl;
}

void test3(){
    int a=30;
    int& b=a;
    cout<<"a address:"<<&a<<endl;
    cout<<"b address:"<<&b<<endl;
    cout<<"b size:"<<sizeof(int&)<<endl;   
    int& c=b;       //底层 -> int* const c=&b;
}

int& test4(){
    static int test=0;
    cout<<"static test:"<<test<<endl;
    return test;   
}

int& test5(){
    int a=10;
    return a;               //error! the value of return is not global!
}

void test6(){
    int b=60;
    const int a=50; 

	const int& tb=b;        //低安全性的变量可以用高安全性的容器装载
	//int& ta=a;            但高安全性的变量不能用低安全性的容器装载
}

inline void test7();        //函数声明，单文件编程中可以省略

inline void test7(){        //函数定义实现
    cout<<"yes!"<<endl;
}


int main(){
    test1();
    int a=999;
    int* pa=&a;
    test2(a);
    test3();

    test4()=50;
    test4();
    test5();
    test6();

    return 0;
}

