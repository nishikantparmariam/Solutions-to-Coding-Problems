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
	    ll N;cin>>N;
	    ll dp[N][2]; //that ends with zero, that ends with one
	    dp[0][0] = 1;
	    dp[0][1] = 1;    
	    for(ll i=1;i<N;i++){
	        dp[i][0] = (dp[i-1][0]%MOD+dp[i-1][1]%MOD)%MOD;
	        dp[i][1] = dp[i-1][0]%MOD;
	        //cout << dp[i][0] << " " << dp[i][1] << endl;
	    }	    
	    cout << (dp[N-1][0]+dp[N-1][1])%MOD << endl;
	}
	return 0;
}