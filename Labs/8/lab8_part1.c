/*
 * Prints the size of the various pointers
 * Linn Klofta 2024
 */

#include <stdio.h>

int main(void) {
	int a = 23;
	int *p1 = &a;
	printf("size of p1: %lu bytes\n", sizeof(p1));

	int b[] = {0};
	int *p2 = &b;
	printf("size of p2: %lu bytes\n", sizeof(p2));

	char c = 'A';
	char *p3 = &c;
	printf("size of p3: %lu bytes\n", sizeof(p3));

	double d = 10.0;
	double *p4 = &d;
	printf("size of p4: %lu bytes\n", sizeof(p4));

	return 0;
}
