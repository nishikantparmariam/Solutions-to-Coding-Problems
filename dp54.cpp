#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;



int main(){
    ll T;cin>>T;
    while(T--){
        ll N;cin>>N;
        ll arr[N];
        ll dp[N];
        for(ll i=0;i<N;i++) {
            cin>>arr[i];
            dp[i] = 1;
        }

        ll lis = 1;
        for(ll i=1;i<N;i++){

            for(ll j=0;j<=i-1;j++){
                if(arr[i] > arr[j] && (arr[i]-arr[j])>=i-j) dp[i] = max(dp[i], 1+dp[j]);
            }

            lis = max(lis, dp[i]);
        }

        cout << N-lis << endl;
        
    }
    return 0;
}