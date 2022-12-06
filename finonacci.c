//Write a program to calculate n Fibonacci numbers using Parallel Directive. Demonstrate elimination of the race condition using Schedule directive.

#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

long fib(int n){
    if(n<2)
    return 1;
    else
    return fib(n-1)+fib(n-2);
}

int main(){

    printf("Enter number of fibonnaci numbers to be calculated: ");
    int n;
    scanf("%d",&n);

    #pragma omp parallel num_threads(n)
    {
        int t=omp_get_thread_num();
        printf("%d:%ld\n",t,fib(t));
    
    }
    return 0;

}