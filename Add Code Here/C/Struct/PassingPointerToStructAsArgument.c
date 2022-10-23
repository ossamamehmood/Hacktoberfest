#include <stdio.h>
#include <stdlib.h>
struct student {
   char name[20];
   int age;
   int roll_no;
};


void display(struct student cv1 ,struct student cv2){

    printf("%s %d %d \n",cv1.name,cv1.age,cv1.roll_no);

    printf("%s %d %d",cv2.name,cv2.age,cv2.roll_no);
}

void changeName(struct student *s){
    

    s->age = 4;

}

int main(){
    struct student s1 = {"Bandar",6,1};
    struct student s2 = {"Akdu Bhudda",96,2};



    changeName(&s2);
    display(s1,s2);
return 0;
}