#include<bits/stdc++.h>
using namespace std;
struct mycomp{
    bool operator()(const pair<long long int, long long int> &p1, const pair<long long int, long long int> &p2){
        return p1.first > p2.first;
    }
};

bool check(long long int i, long long int j, long long int N){
    if(i>=0 && i<N && j>=0 && j<N){
        return true;
    }
    return false;

}
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int T;cin>>T;
	while(T--){
	    long long int N;cin>>N;
	    vector<pair<long long int, long long int>> adj[N*N];
        long long int costs[N*N];
	    //0 --> (vertex, weight) --> (vertex, weight)
	    for(int i=0;i<N;i++){
	        for(int j=0;j<N;j++){
	            long long int w;
	            cin>>w;
	            long long int u = N*i+j;
                costs[u] = w; 
	            long long int top = N*(i-1)+j;
	            long long int bottom = N*(i+1)+j;
	            long long int left = N*i+(j-1);
	            long long int right = N*i+(j+1);
	            if(check(i-1, j, N)){
	                adj[top].push_back(make_pair(u, w));
	            }
	            
	            if(check(i+1, j, N)){
	                adj[bottom].push_back(make_pair(u, w));
	            }
	            
	            if(check(i, j-1, N)){
	                adj[left].push_back(make_pair(u, w));
	            }
	            
	            if(check(i, j+1, N)){
	                adj[right].push_back(make_pair(u, w));
	            }
	        }
	    }
	    
	    long long int distance[N*N];
	    for(int i=0;i<N*N;i++) distance[i] = INT_MAX;	    
	    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, mycomp> Q;
	    Q.push(make_pair(0, 0));
        distance[0] = costs[0];
        bool visited[N*N];
        for(int i=0;i<N*N;i++) visited[i] = false;

        while(!Q.empty()){
            pair<long long int, long long int> p = Q.top();
            Q.pop();         
            long long int u = p.second;
           // cout << u << endl;
            visited[u] = true;
           // cout <<"(" <<(u/N+1) << "," << u%N+1 << ") " << distance[u] << endl;
           // cout << "Out - ";
            for(pair<long long int, long long int> p2:adj[u]){
                long long int v = p2.first;
                long long int w = p2.second;
            
                if(!visited[v]){

                     if(distance[u]+w < distance[v]){
                        distance[v] = distance[u]+w;
                        //cout << v <<" " << distance[v] << " | ";
                        Q.push(make_pair(distance[v], v));
                    }   
                }
            }
            //cout << endl;
        }

       /* int count = N*N;

        while(count--){
            for(long long int i=0;i<N*N;i++){
                for(pair<long long int, long long int> p2:adj[i]){
                    long long int u = p2.first;
                    long long int w = p2.second;
                    if(distance[i]!=INT_MAX){
                        if(distance[i]+w < distance[u]){
                            distance[u] = distance[i]+w;
                        }
                    }                    
                }
            }
        } */

        cout << distance[N*N-1] << endl;
        
	}
	return 0;
}