/*
 * Linn Klofta
 * Account: lklfta1
 *
 * Program finds max and min of up to 205 numbers
 */

#include <stdio.h> 
#define N 205 // 200 + 4 (Linn) + 1 (lklfta1) = 205

void max_min(int a[], int n, int *max, int *min);

int main(void){
	int b[N], i = 0, big, small, count = 0;

	printf("Enter up to %d numbers (non-number to stop): ", N);
	
	while(i<N && scanf("%d", &b[i]) == 1) { // Reads input until a non integer is entered or until the amount of numbers entered is more than N which is 205.
		i++; // increments i once each time a valid input is input
	}
	count = i; // stores the amount of inputs  

	if (count > 0) {
		max_min(b, count, &big, &small);

		printf("Largest %d\n", big);
		printf("Smallest %d\n", small);
	} else {
		printf("No valid numbers were entered.\n");
	}	

	return 0;
}

void max_min(int a[], int n, int *max, int *min){
	int i;

	*max = *min = a[0]; 
	for (i=1; i<n; i++){ 
		if (a[i] > *max) 
			*max = a[i];
		else if (a[i] < *min)
			*min = a[i]; 
	}
}

