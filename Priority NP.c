#include<stdio.h>
#include<stdlib.h>
void function1();
void function2();
void display();
int at[10],bt[10],ct[10],tat[10],wt[10],pri[10],i,j,temp,n,p,q,pos,pos1,pos2;
float avg_tat=0,avg_wt=0;
int prinum;
int main()
{
	//Taking Input from User:
	printf("Enter no.of process:");
	scanf("%d",&n);
	printf("\nEnter Priorities of processes:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&pri[i]);
	}
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
	//sorting based on arrival times
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
	//taking input from user that which type of case you want to implement from priority queue
	while(1){
	printf("\nEnter 0 if(Low number having high priority (or) High nuber having low priority)");
	printf("\nEnter 1 if(high number having high priority (or) Low number having low priority)");
	printf("\nEnter 2 for required answer:");
	printf("\nEnter 3 for Exit");
	printf("\nEnter case of priority:");
	scanf("%d",&prinum);
	switch(prinum)
	{
		case 0:function1();
			break;
		case 1:function2();
			   break;
		case 2:display();
			   break;
		case 3:exit(0);
		default:"Choose correct option!!!";
	}
	}
}
//Low number having high priority case:
void function1()
{
	//Calculating CT
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			ct[0]=at[0]+bt[0];//for first process calculating CT
		}
		else
		{
			for(j=i+1;j<n;j++)
			{
				pos1=i;
				pos2=i;
				if(pri[j]<pri[i])//Swaping the inputs based on the priority of the process
				{
					temp=pri[i];
					pri[i]=pri[j];
					pri[j]=temp;
					
					pos1=at[i];
					at[i]=at[j];
					at[j]=pos1;
					
					pos2=bt[i];
					bt[i]=bt[j];
					bt[j]=pos2;
				}
			}
			if(ct[i-1]>at[i])//completion time for other processes
			{
				ct[i]=ct[i-1]+bt[i];
			}
			else
			{
				for(j=i+1;j<n;j++)
				{
					pos1=i;
					pos2=i;
					if(at[j]<at[i])
					{
						temp=pri[i];
						pri[i]=pri[j];
						pri[j]=temp;
						
						pos1=at[i];
						at[i]=at[j];
						at[j]=pos1;
						
						pos2=bt[i];
						bt[i]=bt[j];
						bt[j]=pos2;
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
}
	
void function2()
{
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			ct[0]=at[0]+bt[0];
		}
		else
		{
			for(j=i+1;j<n;j++)
			{
				pos1=i;
				pos2=i;
				if(pri[j]>pri[i])
				{
					temp=pri[i];
					pri[i]=pri[j];
					pri[j]=temp;
					
					pos1=at[i];
					at[i]=at[j];
					at[j]=pos1;
					
					pos2=bt[i];
					bt[i]=bt[j];
					bt[j]=pos2;
				}
			}
			if(ct[i-1]>at[i])
			{
				ct[i]=ct[i-1]+bt[i];
			}
			else
			{
				for(j=i+1;j<n;j++)
				{
					pos1=i;
					pos2=i;
					if(at[j]<at[i])
					{
						temp=pri[i];
						pri[i]=pri[j];
						pri[j]=temp;
						
						pos1=at[i];
						at[i]=at[j];
						at[j]=pos1;
						
						pos2=bt[i];
						bt[i]=bt[j];
						bt[j]=pos2;
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
	
}
void display()
{
	//Printing Output
	printf("\nPRI\tAT\tBT\tCT\tTAT\tWT");
	printf("\n...............................................");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t%d\t%d\t%d",pri[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	//printing Avg.TAT and Avg.WT:
	printf("\nAverage Total Around Time= %f",avg_tat);
	printf("\nAverage Waiting Time= %f",avg_wt);
	printf("\n***********************************************************");
}
