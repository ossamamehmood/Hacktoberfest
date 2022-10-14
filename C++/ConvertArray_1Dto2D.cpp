#include <iostream>
using namespace std;

class convert {
	public :
		void input();
		void prosesOutput();
		void sort1d();
			
	private :
		int n, row, col;
		int data[40], output[40][20];
		int d = 0, tukar;
};

void convert::input(){
	// Input data [ data values must match the rows and columns to be create ]
	cout <<"Input the amount of data : ";
	cin >> n;
	for(int i=0; i<n; i++){
		cout <<"Data num-" << i+1 <<" = ";
		cin >> data[i];
	}
	
	// first-result
	cout <<endl <<"Result data : " <<endl; 
	for(int j=0; j<n; j++){
		cout << data[j] <<" ";
	}
	cout <<endl <<endl;
	
	cout <<"Enter the number of column : ";
	cin >> col;
	cout <<"Enter the number of row : ";
	cin >> row;
}

void convert::sort1d(){
	// Convert data for Sorting
	for (int i=0; i<n-1; i++){
        tukar = i;
        int temp = 0;
        for(int j=i+1; j<n; j++){
            if(data[j] < data[tukar]){
            	tukar = j;
            }
        }   
        temp = data[tukar];
        data[tukar] = data[i];
        data[i] = temp;
    }
    
    // Sorting Array 1D
    cout <<endl <<"Result after sorting : " <<endl;
    for(int i=0; i<n; i++){
        cout << data[i] << " ";
    }
}

void convert::prosesOutput(){
	// Convert array 1D to 2D
	cout <<endl <<"\n OUTPUT DATA" <<endl;
	cout <<"==============" <<endl;
	for(int k=0; k<row; k++){
		for(int l=0; l<col; l++){
			output[k][l] = data[d];
			d++;
		}
	}
	for(int k=0; k<row; k++){
		for(int l=0; l<col; l++){
			cout << output[k][l] <<"  ";
		}
		cout <<endl;
	}
}

int main(){
	convert cv;
	cv.input();
	cv.sort1d();
	cv.prosesOutput();
}
