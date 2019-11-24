
/*
 Напишите программу находящую первые n составных чисел.
 Программа должна работать не более чем за O(n*log log n) шагов.
 */

#include <iostream>

using namespace std;

void sieve_of_eratosthenes(bool *array, int array_size)
{
    for(int i = 2; i < array_size; i++)
    {
        if(array[i] != true)
        {
            for(int j = 2*i; j < array_size; j = j + i)
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
    
    bool *composite = new bool[2 * n + 5];
    
    for(int i = 0; i < 2 * n + 5; i++)
    {
        composite[i] = false;
        
    }
    
    sieve_of_eratosthenes(composite, 2 * n + 5);
    
    int number_of_composites = 0;
    int i = 4;
    
    while (number_of_composites < n)
    {
        if(composite[i] == true )
        {
        
            cout << i << endl;
            number_of_composites = number_of_composites + 1;
            
        }
        i = i + 1;
    }
    
    return 0;
}
