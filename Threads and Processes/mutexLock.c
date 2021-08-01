#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>
#define THREADS 4

int count = 0;
pthread_mutex_t mutex_lock;

void* increment(void* data){
    pthread_mutex_lock(&mutex_lock);
    count++;
    printf("Count: %d\n", count);
    pthread_mutex_unlock(&mutex_lock);
}

void* decrement(void* data){
    pthread_mutex_lock(&mutex_lock);
    count--;
    printf("Count: %d\n", count);
    pthread_mutex_unlock(&mutex_lock);
}

void main()
{
    pthread_t t1, t2, t3, t4;
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);
    pthread_create(&t3, NULL, decrement, NULL);
    pthread_create(&t4, NULL, decrement, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_mutex_destroy(&mutex_lock);
}