#include <iostream>
using namespace std;


void merge(int a[], int first, int mid, int last,int c[], int& count )
{
    int i = first, j = mid + 1;
    int m = mid, n = last;
    int k = first;
    while (i <= m && j <= n)
    {
        if (a[i] <= a[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = a[j++];
            count += (mid - i+1);
        }
    }
    if (i <= m) {
        while (i <= m)
        {
            c[k++] = a[i++];
        }
        
    }
    if (j <= n) {
        while (j <= n)
            c[k++] = a[j++];
    }
    for (int i = first;i <= last;i++)
        a[i] = c[i];
}
void mergeSort(int a[], int first, int last, int temp[],int& count)
{
    if (first < last)
    {
        int mid = (last + first) / 2;
        mergeSort(a, first, mid,temp, count);
        mergeSort(a, mid + 1, last,temp, count);
        merge(a, first, mid, last,temp, count);
    }
}

int main()
{
	int M;
	cin >> M;

	for (int x = 0;x < M;x++)
	{
		int N;
		cin >> N;
        int* nums = new int[N];
        int* temp = new int[N];
		for (int i = 0;i < N;++i)
			cin >> nums[i];
        int count=0;
        mergeSort(nums, 0, N - 1,temp, count);
        cout << count<<endl;
        delete[] nums;
        delete[] temp;
	}
}


