#include "My_array_int.h"

My_array_int::My_array_int()
{
    this->space=NULL;
    this->len=0;
}

My_array_int::My_array_int(int len)
{
    if(len<0)
    {
        cout<<"array length is error!"<<endl;
        return;
    }

    this->len=len;
    this->space=new int[this->len];
}

My_array_int::My_array_int(const My_array_int& another)
{
    this->len=another.len;
    this->space=new int[this->len];

    for(int i=0;i<this->len;i++)
        this->space[i]=another.space[i];
}

My_array_int::~My_array_int(){
    if(this->space!=NULL)
    {
        delete[] this->space;
        this->space=NULL;
        this->len=0;
        cout<<"array space clear succ!"<<endl;
    }
    cout<<"destroy succ!"<<endl;
}

int My_array_int::GetLen() const
{
    return this->len;
}

My_array_int& My_array_int::operator=(const My_array_int& another)
{
    if(this==&another)
    {
        cout<<"is my self!"<<endl;
        return *this;
    }

    if(this->space!=NULL)
    {
        delete[] this->space;
        this->space=NULL;
        this->len=0;
    }

    if(this->space==NULL)
    {
        this->len=another.len;
        this->space=new int[this->len];
        
        for(int i=0;i<this->len;i++)
            this->space[i]=another.space[i];
    }

    return *this;
}

int& My_array_int::operator[](const int index)
{   
    return this->space[index];
}

ostream& operator<<(ostream& os,const My_array_int& a)
{
    for(int i=0;i<a.GetLen();i++)
        os<<a.space[i]<<" ";

    return os;
}

istream& operator>>(istream& os,const My_array_int& a)
{
    cout<<"ÇëÊäÈë"<<a.GetLen()<<"¸öÊý>";
    for(int i=0;i<a.GetLen();i++)
        os>>a.space[i];

    return os;
}

bool operator==(const My_array_int& a1,const My_array_int&a2)
{
    if(a1.GetLen()!=a2.GetLen())
        return false;

    for(int i=0;i<a1.GetLen();i++)
    {
        if(a1.space[i]!=a2.space[i])
            return false;
    }

    return true;
}

bool operator!=(const My_array_int& a1,const My_array_int&a2)
{
    if(a1.GetLen()!=a2.GetLen())
        return true;

    for(int i=0;i<a1.GetLen();i++)
    {
        if(a1.space[i]==a2.space[i])
            return false;
    }

    return true;
}