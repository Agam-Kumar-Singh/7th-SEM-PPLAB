#include<stdio.h>
#include<omp.h>

int main(){
    int n;
    printf("Enter number of iterations: ");
    scanf("%d",&n);

    #pragma omp parallel for schedule(static,2)
    for(int i=0;i<n;i++){
        printf("\nThread %d is running iteration %d",omp_get_thread_num(),i);
    }
    return 0;
}
//export OMP_NUM_THREADS=2
//gcc chunks.c -fopenmp -o chunk
//./chunk