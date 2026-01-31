#include<iostream>
#include<cstring>
using namespace std;

/*
    1.构造析构函数,等号赋值运算符
    2.括号,new,delete
*/

class student{
    public:
        int age;
        char* sex;
        char* name;

        student(){
            this->age=-1;
            this->name=NULL;
            this->sex=NULL;
        }

        student(int age,const char* name,const char* sex){
            this->age=age;
            this->sex=new char[7];
            this->name=new char[10];
            strcpy(this->sex,sex);
            strcpy(this->name,name);
        }

        student(const student& another){
                
                this->sex=new char[7];
                this->name=new char[10];

                this->age=another.age;
                strcpy(this->sex,another.sex);
                strcpy(this->name,another.name);
        }
                           //必须引用，否则无法通过自身的地址进行判断
        student& operator=(const student& another){
                if(this==&another)
                {
                    cout<<"is my self"<<endl;
                    return *this;
                }

                if(this->sex!=NULL)
                {
                    delete[] this->sex;
                    this->sex=NULL;
                }

                if(this->name!=NULL)
                {
                    delete[] this->name;
                    this->name=NULL;
                }

                int length_n=strlen(another.name)+1;
                int length_s=strlen(another.sex)+1;
                this->name=new char[length_n];
                this->sex=new char[length_s];

                this->age=another.age;
                strcpy(this->name,another.name);
                strcpy(this->sex,another.sex);

                return *this;
        }

        ~student(){
            if(this->sex!=NULL)
            {
                delete[] this->sex;
                this->sex=NULL;
            }

            if(this->name!=NULL)
            {
                delete[] this->name;
                this->name=NULL;
            }
        }

        friend ostream& operator<<(ostream& os,const student& s){
            os<<s.age<<" "<<s.name<<" "<<s.sex<<endl;
            return os;
        }

        void operator()(int num1,int num2){  //()重载后，对象又称为伪函数
            cout<<num1<<" "<<num2<<endl;
        }

        void* operator new(size_t size){     //new重载后也可以触发构造函数
                return malloc(size);      
        }

        void* operator new[](size_t size){
                return malloc(size);
        }

        void operator delete(void* ptr){     //delete重载后也会触发析构函数
                if(ptr!=NULL)
                    free(ptr);
        }

        void operator delete[](void* ptr){
                if(ptr!=NULL)
                    free(ptr);
        }
};

void test(){
    student s1(13,"jack","male");
    student s2(s1);
    student s3;
    s3=s3=s3;
    s3=s1;

    cout<<s1<<s2<<s3;
    s1(1314,999);
}

int main(){
    test();

    return 0;
}