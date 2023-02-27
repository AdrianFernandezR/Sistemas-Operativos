#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void){
    pid_t pidHijo;
    int resultado;
    int estado= 0;

    if((pidHijo = fork()) == -1)
    {
        exit(1);
    }
    else if (pidHijo == 0)
    {
        resultado = getpid() < getppid();
        printf("Soy el proceso hijo (%ld) y mi padre es %ld, su valor es %d despues de esperar 2 segundos\n", (long)getpid(), (long)getppid(), resultado);
        sleep(2);
        exit(resultado);
    }
    else
    {
        while (pidHijo != wait(&estado));
        printf("Soy el proceso padre (%ld) y mi hijo (%ld) me hs devuelto %d\n", (long)getpid(), (long) pidHijo, estado);
    }
    return(0);
}