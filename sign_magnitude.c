#include <stdio.h>

int main()
{
    int number;
    int absolute;

    printf("Enter an integer: ");
    scanf("%d", &number);

    if (number > 0)
    {
        printf("The number is positive.\n");
        absolute = number;
    }
    else if (number < 0)
    {
        printf("The number is negative.\n");
        absolute = -number;
    }
    else
    {
        printf("The number is zero.\n");
        absolute = 0;
    }

    printf("Absolute value: %d\n", absolute);
    printf("Mario Perez\n");

    return 0;
}