#include <iostream>
#include <math.h>
using namespace std;
class Shape{
    public:
    virtual float area()=0;
    virtual float perimeter() =0;
};
class Rectangle : public Shape{
    private:
    float length, breadth;
    public:
    Rectangle(float l, float b){
        length =l;
        breadth =b;
    }
    float area(){
        return length*breadth;
    }
    float perimeter(){
        return 2*(length+breadth);
    }
};
class Circle : public Shape{
    private:
    float radius;
    public:
    Circle(float r){
        radius =r;
    }
    float area(){
        return M_PI*pow(radius,2);
    }
    float perimeter(){
        return M_PI*radius*2;
    }
};
int main(){
    Shape *s = new Rectangle(10,5);
    cout << s->area()<< endl;
    cout<< s->perimeter() << endl;
    s= new Circle(10);
    cout << s->area() << endl;
    cout<< s->perimeter() << endl;

    return 0;
}