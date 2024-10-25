/*
 * changes to the /usr/lib directory and uses du to list the disk usage. outputs the 3 largest files
 * or directories and the remaining usage. includes a debug for testing handling spaces in strings
 * Linn Klofta
 * 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/param.h>

#define BUFFER_SIZE 1024
#define DEBUG 1  // 1 to debug 0 to not

// function to find the next space or tab
char *findNextSpace(char *ptr) {
    while (*ptr != '\0' && *ptr != ' ' && *ptr != '\t') {
        ptr++;
    }
    return ptr;
}

void testFindNextSpace() {
    int i;
    char testStrings[][BUFFER_SIZE] = {
        "123 abc",
        "123\tabc",
        "123abc",
        " 123abc",
        "\t123abc"
    };

    for (i = 0; i < 5; i++) {
        char *result = findNextSpace(testStrings[i]);
        printf("Test %d: \"%s\"\n", i + 1, result);
    }
}

int main() {
    FILE *myProcess;
    char buffer[BUFFER_SIZE];
    char filename[BUFFER_SIZE];
    int size, count = 0;
    int sizes[3] = {0};  // stores 3 entries all initialized to 0 to start off

    FILE *outputFile = fopen("output.txt", "w"); // sends the output to output.txt
    if (outputFile == NULL) {
        perror("Error opening output file");
        exit(1);
    }
    // print the initial directory
    char cwd[MAXPATHLEN];
    getcwd(cwd, sizeof(cwd));
    fprintf(outputFile, "Initial directory is %s\n", cwd);

    // change to the /usr/lib directory
    if (chdir("/usr/lib") != 0) {
        perror("chdir failed");
        fclose(outputFile);
        exit(1);
    }

    // use popen to activate the du command
    myProcess = popen("du -k | sort -nr", "r");
    if (myProcess == NULL) {
        fprintf(outputFile, "Error: du command failed\n");
        fclose(outputFile);
        exit(1);
    }

    while (fgets(buffer, BUFFER_SIZE, myProcess) != NULL && count < 3) {
        buffer[strcspn(buffer, "\n")] = '\0'; // removes  newline character

        // because i use %[^\n] i dont have to use strncpy because i directly copy the filename
        // from buffer using sscanf and place it in the filename variable
        if(sscanf(buffer, "%d %[^\n]", &size, filename) == 2) {
            fprintf(outputFile, "File %d: Size = %d KB, Name = %s\n", count + 1, size, filename);
            sizes[count] = size;  // store size of file
            count++;
        }
    }   
    
    // close the process
    pclose(myProcess);

    // calculate the remaining space by subtracting the second and third from the firt entry
    if (count >= 3) {
        int total = sizes[0];
        int used = sizes[1] + sizes[2];
        fprintf(outputFile, "The rest use %d KB\n", total - used);
    }

    // runs the test function if DEBUG is set to 1
    if (DEBUG) {
        testFindNextSpace();
        exit(0);
    }
    fclose(outputFile);
    return 0;
}

