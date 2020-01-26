#include<bits/stdc++.h>
using namespace std;


bool HamilRecurse(stack<int> &cycle, vector<int> adj[], int N, int i, bool visited[]){
    cycle.push(i);
    
    visited[i] = true;
    if(cycle.size()==N) return true;
    bool ans = false;
    for(int v:adj[i]){
        if(!visited[v]){
            ans = ans || HamilRecurse(cycle,adj,N,v, visited);
        }
    }

    visited[i] = false;
    cycle.pop();
    return ans;
}

int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T;cin>>T;
	while(T--){
	    int N;int M;
	    cin>>N;cin>>M;
	    vector<int> adj[N];
	    for(int i=0;i<M;i++){
	        int u;int v;
	        cin>>u;cin>>v;
	        u--;v--;
	        adj[u].push_back(v);
	    }
	    
	    int HamiltonianExists = 0;
	    stack<int> cycle;	    
        bool ans = false;
        bool visited[N];
        memset(visited, false, sizeof(visited));
        for(int i=0;i<N;i++){
            ans = ans || HamilRecurse(cycle, adj, N, i, visited);
        }
	   // bool ans = HamilRecurse(cycle, adj, N); 
	   
        if(ans) cout << 1 << endl;
        else cout << 0 << endl;
	}
	return 0;
}