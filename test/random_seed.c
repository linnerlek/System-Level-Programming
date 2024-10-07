#include <stdio.h>
#include <stdlib.h>

int main(void){
    int seed, i, values;
    int count[4] = {0, 0, 0, 0};
    float percentage[4];

    printf("Enter a seed value (0 to quit): ");
    scanf("%d", &seed);

    if (seed == 0){
        printf("Quitting program\n");
        exit(0);
    }
    
    printf("Enter number of values to generate: ");
    scanf("%d", &values);

    srandom(seed);
    
    for (i = 0; i<values; i++){
        int random_value = random() % 4;

        switch (random_value){
            case 0:
                count[0]++;
                break;
            case 1:
                count[1]++;
                break;
            case 2:
                count[2]++;
                break;
            case 3:
                count[3]++;
                break;
        }
    }

    for (i=0; i<4; i++){
        percentage[i] = ( (float)count[i] / values ) * 100;
    }    

    printf("Counts of generated numbers:\n");
    printf("0: %d (%.1f%%)\n", count[0], percentage[0]);
    printf("1: %d (%.1f%%)\n", count[1], percentage[1]);
    printf("2: %d (%.1f%%)\n", count[2], percentage[2]);
    printf("3: %d (%.1f%%)\n", count[3], percentage[3]);

    return 0;
}
