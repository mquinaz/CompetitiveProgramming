#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        
        int max_seq = 0;
        for(int j=0;j<n;j++){
            long long snow;
            cin >> snow;
            
            unordered_map<long long,int> snowflakePosition;
            pair<int, int> Segment;
            Segment[n] segmentsByStart;
            Segment[n] segmentsByEnd;
            int current_Sequence = 0;
            
            while( !snowflakePosition.find(snow) ){
                snowflakePosition.insert(snow);
                current_Sequence++;
            }
            if( current_Sequence > max_seq)
                max_seq = current_Sequence;
        }
        cout << max_seq << endl;
    }
	
	return 0;
}
