#include <stdio.h>

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void intercambio(int *primero, int *segundo)
{
    int clonPrimero = *primero;
    *primero = *segundo;
    *segundo = clonPrimero;
}

void ordenaMenores(int arr[], int size)
{
   int i, j;
   for (i = 0; i < size-1; i++)     
 
       // Last i elements are already in place  
       for (j = 0; j < size-i-1; j++)
           if (arr[j] > arr[j+1])
              intercambio(&arr[j], &arr[j+1]);
}
 

int main()
{
    int size, i;
    printf("Ingresa el tamaño de tu arreglo\n");
    scanf("%d",&size);
    int arr [size];
    printf("Ingresa los valores del arreglo: \n");
    
    for(i = 0; i < size;  i++){
        scanf("%d", &arr[i]);
    }
    ordenaMenores(arr, size);
    printf("Tu arreglo ordenado de menor a mayor es: \n");
    printArray(arr, size);
    return 0;
}