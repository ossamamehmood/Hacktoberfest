#include<iostream.h>
#include<conio.h> 
class NUM
{
    private:
        int n;
         
    public:
       void getNum(int x)
        {
            n=x;
        }
       void dispNum(void)
        {
            cout << "value of n is: " << n;
        }
    void operator ++ (void)
        {
            n=++n;
        }
  void operator -- (void)
        {
            n=--n;
        }
};
void main()
{
    NUM num;
    Clrscr;
    num.getNum(10);
     ++num;
    cout << "After increment - ";
    num.dispNum();
    cout << endl;
       --num;
    cout << "After decrement - ";
    num.dispNum();
    cout << endl;
    getch();
}
