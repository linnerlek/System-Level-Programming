/* 
  scanf
*/

#include <stdio.h>

int main (int argc, char *argv[]) {
   int num, count = 0;
   printf("enter an integer value:\n"); 
   count = scanf("%d", &num);
   printf("you entered:  %d\n", num);

   return 0;
}
