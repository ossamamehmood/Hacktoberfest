#include<stdio.h>
int main(){
int a[100][100],i,j,l,n=5,k=0,m=5,top,rig,bot,lef; //can assign custom values to n,k,m,size of array
for(i=0;i<n;i++)
{
    for(j=0;j<m;j++)
    a[i][j]=k++;
}
top=0;
rig=m-1;
bot=n-1;
lef=0;
while(n!=0)
{
    for(j=top;j<m;j++)
    {
        printf("%d ",a[top][j]);
    }
    top++;
    m--;
    for(j=top;j<n;j++)
    {
        printf("%d ",a[j][rig]);
    }
    rig--;
    n--;
    for(j=rig;j>=lef;j--)
    {
        printf("%d ",a[bot][j]);
    }
    bot--;
    for(j=bot;j>=top;j--)
    {
        printf("%d ",a[j][lef]);
    }
    lef++;


}


}
