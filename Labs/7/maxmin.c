/*
 * Linn Klofta
 * Account: lklfta1
 *
 * Program finds max and min of 10 numbers
 */
#include <stdio.h> // includes the standard library
#define N 10 // defines the constant N wuth the value 10 for the preprocessor

void max_min(int a[], int n, int *max, int *min); // tells the compiler that max_min will accept an array a[] of integers, the size of the array n, and pointers to two integers max and min

int main(void){
	int b[N], i, big, small; //declares the integers b[] for holding the values inserted by the user, i, big and small for storing the smallest and biggest numbers as max_min is called

	printf("Enter %d numbers: ", N); // prompts user to enter 10 numbers
	for (i = 0; i < N; i++) 
		scanf("%d", &b[i]); // reads the 10 integers inputted from the user and stores them in the b[] array
	
	max_min(b, N, &big, &small); // calls the function passing it the array b, the size N and the addresses of big and small

	printf("Largest: %d\n", big); // prints the largest value 
	printf("Smallest: %d\n", small); // prints the smallest value

	return 0;
}

void max_min(int a[], int n, int *max, int *min){ // start of the max_min function definition
	int i;

	*max = *min = a[0]; // assigns the first element of a[] to the pointers *max and *min
	for (i=1; i<n; i++){ // for loop looping over the array 
		if (a[i] > *max) 
			*max = a[i]; // if the current element in a[i] is > *max then *max is updated to a[i]
		else if (a[i] < *min)
			*min = a[i]; // if the current element in a[i] is < *min then *min is updated to a[i]
	}
}

