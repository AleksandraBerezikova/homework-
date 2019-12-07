
/*
 Для чисел Фибоначчи известны некоторые тождества:
Докажите эти тождества и напишите программу для вычисления ЧФ с помощью разделяй и властвуй.

 */

#include <iostream>

using namespace std;

long long fib(int n)
{
    if(n == 1 || n == 2)
    {
        return 1;
    }

    if(n % 5 == 0)
    {
        if(n % 2 == 0)
        {
            long long a = fib(n / 5);
            return 25 * a*a*a*a*a + 25 * a*a*a + 5 * a;
        }
        else
        {
            long long a = fib(n / 5);
            return 25 * a*a*a*a*a - 25 * a*a*a + 5 * a;
        }
    }
    else if(n % 2 == 1)
    {
        long long a = fib(n / 2);
        long long b = fib(n / 2 + 1);
        return a * a + b * b;
    }
    else
    {
        long long a = fib(n / 2 - 1);
        long long b = fib(n / 2 + 1);
        return b * b - a * a;
    }
}

int main()
{
    int n;
    cin >> n;

    cout << fib(n);


    return 0;
}
