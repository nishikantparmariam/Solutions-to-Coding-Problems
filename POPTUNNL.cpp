#include <bits/stdc++.h>
using namespace std;

long long int _abs(long long int x){
    return x > 0 ? x : -x;
}

int main(){
    long long int T;cin>>T;
    while (T--)
    {
        long long int N;cin>>N;
        long long int K;cin>>K;
        vector<long long int> adjList[N];
        for(long long int i=0;i<N;i++){
            string S;cin>>S;
            for(long long int j=0;j<N;j++){
                if(S[j]=='1' && i!=j){
                    adjList[i].push_back(j);
                }
            }
        }
        long long int distance[N];
        for(long long int i=0;i<N;i++) distance[i] = -1;
        queue<long long int> Q;
        Q.push(0);
        distance[0] = 0;
        while(!Q.empty()){
            long long int v = Q.front();           
            Q.pop();
            for(long long int u:adjList[v]){                
                if(_abs(u-v) <= K && distance[u]==-1){
                    distance[u] = distance[v]+1;                    
                    Q.push(u);
                }
            }
        }
        cout << distance[N-1] << endl;
    }
    
    return 0;
}