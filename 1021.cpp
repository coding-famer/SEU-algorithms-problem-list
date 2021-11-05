#include <iostream>
using namespace std;


int steer(int p[], int n)
{
    int r[10000];
    r[0] = 0;
    int q;
    for (int i = 1;i < n + 1;i++)
    {
        q = -100;
        for (int j = 1;j <= i;j++)
            q = max(q, p[j] + r[i - j]);
        r[i] = q;

    }
    return r[n];
}

int main()
{
    int M;
    cin >> M;

    for (int x = 0;x < M;x++)
    {
        int L, N;
        cin >> L >> N;
        int pro = 0;
        int l[10000] = { 0 };
        int p[10000] = { 0 };
        for (int i = 0;i < N;++i)
        {
            cin >> l[i] >> p[i];
        }

            int price[10000];
            for (int j = 0;j <= L;j++)
                price[j] = 0;
            for (int i = 0;i < N;i++)
            {
                int j = l[i];
                price[j] = p[i];
            }

            cout << steer(price, L) << endl;
        
    }
}

