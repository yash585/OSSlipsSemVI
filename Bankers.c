#include<stdio.h>
void calNeed();
void checkandCalculate();
int process,resource,row,col,allocation[10][10],max[10][10],size[10],need[10][10],counter=0,safeSeq[10],flag=0,temp=0,visited[10];
int main()
{
	printf("\nEnter Number of Processes :: ");
	scanf("%d",&process);
	printf("\nEnter Number of Resources :: ");
	scanf("%d",&resource);
	printf("\nEnter the Allocation Table ::\n");
	for(row=0;row<process;row++)
	{
		for(col=0;col<resource;col++)
		{
			scanf("%d",&allocation[row][col]);
		}
	}
	printf("\nAllocation Table is ::\n");
	for(row=0;row<process;row++)
	{
		for(col=0;col<resource;col++)
		{
			printf("%d\t",allocation[row][col]);
		}
		printf("\n");
	}
	printf("Enter the Max Table ::\n");
	for(row=0;row<process;row++)
	{
		for(col=0;col<resource;col++)
		{
			scanf("%d",&max[row][col]);
		}
	} 
	printf("\nMax Table is ::\n");
	for(row=0;row<process;row++)
	{
		for(col=0;col<resource;col++)
		{
			printf("%d\t",max[row][col]);
		}
		printf("\n");
	} 
	printf("\nEnter The Total Resources are Available ::\n");
	for(col=0;col<resource;col++)
	{
		scanf("%d",&size[col]);
	}
	printf("\nTotal Resources are ::\n");
	for(col=0;col<resource;col++)
	{
		printf("%d\t",size[col]);
	}	
	calNeed();
	checkandCalculate();	
}
void calNeed()
{
	for(row=0;row<process;row++)
	{
		for(col=0;col<resource;col++)
		{
			need[row][col]=(max[row][col]-allocation[row][col]);
		}
	}
	printf("\n Need Table is ::\n");
	for(row=0;row<process;row++)
	{
		for(col=0;col<resource;col++)
		{
			printf("%d\t",need[row][col]);
		}
		printf("\n\n");
	}
}
void checkandCalculate()
{
	for(row=0;row<process;row++)
	{
		visited[row]=0;
	}
	printf("Available Table is ::\n");
	while(temp<2)
	{
		for(row=0;row<process;row++)
		{
			flag=0;
			for(col=0;col<resource;col++)
			{
				if(visited[row]==0 && size[col]>=need[row][col])
				{
					continue;
				}		
				else
				{
					flag=1;
					break;	
				}
			}
			if(flag==0)
			{	
				for(col=0;col<resource;col++)
				{
					size[col]=size[col]+allocation[row][col];
					printf("%d\t",size[col]);
				}
				printf("\n");
				safeSeq[counter]=row;
				counter++;
				visited[row]=1;
			}
		}
		temp++;
	}	
	flag=0;
	for(row=0;row<process;row++)
	{
		if(visited[row]==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		printf("\nSystem is in Deadlock state...");
	}
	else
	{
		printf("\nSystem is in Safe State and Safe Sequence is ::\n");
		for(row=0;row<process;row++)
		{
			printf("P%d-->",safeSeq[row]);
		}
	}
}
