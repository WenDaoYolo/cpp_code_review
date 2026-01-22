#include<iostream>
using namespace std;
int a;
int b=40;

/*
    c允许重定义全局变量，c++不允许
    int g_a=30;
    int g_a;
*/

void test1(){
    cout<<a<<endl;
    int c=50;    
    cout<<c;
    int d=60;
    cout<<d<<endl;
}

struct ttt{
    int age;
    char name[10];
};

union t{
    int a:20;
    int b:4;
};

void test2(){
    struct ttt t1;
    ttt t2;
    sizeof(struct ttt);
    sizeof(ttt);
    sizeof(union t);
    sizeof(t);
/*c语言中结构体等复合类型其类型都必须完整不能省略*/
/*c语言中函数的返回值可以没有类型，形参和实参可以不匹配，c++中则必须有且要匹配*/
}

void test3(){
    bool a;
    a=33;
    a=true;
    cout<<a<<endl;
    cout<<"sizeof(bool):"<<sizeof(bool)<<endl;
}

void test4(){
    int a=10;
    int b=20;
    (a>b?a:b)=666;              //c语言返回的则是不可修改的右值
                                //其底层的实现逻辑
    *(a>b?&a:&b)=999;           //返回变量的地址再解引用

    cout<<"test:"<<b<<endl;
}

void test5(){
    const int a=333;
    int b=444;
    //int* test=&a;   容器的安全等级不匹配

    const int* pa=&a;
    //*pa=444;   指针指向的空间不可改变
    pa=&b;

    int* const pb=&b;
    *pb=666;
    //pb=&a;     指针指向的地址不可改变

    const int* const pp=&a;
    //*pp=33;    指针指向的地址和空间都不可以改变
    //pp=&b;
}

void test6(){
    const int length=10;
    int arr[length]={3,4,5,6};
    cout<<arr[0]<<arr[1]<<arr[2]<<endl;
    cout<<"sizeof(arr[length]):"<<sizeof(arr)<<endl;
}

void test7(){
    //强转也无法改变
    const int a=222;
    const int* pa=&a;
    int* pa2=(int*)pa;//常量没有空间和地址，此时指针指向的是栈上临时开辟的空间
    *pa2=30;
    cout<<"\na:"<<a<<endl;
    cout<<"temp memory:"<<*pa2<<endl;
}

enum weekday{
    sunday=333,
    sateday=222,
    test
};

void test8(){
    weekday day=sunday;
    //day=222;          只能赋值枚举常量，不能赋其对应的常量值
}

int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();

    return 0;
}