#include<bits/stdc++.h>
using namespace std;
int matrix[50][50];

int DFS(int i, int j, int N, int M){
    matrix[i][j] = -1;
    //vector<int> cor = {i,i,j,j};
    //{MIN X, MAX X, MIN Y, MAX Y};
    int count = 1;
    for(int x=i-1;x<=i+1;x++){
        for(int y=j-1;y<=j+1;y++){
            if(x>=0 && x<N && y>=0 && y<M){
                if(matrix[x][y] == 1){
                    count+=DFS(x,y,N,M);
                    /*cor[0] = min(cor[0], new_cor[0]);
                    cor[1] = max(cor[1], new_cor[1]);
                    cor[2] = min(cor[2], new_cor[2]);
                    cor[3] = max(cor[3], new_cor[3]); */
                }
            }
        }
    }
    return count;
}

int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T;cin>>T;
	while(T--){
	    int N;int M;
	    cin>>N;cin>>M;
	    for(int i=0;i<N;i++){
	        for(int j=0;j<M;j++){
	            cin>>matrix[i][j];
	        }
	    }
	    int area = 0;
	    for(int i=0;i<N;i++){
	        for(int j=0;j<M;j++){
	            if(matrix[i][j]==1){	                
	                area = max(area, DFS(i, j, N, M));
	            }
	        }
	    }
	    cout << area << endl;
	}
	return 0;
}