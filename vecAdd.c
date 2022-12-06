#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main(){
    double a[]={1,2,3,4,5};
    double b[]={11,12,13,14,15};

    double c[5];
    #pragma omp parallel for
    for(int i=0;i<5;i++){
        printf("Thread in execution: %d",omp_get_num_threads());
        printf("\n");
        c[i]=a[i]+b[i];
    }
    printf("Summed vector:\n");
    for(int i=0;i<5;i++)
    printf("%d ",c[i]);
    return 0;
}

//gcc -foepnmp vecAdd.c -o Add
//./Add