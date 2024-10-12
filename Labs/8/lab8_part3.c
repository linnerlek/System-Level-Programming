/*
 * This program reverses an array using pointers
 *
 * Linn Klofta 2024
 */

#include <stdio.h>

int main(void){
	int n, temp;
	int *p, *start, *end;

	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);

	int a[n];

	printf("Enter %d numbers: ", n);
	for (p = a; p < a + n; p++) {
		scanf("%d",p);
	}

	start = a;
	end = a + n - 1;
	while (start < end) {
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}

	printf("Reversed array: ");
	for (p = a; p < a + n; p++){
		printf("%d ", *p);
	}
	printf("\n");
	
	return 0;
}
