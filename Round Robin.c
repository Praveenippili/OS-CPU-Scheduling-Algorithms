//RR
#include<stdio.h>
int main()
{
	int i,n,x,total,at[10],bt[10],temp[10],tat[10],wt[10],time_quantum,counter,wt1=0,tat1=0;
	float avg_tat,avg_wt;
	printf("\nEnter no.of process:");
	scanf("%d",&n);
	x=n;
	printf("\nEnter Arrival Times:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&at[i]);
	}
	printf("\nEnter Burst Times:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
		temp[i]=bt[i];
	}
	printf("\nEnter Time Quantum:");
	scanf("%d",&time_quantum);
	printf("\nAT\tBT\tCT\tTAT\tWT");
	
	for(total=0,i=0;x!=0;)
	{
		if((temp[i]<=time_quantum)&&(temp[i]>0))
		{
			total=total+temp[i];
			temp[i]=0;
			counter=1;
		}
		else if(temp[i]>0)
		{
			total=total+time_quantum;
			temp[i]=temp[i]-time_quantum;
		}
		if(temp[i]==0 && counter==1)
		{
			x--;
			printf("\n P[%d] \t %d \t %d \t %d \t%d", i+1, bt[i],total, total-at[i], total-at[i]-bt[i]);  
			wt1 = wt1+total-at[i]-bt[i];  
			tat1 = tat1+total-at[i];  
			counter=0;
		}
		if(i==n-1)
		{
			i=0;
		}
		else if(at[i+1]<=total)
		{
			i++;
		}
		else
		{
			i=0;
		}
	}
	avg_wt=wt1*1.0/n;
	avg_tat=tat1*1.0/n;
	
	printf("\nAverage Waiting Time:%f",avg_wt);
	printf("\nAverage TotalAround Time:%f",avg_tat);
	return 0;
	
}
