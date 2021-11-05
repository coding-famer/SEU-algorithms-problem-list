#include<iostream>

using namespace std;


int main()
{
    int M;
    cin >> M;

    for (int x = 0;x < M;x++)
    {
        int n;
        cin >> n;
        long long* c = new long long[n];
        long long* y = new long long[n];
        for (int i = 1;i <= n;i++)
        {
            cin >> c[i];
        }
        for (int i = 1;i <= n;i++)
        {
            cin >> y[i];
        }
        unsigned long long sum=0;
        for (int i = 1;i <= n;i++)
        {
            
            sum = sum + static_cast<long long>(c[i]) * static_cast<long long>(y[i]);
            int j = i+1;
            while (c[j] - c[i] > j - i)
            {
                sum = sum + (static_cast<long long>(c[i])+j-i) * static_cast<long long>(y[j]);
                j++;
            }
            i = j - 1;
        }
        cout << sum << endl;
    }
}
