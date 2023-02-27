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
int   path; // Pipe con nombre
struct msg mensaje;


// Abro la pipe de escritura sin bloquearme si el proceso demonio
// no está activo
path = open("pipeE3.pipe",O_WRONLY | O_NONBLOCK);
if ( -1 == path )
	{
	perror("abriendo -> pipeE3.pipe");
	exit(1);
	}

printf("Escriba el mensaje para el pipe:");
fgets(mensaje.texto,50,stdin);
mensaje.pid = getpid();
write(path,&mensaje,sizeof(mensaje));
puts(" Mensaje enviado.");
close(path);
}