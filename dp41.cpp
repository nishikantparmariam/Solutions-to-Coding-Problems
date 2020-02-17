#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    int N;int K;
	    cin>>N;cin>>K;
	    string S;cin>>S;
	    int dp[N][N];
	    //memset(dp, INT_MAX, sizeof(dp));
	    for(int len=1;len<=N;len++){
	        int i=0;
	        int j=i+len-1;
	        while(j<N){
	            if(len==1){
	                dp[i][j] = 0;
	            } else if(len==2){
	                if(S[i]==S[j]){
	                    dp[i][j] = 0;
	                } else {
	                    dp[i][j] = 1;
	                }
	            } else {
                    if(S[i]!=S[j]) dp[i][j] = min(1+dp[i+1][j], min(1+dp[i][j-1], 2+dp[i+1][j-1]));
                    else dp[i][j] = min(1+dp[i+1][j], min(1+dp[i][j-1], dp[i+1][j-1]));
                                        
	            }
	            i++;
	            j++;
	        }
	    }

        if(dp[0][N-1]<=K){
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
	}
	return 0;
}