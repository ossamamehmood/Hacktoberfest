#include <stdio.h>
#include <stdlib.h>



struct student {
   char name[22];
   int age;
   int roll_no;
};

void display(struct student *cv1){

    printf("%d %d \n",cv1->age,cv1->roll_no);

  
}


struct student* AgePlus1( struct student s ){
   
   struct student *ss =(struct student*) malloc(sizeof(struct student));
    ss->age = s.age;
    ss->age++;
    ss->roll_no = s.roll_no;

    return ss;
}

int main(){
    struct student s1 = {"JaguBandar",6,1};

    struct student *s2 = AgePlus1(s1);

    display(&s2);
   

return 0;

}