#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    for(int i=0;i<t;i++){
	long long n,k;
	cin >> n >> k;

	long long nums[k],r[k];
	for(int j=0;j<k;j++){
		cin >> nums[j];
		r[j] = n - nums[j];
	}
	int sizeR = sizeof(r)/sizeof(r[0]); 
	//sort the closest mouse, O(n^2) worst case
        sort(r, r+sizeR);
        int total = 0,m=0;
    	for(int j=0;j<k;j++){
    	    if( total + r[j] < n){
    	        total += r[j];
    	        m++;
    	    }
    	}
        cout << m << endl;
	}
    return 0;
}
