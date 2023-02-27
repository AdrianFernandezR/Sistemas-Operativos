#include <stdio.h>
#include <conio.h> 

#define lr( x, N ) ( (x)<0 ? N+(x)%N : ( (x)>=N ? (x)%N : (x) ) ) 

int main() 
{ 
    int cuadrado[17][17],x,y,n,N; 

    do{ 
        printf( "nIngrese el orden ( impar entre 3 y 17 ): " ); 
        scanf( "%i", &N ); 
        
    }while(!(N%2)); 
    
    printf("nCuadrado Mágico de orden %ix%i :nn", N, N); 
    
    for(x=0;x<N;x++)
        for(y=0;y<N;y++)
            cuadrado[x][y]=0; 
            
    for( x=N/2,y=0,n=1; n<=N*N; )
        if( !cuadrado[x][y] )
            cuadrado[x][y] = n++, x=lr(x+1,N), y=lr(y-1,N);
        
        else x=lr(x-1,N), y=lr(y+2,N);
        
        for(y=0;y<N;y++)
        {
            printf("n");
            
            for(x=0;x<N;x++)
                printf("%4i", cuadrado[x][y] );
        }
        
    printf("nn Suma = %inn", (N*(N*N+1))/2 );
    return 0; 
}
