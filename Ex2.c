#include <stdio.h>
#include <pthread.h>
void* routine(){
printf("test from threads \n");
printf("test from threads \n");
printf("Ending \n");
}
int main() {
    pthread_t t1,t2; //thread id
pthread_create(&t1,NULL,&routine,NULL);
pthread_create(&t2,NULL,&routine,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
}