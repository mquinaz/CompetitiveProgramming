#include<bits/stdc++.h>
using namespace std;
#include <iomanip>

int f(int x){
	return x*x + 2*x + 3;
}

int main()
{
	int N;
	cin >> N;
	double dMax = 0;
	pair<int, int> listp[N];
	
	for(int i=0;i<N;i++){
		int x,y;
		cin >> x >> y;
		listp[i] = make_pair(x,y);
	}
	
	for(int i=0;i<N;i++)
		for(int j=i;j<N;j++){
			double d = sqrt( (listp[i].first-listp[j].first)*(listp[i].first-listp[j].first) + (listp[i].second-listp[j].second)*(listp[i].second-listp[j].second) );
			if(d > dMax){
				dMax = d;
			}
		}
    cout << fixed;
    cout << setprecision(10);
	cout << dMax << endl;
	return 0;
}
