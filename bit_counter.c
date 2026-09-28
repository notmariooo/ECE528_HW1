#include <stdio.h>

int main()
{
    int number;
    int count = 0;

    printf("Enter a non-negative integer: ");
    scanf("%d", &number);

    if (number < 0)
    {
        printf("Invalid input\n");
    }
    else
    {
        while (number != 0)
        {
            number &= (number - 1);
            count++;
        }

        printf("Number of bits set to 1: %d\n", count);
    }

    printf("Mario Perez\n");

    return 0;
}