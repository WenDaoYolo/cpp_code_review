#include<iostream>
#pragma once;
using namespace std;

class My_array_int{
    public:
        size_t len;
        int* space;

        My_array_int();
        My_array_int(int len);
        My_array_int(const My_array_int& another);
        ~My_array_int();

        int GetLen() const;
        My_array_int& operator=(const My_array_int& another);
        int& operator[](const int index);        
};

ostream& operator<<(ostream& os,const My_array_int& a);
istream& operator>>(istream& os,const My_array_int& a);
bool operator==(const My_array_int& a1,const My_array_int&a2);
bool operator!=(const My_array_int& a1,const My_array_int&a2);