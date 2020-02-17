#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    string A;string B;
	    cin>>A;
        cin>>B;
	    if(B.size() > A.size()) cout << 0 << endl;
	    else {
	        int N = A.size();
	        int M = B.size();
	        int dp[N][M];
	        for(int i=0;i<N;i++){
	            for(int j=0;j<M;j++){
	                if(j>i){
	                    dp[i][j] = 0;
	                } else if(i==j){
                        if(A[i]==B[j]){
                            if(i>0 && j>0) dp[i][j] = dp[i-1][j-1];
                            else dp[i][j] = 1;
                        } else {
                            dp[i][j] = 0;
                        }
                    } else if(A[i]!=B[j]) {
                        // j<=i
	                    if(i>0) dp[i][j] = dp[i-1][j];
	                    else dp[i][j] = 0;
	                } else {                        
                        if(j>0 && i>0) dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                        else if(j==0 && i>0) dp[i][j] = 1+dp[i-1][j];                        
                        else dp[i][j] = 1;          
	                }                                     
	            }	           
	        }
	        
	        cout << dp[N-1][M-1] << endl;
	    }
	}
	return 0;
}