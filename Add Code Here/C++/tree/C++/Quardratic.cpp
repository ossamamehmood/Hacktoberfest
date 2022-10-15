//3. roots of quadratic equation

#include <iostream> 
 #include <cmath>
using namespace std;
int main(){
  cout<<" please enter a, b and c according to your quadratic equation ax^2 + bx + c = 0 "<<endl;
    float a,b,c,r1,r2;// where a, b and c are coefficients as per quadratic equation ax^2 + bx + c = 0 and r1, r2 are roots of the equation
    cout<<"enter a :";
    cin>> a;
    cout<<"enter b :";
    cin>>b;
  cout<<"enter c :";
  cin>>c;
    r1= (-b+ sqrt(b*b-4*a*c))/(2*a);
    r2= (-b-sqrt(b*b-4*a*c))/(2*a);
    cout<<"roots are"<< r1 <<" "<<r2;
    return 0;
    }
