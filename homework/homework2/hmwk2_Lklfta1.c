/*
     hmwk2_Lklfta1.c
    
     Linn Erle Klofta
     Account: Lklfta1
     CSc 3320
     Program #2
     Due date:
    
     Description:
         This program implements a mini-game where the player tries to guess a randomly generated secret code. 
         The game provides feedback on whether the guess is too high or too low, as well as the number of 
         digits that are correct and in the right position, and the number of correct digits that are in 
         the wrong position.
     Input:
         The program takes a 3-digit number as input from the player. The player can also enter 'q' or 'Q' 
         to quit the game. The input is validated to ensure it is a valid number.
     Output:
         The program outputs the number of tries remaining, feedback on the player's guess (whether it's too 
         high or low, and how many digits are correct), and messages indicating whether the player has opened 
         the vault or failed to guess the code after exhausting all attempts.
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define TRIES 8
#define DIGITS 3
#define RANGE 9

// Function to check if the input guess is valid
int is_valid_input(char *input) {
    // Check for empty input
    if (strlen(input) < 2) return 0; // Account for the newline character

    // Check if the length matches the number of digits
    if (strlen(input) != DIGITS + 1) return 0; // +1 for the newline character

    // Check if all characters are digits
    for (int i = 0; i < DIGITS; i++) {
        if (!isdigit(input[i])) return 0;
    }
    return 1;
}

// Function to provide feedback about the guess
void get_feedback(int code[DIGITS], int guess[DIGITS], int *correct_position, int *correct_digit) {
    int code_used[DIGITS] = {0};
    int guess_used[DIGITS] = {0};
    *correct_position = 0;
    *correct_digit = 0;

    // First pass: check for correct position
    for (int i = 0; i < DIGITS; i++) {
        if (code[i] == guess[i]) {
            (*correct_position)++;
            code_used[i] = 1;
            guess_used[i] = 1;
        }
    }

    // Second pass: check for correct digits but wrong position
    for (int i = 0; i < DIGITS; i++) {
        for (int j = 0; j < DIGITS; j++) {
            if (i != j && code[i] == guess[j] && !code_used[i] && !guess_used[j]) {
                (*correct_digit)++;
                code_used[i] = 1;
                guess_used[j] = 1;
                break;
            }
        }
    }
}

int main() {
    int code[DIGITS];
    char input[100];
    int tries = TRIES;

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random code
    for (int i = 0; i < DIGITS; i++) {
        code[i] = rand() % (RANGE + 1);
    }

    printf("Welcome to the Vault Opening Game!\n");

    while (tries > 0) {
        printf("%d tries remain. What is the code? ", tries);
        fgets(input, sizeof(input), stdin);

        // Check for quit command
        if (input[0] == 'q' || input[0] == 'Q') {
            printf("You chose to quit the game. Goodbye!\n");
            return 0;
        }

        // Validate input
        if (!is_valid_input(input)) {
            printf("Invalid input. Please enter a %d-digit number.\n", DIGITS);
            continue;
        }

        int guess[DIGITS];
        for (int i = 0; i < DIGITS; i++) {
            guess[i] = input[i] - '0';  // Convert char to int
        }

        // Check if guess is correct
        int correct_position, correct_digit;
        get_feedback(code, guess, &correct_position, &correct_digit);

        if (correct_position == DIGITS) {
            printf("You opened the vault!\n");
            return 0;
        } else {
            // Compare guesses to code to determine higher/lower
            int code_value = 0, guess_value = 0;
            for (int i = 0; i < DIGITS; i++) {
                code_value = code_value * 10 + code[i];
                guess_value = guess_value * 10 + guess[i];
            }

            if (guess_value < code_value) {
                printf("Too low, %d digits are correct and in the right place, %d digits are correct and in the wrong place.\n",
                       correct_position, correct_digit);
            } else {
                printf("Too high, %d digits are correct and in the right place, %d digits are correct and in the wrong place.\n",
                       correct_position, correct_digit);
            }
        }
        
        tries--;
    }

    // If out of tries, reveal the code
    printf("The vault shuts down permanently due to too many incorrect attempts. You failed to open the vault!\n");
    printf("The secret code was ");
    for (int i = 0; i < DIGITS; i++) {
        printf("%d", code[i]);
    }
    printf("\n");

    return 0;
}

