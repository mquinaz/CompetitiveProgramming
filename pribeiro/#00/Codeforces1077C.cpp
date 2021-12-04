#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long int nums[n],sum=0;
    map<long long , long long> cnt;
    
    for (int i = 0; i < n; i++){
      cin >> nums[i];
      sum += nums[i];
      cnt[nums[i] ]++;
    }

    long long int numNice = 0;
    long long int vecInd[n];
    for (int i = 0; i < n; i++){
        sum -= nums[i];
        cnt[nums[i]]--;
        if(cnt[sum/2] && sum % 2 == 0){
            vecInd[numNice] = i+1;
            numNice++;
        }
        sum += nums[i];
        cnt[nums[i]]++;
    }
    
    cout << numNice << "\n";
    if(numNice == 0)
        return 0;
    for (int i = 0; i < numNice-1; i++)
        cout << vecInd[i] << " ";
    cout << vecInd[numNice-1] << "\n";
    return 0;
}
