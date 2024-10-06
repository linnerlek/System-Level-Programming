#include <stdio.h>

int main(void){
    int number, return_value = 0;
    printf("Enter an integer: ");

    return_value = scanf("%d", &number);

    (return_value == 1) ? printf("you entered %d\n", number) : printf("Invalid, please enter an integer\n"); 
}
