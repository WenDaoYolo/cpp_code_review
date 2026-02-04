#include<iostream>
#include "My_array_int.h"

/*
    自定义数组类
    有参构造
    无参构造
    拷贝构造
    析构
    获取长度

    =重载
    <<重载
    >>重载
    []重载
    !=重载
    ==重载
*/

void test1(){
    My_array_int a1;
    My_array_int a2(5);
    My_array_int a3(3);

    cout<<"array 1 length:"<<a1.GetLen()<<endl;
    cout<<"array 2 length:"<<a2.GetLen()<<endl;
    cin>>a2>>a3;
    My_array_int a4(a3);
    a3=a2;
    a2=a4;

    cout<<"a3:"<<a3<<endl;
    cout<<"a2 and a4:"<<a2<<";"<<a4<<endl;

    if(a2==a4)
        cout<<"a2 and a4 are same as"<<endl;
    
    if(a2!=a3)
        cout<<"a2 are not same as a3"<<endl;

    a2[0]=666;
    cout<<"set a2:"<<a2<<endl;

}

int main(){
    test1();
    
    return 0;
}