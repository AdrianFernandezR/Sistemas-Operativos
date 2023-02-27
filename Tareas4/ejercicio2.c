#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define avisos  10

typedef struct
{
	       int tiempo;
	       int pid;
	       int signal;
	      
} 
Aviso;
Aviso tabla[avisos];
int CargarTabla()
{
  FILE *file;
  int i = 0;
  Aviso avs;
  char linea[100];
  
  file = fopen ("avisos.conf","r");
  if ( file == NULL )
     {
     perror("avisos.conf");
     return 0;
     }
  while (NULL != fgets(linea,100,file) )
   {
   if ( linea[0] != '#' )
	{
	sscanf(linea,"%d %d %d", & avs.tiempo, & avs.pid, & avs.signal);
	if ( i < avisos )
	   {
	   tabla[i] = avs;
	   i++;
	   }
	else
	  {
	  return 0;
	  }
	}
    }
   fclose(file);
   return i;
}
  

int main ( int argc, char *argv[])
{
  int pid;
  int espera;
  int numA; 
  int avisoA;
  FILE *plog;   
  int i;
	
  numA = CargarTabla();

  if (numA== 0)
  {
    fprintf(stderr,"Avisos.conf no cumple los requerimientos\n");
     exit(1);
  }
 
  printf("Numero de avisos = %d \n", numA);
  
  for (i=0; i < numA; i++)
  {
    printf(" %5d %5d %5d\n ",tabla[i].tiempo,tabla[i].pid,tabla[i].signal);
  }

  pid = fork();

  if ( pid > 0 )
  {
    puts ("Terminando proceso padre");
    exit(0);
  }

  if (-1 == setsid())
  {
    perror("setsid()");
    exit(1);
  }

  close(1); 
  close(2);
  plog = fopen("avisos.log","w");
  dup(1);
  close(0);

  avisoA = 0;
  while (avisoA < numA )
  {
  espera = tabla[avisoA].tiempo;
  sleep(espera);
  printf("Aviso %5d: Señal %6d Proceso %6d \n",avisoA, tabla[avisoA].signal, tabla[avisoA].pid);
		  
  if (-1 == kill(tabla[avisoA].pid, tabla[avisoA].signal))
  {
	  perror("kill de tabla");
	}
  avisoA++;
  }

  puts("No hay mas avisos por atender");
}