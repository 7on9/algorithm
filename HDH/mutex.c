//
//  newfile.c
//  CoMiIc
//
//  Created by Ống Tre on 12/20/17.
//  Copyright © 2017 Nguyen Long. All rights reserved.
//

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
//#include <semaphore.h>

int val = 0;
//int produce = 2;
int i,j;
//sem_t s;
pthread_mutex_t mutex;

void *thread1(void *data)
{
    pthread_mutex_lock(&mutex);
    for (i = 1; i <= 5; i++)
    {
        printf("Tien trinh 1 : %d \n",++val);
        sleep(0.1);
    }
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

void *thread2(void *data)
{
    pthread_mutex_lock(&mutex);
    for (j = 1; j <= 5; j++)
    {
        printf("Tien trinh 2 : %d \n",--val);
        sleep(0.5);
    }
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main()
{
    pthread_t tt1,tt2;
    
    pthread_mutex_init(&mutex, NULL);
    
    pthread_create(&tt1,NULL,thread1,NULL);
    pthread_create(&tt2,NULL,thread2,NULL);
    
    pthread_join(tt1, NULL);
    pthread_join(tt2, NULL);
    return  0;
}
