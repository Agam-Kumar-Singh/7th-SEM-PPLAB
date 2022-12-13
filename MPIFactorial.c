//Write a MPI program to find factorial of a number using Broadcast and Reduce operation.

#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(int argc,char *argv[]){

  int size,rank;
  int n;
  printf("Enter number whose factorial is to be found :");
  scanf("%d",&n);
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD,&size);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);

  int root=0;
  int global;

  MPI_Bcast(&n,1,MPI_INT,root,MPI_COMM_WORLD);
  int localProd=1;
  int len=(n/size)+1;
  for(int i=1;i<=len;i++){
    int val=(rank*len)+i;
    if(val<=n)
      localProd*=val;
    else break;
  }
  printf("Local Product: %d",localProd);
  MPI_Reduce(&localProd,&global,1,MPI_INT,MPI_PROD,root,MPI_COMM_WORLD);

  if(rank==root)
  printf("Factorial of %d is %d\n",n,global);
  MPI_Finalize();
}

//mpicc main.c
//./a.out
