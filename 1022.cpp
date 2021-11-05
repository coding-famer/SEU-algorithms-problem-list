#include <iostream>
#include<string>
using namespace std;

int main()
{
    int M;
    cin >> M;

    for (int x = 0;x < M;x++)
    {
        string a;
        string b;
        cin >>a >> b;
        int n = a.length();
        int m = b.length();
        int dp[501][501];
        for (int i = 0;i <= n;i++)
        {
            for (int j = 0;j <= m;j++)
                dp[i][j] = 0;
        }
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= m;j++)
            {
                if (a[i-1] == b[j-1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << dp[n][m]<<endl;
    }
}
