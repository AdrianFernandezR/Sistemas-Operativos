#include <stdio.h>
#include <stdlib.h>

int bloqueo = 1;
int lleno = 0;
int vacio = 10;
int objProd = 0;

void productor()
{
    --bloqueo;
    ++lleno;
    --vacio;
    objProd++;

    printf("El productor tiene total de %d objetos\n", objProd);
    ++bloqueo;

}

void consumidor()
{
    --bloqueo;
    --lleno;
    ++vacio;

    printf("Al consumidor le quedan %d objetos sin consumir\n", objProd);
    objProd--;

    ++bloqueo;
}

int main()
{
    int n, i;
    printf("\nPresiona 1 para producir \nPresiona 2 para consumir \nPresiona 3 para salir\n");

    for(int i = 1; i>0; i++)
    {   
        scanf("%d", &n);
        
        switch(n){

            case 1: 

                if((bloqueo == 1) && (vacio != 0))
                {
                    productor();
                } 
                else
                {
                    printf("No hay espacio para almacenar mas objetos\n");
                }
                break;

            case 2:

                if((bloqueo == 1) && (lleno != 0))
                {
                    consumidor();
                }
                else
                {
                    printf("El almacenamiento esta vacio\n");
                }
                break;

            case 3:
                exit(0);
                break;
        }
    }

}
