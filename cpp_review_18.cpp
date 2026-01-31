#include<iostream>
using namespace std;
/*
    1.并且与或者
    2.->指针成员访问操作符
*/

//不建议重载并且和或者，无法还原逻辑截断的特性
//逻辑截断
void fun1(){
    int a=0,b=0;
    
    if(1||(a++))
        ;
    if(0&&(b++))
        ;
    cout<<a<<" "<<b<<endl;
}

//并且与或者的重载
class test{
    public:
        bool x;
        bool y;
        static int test_count;

        test(bool x,bool y){
            this->x=x;
            this->y=y;
        }
};

int test::test_count=0;

bool operator&&(const test& t1,const test& t2){
    test::test_count++;
    if(t1.x==true&&t2.x==true)
        return true;
    else
        return false;
}

bool operator||(const test& t1,const test& t2){
    test::test_count++;
    if(t1.x==false||t2.x==false)
        return false;
    else
        return true;
}

test& operator++(test& t){
    test::test_count++;
    return t;
}

void test1(){
    test t1(0,1);
    test t2(1,1);

    if(t1&&(++t2))
        ;
    if(t2||(++t1))
        ;
    //test::test_count=4 ->无法还原逻辑截断的行为
    cout<<"test_count:"<<test::test_count<<endl;
}

class T{
    public:
        int x;
        int y;

        T(){
            this->x=-1;
            this->y=-2;
        }

        T* operator->(){
            return this;
        }
};

void test2(){
    T t1;
    cout<<t1->x;       //重载->，返回this指针后，编译器自动执行this->x
}

int main(){
    fun1();
    test1();
    test2();

    return 0;
}