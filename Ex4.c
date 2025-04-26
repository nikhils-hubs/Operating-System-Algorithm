#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
int main() {
int shmid;
char *shared_memory;
char buff[100];
// Create shared memory
shmid = shmget(2345, 1024, 0666 | IPC_CREAT);
printf("Shared memory key: %d\n", shmid);
// Attach to shared memory
shared_memory = (char*) shmat(shmid, NULL, 0);
printf("Attached at: %p\n", shared_memory);
// Input data from user
printf("Enter data to write to shared memory:\n");
read(0, buff, sizeof(buff));
strcpy(shared_memory, buff); // Write to shared memory
// Show data from shared memory
printf("You wrote: %s", shared_memory);
return 0;
}