#include<stdio.h>
//function to calculate BMI index
float BMI(float weight, float height) {
   return weight/height*2;
}
int main() {
   float weight=50.00;
   float height=4.9;
   float bmi = BMI(weight,height);
   printf("BMI index is : %.2f ",bmi);
   return 0;
}

//insert values are as below:
//weight 50
//height 4.9
//note; weight is on KG and height is on Foot
//output will be BMI index is : 20.41 
