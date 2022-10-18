#include <stdio.h>
#include <stdlib.h>
// CODE OF MYSTERY #1
//  my first code that i dont know why & how its working
// struct asdf
// {
//     int number;
// };

// struct asdf * increment(struct asdf arr1[])
// {

//     arr1[0].number++;
//     arr1[1].number++;
//     arr1[2].number++;

//     return arr1;
// }

// int main()
// {
//     struct asdf arr[] = {
//         {1},
//         {2},
//         {3},
//     };
//     // arr before inc
//     printf("%d %d %d\n", arr[0].number, arr[1].number, arr[2].number);

//     struct asdf *ptr;
//     ptr = increment(arr);
//     // arr after inc
//     printf("%d %d %d\n", arr[0].number, arr[1].number, arr[2].number);
//     // ptr after inc
//     printf("%d %d %d\n", ptr->number, ptr[1].number, ptr[2].number);

//     return 0;
// }

// ... self refrential pointer
struct CodeOfMystery
{
    int number;
    struct CodeOfMystery *link;
};

int main()
{
    struct CodeOfMystery mystery1 = {1, NULL};

    printf("%d %s",mystery1.number,mystery1.link);
  

    // struct CodeOfMystery *head = (struct CodeOfMystery *)malloc(sizeof(struct CodeOfMystery));

    struct CodeOfMystery mystery2 = {2, NULL};

    mystery1.link = &mystery2;
    printf("\n%d %s",mystery1.number,mystery1.link);



    return 0;
}