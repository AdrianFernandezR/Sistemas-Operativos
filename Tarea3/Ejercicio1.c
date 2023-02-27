#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t hTrhead,eThread, lOneThread, lTwoThread, oThread, wThread, oTwoThread, rThread, lTrheeThread, dThread;
int timeOut= 1;
void* h(void *arg)
{
    printf("h\n");
    return NULL;
}

void* e(void *arg)
{
    printf("e\n");
    return NULL;
}

void* l(void *arg)
{
    printf("l\n");
    return NULL;
}

void* o(void *arg)
{
    printf("o\n");
    return NULL;
}

void* w(void *arg)
{
    printf("w\n");
    return NULL;
}

void* r(void *arg)
{
    printf("r\n");
    return NULL;
}

void* d(void *arg)
{
    printf("d\n");
    return NULL;
}

int main(void)
{
    int err;

        err = pthread_create(&hTrhead, NULL, &h, NULL);
        if (err != 0)
            printf("\n No se puede crear el hilo :[%s]", strerror(err));
        sleep(timeOut);

        err = pthread_create(&eThread, NULL, &e, NULL);
        if (err != 0)
            printf("\nNo se puede crear el hilod :[%s]", strerror(err));
        sleep(timeOut);
            
        err = pthread_create(&lOneThread, NULL, &l, NULL);
        if (err != 0)
            printf("\nNo se puede crear el hilo :[%s]", strerror(err));
        sleep(timeOut);
        
        err = pthread_create(&lTwoThread, NULL, &l, NULL);
        if (err != 0)
            printf("\nNo se puede crear el hilo :[%s]", strerror(err));
        sleep(timeOut);
        
        err = pthread_create(&oThread, NULL, &o, NULL);
        if (err != 0)
            printf("\nNo se puede crear el hilo :[%s]", strerror(err));
        sleep(timeOut);
            
        err = pthread_create(&wThread, NULL, &w, NULL);
        if (err != 0)
            printf("\nNo se puede crear el hilo :[%s]", strerror(err));
        sleep(timeOut);
        
        err = pthread_create(&oTwoThread, NULL, &o, NULL);
        if (err != 0)
            printf("\nNo se puede crear el hilo :[%s]", strerror(err));
        sleep(timeOut);
                
        err = pthread_create(&rThread, NULL, &r, NULL);
        if (err != 0)
            printf("\nNo se puede crear el hilo :[%s]", strerror(err));
        sleep(timeOut);
        
        err = pthread_create(&lTrheeThread, NULL, &l, NULL);
        if (err != 0)
            printf("\nNo se puede crear el hilo :[%s]", strerror(err));
        sleep(timeOut);
        
        err = pthread_create(&dThread, NULL, &d, NULL);
        if (err != 0)
            printf("\nNo se puede crear el hilo :[%s]", strerror(err));
        sleep(timeOut);
        


    pthread_join(hTrhead, NULL);
    return 0;
}