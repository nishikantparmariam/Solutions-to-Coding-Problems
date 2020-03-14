#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    int N;cin>>N;
	    if(N>75) cout << -1 << endl;
	    else {
	        int dp[N+1];
	        dp[0] = 0;
	        for(int i = 1;i<=N;i++){
	            if(i==1) dp[i] = 1;
	            else if(i==2) dp[i] = 2;
	            else if(i==3) dp[i] = 3;
	            else {
	                dp[i] = 1+dp[i-1];
	                for(int k=2;k<=i-1;k++){
	                    dp[i] = max(dp[i], dp[i-3]+dp[k-2]);
	                }
	            }

                cout << dp[i] << " | ";
	        }
	        cout << dp[N] << endl;
	    }
	}
	return 0;
}