#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin >> n;
        
        long long mx = 0;
        long long u = 0;
        unordered_map<int,int> m;
        for(long long j=1;j<=n;j++)
        {
            long long snow;
            cin >> snow;
            
            int &r = m[snow];
            if( r > u )
            {
				mx = max(mx,j-u-1);
				u = r;
			}
			r = j;
        }
        mx = max(mx,n-u);
		cout << mx << endl;
    }
	
	return 0;
}
