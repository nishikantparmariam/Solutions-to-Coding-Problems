#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    int N;int M;
	    cin>>N;cin>>M;
	    int grid[N][M];
	    for(int i=0;i<N;i++){
	        for(int j=0;j<M;j++){
	            cin>>grid[i][j];
	        }
	    }
	    for(int i=N-1;i>=0;i--){
	        for(int j=M-1;j>=0;j--){
	            int a = grid[i][j];
	            if(i==N-1 && j==M-1){
	                if(a>=0){
	                    grid[i][j] = 1;
	                } else {
	                    grid[i][j] = 1-a;
	                } 
	            } else {
                    int b;
    	            if(i<N-1 && j<M-1) b = min(grid[i+1][j], grid[i][j+1]);
    	            else if(i<N-1) b = grid[i+1][j];
    	            else b = grid[i][j+1];
    	            grid[i][j] = b-a;   
	            }
	        }
	    }
	    cout << grid[0][0] << endl;
	}
	return 0;
}