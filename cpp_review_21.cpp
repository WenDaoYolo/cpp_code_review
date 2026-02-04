#include<iostream>
#include "My_string.h"
#include<cstring>
using namespace std;

void test1(){
    string s1("hello");
    string s2(" world");
    string s3=s1+s2;
    cin>>s2;
    cout<<s2<<endl;
    s2[0]='H';
    cout<<s2<<endl;
    cout<<s3<<endl;
}

void test2(){
    My_string s1("LiuYueYang");
    My_string s2;
    My_string s3(s1);
    s2=s3;
    My_string s4=s1+s3;

    cout<<s4<<" "<<s1<<endl;
    cin>>s2;
    s2[0]='R';
    cout<<s2<<endl;

    if(s1==s3)
        cout<<"s1==s3"<<endl;
    if(s1!=s2)
        cout<<"s1!=s2"<<endl;
}

int main(){
    //test1();
    test2();

    return 0;
}