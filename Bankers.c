#include <stdio.h>

int main()
{
    int proc,rec,alloc[20][20],max[20][20],avail[20],need[20][20],safeseq[20],visited[20],flag=0,temp=0,ind=0;
    printf("Enter no of processes: ");
    scanf("%d",&proc);
    printf("Enter no of resources: ");
    scanf("%d",&rec);
    printf("Enter Allocation matrix: \n");
    for(int i=0;i<proc;i++)
    {
        for(int j=0;j<rec;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("\nAllocation matrix: \n");
    for(int i=0;i<proc;i++)
    {
        for(int j=0;j<rec;j++)
        {
            printf("%d  ",alloc[i][j]);
        }
        printf("\n");
    }
    printf("Enter MAX matrix: \n");
    for(int i=0;i<proc;i++)
    {
        for(int j=0;j<rec;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("\nMAX matrix: \n");
    for(int i=0;i<proc;i++)
    {
        for(int j=0;j<rec;j++)
        {
            printf("%d  ",max[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter Available matrix: \n");
    for(int i=0;i<rec;i++)
    {
        scanf("%d",&avail[i]);
    }
    printf("\nAvailable matrix: \n");
    for(int i=0;i<rec;i++)
    {
        printf("%d ",avail[i]);
    }

    for(int i=0;i<proc;i++)
    {
        for(int j=0;j<rec;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("\nNeed matrix: \n");
    for(int i=0;i<proc;i++)
    {
        for(int j=0;j<rec;j++)
        {
            printf("%d  ",need[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<proc;i++)
    {
        visited[i]=0;
    }

    printf("Available:: \n");
    while(temp<2)
    {
        for(int i=0;i<proc;i++)
        {
            flag=0;
            for(int j=0;j<rec;j++)
            {
                if(visited[i]==0 && avail[j]>=need[i][j])
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
                for(int j=0;j<rec;j++)
                {
                    avail[j]=avail[j]+alloc[i][j];
                    printf("%d  ",avail[j]);
                }
                printf("\n");
                safeseq[ind]=i;
                visited[i]=1;
                ind++;
            }
        }
        temp++;
    }
    flag=0;
    for(int i=0;i<proc;i++)
    {
        if(visited[i]==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        printf("System is in deadlock......");
    }
    else
    {
        printf("safe seq: \n");
        for(int i=0;i<proc;i++)
        {
            printf("-->P%d",safeseq[i]);
        }
    }
}