#include<bits/stdc++.h>
using namespace std;
char matrix[100][100];
bool visited[100][100];

void DFS(int x, int y, bool mark, int N, int M){
    visited[x][y] = true;
    if(mark) matrix[x][y] = 'X';
  //  if(!mark) cout << "visited = " << x << " " << y << endl;
    //top
    if(x-1>=0){
        if(!visited[x-1][y] && matrix[x-1][y]=='O'){
            DFS(x-1,y, mark, N, M);   
        }
    }
    //bottom
    if(x+1<=N-1){
        if(!visited[x+1][y] && matrix[x+1][y]=='O'){
            DFS( x+1,y, mark, N, M);   
        }
    }
    //left
    if(y-1>=0){
        if(!visited[x][y-1] && matrix[x][y-1]=='O'){
            DFS( x,y-1, mark, N, M);   
        }
    }
    //top
    if(y+1<=M-1){
        if(!visited[x][y+1] && matrix[x][y+1]=='O'){
            DFS(x,y+1, mark, N, M);   
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
	    int M;cin>>M;
	    for(int i=0;i<N;i++){
	        for(int j=0;j<M;j++){
	            cin>>matrix[i][j];
	            visited[i][j] = false;
	        }
	    }
	    
	    //top row
	    for(int j=0;j<M;j++){
	        if(visited[0][j]==false && matrix[0][j]=='O'){
	            DFS(0, j, false, N, M);
	        }
           // cout << matrix[0][j] << endl;
	    }
	    
	    
	    //bottom row
	    for(int j=0;j<M;j++){
	        if(visited[N-1][j]==false && matrix[N-1][j]=='O'){
	            DFS(N-1, j, false, N, M);
	        }
	    }
	    
	    
	    //left column
	    for(int i=0;i<N;i++){
	        if(visited[i][0]==false && matrix[i][0]=='O'){
	            DFS(i, 0, false, N, M);
	        }
	    }
	    
	    //right column
	    for(int i=0;i<N;i++){
	        if(visited[i][M-1]==false && matrix[i][M-1]=='O'){
	            DFS(i, M-1, false, N, M);
	        }
	    }
	    
	    for(int i=0;i<N;i++){
	        for(int j=0;j<M;j++){
	            if(visited[i][j]==false && matrix[i][j]=='O'){
	                DFS(i, j, true, N,M);
	            }
	        }
	    }

        /*for(int i=0;i<N;i++){
	        for(int j=0;j<M;j++){
                if(visited[i][j]){
                    cout << 1 << " ";
                } else {
                    cout << 0 << " ";
                }
                cout << endl;
	        }
	    } */
	    
	    for(int i=0;i<N;i++){
	        for(int j=0;j<M;j++){
	            cout << matrix[i][j] << " ";
	        }
	    }
	    cout << endl;
	    
	}
	return 0;  
}