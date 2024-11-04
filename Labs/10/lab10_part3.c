/*
 * changes lowercase characters to uppercase and vice versa via command line input.
 * Linn Klofta
 * 2024
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    char *input = argv[1];
    int i = 0;

    if (argc < 2) {
        printf("provide a string as a command line argument when running the code.\n");
        return 1;
    }

    while (input[i] != '\0') {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            putchar(input[i] + 'a' - 'A');
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            putchar(input[i] + 'A' - 'a');
        } else {
            putchar(input[i]);
        }
        i++;
    }
    // putchar('\n'); 
    // i would put this in my code if i could so the output is more clear but
    // since the instructions said not to put a newline character i will leave it commented.
    
    return 0;
}
