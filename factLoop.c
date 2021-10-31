#include <stdio.h>

int factorial(int n)
{
    int result = 1;

    for(int i = 1; i <= n; i++)
    {
        result = result * i;   
    }
    /*
        When i = 1:(First iteration)
            result = 1 * 1 = 1 ---> 1!
        When i = 2:(Second iteration)
            result = 1 * 2 = 2 ---> 2!
        When i = 3:(Third iteration)
            result = 2 * 3 = 6 ---> 3!
                    ...................
    */

    return result;
}

int main()
{
    int n; // 'n' is the integer of which we find the factorial.     
    
    printf("Enter value of n: ");
    scanf("%d", &n);  // Scanning the value of 'n'

    int ans = factorial(n);  // Calling factorial() function and storing the final answer in 'ans'

    printf("Factorial(%d) = %d\n", n, ans);
}