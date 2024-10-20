#include<stdio.h>

void main()
{
    int n,i,qt,temp,sq=0,bt[10],wt[10],tat[10],count=0,rem_bt[10];
    float avg_tat=0,avg_wt=0;
    printf("enter umber of process\n");
    scanf("%d",&n);
    printf("enter burst time");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
    }
    printf("enter quantum time");
    scanf("%d",&qt);
    
    while(1)
    {
        for(i=0,count=0;i<n;i++)
        {
            temp=qt;
            if(rem_bt[i]==0)
            {
                count++;
                continue;

            }
            if(rem_bt[i]>qt)
            rem_bt[i]-=qt;
            else
            if(rem_bt[i]>=0)
            {
                temp=rem_bt[i];
                rem_bt[i]=0;

            }
            sq+=temp;
            tat[i]=sq;
            
        }
        if(n==count)
        break;
    }
    printf("\nProcess\tBurst time\tTAT\tWaiting time\n");
    for(i=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];
        avg_wt=avg_wt+wt[i];
        avg_tat+=tat[i];

        printf("\n%d\t%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],tat[i],wt[i]);
        
    }
    avg_wt/=n;
    avg_tat/=n;

    printf("average waiting time:%f\n",avg_wt);
    printf("average tat is:%f\n",avg_tat);

}