#include<stdio.h>
#include<pthread.h>
#include<time.h>
#include <unistd.h>
#include<semaphore.h>
#define n 1
#define n1 50

int estado[n];
int baberoEstado= 0;
sem_t waitBarb;
sem_t barbSem;

void *barber()
{
    printf("Barbero dormido \n");
    baberoEstado= 1;
    sem_wait(&barbSem);
    printf("Barbero despierto \n");
    sleep(1);
    baberoEstado= 0;

}

void *atender(void *ptr)
{
    int aux;
    aux = *((int *) ptr);
    int seguidor;
    int i= 0;
    int cont= 0;

    for ( i = 0; i < n; i++)
    {
        if(estado[i] == 1)
        {
            seguidor = 1;
            cont++;
        }
    }


    if(cont == n)
    {
        printf("%d El cliente ha regresado \n", aux);
        return 0;
        
    }
        
    if(baberoEstado == 1)
    { 
        printf("El cliente %d desperto al barbero", aux);
        sem_post(&barbSem);

    }

    if(seguidor == 1)
    {

        estado[aux]= 1;
        printf("%d Cliente esperando \n", aux);
        sem_wait(&waitBarb);
    }

    printf("Cortando el cabello de el cliente %d \n", aux);
    estado[aux]= 1;
    sleep(3);
    seguidor= 0;

    for(i=0; i<n; i++)
    {
        if(estado[i] == 1)
        {
            seguidor=1;
        }
    }

    estado[aux]=0;
    printf("El cliente %d se ha cortado el cabello \n", aux);
    if(seguidor == 1)
    {
        sem_post(&waitBarb);
    }
}
    

int main()
{

    sem_init(&waitBarb, 0, n);
    sem_init(&barbSem, 0, 1);
    pthread_t thread[n1];
    pthread_t barberoT;
    int i = 0;
    for(i= 0; i < n; i++)
    {
        estado[i]= 0; 
    }

    pthread_create(&barberoT,NULL,barber,NULL);
    pthread_join(barberoT,NULL);

    for(i=0; i<n1; i++){

        sleep(3);
        printf("El cliente %d ha entrado\n", i);
        pthread_create(&thread[i], NULL, atender, (void *)&i);
    }

}