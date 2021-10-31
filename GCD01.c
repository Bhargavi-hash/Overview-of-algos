#include <stdio.h>

//**************************************************************************************
//                 Brute-Force implementation of GCD using Recursion
//**************************************************************************************

int gcd(int num1, int num2, int factor)
{
    // Base cases
    if (factor == 0 || factor == 1)
        return factor;
    if (num1 == 0 || num2 == 0)
        return 0;

    // Checking whether a factor or not.
    // This will be the highest common factor(HCF/GCD) since we have started moving
    // back from min(a, b)-1
    if (num1 % factor == 0 && num2 % factor == 0)
        return factor;

    // Proceed further if not a factor
    return gcd(num1, num2, factor - 1);
}

int main()
{
    int a, b;

    printf("Enter two numbers to find their GCD\n");

    printf("Enter first num: ");
    scanf("%d", &a);

    printf("Enter second num: ");
    scanf("%d", &b);

    // Conditional statement used to find the smallest of a and b
    int d = a < b ? a : b;

    int ans = gcd(a, b, d);
    printf("GCD of %d and %d = %d\n", a, b, ans);
}