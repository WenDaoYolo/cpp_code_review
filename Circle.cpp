#include "Circle.h"

void Circle::SetR(double r){
    this->r=r;
}

double Circle::GetR(){
    return this->r;
}

double Circle::GetArea(){
    double R=this->r;
    return 3.14*R*R;
}

double Circle::GetLength(){
    return 2*3.14*(this->r);
}