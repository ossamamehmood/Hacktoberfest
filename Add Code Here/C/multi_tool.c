#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()

{
  // enter user input of array
     char go;
    /*============================Main Menu==================================*/
    while (1)
{
     
    int manu_no;
   {

      printf("\n ====================MENU==================\n");
      printf("|                                           |\n");
      printf("| 1. Calculator                             |\n");
      printf("| 2. 1D Array Calculator                    |\n");
      printf("| 3. Birth day Calculator                   |\n");
      printf("| 4. Number system conversion               |\n");
      printf("| 5. Students Mark(max,min,avg,pass/fail)   |\n");
      printf("| 6. Digital clock                          |\n");
      printf("| 7. STOP Watch                             |\n");
      printf("| 8. Factorial                              |\n");
      printf("| 9. Find the number of digits in a value   |\n");
      printf("| 10.Arrat equal or not equal               |\n");
      printf("| 11.Finding the Square or Power of a value |\n");
      printf("| 12.Matrix Calculator                      |\n");
      /*-------------Add New Tool-------------------------------
                    printf(" ");
      --------------------------------------------------------*/
      printf("| 13.Info                                   |\n");
      printf("| 14.EXIT                                   |\n");
      printf("|                                           |\n");
      printf(" ===========================================\n"); 
      printf("\nWhat do you want?: ");
      scanf("%d",&manu_no);
   }
      
 switch (manu_no)
  {
   /*================>>>1. Number sum,Number subtract,number multiplication,Number Divide<<<=================*/

        case 1:
          { 
           printf("\n--------------------------------------Calculator--------------------------------------\n\n");

            float no1,no2;           
            char go,ch;

            while (1)
            {
              printf("-------------------\n");
              printf("  1. Sum\n  2. Subtract\n  3. Multiplication\n  4. Divide\n  5. All\n");
              printf("\nEnter your choice: ");
             scanf("%s",&ch);
  
                          printf("\nEnter first number: ");
                          scanf("%f",&no1);
                          printf("Enter first number: ");
                          scanf("%f",&no2);
                          printf("\n");

               switch (ch)
               {
                case '5':{
                  case '1':
                     printf("Sum: %.2f\n",no1+no2);
                      if(ch!='5')
                        break;
                  case '2':
                     printf("subtract: %.2f\n",no1-no2);
                      if(ch!='5')
                        break;
                  case '3':
                    printf("multiplication: %.2f\n",no1*no2);
                      if(ch!='5')
                        break;
                  case '4':
                    printf("Divide: %.2f\n",no1/no2);
                      if(ch!='5')
                        break;
                        }
            
           
               }
                printf("\nBack to Tool?(Y/N): ");
                scanf("%s",&go);
                if(go=='y')
               { 
                printf("-------------------\n");
                break;
                }
                printf("\n");           
                 
            
            }
          }break;
           
    /*==========================>>>2. array sum, subtract, multiplication, division<<==========================*/  
      
        case 2: 
          {
        
             printf("\n-------------------------------------1D Array calculator-------------------------------------\n\n");
             while (1)
                       {
                    int size;
                    printf("-------------------\n");
                    printf("Enter array size: ");
                    scanf("%d",&size);
                  
                      float arr1[size],arr2[size],arrsum[size];
                      float arrsub[size],arrmul[size];
                      float arrdiv[size];
                      int i,choice;
                      char go;

                    /*-----------------enter first array----------------*/
                              printf("\nEnter first array:\n");
                                   for(i=0;i<size;i++){
                                     printf("element %d: ",i+1);
                                  scanf("%f",&arr1[i]);
                               }
                    /*---------------enter second array-----------------*/    
                      printf("\nEnter second array:\n");
                      for(i=0;i<size;i++){
                        printf("element %d: ",i+1);
                           scanf("%f",&arr2[i]);
                       }
                       
                        
                            printf("\n  1. Sum\n  2. Subtract\n  3. Multiplication\n  4. Division\n  5. All\n");
                              printf("\nEnter your choice: ");
                              scanf("%d",&choice);

                      switch (choice)
                      {
                  /*-------------------------sum-------------------------*/
                        case 5:{
                      case 1: 
                        printf("\nErray sum: ");
                         {
                          for (i = 0; i < size; i++)
                          {
                               arrsum[i]=arr1[i]+arr2[i];  
                               printf("%.0f ",arrsum[i]);
                              }
                          } 
                        if(choice!=5)
                      break;
                  /*---------------------subtract-----------------------*/
                                case 2:
                                  printf("\nErray subtract: ");
                                  {
                                   for (i = 0; i < size; i++)
                                      {
                                           arrsub[i]=arr1[i]-arr2[i];  
                                           printf("%.0f ",arrsub[i]);
                                      }
                                  }
                                  if(choice!=5)
                                break;
                  /*---------------------multiplication-------------------*/
                        case 3:
                        printf("\nErray Multiplication: ");
                        {
                         for (i = 0; i < size; i++)
                            {
                             arrmul[i]=arr1[i]*arr2[i];  
                              printf("%.0f ",arrmul[i]);
                           }
                        }
                      if(choice!=5) 
                        break;
                  /*------------------------divishion---------------------*/
                                case 4:
                                printf("\nErray Division: ");
                                {
                                
                                   for (i = 0; i < size; i++)
                                  {
                                    arrdiv[i]=arr1[i]/arr2[i];  
                                    printf("%.2f ",arrdiv[i]);
                                  }
                                }
                              if(choice!=5)
                                break;
                           } 
                         
                } 
                printf("\n\nBack to Tool?(Y/N): ");
                scanf("%s",&go);
                if(go=='y')
                {
                printf("-------------------\n");
                break;
                }
                 printf("\n");
                       } 

          }break;

    /*=======================================>>>3. Birth day calculator<<======================================*/ 

        case 3:
          {
               int nday,nmonth,nyear;
               int bday,bmonth,byear;
               int days,monts,years;
               int i;
               char go;
                printf("\n--------------------------------------Birth day calculator--------------------------------------\n\n");
                while (1)
                
               {  
                  printf("------------------------------------------\n");
                  printf("Enter date of today(like this YYYY MM DD): ");
                  scanf("%d %d %d",&nyear,&nmonth,&nday);
                  printf("Enter your birth day(like this YYYY MM DD): ");
                  scanf("%d %d %d",&byear,&bmonth,&bday);
                   printf("\n");
             if(bmonth<nmonth)
               {
                     if(bday<nday){
                        monts=nmonth-bmonth;
                          days=nday-bday;
                            years=nyear-byear;    
                             printf("Your Age is %d years %d months %d days",years,monts,days);
                               }
                  
                             if(bday>nday){
                            for(i=0;i<1;i++){
                          nday+=30;
                        nmonth--;
                      monts=nmonth-bmonth;
                    days=nday-bday;
                 years=nyear-byear;
                }                  
             printf("Your Age is %d years %d months %d days",years,monts,days);
                }
              }
            if(bmonth>nmonth)
              {
                     if(bday<nday)
                       for(i=0;i<1;i++){
                         nmonth+=12;
                           nyear--;
                             monts=nmonth-bmonth;
                              days=nday-bday;
                            years=nyear-byear;
                         printf("Your Age is %d years %d months %d days",years,monts,days);
                       }

                 if(bday>nday)
                 for(i=0;i<1;i++){
                   nday+=30;
                     nmonth+=11;
                        nyear--;
                        monts=nmonth-bmonth;
                     days=nday-bday;
                   years=nyear-byear;
                printf("Your Age is %d years %d months %d days",years,monts,days);
                 }

              }
               printf("\n\nBack to Tool?(Y/N): ");
                scanf("%s",&go);
                if(go=='y')
                {
                  printf("------------------------------------------\n");
                break;
                }
          } 
          }break;
    
    /*===================================>>>4. Number system conversion<<<=====================================*/

        case 4:
          {   

            printf("\n--------------------------------------Number system conversion--------------------------------------\n\n");
            char go;
              while (1)
              {
                 
                     int conversion;
                     int dec;
                       printf("\n-------------------------"); 
                       printf("\n  1. Decimal To Octal");
                       printf("\n  2. Octal To Decimal");
                       printf("\n  3. Decimal To Hexadecimal");
                       printf("\n  4. Hexadecimal To Decimal");
                       printf("\n  5. Exit");
                          printf("\n\nWhat do you want? ");
                          scanf("%d",&conversion);
                            
                     switch(conversion)
                          {
                          case 1:
                               printf("\nEnter Decimal number: ");
                               scanf("%d",&dec);
                               printf("\nThe Octal value: %o\n",dec);
                            break;                                                 
                          case 2:
                               printf("\nEnter Octal number: ");
                               scanf("%o",&dec);
                               printf("\nThe Decimal value: %d\n",dec);
                            break;
                          case 3:
                               printf("\nEnter Decimal number: ");
                               scanf("%d",&dec);
                               printf("\nThe Hexadicimal value: %x\n",dec);
                            break;  
                          case 4:  
                               printf("\nEnter Hexadicimal number: ");
                               scanf("%x",&dec);
                               printf("\nThe Decimal value: %d\n",dec);
                            break;
                          case 5:
                              exit(0);
                            break;
                          }

                 printf("\n\nBack to Tool?(Y/N): ");
                scanf("%s",&go);
                if(go=='y')
                {
                   printf("-------------------------\n"); 
                break;  
                }      

              }       


          }break;

    /*=============================>>>5. Students Mark(max,min,avg,pass/fail)<<<===============================*/ 
  
        case 5:
          {
                            float sum,avg;
                            int i,no_of_students;
                            int min,max;
                            int a,b,c,s,f;
                             char go;
                  printf("\n--------------------------------------Students Mark--------------------------------------\n");
                  while(1)
                  {
                        printf("\n--------------------------");  
                           min=0,max=0,sum=0;

                                printf("\nEnter Number of students: ");
                                scanf("%d",&no_of_students);
                                float mark[no_of_students];
                            { 
                                 printf("\n");
                               for(i=0 ; i < no_of_students ; i++){
                                printf("Student %d mark: ",i+1);
                                    scanf("%f",&mark[i]);
                                      sum=sum+mark[i];                                 
                                          }
                                           for(i=0 ; i < no_of_students ; i++){                                                           
                                             if(mark[i]>max)                    
                                            max=mark[i];
                                          }
                                       min=mark[0];
                                    for(i=0 ; i < no_of_students ; i++){                                                            
                                 if(mark[i]<min)                    
                                    min=mark[i];
                                }
                             avg=sum/no_of_students;
                            printf("\nMinimum mark: %d\n",min);
                            printf("Maximum mark: %d\n",max);
                            printf("The Average mark: %.2f\n",avg);
                            }

                                    a=0;
                                   b=0;
                                  c=0;
                                 s=0;
                                f=0;
                              printf("\n");
                                for(i=0 ; i < no_of_students ; i++){
                                   if(mark[i]>=75)
                                       a++;
                                       else if(mark[i]>=65)
                                         b++;
                                          else if(mark[i]>=55)
                                        c++;
                                       else if(mark[i]>35)
                                     s++;
                                   else
                                       f++;                                 
                                }
                                printf("Number of students with a grade of A: %d\n",a);
                                printf("Number of students with a grade of B: %d\n",b);
                                printf("Number of students with a grade of C: %d\n",c);
                                printf("Number of students with a grade of S: %d\n",s);
                                printf("Number of students with a grade of F: %d\n",f);


                     printf("\nBack to Tool?(Y/N): ");
                      scanf("%s",&go);
                      if(go=='y')
                      {
                         printf("--------------------------\n"); 
                       break;
                      }
               
                  }

          }break;

    /*==========================================>>>6. Digital clock<<<=========================================*/
          
        case 6:
          {

                   int s,m,h;
                     printf("\n--------------------------------------Digital clock--------------------------------------\n");
                     printf("\n------------");
                     printf("\nSet Time\n");
                       printf("H: ");
                       scanf("%d",&h);
                       printf("M: ");
                       scanf("%d",&m);
                       printf("S: ");
                       scanf("%d",&s);

                     while (1)
                       {
                         s++;
                          if(s>59){
                            m++;
                             s=0;
                                }
                                if(m>59){
                                  h++;
                                    m=0;
                                   }
                                if(h>=12){
                              h=0;
                            }
                          printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t........................");
                        printf("\n\t\t\t\t\t\t.");
                      printf("\t%.2d:%.2d:%.2d       .",h,m,s);
                     printf("\n\t\t\t\t\t\t........................");

                        system("cls");
                       }

          }break;

    /*===========================================>>7. >Stop Watch<<<===========================================*/

        case 7:
          {
                printf("\n--------------------------------------Stop Watch--------------------------------------\n");
                printf("\n------------");
                  int s,m,h;
                      printf("\n");
                       printf("H: ");
                       scanf("%d",&h);
                       printf("M: ");
                       scanf("%d",&m);
                       printf("S: ");
                       scanf("%d",&s);

                     while (1)
                       {
                         s--;
                          if(s==0){
                            m--;
                             s=59;
                              }
                                if(m<0){
                                  h--;
                                  m=59;
                                 }
                               if(h<0){
                             h=0;
                           exit(0);
                          }
                         printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t........................");
                      printf("\n\t\t\t\t\t\t.");
                    printf("\t%.2d:%.2d:%.2d       .",h,m,s);
                  printf("\n\t\t\t\t\t\t........................");

                        system("cls");
                       }


          }break;

    /*==========================================>>>8. Factorial<<<=============================================*/

        case 8:
          {
            float i,number,factorial;
              printf("\n--------------------------------------Factorial--------------------------------------\n");
               while (1)
               {
                 printf("\n----------------");
                factorial=1;
              printf("\nEnter number: ");
                  scanf("%f",&number);
 
                    for(i=1;i<=number;i++){
                
                factorial=factorial*i;
              }

                printf("\nNumber of Factorial: %.0f",factorial);

                printf("\n\nBack to Tool?(Y/N): ");
                scanf("%s",&go);
                if(go=='y')
                {
                  printf("----------------\n");
                break;
                }
               }       
          }break;

    /*=============================>>>9. Find the number of digits in a value<<<===============================*/
       
       case 9:
          {
                      int num,count;
                       printf("\n--------------------------Find the number of digits in a value--------------------------\n");
                       while (1)
                       {
                         printf("\n----------------");
                       count=0;
                       printf("\nEnter number: ");
                       scanf("%d",&num);

                          while (num!=0)
                          {
                          num=num/10;
                        count++;
                      }
                      printf("Count of Numbers: %d",count);

                         printf("\n\nBack to Tool?(Y/N): ");
                         scanf("%s",&go);
                         if(go=='y')
                         {
                           printf("----------------\n");
                          break;
                         }

                       }
          }break;

    /*===================================>>>10.Arrat equal or not equal<<<=====================================*/

       case 10:
          {
            printf("\n----------------------------Arrat equal or not equal----------------------------\n");
            char go;
        while (1)
        {
          
         printf("\n------------------");
             int row_size,col_size;
                printf("\nNumber of Rows: ");
                scanf("%d",&row_size);
                printf("Number of collom: ");
                scanf("%d",&col_size);

              int arr1[row_size][col_size];
              int arr2[row_size][col_size];
              int i,j,a,b;
               
                 printf("\nArray one\n");
                 a=0;
              for(i=0;i<row_size;i++){
                 for ( j = 0; j < col_size; j++)
                   {
                   printf("element %d: ",++a);
                     scanf("%d",&arr1[i][j]);
                       }
                        }
                         printf("\nArray two\n");
                           b=0;
              for(i=0;i<row_size;i++){
                  for ( j = 0; j < col_size; j++)
                   {               
                 printf("element %d: ",++b);
                    scanf("%d",&arr2[i][j]);
                    }
                      }
                //matrix - array one
                        printf("\nMatrix array one\n");
                for(i=0;i<row_size;i++){
                  for ( j = 0; j < col_size; j++)
                      {
                        printf("%d ",arr1[i][j]);
                         }
                          printf("\n");
                           }
                 
                //matrix - array two
                printf("\nMatrix array two\n");
                for(i=0;i<row_size;i++){
                  for ( j = 0; j < col_size; j++)
                     {
                      printf("%d ",arr2[i][j]);
                      }
                  printf("\n");
                }

                 printf("\nStatus\n");
               for(i=0;i<row_size;i++){
                  for(j=0;j<col_size;j++){
                      if(arr1[i][j]==arr2[i][j]){
                         printf("[ Equal ] ");
                      } 
                      else
                      printf("[Unequal] ");                    
                  }    
                  printf("\n");                  
               }
                  printf("\n");
                //equal or not equal
                int isequal=1;
               printf("\nStatus\n");
               for(i=0;i<row_size;i++){
                  for(j=0;j<col_size;j++){
                      if(arr1[i][j]!=arr2[i][j]){
                         isequal=0;
                         printf("\nArray not Equal\n");
                         break;
                       }
                     
                    }
                  if(isequal==0){
                  break;
                 }
               }
                printf("\n");
                  if(isequal==1){
                     printf("Array Equal\n");

                        }
                    
                   printf("\nBack to Tool?(Y/N): ");
                scanf("%s",&go);
                if(go=='y')
                {
                  printf("------------------\n");
                break;
                }
               }

          }break;
    
    /*============================>>>11.Finding the Square or Power of a value<<<==============================*/
       
       case 11:
          {
            printf("\n----------------------------Finding the Square or Power of a value----------------------------\n");
              while (1)
              { 
                printf("\n---------------------------------\n");
                printf("  1. Finding the Square of a value\n  2. Finding the power of a value\n");
                int choice;
                float number,number_pow,power;
                printf("\nWhat do you want?:");
                scanf("%d",&choice);
                  switch(choice)
                  {
                    case 1:
                      printf("\nEnter the value: ");
                      scanf("%f",&number);
                      printf("\nSquare: %.2f",sqrt(number));
                      break;

                    case 2:
                      printf("\nAt what value?: ");
                      scanf("%f",&number_pow);
                      printf("Enter power: ");
                      scanf("%f",&power);  
                      printf("Value is %.2f",pow(number_pow,power));
                      break;
                  }
                   printf("\nBack to Tool?(Y/N): ");
                   scanf("%s",&go);
                    if(go=='y')
                    {
                     printf("---------------------------------\n");
                     break;
                    }
              }
                             
          }break;

    /*======================================>>>12.Matrices Calculetor<<<=======================================*/

       case 12:
          {
        printf("\n-----------------------------------Matrices Calculetor-----------------------------------\n\n");
              {
                while (1)
                {
                  
                
                      int r1,r2,c1,c2;
                      int i,j,k,p;
                        int md;
                          
                      //========frist Matrices=========     
                        printf("First Matrices Rows: ");
                        scanf("%d",&r1);
                        printf("First Matrices Colloms: ");
                        scanf("%d",&c1);

                            float arr1[r1][c1];
                            
                              printf("Enter first Matrices\n");
                              for(i=0;i<r1;i++){
                                  for(j=0;j<c1;j++){
                                  scanf("%f",&arr1[i][j]);
                                  }
                              }     
                      //========second Matrices=========   
                        printf("\nSecod Matrices Row: ");
                        scanf("%d",&r2);
                        printf("Second Matrices Collom: ");
                        scanf("%d",&c2);

                            float arr2[r2][c2];
                            
                              printf("Enter Second Matrices\n");
                                for(i=0;i<r2;i++){
                                    for(j=0;j<c2;j++){
                                    scanf("%f",&arr2[i][j]);
                                  }
                              }

                          printf("\n\n");
                          //first Matrices printing
                          printf("First Matrices\n");
                          for(i=0;i<r1;i++){
                              for(j=0;j<c1;j++){
                                printf("%.0f ",arr1[i][j]);
                                }
                              printf("\n");
                              }
                            printf("\n");
                              //second Matrices printing
                                printf("Second Matrices\n");
                                  for(i=0;i<r2;i++){
                                    for(j=0;j<c2;j++){
                                      printf("%.0f ",arr2[i][j]);
                                      }
                                  printf("\n");
                              }
            while (1)
              {
                  printf("\n---------------------------");
              printf("\n  1. Matrices multification\n");
              printf("  2. Matrices Divide\n");
              printf("  3. Matrices sum\n");
              printf("  4. Matrices subtract\n");
              printf("  5. All\n");//3
              printf("  6. EXIT\n");//4
          
              printf("\nWhat do you want?: ");
                scanf("%d",&md);
                  switch (md)
                    {
                    case 5:
                      {
                        case 1:
                        {
                      //Matrices multification logic
                            float mularr[r1][c2],mul;
                            for(i=0;i<r1;i++){
                              for(j=0;j<c2;j++){
                                mul=0;
                                for(k=0;k<c1;k++){
                                  mul=mul+(arr1[i][k]*arr2[k][j]);
                                }
                                mularr[i][j]=mul;  
                              }
                            }
                              printf("\nMatrices Multification\n");
                              //printing output
                                  for(i=0;i<r1;i++){
                                      for(j=0;j<c2;j++){
                                        printf("%.0f ",mularr[i][j]);
                                      }
                                        printf("\n");
                                  }
                              }
                              if(md!=5){
                                  break;
                                }
                        case 2:
                              {
                                
                      //Matrices Divide logic
                              float div,divarr[r1][c2];

                              for(i=0;i<r1;i++){
                                for(j=0;j<c2;j++){
                                  div=0;
                                    for(p=0;p<c1;p++){
                                      div=div+(float)(arr1[i][p]/arr2[p][j]); 
                                    }
                                    divarr[i][j]=div;
                                  }
                              }
                              printf("\nMatrices Divide\n");
                                for(i=0;i<r1;i++){
                                  for(j=0;j<c2;j++){
                                      printf("%.1f ",divarr[i][j]);
                                    }
                                  printf("\n");
                                  }
                          
                              }if(md!=5){
                                  break;
                              }
                      
                      //Matrices sum logic
                        case 3:
                        {
                           printf("\nMatrices Sum\n");
                          int sum[r1][c1];
                            for(i=0;i<r1;i++){
                              for(j=0;j<c1;j++){
                                sum[i][j]=(arr1[i][j]+arr2[i][j]);
                                printf("%d ",sum[i][j]);
                              }
                              printf("\n");
                            } 


                        }if(md!=5){
                            break;
                        }

                        case 4:
                        { 
                         // Matrices sumbtract logic
                           printf("\nMatrices subtract\n");
                          int sub[r1][c1];
                            for(i=0;i<r1;i++){
                              for(j=0;j<c1;j++){
                                sub[i][j]=(arr1[i][j]-arr2[i][j]);
                                printf("%d ",sub[i][j]);
                              }
                              printf("\n");
                            } 
                        }if(md!=5){
                            break;
                        }

                        case 6:
                          {
                            if(md==6){
                            system("cls");
                            printf("\n\tHave a nice Day!\n\n");
                             exit(0);
                          }
                        }break;
                          
                        default :
                          if(md!=6)
                            printf("Invalide Option");
                              
                      }break;         
                    } 
                    printf("\nGo to Matrices Calculetor?(Y/N): ");
                   scanf("%s",&go);
                    if(go=='y')
                    {
                     printf("---------------------------------\n");
                     break;
                    } 
                  }

                     printf("\nBack to Tool?(Y/N): ");
                     scanf("%s",&go);
                    if(go=='y')
                    {
                     printf("---------------------------------\n");
                     break;
                    } 
                    if(go=='n')
                    {
                      printf("\n---------------------------\n");
         
                    }

              }
          }
          }break;

    /*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Reserved for friends<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

                           //Write the code in this section according to your idea

    /*==============================================>>>Info<<<=================================================*/

        case 13:
          {
            char go;

                printf("\n------------------------------------Info------------------------------------\n\n");
                printf("Hi there!\n I am A Prabath. This was written just for practical training and experience\n"
                     "with a group of friends doing a project. So there may be bugs here.The steps \n"
                     "here can  be short. So in your  opinion you can  fix the bugs  in it of  add \n"
                     "somthing new to the manu. Details about the project are given below.\n"
                     "\n  #Project Link: https://github.com/avishka2k/C-Tool"
                     "\n\n  If you found this important, please folllow my social media.\n"
                     "\n\tMy GitHub Profile: https://github.com/avishka2k"
                     "\n\tTwitter: https://twitter.com/AvishkaPrabath6"
                     "\n\tlinkdin: https://www.linkedin.com/in/a-prabath-9b3267213\n");

              printf("\nGo to Main Menu?(Y/N): ");
                scanf("%s",&go);
                if(go=='y')
                break;


          }break;
               
    /*===============================================>>>EXIT<<<================================================*/

       case 14:
          {
            system("cls");
            printf("\n\tHave a nice Day!\n\n");
            exit(0);
          }break;
    
       default :
          {
        
          int yn;
            printf("\nSorry, nothing about the number you entered. if possible you can add activation.\n");
            printf("Do you want to make any changes or add any thing to the manu? Check Info (Y: 1/N: 2): ");
            scanf("%d",&yn);
            system("cls");
            if(yn==2)
              { 
                printf("\n\tHave a nice Day!\n\n");
                exit(0);
              }
            else if(yn==1) 
                  {
                printf("\n------------------------------------Info------------------------------------\n\n");
                printf("Hi there!\n I am A Prabath. This was written just for practical training and experience\n"
                       "with a group of friends doing a project. So there may be bugs here.The steps \n"
                       "here can  be short. So in your  opinion you can  fix the bugs  in it of  add \n"
                       "somthing new to the manu. Details about the project are given below.\n"
                       "\n  #Project Link: https://github.com/avishka2k/C-Tool"
                       "\n\n  If you found this important, please folllow my social media.\n"
                       "\n\tMy GitHub Profile: https://github.com/avishka2k"
                       "\n\tTwitter: https://twitter.com/AvishkaPrabath6"
                       "\n\tlinkdin: https://www.linkedin.com/in/a-prabath-9b3267213\n");
                exit(0);
                    }

          }break;
       
           }
            
             while (1)
             {
             printf("\nGo to Main Menu?(Y/N): ");
             scanf("%s",&go);
             if(go=='y'){
             break;
             } 
             if(go=='n')
              exit(0);            
             else
              printf("\nInvalide option\n");
             }

          printf("\n");
       }
   return 0;
}