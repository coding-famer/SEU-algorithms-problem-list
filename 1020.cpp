#include <iostream>
using namespace std;
int main()
{
    int M;
    cin >> M;

    for (int x = 0;x < M;x++)
    {
        int N;
        cin >> N;
		int nums[1000] = { 0 };
		int A[500] = { 0 };
        for (int i = 0;i < 2*N;i++)
        {
			cin >> nums[i];
        }
		A[0] = nums[0];
		for (int i = 1;i < 2 * N;i++)
		{
			if (i % 2 == 0)
				A[i / 2] = nums[i];
		}
		A[N] = nums[2 * N-1];
		//for (int i = 0;i <= N;i++)
		//{
		//	cout << A[i] << " ";
		//}
		//cout << endl;
		int l, i, j, k;
		int dp[500][500];
		for (i = 1; i <= N; i++)
		{
			dp[i][i] = 0;
		}
		for (l = 2; l <= N; l++)
		{
			for (i = 1; i <= N - l + 1; i++)
			{
				j = i + l - 1;
				dp[i][j] = dp[i][i] + dp[i + 1][j] + A[i - 1] * A[i] * A[j];
				for (k = i + 1; k < j; k++)
				{
					int t = dp[i][k] + dp[k + 1][j] + A[i - 1] * A[k] * A[j];
					if (t < dp[i][j])
					{
						dp[i][j] = t;
					}
				}
			}
		}
		cout << dp[1][N]<<endl;
    }
}