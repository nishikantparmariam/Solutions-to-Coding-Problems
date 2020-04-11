#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;cin>>T;
    while(T--){
        ll N;cin>>N;         
        vector<vector<ll>> p(N, vector<ll>(4, 0));
        ll ans = 0;
        for(ll i=0;i<N;i++){
            ll x;cin>>x;x=abs(x);                        
            p[i][x%4]++;                 
            for(ll q=0;q<4;q++){
                p[i][(q*x%4)%4]+=(i>0?p[i-1][q]:0);                                
            }
            for(ll q=0;q<4;q++){                
                if(q!=2) ans+=p[i][q];
            }                                   
        }  
        cout << ans << endl;                      
    }

    return 0;
}