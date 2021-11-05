#include<iostream>
using namespace std;
int INF = 1000000;

int main()
{
	int M;
	cin >> M;
	for (int x = 0;x < M;x++)
	{
		int n,E,s,t;
		cin >> n>>E>>s>>t;
		int g[501][501];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                g[i][j] = INF;
            }
		for (int i = 0; i <E; ++i) 
		{
			int x, y, v;
            cin >> x >> y >> v;
			if (g[x][y] >= v)
			{
				g[x][y] = v;
				g[y][x] = v;
			}
		}
		int dist[500];
        int i, j, k=s;
        int min;
        int tmp;
        int flag[500];     

        for (i = 1; i <= n; i++)
        {
            flag[i] = 0;              
            dist[i] = g[s][i];
        }

        flag[s] = 1;
        dist[s] = 0;

 
        for (i = 1; i <= n; i++)
        {
            min = INF;
            for (j = 1; j <= n; j++)
            {
                if (flag[j] == 0 && dist[j] < min)
                {
                    min = dist[j];
                    k = j;
                }
            }
            flag[k] = 1;
            for (j = 1; j <= n; j++)
            {
                tmp = (g[k][j] == INF ? INF : (min + g[k][j])); 
                if (flag[j] == 0 && (tmp < dist[j]))
                {
                    dist[j] = tmp;
                }
            }
        }
        cout << (dist[t]!=INF?dist[t]:-1)<<endl;

	}
}

