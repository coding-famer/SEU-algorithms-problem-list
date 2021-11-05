#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct E {
	int s, f, v;
};

bool cmp(E a, E b) {
	return a.f < b.f;
}

int main()
{
	int M;
	cin >> M;
	for (int x = 0;x < M;x++)
	{
		int N;
		cin >> N;
		E* e = new E[N+1];
		for (int i = 1; i <= N; ++i) {
			cin >> e[i].s >> e[i].f >> e[i].v;
		}
		sort(e+1, e + N+1, cmp);
		int p[10002];
		int dp[10002];
		memset(p, 0, sizeof(p));
		memset(dp, 0, sizeof(dp));
		for (int i = 1;i <= N;i++)
		{
			for (int j = i - 1;j > 0;j--)
			{
				if (e[j].f <= e[i].s) 
				{
					p[i] = j;
					break;
				}
			}
		}
		for (int i = 1;i <= N;i++)
		{
			dp[i] = max(dp[i - 1], dp[p[i]] + e[i].v);
		}
		cout << dp[N] << endl;
	}
}
