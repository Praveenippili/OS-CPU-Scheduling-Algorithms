#include<stdio.h>
int main(){
    int min, rs[25], m[10], count[10], flag[25], n, f, pf=0, next=1;
    printf("\n Enter the length of the reference string -- ");
    scanf("%d", &n);

    printf("\nEnter the reference string -- ");
    for(int i=0; i<n; i++){
        scanf("%d", &rs[i]);
        flag[i] = 0;
    }

    printf("\nEnter no. of frames -- ");
    scanf("%d", &f);
    for(int i=0; i<f; i++){
        m[i] = -1;
        count[i] = 0;
    }    

    printf("\nThe page replacement process is :- \n");

    for(int i=0; i<n; i++){
        for(int j=0; j<f; j++){
            // page hit
            if(m[j]==rs[i]){
                flag[i] = 1;
                count[j] = next++;
            }
        }
        // page fault
        if(flag[i]==0){
            if(i<f){
                m[i] = rs[i];
                count[i] = next;
                next++;
            }
            else{
                min=0;
                for(int j=1; j<f; j++)
                    if(count[min]>count[j])
                        min = j;
                m[min] = rs[i];
                count[min] = next++;
            }
            pf++;
        }
        for(int j=0; j<f; j++)
            printf("%d\t", m[j]);
        if(flag[i]==0)
            printf("PF =%d", pf);
        printf("\n");
    }
    return 0;
}