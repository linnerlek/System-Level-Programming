/* 
  scanf
*/

#include <stdio.h>

int main (int argc, char *argv[]) {
   int num, return_value = 0;
   printf("enter an integer value:\n"); 
   return_value = scanf("%d", &num);
   printf("you entered:  %d\n", num);
   printf("scanf returned the value: %d\n", return_value);
   return 0;
}

