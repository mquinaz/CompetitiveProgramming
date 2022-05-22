#include <bits/stdc++.h>
using namespace std;

bool isFeasible(long long mid, vector<long long> arr, int k)
{
    long long pos = arr[0];
    int elements = 1;
 
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - pos >= mid)
        {
            pos = arr[i];
            elements++;
 
            if (elements == k)
            {
                return true;
            }
        }
    }
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,c;
        cin >> n >> c;
        
        vector<long long> numList;
        numList.clear();
        for(int i=0;i<n;i++)
        {
            long long x;
            cin >> x;
            numList.push_back(x);
        }
        sort(numList.begin(),numList.end());
        
        long long res=-1,left=1,right=numList[numList.size()-1];
        while (left < right)
        {
            long long mid = (left + right) / 2;
            if (isFeasible(mid, numList, c))
            {
                res = max(res, mid);
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        cout << res << endl;
    }

    return 0;
}
