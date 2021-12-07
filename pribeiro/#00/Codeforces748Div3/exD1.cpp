#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    for(int i=0;i<t;i++){
		int n;
		cin >> n;
		long long nums[n],numsTemp[n];
		for(int j=0;j<n;j++)
		    cin >> nums[j];
		int sizeNums = sizeof(nums)/sizeof(nums[0]); 
        sort(nums, nums+sizeNums);
        
        //set up numsTemp
        copy(begin(nums), end(nums), begin(numsTemp));
        long long diferenceMaxMin = nums[n-1] - nums[0];
        for(int j=diferenceMaxMin;j>=0;j--){
            int flagBad = 0;
            copy(begin(numsTemp), end(numsTemp), begin(nums));
            for(int k=0;k<n;k++){
                while( nums[k] < nums[n-1] && !flagBad){
                    nums[k] += j;
                }
                cout << nums[k] << " " << j << " " << flagBad << endl;
                if(nums[k] == nums[n-1])
                    continue;
                else{
                    flagBad = 1;
                    break;
                }
            }
            if(flagBad == 1)
                continue;
            else{
                cout << j << endl;
                break;
            }
        }
	}
    return 0;
}
