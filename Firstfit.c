#include<stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n)
{
	int i, j;
	int allocation[n],already_allocated[n];

	for(i = 0; i < n; i++)
	{
		allocation[i] = -1;
		already_allocated[i]=-1;
	}
	
	for (i = 0; i < n; i++)	 
	{
		for (j = 0; j < m; j++)	 
		{
			if ((blockSize[j] >= processSize[i]) && already_allocated[j]==-1)
			{
				allocation[i] = j;
				already_allocated[j]=0;
				blockSize[j] -= processSize[i];
				break; 
			}
		}
	}

	printf("\nProcess No.\tProcess Size\t\t\tBlock no.\n");
	for (i=0; i < n; i++)
	{
		printf(" %i\t\t\t", i+1);
		printf("%i\t\t\t\t", processSize[i]);
		if (allocation[i] != -1)
			printf("%i", allocation[i] + 1);
		else
			printf("Not Allocated");
		printf("\n");
	}
}

// Driver code
int main()
{
	int i,m,n,blockSize[m],processSize[n]; 
	
	printf("enter no of processes:\n");
	scanf("%d",&n);
	
	printf("enter no of blocks:\n");
	scanf("%d",&m);

	for(i=0;i<m;i++){
		printf("\nEnter %d process size:",i+1);
		scanf("%d",&processSize[i]);
	}
	
	for(i=0;i<n;i++){
		printf("\nenter %d block size:",i+1);
		scanf("%d",&blockSize[i]);
	}

	firstFit(blockSize, m, processSize, n);

	return 0 ;
}

