#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long long int MOD = 1000000007;

ll validate(ll index, ll base_dp[], ll m){
    if(index>=0 && index<m) return base_dp[index];
    return 0; 
}

ll power(ll base, ll power, ll MOD){
    ll res = 1;
    while(power>0){
        if(power & 1){
            res = res*base;
        }
        power = power>>1;
        base = base*base;
    }
    return res;
}


int main(){
    const ll mod = 1000000007;
    ll f[101];
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i=1; i<=100; i++){
        for (int j=1; j<=4; j++){
            if (i - j >= 0) f[i] = (f[i] + f[i-j]) % mod;
        }
        cout << f[i] << endl;
    }                
    return 0;
}
