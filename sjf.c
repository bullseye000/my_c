#include<stdio.h>
void main()
{
    int i,j,n,t,p[20],bt[20],wt[20],tat[20];
    float avg_wt=0,avg_tat=0;
    printf("enter the number of process\n");
    scanf("%d",&n);
    printf("enter process numbers:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("enter the burst time of the process\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);

    }
    for(i=0;i<n;i++)
    {                                                  /*we use bubble sort here*/
       for(j=0;j<n-1-i;j++)
       {
        if(bt[j]>bt[j+1])
        {
            t=bt[j];
            bt[j]=bt[j+1];
            bt[j+1]=t;

            p[j]=t;
            p[j]=p[j+1];
            p[j+1]=t;
        }

       }
    }
    printf("\n Process\t Burst time\t Waiting time\t TAT\n");
    for(i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
        for(j=0;j<i;j++)
        {
            wt[i]+=bt[j];
        }
        tat[i]=wt[i]+bt[i];
        avg_tat+=tat[i];
        avg_wt+=wt[i];

        printf("\n%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);        
    }
    avg_wt=avg_wt/n;
    avg_tat/=n;
    printf("\naverage waiting time:%f\n",avg_wt);
    printf("average TAT is:%f\n",avg_tat);
}