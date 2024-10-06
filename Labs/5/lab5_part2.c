/*
  random numbers from 0 to 3 counter
  Linn Klofta  

 */

#include <stdio.h>
#include <stdlib.h>

// Generate random value between 0 and 3
int generate_random_value() {
    return rand() % 4; // Generates a value from 0 to 3
}

int main() {
    int seed;
    int num_values;
    int counts[4] = {0}; // array to hold counts for 0, 1, 2, and 3
    int i;               // loop variables
    int value;           // variable for generated values
    float percentage;    // Variable for % calculation

    // Prompt for a seed value
    printf("Enter a seed value: ");
    scanf("%d", &seed);
    srand(seed); // set seed value for random number generation

    // prompt for number of random values to generate
    printf("Enter the number of random values to generate: ");
    scanf("%d", &num_values);

    // Generate random values and count occurrences
    for (i = 0; i < num_values; i++) {
        value = generate_random_value();
        counts[value]++; // Increment the count for the generated value
    }

    // Display the counts
    printf("Counts:\n");
    for (i = 0; i < 4; i++) {
        printf("Value %d: %d\n", i, counts[i]);
    }
 
    // Calculate and display pecentages of each number
    printf("Percentages:\n");
    for (i = 0; i < 4; i++) {
        percentage = (counts[i] / (float)num_values) * 100;
        printf("Value %d: %.1f%%\n", i, percentage);
    }

    return 0;
}

