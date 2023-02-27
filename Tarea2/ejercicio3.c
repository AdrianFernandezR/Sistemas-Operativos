#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
 
int main(int argc, char *argv[])
{
    pid_t pid;
    int suma= 4;
    
    printf("el valor incial es %d \n", suma);
    if ( (pid=fork()) == 0 )
    { 
        suma= suma + 4;
        printf("Soy el hijo con PID: %d, hijo de %d con valor %d \n", getpid(), getppid(), suma);
    }
    else
    { 
        suma = suma+ 2;
        printf("Soy el padre con PID: %d, con valor %d \n", getpid(), suma);
    }
 
    return 0;
}