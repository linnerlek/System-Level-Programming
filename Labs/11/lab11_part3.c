/*
 * Modified the fcopy program with some command line arguments
 * added the upper and lowercase conversion implementation
 * original from: Page 568 C Programming, a moden approach, K. N. King
 * Linn Klofta 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1 // 1 for on 0 for off

typedef enum {false, true} bool;

char convert_uppercase(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        ch = ch - 'a' + 'A';
    }
    return ch;
}

char convert_lowercase(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        ch = ch - 'A' + 'a';
    }
    return ch;
}

int main(int argc, char *argv[]) {
    FILE *source_fp, *dest_fp;
    int ch, i;
    bool help = false, uppercase = false, lowercase = false;
    char *input_file = NULL;
    char *output_file = NULL;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            help = true; // if -h is input print help info
        } else if (strcmp(argv[i], "-u") == 0) {
            uppercase = true; // if -u is input convert to uppercase text
        } else if (strcmp(argv[i], "-l") == 0) {
            lowercase = true; // if -l is input convert to lowercase text
        } else if (!input_file) {
            input_file = argv[i]; // if no input file has been specified set current to input
        } else if (!output_file) {
            output_file = argv[i]; // if no output file has been specified set current to output
        } else {
            fprintf(stderr, "Too many arguments provided. do -h for help\n");
            exit(EXIT_FAILURE);
        }
    }

    if (help) {
        printf("How to use: ./lab11_part2 [option] <source> <destination\n>");
        printf("Options:\n");
        printf("  -h        Display help info\n");
        printf("  -u        Convert text to uppercase\n");
        printf("  -l        Convert text to lowercase\n");
        exit(0);
    }

    if (uppercase && lowercase) {
        fprintf(stderr, "Error: can not specify both upper- and lowercase.\n");
        exit(EXIT_FAILURE);
    }

    if (!input_file || !output_file) {
        fprintf(stderr, "Error: expected a source- and a destination file\n");
        exit(EXIT_FAILURE);
    }



    // we use rb to allow for copying of binary files as well as text
    if ((source_fp = fopen(input_file, "rb")) == NULL) { 
        fprintf(stderr, "Can't open %s\n", input_file);
        exit(EXIT_FAILURE);
    }

    // we use wb to allow for copying binary files as well as text
    if ((dest_fp = fopen(output_file, "wb")) == NULL) { 
        fprintf(stderr, "Can't open %s\n", output_file);
        fclose(source_fp);
        exit(EXIT_FAILURE);
    }

    #if DEBUG
        printf("Debug info:\n");
        printf("    help: %s\n", help ? "true" : "false");
        printf("    uppercase: %s\n", uppercase ? "true" : "false");
        printf("    lowercase: %s\n", lowercase ? "true" : "false");
        printf("    input_file: '%s'\n", input_file ? input_file : "None");
        printf("    output_file: '%s'\n", output_file ? output_file : "None");
    #endif

    while ((ch = getc(source_fp)) != EOF) {
        if (uppercase) {
            ch = convert_uppercase(ch);
        } else if (lowercase) {
            ch = convert_lowercase(ch);
        }
        putc(ch, dest_fp);
    }
    
    fclose(source_fp);
    fclose(dest_fp);

    printf("File copied successfully to '%s'\n", output_file);
    return 0;
}
