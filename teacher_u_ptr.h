#include<iostream>
#include<cstring>
#pragma once
using namespace std;

class teacher{              //动态内存数据区
    public:
        char* name;
        char sex[7];
        int age;

        teacher();
        teacher(const char* name,const char* sex,int age);
        ~teacher();
};

class teacher_u_ptr{        //静态内存接管区
    private:
        teacher* heap_space;
    public:
        ~teacher_u_ptr();
        teacher_u_ptr(teacher* heap_space);
        teacher* operator->();
        teacher& operator*();
};