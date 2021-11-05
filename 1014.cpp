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
		int nums[50000] = { 0 };
		for (int i = 0;i < N;++i)
			cin >> nums[i];
		int a[50000] = { 0 };
        a[0] = nums[0];

        for (int i = 1;i < N;i++)
        {
            if (a[i - 1] > 0)
            {
                a[i] = nums[i] + a[i - 1];
            }
            else
            {
                a[i] = nums[i];
            }

        }
        int m = nums[0];
        for (int i = 0;i < N;i++)
        {
            if (a[i] > m)
                m = a[i];
        }
        cout<<m<<endl;
	}
}
