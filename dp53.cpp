#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll minJumps(int move, int curr, int D, vector<vector<ll>> &dp){  

    if(curr > D) return INT_MAX;

    if(dp[move][curr]!=-1) return dp[move][curr];

    if(curr==D) {
        dp[move][curr] = 0;   
    }
    else if(abs(curr-D)==1){
        if(move==1) dp[move][curr] =  1;
        else dp[move][curr] =  2;
    } else {
        dp[move][curr] = min(2+minJumps(move+2, curr+1, D, dp), 1+minJumps(move+1, curr+move, D,dp));
    }
    
    return dp[move][curr];
}
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
        int D;cin>>D;
        if(D==0 || D==1) cout << D << endl;
        else {
            vector<vector<ll>> dp;
            for(ll moves=1;moves<=2*D+5;moves++){
                vector<ll> a;
                for(ll curr=0;curr<=D;curr++){
                    a.push_back(-1);
                }
                dp.push_back(a);
            }
            cout << minJumps(1, 0, D, dp) << endl;
        }
	}
	return 0;
}

