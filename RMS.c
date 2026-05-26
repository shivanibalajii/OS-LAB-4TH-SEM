#include <stdio.h>

struct Process {
    int id, period, burst;
};

int main() {
    int n, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);

        p[i].id = i + 1;

        printf("Enter Burst Time: ");
        scanf("%d", &p[i].burst);

        printf("Enter Period: ");
        scanf("%d", &p[i].period);
    }

    // Sort by period (smallest period = highest priority)
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(p[i].period > p[j].period) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    printf("\nRate Monotonic Scheduling Order:\n");

    for(i = 0; i < n; i++) {
        printf("P%d ", p[i].id);
    }

    return 0;
}
