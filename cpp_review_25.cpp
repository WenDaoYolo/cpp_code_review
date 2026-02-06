#include<iostream>
#include<cstring>
using namespace std;
/*
    多态的基本概念
    多态的案例
    静态联编和动态联编
    虚析构函数
*/

/*
    多态：同一方法对于不同对象执行不同的操作
    例如：上课铃响了，高一学生走进了图书馆，高二学生去教室上课,高三学生大扫除

    实现多态的三个必要条件
    1.必须继承
    2.父类定义需要多态的虚函数，子类重写虚函数
    3.执行函数中，父类指针或引用指向子类对象
*/

/*
    虚析构函数：子类重写时无需函数名一致
    某些场景下需要多态析构函数,编译器会做安全转换
    普通函数中，父类指针只能调用父类方法(详见后续普通函数与虚函数)
    所以要避免出现父类方法析构子类对象导致内存泄漏
*/

/*
    联编：代码与代码之间有关联
    静态联编：编译期间已经确定好，一定会执行，例如
    普通函数，重载函数等,编译器默认采用静态联编

    动态联编：又称为迟绑定，代码是否够会执行是在程序允许期间确定的
    例如if,switch等判断语句，又例如多态
*/

/*
    模拟实现一个学生类，实现多态：不同年级
    的学生对于上课了响了,做出不同的反应,并实现动态内存回收时析构函数的多态
*/

class stu{
    public:
        int level;
        char name[10];

        stu(const char* name,int level){
            strcpy(this->name,name);
            this->level=level;
        }

        virtual void TakingClass(){
            cout<<"上课铃响了"<<endl;;
        }

        virtual ~stu(){
            ;
        }
};

class stu_1:public stu
{
    public:
        char* sex_1;

        virtual void TakingClass(){
            cout<<this->level<<"年级的"<<this->name<<"走进了图书馆"<<endl;
        }

        stu_1(const char* name,int level):stu(name,level)  //初始化
        {
            this->sex_1=new char;                          //赋值构造
        }

        ~stu_1(){
            if(this->sex_1!=NULL)
            {
                cout<<"~stu_1()..."<<endl;
                delete this->sex_1;
            }
        }
};

class stu_2:public stu
{
    public:
        char* sex_2;

        void TakingClass(){
            cout<<this->level<<"年级的"<<this->name<<"开始大扫除"<<endl;
        }

        stu_2(const char* name,int level):stu(name,level)
        {
            this->sex_2=new char;
        }

        ~stu_2(){
            if(this->sex_2!=NULL)
            {
                cout<<"~stu_2()..."<<endl;
                delete this->sex_2;
            }
        }
};

void Sudo(stu& s){
    s.TakingClass();      //发生多态
}

void Sudo2(stu* s){        
    s->TakingClass();     //发生多态
    delete s;             //发生多态,delete回收动态内存并触发虚析构函数
}

void test1(){
    stu_1 s1("张三",2);
    stu_2 s2("李四",1);

    Sudo(s1);
    Sudo(s2);
}

void test2(){
    stu_1* ps1=new stu_1("王五",1);
    stu_2* ps2=new stu_2("五四",3);

    Sudo2(ps1);
    Sudo2(ps2);
}

int main(){
    test1();
    cout<<"-------------------"<<endl;
    test2();

    return 0;
}