#include <stdio.h>

#define N 5

void philosopher(int n) {
    printf("\nPhilosopher %d is Thinking", n);

    printf("\nPhilosopher %d takes Fork %d and %d",
           n, n, (n + 1) % N);

    printf("\nPhilosopher %d is Eating", n);

    printf("\nPhilosopher %d puts down Fork %d and %d",
           n, n, (n + 1) % N);

    printf("\nPhilosopher %d is Thinking again\n", n);
}

int main() {
    int i;

    for(i = 0; i < N; i++) {
        philosopher(i);
    }

    return 0;
}
