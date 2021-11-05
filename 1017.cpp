#include <iostream>
#include<unordered_map>
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
       
    }
}

int merge(int m, int n)
{
    if (m == n)
        return 0;
    else
    { 
        
        return merge(m, (m + n) / 2) + merge((m + n) / 2, n) + x;
    }
    
}
