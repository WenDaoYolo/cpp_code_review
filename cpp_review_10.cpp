#include<iostream>
using namespace std;


class test{
	public:
	int a;
	test(int a){
		this->a=a;
		cout<<"test(a)..."<<endl;
	}
	
	~test(){
		cout<<"~test()..."<<endl;
	}
};

int main(){
	test t1(3);
	t1=4;        //没有重载=操作符，直接修改对象则会发生隐式转换

	return 0;
}