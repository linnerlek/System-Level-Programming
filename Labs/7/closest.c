/*
 * Linn Klofta
 * Account: lklfta1
 *
 * Program finds the closest value to a number from values
 * from an input of any amount of values up to 205
 */

#include <stdio.h>
#define N 205 // 200 + 4 (Linn) + 1 (Lklfta1) = 205

void find_closest(int a[], int n, int target, int *closest1, int *closest2);

int main(void) {
	int b[N], i = 0, count = 0, target, closest1, closest2;

	printf("Enter the number to find the closest value to: ");
    	scanf("%d", &target);  // Read the number to find the closest value to
    
    	printf("Enter up to %d numbers (non-number to stop): ", N);
    
    	while (i < N && scanf("%d", &b[i]) == 1) {  // Read the list of numbers
        	i++;
    	}	
    	count = i;  // Store the number of inputs

    	if (count > 0) {
        	find_closest(b, count, target, &closest1, &closest2);

        	if (closest1 == closest2) {
            		printf("Closest value: %d\n", closest1);  // Print the closest value if there is only one closest value
        	} else {
            		printf("Closest values: %d and %d\n", closest1, closest2);  // Print both closest values if there are two equally close
        	}
    	} else {
        	printf("No valid numbers were entered.\n");
    	}	

    	return 0;
}

// Function to find the closest value(s) to the target
void find_closest(int a[], int n, int target, int *closest1, int *closest2) { 
	int i;
	*closest1 = a[0];
	*closest2 = a[0];
	int min_diff = (a[0] - target) < 0 ? -(a[0] - target) : (a[0] - target);  // checks if a[0] - target is less than 0, if it is it negates the value to make it positive, else it keeps the value as it is.

	for (i = 1; i < n; i++) {
		int diff = (a[i] - target) < 0 ? -(a[i] - target) : (a[i] - target); // checks if a[i] - target is less than 0, if it is it negates the value to make it positive, else it keeps the value as it is.

		if (diff < min_diff) {
			// If the current element is closer, update both closest1 and closest2
			min_diff = diff;
			*closest1 = a[i];
			*closest2 = a[i];
		} else if (diff == min_diff) {
			// If two values are equally close, update closest2 to the new one
			*closest2 = a[i];
		}
	}
}

