#include<iostream>
#include<cstring>
using namespace std;

//c code style
struct people{
    char name[10];
    char food[10];
};

void Eat(char* name,char* food){
    printf("%s在吃%s\n",name,food);
}

//cpp code style
class animal{
    public:
        char name[10];
        char food[10];
        void Eat(char food[10]){
            cout<<this->name<<"在吃"<<this->food<<endl;
        }
};

void test1(){
    people xiaoming;
    strcpy(xiaoming.name,"小明");
    strcpy(xiaoming.food,"面条");

    animal dog;
    strcpy(dog.name,"小黄狗");
    strcpy(dog.food,"翔");

    //pop
    Eat(xiaoming.name,xiaoming.food);
    //oop
    dog.Eat(dog.food);
}

//c语言中实现结构体方法  结构体+函数指针

struct student{
    char name[10];
    char sex[10];
    void(*eat)();
};

void eat(){
    printf("this is a function for struct!\n");
};

void test2(){
    struct student t1;
    t1.eat=eat;           //将函数指针和函数方法进行关联
    t1.eat();             //通过内部函数指针调用外部关联的函数方法
}

int main(){
    test1();
    test2();

    //pop -> 过程(对象,参数)
    //oop -> 对象.过程(参数)
    return 0;
}