#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = 1e9+7;
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    ll M;ll N;
	    cin>>M;cin>>N;
	    ll arr[M];
	    for(ll i=0;i<M;i++) cin>>arr[i];
	    ll dp[M][N+1];
	    for(ll i=0;i<M;i++){
	        for(ll n=0;n<=N;n++){
	            if(n==0){
	                dp[i][n] = 1;
	            } else {
	                if(i>0){
	                    if(n>arr[i]) dp[i][n] = (dp[i-1][n]+dp[i][n-arr[i]])%MOD;
	                    else if(n==arr[i]) dp[i][n] = (dp[i-1][n]+1)%MOD;
                        else dp[i][n] = dp[i-1][n];   
	                } else {
	                    if(n>arr[i]) dp[i][n] = dp[i][n-arr[i]];
                        else if(n==arr[i]) dp[i][n] = 1;
	                    else dp[i][n] = 0;   
	                }
	            }
	        }
	    }
	    
	    cout << dp[M-1][N]%MOD << endl;
	}
	return 0;
}