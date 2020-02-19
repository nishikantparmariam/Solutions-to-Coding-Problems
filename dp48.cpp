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
        int x;int y;int z;
        cin>>x;cin>>y;cin>>z;
        int min_v = min(x, min(y,z));
        int arr[] = {x,y,z};
        int dp[N+1];
        for(int i=0;i<=N;i++){
            dp[i] = 0;            
            for(int p:arr){
                if(i==p) dp[i] = max(1+dp[i-p], dp[i]);
                else if(i>p && dp[i-p]>0) dp[i] = max(1+dp[i-p], dp[i]);             
            }            

           // cout << dp[i] << " ";
        }
       // cout << endl;
        cout << dp[N] << endl;
	}
	return 0;
}