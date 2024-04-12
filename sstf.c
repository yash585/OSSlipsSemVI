#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int curr_pos=0,lim,req[20],c=0,tot=0;
    printf("Enter head");
    scanf("%d",&curr_pos);
    printf("Enter no of requests");
    scanf("%d",&lim);
    printf("Enter requests:");
    for(int i=0;i<lim;i++)
    {
        scanf("%d",&req[i]);    
    }

    printf("%d",curr_pos);

    while(c!=lim)              //[98,183,41,122,14,124,65,67]
    {
        int index,min=999,min_dist;
        
        for(int i=0;i<lim;i++)
        {
            min_dist=abs(req[i]-curr_pos);
            if(min>min_dist)
            {
                min=min_dist;
                index=i;
            }
        }
        printf("-->%d",req[index]);
        curr_pos=req[index];
        req[index]=999;
        tot=tot+min;
        c++;
    }
    printf("\ntotal head movements:%d",tot);
}