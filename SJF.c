#include <stdio.h>

int main() {
    int choice;
    printf("Choose Scheduling:\n1. Non-Preemptive SJF\n2. Preemptive SJF\n");
    scanf("%d",&choice);

    switch(choice) {
        case 1: {
            //non preemptive
            int n = 4;
            int pid[] = {1,2,3,4};
            int at[]  = {0,4,4,8};
            int bt[]  = {6,10,4,3};
            int ct[4], tat[4], wt[4], rt[4], start[4];
            int done[4] = {0};
            int time=0, completed=0;

            for(int i=0;i<n;i++) start[i] = -1;

            while(completed<n) {
                int idx=-1, minBT=9999;
                for(int i=0;i<n;i++) {
                    if(at[i]<=time && !done[i]) {
                        if(bt[i]<minBT) {
                            minBT=bt[i]; idx=i;
                        }
                    }
                }
                if(idx!=-1) {
                    if(start[idx]==-1) start[idx]=time;
                    time += bt[idx];
                    ct[idx]=time;
                    tat[idx]=ct[idx]-at[idx];
                    wt[idx]=tat[idx]-bt[idx];
                    rt[idx]=start[idx]-at[idx];
                    done[idx]=1;
                    completed++;
                } else time++;
            }

            printf("\nNon-Preemptive SJF:\n");
            printf("PID AT BT CT TAT WT RT\n");
            for(int i=0;i<n;i++)
                printf("P%d  %d  %d  %d  %d   %d  %d\n",
                       pid[i],at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
            break;
        }

        case 2: {
            // preemptive
            int n = 4;
            int pid[] = {1,2,3,4};
            int at[]  = {0,8,3,5};
            int bt[]  = {7,3,2,6};
            int ct[4], tat[4], wt[4], rt[4], start[4];
            int rem[4], done[4]={0};
            int time=0, completed=0;

            for(int i=0;i<n;i++) { rem[i]=bt[i]; start[i]=-1; }

            while(completed<n) {
                int idx=-1, minBT=9999;
                for(int i=0;i<n;i++) {
                    if(at[i]<=time && !done[i]) {
                        if(rem[i]<minBT) { minBT=rem[i]; idx=i; }
                    }
                }
                if(idx!=-1) {
                    if(start[idx]==-1) start[idx]=time;
                    rem[idx]--; time++;
                    if(rem[idx]==0) {
                        ct[idx]=time;
                        tat[idx]=ct[idx]-at[idx];
                        wt[idx]=tat[idx]-bt[idx];
                        rt[idx]=start[idx]-at[idx];
                        done[idx]=1; completed++;
                    }
                } else time++;
            }

            printf("\nPreemptive SJF:\n");
            printf("PID AT BT CT TAT WT RT\n");
            for(int i=0;i<n;i++)
                printf("P%d  %d  %d  %d  %d   %d  %d\n",
                       pid[i],at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
            break;
        }

        default: printf("Invalid choice\n");
    }
    return 0;
}
