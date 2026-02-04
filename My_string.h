#include<iostream>
#include<cstring>
#define MAX_STRING 64
#pragma once
using namespace std;

class My_string{
    public:
        int len;
        char* str;

        My_string();
        My_string(const char* str);
        My_string(const My_string& another_str);
        ~My_string();

        bool operator==(const My_string& another) const;
        bool operator!=(const My_string& another) const;
        My_string& operator=(const My_string& another);
        My_string operator+(const My_string& another) const;

        char& operator[](int index);
        friend ostream& operator<<(ostream& os,const My_string& s);
        friend istream& operator>>(istream& os,My_string& s);
};