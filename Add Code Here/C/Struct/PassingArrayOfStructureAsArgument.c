#include <stdio.h>
#include <stdlib.h>
struct student{
    int Age;
    int RollNo;
};

void display(struct student arr[]){
    for (int i = 0; i < 2; i++)
    {
            printf("Age is %d Roll No is  %d \n",arr[i].Age , arr[i].RollNo);

    }
    
}
int main (){

struct student arr[2] = {{1,1},{2,2}};

    display(arr);

}