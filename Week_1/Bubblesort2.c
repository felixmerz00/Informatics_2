#include <stdio.h>

void print_array(int *A, int length)
{
    for(int i = 0; i < length; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

//sortiert von links nach rechts, von klein zu gross
int* bubblesort2(int *A, int length)
{
    for(int i = 0; i < length-1; i++){
        for(int j = length-1; j > i; j--){
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
    int A[5] = {44, -12, 23, 10, -13};
    int *pA = &A;
    printf("Array for dem Sortieren: ");
    print_array(pA, 5);
    printf("Array während dem Sortieren:\n");
    pA = bubblesort2(pA, 5);
    printf("Array nach dem Sortieren: ");
    print_array(pA, 5);
}