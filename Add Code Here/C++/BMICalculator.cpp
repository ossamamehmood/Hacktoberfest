include<iostream>
using namespace std;

int main()
{

float bmi,weight,height; 
cout<<"Please Enter your weight in Pounds : ";
    cin>>weight;
cout<<"Please Enter your Height in Inches : ";
    cin>>height;
bmi=(weight*703)/(height*height);
cout<<"Your BMI is : "<<bmi<<endl;

if(bmi>25)
    cout<<"Overweight";
else if(bmi<25 && bmi>18.5)
    cout<<"Optimal";
else
    cout<<"Underweight";
return 0;
}
