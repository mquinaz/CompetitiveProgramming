#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int main()
{
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    string x;
    int Q_num,P;
    while(cin >> x){
        if(x == "#")
            break;
        cin >> Q_num >> P;
        pq.push(make_pair(P, Q_num));
    }
    
    int K;
    cin >> K;
    
    pair<int, int> top = pq.top();
    cout << top.first << " " << top.second;
    return 0;
}
