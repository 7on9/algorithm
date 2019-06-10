#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>

int produce = 2;
int i;
sem_t sem;

void *sd()
{
    while(1)
    {
        sem_wait(&sem);
        printf("SU DUNG - San pham con lai : %d \n",--produce);
        sleep(1);
    }
    pthread_exit(NULL);
}
void *sx()
{
    for(i = 1 ;;i++)
    {
        printf("SAN XUAT - San pham con lai : %d \n",++produce);
        sleep(3);
        sem_post(&sem);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t tsx,tsd;
    
    sem_init(&sem, 0, 0);
    pthread_create(&tsd, NULL, sd, NULL);
    pthread_create(&tsx, NULL, sx, NULL);

    pthread_join(tsd, NULL);
    pthread_join(tsx, NULL);
    return 0;
}
