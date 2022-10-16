#include<iostream>
using namespace std;


int main(){

int m,n;
cin >> m >> n;
int arr[m][n];
int transp[n][m];

for ( int i=0 ; i<m ; i++){


  for (int j=0  ; j<n ; j++){
  
    cin >> arr[i][j] ; 
  
  }



}

for (int i=0; i< m ;i++){
    for (int j=0 ;j< n;j++){
        transp[j][i]=arr[i][j];
    }
}


for (int i=0  ;  i<m  ; i++){

	for(int j=0  ;   j<n  ; j++){
	
		cout << transp[i][j] << " ";
	}
	cout << '\n';
}


}
