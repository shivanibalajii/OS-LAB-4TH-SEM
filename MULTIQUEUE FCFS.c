 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Process {
    char name[20];
    int arrivalTime;
    int burstTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
};

void fcfs(struct Process p[], int n) {
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < p[i].arrivalTime) {
            time = p[i].arrivalTime;
        }
        time += p[i].burstTime;
        p[i].completionTime = time;
        p[i].turnaroundTime = p[i].completionTime - p[i].arrivalTime;
        p[i].waitingTime = p[i].turnaroundTime - p[i].burstTime;
    }
}

void display(struct Process p[], int n, char type[]) {
    printf("\n%s Processes:\n", type);
    printf("Name\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n",
               p[i].name,
               p[i].arrivalTime,
               p[i].burstTime,
               p[i].completionTime,
               p[i].turnaroundTime,
               p[i].waitingTime);
    }
}

int main() {
    int sysCount, userCount;

    printf("Enter number of system processes: ");
    scanf("%d", &sysCount);
    struct Process sys[sysCount];
    for (int i = 0; i < sysCount; i++) {
        printf("Enter name, arrival time, burst time for system process %d: ", i + 1);
        scanf("%s %d %d", sys[i].name, &sys[i].arrivalTime, &sys[i].burstTime);
    }

    printf("Enter number of user processes: ");
    scanf("%d", &userCount);
    struct Process user[userCount];
    for (int i = 0; i < userCount; i++) {
        printf("Enter name, arrival time, burst time for user process %d: ", i + 1);
        scanf("%s %d %d", user[i].name, &user[i].arrivalTime, &user[i].burstTime);
    }

    fcfs(sys, sysCount);
    fcfs(user, userCount);

    display(sys, sysCount, "System");
    display(user, userCount, "User");

    printf("\nScheduling Order:\n");
    for (int i = 0; i < sysCount; i++) {
        printf("%s -> ", sys[i].name);
    }
    for (int i = 0; i < userCount; i++) {
        printf("%s -> ", user[i].name);
    }
    printf("End\n");

    return 0;
}
