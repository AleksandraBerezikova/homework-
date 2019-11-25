

/* 
Напишите функцию вычисляющую праймориал числа. Программа должна работать не 
более чем за O(n*log log n) шагов. 
*/

#include <iostream>

using namespace std;

void sieve_of_eratosthenes(bool *array, int array_size)
{
    for (int i = 2; i < array_size; i++)
    {
        if (array[i] != true)
        {
            for (int j = 2 * i; j < array_size; j = j + i)
            {
                array[j] = true;
            }
        }
    }
}


int main()
{
    int n;
    cin >> n;

    bool *composite = new bool[n + 1];

    for (int i = 0; i <= n; i++)
    {
        composite[i] = false;

    }

    sieve_of_eratosthenes(composite, n + 1);

    long long primorial = 1;

    for(int i = 2; i <= n; ++i)
    {
        if(composite[i] == false)
        {
            primorial = primorial * (1LL * i);
        }
    }

    cout << primorial;

    delete[] composite;

    return 0;
}
