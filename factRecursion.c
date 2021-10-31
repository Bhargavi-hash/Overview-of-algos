#include <stdio.h>

int factorial(int n)
{
    // Base case
    if (n == 1)
        return 1;

    return n * factorial(n - 1);   // Recursive call
}

int main()
{
    int n; // 'n' is the integer of which we find the factorial.

    printf("Enter value of n: ");
    scanf("%d", &n); // Scanning the value of 'n'

    int ans = factorial(n); // Calling factorial() function and storing the final answer in 'ans'

    printf("Factorial(%d) = %d\n", n, ans);
}