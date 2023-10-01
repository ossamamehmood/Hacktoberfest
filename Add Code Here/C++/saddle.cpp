/*
saddle point-> min in row and max in column
application-> used in maps,social media
*/
#include<iostream>
using namespace std;
class saddlemat{
    public:
        int mat[10][10],r1,c1;
        int pos_min=0;
        int pos_max=00;

        void getdata();
        void find();

};
 void saddlemat::getdata(){
    cout<<"\n enter row: ";
    cin>>r1;
    cout<<"\n enter col: ";
    cin>>c1;
    cout<<"\n enter values: \n";
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cin>>mat[i][j];
        }
        cout<<"\n";
    }

    cout<<"\n -------displaying matrix---------\n";
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cout<<mat[i][j]<<"\t";
        }
        cout<<"\n";
    }
 }

 void saddlemat::find(){
     int max=0;
     int min=0;
     int flag=0;

     for(int i=0;i<r1;i++){
        min=mat[i][0];
        for(int j=0;j<c1;j++){      //finding min in row
            if(mat[i][j]<min){
                min=mat[i][j];
                pos_min=j;
            }
        }
        max=mat[0][pos_min];
        for(int k=0;k<r1;k++){      //finding max in column
            if(mat[k][pos_min]>max){
                max=mat[k][pos_min];
                pos_max=k;
            }
        }
        if(max==mat[i][pos_min]){   //to be a saddle point->it has to be min in row and max in col

            cout<<"\n saddle point found:"<<mat[i][pos_min]<<" at row: "<<i<<" at col: "<<pos_min<<endl;
            flag=1;
        }
        else{
            continue;
        }
     }

     if(flag==0){
        cout<<"\n No saddle point in given matrix :(\n";
     }

 }

int main(){
    saddlemat m;
    m.getdata();
    m.find();

    return 0;
}    