// A magic trick from cards
#include <stdio.h>

void main()
{
    int number[25][25],numbers[25][25],i=0,j=0,num1,num2,num3,x=0;
    for(i=0;i<7;i++)
    {
        for(j=0;j<3;j++)
        {
            number[i][j] = (j+1)+(i*3);
        }
    }

    printf("column_1\tcolumn_2\tcolumn_3");
    printf("\n\n");

     for(i=0;i<7;i++)
    {
        for(j=0;j<3;j++)
        {
           printf("  %d\t\t",number[i][j]);
        }

        printf("\n\n");
    }

    printf("\n\nChoose a number from one of the 3 coloumn and enter the column number : ");
    scanf("%d",&num1);


     numbers[0][0]=1,numbers[1][0]=10;numbers[2][0]=19,numbers[3][0]=8;numbers[4][0]=17;numbers[5][0]=6;numbers[6][0]=15;
     numbers[0][1]=4,numbers[1][1]=13;numbers[2][1]=2,numbers[3][1]=11;numbers[4][1]=20;numbers[5][1]=9;numbers[6][1]=18;
     numbers[0][2]=7,numbers[1][2]=16;numbers[2][2]=5,numbers[3][2]=14;numbers[4][2]=3;numbers[5][2]=12;numbers[6][2]=21;


    printf("\n\ncolumn_1\tcolumn_2\tcolumn_3");
    printf("\n\n");



     for(i=0;i<7;i++)
    {
        for(j=0;j<3;j++)
        {
           printf("  %d\t\t",numbers[i][j]);
        }

        printf("\n\n");

    }

    printf("\n\nChoose a number from one of the 3 coloumn and enter the column number : ");
    scanf("%d",&num2);


     numbers[0][0]=1,numbers[1][0]=8;numbers[2][0]=15,numbers[3][0]=2;numbers[4][0]=9;numbers[5][0]=16;numbers[6][0]=3;
     numbers[0][1]=10,numbers[1][1]=17;numbers[2][1]=4,numbers[3][1]=11;numbers[4][1]=18;numbers[5][1]=5;numbers[6][1]=12;
     numbers[0][2]=19,numbers[1][2]=6;numbers[2][2]=13,numbers[3][2]=20;numbers[4][2]=7;numbers[5][2]=14;numbers[6][2]=21;


      printf("\n\ncolumn_1\tcolumn_2\tcolumn_3");
    printf("\n\n");



     for(i=0;i<7;i++)
    {
        for(j=0;j<3;j++)
        {
           printf("  %d\t\t",numbers[i][j]);
        }

        printf("\n\n");
    }

         printf("\n\nChoose a number from one of the 3 coloumn and enter the column number : ");
    scanf("%d",&num3);

    if(num1 == 1)
        {
            if(num2 == 1)
            {
                if(num3 == 1)
                {
                    x = 1;
                }


                else if(num3 == 2)
                {
                    x = 10;
                }


                else
                {
                    x = 19;
                }
            }

            else if(num2 == 2)
            {
                if(num3 == 2)
                {
                    x = 4;
                }


                else
                {
                    x = 13;
                }

            }

            else
            {
                if(num3 == 1)
                {
                    x = 16;
                }


                else
                {
                    x = 7;
                }

            }

        }
         else if(num1 == 2)
        {
            if(num2 == 2)
            {
                if(num3 == 1)
                {
                    x = 2;
                }


                else if(num3 == 2)
                {
                    x = 11;
                }


                else
                {
                    x = 20;
                }
            }

            else if(num2 == 1)
            {
                if(num3 == 1)
                {
                    x = 8;
                }


                else
                {
                    x = 17;
                }



            }

            else
            {
                if(num3 == 2)
                {
                    x = 5;
                }


                else
                {
                    x = 14;
                }

            }

        }


         else
        {
            if(num2 == 3)
            {
                if(num3 == 1)
                {
                    x = 3;
                }


                else if(num3 == 2)
                {
                    x = 12;
                }


                else
                {
                    x = 21;
                }
            }

            else if(num2 == 1)
            {
                if(num3 == 1)
                {
                    x = 15;
                }


                else
                {
                    x = 6;
                }

            }

            else
            {
                if(num3 == 1)
                {
                    x = 9;
                }

                else
                {
                    x = 18;
                }
            }
        }


        printf("\n\n The number you chose was %d",x);







}
