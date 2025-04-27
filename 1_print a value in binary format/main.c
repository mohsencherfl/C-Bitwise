#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char value = 200 ;
    unsigned char mask = 1;
    mask <<= 7;

    for(int i=0; i<8; i++)
    {
        if((mask & value) == 0)
            printf("0");
        else
            printf("1");

        mask >>= 1;
    }


    return 0;
}

