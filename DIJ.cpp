#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        long long int N;long long int M;cin >> N;cin >> M;
        vector<long long int> adjList[N]; //(vertex, weight)
        while(M--){
            long long int v1;long long int v2;
            cin >> v1;cin >> v2;
            v1--;v2--;
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);
        }
        long long int S;
        cin >> S;
        S--;

        //BFS
        queue<long long int> Q;
        long long int label[N];
        for(long long int i = 0; i<N; i++){
            label[i] = -1;
        }

        label[S] = 0;
        Q.push(S);
        while(!Q.empty()){
            int src = Q.front();
            Q.pop();
            bool neigh[N];
            memset(neigh, true, sizeof(neigh));            
            for(long long int x:adjList[src]){
                neigh[x] = false;
            }
            for(long long int i = 0; i<N; i++){
                if(neigh[i] && label[i]==-1){
                    label[i] = label[src]+1;
                    Q.push(i);
                }
            }
        }

        for(long long int i = 0; i<N; i++){
            if(i!=S) cout << label[i] << " ";
        }

        cout << endl;

        
    }    
    return 0;
}