#include <stdio.h>
#include <stdio.h>
int main() {
int n, bt[20], wt[20] = {0}, tat[20], i;
float avwt = 0, avtat = 0;
printf("Enter number of processes: ");
scanf("%d", &n);
printf("Enter burst times:\n");
for(i = 0; i < n; i++) scanf("%d", &bt[i]);
for(i = 1; i < n; i++) wt[i] = wt[i - 1] + bt[i - 1];
printf("\nProcess\tBT\tWT\tTAT\n");
for(i = 0; i < n; i++) {
tat[i] = bt[i] + wt[i];
avwt += wt[i];
avtat += tat[i];
printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
}
printf("\nAvg WT = %.2f\nAvg TAT = %.2f\n", avwt / n, avtat / n);
return 0;
}