#include <bits/stdc++.h>
using namespace std;
#define mod 998244353

long long int modPower(long long int x,long long int y,long long int p){
    if(x==1){
        return 1;
    }        
    long long int ans = 1;
    x = x % p;  
    while (y > 0){
        if (y & 1) ans = (ans*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }        
    return ans;
}    

long long int calculate_fac(long long int n, long long int prev_max_cal_fac, unordered_map<long long int, long long int> &factorial){
    long long int diff = n-prev_max_cal_fac;
    long long int ans = 1;
    for(long long int i=n; i>prev_max_cal_fac;i--){
        ans = (i*ans)%mod;
    }
    ans = (ans*factorial[prev_max_cal_fac])%mod;
    factorial[n] = ans;
    return ans;
}

int main(){
    long long int T;
    cin >>  T;
    while(T--){
        long long int N;
        long long int p;
        long long int r;
        cin >> N;
        cin >> p;
        cin >> r;
        unordered_map<long long int, long long int> factorial;
        factorial[0] = 1;
        for(long long int i = 1; i<=r; i++){
            factorial[i] = i*factorial[i-1];
        }

        long long int ans = 0;
        long long int prev_max_cal_fac = 0;
        for(long long int i = 0; i<=N; i++){
            long long int p_i = (long long int)pow(p,i);
            if(p_i==r){
                ans+=1;                
            } else if(p_i>r){ 
               long long int p_i_r_f = calculate_fac(p_i-r, prev_max_cal_fac, factorial);               
               prev_max_cal_fac = p_i-r;
               long long int p_i_f = calculate_fac(p_i, prev_max_cal_fac, factorial);
               prev_max_cal_fac = p_i;
               ans+=(p_i_f*modPower(factorial[r],mod-2,mod) % mod *modPower(p_i_r_f,mod-2,mod) % mod)%mod;
               ans%=mod;
            }
        }

        cout << ans%mod << endl;
    }
    return 0;
}