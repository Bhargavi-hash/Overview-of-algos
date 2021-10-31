#include <stdio.h>

//**************************************************************************************
//                           Euclidean Algorithm 
//**************************************************************************************

int gcd(int num1, int num2)
{
    if (num1 == 0)
       return num2;
    if (num2 == 0)
       return num1;
 
    // base case
    if (num1 == num2)
        return num1;
 
    // a is greater
    if (num1 > num2)
        return gcd(num1-num2, num2);
    return gcd(num1, num2-num1);
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