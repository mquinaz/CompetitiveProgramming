#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    map<vector<int>, int> m;
    while(cin >> n, n) {
        m.clear();
		vector<int> frosh[n];
		for( int i=0;i<n;i++){
    	    vector<int> c(5);
    	    for(auto &x: c) 
    	        cin >> x;
    	    sort(c.begin(), c.end());
    	    m[c]++;
		}
		
    	int max_val = 0;
    	for(map<vector<int>, int>::iterator it=m.begin(); it!=m.end(); it++) {
    	    max_val = max(max_val, it->second);
    	}
    	int cnt = 0;
    	for(map<vector<int>, int>::iterator it=m.begin(); it!=m.end(); it++) {
    	    if(it->second == max_val) cnt++;
    	}
    	cout << max_val*cnt << '\n';
	}
	
	return 0;
}
