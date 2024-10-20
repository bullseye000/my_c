#include<stdio.h>

void main()
{
    int i,j,n,bt[20],wt[20],tat[20],p[20];
    float avg_wt=0,avg_tat=0;
    printf("enter number of process\n");
    scanf("%d",&n);
    printf("Enter process number\n");
    for(i=0;i<n;i++)
    scanf("%d",&i+1);

    printf("enter burst time");
    for(i=0;i<n;i++)
    {
        
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
        {
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[i];
        avg_tat+=tat[i];
        avg_wt+=wt[i];
    }
    printf("\n Process\t Burst time\t Waiting time\t TAT\n");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
        
    }
    avg_tat/=n;
    avg_wt/=n;
    printf("average witing time is:%f\n",avg_wt);
    printf("average TAT is:%f",avg_tat);
}