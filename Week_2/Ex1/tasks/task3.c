/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 1 - Task 3                                    *
 *                                                                          *
 * @date 2022-02-10                                                         *
 ****************************************************************************/

#include <stdio.h>

void selectionSort(int A[], int n) {
	int i;
	for(i = 0; i < n-1; i++){
		//find the position of the lowest value
		int target_pos = i;
		for(int j = i+1; j < n; j++){
			if(A[j] < A[target_pos]){
				target_pos = j;
			}
		}
		//swap the two values
		int t = A[i];
		A[i] = A[target_pos];
		A[target_pos] = t;
	}

	//print the array
	for(i = 0; i < n; i++){
		printf(" %d", A[i]);
	}
	printf("\n");
	return;
}

void evenOddSelectionSort(int A[], int n){
	int even_n, i = 0;
	int odd_n = 0;
	int E[100], O[100];

	//distribute the numbers in an odd array and an even array and count their length
	for(i = 0; i < n; i++){
		if(A[i] % 2 == 0){
			E[even_n] = A[i];
			even_n++;
		}
		else{
			O[odd_n] = A[i];
			odd_n++;
		}
	}

	//sort both arrays and print them
	printf("Sorted even numbers:");
	selectionSort(E, even_n);
	printf("Sorted odd numbers:");
	selectionSort(O, odd_n);
	return;
}

int main(int argc, const char * argv[]) {
	int A[100];
	int n = 0;

	/*On success, the scanf function returns the number of items of the argument list 
	successfully read.*/
	printf("Values of A separated by spaces (non-number to stop):");
	while (scanf("%d", &A[n]) == 1) {
		n++;
	}
	scanf("%*s");
	
	printf("Result:\n");
	evenOddSelectionSort(A, n);
}

// Linux, Mac: gcc task4.c -o task4; ./task4
