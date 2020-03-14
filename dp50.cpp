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
        int dp[N+1];        
        dp[0] = 1;
        if(N>=1){
            dp[1] = 1;
            for(int i=2;i<=N;i++){
                if(i & 1) dp[i] = 1+dp[i-1];
                else dp[i] = 1+min(dp[i-1], dp[i/2]);
            }
        }

        cout << dp[N] << endl;
	}
	return 0;
}