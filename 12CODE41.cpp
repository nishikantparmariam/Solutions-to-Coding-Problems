#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;cin>>T;
    while(T--){
        ll N;cin>>N;
        ll arr[N];
        for(ll i=0;i<N;i++) cin>>arr[i];
        ll ans = 0;
        for(ll i=0;i<N;i++){
            ans^=(2*arr[i]);
        }
        cout << ans << endl;
    }
    return 0;
}