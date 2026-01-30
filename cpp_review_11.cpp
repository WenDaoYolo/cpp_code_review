#include<iostream>
using namespace std;

/*
    new与delete
    malloc与free
*/

class test{
    public:
        int a;
        int b;
    
    test(){
        this->a=666;
        this->b=999;
        cout<<"test()..."<<endl;
    }

    test(int new_a,int new_b){
        this->a=new_a;
        this->b=new_b;
        cout<<"test(int,int)..."<<endl;
    }

    void Setter(int a,int b){
        this->a=a;
        this->b=b;
        cout<<"void Setter(int,int)..."<<endl;
    }

    ~test(){
        cout<<"~test()..."<<endl;
    }
};

//malloc 与 free
void test1(){
    test* tptr=(test*)malloc(sizeof(test));
    cout<<"malloc object:"<<tptr->a<<" "<<tptr->b<<endl;
    test* tptr2=(test*)malloc(sizeof(test));

    free(tptr);
    tptr=NULL;

    cout<<"in hand"<<endl;
    tptr2->Setter(33,44);
    cout<<tptr2->a<<" "<<tptr2->b<<endl;
    tptr2->~test();
    free(tptr2);
    tptr2=NULL;
}

//new 与 delete
void test2(){
    test* tptr=new test(111,222);
    test* tptr2=new test();
    test* tptr3=new test;
    cout<<"new object:"<<tptr->a<<" "<<tptr->b<<endl;
    cout<<"new object:"<<tptr2->a<<" "<<tptr2->b<<endl;
    cout<<"new object:"<<tptr3->a<<" "<<tptr3->b<<endl;

    delete tptr;
    delete tptr2;
    delete tptr3;
    tptr=NULL;
    tptr2=NULL;
    tptr3=NULL;
}

//malloc与delete，new与free也可以混用，但不建议

int main(){
    
    test1();
    cout<<"---------------------"<<endl;
    test2();

    return 0;
}