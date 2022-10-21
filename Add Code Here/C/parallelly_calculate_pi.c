// A program built with OpenMP that uses paralell programming to calculate a value for PI.
// This program also outputs the average time taken for the program to run.

#include <omp.h>
#include <stdio.h>
#include <unistd.h>

// Defines the number of times to run this program to calculate an average value for 
// the time taken to run it
#define RUNS 10

int main(){

    // n is a very large, arbitary integer
	int n = 100000;

	float value=0;
    long int total = 0;
    double tStart=0, tCalc=0, tStop=0;
    double timeTotal = 0;
    for (int s=1; s<=RUNS; s++){
        total = 0;
        tStart = omp_get_wtime();
    #pragma omp parallel for reduction(+:value)
        for (int a=1; a<=n; a++){
            value = value + (1 / (1 + ((a-0.5)/n)*((a-0.5)/n)));
        }
        value = value/(float)n * 4;

        printf("Pi =  %f\n", value);
        tStop = omp_get_wtime();
        tCalc = tStop - tStart;
        printf("Time taken =  %f\n", tCalc);
        if(s>3){
            timeTotal += tCalc; 
        }
    }
    printf("Average time taken =  %f\n", (float)timeTotal/RUNS);
}