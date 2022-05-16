#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    int t;
    while(t--)
    {
        int N,C;
        cin >> N >> C;
        
        vector<int> ord;
        for(int i=0;i<N;i++)
        {
            long long x;
            cin >> x;
            ord.push_back(x);
        }
        sort(ord.begin(),ord.end());
        int middle = (ord[ord.size()] - ord[0]) / 2;
    }

    return 0;
}
