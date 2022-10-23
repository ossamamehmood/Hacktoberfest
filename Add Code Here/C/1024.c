#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//functions used
void display(int arr[4][4]);
void UP(int arr[4][4]);
void DOWN(int arr[4][4]);
void LEFT(int arr[4][4]);
void RIGHT(int arr[4][4]);

int quitcheck(int arr[4][4]);
void spawn(int arr[4][4],int num);

int main(){
    int i,j,arr[4][4],choice,cont = 1;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            arr[i][j] = 0;
        }
    }
    spawn(arr,2);
    
    display(arr);
    
    while(cont==1)
    {
        scanf("%d",&choice);
        if (choice == 1)
        {
            UP(arr);
            display(arr);
            spawn(arr,1);
            display(arr);
        }
        if (choice == 2)
        {
            DOWN(arr);
            display(arr);
            spawn(arr,1);
            display(arr);
        }
        if (choice == 3)
        {
            LEFT(arr);
            display(arr);
            spawn(arr,1);
            display(arr);
        }
        if (choice == 4)
        {
            //RIGHT(arr);
            display(arr);
            spawn(arr,1);
            display(arr);
        }
        else if(choice == 5){
            cont = 0;
        }

        /*if (quitcheck(arr)==0){
            cont = 0;
            printf("GAME OVER");
            }
        */
    }

    return 0;

}

void display(int arr[4][4]){
int i,j;
for(i=0;i<4;i++){

        printf("\n");
        for(j=0;j<4;j++){
            printf("| %d ",arr[i][j]);
        }
        printf("|\n");
    }
    
    printf("\n");
}

void UP(int arr[4][4]){
    int r,c,next,dub=0;
    for(c=3;c>=0;c--)
    {
        dub = 0;
        for(r=3;r>=0;r--)
        {
            if(r>0)
            next = arr[r-1][c];
            else 
            continue;

            if(next == 0){
                arr[r-1][c] = arr[r][c];
                arr[r][c] =  0; 
            }
            else if (next == arr[r][c]){
                if(dub == 0)
                {
                    if(r<3)
                    {
                    arr[r-1][c] = 2 * arr[r][c];
                    arr[r][c] =  arr[r+1][c];
                    dub = 1;
                    }
                    else
                    {
                    arr[r-1][c] = 2 * arr[r][c];
                    arr[r][c] =  0;
                    dub = 1;
                    }
                }    
                else
                    continue;          
            }
            else if (next != arr[r][c])
                continue;
                
        }
    }
    
}

int quitcheck(int arr[4][4])
{
    int i,j,count=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(arr[i][j]!=0)
                count+= 1;
        }
    }
    if(count == 16)
        return 0;
    else 
        return 1;
}

void spawn(int arr[4][4],int num){
    int i,x,y,x1,y1,done = 0;
    srand(time(0));
    
        for(i =0;i<num;i++)
        {
            done = 0;
            while(done == 0)
            {   
                x = rand()%4;  
                y = rand()%4;

                while(x1 == x && y1 == y)
                {
                    if(x<3 && y<3)
                    {
                        x += rand()%3;  
                        y += rand()%3;
                    }
                    else
                    {
                        x -= rand()%3;  
                        y -= rand()%3;
                    }
                }

                if(arr[x][y]==0)
                {
                    arr[x][y] = 1;
                    done = 1;
                }
                else 
                     continue;
                x1 = x;
                y1 = y;
            }
    }
}


void DOWN(int arr[4][4]){
    int r,c,next,dub=0;
    for(c=0;c<4;c++)
    {
        dub = 0;
        for(r=0;r<4;r++)
        {
            if(r<3)
            next = arr[r+1][c];
            else 
            continue;
            
            if(next == 0){
                arr[r+1][c] = arr[r][c];
                arr[r][c] =  0; 
            }
            else if (next == arr[r][c]){
                if(dub == 0)
                {
                    if(r>0)
                    {
                    arr[r+1][c] = 2 * arr[r][c];
                    arr[r][c] =  arr[r-1][c];
                    dub = 1;
                    }
                    else
                    {
                    arr[r+1][c] = 2 * arr[r][c];
                    arr[r][c] =  0;
                    dub = 1;
                    }
                }
                else
                    continue;          
            }
            else if (next != arr[r][c])
                continue;
                
        }
    }
    
}

void LEFT(int arr[4][4])
{
int r,c,next,dub=0;
    for(r=0;r<4;r++)
    {
        dub = 0;
        for(c=3;c>=0;c--)
        {
            if(c>0)
            next = arr[r][c-1];
            else 
            continue;

            if(next == 0){
                arr[r][c-1] = arr[r][c];
                arr[r][c] =  0; 
            }
            else if (next == arr[r][c]){
                if(dub == 0)
                {
                    if(c<3)
                    {
                    arr[r][c-1] = 2 * arr[r][c];
                    arr[r][c] =  arr[r][c+1];
                    dub = 1;
                    }
                    else
                    {
                    arr[r][c-1] = 2 * arr[r][c];
                    arr[r][c] =  0;
                    dub = 1;
                    }
                }    
                else
                    continue;          
            }
            else if (next != arr[r][c])
                continue;
                
        }
    }
    
}