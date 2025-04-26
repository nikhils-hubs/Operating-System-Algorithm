#include <stdio.h>
void print(int f, int fr[]) {
for (int i = 0; i < f; i++) printf("%d\t"
, fr[i]);
printf("\n");
}
int main() {
int n, p[50], f, fr[10], freq[10] = {0}, count = 0, used = 0, rep, min;
printf("Enter no. of pages: "); scanf("%d"
, &n);
printf("Enter page refs: "); for (int i = 0; i < n; i++) scanf("%d"
, &p[i]);
printf("Enter no. of frames: "); scanf("%d"
, &f);
for (int i = 0; i < f; i++) fr[i] = -1;
printf("Page\tFrames\n");
for (int i = 0; i < n; i++) {
printf("%d\t"
, p[i]);
int found = 0;
for (int j = 0; j < f; j++) {
if (fr[j] == p[i]) { freq[j]++; found = 1; printf("No replace\n"); break; }
}
if (!found) {
if (used < f) {
fr[used] = p[i]; freq[used++] = 1;
} else {
rep = 0; min = freq[0];
for (int j = 1; j < f; j++) if (freq[j] < min) { min = freq[j]; rep = j; }
fr[rep] = p[i]; freq[rep] = 1;
}
count++; print(f, fr);
}
}
printf("Faults = %d\nRate = %.2f\n"
, count, (float)count/n);
return 0;
}