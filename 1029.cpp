#include<iostream>
using namespace std;
int MaxInt = 1000000;

int main()
{
    int M;
    cin >> M;
    for (int x = 0;x < M;x++)
    {
        int n, E;
        cin >> n >> E;
        int g[501][501];
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
            {
                g[i][j] = MaxInt;
            }
        for (int i = 1; i <= E; ++i)
        {
            int x, y, v;
            cin >> x >> y >> v;
            if (g[x][y] >= v)
            {
                g[x][y] = v;
                g[y][x] = v;
            }
        }
		int ans = 0;
		int cedge[501];

		int lowest[501];

		bool* f = new bool[n + 2];
		f[1] = true;
		for (int i = 2; i <= n; i++)
		{
			lowest[i] = g[1][i];
			cedge[i] = 1;
			f[i] = false;
		}
		for (int i = 1; i < n; i++)
		{
			int min = MaxInt;
			int j = 1;
			for (int k = 2; k <= n; k++)
			{
				if (lowest[k] < min && (!f[k]))
				{
					min = lowest[k];
					j = k;
				}
			}
			f[j] = true;
			ans += min;
			for (int k = 2; k <= n; k++)
			{
				if ((g[j][k] < lowest[k] && (!f[k])))
				{
					lowest[k] = g[j][k];
					cedge[k] = j;
				}
			}
		}
		int d = 0;
		for (int i = 1; i <= n; i++)
			if (f[i])d++;
		if (d == n)
			cout << ans << endl;
		else
			cout << "-1" << endl;

    }
}