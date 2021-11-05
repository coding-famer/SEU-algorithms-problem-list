#include <iostream>
using namespace std;
int knapsack(int* W, int* V, int n, int C)
{
    int value = 0;
    int** f = new int* [n];
    for (int i = 0; i < n; i++)
    {
        f[i] = new int[C + 1];
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= C;j++)
            f[i][j] = 0;

    for (int i = 1; i <= C; i++)
    {
        f[0][i] = (i < W[0]) ? 0 : V[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int y = 1; y <= C; y++)
        {
            if (y >= W[i])
            {
                f[i][y] = (f[i - 1][y] > (f[i - 1][y - W[i]] + V[i])) ? f[i - 1][y] : (f[i - 1][y - W[i]] + V[i]);
            }
            else {
                f[i][y] = f[i - 1][y];
            }
        }
    }
    value = f[n - 1][C];
    return value;
}
int main()
{
    int M;
    cin >> M;

    for (int x = 0;x < M;x++)
    {
        int N, C;
        cin >> N >> C;
        int s[50000] = { 0 };
        int v[50000] = { 0 };
        for (int i = 0;i < N;++i)
        {
            cin >> s[i] >> v[i];
        }
        cout << knapsack(s, v, N, C) << endl;
    }
}