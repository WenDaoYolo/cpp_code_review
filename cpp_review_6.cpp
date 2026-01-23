#include<iostream>
#include "Circle.h"

using namespace std;

void DisplayCircle(Circle c1){
    cout<<"R:"<<c1.GetR()<<endl;
    cout<<"area:"<<c1.GetArea()<<endl;
    cout<<"length:"<<c1.GetLength()<<endl;
}

int main(){
    Circle c1;
    c1.SetR(3.11);
    DisplayCircle(c1);

    return 0;
}