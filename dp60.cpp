#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    int N;int K;cin>>N;cin>>K;
	    int arr[N];
	    for(int i=0;i<N;i++) cin>>arr[i];
	    int dp[K+1][N];
	    for(int k=1;k<=K;k++){
	        for(int i=0;i<N;i++){
	            dp[k][i] = -1;
	            if(i+1 < k) dp[k][i] = -1;
	            else {
	                if(k==1) dp[k][i] = arr[i];
	                else if(i==0) dp[k][i] = arr[0];
	                else {
	                    for(int j=0;j<i;j++){
	                        if(arr[j] <= arr[i]){
	                            if(dp[k-1][j]!=-1){
	                                dp[k][i] = max(dp[k][i], dp[k-1][j]+arr[i]);   
	                            }
	                        }
	                    }
	                }
	            }
	        }
	    }
	    
	    cout << dp[K][N-1] << endl;
	}
	return 0;
}