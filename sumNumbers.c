//Write a program   calculate the sum of first 100 Numbers. (Using critical directive)

#include<stdio.h>
#include<omp.h>

int main(){

    int n=100;
    double sum=0;

    // #pragma omp parallel for shared(sum)
    // for(int i=1;i<=n;i++){
    // #pragma omp critical
    // sum+=i;
    // }

    // printf("Sum is: %d ",sum);

    double thread[100];
    #pragma omp parallel for num_threads(8)
    for(int i=1;i<=100;i++)
    {
        #pragma omp critical
        {   
            int t=omp_get_thread_num();
            thread[t]+=i;
            printf("Thread %d has now value stored: %lf\n",t,thread[t]);
        }

    }

    for(int i=0;i<8;i++)
    sum+=thread[i];

    printf("Sum is %lf ",sum);
}

//gcc -fopenmp sumNumbers.c -o sum
//./sum
