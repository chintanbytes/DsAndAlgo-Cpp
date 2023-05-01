#include <iostream>
#include <algorithm>

class DynamicProgramming
{
private:
    /* data */
public:
    DynamicProgramming(/* args */);
    ~DynamicProgramming();
    int Fibonacci(int n, int *arr);
    int Fibonacci(int n);
    int Fibonacci3(int n);
    int minStepsToOneBruteForce(int n);
    int minStepsToOneMemoization(int n, int *arr);
    int minStepsToOneBottomUp(int n);
    int climbingStairs(int n, int maxSteps);
};

DynamicProgramming::DynamicProgramming(/* args */)
{
}

DynamicProgramming::~DynamicProgramming()
{
}

int DynamicProgramming::Fibonacci(int n, int *arr)
{
    if (n == 0 || n == 1)
        return n;
    else
    {
        if (arr[n] != 0)
            return arr[n];

        int result = Fibonacci(n - 1, arr) + Fibonacci(n - 2, arr);
        arr[n] = result;
        return result;
    }
}

int DynamicProgramming::Fibonacci(int n)
{
    auto arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    int ans = arr[n];
    delete[] arr;
    return ans;
}

int DynamicProgramming::Fibonacci3(int n)
{
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        int a = i - 1;
        int b = i - 2;
        int c = a + b;
        ans += c;
    }
    return ans + 0 + 1;
}

// Allowed steps:
// 1) Decrement by 1
// 2) Divide by 2 if divisible by 2
// 3) Divide by 3 if divisible by 3
int DynamicProgramming::minStepsToOneBruteForce(int n)
{
    if (n <= 1)
    {
        return 0;
    }

    int x = minStepsToOneBruteForce(n - 1);
    int y = INT_MAX;
    int z = INT_MAX;
    if (n % 2 == 0)
    {
        y = minStepsToOneBruteForce(n / 2);
    }
    if (n % 3 == 0)
    {
        z = minStepsToOneBruteForce(n / 3);
    }

    // find min of all three plus 1 for the initial step
    int ans = std::min(x, std::min(y, z)) + 1;
    return ans;
}

int DynamicProgramming::minStepsToOneMemoization(int n, int *arr)
{
    if (n <= 1)
    {
        return 0;
    }

    if (arr[n] != 0)
        return arr[n];

    int x = minStepsToOneMemoization(n - 1, arr);

    int y = INT_MAX;
    int z = INT_MAX;
    if (n % 2 == 0)
    {
        y = minStepsToOneMemoization(n / 2, arr);
    }
    if (n % 3 == 0)
    {
        z = minStepsToOneMemoization(n / 3, arr);
    }

    // find min of all three plus 1 for the initial step
    int ans = std::min(x, std::min(y, z)) + 1;
    arr[n] = ans;
    return ans;
}

int DynamicProgramming::minStepsToOneBottomUp(int n)
{
    auto arr = new int[n + 1];

    arr[0] = 0;
    arr[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + 1;
        if (n % 2 == 0)
            arr[i] = std::min(arr[i], arr[i / 2] + 1);
        if (n % 3 == 0)
            arr[i] = std::min(arr[i], arr[i / 3] + 1);
    }

    int ans = arr[n];
    delete[] arr;
    return ans;
}

int DynamicProgramming::climbingStairs(int n, int maxSteps)
{
    auto arr = new int[n + 1];

    arr[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        for (int j = 1; j <= maxSteps; j++)
        {
            if (i - j < 0)
                break;
            ans += arr[i - j];
        }
        arr[i] = ans;
    }

    int ans = arr[n];
    delete[] arr;
    return ans;
}
