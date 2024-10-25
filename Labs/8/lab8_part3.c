/*
 * This program reverses an array using pointers
 *
 * Linn Klofta 2024
 */

#include <stdio.h>

int main(void){
	int n, *p;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);

	int a[n];

	// I used the logic in the program reverse3.c from the C textbook written by K.N. King
	printf("Enter %d numbers: ", n);
	for (p = a; p < a + n; p++)
		scanf("%d", p);

	printf("Reversed array: ");
	for (p = a + n - 1; p >= a; p--)
		printf(" %d", *p);
	printf("\n");

	return 0;
}
