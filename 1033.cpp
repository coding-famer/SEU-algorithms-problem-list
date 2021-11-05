#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

class t
{
public:
    int d, p;
};
bool compare(t a, t b)
{
    return a.p > b.p;
}
int main()
{
    int M;
    cin >> M;

    for (int x = 0;x < M;x++)
    {
        int n;
        cin >> n;
        t f[50000];
        for (int i = 0;i < n;i++)
        {
            cin>>f[i].d>>f[i].p;
        }
        //int* time = new int[f[n-1].d+1];
        int time[100000];
        memset(time, 0, sizeof(time));
        sort(f, f + n, compare);

        unsigned long long sum = 0;
        for (int i = 0;i < n;i++)
        {
            int j = f[i].d;
            while (time[j] == 1&&j>0)
                j--;
            if (j != 0)
            {
                sum = sum + f[i].p;
                time[j] = 1;
            }
        }
        cout << sum<<endl;
    }
}
