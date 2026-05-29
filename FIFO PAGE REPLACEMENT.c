#include <stdio.h>

int main() {
    int pages[20], frames[10], n, f, i, j, k = 0, fault = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++) {
        found = 0;

        for(j = 0; j < f; j++)
            if(frames[j] == pages[i])
                found = 1;

        if(!found) {
            frames[k] = pages[i];
            k = (k + 1) % f;
            fault++;
        }
    }

    printf("Page Faults = %d", fault);

    return 0;
}
