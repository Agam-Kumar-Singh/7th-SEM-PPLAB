#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void merge(int *a,int i1,int j1,int i2,int j2){

    int i=i1;
    int j=i2;
    int k=0;

    int temp[1000];
    while(i<=j1 && j<=j2)    //while elements in both lists
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }

    while(i<=j1)    //copy remaining elements of the first list
        temp[k++]=a[i++];
        
    while(j<=j2)    //copy remaining elements of the second list
        temp[k++]=a[j++];
    
    for(i=i1,j=0;i<=j2;i++,j++)
    a[i]=temp[j];

}

void mergesortParallel(int *a,int l,int h){
    if(l<h){

        int mid=(l+h)/2;

        #pragma omp parallel sections
        {
            #pragma omp section
            {  
                mergesortParallel(a,l,mid);
            }
            #pragma omp section
            {  
                mergesortParallel(a,mid+1,h);
            }
        }
        merge(a,l,mid,mid+1,h);
    }
}

void mergesortSerial(int *a,int l,int h){
    if(l<h){

        int mid=(l+h)/2;
                mergesortSerial(a,l,mid);
                mergesortSerial(a,mid+1,h);
        merge(a,l,mid,mid+1,h);
    }
}
int main(){

    int a[100],n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    double start=omp_get_wtime();
    mergesortParallel(a,0,n-1);
    double end=omp_get_wtime();
    printf("\nTime for parallel execution is: %lf",end-start);

    start=omp_get_wtime();
    mergesortSerial(a,0,n-1);
    end=omp_get_wtime();
    printf("\nTime for Serial execution is: %lf",end-start);

    printf("Array after sorting:\n");
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);

}
