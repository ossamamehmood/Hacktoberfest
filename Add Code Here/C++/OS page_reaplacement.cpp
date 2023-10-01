//C++ implementation of page replacement algorithms

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//Function to find page faults using FIFO
int fifo_pageFaults(int page_ref[], int pages, int frames){
    int page_faults = 0 , temp[frames];
    queue<int> q;

    for (int i = 0; i < frames; i++)
    {     q.push(-1);   }

    for (int i = 0; i < pages ; i++)
    {   int s = 0;
        for (int j = 0; j < frames; j++)
        {   temp[j] = q.front();          //to iterate over queue
            q.pop();   q.push(temp[j]);   
        } 

        for (int j = 0; j < frames; j++)
        {
            if ( temp[j] == page_ref[i] )
            {   break; }  
            s++; 
        }
        
        if(s == frames){    //if page not found
            page_faults++;
            q.pop();
            q.push(page_ref[i]);        //push page into the queue
        }
        
    }
    cout <<"no. of page faults by FIFO method : "<< page_faults << "\n" ;
}

//Function to find page faults by LRU
int findLRU(int time[], int frames){
    int minimum = time[0], pos = 0;
    for (int i = 1; i < frames; i++)
    {    if (time[i] < minimum)
        {
            minimum = time[i];
            pos = i;
        }
    }
   return pos; 
}

int lru_pageFaults(int page_ref[], int pages, int frames){
    int temp[frames], time[frames];
    int page_faults = 0 , counter = 0;

    for (int i = 0; i < frames; i++)
    {   temp[i] = -1; 
        time[i] = 0;  }

    for (int i = 0; i < pages ; i++)
    {   
        counter ++;                  // counting time
        int s = 0;
        for (int j = 0; j < frames; j++)
        {
            if ( temp[j] == page_ref[i] )   //if page found
            {   time[j] = counter;
                break; }  
            s++; 
        }
        
        if(s == frames){    //if page not found
            page_faults++;
            int pos = findLRU(time,frames);
            temp[pos] = page_ref[i];         //replace page
            time[pos] = counter;  
        }
        
    }
    cout <<"no. of page faults by LRU method : "<< page_faults << "\n" ;
}


//Function to find page faults by optimal
int farthest_frame(int pg[],int fr[],int pages,int frames, int cur_index){
    int farthest = cur_index, ref[frames]={0,0,0,0};
    for (int i = 0; i < frames; i++)
    {
        for(int j=cur_index ; j< pages ;j++){
            if (fr[i] == pg[j]){
                ref[i] = 1;
                if (j > farthest)   //if it is referenced farther from prev
                { farthest = j;}      
            }
            break;   //break and check for the next frame
        }
    }

    for (int i = 0; i < frames; i++)
    {   //if a page is never referenced return it
        if(ref[i]==0){return i;}
    }
    
    return farthest;
}


int optimal_pageFaults(int page_ref[], int pages, int frames){
    int fr[frames];
    int page_faults = 0 ;

    for (int i = 0; i < frames; i++)
    {   fr[i] = -1;  }

    for (int i = 0; i < pages ; i++)
    {   

        int s = 0;
        for (int j = 0; j < frames; j++)
        {
            if ( fr[j] == page_ref[i] )   //if page found
            {  break; }  
            s++; 
        }
        
        if(s == frames){    //if page not found
            page_faults++;
            for(int m=0;m<frames;m++){
                if(fr[m]== -1){     //if frame is empty
                    fr[m] = page_ref[i];
                    break;
                }
                if(m==frames){    //if frames are full
                    //find the page which is referenced farthest
                    int pos = farthest_frame(page_ref, fr ,pages,frames,i);
                    fr[pos] = page_ref[i];         //replace page   
            }
            }  
            //find the page which is referenced farthest
            int pos = farthest_frame(page_ref, fr ,pages,frames,i);
            fr[pos] = page_ref[i];         //replace page
            
        }
        
    }
    cout <<"no. of page faults by optimal method : "<< page_faults << "\n" ;
}





/* Driver Code */
int main(){
        int page_reference[10],frames = 4 ;
        srand(time(0));
        for (int i = 0; i < 10 ; i++)
        {  
            page_reference[i] = ((rand()%50)%30) % 10 ;
            cout<<page_reference[i]<<"\n";
        }
       
        int pages = sizeof(page_reference)/sizeof(page_reference[0]);
        fifo_pageFaults(page_reference ,pages, frames);
        lru_pageFaults(page_reference,pages, frames);
        optimal_pageFaults(page_reference,pages, frames);
        
}
