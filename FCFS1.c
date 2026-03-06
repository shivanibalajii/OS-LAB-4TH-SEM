#include <stdio.h>

struct Process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
};

int main() {
    int n = 4;
    struct Process p[4] = {
        {1, 0, 7, 0, 0, 0, 0},
        {2, 8, 3, 0, 0, 0, 0},
        {3, 3, 4, 0, 0, 0, 0},
        {4, 5, 6, 0, 0, 0, 0}
    };

    // Sort by Arrival Time (FCFS rule)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < p[i].at) {
            time = p[i].at; // CPU idle until process arrives
        }
        time += p[i].bt;
        p[i].ct = time;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        p[i].rt = p[i].wt; // In FCFS, RT = WT
    }

    printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].tat, p[i].wt, p[i].rt);
    }

    return 0;
}
