#include<bits/stdc++.h>
using namespace std;

//binary search - balanced partition
bool possible(vector<int> v, int K, int S)
{
    int sum = 0;
    int ind = K;
    for(int i=0;i<v.size();i++)
    {
        if(ind > 0)
        {
            if( sum + v[i] <= S)
            {
                sum += v[i];
            }
            else
            {
                sum = v[i];
                ind--;
            }
        }
        else
            return false;
    }
    return true;
}

int main()
{
    int N,K;
    while(cin >> N >> K)
    {
        int s = 0;
        vector <int> campsites;
        for(int i=0;i<=N;i++)
        {
            int distance;
            cin >> distance;
            s += distance;
            campsites.push_back(distance);
        }
        
        int low = 1;
        int high = s;
        while(low < high)
        {
            int middle = low + (high - middle)/2;

            if ( possible(campsites,K,middle) )
                high = middle;
            else
                low = middle + 1;
            
            if( !possible(campsites,K,low) )
                break;
        }
        cout << high << endl;
    }
    
    
	return 0;
}
