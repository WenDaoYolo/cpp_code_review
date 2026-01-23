#include<iostream>

class Circle{
    private:
        int p_x;
        int p_y;
        double r;
    
    public:
        void SetR(double r);
        double GetR();
        double GetArea();
        double GetLength();
};
