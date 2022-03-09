/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 2 - Task 2                                                      *
 *                                                                          *
 * @author <your name>                                                      *
 ****************************************************************************/

#include <stdio.h>

// hard-coded maximum length for input strings
const int MAX_LENGTH = 1000;

// TODO: your implementation
int find_second_smallest(int A[], int i, int length)
{
	int count = 0;
	for(int j = 0; j < length; j++){
		if(A[j] < A[i]){
			count++;
		}
	}
	//base case
	if(count == 1){return A[i];}
	//if not, try for element at postion i+1
	else{
		return find_second_smallest(A, i+1, length);
	}
	return 0;
}

int main() {
	printf("Values of array separated by spaces (non-number to stop): ");
	int arr[MAX_LENGTH];
	int pos = 0;
	while (scanf("%d", &arr[pos]) == 1) {
		pos++;
	}
	// variable pos will contain number of integers read in from user

	// TODO: your implementation
	int second_smallest_integer = find_second_smallest(arr, 0, pos);
	printf("The second smallest integer is: %d\n", second_smallest_integer);

	return 0;
}
