#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int curr_pos=0,req[20],i,limit,dist=0;
    printf("Enter curr pos:");
    scanf("%d",&curr_pos);
    printf("Enter no of requests");
    scanf("%d",&limit);
    printf("Enter requests");
    for(int i=0;i<limit;i++)
    {
        scanf("%d",&req[i]);
    }

    dist+=abs(curr_pos-req[0]);
    printf("%d->%d",curr_pos,req[0]);
    
    for(int i=1;i<limit;i++)
    {
        dist+=abs(req[i]-req[i-1]);
        printf("->%d",req[i]);
    }
    printf("\n%d",dist);

}