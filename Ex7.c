#include <stdio.h>

int main() {
    int n, a[50], f, frame[50], j = 0, count = 0, hit;

    printf("Enter reference string length: ");
    scanf("%d", &n);

    printf("Enter reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames to -1
    for (int i = 0; i < f; i++)
        frame[i] = -1;

    printf("\nReference\tFrames\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t\t", a[i]);
        hit = 0;

        // Check if page is already in frame
        for (int k = 0; k < f; k++) {
            if (frame[k] == a[i]) {
                hit = 1;
                break;
            }
        }

        // If not in frame, insert using FIFO
        if (!hit) {
            frame[j] = a[i];
            j = (j + 1) % f;
            count++;
        }

        // Print current frame status
        for (int k = 0; k < f; k++) {
            if (frame[k] == -1)
                printf("-\t");
            else
                printf("%d\t", frame[k]);
        }

        if (hit)
            printf("Hit");
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", count);

    return 0;
}
