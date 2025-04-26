#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> // for sleep()

#define NUM_PHILOSOPHERS 5

void* dine(void* num);

pthread_t philosopher[NUM_PHILOSOPHERS];
pthread_mutex_t chopstick[NUM_PHILOSOPHERS];

int main() {
    int i;
    int* args;

    // Initialize mutexes for chopsticks
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        if (pthread_mutex_init(&chopstick[i], NULL) != 0) {
            printf("Mutex init failed\n");
            exit(1);
        }
    }

    // Create philosopher threads
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        args = malloc(sizeof(int));
        *args = i;
        if (pthread_create(&philosopher[i], NULL, dine, args) != 0) {
            printf("Thread creation failed\n");
            exit(1);
        }
    }

    // Join all threads
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosopher[i], NULL);
    }

    // Destroy mutexes
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&chopstick[i]);
    }

    return 0;
}

void* dine(void* num) {
    int id = *(int*)num;
    free(num); // Free dynamically allocated memory

    printf("Philosopher %d is thinking\n", id);

    pthread_mutex_lock(&chopstick[id]);
    pthread_mutex_lock(&chopstick[(id + 1) % NUM_PHILOSOPHERS]);

    printf("Philosopher %d is eating\n", id);
    sleep(2);

    pthread_mutex_unlock(&chopstick[id]);
    pthread_mutex_unlock(&chopstick[(id + 1) % NUM_PHILOSOPHERS]);

    printf("Philosopher %d finished eating\n", id);
    return NULL;
}
