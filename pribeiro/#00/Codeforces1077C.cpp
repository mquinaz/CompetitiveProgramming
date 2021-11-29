#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int numNice = 0;
    int vecInd[n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(j==i)
                continue;
            //calculate sum
            int sum=0;
            for (int k = 0; k < n; k++){
                if(i==k || j==k)
                    continue;
                //cout << j << "j" << nums[k] << "\n";
                sum += nums[k];
            }
            if(sum == nums[j]){
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
