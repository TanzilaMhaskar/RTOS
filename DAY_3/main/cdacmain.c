#include <stdio.h>
#include <pthread.h>

void *helloESPthread (void *arg)
{
    printf("THREAD\n");
    return NULL;
}

int app_main()
{

    printf("Hello RTOS\n");
    pthread_t helloID;
    pthread_create (&helloID,NULL,helloESPthread,NULL);
    pthread_join (helloID,NULL);

    return 0;
}
