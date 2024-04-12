#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int curr_pos,req[20],n,temp,dir,index,minsize,maxsize,dist=0;
    printf("enter limit");
    scanf("%d",&n);
    printf("enter curr pos");
    scanf("%d",&curr_pos);
    printf("Enter string");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(req[i]>req[j])
            {
                temp=req[i];
                req[i]=req[j];
                req[j]=temp;
            }
        }
    }
    
    printf("left (0) or right (1)");
    scanf("%d",&dir);
    for(int i=0;i<n;i++)
    {
        if(req[i]>curr_pos)
        {
            index=i;
            break;
        }
    }
        printf("Enter max size");
        scanf("%d",&maxsize);

        printf("min size of disk:");
        scanf("%d",&minsize);

    if(dir==1)
    {
        dist=abs(maxsize-curr_pos)+abs(maxsize-minsize)+abs(minsize-req[index-1]);
    }
    if(dir==0)
    {
        dist=abs(curr_pos-minsize)+abs(maxsize-minsize)+abs(maxsize-req[index]);
    }
    printf("%d",dist);
}