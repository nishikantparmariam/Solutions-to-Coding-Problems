#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll MOD = 1000000007;

void multiply(vector<vector<ll>> &A, vector<vector<ll>> &B, vector<vector<ll>> &C){    
    for(ll i=0;i<2;i++){
        for(ll j=0;j<2;j++){
            C[i][j] = 0;
        }
    }
    for(ll i = 0;i<2;i++){
        for(ll j = 0;j<2;j++){
            for(ll k=0;k<2;k++){
                C[i][j] = ((A[i][k]%MOD*B[k][j]%MOD)%MOD+C[i][j]%MOD)%MOD;
                
            }            
        }       
    }    
}

void power(vector<vector<ll>> &A, ll y, vector<vector<ll>> &res){
    for(ll i=0;i<2;i++){
        for(ll j=0;j<2;j++){
            if(i==j){
                res[i][j] = 1;
            } else {
                res[i][j] = 0; 
            }
        }
    }  
    vector<vector<ll>> temp = {{0,0},{0,0}};    
    while(y>0){
        
        if(y & 1){
            multiply(res, A, temp);
            res = temp;                
        }
        y = y>>1;        
        multiply(A, A, temp);
        A = temp;
    }    
}

int main(){
    ll T;cin>>T;    
    while(T--){
        ll N; ll M;
        cin>>N;cin>>M;
        //cout << N << " " << M << endl;
        vector<vector<ll>> P = {{(M-1)%MOD, (M-1)%MOD},{1,0}};
        vector<vector<ll>> res = {{1,0},{0,1}};        
        power(P,N-1,res);                   
        ll a1 = (res[0][0]%MOD*M%MOD)%MOD;
        ll a2 = (res[1][0]%MOD*M%MOD)%MOD;    
        cout << (a1+a2)%MOD << endl;        
    }
 
    return 0;
}