#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int M;
	cin >> M;

	for (int x = 0;x < M;x++)
	{
        int f[20002];
        int n;
        long long int l=0;
        int count=0;
        cin >> n;

        memset(f, 0, sizeof(f));
        for (int i = 0;i < 2 * n;i++)
        {
            cin >> f[i];
        }

        for (int i = 0;i < 2 * n;i++)
        {
            l += abs(count);
            if (f[i] == 1)
                count += 1;
            else
                count -= 1;
        }
        cout << l << endl;
	}
}

