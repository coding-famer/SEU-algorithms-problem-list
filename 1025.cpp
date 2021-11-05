#include<iostream>
#include<string>
using namespace std;


int main()
{
	int M;
	cin >> M;
	for (int i = 0;i < M;i++)
	{
		int N;
		int c = 0;
		cin >> N;
		int* nums = new int[N];

		for (int x = 0;x < N;x++)
		{
			cin >> nums[x];
		}


		int ma = 0;

		int* dp = new int[N];

		for (int j = 0;j < N;j++)
			dp[j] = 1;
		for (int j = 0;j < N;j++)
		{
			for (int k = 0;k < j;k++)
			{

				if (nums[j] >= nums[k])
				{
					dp[j] = max(dp[j], dp[k] + 1);
				}
			}

		}
		for (int j = 0;j < N;j++)
			ma = max(ma, dp[j]);


		cout << ma << endl;
	}

}