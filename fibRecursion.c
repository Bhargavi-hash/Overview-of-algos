#include <stdio.h>
#include <string.h>

int fib(int n)
{
    if (n < 2)
        return n;
    return fib(n-1) + fib(n-2);
}

int main()
{
    int n;  

    printf("\t--> Enter value of 'n': ");
    scanf("%d", &n);
    
    int ans = fib(n);

    printf("\t--> Fibonacci number of %d = %d\n", n, ans);
}