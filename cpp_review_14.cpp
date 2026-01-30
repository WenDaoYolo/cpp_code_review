#include<iostream>
using namespace std;

/*
    1.基本语法
    2.重载规则
*/

/*
    普通方式：类方法与全局方法
    重载方式：类方法与全局方法
    写一个方法，能实现两个对象相应的值相加并返回对象
*/

//普通方式-全局方法
class add1{
    public:
        int x;
        int y;

        add1(int x,int y){
            this->x=x;
            this->y=y;
        }
};

add1 ADD1(add1 num1,add1 num2){
    add1 temp(0,0);
    temp.x=num1.x+num2.x;
    temp.y=num1.y+num2.y;
    return temp;
}

void test1(){
    add1 a1(3,4);
    add1 a2(5,6);
    cout<<"("<<a1.x<<","<<a1.y<<")+("<<a2.x<<","<<a2.y<<")=";

    add1 temp=ADD1(a1,a2);
    cout<<"("<<temp.x<<","<<temp.y<<")"<<endl;
}

//普通方式-类方法
class add2{
    public:
        int x;
        int y;

        add2(int x,int y){
            this->x=x;
            this->y=y;
        }

        add2 ADD2(add2 another){
            this->x+=another.x;
            this->y+=another.y;
            return *this;
        }
};

void test2(){
    add2 a1(1,2);
    add2 a2(1,2);
    cout<<"("<<a1.x<<","<<a1.y<<")+("<<a2.x<<","<<a2.y<<")=";
    
    add2 temp=a1.ADD2(a2);
    cout<<"("<<temp.x<<","<<temp.y<<")"<<endl;
}

//重载方式-全局方法
//隐式或显示调用，操作符左边对应形参1，操作符右边对应形参2
class add3{
    public:
        int x;
        int y;

        add3(int x,int y){
            this->x=x;
            this->y=y;
        }
};

add3 operator+(const add3 a1,const add3 a2){
    add3 temp(0,0);
    temp.x=a1.x+a2.x;
    temp.y=a1.y+a2.y;
    return temp;
}

void test3(){
    add3 a1(33,33);
    add3 a2(66,66);
    cout<<"("<<a1.x<<","<<a1.y<<")+("<<a2.x<<","<<a2.y<<")=";
    
    add3 temp=a1+a2;        //操作符调用
    temp=operator+(a1,a2);  //函数调用
    cout<<"("<<temp.x<<","<<temp.y<<")"<<endl;
}

//重载方式-类方法
//隐式调用，操作符左边对应this对象，操作符右边对应形参1
//显示调用，主调对象对应this对象，传递参数对应形参1

class add4{
    public:
        int x;
        int y;

        add4(int x,int y){
            this->x=x;
            this->y=y;
        }

        add4 operator+(const add4 another){
                add4 temp(0,0);
                temp.x=this->x+another.x;
                temp.y=this->y+another.y;
                return temp;
        }
};

void test4(){
    add4 a1(10,11);
    add4 a2(3,3);
    cout<<"("<<a1.x<<","<<a1.y<<")+("<<a2.x<<","<<a2.y<<")=";
    
    add4 temp=a1+a2;        //操作符调用
    temp=a1.operator+(a2);  //函数调用
    cout<<"("<<temp.x<<","<<temp.y<<")"<<endl;
}

/*
    操作符的重载规则
    1.只能对c++已有的操作符进行重载，不能创新
    2.不能重载的操作符：. .* :: ?:
      只能以类方法进行重载的操作符：(),[],->,=,类型转换
      特殊的重载操作符：->,虽然是二元，但被设计为一元，自动执行this->参数2
    3.不能使用默认参数，否则会造成重载参数匹配的错误
    4.不要改变原操作符的操作数个数
    5.不要改变原操作符的意义
    6.不能改变原操作符的优先级
    7.不能改变原操作符的结合性
    8.重载的操作符必须和自定义类对象结合使用，否则造成原操作符运算混乱
    9.用于类对象的运算符必须重载，但&和=不一定必须重载
    10.操作符重载的方法既可以是类方法，也可以是类的友元函数
*/

int main(){
    test1();
    test2();
    test3();
    test4();

    return 0;
}