#include <stdio.h> 
  int main() 
{ 
  int n, pid[10],ari[10], bur[10], total = 0, i, j, small, temp, procs[100], k, waiting[10], finish[10]; 
  float tavg = 0.0, wavg = 0.0; 
  printf("ENTER THE NUMBER OF PROCESSES:"); 
  scanf("%d", & n); 
  for (i = 0; i < n; i++) 
  { 
    printf("ENTER THE PID , ARRIVAL TIME AND BURST TIME OF PROCESS:\t"); 
    scanf("%d %d %d",&pid[i],&ari[i],&bur[i]); 
    waiting[i] = 0; 
    total += bur[i]; 
  } 
  for (i = 0; i < n; i++) 
  { 
    for (j = i + 1; j < n; j++) 
    { 
      if (ari[i] > ari[j]) 
      { 
        temp = ari[i]; 
        ari[i] = ari[j]; 
        ari[j] = temp; 
        temp = bur[i]; 
        bur[i] = bur[j]; 
        bur[j] = temp; 
        temp=pid[i];
        pid[i]=pid[j];
        pid[j]=temp;
      } 
    } 
  } 
  for (i = 0; i < total; i++) 
  { 
    small = 3200; 
    for (j = 0; j < n; j++) 
    { 
      if ((bur[j] != 0) && (ari[j] <= i) && (bur[j] < small)) 
      { 
        small = bur[j]; 
        k = j; 
      } 
    } 
    bur[k]--; 
    procs[i] = k; 
  } 
  k = 0; 
  for (i = 0; i < total; i++) 
  { 
    for (j = 0; j < n; j++) 
    { 
      if (procs[i] == j) 
      { 
        finish[j] = i; 
        waiting[j]++; 
      } 
    } 
  } 
  printf("\nPID\tCT\tTAT\tWT\n");
  for (i = 0; i < n; i++) 
  { 
    printf("\np%d\t%d\t%d\t%d\n", pid[i], finish[i] + 1, (finish[i] - ari[i]) + 1, (((finish[i] + 1) - waiting[i]) - ari[i])); 
    wavg = wavg + (((finish[i] + 1) - waiting[i]) - ari[i]); 
    tavg = tavg + ((finish[i] - ari[i]) + 1); 
  } 
  printf("\n WAvG==>\t%f\n TAVG==>\t%f\n", (wavg / n), (tavg / n)); 
  return 0; 
}
