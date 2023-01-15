#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
// int main(){
//     double a[]={1,2,3,4,5};
//     double b[]={11,12,13,14,15};

//     double c[5];
//     #pragma omp parallel for
//     for(int i=0;i<5;i++){
//         printf("Thread in execution: %d",omp_get_num_threads());
//         printf("\n");
//         c[i]=a[i]+b[i];
//     }
//     printf("Summed vector:\n");
//     for(int i=0;i<5;i++)
//     printf("%d ",c[i]);
//     return 0;
// }


#include<stdio.h>
#include<omp.h>
#include<stdlib.h>


void vecAdd(int *a,int *b,int *c,int n){

int t;
    #pragma omp parallel num_threads(n)
    {
        t=omp_get_thread_num();
        c[t]=a[t]+b[t];
        printf("Thread %d does calculation for c[%d]\n",t,t);
    }
}
int main(){

    int a[5],b[5];
    int c[5];

    for(int i=0;i<5;i++)
    {
        a[i]=rand()%10;
        b[i]=rand()%10;
    }

    printf("Array A: Is\n");
    for(int i=0;i<5;i++)
    printf("%d ",a[i]);
    printf("\n");

    printf("Array B: Is\n");
    for(int i=0;i<5;i++)
    printf("%d ",b[i]);

    printf("\n");
    vecAdd(a,b,c,5);

    printf("Vextor Addition:\n");
    for(int i=0;i<5;i++)
    printf("%d ",c[i]);


}

//gcc -foepnmp vecAdd.c -o Add
//./Add
