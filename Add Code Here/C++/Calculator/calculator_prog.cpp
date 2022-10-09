#include <iostream>
#include <cmath>
#include <string>
#include<algorithm>
#include <vector>
using namespace std;

//Function Call for Each Calculation
void switchcase(int sino);
void arithmetic();
void trignometry();
void logarithmic();
void exponential();
void relational();
void addition();
void subtraction();
void multiplication();
void division();
double raddegcheck(int &);
void inversetrig();
void trig();
void Sin(double pi);
void Cos(double pi);
void Tan(double pi);
void Cot(double pi);
void Sec(double pi);
void Cosec(double pi);
void ArcSin();
void ArcCos();
void ArcTan();
void ArcCot();
void ArcSec();
void ArcCosec();
//void modu();

int main() {
    cout << "Welcome to Calculator Program"<< endl ;
    cout<<"This is a program to perform various mathematical operations such as Arithmetic, Trignometric,"
          "Exponential, Logarithmic Functions and Relational Operations"<<endl;
    /*cout<<endl<<"1. Arithmetic Operations"<<endl<<"2. Trignometric Operations"<<endl<<"3. Logarithmic Functions";
    cout<<endl<<"4. Exponential Functions"<<endl<<"5. Relational Operations"<<endl;*/

    bool cont=true;
    char yesno;
    int SINo;

    //For user to enter the value continuously till a limit/

    while(cont)
    {
        cout<<"Enter a number to perform the operation(between 1-5)";
        cout<<endl<<"1. Arithmetic Operations"<<endl<<"2. Trignometric Operations"<<endl<<"3. Logarithmic Functions";
        cout<<endl<<"4. Exponential Functions"<<endl<<"5. Relational Operations"<<endl;
        cin>>SINo;

        if(SINo>0 && SINo<=5)
        {
            switchcase(SINo);
        }
        else
        {
            cout<<endl<<"Enter a valid number between 1 and 5"<<endl;
            continue;
        }
        //Checking whether the use want to continue the program//

        checkagain:
    cout<<"Enter (Y/N) for Continuing Calculator Program "<<endl<<"Y for Continue"<<endl<<"N for Exiting"<<endl;
    cin>>yesno;

        if (yesno == 'y' || yesno == 'Y')
        {
            {
                cont = true;
            }
        }

        else if (yesno == 'n' || yesno == 'N')
        {
            {
                cont = false;
                cout << "Calculator Program Ended Successfully" << endl;
            }

        }
        else
        {
            cout << "Wrong Output" << endl;
            goto checkagain;
           // cout << "Wrong Output. Yes(Y) taken as default" << endl;
        }
     

    }
    return 0;
}
void switchcase(int sino)
{
    //To check which operation to be performed//

    switch(sino)
    {
        case 1:
        {
            arithmetic();
            cout<<endl;
            break;
        }
        case 2:
        {
            trignometry();
            cout<<endl;
            break;
        }
        case 3:
        {
            logarithmic();
            cout<<endl;
            break;
        }
        case 4:
        {
            exponential();
            cout<<endl;
            break;
        }
        case 5:
        {
            relational();
            cout<<endl;
            break;
        }
        default:
        {
            cout<<"This will never get printed!!!"<<endl;
            break;
        }
    }
}

