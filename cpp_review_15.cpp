#include<iostream>
using namespace std;

/*
    1.单目与双目运算符
*/

/*
    双目运算符的重载，例如+=
    分析：+=可以连续运算，所以应该返回被加对象的引用
*/
void fun1(){
    int a=10;
    int b=20;
    (a+=b)+=b;
    cout<<a<<endl;
}

//重载方式-全局方法：若属性是私有成员，则全局方式需要声明友元函数
class op1{
    private:
        int x;
        int y;
    public:
        op1(int x,int y){
            this->x=x;
            this->y=y;
        }

        friend op1& operator+=(op1& obj1,const op1 obj2)
        {   
            obj1.x+=obj2.x;
            obj1.y+=obj2.y;
            return obj1;
        }

        int GetX(){
            return this->x;
        }

        int GetY(){
            return this->y;
        }
};

void test1(){
    op1 p1(3,3);
    op1 p2(6,6);
    p1+=p2;                //9,9
    operator+=(p1,p2);     //15,15
    (p1+=p2)+=p1;          //42,42
    cout<<"result:"<<p1.GetX()<<","<<p1.GetY()<<endl;
}

//重载方式-类方法
class op2{
    public:
        int x;
        int y;
        
        op2(int x,int y){
            this->x=x;
            this->y=y;
        }

        op2& operator+=(const op2 another){
                this->x+=another.x;
                this->y+=another.y;
                return *this;
        }
};

void test2(){
    op2 o1(11,22);
    op2 o2(11,33);

    o1+=o2;              //22,55
    o1.operator+=(o2);   //33,88
    (o1+=o2)+=o2;        //55,154
    cout<<"result:"<<o1.x<<","<<o1.y<<endl;
}

/*
    单目运算符的重载：例如前置++(前置--同理)
    分析：可以连续进行运算，所以应该返回自增对象的引用
*/
void fun2(){
    int a=1;
    ++++++a;
    cout<<a<<endl;
}

//重载方式-全局方法
class op3{
    public:
        int x;
        int y;

        op3(int x,int y){
            this->x=x;
            this->y=y;
        }
};

op3& operator++(op3& o1){
    o1.x++;
    o1.y++;
    return o1;
}

void test3(){
    op3 o1(12,34);
    ++o1;             //13,35
    operator++(o1);   //14,36
    ++(++o1);         //16,38
    cout<<"result:"<<o1.x<<","<<o1.y<<endl;
}

//重载方式-类方法
class p4{
    public:
        int x;
        int y;

        p4(int x,int y){
            this->x=x;
            this->y=y;
        }

        p4& operator++(){
            this->x++;
            this->y++;
            return *this;
        }
};

void test4(){
    p4 o1(1,2);
    ++o1;            //2,3
    o1.operator++(); //3,4
    ++++o1;          //5,6
    cout<<"result:"<<o1.x<<","<<o1.y<<endl;
}

/*
    单目运算符-后置++(--同理),为了区分前置++--，函数方法需要使用占位符
    经过分析：后置++不可以连续运算，所以应该返回不可修改的左值
*/
void fun3(){
    int x=4;
    //x++++;      无法连续运算
}

//重载方式-全局方法
class p5{
    public:
        int x;
        int y;
    
        p5(int x,int y){
            this->x=x;
            this->y=y;
        }
};

const p5 operator++(p5& o1,int){
        o1.x++;
        o1.y++;
        return o1;
}

void test5(){
    p5 o1(3,3);
    o1++;                     //4,4
    operator++(o1,0);         //5,5  占位符，需要额外参数
    //o1++++;
    cout<<"result"<<o1.x<<","<<o1.y<<endl;
}

//重载方式-类方法
class p6{
    public:
        int x;
        int y;

        p6(int x,int y){
            this->x=x;
            this->y=y;
        }

        const p6 operator++(int){
            this->x++;
            this->y++;
            return *this;
        }
};

void test6(){
    p6 o1(1,2);
    o1++;                //2,3
    o1.operator++(0);    //3,4
    //o1++++;
    cout<<"result:"<<o1.x<<","<<o1.y<<endl;
}

int main(){
    fun1();
    test1();
    test2();
    
    fun2();
    test3();
    test4();  

    fun3();  
    test5();
    test6();

    return 0;
}