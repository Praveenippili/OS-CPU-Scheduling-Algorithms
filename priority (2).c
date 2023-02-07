// C Implementation of Preemptive Priority Scheduling
#include<stdio.h>
#include<conio.h>
main()
{
    int n,i;//number of processes to be scheduled
    printf("Enter the number of processes:");
    scanf("%d",&n);
    int arrivalTime[n],burstTime[n],priority[n+1];
    for(i=0; i<n; i++)
    {
        printf("Enter the Arrival Time& Burst Time:");
        scanf("%d%d",&arrivalTime[i],&burstTime[i]);
    }
    for(i=0; i<n; i++)
    {
        printf("Enter the Priority:");
        scanf("%d",&priority[i]);
    }
    
    int x[n];
    int waitingTime[n],turnaroundTime[n], completionTime[n];
    int j, smallest, count = 0, time; // count -> number of processes completed
    double avg=0,tt=0,end;
    for(i = 0; i < n; i++)
        x[i]=burstTime[i];
    priority[n]=1;
    for(time=0;count!=n;time++)
    {
        smallest=n;
        for(i=0;i<n;i++)
        {
            if (arrivalTime[i]<=time&&priority[i]>priority[smallest] && burstTime[i] > 0)
                smallest = i;
        }
        burstTime[smallest]--;
        if (burstTime[smallest] == 0)
        {
            count++;
            end=time+1;
            completionTime[smallest]=end;
            waitingTime[smallest]=end-arrivalTime[smallest]-x[smallest];
            turnaroundTime[smallest]=end-arrivalTime[smallest];
        }
    }
    printf("PID\tpriority\t AT \t BT\t CT \t TAT\tWT\n");
    for (i = 0; i < n; i++)
    {
        printf("p%d\t\t%d\t%d\t%d\t%d\t%d\t%d\n",i + 1,priority[i],arrivalTime[i],x[i],completionTime[i],turnaroundTime[i],waitingTime[i]);
        avg = avg + waitingTime[i];
        tt = tt + turnaroundTime[i];
    }
    avg=avg/n;
    tt=tt/n;
    printf("\n\nAverage waiting time time =%f",avg);
    printf("Average turnaround time time =%f",tt);
}
