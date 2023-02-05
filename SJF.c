//SJF NP
#include<stdio.h>
int main()
{
	int at[10],bt[10],ct[10],tat[10],wt[10],i,j,temp=0,n,pos,p,q;
	float avg_tat=0,avg_wt=0;
	//Taking Input from User:
	printf("Enter no.of process:");
	scanf("%d",&n);
	printf("\nEnter Arrival Time of processes:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&at[i]);
	}
	printf("\nEnter Burst Time of processes:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}
	//Sorting AT and BT based on Arrival time
	for(p=0;p<n;p++)
	{
		pos=p;
		for(q=p+1;q<n;q++)
		{
			if(at[p]>at[q])
			{
				temp=at[p];
				at[p]=at[q];
				at[q]=temp;
				
				pos=bt[p];
				bt[p]=bt[q];
				bt[q]=pos;
			}
		}
	}
	//Calculating Completion Time:
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			ct[0]=at[0]+bt[0];//CT for First Process
		}
		else
		{
			if(ct[i-1]>=at[i])//CT for remaining process-if Processes came within the Completion time
			{
				pos=i;
				for(j=i+1;j<n;j++)//sorting burst time and AT  
				{
					if(bt[i]>bt[j])//searching for sortest job
					{
						temp=bt[i];  
						bt[i]=bt[j];//swaping 
						bt[j]=temp;
						
						pos=at[i];
						at[i]=at[j];
						at[j]=pos;
					}
				}
				ct[i]=ct[i-1]+bt[i];//Finding CT[i-th process]
			}
			else//CT for remaining processes if that particular process is not arrived within the CT
			{
				pos=i;
				for(j=i+1;j<n;j++)//sorting BT and AT but we sort based on AT 
				{
					if(at[i]>at[j])//searching for sortest AT 
					{
						temp=bt[i];
						bt[i]=bt[j];//swaping
						bt[j]=temp;
						
						pos=at[i];
						at[i]=at[j];
						at[j]=pos;
						
					}
				}
				ct[i]=ct[i-1]+bt[i];
			}
		}
    }

	//Calculating TAT and WT:
	for(i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
		avg_tat+=tat[i];
		avg_wt+=wt[i];
	}
	avg_tat=avg_tat/n;
	avg_wt=avg_wt/n;
	//Printing Output
	printf("\nAT\tBT\tCT\tTAT\tWT");
	printf("\n...............................................");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t%d\t%d",at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	//printing Avg.TAT and Avg.WT:
	printf("\nAverage Total Around Time= %f",avg_tat);
	printf("\nAverage Waiting Time= %f",avg_wt);
}
	
