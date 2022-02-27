#include <stdio.h>

void print_array(int* A, int length)
{
    for(int i = 0; i < length; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int* insertionsort(int *A, int length){
    for(int i = 1; i < length; i++){
        int j = i-1;
        int t = A[i];
        /*solage t<A[j] das Element A[j] nach rechts verschieben, 
        um weiter links Platz zu machen für t*/
        while(j >= 0 && t < A[j]){
            A[j+1] = A[j];
            j--;
        }
        //wenn A[j] kleiner ist als t, dann t bei A[j+1] einfügen
        A[j+1] = t;
        print_array(A, length);
    }
    return A;
}

int main()
{
    int A[7] = {87, 12, -20, 61, -25, 44, -67};
    int *pA = A;
    printf("Array vor dem Sortieren: ");
    print_array(pA, 7);
    pA = insertionsort(pA, 7);
    printf("Nach dem Sortieren: ");
    print_array(pA, 7);
    return 0;
}