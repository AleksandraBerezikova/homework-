/*
Напишите программу, находящую все простые числа Ченя не превосходящие n. Программа должна работать не более чем за O(n*log log n) шагов.
*/

#include <iostream>

using namespace std;

void sieve_of_eratosthenes(int *array, int array_size)
{
    for (int i = 2; i < array_size; i++)
    {
        if (array[i] == 0)
        {
            for (int j = 2 * i; j < array_size; j = j + i)
            {
                array[j] = i;
            }
        }
    }
}


int main()
{
    int n;
    cin >> n;

    int *composite = new int[n + 3];

    for (int i = 0; i <= n; i++)
    {
        composite[i] = 0;

    }

    sieve_of_eratosthenes(composite, n + 3);

    composite[2] = 0;
    composite[1] = 1;



    for (int i = 2; i <= n; i++)
    {
        if (composite[i] == 0 && composite[i + 2] == 0)
        {
            cout << i << "\n";
        }
        else if (composite[i] == 0 && composite[(i + 2) / composite[i + 2]] == 0)
        {
            cout << i << "\n";
        }
    }


    delete[] composite;

    return 0;
}
