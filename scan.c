#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int curr_pos,req[20],lim,temp,dir,index,minsize,maxsize,dist=0;
    printf("Enter head: ");
    scanf("%d",&curr_pos);
    printf("Enter limit: ");
    scanf("%d",&lim);
    printf("Enter Requests: ");
    for(int i=0;i<lim;i++)
    {
        scanf("%d",&req[i]);
    }
    for(int i=0;i<lim;i++)
    {
        for(int j=i+1;j<lim;j++)
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
    for(int i=0;i<lim;i++)
    {
        if(req[i]>curr_pos)
        {
            index=i;
            break;
        }
    }

    if(dir==1)
    {
        printf("Enter max size");
        scanf("%d",&maxsize);
        dist=abs(maxsize-curr_pos)+abs(maxsize-(req[index-1]))+abs(req[index-1]-req[0]);
    }
    if(dir==0)
    {
        printf("min size of disk:");
        scanf("%d",&minsize);
        dist=abs(curr_pos-minsize)+abs(req[lim-1]-minsize);
    }
    printf("%d",dist);
}
