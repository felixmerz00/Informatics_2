#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void print_Array(int *A, int length)
{
    for(int i = 0; i < length; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int *A, int l, int r, int m, int direction)
{
    int B[r];
    int i, j, k;
    for(i = l; i <= m; i++){
        B[i] = A[i];
    }
    for(i = m+1; i <= r; i++){
        B[r+m-i+1] = A[i];
    }
    i = l; j = r;
    if(direction == 1){
        for(k = l; k <= r; k++){
            if(B[i] < B[j]){
                A[k] = B[i];
                i++;
            }
            else{
                A[k] = B[j];
                j--;
            }
        }
    }
    if(direction == -1){
        for(k = l; k <= r; k++){
            if(B[i] > B[j]){
                A[k] = B[i];
                i++;
            }
            else{
                A[k] = B[j];
                j--;
            }
        }
    }
}

void mergeSort(int *A, int l, int r, int direction)
{
    if(l < r){
        int m = floor((l+r)/2);
        mergeSort(A, l, m, direction);
        mergeSort(A, m+1, r, direction);
        merge(A, l, r, m, direction);
    }
}

int main()
{
    int direction = 0;
    while(direction !=  1 && direction != -1){  //if you enter ".1" as value, the program goes nuts, why?
        printf("In which direction do you want to order the array? (1/-1)");
        scanf("%d", &direction);
        if(direction == 1){
            printf("Array is sorted in ascending order:\n");
        }
        else if(direction == -1){
            printf("Array is sorted in descending order:\n");
        }
        else{
            printf("%d is invalid. Please enter a valid value: 1, -1.\n", direction);
        }
    }
    int A[8] = {5, 2, 4, 7, 1, 3, 6, 2};
    int length = 8;
    int *pA;
    pA = (int*)malloc(8*sizeof(int));
    for(int i = 0; i < length; i++){
        pA[i] = A[i];
    }
    mergeSort(pA, 0, length-1, direction);
    print_Array(pA, length);    
}