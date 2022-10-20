#include <iostream>
#include <iomanip>
using namespace std;
class sample
{
    int a, b;

public:
    void getdata()
    {
        a = 5;
        b = 6;
    }
    friend float mean(sample);
};
float mean(sample x)
{
    return (x.a + x.b) / 2.0;
}
int main()
{
    cout << fixed << setprecision(2); // to cout float value 
    // RIP code
    setprecision(2) help us to print 2
    samp

}