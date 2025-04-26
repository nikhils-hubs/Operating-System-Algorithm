#include <stdio.h>
#define true 1
#define false 0

int req[10], m, n;
int available[10], allocation[10][10], max[10][10], need[10][10];
int work[10], finish[10], maxres[10], safe[10];

// Function to find the next process that can execute
int find() {
    for (int i = 0; i < n; i++) {
        if (finish[i] == false) {
            int j;
            for (j = 0; j < m; j++) {
                if (need[i][j] > work[j])
                    break;
            }
            if (j == m) {
                finish[i] = true;
                return i;
            }
        }
    }
    return -1;
}

// Function to check if the system is in a safe state
int issafe() {
    int i, j, k = 0, cnt = n;

    for (j = 0; j < m; j++)
        work[j] = available[j];

    for (i = 0; i < n; i++)
        finish[i] = false;

    while (cnt > 0) {
        int idx = find();
        if (idx == -1) {
            printf("\nThe system is in an **unsafe state** ❌\n");
            return 0;
        }
        for (j = 0; j < m; j++)
            work[j] += allocation[idx][j];

        safe[k++] = idx;
        cnt--;
    }

    printf("\n✅ The system is in a **safe state**.\nSafe Sequence: ");
    for (i = 0; i < n; i++)
        printf("P%d ", safe[i]);
    printf("\n");

    return 1;
}

int main() {
    int i, j, sum;

    printf("Enter the number of processes and the number of resources:\n");
    scanf("%d %d", &n, &m);

    printf("Enter maximum instances of each resource:\n");
    for (j = 0; j < m; j++) {
        scanf("%d", &maxres[j]);
        available[j] = maxres[j]; // Initially all are available
    }

    printf("Enter the Allocation Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the Max Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Calculate Available Resources
    for (j = 0; j < m; j++) {
        sum = 0;
        for (i = 0; i < n; i++) {
            sum += allocation[i][j];
        }
        available[j] = maxres[j] - sum;
    }

    // Display Need Matrix
    printf("\nNeed Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // Check for safety
    issafe();

    return 0;
}
