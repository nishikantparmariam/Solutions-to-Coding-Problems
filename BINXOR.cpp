#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
typedef long long int lli;
const lli mod=1000000007;
lli modPower(lli x, lli y, lli p) 
{ 
    lli ans = 1;  
    x = x % p;  
    while (y > 0) 
    {         
        if (y & 1) 
           ans = (ans*x) % p;         
        y = y>>1;
        x = (x*x) % p; 
    } 
    return ans; 
} 
  
int main(){
    lli tc;
    cin >> tc;
    while(tc--){
        lli N;
        cin >> N;
        string A,B;
        cin >> A >> B;        
        lli A_zero_count = count(A.begin(), A.end(), '0');
        lli B_zero_count = count(B.begin(), B.end(), '0');                
        lli low = min(N-A_zero_count,N-B_zero_count)+min(A_zero_count,B_zero_count);
        lli high = N-min(N-A_zero_count,B_zero_count)-min(A_zero_count,N-B_zero_count);
        lli lower = min(low,high);
        lli upper = max(low,high);
        lli ans = 0;              
        lli f[N+1];
        f[0] = 1;
        for(lli i = 1; i<=N; i++){
            f[i] = (i*f[i-1])%mod;
        }
        int diff = 2;
        for(lli r = lower; r<=upper; r = r+diff){                                 
            ans+=(f[N]*modPower(f[r],mod-2,mod) % mod *modPower(f[N-r],mod-2,mod) % mod) % mod;                
        }  
                
        cout << ans%mod << endl;              

    }
    return 0;
}