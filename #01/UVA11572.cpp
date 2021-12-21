#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    map<long long,int> l;
    for(int i=0;i>t;i++){
        l.clear();
        int n;
        cin >> n;
        for(int j=0;j<n;j++){
            long long snow;
            cin >> snow;
            l[snow]++;
        }
        
        for(map<long long,int>::iterator it=l.begin();it!=l.end();it++){
            
        }
        cout << n << endl;
    }
	
	return 0;
}
