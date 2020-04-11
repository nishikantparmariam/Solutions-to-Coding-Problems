#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = (ll)(1e9+7);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;cin>>T;
    while(T--){        
        ll N;ll K;cin>>N;cin>>K;
        ll minSum=(K*(K+1))/2;
        if(N<minSum) cout << -1 << endl;
        else {
            ll diff = N-minSum;                        
            ll ans = 1;
            ll rem = diff%K;
            for(ll k=K;k>=1;k--){
                ll p = k+diff/K;
                if(rem>0){
                    p++;
                    rem--;
                }       
                ans = ((p*p-p)%MOD*ans)%MOD;
            }
            cout << ans << endl;            
        }   
    }
    return 0;
}

            