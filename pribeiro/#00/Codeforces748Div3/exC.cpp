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
		
		long long nums[k];
		for(int j=0;j<k;j++){
			cin >> nums[j];
		}
		
		int count=0;
		for(int j=0;j<10;j++){
			long long maxNum = *max_element(nums , nums + k);
			auto indMax = distance(nums, find(nums, nums + k, maxNum) );
			//cout << maxNum << " " << indMax << endl;
			nums[indMax]++;
			if( nums[indMax] == n){
				nums[indMax] = -1;
				count++;
			}
		}
		cout << count << endl;
	}
    return 0;
}
