#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>
#define THREADS 4

/*
1.
void* f(void* data){
    printf("Hello from a thread!\n");
    pthread_exit(NULL);
}

int main()
{   int t;
    pthread_t threads[THREADS];
    for(t = 0; t<THREADS; t++)
        pthread_create(&threads[t], NULL, f, NULL);
    pthread_exit(NULL);
    return 0;
}

2.
void* say_hello(void* data){
    char *string;
    int i =0;
    string = (char*)data;
    for(int i=0; i<2; i++){
        printf("%s\n", string);
        sleep(1);
    }
    pthread_exit(NULL);
}

void main()
{
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, say_hello, "hello from 1");
    pthread_create(&thread2, NULL, say_hello, "hello from 2");
    pthread_join(t1, NULL);
}

3.
int count = 0;

void* increment(void* data){
    printf("Before increment: count: %d\n", count);
    count++;
    printf("After increment: count: %d\n", count);
}

void* decrement(void* data){
    printf("Before decrement: count: %d\n", count);
    count--;
    printf("After decrement: count: %d\n", count);
}

void main()
{
    pthread_t thread1, thread2, thread3, thread4;
    
    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, increment, NULL);
    pthread_create(&thread3, NULL, decrement, NULL);
    pthread_create(&thread4, NULL, decrement, NULL);
    
    pthread_join(thread1, NULL);
}
*/