#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; v++)
    {
        cout <<  (v+1) << " head ";
        for (auto x : adj[v])
           cout << "-> " << (x+1);
        printf("\n");
    }
}

int main()
{
    int t;
    cin >> t;
    
    for(int i=0;i<t;i++){
        string s;
		getline(cin, s);
		int n,k;
		cin >> n >> k;
		vector<int> adj[n];
		for(int j=0;j<n-1;j++){
		    int u,v;
		    cin >> u >> v;
		    addEdge(adj, u-1, v-1);
		}
        //printGraph(adj,n);
        while(k > 0){
            for (int v = 0; v < n; v++){
                int nrVertex = 0;
                for (auto x : adj[v])
                    nrVertex++;
                if(n == 2){
                    adj[v].clear();
                    k = 0;
                    break;
                }
                if(nrVertex == 1){
                    int count = 0;
                    //remove the opposite connection
                    for (auto x : adj[ adj[v][0] ]){
                        count++;
                        if( x == v )
                            adj[ adj[v][0] ].erase( (adj[ adj[v][0] ].begin() + count - 1) );
                    }
                    //remove vertex leaf
                    adj[v].pop_back();
                    //printGraph(adj,n);
                }
            }
            k--;
        }
        //printGraph(adj,n);
        int finalVertex = 0;
        for (int v = 0; v < n; v++)
            for (auto x : adj[v])
                finalVertex++;
        cout << finalVertex << endl;
    }
    return 0;
}
