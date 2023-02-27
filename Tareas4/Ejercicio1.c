#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void contador (int estado)
{
    static int cont = 0;
    cont++;
    puts("Señal enviada");
    if ( cont == 3)
    {
        puts("Señal enviada 3 veces, terminando proceso");
        kill(getppid(),SIGKILL);
        exit(0); 
    }
}

int main()
{
    int pid;

    pid = fork();
    if ( pid == -1 )
    {
        perror(" fork:");
        exit(1);
    }

    if (pid == 0 )
    {    
        signal(SIGUSR1,contador);
        puts(" Proceso hijo inicia");
        while (1)
            {
            pause();
        }
   }
    else
    {
    puts("Proceso padre inicia");
        while(1)
        {
            sleep(5);
            puts("Señal recibida");
            kill(pid,SIGUSR1);
        }
    }
}