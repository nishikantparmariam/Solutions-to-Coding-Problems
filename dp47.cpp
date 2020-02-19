#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD =  1e9+7;

int main(){
    ll T;cin>>T;
    while(T--){
        ll x;ll y;ll z;
        cin>>x;cin>>y;cin>>z;
        cout << go(x,y,z)%MOD << endl;
    }
    return 0;
}