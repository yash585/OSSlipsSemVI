#include <stdio.h>
#include <stdlib.h>

int file[50],s,l,ch;

void contiguous()
{
    printf("Enter starting block and length:");
    scanf("%d",&s);
    scanf("%d",&l);
    for(int i=s;i<(s+l);i++)
    {
        if(file[i]==0)
        {
            file[i]=1;
            printf("%d-->%d\n",i,file[i]);

        }
        else
        {
            l++;
        }
    }
    printf("Do you want to add new files(0/1)?");
    scanf("%d",&ch);
    if(ch==1)
    {
        contiguous();
    }
    else if(ch==0)
    {
        exit(0);
    }
}
int main()
{
    for(int i=0;i<50;i++)
    {
        file[i]=0;
    }
    contiguous();
}