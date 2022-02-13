#include<bits/stdc++.h>
using namespace std;

//binary search - balanced partition
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
            int middle = low + (high - mid)/2;
            /*possible(middle);
            if (bool)
                high = middle;
            else
                low = middle + 1;
            
            if( possible(low) == no)
                break;
            */
        }
        
    }
    
    
	return 0;
}
