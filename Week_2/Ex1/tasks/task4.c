/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 1 - Task 4                                     *
 *                                                                          *
 * @date 2022-02-10                                                         *
 ****************************************************************************/

#include <stdio.h>
const int MAX_LENGTH = 1000;

int main() {
	printf("Values of A separated by spaces (non-number to stop): ");
	int timestamps[MAX_LENGTH];
	int pos = 0;
	while (scanf("%d", &timestamps[pos]) == 1) {
		pos++;
	}

	int length = pos;
	for(int i = 0; i < length; i++){
		printf(" %d", timestamps[i]);
	}
	printf("\n");

	//insertionsort the array, if an element is equal to another element, dicard it
	for(int i = 1; i < length; i++){
		int target = timestamps[i];

		//test if target already exists in sorted section
		int target_exists = 0;
		for(int k = 0; k < i; k++){
			if(timestamps[k] == target){
				target_exists = 1;
			}
		}

		//if target exists, add a -1 at the end of the sorted section
		if(target_exists){
			timestamps[i] = -1;
		}
		//if target doesn't exist yet in sorted section, insert it with insertion sort
		else{
			int j = i-1;
			while((timestamps[j] == -1 || target < timestamps[j]) && j >= 0){
				timestamps[j+1] = timestamps[j];
				j--;
			}
			timestamps[j+1] = target;
		}

	}

	//find biggest gap
	int biggest_gap = timestamps[1] - timestamps[0];
	int most_recent_timestamp = timestamps[0];
	for(int i = 1; i < length && timestamps[i] != -1; i++){
		int current_gap = timestamps[i+1]-timestamps[i];
		if(current_gap > biggest_gap){
			biggest_gap = current_gap;
		}
		most_recent_timestamp = timestamps[i];
	}

	for(int i = 0; i < length; i++){
		printf(" %d", timestamps[i]);
	}
	printf("\n");

	//return oldest, newest timestamp and biggest gap
	printf("Oldest timestamp: %d, most recent timestamp: %d, biggest gap: %d\n", timestamps[0], most_recent_timestamp, biggest_gap);

	return 0;
}