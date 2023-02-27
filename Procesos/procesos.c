#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{

    pid_t rf;
    
    rf = fork();
    int varfork;
    varfork = 10;
    int i;
    int status;

    
    while
    {
        switch(rf)
        {
            case -1:
                printf("No he podido crear el proceso hijo\n");
                exit(1);
                break;

            case 0:
                printf("Soy el proceso hijo mi PID es %d y mi PPID es %d \n", getpid(), rf);
                varfork = varfork + 1;
                break;

            default:
                printf("Soy el proceso padre PID es %d y  mi PPID es %d", getpid(), rf);
                varfork = varfork + 10;
                wait(%status);
        }
    }

    printf("final del proceso");
    exit(0);

}