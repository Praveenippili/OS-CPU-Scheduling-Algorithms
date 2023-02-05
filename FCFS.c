//FCFS
#include<stdio.h>
#include<conio.h>
int main()
{
	int at[15],bt[15],pr[15];
	int p,i,j;
	//taking input
	printf("Enter number of processes:");
	scanf("%d",&p);
	for(i=0;i<p;i++)
	{
		scanf("%d",&pr[i]);
	}
	for(i=1;i<p+1;i++)
	{
	   printf("Enter AT and BT of p%d:",i);
	   scanf("%d %d",&at[i],&bt[i]);
	}

	//sorting AT and BT and Process ID
	int temp,temp1,temp2;
	for(i=0;i<p;i++){
		for(j=i+1;j<p-1;j++){
			if(at[i]>at[j]){
				
					
				temp2=pr[i];
				pr[i]=pr[j];
				pr[j]=temp2;
				
				temp=at[i];
				at[i]=at[j];
				at[j]=temp;
				
				temp1=bt[i];
				bt[i]=bt[j];
				bt[j]=temp1;
			
			}
		}
	}
	printf("\nAT | BT\n");   
	for(i=1;i<=p;i++){
		printf("\n%d | %d\n",at[i],bt[i]);
	}
	int CT[15],check=0;
	for(i=1;i<=p;i++){
		if(check==0)
		{
			CT[i]=at[i]+bt[i];
			check=check+1;
		}
		else
		{
			if(CT[i-1]<at[i])
			{
				CT[i]=CT[i-1]+bt[i]+(at[i]-CT[i-1]);
			}
			else
			{
				CT[i]=CT[i-1]+bt[i];
			}
		}
	}
	int TAT[15],WT[15];
	printf("\nAT| BT|CT |TAT |WT\n");
	for(i=1;i<=p;i++){
		TAT[i]=CT[i]-at[i];
		WT[i]=TAT[i]-bt[i];
		printf("\n%d | %d | %d | %d | %d\n",at[i],bt[i],CT[i],TAT[i],WT[i]);
	}
	float tat=0,wt=0;
	for(i=1;i<=p;i++)
	{
		tat=tat+TAT[i];
		wt=wt+WT[i];
	}
	float Av_tat,Av_wt;
	Av_tat=tat/p;
	Av_wt=wt/p;
	printf("Average Turn Around Time:%.2f\n",Av_tat);
	printf("Average Waiting Time:%.2f",Av_wt);
}
