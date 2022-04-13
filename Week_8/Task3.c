#include <stdio.h>
#include <stdlib.h>

void get_span(int data[], int length_data, int* spans)
{
    int i, j;
    for(i = 0; i < length_data; i++){
        int count = 0;
        for(j = i; j >= 0 && data[j] <= data[i]; j--){
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