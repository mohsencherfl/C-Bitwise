#include <stdio.h>
#include <stdlib.h>

int main()
{
    int value1 = 15;
    int value2 = 40;

    printf("Before swapping the values: \n");
    printf("\tValue 1: %d \n", value1);
    printf("\tValue 2: %d \n", value2);

    value1 = value1 ^ value2;
    value2 = value1 ^ value2;
    value1 = value1 ^ value2;

    printf("After swapping the values: \n");
    printf("\tValue 1: %d \n", value1);
    printf("\tValue 2: %d \n", value2);

    return 0;
}
