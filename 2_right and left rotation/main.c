#include <stdio.h>
#include <stdlib.h>

void userInput(char* choice, unsigned int* value, unsigned int* rotationNum)
{
    printf("Choose rotation direction (right rotation(1)/ left rotation(2): ");
    scanf("%d", choice);
    printf("Enter a number (32 bit unsigned number): ");
    scanf("%u", value);
    printf("Enter the number of times you want to rotate the binary value to the right: ");
    scanf("%u", rotationNum);
}

void printInBinary(unsigned int value, unsigned int leftMask)
{
    for(int i=0; i<32; i++)
    {
        if((leftMask & value) == 0)
            printf("0");
        else
            printf("1");

        leftMask >>= 1;
    }
    printf("\n");
}

void rotateRight(unsigned int rotationNum, unsigned int rightMask, unsigned int leftMask, unsigned int* value)
{
    for(int i=0; i<rotationNum; i++)
    {
        if((rightMask & *value) == 0)
        {
            *value >>= 1;
        }
        else
        {
            *value >>= 1;
            *value |= leftMask;
        }
    }
}

void rotateLeft(unsigned int rotationNum, unsigned int rightMask, unsigned int leftMask, unsigned int* value)
{
    for(int i=0; i<rotationNum; i++)
    {
        if((leftMask & *value) == 0)
        {
            *value <<= 1;
        }
        else
        {
            *value <<= 1;
            *value |= rightMask;
        }
    }
}

int main()
{
    unsigned int value;
    unsigned int rotationNum;
    unsigned int leftMask = 1, rightMask = 1;
    leftMask <<= 31;
    char choice;

    userInput(&choice, &value, &rotationNum);

    if(choice == 1)
    {
        printInBinary(value, leftMask);
        rotateRight(rotationNum, rightMask, leftMask, &value);
        printInBinary(value, leftMask);
    }
    if(choice == 2)
    {
        printInBinary(value, leftMask);
        rotateLeft(rotationNum, rightMask, leftMask, &value);
        printInBinary(value, leftMask);
    }

    return 0;

}
