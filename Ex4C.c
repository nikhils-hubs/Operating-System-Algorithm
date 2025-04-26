#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct msg_buffer { long msg_type; char msg[100]; };
int main() {
int msgid = msgget(ftok("progfile", 65), 0666 | IPC_CREAT);
struct msg_buffer message = {1};
printf("Write Message: ");
fgets(message.msg, sizeof(message.msg), stdin);
msgsnd(msgid, &message, sizeof(message), 0);
printf("Sent: %s", message.msg);
msgrcv(msgid, &message, sizeof(message), 1, 0);
printf("Received: %s", message.msg);
msgctl(msgid, IPC_RMID, NULL);
return 0;
}