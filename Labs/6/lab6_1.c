#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srandom(time(NULL));
    int i;
    int odd_or_even[2] = {0, 0};

    for(i=0; i<50; i++){
        int random_value = (random() % 100) + 1;
        
        random_value % 2 == 1 ? odd_or_even[0]++ : odd_or_even[1]++;        
    }
    printf("Odd count: %d\n", odd_or_even[0]);
    printf("Even count: %d\n", odd_or_even[1]);
}
