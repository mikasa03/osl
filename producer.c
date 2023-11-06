#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#define MaxItems 5 // Maximum items a producer can produce or a consumer can consume
#define BufferSize 5 // Size of the buffer

int buffer[BufferSize];
sem_t empty, full;
pthread_mutex_t mutex;
int in=0;
int out=0;

void* producer(void * arg)
{
    
    for(int i=0; i< MaxItems; i++)
    {
        int item= rand();
        
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        
        buffer[in]=item;
        printf("produced %d",item);
        printf("\n\n");
        in= (in+1)%BufferSize;
        
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        sleep(1);
        
    }
}

void* consumer (void* arg)
{
    for(int i=0;i<MaxItems;i++)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        
        int item=buffer[out];
        printf("Consumed %d",item);
        printf("\n\n");
        out=(out+1)%BufferSize;
        
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main()
{
    pthread_t pid, cid;
    sem_init(&empty, 0, BufferSize);
    sem_init(&full,0,0);
    
    pthread_create(&pid, NULL,producer, NULL);
    pthread_create(&cid, NULL, consumer,NULL);
    
    pthread_join(pid,NULL);
    pthread_join(cid,NULL);
    
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
    
    return 0;
    
}