/*
 * Reads and prints the contents of a file line by line with a buffer using fread
 * Linn Klofta
 * 2024
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 200
// i define bool for c89 compatability
#define bool int
#define true 1
#define false 0

bool printNextLine(char *buffer, char *ptr, int bufferFillLength, int *lineNumber, bool startedLineAlready) {
    char *lineStart = ptr;
    bool foundLineEnd = false;
    char *temp;

   // traverse through the buffer looking for character with ASCII value 10
    while (ptr < buffer + bufferFillLength) {
        if (*ptr == 10) {  
            foundLineEnd = true;
            break;
        }
        ptr++;
    }
    if (!startedLineAlready) {
        printf("%d \"", *lineNumber); // prints the line number, a space and then the first " 
        (*lineNumber)++;
    }
    // print the current part of the line
    for (temp = lineStart; temp < ptr; temp++) {
        putchar(*temp);
    }
    if (foundLineEnd) {
        printf("\"\n"); // prints a quote and newline character at the end of a line
        return false; 
    } else {
        return true;  // line incomplete, buffer needs to be refilled
     }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char BUFFER[BUFFER_SIZE];
    int current_line = 1;
    size_t bufferFillLength;
    bool startedLineAlready = false;
    
    if (argc != 2) {
        printf("usage: canopen filename\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r"); // opens the file
    if (fp == NULL) {
        printf("%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((bufferFillLength = fread(BUFFER, 1, BUFFER_SIZE, fp)) > 0) {
        char *ptr = BUFFER;

        while (ptr < BUFFER + bufferFillLength) {
            startedLineAlready = printNextLine(BUFFER, ptr, bufferFillLength, &current_line, startedLineAlready);

            if (!startedLineAlready) {
            // if we finished the line, move the pointer past the newline
                while (ptr < BUFFER + bufferFillLength && *ptr != 10) {
                    ptr++;
                }
                ptr++;  // move past the line-feed character
            } else {
                break;              
            }
        }
    }

    if (feof(fp)) {
        printf("%s was opened and read successfully\n", argv[1]);
    }
    fclose(fp);
    return 0;
}
