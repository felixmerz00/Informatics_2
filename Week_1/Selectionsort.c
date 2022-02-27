#include <stdio.h>
#define INT_MIN -999999

void print_array(int *A, int length)
{
    for(int i = 0; i < length; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int* insertionsort(int* A, int length)
{
    for(int i = 0; i < length-1; i++){
        int pos_min = i;
        for(int j = i+1; j < length; j++){
            if(A[j] < A[i]){
                pos_min = j;
            }
        }
        int t = A[i];
        A[i] = A[pos_min];
        A[pos_min] = t;
        print_array(A, length);
    }
    return A;
}

int main()
{
    int A[7] = {98, 34, 56, 97, 56, 23, 11};
    int *pA = A;
    printf("Array vor dem Sortieren: ");
    print_array(pA, 7);
    pA = insertionsort(pA, 7);
    printf("Array nach dem Sortieren: ");
    print_array(pA, 7);
    return 0;
}