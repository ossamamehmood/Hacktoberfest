#include <stdio.h>
#include <conio.h>

int main()
{
 int a[12],time=1100;
   int u1,u2,u3,u4,u5,u6,u7,u8,u9,u10,u11,u12,i;
   printf("Enter Time of Each User : ");
   for(i=0;i<12;i++)
   {
     printf("\na[%d] : ",i+1);
     scanf("%d",&a[i]);
   }
   	 u1=a[0]/10;
	 u2=a[1]/10;
	 u3=a[2]/10;
	 u4=a[3]/10;
	 u5=a[4]/10;
	 u6=a[5]/10;
	 u7=a[6]/10;
	 u8=a[7]/10;
	 u9=a[8]/10;
	 u10=a[9]/10;
	 u11=a[10]/10;
	 u12=a[11]/10;
 
 while(time!=0)
 {
     if(u1>0)
     {
      printf("\nUser[1] Using Channel.");
      time=time-10;
      u1=u1-1;
     }
     if(u2>0)
     {
      printf("\nUser[2] Using Channel.");
      time=time-10;
      u2=u2-1;
     }
     if(u3>0)
     {
      printf("\nUser[3] Using Channel.");
      time=time-10;
      u3=u3-1;
     }
     if(u4>0)
     {
      printf("\nUser[4] Using Channel.");
      time=time-10;
      u4=u4-1;
     }
     if(u5>0)
     {
      printf("\nUser[5] Using Channel.");
      time=time-10;
      u5=u5-1;
     }
     if(u6>0)
     {
      printf("\nUser[6] Using Channel.");
      time=time-10;
      u6=u6-1;
     }
     if(u7>0)
     {
      printf("\nUser[7] Using Channel.");
      time=time-10;
      u7=u7-1;
     }
     if(u8>0)
     {
      printf("\nUser[8] Using Channel.");
      time=time-10;
      u8=u8-1;
     }
     if(u9>0)
     {
      printf("\nUser[9] Using Channel.");
      time=time-10;
      u9=u9-1;
     }
     if(u10>0)
     {
      printf("\nUser[10] Using Channel.");
      time=time-10;
      u10=u10-1;
     }
     if(u11>0)
     {
      printf("\nUser[11] Using Channel.");
      time=time-10;
      u11=u11-1;
     }
     if(u12>0)
     {
      printf("\nUser[12] Using Channel.");
      time=time-10;
      u12=u12-1;
     }
   }
 return 0;
}