//Arithmetic Operation//
void arithmetic()
{
    cout<<endl<<"Welcome To Arithmetic Operations such as"<<endl;
    cout<<"Addition, Subtraction, Multiplication, Division"<<endl;
    bool cont1=true;
    char yesorno;
    int switchvalue;
    while(cont1)
    {
        cout<<"Enter a number between 1 and 5 to perform Arithmetic Operation"<<endl;
        cout<<"1 for Addition"<<endl<<"2 for Subtraction"<<endl;
        cout<<"3 for Multiplication"<<endl<<"4 for Division"<<endl;
//      cout<<"5 for Modulus"<<endl;
        cin>>switchvalue;
        if (switchvalue>0 && switchvalue<=4)
        {
            switch(switchvalue)
            {
                case 1:
                {
                    addition();
                    cout<<endl;
                    break;
                }
                case 2:
                {
                    subtraction();
                    cout<<endl;
                    break;
                }
                case 3:
                {
                    multiplication();
                    cout<<endl;
                    break;
                }
                case 4:
                {
                    division();
                    cout<<endl;
                    break;
                }
/*                case 5:
                {
                    modu();
                    cout<<endl;
                    break;
                }*/
                default: 
                    break;
            }
        }
        else
        {
            cout<<"Enter a valid number between 1 and 4"<<endl;
            continue;
        }
        //Checking whether the use want to continue the program//
        arithmeticcheck:
        cout<<"Enter (Y/N) for Arithmetic Operations"<<endl<<"Y for continue"<<endl<<"N for Exiting"<<endl;
        cin>>yesorno;

        if (yesorno == 'y' || yesorno == 'Y')
        {
            {
                cont1 = true;
            }
        }

        else if (yesorno == 'n' || yesorno == 'N')
        {
            {
                cont1 = false;
                cout << "Arithmetic Operation Completed Successfully" << endl;
            }

        }
        else
        {
            cout << "Wrong Output" << endl;
            goto arithmeticcheck;
           // cout << "Wrong Output. Yes(Y) taken as default" << endl;
        }
    }
}
void addition()
{
    double n,ar[1024],sum=0;
    int i;
    cout<<"No of terms to find sum"<<endl;
    cin>>n;
    cout<<endl<<"Enter numbers";
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    for(i=0;i<n;i++)
    {
        sum=sum+ar[i];
    }
    cout<<endl<<"Sum of "<<i<<" terms is"<<sum<<endl;
}
void subtraction()
{
    cout<< endl;
    double n,ar[1024],diff;
    int i;
    cout<<"No of terms to find difference"<<endl;
    cin>>n;
    cout<<endl<<"Enter numbers"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    diff=ar[0];
    for(i=1;i<=n;i++)
    {
        diff=diff-ar[i];
    }
    cout<<endl<<"Difference of "<<i<<" terms is"<<diff<<endl;
}
void multiplication()
{
    cout<< endl;
    double n,ar[1024],pro=1;
    int i;
    cout<<"No of terms to find product"<<endl;
    cin>>n;
    cout<<endl<<"Enter numbers"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    for(i=0;i<n;i++)
    {
        pro=pro*ar[i];
    }
    cout<<endl<<"Sum of " << i-1<<" terms is "<<pro<<endl;
}
void division()
{
    cout<< endl;
    double n,ar[1024],div;
    int i;
    cout<<"No of terms to divide: "<<endl;
    cin>>n;
    cout<<endl<<"Enter numbers: "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    div=ar[0];
    for(i=1;i<n;i++)
    {
        if (ar[i] != 0)
        {
            div = div / ar[i];
        }
        else
        {
            cout<<endl<<"Division by zero is underdefined!! "<<endl;
            break;
        }
    }
    cout << endl << "Quotient of " << i << " terms is" << div << endl;

}
/*void modu()
{
    float a,b;
    cout<<"Enter the number to find the modulus";
    cin>>a;
    b= a % 10;
}*/

//Trignometric Operations
void trignometry()
{
    int a;
    bool cont1=true;
    char yesorno;
    int switchvalue;
    while(cont1)
    {
        cout<<"Enter a value for performing the calculation";
        cout<<endl<<"1.Trigonometric function" <<endl<<"2.Inverse Trigonometric"<<endl;//<<"3.Hyperbolic Function"<<endl;//
        cin>>a;
        if(a==1)
        {
            trig();
        }
        else if(a==2)
        {
            inversetrig();
        }
        else
        {
            cout<<endl<<"Enter a valid number"<<endl;
            continue;
        }
        //Checking whether the use want to continue the program//
        tricheck:
        cout<<"Enter (Y/N) for Trigonometric Operations(Both Trig and Inverse) "<<endl<<" Y for continue "<<endl<<" N for Exiting "<<endl;
        cin>>yesorno;

        if (yesorno == 'y' || yesorno == 'Y')
        {
            {
                cont1 = true;
            }
        }

        else if (yesorno == 'n' || yesorno == 'N')
        {
            {
                cont1 = false;
                cout << "Trigonometric Operations(Both Trig and Inverse) Completed Successfully" << endl;
            }

        }
        else
        {
         cout << "Wrong Output." << endl;
         goto tricheck;
        }
    }
}


