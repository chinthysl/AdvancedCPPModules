#include <pthread.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>

using namespace std;


pthread_mutex_t mutex;
pthread_cond_t cond;

int buffer[100];

int loops = 5;
int length = 0;



void *producer(void *arg) {
    int i;
    while(length<99)
    {
          for (i = 0; i < loops; i++) 
          {
              pthread_mutex_lock(&mutex);
              buffer[length++] = i;
              cout<<"producer length "<< length <<endl;
              pthread_cond_signal(&cond);
              pthread_mutex_unlock(&mutex);
          }
          usleep(1);
    }
}


void *consumer(void *arg) {
    int i;

    while(1)
    {
          for (i = 0; i < loops; i++) 
          {
              pthread_mutex_lock(&mutex);
              while(length == 0) 
              {
                cout<< " consumer waiting..."<< endl;
                pthread_cond_wait(&cond, &mutex);
              }

              --length;
              cout<< "Consumer "<< length << endl;
              pthread_mutex_unlock(&mutex);
          }
    }
}






int main(int argc, char *argv[])
{

    pthread_mutex_init(&mutex, 0);
    pthread_cond_init(&cond, 0);

    pthread_t pThread, cThread;
    pthread_create(&pThread, 0, producer, 0);
    pthread_create(&cThread, 0, consumer, 0);
    pthread_join(pThread, NULL);

    usleep(5);
    //pthread_join(cThread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}