/*
   Song name: Tall Trees
   Artist: (G)i-dle
   Album: Heat
   Release 2023
*/

#include <stdio.h>   // for input and output
#include <stdlib.h>  // for random number generation
#include <time.h>    // for seeding random number generator

int main() {
    char* lyrics[] = {
        "Branches exploding",
        "My leaves are golden stars, ah",
        "Birds love to breeze by",
        "Dogs come to see my bark, hmm-ah",
        "My expectations stay on low",
        "But you're the sun, you make them grow",
        "If there's an axe behind your back, just let me know",
        "'Cause tall trees fall hard, hard, hard, hard, hoo",
        "Tall trees fall hard, hard, hard, hard, hoo",
        "Tall trees fall hard",
        "So don't you break my"
    };

    int num_lines = sizeof(lyrics) / sizeof(lyrics[0]); // Get number of lines in the lyrics

    // Seed the random number generator using the current time
    srandom(time(NULL));

    // Prompt the user for input
    int n, i;
    printf("Enter the number of lines to display: ");
    scanf("%d", &n);
    
    // Print random lyrics N times
    for (i = 0; i < n; i++) {
        // Generate a random index between 0 and the number of lyrics
        int random_index = random() % num_lines;
        printf("%s\n", lyrics[random_index]);
    }

    return 0;
}
