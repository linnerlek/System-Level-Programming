#include <stdio.h>

int main(void) {
    int number;
    printf("Enter integer values: \n");

    while (scanf("%d", &number) == 1) {
        printf("You entered: %d\n", number);
    }
    printf("Exiting program\n");
    return 0;
}
