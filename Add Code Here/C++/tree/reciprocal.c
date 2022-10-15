#include<stdio.h>
//roots of a polynomial function
# define sign(a) (((a<0?-1:1)))
float  reciprocal(float x);
int main(void){
    float x;
    printf("enter the value to find reciprocal for: ");
    scanf("%f",&x);
    printf("the reciprocal of the given value is:%f",reciprocal(x));
    return 0;


}
float reciprocal(float x){
    float x1=2,x0;
    float e=0.00001;
    int temp=0;   // a temporary variable to put correct decimal places
    x *=sign(x);

    if (x==0) return 0;

    if(x>1){
        while(x>1){
            temp++;
            x/=10;
        }
    }else if (x<1){
        while(x<1){
        temp--;
        x*=10;
        }
    }

    do{
        x0=x1;
        x1= x0*(2-x0*x);     //formula derived by taylor series

    }while ((sign((x1-x0)/x0))*((x1-x0)/x0)>e);  //relative error check
    if (temp>0)
        for (int i=temp; i>0;i--) x1/=10;    /*if else condition
                                               for adjusting decimal
                                                places*/
    else if (temp<0)
        for (int i=temp;i<0;i++) x1*=10;
    return x1;

    return 0;
}

