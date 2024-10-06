#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    srandom(time(NULL));
    int frequencies[101] = {0};
    int i, random_value, number_to_check;

    for(i=0; i<50; i++){
        int random_value = (random() % 100) + 1;   
        frequencies[random_value]++;   
    }
    printf("Enter a number between 1-100 to check its frequency: ");
    scanf("%d", &number_to_check);

    if (number_to_check < 1 || number_to_check > 100){
        printf("Invalid, enter a number between 1 and 100.\n");
    } else {
        printf("The number %d was generated %d time(s).\n", number_to_check, frequencies[number_to_check]);
    }
    
    return 0;
}
