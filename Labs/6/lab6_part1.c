/*
Frequency of odd and even numbers
Linn Klofta
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, num;
    int frequencies[2] = {0, 0};  // frequencies[0] for even, frequencies[1] for odd

    // Seed the random number generator
    srand(time(NULL));

    // Generate 50 random numbers between 1 and 100
    for (i = 0; i < 50; i++) {
        num = (random() % 100) + 1;  // Generates a number between 1 and 100
        if (num % 2 == 0) {
            frequencies[0]++;  // Increment the even count
        } else {
            frequencies[1]++;  // Increment the odd count
        }
    }

    // Print the frequencies
    printf("Frequency of even numbers: %d\n", frequencies[0]);
    printf("Frequency of odd numbers: %d\n", frequencies[1]);

    return 0;
}

