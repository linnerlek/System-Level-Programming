/*
 * Tells you if a program can be opened or not.
 * Reads a file and outputs the contents and line number
 *
 * Linn Klofta
 * 2024
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h> //So i can use strlen 

int main(int argc, char *argv[]) {
	FILE *fp;
	char BUFFER[1000];
	int current_line = 1;

	if (argc != 2) {
		printf("usage: canopen filename\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("%s can't be opened\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while(fgets(BUFFER, sizeof(BUFFER), fp)){
		size_t len = strlen(BUFFER);
		if (len > 0 && BUFFER[len - 1] == '\n'){ //checks for newline character
			BUFFER[len - 1] = '\0'; // replaces with a 0
		}
	
		printf("%d \"%s\"\n", current_line, BUFFER);
		current_line++;
	}
	printf("%s was opened and read successfully\n", argv[1]);
	fclose(fp);
	return 0;
}
