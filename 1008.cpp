#include<iostream>
#include<string>
using namespace std;


int main()
{
	int M;
	cin >> M;
	int* ret = new int[M];
	int Max = 0;
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

					if (nums[j] <= nums[k])
					{
						dp[j] = max(dp[j], dp[k] + 1);
					}
				}

			}
			for (int j = 0;j < N;j++)
				ma = max(ma, dp[j]);

			int m = 0;
			int j = 0;
			for (int x = 0; x < N; x++) {
				for (j = 0; j < m; j++) {  
					if (nums[j] >= nums[x])  
									
						break;
				}
				if (j < m) 
					nums[j] = nums[x];
				else {		
					nums[m] = nums[x];
					m++;
				}
			}	
		cout << ma << " " << m << endl;
	}

}



//int main()
//{
//	int M;
//	cin >> M;
//	int* ret = new int[M];
//	int Max = 0;
//	for (int i = 0;i < M;i++)
//	{
//		int N;
//		int c = 0;
//		cin >> N;
//		int* nums = new int[N];
//		int* a = new int[N];
//
//		for (int x = 0;x < N;x++)
//			a[x] = 0;
//		for (int x = 0;x < N;x++)
//		{
//			cin >> nums[x];
//		}
//
//		int count = 0;
//		int r = 1;
//		int ma = 0;
//		while (count < N)
//		{
//			int* dp = new int[N];
//
//			for (int j = 0;j < N;j++)
//				dp[j] = 1;
//			for (int j = 0;j < N;j++)
//			{
//				for (int k = 0;k < j;k++)
//				{
//
//					if (nums[j] <= nums[k] && a[j] == 0 && a[k] == 0)
//					{
//						dp[j] = max(dp[j], dp[k] + 1);
//					}
//				}
//				if (j == N - 1)
//					r++;
//			}
//			for (int j = 0;j < N;j++)
//				ma = max(ma, dp[j]);
//			if (r == 2)
//			{
//				Max = ma;
//			}
//			count = count + ma;
//			for (int j = N - 1;j >= 0;j--)
//			{
//				if (dp[j] == ma)
//				{
//					a[j] = r - 1;
//					ma--;
//				}
//			}
//
//		}
//		cout << Max << " " << r - 1 << endl;
//	}
//
//}