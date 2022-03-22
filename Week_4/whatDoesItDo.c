#include <stdio.h>

int whatDoesItDo(int A[], int n, int k)
{
    int result = -1000;
    for(int i = 0; i < n; i++){
        int current = 0;
        for(int j = i; j < n; j = j+k){
            current += A[j];
        }
        if(current > result){
            result = current;
        }
    }
    return result;
}

int main()
{
    int A[] = {1,3,5,4,2,6,8};
    int n = 7;
    int k = 3;
    printf("%d\n", whatDoesItDo(A, n, k));
    return 0;
}