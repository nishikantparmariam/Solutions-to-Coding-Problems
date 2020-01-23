#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll profits[n];
        for(ll i=0;i<n;i++) cin>>profits[i];
        ll dp[n];
        for(ll i=0;i<n;i++){
            dp[i] = 0;        
            if(i>0){
                ll ps = 0;
                for(ll k=i-1;k>=0;k--){
                    if(profits[k]<profits[i]){
                         ps+=profits[i]-profits[k];
                         if(k>0) dp[i] = max(dp[i], dp[k-1]+ps);
                         else dp[i] = max(dp[i], ps);
                    }
                }
                dp[i] = max(dp[i], dp[i-1]);
            }
            
        }   
        cout << dp[n-1] << endl;
                                     
    }
}
