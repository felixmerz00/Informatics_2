#include <stdio.h>
#include <math.h>

int* merge(int A[], int l, int r, int m, int direction)
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
        for(k = l; k >= r; k++){
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
    return A;
}

int* mergeSort(int A[], int l, int r)
{
    if(l < r){
        int m = floor((l+r)/2);
        mergeSort(A, l, m);
        mergeSort(A, m+1, r);
        A = merge(A, l, r, m, 1);
    }
    return A;
}

int main()
{
    int direction = 0;
    while(direction !=  1 && direction != -1){  //if you enter ".1" as value, the program goes nuts, why?
        printf("In which direction do you want to order the array? (a/d)");
        scanf("%d", &direction);
        printf("%d\n", direction);
    }
    int A[] = {1, 2, 3, 5, 6, 4};
    int B[] = {1, 2, 3, 4, 5, 6};

    
}