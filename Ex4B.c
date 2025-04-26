#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
int fd[2], n;
char buff[100];
pipe(fd); // create pipe
pid_t p = fork();
if (p > 0) {
// Parent Process
close(fd[0]); // Close read end
printf("Parent: Sending message to child...\n");
write(fd[1], "My name is Nikhil Singh\n", 23);
close(fd[1]); // Close write end after sending
wait(NULL); // Wait for child to finish
} else {
// Child Process
close(fd[1]); // Close write end
printf("Child: Received message -\n");
n = read(fd[0], buff, sizeof(buff));
write(1, buff, n); // Print to stdout
close(fd[0]); // Close read end after reading
}
return 0;
}