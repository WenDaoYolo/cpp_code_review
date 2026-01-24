#include<iostream>
#include<cstring>
using namespace std;

/*
    1.深拷贝与浅拷贝
    2.构造函数的初始化列表
*/

class student{
    public:
        int age;
        char* name;

        student(){
            this->age=-1;
            this->name=(char*)malloc(sizeof(char)*10);
            strcpy(this->name,"jack");
        }

        ~student(){
            if(this->name!=NULL)
            {
                free(this->name);
                this->name=NULL;
            }
            cout<<"~student()..."<<endl;
        }

        student(int age,const char* name){      //有参构造函数 - 深拷贝
            this->age=age;
            this->name=(char*)malloc(sizeof(name));
            strcpy(this->name,name);
        }

        student(const student& another){
            if(this==&another)
            {
                cout<<"Is MySelf"<<endl;
                return;
            }

            this->age=another.age;

            //拷贝构造-深拷贝
            this->name=(char*)malloc(sizeof(strlen(another.name)+1));
            strcpy(this->name,another.name);

            //拷贝构造-浅拷贝
            /*
                this->name=another.name;
                在析构时会出现重复释放内存的风险或其他潜在风险
            */
        }

};

void test1(){
    cout<<endl<<endl<<endl;
    student s1;
    student s2=s1;
    student s3(s2);
    student s4(33,"jack");
}

class A{
    public:
    int a;
    A(int new_a){
        this->a=new_a;
        cout<<this->a<<"  A(int new_a)..."<<endl;
    }

    ~A(){
        cout<<this->a<<"  ~A()..."<<endl;
    }
};

class B
{
    public:
    A a2;
    A a1;
    int b;
    const int c;      //const常量成员只能且必须通过初始化列表来初始化

    //初始化列表中通过A类的有参构造来初始化A类对象成员,注意访问控制权限
    B(int new_a,int new_b):a1(new_a),a2(new_b),c(999)
    {
        //值的修改
        (this->a1).a=new_a;
        
        //this->a1=new_a;
        //注意，此写法是使用=直接对类对象a1进行赋值，若没有重载=则会隐式转换
        //创建一个临时对象进行赋值的过度，临时对象也会调用构造和析构函数
        

        //只有所有成员属性构造完成后对象才会完成构造
        this->b=new_b;
        cout<<"B(int new_a,int new_b):..."<<endl;
    }

    ~B(){
        cout<<"~B()..."<<endl;
    }
};

void test2(){
    cout<<"============="<<endl;
    B b1(1,2);

    //构造与析构的过程
    /*
        a2调用有参构造 2  A(int new_a)...
        a1调用有参构造 1  A(int new_a)...
        b1调用有参构造 B(int new_a,int new_b):...
        
        b1调用析构并销毁 ~B()...
        a1调用析构并销毁 1  ~A()...
        a2调用析构并销毁 2  ~A()...
    */
}

int main(){
    //test1();
    test2();

    return 0;
}