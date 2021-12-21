#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    map<long long,int> l;
    for(int i=0;i<t;i++){
        l.clear();
        int n;
        cin >> n;
        for(int j=0;j<n;j++){
            long long snow;
            cin >> snow;
            l[snow]++;
        }
        
        int sizeUnique = l.size();
        cout << min(n,sizeUnique) << endl;
    }
	
	return 0;
}
