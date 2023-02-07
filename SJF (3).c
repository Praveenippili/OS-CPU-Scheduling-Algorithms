#include<stdio.h>
int main(){
	int n;
	printf("Enter number of processes:");
	scanf("%d",&n);
	int at[n],bt[n],pid[n];
	int i,j,temp;
	for(i=0;i<n;i++){
		printf("Enter AT and BT of p%d:",i+1);
		scanf("%d %d",&at[i],&bt[i]);
		pid[i]=i+1;
	}
	for(i=0;i<=n;i++){
		for(j=i+1;j<n;j++){
			if(bt[i]>bt[j]){
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
				temp=at[i];
				at[i]=at[j];
				at[j]=temp;
				temp=pid[i];
				pid[i]=pid[j];
				pid[j]=temp;
			}
		}
	}
	//print(arrival,burst);
	int count=0;
	int CT[n],completed[n];
	int currtime=0;	
	for(i=0;i<n;i++){
		completed[i]=0;
	}
	while(1){
		if(count==n){
			break;
		}
		else{
			int bin=0;
		for(i=0;i<n;i++){
			if(completed[i]!=1&&at[i]<=currtime){
				currtime+=bt[i];
				CT[i]=currtime;
				completed[i]=1;
				count++;
				bin=1;
				break;
			}
			}
		if(bin==0){
			currtime++;
		}	
		}
		}
		int TAT[15],WT[15];
		float tat=0,wt=0;
	    printf("\nPid|AT| BT|CT |TAT |WT\n");
	for(i=0;i<n;i++){
		TAT[i]=CT[i]-at[i];
		WT[i]=TAT[i]-bt[i];
		tat=tat+TAT[i];
		wt=wt+WT[i];
		printf("\np%d | %d | %d | %d | %d | %d\n",pid[i],at[i],bt[i],CT[i],TAT[i],WT[i]);
	}
	float Av_tat,Av_wt;
	Av_tat=tat/n;
	Av_wt=wt/n;
	printf("Average Turn Around Time:%.2f\n",Av_tat);
	printf("Average Waiting Time:%.2f",Av_wt);
}
