#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>
#define THREADS 4

int chopsticks_available = 5;
pthread_mutex_t mutex_lock;

void* eat(void* data){
    if(chopsticks_available>=2){
    pthread_mutex_lock(&mutex_lock);
    chopsticks_available = chopsticks_available-2;
    printf("Eating\n");
    }
    
    else{
        printf("Thinking\n");
    }
    chopsticks_available = chopsticks_available+2;
    pthread_mutex_unlock(&mutex_lock);
}

void main()
{
    pthread_t t1, t2, t3, t4;
    pthread_create(&t1, NULL, eat, NULL);
    pthread_create(&t2, NULL, eat, NULL);
    pthread_create(&t3, NULL, eat, NULL);
    pthread_create(&t4, NULL, eat, NULL);   
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_mutex_destroy(&mutex_lock);
}