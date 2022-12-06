#include<stdio.h>
#include<stdlib.h>
#include<omp.h>


int isPrime(int x){
    if(x<=2)
    return 0;
    else
    for(int i=2;i<=x/2;i++)
    if(x%i==0)
    return 0;
    return 1;

}
void parallelprime(int n){
    
    printf("Prime Numbers are; \n");
    #pragma omp parallel for
    for(int i=2;i<=n;i++){
        if(isPrime(i))
        printf("%d ",i);
    }
}

void serialprime(int n){
    
    printf("Prime Numbers are; \n");
    for(int i=2;i<=n;i++){
        if(isPrime(i))
        printf("%d ",i);
    }
}


int main(){

   double start=omp_get_wtime();
   parallelprime(100);
   double end=omp_get_wtime();
   printf("Time for Parallel execution is %lf\n",end-start);

   start=omp_get_wtime();
   serialprime(100);
    end=omp_get_wtime();
   printf("Time for Serial execution is %lf\n",end-start);
}
