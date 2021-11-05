#include<iostream>
using namespace std;
const int maxdist = 9999;

void Dijkstra(int n, int v, int* dist, int d[][500])
{
    int s[500];
    for (int i = 1; i <= n;i++)
    {
        dist[i] = d[v][i];

    }
    dist[v] = 0;
    s[v] = true;
    for (int i = 2; i <= n;i++)
    {
        int best = v;
        int temp = maxdist;
        for (int j = 1; j <= n;j++)
        {
            if (!s[j] && dist[j] < temp)
            {
                temp = dist[j];
                best = j;
            }
        }
        s[best] = true;
        for (int j = 1; j <= n;j++)
        {
            if (!s[j] && d[best][j] != maxdist)
            {
                int newdist = dist[best] + d[best][j];
                if (newdist < dist[j])
                {
                    dist[j] = newdist;
                }
            }
        }
    }
}


int main()
{
	int M;
	cin >> M;

	for (int i = 0;i < M;i++)
	{
		int n,E,s,t,M;
		cin >> n>>E>>s>>t>>M;
		int B[500];
		int G[500][500];
		for (int i = 0;i < n;i++)
		{
			cin >> B[i];
		}
		for (int i = 0;i < E;i++)
		{
			int x, y, w;
			cin >> x >> y >> w;
			G[x][y] = min(G[x][y], w);
			G[y][x] = min(G[y][x], w);
		}
        int dist[500];
        Dijkstra(n, s, dist, G);
        cout<<(dist[t]<9000?dist[t]:-1)<<endl;



	}

}



