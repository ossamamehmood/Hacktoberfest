#include<iostream>
using namespace std;
 int main()
{
  	int N,M,R, incoming[1000],outgoing[1000],actin[1000],acout[1000];
  	int totin, totout;

  	cin>>N>>M>>R;
  if((N||M||R))
  {
  
          for(int i=0; i<N; i++)
          {
              cin>>incoming[i];
              actin[i]= incoming[i]-R;
          }

          for(int i=0; i<M; i++)
          {
              cin>>outgoing[i];
              acout[i]= outgoing[i]-R;
          }
          totin = 0;
          totout=0;
          for (int i=0;i<N;i++){
              totin += actin[i];
          }
          for (int i=0;i<M;i++){
              totout += acout[i];
          }
          int addpipe;
          addpipe =(totin-totout)+R;
          if (totin == totout){
              cout<<"BALANCED";
          }
          else{
              cout<<addpipe;
          }
  }
          
  else
  {
   cout<<"Invalid input";

  }
     return 0;
 }
