#include<iostream>
#include<cstring>
using namespace std;

/*  
    构造函数与析构函数  

    默认的无参构造，默认析构
    默认的拷贝构造，默认的等号操作符重载
*/

class student{
    public:
        char* name;
        int age;
        
        student(){  //无参构造
            this->age=-1;
            this->name=(char*)malloc(sizeof(char)*10);
            strcpy(this->name,"NULL");
            cout<<"Default Initzation success!"<<endl;
        }

        student(int age,const char* name){    //有参构造
            this->age=age;
            this->name=(char*)malloc(sizeof(char)*10);
            strcpy(this->name,name);
            cout<<"With value Initzation success!"<<endl;
        }

        ~student(){  //析构函数
            if(this->name!=NULL)
            {
                free(this->name);
                this->name=NULL;
                cout<<"Destry memory success!"<<endl;
            }
            cout<<"Finished Destry!"<<endl;
        }

        student(const student& stu){    //拷贝构造
                this->age=stu.age;

                //深拷贝，浅拷贝析构会进行多次释放！详见后续内容 
                this->name=(char*)malloc(sizeof(char)*10);
                strcpy(this->name,stu.name);
                cout<<"with object Initzation success!"<<endl;    
        }

        void operator=(const student& stu){     //等号操作符重载，详见后续
           //...
        }

};

void test1(){
    student s1;
    student s2(19,"jack");
    student s3(s2);

    cout<<s1.age<<" "<<s1.name<<endl;
    cout<<s2.age<<" "<<s2.name<<endl;
    cout<<s3.age<<" "<<s3.name<<endl;

    //手动调用析构，因为指针置空，所以多次调用析构不会重复释放内存
    s1.~student();     
}

class test{
    public:
        int a;
        int b;
};

void test2(){
    test t1;        //调用默认的无参构造进行初始化
    test t2(t1);    //调用默认的拷贝构造函数进行初始化
    test t3=t1;     //注意此写法是拷贝构造而非赋值
    test t4;        //调用默认的无参构造进行初始化
    t4=t1;          //初始化完成后，再调用等号操作符重载进行赋值
}

int main(){
    test1();
    test2();

    return 0;
}