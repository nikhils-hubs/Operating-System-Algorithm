#include <stdio.h>
#include <stdlib.h> // for abs()

int main() {
    int i, j = 0, k, n, cp, cp1, mov = 0;
    int req[50], index[50], a[50];
    int min, mini;

    printf("Enter the current head position: ");
    scanf("%d", &cp);
    cp1 = cp;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the request order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    // SSTF Logic
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            index[i] = abs(cp - req[i]);
        }

        min = 9999;
        mini = -1;
        for (i = 0; i < n; i++) {
            if (req[i] != 999 && index[i] < min) {
                min = index[i];
                mini = i;
            }
        }

        a[j++] = req[mini];
        cp = req[mini]; // Move head
        req[mini] = 999; // Mark as visited
    }

    // Output sequence
    printf("\nSSTF Head Movement Sequence:\n");
    printf("%d", cp1);
    mov += abs(cp1 - a[0]);
    printf(" -> %d", a[0]);

    for (i = 1; i < n; i++) {
        mov += abs(a[i] - a[i - 1]);
        printf(" -> %d", a[i]);
    }

    printf("\n\nTotal head movement = %d\n", mov);
    return 0;
}
