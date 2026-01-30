#include<iostream>
using namespace std;

/*
    1.左移与与右移运算符
    2.等号赋值运算符     
*/

/*
  左移右移操作符的重载：不建议以类方法重载，重载后其语法不符合原操作符的逻辑
  左移输出操作符的重载:cout本质是ostream类的对象
  分析：可以连续运算，所以应该返回cout关键字对象本身  
*/

//重载方式-全局方法
class Print1{
    public:
        int x;
        int y;

        Print1(int x,int y){
            this->x=x;
            this->y=y;
        }        
};

ostream& operator<<(ostream& os,Print1 p){
    os<<"("<<p.x<<","<<p.y<<")";
    return os;
}

void test1(){
    Print1 t1(1,2);
    Print1 t2(3,4);
    Print1 t3(5,6);
    cout<<t1<<t2<<t3;                                  //隐式调用
    cout<<endl;
    operator<<(operator<<(operator<<(cout,t1),t2),t3); //显示调用
    cout<<endl;
}

//重载方式-类方法
class Print2{
    public:
        int x;
        int y;

        Print2(int x,int y){
            this->x=x;
            this->y=y;
        }

        ostream& operator<<(ostream& os) const
        {
                os<<"("<<this->x<<","<<this->y<<")";
                return os;
        }
};

void test2(){
    Print2 p1(1,2);
    Print2 p2(9,8);
    p2<<(p1<<cout);                        //不符合原操作符的逻辑
    cout<<endl;
    p2.operator<<(p1.operator<<(cout));    //显示调用麻烦
    cout<<endl;
}

//右移输入操作符重载：与左移同理

//重载方式-全局重载
class Print3{
    public:
        int x;
        int y;

        Print3(int x,int y){
            this->x=x;
            this->y=y;
        }
};

istream& operator>>(istream& os,Print3& p){
    os>>p.x>>p.y;
    return os;
}

void test3(){
    Print3 p1(0,0);
    Print3 p2(0,0);

    cin>>p1>>p2;                          //隐式调用
    operator>>(operator>>(cin,p1),p2);    //显示调用
    cout<<p1.x<<","<<p1.y<<" "<<p2.x<<","<<p2.y;
    cout<<endl;
}

//重载方式-类方法
class Print4{
    public:
        int x;
        int y;
    
        Print4(int x,int y){
            this->x=x;
            this->y=y;
        }

        istream& operator>>(istream& os){
            os>>this->x>>this->y;
            return os;
        }
};

void test4(){
    Print4 p1(0,0);
    Print4 p2(0,0);
    p2>>(p1>>cin);
    p2.operator>>(p1.operator>>(cin));

    cout<<p1.x<<","<<p1.y<<" "<<p2.x<<","<<p2.y;
    cout<<endl;
}

int main(){
    test1();
    test2();
    test3();
    test4();

    return 0;
}