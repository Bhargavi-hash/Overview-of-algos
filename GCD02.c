#include <stdio.h>

//**************************************************************************************
//                 Brute-Force implementation of GCD using Iteration
//**************************************************************************************

int gcd(int num1, int num2)
{
    int result = 1;

    int limit = num1 > num2 ? num2 : num1;
    for (int i = 2; i <= limit; i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
            result = i;
    }
    return result;
}

int main()
{
    int a, b;

    printf("Enter two numbers to find their GCD\n");

    printf("Enter first num: ");
    scanf("%d", &a);

    printf("Enter second num: ");
    scanf("%d", &b);

    int ans = gcd(a, b);
    printf("GCD of %d and %d = %d\n", a, b, ans);
}
