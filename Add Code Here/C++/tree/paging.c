//Stimulate page replacement algorithms

#include<stdio.h>
#include<stdlib.h>
int framesize,pagesize,page[30],counter=0;
void fifo(){
    int i,j,k,frame[10] = {[0 ... 9]=-1},pagefault=0;
    int available,index=0;
    for(i=0;i<pagesize;i++){
        available =0;
        for(j=0;j<framesize;j++){
            if(frame[j]==page[i])
                available=1;
        }
        if(available==0){
            frame[index]=page[i];
            index=(index+1)%framesize;
            pagefault++;
            for(k=0;k<framesize;k++){
                printf("%d\t",frame[k]);
            }
            printf("Pagefault : %d\n",pagefault);
        }
    }
    printf("\nTotal Page Faults: %d\n", pagefault);
}
void lru(){
    int i,j,k,frame[10] = {[0 ... 9]=-1},pagefault=0;
    int time[10]={0};
    int clock=0,available,flag1,pos,min;

    for(i=0;i<pagesize;i++){
        clock++;
        available=0;
        for(j=0;j<framesize;j++){
            if(frame[j]==page[i]){
                available=1;
                time[j]=clock;
            }
        }

        if(available==0){
            flag1=0;
            for(j=0;j<framesize;j++){
                if(frame[j]==-1){
                    frame[j]=page[i];
                    time[j]=clock;
                    flag1=1;
                    break;
                }
            }

            if(flag1==0){
                min=time[0];
                pos=0;
                for(j=1;j<framesize;j++){
                    if(min>time[j]){
                        min=time[j];
                        pos=j;
                    }
                }
                frame[pos]=page[i];
                time[pos]=clock;
            }
            pagefault++;
            for(k=0;k<framesize;k++)
                printf("%d\t",frame[k]);
            printf("Pagefault : %d\n",pagefault);
        }
    }
    printf("\nTotal Page Faults: %d\n", pagefault);
}
void optimal(){
    int i,j,k,frame[10] = {[0 ... 9]=-1},pagefault=0;
    int occurrence[10]={[0 ... 9]=0};
    int available,flag1,flag2,max,pos;

    for(i=0;i<pagesize;i++){
        available=0;
        for(j=0;j<framesize;j++){
            if(frame[j]==page[i])
                available=1;
        }

        if(available==0){
            flag1=0;
            for(j=0;j<framesize;j++){
                if(frame[j]==-1){
                    frame[j]=page[i];
                    flag1=1;
                    break;
                }
            }

            if(flag1==0){
                for(j=0;j<framesize;j++){
                    occurrence[j]=0;
                    for(k=i+1;k<pagesize;k++){
                        if(frame[j]==page[k]){
                            occurrence[j]=k;
                            break;
                        }
                    }
                }
                flag2=0;
                for(j=0;j<framesize;j++){
                    if(occurrence[j]==0){
                        frame[j]=page[i];
                        flag2=1;
                        break;
                    }
                }

                if(flag2==0){
                    max=occurrence[0];
                    pos=0;
                    for(j=1;j<framesize;j++){
                        if(occurrence[j]>max){
                            max=occurrence[j];
                             pos=k;
                        }
                    }
                    frame[pos]=page[i];
                }
            }
            pagefault++;
            for(k=0;k<framesize;k++){
                printf("%d\t",frame[k]);
            }
            printf("Pagefault : %d\n",pagefault);
        }
    }
    printf("\nTotal Page Faults: %d\n", pagefault);
}
void main(){
    int i,ch;
    char cho;
    printf("Enter the number of pages : ");
    scanf("%d",&pagesize);
    printf("Enter the reference string values : \n");
    for(i=0;i<pagesize;i++)
        scanf("%d",&page[i]);
    printf("Enter the number of frames : ");
    scanf("%d",&framesize);
    do
    {
        printf("\t\t MENU");
        printf("\n 1) FIFO \n 2) LRU \n 3) Optimal");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        if(ch == 1)
            fifo();
        else if(ch == 2)
            lru();
        else if(ch == 3)
            optimal();
        else
        printf("Enter valid choice ");
        printf("\nDo you want to continue(y/n)?:");
        scanf("%s",&cho);
    } while(cho=='y'||cho=='Y');
}
