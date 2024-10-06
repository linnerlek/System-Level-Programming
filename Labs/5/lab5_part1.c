/*
  random number generator
  Linn Klofta  

 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int seed;
    int i; // declares the loop vaiable outside the for loop so it works with C89

    while (1){
        printf("Enter a seed value (or 0 to quit): ");
        scanf("%d", &seed);

        // check if user inserts 0 to quit
        if (seed == 0){
            printf("Exiting the program.\n");
            break;
        }

        srand(seed); // give the seed to the random number generator
        
        // Generate and print 5 random numbers
        printf("Random numbers with seed %d:\n", seed);
        for (i = 0; i<5; i++){
            printf("%d\n", rand());
        }
        printf("\n");
    }
    return 0;
}
