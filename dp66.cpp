#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int rowSum(vector<vector<int>> &grid, int cols, int cole,int row){
    int res = 0;
    for(int col=cols;col<=cole;col++){
        res+=grid[row][col];
    }
    return res;
}

int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    int N;cin>>N;
	    int M;cin>>M;	    
        vector<vector<int>> grid(N, vector<int> (M,0));	    	    
	    
	    for(int i=0;i<N;i++){
	        for(int j=0;j<M;j++){
	            cin>>grid[i][j];	            
	        }
	    }

        int ans = grid[0][0];

        for(int len=1;len<=M;len++){
            int cols = 0;
            int cole = cols+len-1;
            while(cole<M){
                int prevrow = rowSum(grid,cols,cole,0);
                int ansHere = prevrow;
                for(int row=1;row<N;row++){
                    int currrow = rowSum(grid,cols,cole,row);
                    if(prevrow>0){
                        prevrow+=currrow;
                    } else {
                        prevrow = currrow;
                    }
                    ansHere = max(ansHere, prevrow);
                }

                ans = max(ansHere, ans);

                cols++;
                cole++;
            }
        }
        cout << ans << endl;
	    
	}
	return 0;
}