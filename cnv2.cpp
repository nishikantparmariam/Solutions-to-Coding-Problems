#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll gcd(ll x, ll y){
    if(y==0) return x;
    return gcd(y, x%y);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;cin>>T;
    while(T--){
        ll n;cin>>n;
        ll A[n];
        for(ll i=0;i<n;i++) cin>>A[i];
        ll dp[n][2];
        ll dp2[n][2];
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp2[0][0] = 0;
        dp2[0][1] = 0;
        ll A_0 = A[0];
        A[0] = 0;
        /*for(ll i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+A[i-1]);                      
            dp[i][1] = max(dp[i-1][0]+A[i], dp[i-1][1]+_abs(A[i]-A[i-1]));
            cout << " (" <<dp[i][0] << " " << dp[i][1] << ") ";
        }
        
        cout << endl;
        A[0] = A_0;
        for(ll i=1;i<n;i++){
            dp2[i][0] = max(dp2[i-1][0], dp2[i-1][1]+A[i-1]); 
            dp2[i][1] = max(dp2[i-1][0]+A[i], dp2[i-1][1]+_abs(A[i]-A[i-1]));
            cout << " (" <<dp2[i][0] << " " << dp2[i][1] << ") ";
        }     


        */

        cout << dp[n-1][0] << " " << dp[n-1][1]+A[n-1] << " " << dp2[n-1][0]+A[0] << " " << dp2[n-1][1]+_abs(A[0]-A[n-1]) << endl;
        if(n>2) cout << max(dp[n-1][0], max(dp[n-1][1]+A[n-1], max(dp2[n-1][0]+A[0], dp2[n-1][1]+_abs(A[0]-A[n-1])))) << endl;
        else {
            cout << max(dp[n-1][0],max(dp[n-1][1], max(dp2[n-1][0], dp2[n-1][1]))) << endl;
        }
    }
    return 0;
}