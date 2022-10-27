#include<iostream>
using namespace std;
#include <stdlib.h>
#include<time.h>
class Allsort
{
int ar[5000],len;
public:
Allsort();
Allsort(int x);
void input();
void bsort();
void isort();
void ssort();
void display();
};

Allsort::Allsort()
{
len=5;
}
Allsort::Allsort(int x)
{
len=x;
}

void Allsort::input()
{
time_t t1;
srand(time(0));
for(int i=0;i<len;i++)
{
ar[i]=rand()%(2*len);
}
}

void Allsort::display()
{
cout<<"The elements are:"<<endl;
for(int i=0;i<len;i++)
{
cout<<ar[i]<<" ";
}
cout<<endl;
}

void Allsort::isort()
{
int temp,i,j,comp1=0;
for(i=1;i<len;i++)
{
temp=ar[i];
for(j=i-1;j>=0;j--)
{
comp1++;
if(temp<ar[j])
{
ar[j+1]=ar[j];
}
else
break;
}
ar[j+1]=temp;
}
cout<<"Total no. of comparision for Insertion sort: "<<comp1<<endl;
}

void Allsort::bsort()
{
int temp,comp2=0;
for(int i=0; i<len; i++)
{
for(int j=0; j<len-i-1; j++)
{
comp2++;
if(ar[j]>ar[j+1])
{
temp=ar[j];
ar[j]=ar[j+1];
ar[j+1]=temp;
}
}
}
cout<<"Total no. of comparision for Bubble sort: "<<comp2<<endl;
}

void Allsort::ssort()
{
int i,j,min,minindex,comp3=0;
for(i=0;i<len;i++)
{
min=ar[i];
minindex=i;
for(j=i+1; j<len;j++)
{
comp3++;
if(min>ar[j])
{
min=ar[j];
minindex=j;
}
}
if(i!=minindex)
{
int temp=ar[i];
ar[i]=min;
ar[minindex]=temp;
}
}
cout<<"Total no. of comparision for selection sort: "<<comp3<<endl;
}

int main()
{
int n;
cout<<"Enter total no . of elements";
cin>>n;
Allsort ob(n);
ob.input();
ob.display();
ob.isort();
ob.bsort();
ob.ssort();
ob.display();
return 0;
}