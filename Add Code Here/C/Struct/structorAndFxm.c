#include <stdio.h>
#include <stdlib.h>


struct student {
   char name[21];
   int age;
   int roll_no;
};

void display(char name[],int age, int rollno){
    printf("%s %d %d",name,age,rollno);
}

int main(){
    struct student s1 = {"name",6,1};

    display(s1.name,s1.age,s1.roll_no);

return 0;

}