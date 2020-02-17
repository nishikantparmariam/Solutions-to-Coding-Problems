#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll T;cin>>T;
    while(T--){        
        ll N;cin>>N;
        ll arr[N];
        ll dp[N];
        bool onlypos = true;
        ll sum = 0;
        for(ll i=0;i<N;i++){
            cin>>arr[i];
            dp[i] = arr[i];
            sum+=arr[i];
            if(arr[i] < 0) onlypos = false;
        }

        if(onlypos){
            for(ll i=0;i<N;i++){
                cout << sum << " ";
            }            
        } else {
            for(ll i=1;i<N;i++){
                if(dp[i-1]>0){
                    dp[i]+=dp[i-1];
                }
            }
        }            

        cout << endl;

    }
    return 0;
}