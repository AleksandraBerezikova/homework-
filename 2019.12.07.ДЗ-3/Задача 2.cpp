/*
Напишите программу на основе разделяй и властвуй позволяющую эффективно проверять принадлежность пары значений массиву.
 Например, пара (2,3) принадлежит массиву [1,2,3,5,7,11,13,17], а пара (3,4) - нет. 
 Можно считать, что количество запросов многократно превышает размер массива. 
 В комментариях напишите, почему перебор - эффективное

 Перебор эффективный благодаря бинарному поиску 
 */


#include <iostream>

using namespace std;

bool find(int *v, int n, int a)
{
    int l = 0;
    int r = n;

    while (l - r > 1)
    {
        int mid = (l + r) / 2;

        if (v[mid] > a )
        {
            r = mid;
        }
        else if (v[mid] < a )
        {
            l = mid;
        }
        else
        {
            return true;
        }
    }
    if(v[l] == a || v[r] == a)
    {
        return true;
    }

    return false;

};

int main()
{
    int x, n, y;

    cin >> x >> y >> n;

    int *v = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    if(find(v, n, x) && find(v, n, y))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;

}
