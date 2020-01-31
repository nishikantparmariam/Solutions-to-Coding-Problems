#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool isPrime[200005];

void DFS(vector<ll> adjList[], int root, bool visited[], int *ans, int no_of_seniors){
    visited[root] = true;
    if(no_of_seniors!=0){
        if(isPrime[root+1+no_of_seniors]) (*ans)++;
    }

    for(ll v:adjList[root]){
        if(!visited[v]){
            DFS(adjList,v,visited, ans, no_of_seniors+1);
        }
    }
}

int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    
    memset(isPrime, true, sizeof(isPrime));
    for(ll p=2;p*p<=200004;p++){
        if(isPrime[p]){
            for(ll k=p*p; k<=200004; k=k+p){
                isPrime[k] = false;
            }
        }
    }
	ll T;cin>>T;
	while(T--){
	    ll N;cin>>N;
	    vector<ll> adjList[N];
	    ll root;
	    for(ll i=0;i<N;i++){
	        int v;cin>>v;
	        v--;
	        int u = i;
	        if(v>=0){
	            adjList[u].push_back(v);
	            adjList[v].push_back(u);   
	        } else {
	            root = u;
	        }
	    }
	    
	    int ans = 0;
	    bool visited[N];
	    memset(visited, false, sizeof(visited));
	    DFS(adjList, root, visited, &ans, 0);
	    cout << ans << endl;
	    
	    
	}
	return 0;
}