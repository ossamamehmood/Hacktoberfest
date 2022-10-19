
#include<stdio.h>
#include<graphics.h>
#include<math.h>
void main()
{
    int gd=DETECT,gm;
    int x1,y1,x2,y2,x3,y3;
    int a1,b1,a2,b2,a3,b3;
    int p1,q1,p2,q2,p3,q3;
    int r1,s1,r2,s2,r3,s3;
    float s,si,c;
    float an;
    int choice;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    line(getmaxx()/2,0,getmaxx()/2,getmaxy());
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);

    printf("Enter the coordinates of 1st point:\n");
    scanf("%d%d",&x1,&y1);
    printf("Enter the coordinates of 2nd point:\n");
    scanf("%d%d",&x2,&y2);
    printf("Enter the coordinates of 3rd point:\n");
    scanf("%d%d",&x3,&y3);
    line(x1,y1,x2,y2);
     line(x2,y2,x3,y3);
      line(x3,y3,x1,y1);

    a1=x1-x1;
    b1=y1-y1;
    a2=x2-x1;
    b2=y2-y1;
    a3=x3-x1;
    b3=y3-y1;
    line(a1,b1,a2,b2);
     line(a2,b2,a3,b3);
    line(a3,b3,a1,b1);

   do {
    printf("Enter choice:\n 1.scaling\n 2. Rotation\n3.Exit");
    scanf("%d",&choice);
    if(choice==1)
    {
    printf("Enter the scaling factor:\n");
    scanf("%f",&s);
    p1=a1*s;
    q1=b1*s;
    p2=a2*s;
    q2=b2*s;
    p3=a3*s;
    q3=b3*s;
   line(p1,q1,p2,q2);
    line(p2,q2,p3,q3);
    line(p3,q3,p1,q1);
     r1=x1+p1;
     s1=y1+q1;
     r2=x1+p2;
     s2=y1+q2;
     r3=x1+p3;
     s3=y1+q3;
     setcolor(CYAN);
     line(r1,s1,r2,s2);
    line(r2,s2,r3,s3);
    line(r3,s3,r1,s1);
    }
    if(choice==2)
    {
       printf("Enter angle:\n") ;
       scanf("%f",&an);
       setcolor(YELLOW);
       si=sin(an*3.14/180);
       c=cos(an*3.14/180);
       p1=a1*c-b1*si;
       q1=a1*si+b1*c;
       p2=a2*c-b2*si;
       q2=a2*si+b2*c;
       p3=a3*c-b3*si;
       q3=a3*si+b3*c;
       line(p1,q1,p2,q2);
       line(p2,q2,p3,q3);
       line(p3,q3,p1,q1);
    r1=x1+p1;
     s1=y1+q1;
     r2=x1+p2;
     s2=y1+q2;
     r3=x1+p3;
     s3=y1+q3;
       line(r1,s1,r2,s2);
    line(r2,s2,r3,s3);
    line(r3,s3,r1,s1);
    }}while(choice!=3);
    getch();
    closegraph();
}