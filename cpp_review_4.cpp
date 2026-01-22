#include<iostream>
using namespace std;

//function pointer define

void function(int a,int b)
{
    cout<<a*b<<endl;
}

//style 1    typedef
typedef void(*funii_ptr)(int,int);

//style 2    define
void test1(){
    void(*ptr)(int,int)=function;
    funii_ptr ptr2=function;
    (*ptr)(3,4);
    ptr2(4,5);
}

//style 3    typedef + define
void test2()
{
    typedef void my_fun(int,int);
    my_fun* fun_ptr=function;
    fun_ptr(3,3);
}

//////////////////////////////////////////////////////

void funt(int a,char b){
    cout<<"funt(int,char)"<<endl;
}

void funt(int a){
    cout<<"funt(int)"<<endl;
}

void test3(){

    //初始化时函数指针与重载函数就已经进行了匹配和绑定
    void(*ptr1)(int,char)=funt;
    void(*ptr2)(int)=funt;

    ptr1(3,'w');
    ptr2(2);
    
    ptr1=funt;   //ptr自动与funt的相应重载函数进行匹配,底层指针已经绑定funt_a
                 //无法再修改其指向，通过该指针无法调用其他重载函数
    ptr1(3,'w');
}

int main(){ 
    test1();
    test2();
    test3();

    return 0;
}