#include<bits/stdc++.h>
using namespace std;
//https://www.redgreencode.com/uva-11572-unique-snowflakes/

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        
        int max_seq = 0;
        unordered_map<long long,int> snowflakePosition;
        pair<int, int> segmentsByStart[n];
        pair<int, int> segmentsByEnd[n];
        for(int j=0;j<n;j++){
            long long snow;
            cin >> snow;
            
            int previousPos = -1;
            for (auto itr = snowflakePosition.find(snow); itr != snowflakePosition.end(); itr++)
                if(itr->second >= 0)
                    previousPos = itr->second;
                 
            cout << previousPos << endl;
            snowflakePosition.insert({snow,j});
            if( previousPos < 0)
                continue;
            
            else
            {
                int currentPos = j;
                segmentsByStart[previousPos] = make_pair(previousPos,currentPos);
                segmentsByEnd[currentPos] = make_pair(previousPos,currentPos);
            }
        }
        
        for(int p=0;p<n;p++)
        {
            unordered_map<long long,int>::iterator itr;
            pair<int, int> s1 = segmentsByStart[p];
            if(s1.second == -1)
            {
               pair<int, int> auxSegment = make_pair(p,n);
            }
            else
                s1 = make_pair(-1,-1);
            
            int len = s1.second - s1.first;
        
            pair<int, int> s2 = segmentsByEnd[p];
            if(s2.first >= s1.first && s2.second <= s1.second)
                len = s1.first - s2.second;

            if(len > max_seq)
                max_seq = len;
        }
        cout << max_seq << endl;
    }
	
	return 0;
}
