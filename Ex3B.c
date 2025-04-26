#include <stdio.h>

int main() {
    int n, i, j, temp;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n], p[n]; // burst time, wait time, turnaround time, process ID
    float total_wt = 0, total_tat = 0;

    // Initialize wait times to 0
    for (i = 0; i < n; i++) wt[i] = 0;

    // Input burst times
    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

    // Sort by burst time (SJF)
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(bt[i] > bt[j]) {
                // Swap burst time
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                // Swap process ID accordingly
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }

    // Calculate WT and TAT
    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Output
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage WT = %.2f\nAverage TAT = %.2f\n", total_wt / n, total_tat / n);

    return 0;
}
