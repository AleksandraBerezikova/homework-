/*
  Число является палиндромом, если его когда его первая половина совпадает со второй половиной
Таким образом достаточно перебрать только все возможные половины, и зеркально достроить вторые половины


Напишите эффективную программу, находящую все числа длины n являющиеся палиндромами.
 В комментариях напишите, почему перебор - эффективный

*/

#include <iostream>

using namespace std;

void print_palindromes(short *v, int n, int length)
{
    if (length % 2 == 0)
    {
        while (v[0] != 10)
        {

            for (int i = 0; i < n; ++i)
            {
                cout << v[i];
            }
            for (int i = n - 1; i >= 0; i--)
            {
                cout << v[i];
            }

            cout << "\n";

            v[n - 1] = v[n - 1] + 1;
            if (v[n - 1] >= 10)
            {
                int i = n - 1;
                while (i > 0 && v[i] >= 10)
                {
                    v[i] = 0;
                    v[i - 1] = v[i - 1] + 1;
                    i = i - 1;
                }
            }
        }
    }
    else
    {
        while (v[0] != 10)
        {

            for (int i = 0; i < n; ++i)
            {
                cout << v[i];
            }
            for (int i = n - 2; i >= 0; - i)
            {
                cout << v[i];
            }

            cout << "\n";

            v[n - 1] = v[n - 1] + 1;
            if (v[n - 1] >= 10)
            {
                int i = n - 1;
                while (i > 0 && v[i] >= 10)
                {
                    v[i] = 0;
                    v[i - 1] = v[i - 1] + 1;
                    i = i - 1;
                }
            }
        }
    }
}


int main()
{
    int n;
    cin >> n;

    short *v;
    if (n % 2 == 0)
    {
        v = new short[n / 2];
        v[0] = 1;

        for (int i = 1; i < n / 2; ++i)
        {
            v[i] = 0;
        }

        print_palindromes(v, n / 2, n);
    }
    else
    {
        v = new short[n / 2 + 1];
        v[0] = 1;

        for(int i = 1; i < n / 2 + 1; ++i)
        {
            v[i] = 0;
        }

        print_palindromes(v, n / 2 + 1, n);

    }

    return 0;
}
