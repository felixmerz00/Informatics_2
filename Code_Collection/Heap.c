#include <stdio.h>

void swap(int *a, int *b) 
{ int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int A[], int i, int s) {
    int largest = i;
    int left=2*i+1;
    int right=2*i+2;
    if(left < s && A[left] > A[largest]) largest = left;
    if(right < s && A[right] > A[largest]) largest = right;
    if(largest != i){
        swap(&A[i], &A[largest]);
        heapify(A, largest, s);
    } 
}

void printArray(int A[], int n) 
{
    for (int i = 0; i < n; ++i) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void buildheap(int A[], int n) 
{
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(A, i, n);
        printArray(A, n);
    }
}

void heapSort(int A[], int n)
{
    buildheap(A, n);
    for (int i = n - 1; i >= 0; i--) {
        swap(&A[0], &A[i]); 
        heapify(A, 0, i); 
        printArray(A, n);
    }
}

int main() 
{
    int A[]={11,0,9,19,8,1,5,13,18,7};
    int n = sizeof(A) / sizeof(A[0]);
    heapSort(A, n);
    printf("State of A after heapSort: \n"); 
    printArray(A, n);
}