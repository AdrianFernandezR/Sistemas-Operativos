#include <stdio.h>


void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int menorIzquierda(int *ap1, int *ap2) 
{ 
    return (*ap1 >*ap2); 
}

void ordenaMenores (int *apuntador, int N) 
{ 
    int i, j, k;
    
    for (i=N-1; i >=0; i--)
    { 
        for (j = 1; j<=i; j++) 
        { 
            if (menorIzquierda(&apuntador[j-1], &apuntador[j])) 
            { 
                k = apuntador[j-1]; 
                apuntador[j-1]= apuntador[j]; 
                apuntador[j] = k; 
            } 
        } 
    } 
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