void trig()
{
    cout<<endl<<"Welcome To Trigonometric Calculation"<<endl;
    bool cont1=true;
    const double pi=3.14159265358979323846;
    char yesorno;
    int switchvalue;
    while(cont1)
    {
        cout << endl << " 1.Sine "<<endl<<" 2.Cosine "<<endl<<" 3.Tangent "<<endl<<" 4.Cotangent "<<endl<<" 5.Secant "<<endl<<" 6.Cosecant"<<endl;
        cin >> switchvalue;

        if (switchvalue >= 1 && switchvalue <= 6)
        {
            switch (switchvalue)
            {
                case 1:
                {
                    Sin(pi);
                    break;
                }
                case 2:
                {
                    Cos(pi);
                    break;
                }
                case 3:
                {
                    Tan(pi);
                    break;
                }
                case 4:
                {
                    Cot(pi);
                    break;
                }
                case 5:
                {
                    Sec(pi);
                    break;
                }
                case 6:
                {
                    Cosec(pi);
                    break;
                }
                default:
                {
                    cout<<"This will never get printed!!!"<<endl;
                    break;
                }
            }
        }
        else
        {
            cout << endl << "Enter a Valid number between 1 and 6"<<endl;
            continue;
        }

        //Checking whether the use want to continue the program//
        trigcheck:
        cout << "Enter (Y/N) for Trigonometric Operations" << endl << "Y for continue " << endl << "N for Exiting " << endl;
        cin >> yesorno;

        if (yesorno == 'y' || yesorno == 'Y') {
            {
                cont1 = true;
            }
        } else if (yesorno == 'n' || yesorno == 'N') {
            {
                cont1 = false;
                cout << "Trigonometric Operation Completed Successfully" << endl;
            }

        } else {

            cout << "Wrong Output!!" << endl;
            goto trigcheck;
        }
    }
}

double raddegcheck(int &num){
    const double pi=3.14159265358979323846;
    double b,c;
    double radian;
    cout<<endl<<"Enter your Choice"<<endl<<"1 for Degree"<<endl<<"2 for Radian"<<endl;
    cin>>num;
    if(num==1){
            cout<<"Enter the number in degree"<<endl;
            cin>>c;
            radian = (c*pi)/180;
            return radian;
    }
    else if(num==2){
            cout<<"Enter the number is radian"<<endl;
            cin>>c;
            return c;
    }
    else{
        cout<<"Wrong Input!!"<<endl;
    }
    }

void Sin(double pi)
{
    int num;
    double b=raddegcheck(num);
    if(num==1||num==2){
    double c=sin(b);
    cout<<"Value is "<<c<<endl;
    }
}
void Cos(double pi)
{
    int num;
    double b=raddegcheck(num);
    if(num==1||num==2){
    double c=cos(b);
    cout<<"Value is "<<c<<endl;
    } 
}
void Tan(double pi)
{
    int num;
    double b=raddegcheck(num);
    if(num==1||num==2){
    double c=sin(b)/cos(b);
    cout<<"Value is "<<c<<endl;
    }
}
void Cot(double pi)
{
    int num;
    double b=raddegcheck(num);
    if(num==1||num==2){
    double c=cos(b)/sin(b);
    cout<<"Value is "<<c<<endl;
    }
}
void Sec(double pi)
{
    int num;
    double b=raddegcheck(num);
    if(num==1||num==2){
    double c=1/cos(b);
    cout<<"Value is "<<c<<endl;
    }
}
void Cosec(double pi)
{
    int num;
    double b=raddegcheck(num);
    if(num==1||num==2){
    double c=1/sin(b);
    cout<<"Value is "<<c<<endl;
    }
}

