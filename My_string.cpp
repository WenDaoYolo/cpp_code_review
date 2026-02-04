#include "My_string.h"

My_string::My_string()
{
    this->len=0;
    this->str=NULL;
}

My_string::My_string(const char* str)
{
    this->len=strlen(str)+1;
    this->str=new char[this->len];
    strcpy(this->str,str);
}

My_string::My_string(const My_string& another_str)
{
    this->len=another_str.len;
    this->str=new char[this->len];
    strcpy(this->str,another_str.str);
}

My_string::~My_string()
{
    if(this->str!=NULL)
    {   
        delete this->str;
        this->str=NULL;
        this->len=0;
    }
}

bool My_string::operator==(const My_string& another) const
{
    if(this->len!=another.len)
    {
        return false;
    }

    for(int i=0;i<this->len;i++)
    {
        if(this->str[i]!=another.str[i])
            return false;
    }

    return true;
}

bool My_string::operator!=(const My_string& another) const
{
    if(this->len!=another.len)
    {
        return true;
    }

    for(int i=0;i<this->len;i++)
    {
        if(this->str[i]!=another.str[i])
            return true;
    }

    return false;
}

My_string& My_string::operator=(const My_string& another)
{
    if(this==&another)
    {
        cout<<"is my self"<<endl;
        return *this;
    }

    if(this->str!=NULL)
    {
        delete this->str;
        this->len=0;
        this->str=NULL;
    }

    if(this->str==NULL)
    {
        this->len=another.len;
        this->str=new char[this->len];
        strcpy(this->str,another.str);
    }
    return *this;
}

My_string My_string::operator+(const My_string& another) const
{
    My_string tmp;
    tmp.len=this->len+another.len-1;
    tmp.str=new char[tmp.len];
    
    strcpy(tmp.str,this->str);
    strcat(tmp.str,another.str);
    return tmp;
}

char& My_string::operator[](int index)
{
    return (this->str)[index];
}

ostream& operator<<(ostream& os,const My_string& s)
{
    os<<s.str;
    return os;
}

istream& operator>>(istream& os,My_string& s)
{
    cout<<"请输入"<<MAX_STRING<<"个字符以内的字符串>";
    char temp[MAX_STRING]={0};
    cin>>temp;

    s.len=strlen(temp)+1;
    strcpy(s.str,temp);
    return os;
}