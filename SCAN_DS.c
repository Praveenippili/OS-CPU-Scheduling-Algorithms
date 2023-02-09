#include<stdio.h>
int main(){
int n,header_moves,first,last,cur_pos,direction;
printf("enter first cylinder number:");
scanf("%d",&first);
printf("enter last cylinder number");
scanf("%d",&last);
printf("Enter current position of header");
scanf("%d",&cur_pos);
printf("Enter direction 0->left 1->right");
scanf("%d",&direction);
printf("enter no of requests:");
scanf("%d",&n);
int request[n];
int i;
header_moves=0;
int count=0;
for(i=0;i<n;i++){
printf("enter request %d :",i+1);
scanf("%d,",&request[i]);
}0
int min_pos,j,temp;
for(i=0;i<n;i++){
min_pos=i;
for(j=i+1;j<n;j++){
if(request[min_pos]>request[j]){
min_pos=j;
}
}
temp=request[i];
request[i]=request[min_pos];
request[min_pos]=temp;
}
printf("\n");
for(i=0;i<n;i++){
printf("%d,",request[i]);
}
printf("\n");
if(direction==0){ 
header_moves+=(cur_pos-first);// moving toward first cylinder
if(request[n-1]>cur_pos){ // check if there are any un covered cylinders in the request
header_moves+=(request[n-1]-first);
}
}
else{
header_moves+=(last-cur_pos);
if(request[0]<cur_pos){
header_moves+=(last-request[0]);
}
}
printf("\n no of head movements is:\t %d",header_moves);
}
