#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    int V;int N;
	    cin>>V;cin>>N;
	    int coins[N];
	    for(int i =0;i<N;i++) cin>>coins[i];
	    int dp[V+1][N];
	    memset(dp, -1, sizeof(dp));
	    
	    for(int v=0;v<=V;v++){
	        for(int i=0;i<N;i++){
	            if(v==0) dp[v][i] = 0;
	            else {
	                if(coins[i] > v){
	                    dp[v][i] = i>0 ? dp[v][i-1] : -1;
	                } else {	                    
	                    dp[v][i] = min((dp[v-coins[i]][i]!=-1 ? dp[v-coins[i]][i]+1 : INT_MAX), (i>0 ?  (dp[v][i-1]!=-1 ? dp[v][i-1] : INT_MAX) : INT_MAX) ); 
                        if(dp[v][i]==INT_MAX) dp[v][i] = -1;
	                }
	            }
	        }
	    }
	    
	    cout << dp[V][N-1] << endl;
	}
	return 0;
}