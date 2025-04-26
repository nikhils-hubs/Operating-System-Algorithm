#include <stdio.h>
#include <stdlib.h> // For abs()

int main() {
    int i, n, req[50], mov = 0, cp;

    printf("Enter the current head position: ");
    scanf("%d", &cp);

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the request order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    // Head movement from current position to first request
    mov += abs(cp - req[0]);
    printf("\nHead movement: %d", cp);

    // Print first move
    printf(" -> %d", req[0]);

    // Head movement for remaining requests
    for (i = 1; i < n; i++) {
        mov += abs(req[i] - req[i - 1]);
        printf(" -> %d", req[i]);
    }

    printf("\n\nTotal head movement = %d\n", mov);
    return 0;
}
