#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


struct msg 
{
    int pid;
    char texto[50];
};

int main ()

{
int pid;
time_t tiempo;
FILE *file; 
int   path; 
struct msg mensaje;


pid = fork();

if ( pid > 0 )
   {
   puts ("Termina proceso padre");
   exit(0);
   }

if (-1 == setsid())
   {
   perror("setsid()");
   exit(1);
   }
   
path = open("pipeE2.pipe",O_RDWR);
if ( -1 == path )
   {
   perror("abriendo pipeE2.pipe");
   exit(1);
   }
file = fopen("info.txt","a");
if (file == NULL )
        {
   perror("abriendo info.txt ");
   exit(2);
   }

close(0);
close(1);
close(2);

    while ( 1 )
    {
        read(path,& mensaje, sizeof(mensaje));
        tiempo = time(NULL);
        fprintf(file,"PID del proceso (%6d) Mesnaje:%-30s Fecha:%s \n",
        mensaje.pid,
        mensaje.texto,
        ctime(&tiempo));
        fflush(file);
    }

}
