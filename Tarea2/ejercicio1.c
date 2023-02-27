#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

void espera (int i, char *familia, int slept)
{
    int pid, r1, r2;
    pid= getpid();

    if(pid == -1)
    {
        perror("Error en getpid");
        exit(1);
    }

    r1= pid%10;
    int j;
    for(j= 0; j<i; j++)
    {

        if(wait(&r2) == -1)
        {
            perror("pract4:wait");
            exit(1);
        }

        if (WIFEXITED(r2))
        {
            r1= r1 + WEXITSTATUS(r2);  
        }
        else
        {
            perror("fallo en WIFEXITED");
            exit(0);
        }
        
    }
    printf("Soy el %s (pid=%d) y mi suma es %d \n", familia, pid, r1);
    exit(r1);

}

int main(int arr, char *arrChar[])
{
    int pid;

    if(arr != 1)
    {
        printf("Consumo total: %s \n", arrChar[0]);
        return 1;
    }

    switch(fork())
    {
        case -1: perror("error en fork");
                return 2;
        case 0: espera(0, "primer hijo", 0);
    }

    switch (fork())
    {
    case -1: perror("error en fork");
             return 3;
        
    case 0: switch(fork())
        {
            case -1: perror("error en fork");
                     return 4;
            case 0: espera(0, "primer nieto", 0);
        }

        switch(fork())
        {
            case -1: perror("error en fork");
                    return 5;
            case 0: switch(fork())
            {
                case -1: perror("error en fork");
                        return 6;
                case 0: espera(0,"bisnieto",0);
            }
            espera(1, "segundo nieto", 1);
        }
        espera(2, "segundo hijo", 1);
    }
    espera(2, "padre", 1);
}