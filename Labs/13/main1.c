/*
 * Program from Glass and Ables, Unix for Programmers and Users
 * Ch 12, p 393
 *
 * MAIN 1.C
 */

#include <stdio.h>
#include <string.h>
#include "reverse.h"

main(int argc, char *argv[])
{
    char str [100];
    char reversed [100];

    printf("Enter a string to reverse: ");
    scanf("%99s", str);

    reverse(str, reversed);

    printf("Reversed string: %s\n", reversed);

    return 0;
}

