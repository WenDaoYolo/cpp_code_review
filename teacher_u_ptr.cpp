#include "teacher_u_ptr.h"

teacher::teacher()
{
    this->age=0;
    this->name=NULL;
    strcpy(this->sex,"Unknow");
}

teacher::teacher(const char* name,const char* sex,int age)
{
    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
    strcpy(this->sex,sex);
    this->age=age;
}

teacher::~teacher()
{
    if(this->name!=NULL)
    {
        delete[] this->name;
        this->name=NULL;
    }
    cout<<"~teacher()..."<<endl;
}

teacher_u_ptr::teacher_u_ptr(teacher* heap_space)
{
    this->heap_space=heap_space;
}

teacher_u_ptr::~teacher_u_ptr()
{
    if(this->heap_space!=NULL)
    {
        delete this->heap_space;
        this->heap_space=NULL;
    }
    cout<<"~teacher_u_ptr()..."<<endl;
}

teacher* teacher_u_ptr::operator->()
{
    return this->heap_space;
}

teacher& teacher_u_ptr::operator*()
{
    return *(this->heap_space);
}