#include <stdio.h>

struct Process {
    int pid;
    int bt;
    int rt;
    int wt;
    int tat;
};

int main() {
    int n = 5, quantum, time = 0, remain = 5;
    struct Process p[5];

    printf("Enter Burst Time for 5 processes:\n");
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Process %d Burst Time: ", p[i].pid);
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].wt = 0;
        p[i].tat = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    int i = 0;
    while (remain != 0) {
        if (p[i].rt > 0) {
            if (p[i].rt <= quantum) {
                time += p[i].rt;
                p[i].rt = 0;
                p[i].tat = time;
                p[i].wt = p[i].tat - p[i].bt;
                remain--;
            } else {
                p[i].rt -= quantum;
                time += quantum;
            }
        }
        i = (i + 1) % n;
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n",
               p[i].pid, p[i].bt, p[i].wt, p[i].tat);
    }

    float avgWT = 0, avgTAT = 0;
    for (int i = 0; i < n; i++) {
        avgWT += p[i].wt;
        avgTAT += p[i].tat;
    }
    avgWT /= n;
    avgTAT /= n;

    printf("\nAverage Waiting Time: %.2f", avgWT);
    printf("\nAverage Turnaround Time: %.2f\n", avgTAT);

    return 0;
}
