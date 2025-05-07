#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3

void* thread_function(void* arg) {
    int thread_id = *((int*)arg);
    for (int i = 0; i < 5; i++) {
        printf("Thread %d: iteration %d\n", thread_id, i);
        sleep(1); // Sleep for 1 second
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int rc;

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i + 1;
        rc = pthread_create(&threads[i], NULL, thread_function, (void*)&thread_ids[i]);
        if (rc) {
            printf("Error: pthread_create() failed with code %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed.\n");
    return 0;
}
