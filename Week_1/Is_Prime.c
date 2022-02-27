#include <stdio.h>
#include <stdlib.h>
//Algorithms Exercise SL01-1

int main()
{
    int n;
    int *A;

    //read n and setup the array with all 1s for the index of 2 onwards
    printf("Enter a number n: ");
    scanf("%d", &n);
    A = (int*)malloc((n+1)*sizeof(int));
    A[0] = 0;
    A[1] = 0;
    for(int i = 2; i < n+1; i++){
        A[i] = 1;
    }

    //overwrite all 1s at non prime indexes with a 0
    for(int i = 2; i < n+1; i++){
        int factor = 2;
        while(i * factor < n+1){
            A[i*factor] = 0;
            factor++;
        }
    }

    //print the all numbers from 1 to n and weather they are prime
    for(int i = 1; i < n+1; i++){
        printf("%d is prime: %d\n", i, A[i]);
    }
    return 0;
}