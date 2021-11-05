#include<iostream>
#include<string>
#include<cstring>
using namespace std;


int main()
{
	int M;
	cin >> M;
	
	for (int x = 0;x < M;x++)
	{
		int N, K;		
		cin >> N >> K;
		char str[41]; 
		int i, j, k;
		cin >> str;
		long long dp[41][7];
		memset(dp, 0, sizeof(dp));
		long long num[41][41];
		for (i = 0;i < N;i++)
		{
			long long temp = 0;
			for (j = i;j < N;j++)
			{
				temp = temp * 10 + str[j] - '0';
				num[i][j] = temp;
			}
		}
		for (i = 0;i < N;i++)
			dp[i][0] = num[0][i];
		for (i = 0;i < N;i++)
			for (j = 1;j <= K;j++)
				for (k = 0;k < i;k++)
					dp[i][j] = max(dp[k][j - 1] * num[k + 1][i], dp[i][j]);
		cout <<  dp[N - 1][K] << endl;
	}
}