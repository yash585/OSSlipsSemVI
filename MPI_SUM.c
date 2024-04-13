#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
int main(int argc,char **argv)
{
	int rank,size,number[100],local_sum=0,global_sum=0,i;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	srand(rank);
	for(i=0;i<100;i++)
	{
		number[i]=rand()%100;
		local_sum=local_sum+number[i];
	}
	MPI_Reduce(&local_sum,&global_sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	if(rank==0)
	{
		printf("\nSum of %d numbers is :: %d\n",100*size,global_sum); 
	}
	MPI_Finalize();
}
