#include <stdio.h>
#include <stdlib.h>

void get_span(int data[], int length_data, int* spans)
{
    int i, j;
    for(i = 0; i < length_data; i++){
        int count = 1;
        for(j = i-1; j >= 0 && data[j] <= data[i]; j--){
            count++;
        }
        spans[i] = count;
    }
}

void print_array(int A[], int length)
{
    for(int i = 0; i < length; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int data[] = {6, 3, 4, 5, 2};
    int length_data = 5;
    int* spans;
    spans = (int*)malloc(length_data*sizeof(int));
    get_span(data, length_data, spans);
    print_array(data, length_data);
    print_array(spans, length_data);
    return 0;
}

/*Task3
Consider an array A[0..n − 1] of n integers. The span s(A, i) of array element A[i] is the maximum number of 
consecutive elements A[j] immediately preceding A[i] and such that A[j] ≤ A[i]. For example, array A = [6,3,4,5,2] 
has the spans s(A,0) = 1, s(A,1) = 1, s(A,2) = 2, s(A,3) = 3 and s(A, 4) = 1 which can be written as an array as 
follows: s(A) = [1, 1, 2, 3, 1].*/