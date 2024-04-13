#include<stdio.h>
int main()
{
	int file[50],index[50],i,file_index,limit,c=0;
	for(i=0;i<50;i++)
	{
		file[i]=0;
	}
	printf("\nEnter File Index :: ");
	scanf("%d",&file_index);
	if(file[file_index]==0)
	{
		printf("\nEnter How many numbers of blocks are required :: ");
		scanf("%d",&limit);
	}
	else
	{
		printf("Block is already Allocated...");
	}
	printf("\nEnter Files :: ");
	for(i=0;i<limit;i++)
	{
		scanf("%d",&index[i]);
		if(file[index[i]]==0)
		{
			file[index[i]]=1;
			c++;	
		}
	}
	if(c==limit)
	{
		for(i=0;i<limit;i++)
		{
			printf("\nIndex = %d --> File --> %d and Status = %d",file_index,index[i],file[index[i]]);
		}
	}
	else
	{
		printf("\nFile Already Allocated..");
	}
}

