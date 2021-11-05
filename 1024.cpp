#include<iostream>
#include <iomanip>
using namespace std;


int main()
{
	int M;
	cin >> M;
	for (int a = 0;a < M;a++)
	{
		int N;
		cin >> N;
		int nums[500];
		double p[501];
		double q[501];

		for (int x = 0;x < N;x++)
		{
			cin >> nums[x];
		}
		for (int i = 1;i < N+1;i++)
			cin >> p[i];
		for (int i = 0;i <= N;i++)
			cin >> q[i];

		double** e = new double* [N+2];
		for (int i = 0; i < N+2; i++)
		{
			e[i] = new double[N+2];
		}
		double** w = new double* [N + 2];
		for (int i = 0; i < N + 2; i++)
		{
			w[i] = new double[N + 2];
		}
		for (int i = 1;i <= N + 1;i++)
		{
			w[i][i - 1] = q[i - 1];
			e[i][i - 1] = 0;
		}
		for (int len = 1;len <= N;++len)
		{
			for (int i = 1;i <= N - len + 1;++i)
			{
				int j = i + len - 1;
				e[i][j] = 10000;
				w[i][j] = w[i][j - 1] + p[j] + q[j];
				for (int k = i;k <= j;++k)
				{
					double temp = e[i][k - 1] + e[k + 1][j] + w[i][j];
					if (temp < e[i][j])
					{
						e[i][j] = temp;

					}
				}
			}
		}
		cout << fixed << setprecision(6) << e[1][N]<<endl;
	}

}
