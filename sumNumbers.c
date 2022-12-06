//Write a program   calculate the sum of first 100 Numbers. (Using critical directive)

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(){

    int sum=0;
    #pragma omp critical
    for(int i=1;i<=100;i++){
        sum+=i;
        printf("Thread in use:%d \n",omp_get_num_threads());
    }
    printf("Sum=%d ",sum);
}

//gcc -fopenmp sumNumbers.c -o sum
//./sum