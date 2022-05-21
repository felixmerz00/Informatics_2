#include <stdio.h>

void swap(int ∗a, int ∗b) { int temp = ∗a;
∗a = ∗b; ∗b = temp;
void printArray(int A[], int size){ int i;
for (i=0; i < size; i++) printf(”%d ”, A[i]);
printf(”\n”); }
int LomutoPartition(int A[], int l, int r){ int pivot = A[r];
int i = (l − 1);
for (int j = l; j ≤r− 1; j++){
if (A[j] ≤pivot){ i++;
swap(&A[i], &A[j]);
printArray(A, 10);}} swap(&A[i + 1], &A[r]);
printArray(A, 10);
return (i + 1); }
void QuickSort1(int A[], int l, int r){ if (l < r){
int pi = LomutoPartition(A, l, r); QuickSort1(A, l, pi − 1); QuickSort1(A, pi + 1, r);
} }
int HoarePartition(int A[], int l, int r){ int pivot = A[r];//−> high
int i = l − 1, j = r + 1;
while (1) {
do { i++;
} while (A[i] < pivot); do {
j−−;
} while (A[j] > pivot); if (i ≥j)
return i; swap(&A[i], &A[j]); printArray(A, 10);} }
void QuickSort2(int A[], int l, int r){ if (l < r) {
int pi = HoarePartition(A, l, r); QuickSort2(A, l, pi−1); QuickSort2(A, pi, r);
} }
int main(){
int A[] = {11, 0, 9, 19, 8, 1, 5, 13, 18, 7}; int n = sizeof(A)/sizeof(A[0]); printf(”Lomuto: \n”);
printArray(A, n);
QuickSort1(A, 0, n−1);
printArray(A, n);
printf(”\n”);
printf(”\nHoare: \n”); printArray(A, n); QuickSort2(A, 0, n−1); printArray(A, n);
return 0; }