#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N, K, T;
ll grid[205][205];	    

ll ways(ll i,ll j, ll k, vector<vector<vector<ll>>> &dp){
    
   // cout << "Called -" << i << " " << j << " " << k << endl;

    if(dp[i][j][k]!=-1) return dp[i][j][k];

    if(i==N-1 && j==N-1){
        if(k==grid[i][j]) dp[i][j][k] = 1;
        else dp[i][j][k] = 0;            
    } else if(k < grid[i][j]){
        dp[i][j][k] =  0;
    } else {
        if(i==N-1){
            dp[i][j][k] = ways(i, j+1, k-grid[i][j], dp);
        } else if(j==N-1){
            dp[i][j][k] =  ways(i+1, j, k-grid[i][j], dp);
        } else {
            dp[i][j][k] = ways(i+1, j, k-grid[i][j], dp)+ways(i, j+1, k-grid[i][j], dp);
        }
    }

    //cout << i << " " << j << " " << dp[i][j][k] << endl;

    return dp[i][j][k];
}


int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>T;
	while(T--){
	    cin>>K;
	    cin>>N;	    
	    for(int i=0;i<N;i++){
	        for(int j=0;j<N;j++){
	            cin>>grid[i][j];	                   
	        }
	    }

        vector<vector<vector<ll>>> dp;

        for(ll i=0;i<N+3;i++){
            vector<vector<ll>> a;
            for(ll j=0;j<N+3;j++){
                vector<ll> b;
                for(ll k=0;k<K+3;k++){
                    b.push_back(-1);
                }
                a.push_back(b);
            }   
            dp.push_back(a);
        }
	    
        cout << ways(0,0,K,dp) << endl;
	    	    	    
	}
	return 0;
}