class Solution {
public:
    void DFS(int s, bool visited[], int nodes_beneath[], int sum_beneath[], vector<int> adj[]){        
        visited[s] = true;         
        int sum_here = 0;
        int nodesbeneath = 1;
        for(int v:adj[s]){
            if(!visited[v]){
                DFS(v,visited,nodes_beneath,sum_beneath,adj);
                sum_here+=sum_beneath[v]+nodes_beneath[v];
                nodesbeneath+=nodes_beneath[v];
            } 
        }                
        nodes_beneath[s] = nodesbeneath;
        sum_beneath[s] = sum_here;        
    }    
    void DFS_tn(int s, bool visited[], int nodes_beneath[], vector<int> adj[], int total_sum[], int sum_beneath[], int N){
        visited[s] = true;
        for(int child:adj[s]){
            if(!visited[child]){               
                int number_nodes_up = N-nodes_beneath[child];
                int sum_up = total_sum[s]-sum_beneath[child]-nodes_beneath[child];
                total_sum[child] = sum_beneath[child]+number_nodes_up+sum_up;                                                
                DFS_tn(child,visited, nodes_beneath,adj,total_sum,sum_beneath, N);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        //root - vertex - 0
        vector<int> adj[N];
        for(vector<int> edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int nodes_beneath[N];
        int sum_beneath[N];
        bool visited[N];   
        int total_sum[N];
        memset(nodes_beneath,0,sizeof(nodes_beneath));        
        memset(nodes_beneath,0,sizeof(nodes_beneath));      
        memset(total_sum,0,sizeof(total_sum));


        memset(visited,false,sizeof(visited));
        DFS(0, visited, nodes_beneath, sum_beneath, adj);                


        memset(visited,false,sizeof(visited));
        total_sum[0] = sum_beneath[0];
        DFS_tn(0, visited, nodes_beneath, adj, total_sum, sum_beneath, N);       

        
        vector<int> ans;
        for(int i=0;i<N;i++) ans.push_back(total_sum[i]);
        return ans;
    }
};