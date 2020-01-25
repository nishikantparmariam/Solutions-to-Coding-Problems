#include <bits/stdc++.h>
using namespace std;

long long int power(long long int x, long long int y, long long int p) 
{ 
    long long int res = 1;      
  
    x = x % p; 
    while (y > 0) 
    { 
        
        if (y & 1) 
            res = (res*x) % p; 
          
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 

int main(){
    long long int MOD  = 1000000007;
    long long int T;cin>>T;
    while(T--){
        long long int N;cin>>N;
        long long int M;cin>>M;        
        long long int last = 0;
        long long int second_last = 0;
        long long int ans = 0;
        /*for(long long int i=0;i<N;i++){
            if(i==0 || i==1){
                if(i==0) {
                    ans = M%MOD;
                    second_last = ans;
                } else {
                    ans = ((M%MOD)*(M%MOD))%MOD;
                    last = ans;
                }            
            }
            else {
                ans = (((M-1)%MOD)*((second_last%MOD+last%MOD)%MOD))%MOD;
                second_last = last;
                last = ans;
            } 
            //cout << ans << " ";
        }   */      
        ans = (power(M, N, MOD)%MOD - ((M%MOD*(N-1)%MOD))%MOD)%MOD;
        cout << ans << endl;
    }
    return 0;
}