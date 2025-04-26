#include <stdio.h>
int main() {
int n, tq, bt[20], rt[20], wt[20], tat[20], time = 0;
float total_wt = 0, total_tat = 0;
// Input number of processes and time quantum
printf("Enter total number of processes: ");
scanf("%d", &n);
printf("Enter burst time for each process:\n");
for (int i = 0; i < n; i++) {
printf("P[%d]: ", i + 1);
scanf("%d", &bt[i]);
rt[i] = bt[i]; // Initialize remaining burst time
wt[i] = 0; // Initialize waiting time
}
// Input Time Quantum
printf("Enter Time Quantum: ");
scanf("%d", &tq);
// Round Robin Scheduling
while (1) {
int done = 1;
for (int i = 0; i < n; i++) {
if (rt[i] > 0) {
done = 0;
int time_slice = (rt[i] > tq) ? tq : rt[i];
time += time_slice;
rt[i] -= time_slice;
if (rt[i] == 0) wt[i] = time - bt[i]; // Calculate waiting time when process completes
}
}
if (done) break;
}
// Calculate Turnaround Time
for (int i = 0; i < n; i++) {
tat[i] = bt[i] + wt[i];
total_wt += wt[i];
total_tat += tat[i];
}
// Display Results
printf("\nProc\tBT\tWT\tTAT");
for (int i = 0; i < n; i++) {
printf("\nP[%d]\t%d\t%d\t%d", i + 1, bt[i], wt[i], tat[i]);
}
printf("\n\nAverage Waiting Time: %.2f", total_wt / n);
printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
return  0;
}