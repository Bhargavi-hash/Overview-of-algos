#include <stdio.h>
#include <string.h>

int fib(int n)
{
    if (n < 2)
        return n;

    // Declaring variables to store
    // 1. Previous previous number
    // 2. Previous number
    // 3. Current number

    int PrevPrevNum, PrevNum = 0, CurrenNum = 1;

    for (int i = 1; i < n; i++)
    {
        PrevPrevNum = PrevNum;  // F(n-2) = F(n-1)

        PrevNum = CurrenNum;    // F(n-1) = F(n)

        CurrenNum = PrevPrevNum + PrevNum; // F(n) = F(n-1) + F(n-2)
    }
    return CurrenNum;
}

int main()
{
    int n;

    printf("\t--> Enter value of 'n': ");
    scanf("%d", &n);

    int ans = fib(n);

    printf("\t--> Fibonacci number of %d = %d\n", n, ans);
}