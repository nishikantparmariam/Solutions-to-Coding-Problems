#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = (ll)(1e9+7);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        ll n;ll q;
        cin>>n;cin>>q;        
        vector<vector<ll>> Q(q, vector<ll> (3, 0));
        for(ll i=0;i<q;i++){
            ll type;ll l;ll r;
            cin>>type;
            cin>>l;
            cin>>r;
            l--;r--;
            Q[i][0] = type;
            Q[i][1] = l;
            Q[i][2] = r;
        }

        vector<ll> times(q, 1);
        vector<ll> difference(q, 0);
        for(ll i=q-1;i>=0;i--){
            times[i] = (difference[i]%MOD+(i+1<=q-1 ? times[i+1] : 1)%MOD)%MOD;
            if(Q[i][0]==2){
                difference[Q[i][2]]=(difference[Q[i][2]]%MOD+times[i]%MOD)%MOD;  
                if(Q[i][1]>0) difference[Q[i][1]-1]=(difference[Q[i][1]-1]%MOD-times[i]%MOD+MOD)%MOD;  
            }            
        }

        vector<ll> difference_array(n, 0);
        for(ll i=0;i<q;i++){
            if(Q[i][0]==1){
                difference_array[Q[i][2]] = (difference_array[Q[i][2]]%MOD+times[i]%MOD)%MOD;
                if(Q[i][1]>0) difference_array[Q[i][1]-1] = (difference_array[Q[i][1]-1]%MOD-times[i]%MOD+MOD)%MOD;
            }
        }

        vector<ll> ans(n, 0);
        for(ll i=n-1;i>=0;i--){
            ans[i] = ((i+1<=n-1 ? ans[i+1] : 0)%MOD+difference_array[i]%MOD)%MOD;
        }

        for(ll i=0;i<n;i++){
            cout << ans[i]%MOD << " ";
        }
        cout << endl;
    }
    return 0;
}