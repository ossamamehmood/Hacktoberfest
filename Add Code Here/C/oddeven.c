#include<stdio.h>
int oddeven(int num){
        if(num%2==1)
                return 1;
        else
                return 0;
}
int main(){
        int a,res;
        char choice;
    do {
        printf("Enter any number to check odd or even: ");
        if (scanf("%d", &a) != 1) {
            printf("Invalid input. Please enter a valid integer.\n");
            // Clear the input buffer to prevent an infinite loop
            while (getchar() != '\n');
            continue;
        }

        res = oddeven(a);

        if (res == 1)
            printf("The number is odd\n");
        else
            printf("The number is even\n");

        printf("Do you want to check another number? (y/n): ");
        while (getchar() != '\n'); // Clear the input buffer
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Exiting the program.\n");

    return 0;
}
