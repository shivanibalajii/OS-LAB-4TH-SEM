#include <stdio.h>

struct Process {
    int id, deadline, burst;
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

        printf("Enter Deadline: ");
        scanf("%d", &p[i].deadline);
    }

    // Sort by earliest deadline
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(p[i].deadline > p[j].deadline) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    printf("\nEarliest Deadline First Scheduling Order:\n");

    for(i = 0; i < n; i++) {
        printf("P%d ", p[i].id);
    }

    return 0;
}
