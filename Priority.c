#include<stdio.h>
struct PS
{
    int pid,BT,PR,WT,TAT;
};
void main()
{
int num,i,pos,j,temp;
float awt=0.0,atat=0.0;
struct PS p[10];
printf("Enter the number of processes");
scanf("%d",&num);
for(i=0;i<num;i++)
{
    printf("Enter the burst time of process %d:",i+1);
    scanf("%d",&p[i].BT);
    p[i].pid=i+1;
}
for(i=0;i<num;i++)
{
    printf("Enter the priority of the process %d:",i+1);
    scanf("%d",&p[i].PR);
}
for(i=0;i<num;i++)
{
    pos=i;
    for(j=i+1;j<num;j++)
    {
        if(p[j].PR<p[pos].PR)
        {
            pos=j;
        }
    }
    temp=p[i].PR;
    p[i].PR=p[pos].PR;
    p[pos].PR=temp;

    temp = p[i].BT;
    p[i].BT = p[pos].BT;
    p[pos].BT= temp;
}
    p[i].WT=0;
    printf("PID\tBurst Time\tPriority\tWaiting Time\tTurnarount Time\n");
    for(i=0;i<num;i++)
    {
        p[i].WT=0;
        p[i].TAT=0;
        for(j=0; j<i; j++)
        {
        p[i].WT=p[i].WT+p[j].BT;
        }
        p[i].TAT=p[i].WT+p[i].BT;
        awt=awt+p[i].WT;
        atat=atat+p[i].TAT;
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].BT,p[i].PR,p[i].WT,p[i].TAT);
    }
    awt=awt/num;
    atat=atat/num;
    printf("Average waiting Time=%f\n",awt);
    printf("Average Turnaround Time=%f\n",atat);
}