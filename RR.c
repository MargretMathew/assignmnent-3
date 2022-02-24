#include<stdio.h>
struct RR
{
    int pid,BT,TAT,WT;
};
void main()
{
    int i,num,qt,sq=0,count=0,temp,bt[10];
    float awt=0,atat=0;
    struct RR p[10];
    printf("Enter the number of processes");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
    printf("Enter the burst time of process %d:",i+1);
    scanf("%d",&p[i].BT);
    bt[i] = p[i].BT;
    p[i].pid = i+1;
    }
    printf("Enter the quantum time");
    scanf("%d",&qt);
    while(1)
    {
        for(i=0,count=0;i<num;i++)
        {
            temp=qt;
            if(bt[i]==0)
            {
                count++;
                continue;
            }
            if(bt[i]>qt)
            {
            bt[i]=bt[i]-qt;
            }
            else
                if(bt[i]>=0)
                {
                    temp=bt[i];
                    bt[i]=0;
                }
            sq=sq+temp;
            p[i].TAT=sq;
        }
            if(num==count)
            break;
    }
    printf("\nPID\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for(i=0;i<num;i++)
    {
        p[i].WT=p[i].TAT-p[i].BT;
        awt=awt+p[i].WT;
        atat=atat+p[i].TAT;
        printf("\n%d\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].BT,p[i].TAT,p[i].WT);
    }
    awt=awt/num;
    atat=atat/num;
    printf("Average waiting time=%f\n",awt);
    printf("Average turnaround time=%f\n",atat);
}