void inversetrig()
{
    cout<<endl<<"Welcome To Inverse Trigonometric calculation"<<endl;
    bool cont=true;
    char yesorno;
    int switchvalue;
    
    while(cont){

        cout << endl << "1.ArcSine "<<endl<<"2.ArcCosine "<<endl<<"3.ArcTangent "<<endl<<"4.ArcCotangent "<<endl<<"5.ArcSecant "<<endl<<"6.ArcCosecant"<<endl;
        cin >> switchvalue;

        if(switchvalue>0&&switchvalue<=6){

        switch(switchvalue){
            case 1:
                {
                    ArcSin();
                    break;
                }
                case 2:
                {
                    ArcCos();
                    break;
                }
                case 3:
                {
                    ArcTan();
                    break;
                }
                case 4:
                {
                    ArcCot();
                    break;
                }
                case 5:
                {
                    ArcSec();
                    break;
                }
                case 6:
                {
                    ArcCosec();
                    break;
                }
                default:
                {
                    cout<<"This will never get printed!!!"<<endl;
                    break;
                }
        }
        }
        else{
            cout<<endl<<"Enter a valid number between 1 and 6"<<endl;
        }

        inversetrigcheck:
        cout << "Enter (Y/N) for Inverse Trigonometric Operations" << endl << "Y for continue " << endl << "N for Exiting " << endl;
        cin >> yesorno;

        if (yesorno == 'y' || yesorno == 'Y') {
            {
                cont = true;
            }
        } else if (yesorno == 'n' || yesorno == 'N') {
            {
                cont = false;
                cout << "Inverse Trigonometric Operation Completed Successfully" << endl;
            }

        } else {

            cout << "Wrong Output. " << endl;
            goto inversetrigcheck;
        }
    }

}

void ArcSin()
{
    double value;
    cout<<endl<<"Enter the sin value"<<endl;
    cin>>value;
    double a=asin(value);
    cout<<endl<<"Arc Sine Value(In Radian): "<<a<<endl;
}
void ArcCos()
{
    double value;
    cout<<endl<<"Enter the Cos value"<<endl;
    cin>>value;
    double a=acos(value);
    cout<<endl<<"Arc Cos Value(In Radian): "<<a<<endl;
}
void ArcTan()
{
    double value;
    cout<<endl<<"Enter the Tan value"<<endl;
    cin>>value;
    double a=atan(value);
    cout<<endl<<"Arc Tan Value(In Radian): "<<a<<endl;
}
void ArcCot()
{
    double value;
    cout<<endl<<"Enter the Cot value"<<endl;
    cin>>value;
    double a=atan(1/value);
    cout<<endl<<"Arc Cot Value(In Radian): "<<a<<endl;
}
void ArcSec()
{
    double value;
    cout<<endl<<"Enter the sec value"<<endl;
    cin>>value;
    double a=acos(1/value);
    cout<<endl<<"Arc Sec Value(In Radian): "<<a<<endl;
}
void ArcCosec()
{
    double value;
    cout<<endl<<"Enter the Cosec value"<<endl;
    cin>>value;
    double a=asin(1/value);
    cout<<endl<<"Arc Cosec Value(In Radian): "<<a<<endl;
}


//Logarithmic Operations
void logarithmic()
{
    cout<<"Enter the number whose log (base-10)value is to be found"<<endl;
    int n;
    cin>>n;
    long long ans=log10(n);
    cout<<"Answer is "<<ans<<endl;
}




//Exponential operation
void exponential()
{
    cout<<"Enter the number whose exponential is to be found"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the power to find"<<endl;
    int power;
    cin>>power;
    long long ans=pow(n,power);
    cout<<"The value of "<<n<<"^"<<power<<" is "<<ans<<endl;
}




//relational operations
void relational()
{
    cout<<"How many numbers you want to check"<<endl;
    int n;
    cin>>n;
    vector<int> ans;
    cout<<"Enter your numbers"<<endl;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        ans.push_back(t);
    }
    sort(ans.begin(), ans.end());
    cout<<"Array in sorted manner"<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl<<"Largest Number in the array"<<ans[ans.size()-1]<<endl;
    cout<<"Smallest Number in the array"<<ans[0]<<endl;
}