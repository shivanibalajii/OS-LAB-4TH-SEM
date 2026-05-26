#include <stdio.h>

int main() {
    int n, m, i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], request[n][m];
    int avail[m], finish[n];

    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter Request Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &request[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    for(i = 0; i < n; i++) {
        finish[i] = 0;
    }

    for(i = 0; i < n; i++) {

        if(finish[i] == 0) {

            for(j = 0; j < m; j++) {
                if(request[i][j] > avail[j])
                    break;
            }

            if(j == m) {

                for(k = 0; k < m; k++) {
                    avail[k] += alloc[i][k];
                }

                finish[i] = 1;
                i = -1; // Restart checking
            }
        }
    }

    int deadlock = 0;

    printf("\nDeadlocked Processes:\n");

    for(i = 0; i < n; i++) {
        if(finish[i] == 0) {
            printf("P%d ", i);
            deadlock = 1;
        }
    }

    if(deadlock == 0)
        printf("No Deadlock Detected");

    return 0;
}
