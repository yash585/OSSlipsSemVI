#include <stdio.h>

int file[50],s,l,bno,blocks;

void linked()
{
    printf("enter number of blocks that are allocated:");
    scanf("%d",&blocks);
    printf("Enter block number that is allocated::\n");
    for(int i=0;i<blocks;i++)
    {
        printf("Enter block number: ");
        scanf("%d",&bno);
        file[bno]=1;
    }

    printf("\nEnter starting block and length");
    scanf("%d",&s);
    scanf("%d",&l);
    if(file[s]==0)
    {
        for(int i=s;i<(s+l);i++)
        {
            if(file[i]==0)
            {
                file[i]=1;
                printf("%d-->%d\n",i,file[i]);
            }
            else
            {
                printf("Block is full\n");
                l++;
            }
        }
    }
    else
    {
        printf("Files not allocated");
    }
}
int main()
{
    for(int i=0;i<50;i++)
    {
        file[i]=0;
    }
    linked();
}