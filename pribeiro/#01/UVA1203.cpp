#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int main()
{
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    string x;
    int Q_num,P;
    int DIC [5000] ;
    
    //priority_queue ordered by minimum Period with pair as ID(Q_num)
    //DIC dictionary with the periods
    while(cin >> x){
        if(x == "#")
            break;
        cin >> Q_num >> P;
        pq.push(make_pair(P, Q_num));
        DIC [Q_num] =  P;
    }
    int K;
    cin >> K;
    
    //here we pop the minimum period and add the same period, 200, 400, 600...300,600,900..
    while(K > 0){
        pair<int, int> top = pq.top(); 
        pq.pop();
        top.first += DIC[top.second];
        pq.push(make_pair(top.first, top.second));
        cout << top.second << endl;
        K--;
    }
    return 0;
}
