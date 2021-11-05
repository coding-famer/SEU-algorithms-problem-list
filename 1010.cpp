
#include <iostream>
using namespace std;
int binarySearch2(int array[], int n, int target);
int main()
{
	int M;
	cin >> M;
	for (int q = 0;q < M;q++)
	{
		int N, K;
		cin >> N >> K;
		int* nums = new int[N];
		for (int i = 0;i < N;i++)
		{
			cin >> nums[i];
		}
		binarySearch2(nums, N, K);

	}
	return 0;
}


int binarySearch2(int array[], int n, int target) {
	int low = 0, high = n-1, middle = 0, father = 0;
	while (low <= high) {
		middle = (low + high) / 2;
		if (target == array[middle]) {
			cout << "success, father is "<<array[father]<<endl;
			return middle;
		}
		else if (target < array[middle]) {
			high = middle-1;
		}
		else if (target > array[middle]) {
			low = middle + 1;
		}
		father = middle;
	}
	cout << "not found, father is " << array[father] << endl;
	return middle;
}