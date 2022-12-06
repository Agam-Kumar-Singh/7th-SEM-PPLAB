//Write a program to calculate n Fibonacci numbers using Parallel Directive. Demonstrate elimination of the race condition using Schedule directive.

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>


int fib(int n){
    int a=0,b=1,c;

    #pragma omp parallel for schedule(static,2)
        for(int i=0;i<n;i++){
            c=a+b;
            a=b;
            b=c;
        }
    
    return a;
}
int main(){

    int n=7;
    double start=omp_get_wtime();

    #pragma omp parallel for
    for(int i=0;i<n;i++){
        int t = omp_get_thread_num();
        printf("thread: %d fib(%d) = %d\n",t,i,fib(i));
    }

    double end=omp_get_wtime();
    printf("Time taken: ",end-start);
}
