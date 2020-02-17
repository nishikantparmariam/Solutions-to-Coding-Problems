#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    int n;int m;cin>>n;cin>>m;
	    int grid[n][m];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cin>>grid[i][j];
	        }
	    }
	    
        int ans = -1;
	    for(int col=m-2;col>=0;col--){
	        for(int row=0;row<n;row++){
	            grid[row][col] = grid[row][col]+max(grid[max(row-1,0)][min(col+1, m-1)], max(grid[row][min(col+1, m-1)], grid[min(row+1,n-1)][min(col+1, m-1)]));
                if(col==0){
                    ans = max(ans, grid[row][col]);
                }
	        }            
	    }

        cout << ans << endl;
	}
	return 0;
}