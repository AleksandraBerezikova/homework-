/*
 Напишите программу, находящую k-ую порядковую статистику. Программа должна работать за время O(n) в среднем.

 */
#include <iostream>

using namespace std;

int part(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int kt(int arr[], int l, int r, int k)
{

    if (k > 0 && k <= r - l + 1) {


        int in = part(arr, l, r);


        if (in - l == k - 1)
            return arr[in];


        if (in - l > k - 1)
            return kt(arr, l, in - 1, k);


        return kt(arr, in + 1, r,
                           k - in + l - 1);
    }


    return INT_MAX;
}


int main()
{

    int n,k;
    cin >> k >> n;
    int *v = new int[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    cout << kt (v, 0, n - 1, k);
    return 0;
}

