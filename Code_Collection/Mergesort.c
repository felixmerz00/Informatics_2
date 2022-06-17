#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Display the array sequence from l to r
void displayArray(int *A, int l, int r)
{
    for(int i = l; i <= r; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Input: array A; indexes l, r and m from MergeSort
// Output: A[l..r] is sorted in increasing order
void Merge(int *A, int l, int r, int m)
{
    int i, j;
    int B[r];
    for(i = l; i <= m; i++){
        B[i] = A[i];    // Copy the first half of the sequence into B
    }
    for(i = m+1; i <= r; i++){
        B[r+m-i+1] = A[i];  //Copy the second half in reverse order into B --> smallest element of the second half is on the far right of Array B.
    }
    // Merge the elements in ascending order back into array A
    i = l; j = r;
    for(int k = l; k <= r; k++){
        if(B[i] < B[j]){
            A[k] = B[i];
            i = i+1;
        }else{
            A[k] = B[j];
            j = j-1;
        }
    }
}

// Input: array A[l..r]
// Output: permuted array A[l..r] that is sorted in increasing order
void MergeSort(int *A, int l, int r)
{
    if(l < r){
        int m = floor((l+r)/2);
        MergeSort(A, l, m);
        MergeSort(A, m+1, r);
        Merge(A, l, r, m);
        displayArray(A, l, r);
    }
}

int main()
{
    int A[8] = {5, 2, 4, 7, 1, 3, 6, 2};
    int *p;
    p = (int*)malloc(8*sizeof(int));
    for(int i = 0; i < 8; i++){
        p[i] = A[i];
    }
    displayArray(p, 0, 7);
    MergeSort(p, 0, 7);
    return 0;
}

