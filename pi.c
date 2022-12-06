//Estimate the value of pi using:pi=4*sigma(0,infi)[(-1)^k/(2k+1)]

//Parallelize the code by removing loop carried dependency and record both serial and parallel execution times.

#include<math.h>
#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

#define num_steps 1000000 //infinity assumptions

void main(){
    double pi=0;
    //serial
    double start=omp_get_wtime();
    for(int k=0;k<num_steps;k++)
    pi+=pow(-1,k)/(2*k+1);

    pi=4*pi;
    double end=omp_get_wtime();

    printf("Value of PI in serial is %lf with time %lf\n",pi,end-start);

    //parallel

    pi=0;
    //omp_set_num_threads(4);
    start=omp_get_wtime();
    int size=omp_get_num_threads();
    float thread[size];

    #pragma omp parallel for num_threads(6)
    for(int k=0;k<num_steps;k++){
        int t=omp_get_thread_num();
        thread[t]+=pow(-1,k)/(2*k+1);
    }
    

    for(int i=0;i<size;i++)
    pi+=thread[i];
    
    pi=4*pi;
    end=omp_get_wtime();
    printf("value of pi in parallel : %lf with time : %lf\n", pi,end-start);

}
