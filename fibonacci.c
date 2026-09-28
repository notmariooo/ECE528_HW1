#include <stdio.h>

int main()
{
    int n;
    int first = 0;
    int second = 1;
    int next;
    int i;

    printf("Enter N: ");
    scanf("%d", &n);

    if (n < 2)
    {
        printf("Invalid input. N must be 2 or greater.\n");
    }
    else
    {
        printf("%d %d ", first, second);

        for (i = 2; i <= n; i++)
        {
            next = first + second;
            printf("%d ", next);

            first = second;
            second = next;
        }

        printf("\n");
    }

    printf("Mario Perez\n");

    return 0;
}