#include<bits/stdc++.h>
using namespace std;
int adjMatrix[100][100];

void DFS(int s, int v, int N,vector<vector<bool>> &transitive_closure){
    transitive_closure[s][v] = true;
    for(int i=0;i<N;i++){
        if(transitive_closure[s][i]==false && adjMatrix[v][i]==1){
            DFS(s,i,N,transitive_closure);
        }
    }
}

int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        bool visited[N];
        vector<vector<bool>> transitive_closure;
        for(int i=0;i<N;i++){
            visited[i] = false;
            vector<bool> a;
            for(int j=0;j<N;j++){
                cin>>adjMatrix[i][j];
                if(i==j) a.push_back(true);
                else if(adjMatrix[i][j]==1){
                    a.push_back(false);
                } else {
                    a.push_back(false);
                } 
            }
            transitive_closure.push_back(a);
        }
        
        /*for(int k=0;k<N;k++){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                  //  cout << i << " " << j << " " << k << endl;
                    transitive_closure[i][j] =  transitive_closure[i][j] || (transitive_closure[i][k] && transitive_closure[k][j]); 
                }   
            }
        }*/
        for(int k=0;k<N;k++){
            DFS(k,k,N,transitive_closure);
        }
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(transitive_closure[i][j]) cout << "1 ";
                else cout<<"0 ";
            }
        }        
        
        cout << endl;        
    }
	return 0;
}       