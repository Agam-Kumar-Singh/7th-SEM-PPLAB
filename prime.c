//Write a program to find the prime numbers from 1 to n employing parallel for directive. Record both serial and parallel execution times.

#include<stdio.h>
#include<omp.h>

int main(){

    int prime[1000];
    printf("\nIn order to find prime numbers from 1 to n, enter the value of n:");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        prime[i]=1;
    }

    prime[1]=0;
    
    double start_time=omp_get_wtime();
    for(int i=2;i*i<=n;i++){

        #pragma omp parallel for
        for(int j=i*i;j<=n;j+=i)
        {
            if(prime[j]==1)
            prime[j]=0;
        }
    }
    double end_time=omp_get_wtime();
    printf("Execution time for parallel region: %lf\n",end_time-start_time);

    printf("\nPrime numbers from 1 to %d are\n",n);

    for(int i=2;i<=n;i++)
    {
        if(prime[i] == 1)
        {
            printf("%d\t ",i);
        }
    }

    return 0;
}