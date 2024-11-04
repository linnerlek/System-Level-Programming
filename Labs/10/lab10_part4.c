/*
 * stores a list of cheese in a 2d array using strncpy() and sorts the list based on
 * input from the user
 * Linn Klofta
 * 2024
 */


#include <stdio.h>
#include <string.h>

#define MAX_CHEESE 8
#define MAX_LENGTH 21

void sortCheese (char cheese[][MAX_LENGTH], int ascending) {
    char temp[MAX_LENGTH];
    int i, j;
    for (i = 0; i < MAX_CHEESE - 1; i++) { // outer loop sorts
        for (j = 0; j < MAX_CHEESE - 1 - i; j++) { // innter loop compares
            int compare = strncmp(cheese[j], cheese[j + 1], MAX_LENGTH); // compares names
            if (ascending ? (compare > 0) : (compare < 0)) { // sorts based on input
                // swaps if the order is wrong
                strncpy(temp, cheese[j], MAX_LENGTH);
                strncpy(cheese[j], cheese[j + 1], MAX_LENGTH);
                strncpy(cheese[j + 1], temp, MAX_LENGTH);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    char cheese[MAX_CHEESE][MAX_LENGTH];
    int i;

    char *random_cheese[] = {
        "Gouda",
        "Brie",
        "Cheddar",
        "Norwegia",
        "Havarti",
        "American",
        "Blue Cheese",
        "Colby"
    };

    for (i = 0; i < MAX_CHEESE; i++) {
        strncpy(cheese[i], random_cheese[i], MAX_LENGTH -1);
        cheese[i][MAX_LENGTH - 1] = '\0';
    }

    if (argc > 1) {
        if (strncmp(argv[1], "-asc", MAX_LENGTH) == 0) { //if the user inputs -asc sort in ascending order
            printf("Sorting in ascending alphabetical order:\n");
            sortCheese(cheese, 1);
        } else if (strncmp(argv[1], "-desc", MAX_LENGTH) == 0) { //-desc sort descending order
            printf("Sorting in descending alphabetical order:\n");
            sortCheese(cheese, 0);
        } 
    } else {
        printf("Printing in random order:\n");
    }

    for (i = 0; i < MAX_CHEESE; i++) {
        printf("%s\n", cheese[i]);
    }

    return 0;
    
}
