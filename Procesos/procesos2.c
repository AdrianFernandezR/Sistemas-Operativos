#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    pid_t pid1, pid2;
    in status1, status2;
    if((pid1 = fork()) == 0){
        printf("Soy el primer hijo fr %d \n", getpid())
    }
    else{

        if((pid2 = fork()) == 0){

            printf("Soy el segundo hijo (%d, hijo de %d) \n", getpid(), getppid());
        }
        else{
            waitpid(pid1, &status1, 0);
            waitpid(pid2, &status2, 0);
            printf("Soy el padre (%d hijo de %d) \n", getpid(), getppid);
        }


    }
}