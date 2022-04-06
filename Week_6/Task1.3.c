#include <stdio.h>
#include <stdlib.h>

//i is the node we want to heapify
//s = size of heap
void heapify(int *A, int i, int s)
{

}

int main()
{
    printf("Hello World!\n");
    int A[] = {85, 77, 55, 41, 38, 46};
    int length = 6;
    int* pA;
    pA = (int*)malloc(6*sizeof(int));
    for(int i = 0; i < length; i++){
        pA[i] = A[i];
    }
    heapify(pA, )
    return 0;
}