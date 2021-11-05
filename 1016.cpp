#include <iostream>
#include<unordered_map>
using namespace std;

int main()
{
    int M;
    cin >> M;

    for (int x = 0;x < M;x++)
    {
        int N,X;
        cin >> N>>X;
        int nums[50000] = { 0 };
        for (int i = 0;i < N;++i)
            cin >> nums[i];
        unordered_map<int, int> hashtable;
        bool flag = 0;
        for (int i = 0; i < N; ++i) {
            auto it = hashtable.find(X - nums[i]);
            if (it != hashtable.end()) {
                cout<<"yes"<<endl;
                flag = 1;
                break;
            }
            hashtable[nums[i]] = i;
        }
        if (flag == 0)
            cout << "no" << endl;
    }
}