#include <iostream>
using namespace std;
class Rectangle
{
public:
    int length, breadth;
    int area()
    {
        return length * breadth;
    }
    int Perimeter();
};
int Rectangle::Perimeter()
{
    return 2 * (length + breadth);
}

int main()
{
    Rectangle r;

    Rectangle *p = new Rectangle();
    // r.length = 10;
    p->length = 10;
    p->breadth = 5;
    cout << p->area();
    cout << p->Perimeter();
    return 0;
}