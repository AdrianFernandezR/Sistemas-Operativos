#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    pid_t pid1, pid2;
    in status1, status2;
    if((pid1 = fork()) == 0){
        
        if((pid2 = fork()) == 0){
            printf("Soy el nieto  %d hijo de %d \n", getpid(), getppid());
 
    }
    else{


            wait(&status2);
            printf("Soy el padre (%d, hijo de %d) \n", getpid(), getppid());
        }
        
        else{
            wait(&status1);
            printf("Soy el abuelo (%d hijo de %d) \n", getpid(), getppid);
        }


    }
    return 0;
}