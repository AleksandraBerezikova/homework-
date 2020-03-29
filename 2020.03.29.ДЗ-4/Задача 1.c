#include <iostream>
#include <vector>
#include <string>
using namespace std;


int m(char c1, char c2)
{
    if(c1 != c2)
    {
        return 12;
    }
    else return 0;
}

int levenshtein_distance(string a, string b)
{
    int M,N;
    M = a.length();
    N = b.length();

    vector<vector<int>>D(M, vector<int>(N));
    for(int i = 0; i < M; ++i)
    {
        for(int j = 0;j  < N; ++j)
        {
            D[i][j] = 0;
        }
    }

    for(int j = 1; j < N; ++j)
    {
        D[0][j] = D[0][j - 1] + 15;
    }

    for(int i = 1; i < M; ++i)
    {
        D[i][0] = D[i - 1][0] + 20;
        {
            for(int j = 1; j < N; ++j)
            {
                D[i][j] = min(min(D[i - 1][j] + 20, D[i][j -1] + 15), D[i - 1][j - 1] + m(a[i],b[j]));

            }

        }
    }


    return D[M-1][N-1];


}

int main()
{
    string a, b;
    cin >> a >> b;

    cout << levenshtein_distance(a, b);

    return 0;
}
