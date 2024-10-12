/*
 * Program taken from Lab8
 *
 * Linn Klofta 2024
 */

#include <stdio.h>

int main(){
	int arr[5] = {1,2,3,4,5};
	int *p1 = &arr;
	char *p2 = &arr;

	printf("%p\n", p1);
	printf("%p\n", p1+1);

	printf("%p\n", p2);
	printf("%p\n", p2+1);
	return 0;
}
