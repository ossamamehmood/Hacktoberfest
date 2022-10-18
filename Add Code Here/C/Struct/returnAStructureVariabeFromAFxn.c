#include <stdio.h>
#include <stdlib.h>


struct student {
   char name[22];
   int age;
   int roll_no;
};

void display(struct student cv1){

    printf("%s %d %d \n",cv1.name,cv1.age,cv1.roll_no);

  
}


struct student AgePlus1( struct student s){
    s.age++;

    return s;
}

int main(){
    struct student s1 = {"JaguBandar",6,1};
    struct student s2 = AgePlus1(s1);

display(s2);

return 0;

}