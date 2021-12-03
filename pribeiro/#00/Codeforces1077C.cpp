#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int nums[n];
    long long int sum = 0;
    
    for (int i = 0; i < n; i++){
      cin >> nums[i];
      sum += nums[i];
    }

    int numNice = 0;
    int vecInd[n];
    long long int auxSum;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(j==i){
                continue;
            }
            auxSum = sum - nums[i] - nums[j];
            if(auxSum == nums[j]){
                vecInd[numNice] = i+1;
                numNice++;
                break;
            }
        }
    }
    
    cout << numNice << "\n";
    if(numNice == 0)
        return 0;
    for (int i = 0; i < numNice-1; i++)
        cout << vecInd[i] << " ";
    cout << vecInd[numNice-1] << "\n";
    return 0;
}
