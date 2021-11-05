#include<iostream>

using namespace std;
class point
{
public:
    int c;
    int d;
};
int compare(point a,point b)
{
    return a.d < b.d;
}
int main()
{
    int M;
    cin >> M;

    for (int x = 0;x < M;x++)
    {
        int n;
        cin >> n;
        int** g = new int* [n];
        for (int i = 0;i < n;i++)
        {
            g[i] = new int[n];
        }
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
            {
                g[i][j] = 0;
            }
        }
        point p[50000];
        for (int i = 0;i < n - 1;i++)
        {
            int u,v;
            cin >> u,v;
            g[u][v] = g[v][u] = 1;
            p[u].d++;
            p[v].d++;
        }

    }
}
