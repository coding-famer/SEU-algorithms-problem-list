#include<iostream>
#include<cstring>
using namespace std;


int main()
{
	int M;
	cin >> M;
	for (int x = 0;x < M;x++)
	{
		int N,K;
		long long c = 0;
		cin >> N>>K;
		long long nums[20];
		long long sum[20];
		long long dp[20][20];
		memset(dp, 0, sizeof(dp));
		for (int i = 0;i < N;i++)
		{
			cin >> nums[i];
		}
		sum[0] = nums[0];
		for (int i = 1;i < N;i++)
		{
			sum[i] = sum[i - 1] + nums[i];
		}
		for (int i = 0;i < N;i++)
		{
			dp[i][0] = sum[i];
		}
		for (int i = 1;i < N;i++)
		{
			for (int j = 1;j <= K;j++)
			{
				for (int k = 1;k <= i;k++)
				{
					int s = sum[i] - sum[k - 1];
					dp[i][j] = max(dp[k - 1][j - 1] * s, dp[i][j]);
				}
			}
		}
		cout << dp[N - 1][K]<<endl;
	}

}
