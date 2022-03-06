/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 2 - Task 3                                                      *
 *                                                                          *
 * @author <your name>                                                      *
 ****************************************************************************/

#include <stdio.h>

/*
f(n)=1 -> 1
f(n)=2 -> 2
f(n)=3 -> 3
f(n)=4 -> 5
f(n)=5 -> 8
f(n)=6 -> 13
f(n)=f(n-1) + f(n-2) */

// TODO: your implementation
//returns the number of combinations for a given number of blinks n
int rec_fun(int n)
{
	if(n==1){
		return 1;
	}
	else if(n==2){
		return 2;
	}
	else{
		return rec_fun(n-1) + rec_fun(n-2);
	}
}

int main() {
	int input;
	printf("Enter the number of blinks: ");
	scanf("%d", &input);

	// TODO: your implementation
	int number_of_combinations = rec_fun(input);
	printf("Number of combinations: %d\n", number_of_combinations);

	return 0;
}
