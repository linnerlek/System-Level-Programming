/*
 * Program from Glass and Ables, Unix for Programmers and Users
 * Ch 12, p 393
 *
 * REVERSE.C
 */

#include <stdio.h>
#include "reverse.h"

reverse (before, after)

char *before;
char *after;

{
    int i, j, len;

    len = strlen (before);

    for (j = len - 1, i = 0; j >= 0; j--, i++)
        after [i] = before [j];
    after[len] = NULL;
}
