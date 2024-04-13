#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#include<limits.h>
int main(int argc,char **argv)
{
	int rank,size,number[100],local_min=INT_MAX,local_max=INT_MIN,i,global_min,global_max;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	srand(rank);
	for(i=0;i<100;i++)
	{
		number[i]=rand()%100;
		if(local_min>number[i])
		{
			local_min=number[i];
		}
		if(local_max<number[i])
		{
			local_max=number[i];
		}
	}
	MPI_Allreduce(&local_min,&global_min,1,MPI_INT,MPI_MIN,MPI_COMM_WORLD);
	MPI_Allreduce(&local_min,&global_min,1,MPI_INT,MPI_MAX,MPI_COMM_WORLD);
	printf("\nProcess %d ::\nLocal Min = %d\nLocal Max = %d",rank,local_min,local_max);
	if(rank==0)
	{
		printf("\nLocal Min = %d\nLocal Max = %d",global_min,global_max);	
	}
	MPI_Finalize();
}
