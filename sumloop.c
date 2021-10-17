#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum(int list[], int length)
{
    int result = 0;
    while (length != 0)
    {
        length = length - 1;
        result = result + list[length];
    }

    return result;
}

int main()
{
    int length;
    int list[length];

    printf("\n\t\t\tAdding the elements of a list using recursion\n");

    printf("\t--> Enter number of elements in your list: ");
    scanf("%d", &length);

    printf("\t--> Enter the elements:\n");

    for (int i = 0; i < length; i++)
    {
        printf("\t--> ");
        scanf("%d", &list[i]);
    }

    int ans = sum(list, length);

    printf("\t--> Sum of elements: %d\n", ans);
}