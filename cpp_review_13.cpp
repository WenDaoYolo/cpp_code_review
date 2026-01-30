#include<iostream>
using namespace std;

/*  
    静态类成员的应用
    友元函数与类
*/

//写一个类方法，求学生的平均分，要求其结果能随学生人数的动态增删而变化
class student{
    public:
        int sid;
        int age;
        float score;
        static int total_count;
        static float total_score;

        student(int sid,int age,float score){
            this->sid=sid;
            this->age=age;
            this->score=score;
            this->total_count++;
            this->total_score+=this->score;
        }

        ~student(){
            this->total_count--;
            this->total_score-=this->score;
        }

        float GetAvg(){
            return (this->total_score/this->total_count);
        }
};

int student::total_count=0;
float student::total_score=0.0;

void test1(){
    student t1(1,18,76.4);
    student t2(2,22,93.2);
    student* t3=new student(3,19,78.2);
    student* t4=new student(4,29,83);
    
    delete t4;
    t4=NULL;

    cout<<"nums:"<<student::total_count<<endl;
    cout<<"avg:"<<t1.GetAvg()<<endl;
}

//友元类与函数
class A{
    private:
        int a;
        int b;
    friend int Printa(A& a1);
    friend class B;
};

int Printa(A& a1){
    cout<<a1.a<<endl;       //友元函数Printa可以访问A类的private私有成员
}

class B{                    //友元类B可以访问A类的private私有成员
    public:
    int s;

    void test(A a1){
        cout<<a1.a<<" "<<a1.b<<endl;
    }
};

/*
    友元函数的特点：
    1.是单向的
    2.不具有传递性
    3.不能被继承
*/

int main(){
    test1();

    return 0;
}
