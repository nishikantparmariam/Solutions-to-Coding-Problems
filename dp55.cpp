#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    string S;cin>>S;
	    int N = S.size();
	    int dp[N][N];
	    int ans = -1;
	    for(int len=1;len<=N;len++){
	        int i = 0;
	        int j = i+len-1;
	        while(j<N){
	            if(len==1){
	                if(S[i]=='1') dp[i][j] = 1;
	                else dp[i][j] = 0;
	            } else if(len==2){
	                if(S[i]=='1' && S[j]=='1'){
	                    dp[i][j] = 2;
	                } else if(S[i]=='1' && S[j]=='0'){
	                    dp[i][j] = 1;
	                } else if(S[i]=='0' && S[j]=='1'){
	                    dp[i][j] = 1;
	                } else {
	                    dp[i][j] = 0;
	                }
	            } else {
	                int c = dp[i+1][j-1];
	                if(S[i]=='1'){
	                    c++;
	                }
	                if(S[j]=='1'){
	                    c++;
	                }
	                dp[i][j] = c;
	            }
	            
	            ans = max(ans, len-2*dp[i][j]);
	            
	            i++;
	            j++;
	        }
	    }
	    
	    cout << ans << endl;
	}
	return 0;
}