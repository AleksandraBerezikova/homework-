/*
Напишите эффективную процедуру, выписывающую из массива длины n все элементы, у которых произведение ненулевых цифр больше k.
 В комментариях напишите, почему перебор - эффективный
*/


/*
*Перебор эффективный потому, что работает за линейное время от длины массива.
*По крайней мере нам нужно просмотреть хотя бы раз каждый эл-т массива, что дает оценку снизу на асимптотику как O(n)
*
*
*
*/

#include <iostream>
#include <string>

using namespace std;

void procedure(string *number, int *prod, int n, int k)
{
    for(int i = 0; i < n; ++i)
    {
        if (prod[i] > k)
        {
            cout << number[i] << "\n";
        }
    }
}


int main()
{


    int n, k;
    cin >> n >> k;

    string *number = new string[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> number[i];
    }

    int *product_of_digits = new int[n];

    int c = 1;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < number[i].size(); ++j)
        {
            if(number[i][j] != '0')
            {
                c *= int(number[i][j]) - int('0');
            }
        }
        product_of_digits[i] = c;
        c = 1;
    }

    procedure(number, product_of_digits, n, k);


    return 0;
}
