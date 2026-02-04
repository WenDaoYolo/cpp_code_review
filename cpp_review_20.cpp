#include "teacher_u_ptr.h"
#include<iostream>
#include<memory>
using namespace std;

/*
    unique_ptr独占指针的使用
    模拟实现teacher类型的unique_ptr独占指针
    为了方便使用，则*和->需要重载，否则调用会更麻烦(例如:(ptr.space)->name)
*/

class student{
    public:
        int age;
        int id;
    
    ~student(){
        cout<<"智能指针调用delete回收对象类型的内存并触发了析构函数.."<<endl;
    }
};

void test1(){
    //student* sptr=new student;            普通指针不会自动回收动态内存
    unique_ptr<student> s_ptr(new student);
}

void test2(){
    teacher_u_ptr uniq_ptr(new teacher("zhang","male",14));
    teacher* normal_ptr=new teacher;
    cout<<uniq_ptr->age<<" "<<(*uniq_ptr).name<<" "<<uniq_ptr->sex<<endl;
}

int main(){
    test1();
    cout<<"------------after------------"<<endl;
    test2();
    cout<<"------------after------------"<<endl;

    return 0;
}