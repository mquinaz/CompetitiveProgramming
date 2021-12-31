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
    
    int totalInc = 0;
    while(K > 0){
        pair<int, int> top = pq.top();
        //explorar resto divisao inteira quando se repete o nr
        if(top.first - totalInc <= 0){
            pq.pop();
            pq.push(make_pair(top.first, top.second));
            cout << top.first << " " << top.second;
        }
        totalInc++;
    }
    return 0;
}
