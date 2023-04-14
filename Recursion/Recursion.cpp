#include <iostream>
using namespace std;

class Recursion
{
private:
    /* data */
public:
    Recursion(/* args */);
    ~Recursion();
    int factorial(int n);
    int Fibonacci(int n);
    void Print(char array[]);
    void RevPrint(char array[]);
    void RemoveConsicutiveDups(char array[]);
    void PrintSubSeq(string input, string output);
    int Length(char array[]);
    int ConvertToInt(char array[], int i);
    void Permutation(char arra[], int i = 0);
    int toh(int n);
    void PrintTohSteps(int n, char s, char d, char h);
};

Recursion::Recursion(/* args */)
{
}

Recursion::~Recursion()
{
}

int Recursion::factorial(int n)
{
    if (n < 0)
        return n;
    else if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int Recursion::Fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2);
}

void Recursion::Print(char array[])
{
    if (array[0] == '\0')
        return;

    cout << array[0];
    Print(array + 1);
}

void Recursion::RevPrint(char array[])
{
    if (array[0] == '\0')
        return;

    RevPrint(array + 1);
    cout << array[0];
}

void Recursion::RemoveConsicutiveDups(char array[])
{
    if (array[0] == '\0')
    {
        return;
    }

    if (array[0] != array[1])
        RemoveConsicutiveDups(array + 1);
    else
    {
        for (int i = 0; array[i] != '\0'; i++)
        {
            array[i] = array[i + 1];
        }
        RemoveConsicutiveDups(array);
    }
}

void Recursion::PrintSubSeq(string input, string output)
{
    if (input.length() == 0)
    {
        cout << output << endl;
        return;
    }

    PrintSubSeq(input.substr(1), output + input.substr(0, 1));
    PrintSubSeq(input.substr(1), output);
}

int Recursion::Length(char array[])
{
    if (array[0] == '\0')
        return 0;

    return 1 + Length(array + 1);
}

int Recursion::ConvertToInt(char array[], int i)
{
    if (i == 0)
        return 0;

    int smallAnswer = ConvertToInt(array, i - 1);
    int lastDigit = array[i - 1] - '0';
    return smallAnswer * 10 + lastDigit;
}

void Recursion::Permutation(char arra[], int i)
{
    if (arra[i] == '\0')
    {
        cout << arra << endl;
        return;
    }

    for (int j = i; arra[j] != '\0'; j++)
    {
        swap(arra[i], arra[j]);
        Permutation(arra, i + 1);
        swap(arra[i], arra[j]);
    }
}

int Recursion::toh(int n)
{
    if (n == 0)
        return 0;

    return toh(n - 1) + 1 + toh(n - 1);
}

void Recursion::PrintTohSteps(int n, char s, char d, char h)
{
    if (n == 0)
    {
        return;
    }

    PrintTohSteps(n - 1, s, h, d);
    cout << "Moving disk " << n << " from " << s << " to " << d << endl;
    PrintTohSteps(n - 1, h, d, s);
}
