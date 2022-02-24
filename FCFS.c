#include<stdio.h>
struct FCFS
{
    int pid,AT,BT,TAT;
};
void main()
{
    int num,i,j;
    float average = 0.0, sum = 0.0;
    struct FCFS p[10],temp;
    printf("Enter number of processes");
    scanf("%d",&num);
        for(i=0;i<num;i++)
        {
            printf("Enter arrival time and burst time of process %d",i+1);
            scanf("%d%d",&p[i].AT,&p[i].BT);
            p[i].pid = i+1;
        }
            for(i=0;i<num-1;i++)
            {  
                for(j=0;j<num-i-1;j++)
                {
                    if(p[j].AT>p[j+1].AT)
                    {
                        temp=p[j];
                        p[j]=p[j+1];
                        p[j+1]=temp;
                    }
                }
            }
            for(i=0;i<num;i++)
            {
                sum = sum+p[i].BT;
                p[i].TAT = sum;
            }
            sum=0;
            printf("PID\tArrival Time\tBurst Time\tTurnaround Time\n");
            for(i=0;i<num;i++)
            {
                printf("%d\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].AT,p[i].BT,p[i].TAT);
                sum = sum + p[i].TAT;
            }
                average = sum/(float)num;
                printf("\nTotal Turnaround Time : %f", sum);
                printf("\nAverage Turnaround Time : %.3f\n",average);
}
