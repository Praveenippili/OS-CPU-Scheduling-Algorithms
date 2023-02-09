#include<stdio.h>
struct process
{
int allocation[3];
int max[3];
int need[3];
int finish;
}
p[10];
int main()
{
	int n,i,j,avail[3],avail1[3],flag,count=0,sequence[10],k=0;
	printf("\nEnter the number of process:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
	printf("\nEnter the %dth process allocated resources:",i); 
	scanf("%d%d%d",&p[i].allocation[0],&p[i].allocation[1],&p[i].allocation[2]);
	printf("\nEnter the %dth process maximum resources:",i);
	scanf("%d%d%d",&p[i].max[0],&p[i].max[1],&p[i].max[2]);
	p[i].finish=0;
    p[i].need[0]=p[i].max[0]-p[i].allocation[0];
    p[i].need[1]=p[i].max[1]-p[i].allocation[1];
    p[i].need[2]=p[i].max[2]-p[i].allocation[2];
    }
    printf("\nEnter the available resources:");  
    scanf("%d%d%d",&avail[0],&avail[1],&avail[2]);
    for(i=0;i<3;i++)
    avail1[i]=avail[i];
    while(count!=n)
    {
    	count=0;
		for(i=0;i<n;i++)
		{
		flag=1;
        if(p[i].finish==0)
        if(p[i].need[0]<=avail1[0])
        if(p[i].need[1]<=avail1[1])
        if(p[i].need[2]<=avail1[2])
        {
		for(j=0;j<3;j++)
		avail1[j]+=p[i].allocation[j]; 
        p[i].finish=1;
        flag=0;
        }
        if(flag==1)
		count++;
		}
	}
	count=0;
	for(i=0;i<n;i++)
	if(p[i].finish==1)
	count++;
	printf("\n The safe sequence is:\t");
	if(count==n)
	for(i=0;i<k;i++)
	printf("%d\n",sequence[i]);
	else
	printf("SYSTEM IS NOT IN A SAFE STATE \n\n");
	return 0;
}
