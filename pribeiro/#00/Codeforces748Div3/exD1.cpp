#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#include <algorithm>
#include <iterator>
using namespace std;

/*
int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
*/

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

		bool inf = true;
		int minval = a[0];
        
        for(int j=1;j<n;j++){
            if (a[j] != a[0]){
                inf = false;
                break;
            }
            minval = min(minval, a[j]);
        }
        if (inf)
		{
			cout << "-1\n";
			continue;
		}
		sort(a.begin(), a.end());
		
		int ans = 0;
		for (int j = 0; j < n; j++)
			ans = gcd(ans, a[j] - minval);
		cout << ans << '\n';
    }
    return 0;
}
