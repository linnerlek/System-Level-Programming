/*
Random numbers frequency, odd and even count with user input
Linn Klofta
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, num, queried_number;
    int frequencies[101] = {0};  // Array to store frequencies of numbers 1-100 (index 0 is unused)
    int odd_count = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Generate 50 random numbers between 1 and 100
    for (i = 0; i < 50; i++) {
        num = (random() % 100) + 1;  // Generates a number between 1 and 100
        frequencies[num]++;
        
        // Check if the number is odd
        if (num % 2 != 0) {
            odd_count++;
        }
    }

    // Ask user for a specific number to check the frequency
    printf("Enter a number between 1 and 100 to check its frequency: ");
    scanf("%d", &queried_number);

    // Check if the queried number is within the valid range
    if (queried_number < 1 || queried_number > 100) {
        printf("The number is out of range.\n");
    } else if (frequencies[queried_number] == 0) {
        printf("This number never appears.\n");
    } else {
        printf("The frequency of %d is: %d\n", queried_number, frequencies[queried_number]);
    }

    // Calculate the percentage of odd numbers
    double odd_percentage = (odd_count / 50.0) * 100.0;

    // Print the counts and percentages of odd numbers
    printf("Total odd numbers: %d\n", odd_count);
    printf("Percentage of odd numbers: %.1f%%\n", odd_percentage);

    return 0;
}

