/* 
  scanf
*/

#include <stdio.h>

int main (int argc, char *argv[]) {
   int num, return_value;
   int sum = 0;
   printf("enter integer values:\n");
   while ((return_value = scanf("%d", &num)) == 1) {
       sum += num;
   }
 
   printf("the sum is: %d\n", sum);
   return 0;
}



