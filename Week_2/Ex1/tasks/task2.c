/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 1 - Task 2                                               *
 *                                                                          *
 * @author <Felix>                                                      *
 ****************************************************************************/

#include <stdio.h>

// hard-coded maximum length for input strings
const int MAX_LENGTH = 1000;

/*    
 * Task 2.1 number of vowals. Implement the C function int count_vowels(char A[]) that returns the number 
 * of vowels for a given string A.   
 * */
int is_vowel(char c)
{
	if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U'){
		return 1;
	}
	return 0;
}

int count_vowels(char A[]){
	int i = 0;
	int count = 0;
	while(A[i] != '\0'){
		if(A[i] == 'a' || A[i] == 'A' || A[i] == 'e' || A[i] == 'E' || A[i] == 'i' || A[i] == 'I' || A[i] == 'o' || A[i] == 'O' || A[i] == 'u' || A[i] == 'U'){
			count++;
		}
		i++;
	}
	return count;
}

/*Task 2.2 B-Sprache String. Given a string A[1..n], the B-Sprache string BS of A is generated as followed.
We traverse the string A from the first element of A to the last one, one after another. 
If A[i], 1 ≤ i ≤ n, is not a vowel, A[i] is copied to the BS, otherwise, three consecutive letters: 
A[i], ’b’ and A[i] are copied to BS. Implement the C function void BS(char A[]) 
that prints the B-Sprache String of A.*/
int get_length(char A[]){
	int length = 0;
	int i = 0;
	while(A[i] != '\0'){
		length++;
		i++;
	}
	return length;
}

void BS(char A[]) {
	int length = get_length(A);
	char B[length * 3 + 1];
	int i = 0;
	int j = 0;
	while(A[i] != '\0'){
		if(is_vowel(A[i])){
			B[j] = A[i];
			B[j+1] = 'b';
			B[j+2] = A[i];
			j += 3;
		}
		else{
			B[j] = A[i];
			j++;
		}
		i++;
	}

	B[j] = '\0';

	/*Print B*/
	j = 0;
	while(B[j] != '\0'){
		printf("%c", B[j]);
		j++;
	}
	printf("\n");
}

int main() {
	char input_string[MAX_LENGTH + 1];
	printf("Enter a string: ");
	scanf("%[^\n]s", input_string);
	int num_vowls = count_vowels(input_string);
	printf("Number of vowels: %d\n", num_vowls);

	BS(input_string);

	return 0;
}
