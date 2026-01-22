#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>

namespace t1{
    int a;
};

namespace t2{
    int a;
};

namespace t3{
    int b;             //优先使用外层中的变量b
    namespace t4{           
        int b;
    };
};

namespace t5{               
    namespace t6{      //使用时指定具体的命名空间路径，或在命名空间中进行指定
        int a;
    };                       
    namespace t7{
        int a;
    };
    using namespace t6;
};

void test1(){               //在test1函数中使用std命名空间
    using namespace std;    
    cout<<"yes!"<<endl;     //cout是std空间中的关键字
}

void test2(){
    using namespace t1;
    using namespace t2;
    //a=30;                 t1和t2命名空间中的变量a冲突
    t1::a=20;               //使用时指定作用域
}

void test3(){
    using namespace t3;
    b=20;                   
}

void test4(){
    using namespace t5;
    a=20;
    t5::t7::a=30;
}

int main(){
    using namespace t1;
    using t2::a;
    using t3::t4::b;

    using namespace std;
    int bbb;
    cin>>bbb;
    cout<<right<<setw(10)<<"this"<<bbb<<endl;
    
    return 0;
}