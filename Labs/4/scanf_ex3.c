/* 
  scanf
*/

#include <stdio.h>

int main (int argc, char *argv[]) {
   int num, return_value;
   printf("enter integer values:\n");
   while ((return_value = scanf("%d", &num)) == 1) {
       printf("You entered: %d\n", num);
   }
 
   printf("scanf returned the value: %d\n", return_value);
   return 0;
}


