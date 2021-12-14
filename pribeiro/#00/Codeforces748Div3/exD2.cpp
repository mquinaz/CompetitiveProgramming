#include<bits/stdc++.h>
using namespace std;

set<int> divs(int n) {  
    set<int> d;
    for (int dd = 1; dd * dd <= n; dd++)
        if (n % dd == 0) {
            d.insert(n / dd);
            d.insert(dd);
        }
    return d;
}

int main()
{
    int t;
    cin >> t;
    
    for(int i=0;i<t;i++){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int j=0;j<n;j++)
		    cin >> a[j];

        int k = -1;
        for(int j=0;j<n;j++){
            int minv = a[j];
            int same = 0;
            vector<int> d;
            for(int j1=0;j1<n;j1++) {
                if (a[j1] == minv)
                    same++;
                else if (a[j1] > minv)
                    d.push_back(a[j1] - minv);
            }
            if (same >= n / 2) {
                k = INT_MAX;
                continue;
            }
        
            map<int,int> div_counts;
            for (int di: d)
                for (int dd: divs(di))
                    div_counts[dd]++;
            for (auto p: div_counts)
                if (p.second >= n / 2 - same)
                    k = max(k, p.first);
        }
        cout << (k == INT_MAX ? -1 : k) << endl;
    }
    return 0;
}
