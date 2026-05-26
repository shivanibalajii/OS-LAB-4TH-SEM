#include <stdio.h>

int main() {
    int n, i;
    int burst[10], share[10];
    int total = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);

        printf("Enter Burst Time: ");
        scanf("%d", &burst[i]);

        printf("Enter CPU Share: ");
        scanf("%d", &share[i]);

        total += share[i];
    }

    printf("\nProportional Scheduling:\n");

    for(i = 0; i < n; i++) {
        float cpu_percent = (share[i] * 100.0) / total;

        printf("P%d gets %.2f%% CPU time\n", i + 1, cpu_percent);
    }

    return 0;
}
