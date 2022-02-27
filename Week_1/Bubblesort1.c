#include <stdio.h>

void print_array(int *A, int length)
{
    for(int i = 0; i < length; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

//sortiert von rechts nach links
int* bubblesort(int *A, int length)
{
    for(int i = 0; i < length-1; i++){
        for(int j = 1; j < length-i; j++){
            if(A[j] < A[j-1]){
                int t = A[j-1];
                A[j-1] = A[j];
                A[j] = t;
            }
        }
        print_array(A, length);
    }
    return A;
}

int main()
{
    int A[17] = {99, 46, -43, 48, 34, 84, -34, 29, 12, 26, 50, -10, 34, -44, 22, -17, -99};
    int *pA = &A;
    printf("Array at the beginning:\n");
    print_array(A, 17);
    printf("Array during/after bubblesort:\n");
    pA = bubblesort(A, 17);
    

    return 0;
}