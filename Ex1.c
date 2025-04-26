#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
int id = fork();
if (id < 0) {
printf("Fork failed.\n");
exit(1);
}
if (id == 0) {
// Child Process
printf("Child process started.\n");
for (int i = 0; i < 5; i++) {
    printf("Child loop: %d\n", i);
    sleep(1);
    }
    printf("Child process ended.\n");
    } else {
    // Parent Process
    wait(NULL); // Wait for child to finish
    printf("Parent process ended.\n");
    }
    return 0;
    }