#include <stdio.h>

 
//creo mi puntero 
int main () 
{ 
    int *apuntador; 
    int size, i;
    printf("Ingresa el numero de alumnos en lista\n");
    scanf("%d",&size);
    int arr [size];
    printf("Las calificaciones de los alumnos: \n");
    
    for(i = 0; i < size;  i++){
        scanf("%d", &arr[i]);
    }
    apuntador = &arr[0]; //le asigno la dirección 
    //del primer elemento 
    //del arreglo 
    
    for (i=0; i<size; i++) 
    { 
        printf("El apuntador esta en la posicion  %d del arreglo, que corresponde a la calificacion = %d \n", i, *(apuntador +i)); 
    } 
}