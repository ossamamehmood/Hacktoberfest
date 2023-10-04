
#include<stdio.h>
void main()
{int height=8,width=(height-2);
    //print A
    
  for(int row=0;row<height;row++)  
  {
      for(int col=0; col<=height/2;col++)
      {
          if(((col==0||col==height/2)&&row!=0)
          ||(row==0 &&col!=0 && col!=height/2)
          ||row==height/2){
              printf("*");
          }
          else printf(" ");
      }
printf("\n");
  }  

printf("\n\n\n");
//print B
   int row,col;//width=(height-2);
   
  for(row=0;row<height;row++)
  {
  printf("*");
  
      for(col=0; col<width;col++)
      
      {
          if
          (( row==0 || row==height/2 || row==height-1) &&col<width-1)
     {printf("*");
              
          }
         else
         if
          ((col==width-1)&&!( row==0 || row==height/2 || row==height-1) )
             
             { 
                 printf("*");
             }
          else 
               printf(" ");
      }
              printf("\n");
  }  

printf("\n\n\n");

    //print C
     //int row,col,width=(height-2);
   
  for(row=0;row<height;row++)
  {
  printf("*");
  
      for(col=0; col<width;col++)
      
      {
          if
          (row==0 || row==height-1)
     {printf("*");
              
          }
        
          else 
               printf(" ");
      }
              printf("\n");
  }  
  printf("\n\n\n");
  //print D
  for(int row=0;row<height;row++)  
  {
      for(int col=0; col<=height-2;col++)
      {
          if(col==0)
          {
              printf("*");
          }
          else
          if ((row==0||row==height-1) &&(col!=height-2))
          {
              printf("*");
          }
          else 
          if((col==height-2)&&!(row==0 || row==height-1))
          {
              printf("*");
          }
          else
           printf(" ");
      }
printf("\n");
  }  
  printf("\n\n\n");
  //print E
 //int row,col;
   
   
  for(row=0;row<height;row++)
  {
 
  
      for(col=0; col<height-1;col++)
      
      {
          if
          (col==0)
     {printf("*");
              
          }
         else
         if
          ( row==0||row==height-1||row==height/2 )
             
             { 
                 printf("*");
             }
          else 
               printf(" ");
      }
              printf("\n");
  }  
  printf("\n\n\n");
  //print F
   for(int row=0;row<height;row++)  
  {
      for(int col=0; col<=height/2;col++)
      {
          if(col==0)
          {
              printf("*");
          }
          else
          if (row==0||row==height/2)
          {
              printf("*");
          }
           printf(" ");
      }
printf("\n");
  }  
  printf("\n\n\n");
  //print G
  for(row=0;row<height;row++)
  {
  
  
      for(col=0; col<=width;col++)
      
      {
          if(row==height-1||row==0)
          {
              printf("*");
          }
          else
          if (col==0)
          {
              printf("*");
          }
          
         
          else
         if (col==width &&!(row<=height/2))
         {
            printf("*");
         }
         else
         if((row==height/2)&&!(col<=width/2))
         {
             printf("*");
         }
         else
           printf(" ");
         
      }
              printf("\n");
  }  
  printf("\n\n\n");
  //print H
  for(int row=0;row<height;row++)  
  {
      for(int col=0; col<=height-2;col++)
      {
          
          if ((col==0 || col==height-2))
          {
              printf("*");
          }
           else
           if(row==height/2)
           {
               printf("*");
           }
           else
           printf(" ");
      }
printf("\n");
  } 
  printf("\n\n\n");
  //print I
  for(int row=0;row<height;row++)  
  {
      for(int col=0; col<=height-2;col++)
      {
          if(row==0 || row==height-1)
          {
              printf("*");
          }
          else
          if (col==(height/2)-1)
          {
              printf("*");
          }
          else 
           printf(" ");
      }
printf("\n");
  }  
  printf("\n\n\n");
  //print J
  for(int row=0;row<height;row++)  
  {
      for(int col=0; col<=height-2;col++)
      {
          if(row==0)
          {
              printf("*");
          }
          else
          if (col==(height/2)-1)
          {
              printf("*");
          }
          else 
          if(row==height-1 &&!(col>=(height/2)-1))
          {
              printf("*");
          }
          else
          if(col==0 &&!(row<=height-4))
          {
              printf("*");
          }
          else
           printf(" ");
      }
printf("\n");
  }
  printf("\n\n\n");
  //print K
   for(row=0;row<height;row++)
  {
  
  
      for(col=0; col<=width;col++)
      
      {
          if(row==col+3) 
          {
              printf("*");
          }
          else
          if(col==(height-row)-3) 
          {
              printf("*");
          }
          else
          if(col==0) 
          {
              printf("*");
          }
         
          else
        
           printf(" ");
         
      }
              printf("\n");
  }  
  printf("\n\n\n");
  //print L
  
      for(int row=0;row<height;row++)  
  {
      for(int col=0; col<=height-2;col++)
      {
          if(row==height-1)
          {
              printf("*");
          }
          else
          if (col==0)
          {
              printf("*");
          }
          else 
           printf(" ");
      }
printf("\n");
  }  
printf("\n\n\n");
//print M
for(row=0;row<height;row++)
  {
      for(col=0; col<=width;col++)
      
      {
          if(col==0||col==width)
          {
              printf("*");
          }
          else
          if(col==row&&!(row>=4)) 
          {
              printf("*");
          }
          
         
          else 
           if(col==(height-row)-2 &&!(row>=4)) 
          {
              printf("*");
          }
          else
           printf(" ");
         
      }
      printf("\n");
  }
  printf("\n\n\n");

//print N
for(row=0;row<height;row++)
  {
  
  
      for(col=0; col<=width;col++)
      
      {
          
          if (col==0)
          {
              printf("*");
          }
          
         
          else
         if (col==width)
         {
            printf("*");
         }
         else
         if(row==col)
         {
             printf("*");
         }
         else
           printf(" ");
         
      }
              printf("\n");
  }  
  printf("\n\n\n");
//print O
  for(int row=0;row<height;row++)  
  {
      for(int col=0; col<=height-2;col++)
      {
          if(row==0 ||row==height-1 )
          {
              printf("*");
          }
          else
          if (col==0||col==height-2)
          {
              printf("*");
          }
          else 
           printf(" ");
      }
      printf("\n");
 }  
  printf("\n\n\n");
  //print P
  for(row=0;row<height;row++)
  {
  
  
      for(col=0; col<=width;col++)
      
      {
          if(col==0|| (col==width)&&!(row>=height/2))
          {
              printf("*");
          }
          else
          if (row==0 || row== height/2)
          {
              printf("*");
          }
          
         
          else
           printf(" ");
         
      }
              printf("\n");
  }  
  printf("\n\n\n");
  //print Q
  for(row=0;row<height;row++)
  {
      for(col=0; col<=width;col++)
      
      {
          if((col==0||col==width)&&!(row==height-1))
          {
              printf("*");
          }
          else
          if(row==0||row==height-2) 
          {
              printf("*");
          }
          
         
          else 
           if(((row==height-3)&&(col==width-2))||((row==height-4)&&(col==width-3))||((row==height-1)&&(col==width))) 
          {
              printf("*");
          }
          else
           printf(" ");
         
      }
              printf("\n");
  }  
  printf("\n\n\n");
  //print R
   for(row=0;row<height;row++)
  {
      for(col=0; col<=width;col++)
      
      {
          if(row==0||row==(height/2)-1) 
          {
              printf("*");
          }
          else
          if(col==0||(col==width)&&!(row>=height/2)) 
          {
              printf("*");
          }
          else
          if(row==col+2)
          {
              printf("*");
          }
          else
           printf(" ");
         
      }
              printf("\n");
  }  
  printf("\n\n\n");
//print S
for(row=0;row<height;row++)
  {
  
  
      for(col=0; col<=width;col++)
      
      {
          if(row==0||row==height-1||row==height/2)
          {
              printf("*");
          }
          else
          if (col==0&&!(row>=height/2))
          {
              printf("*");
          }
          
         
          else
          if(col==width&&!(row<=height/2))
          {
              printf("*");
          }
          else
           printf(" ");
         
      }
              printf("\n");
  }

printf("\n\n\n");
//print T
 for(row=0;row<height;row++)
  {
  
  
      for(col=0; col<=width;col++)
      
      {
          if(row==0 )
          {
              printf("*");
          }
          else
          if (col==width/2)
          {
              printf("*");
          }
          
         
          else
         
           printf(" ");
         
      }
              printf("\n");
  }  
  printf("\n\n\n");
  //print U
  for(row=0;row<height;row++)
  {
  
  
      for(col=0; col<=width;col++)
      
      {
          if(row==height-1)
          {
              printf("*");
          }
          else
          if (col==0||col==width)
          {
              printf("*");
          }
          
         
          else
         
           printf(" ");
         
      }
              printf("\n");
  }  
  printf("\n\n\n");
  //print V
  for(row=0;row<height;row++)
  {
      for(col=0; col<=width;col++)
      
      {
          if((col==0||col==width)&&!(row>=4)) 
          {
              printf("*");
          }
          else
          if((col==3)&&(row==height-1)) 
          {
              printf("*");
          }
          
         
          else 
           if((col==2||col==width-2)&&(row==height-3)) 
          {
              printf("*");
          }
          else
           printf(" ");
         
      }
              printf("\n");
  }  
  printf("\n\n\n");
  //print W
  for(row=0;row<height;row++)
  {
      for(col=0; col<=width;col++)
      
      {
          if(col==0||col==width)
          {
              printf("*");
          }
          else
          if(col==row&&!(row<3)) 
          {
              printf("*");
          }
          
         
          else 
           if(col==(height-row)-2 &&!(row<3)) 
          {
              printf("*");
          }
          else
           printf(" ");
         
      }
              printf("\n");
  }  
  printf("\n\n\n");
  //print x
   for(row=0;row<height;row++)
  {
  
  
      for(col=0; col<=width;col++)
      
      {
          if(col==(height-row)-2) 
          {
              printf("*");
          }
         
          else
         if(row==col) 
          {
              printf("*");
          }
          else
           printf(" ");
         
      }
              printf("\n");
  }
  printf("\n\n\n");
  //print Y
  for(row=0;row<height;row++)
  {
      for(col=0; col<=width;col++)
      
      {
          if(col==width/2&&!(row<=3))
          {
              printf("*");
          }
          else
          if(col==row&&!(row>=4)) 
          {
              printf("*");
          }
          
         
          else 
           if(col==(height-row)-2 &&!(row>=4)) 
          {
              printf("*");
          }
          else
           printf(" ");
         
      }
              printf("\n");
  }  
  printf("\n\n\n");
  //print z
   for(row=0;row<height;row++)
  {
      for(col=0; col<=width;col++)
      
      {
          if(row==0||row==height-2) 
          {
              printf("*");
          }
          else
          if(col==(height-row)-3) 
          {
              printf("*");
          }
          else
           printf(" ");
         
      }
              printf("\n");
  }  
  printf("\n\n\n");

}

                

