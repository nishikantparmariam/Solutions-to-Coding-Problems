#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = 1003;

bool eval(string S, ll i, bool exp1, bool exp2){
    char op = S[2*i+1];
    bool finalexp;
    if(op=='&'){
        finalexp = exp1 & exp2;
    } else if(op=='|'){
        finalexp = exp1 | exp2;
    } else {
        finalexp = exp1 ^ exp2;
    }
    return finalexp;
}

bool giveBool(string S, ll i){
    if(S[2*i]=='T') return true;
    return false;
    //return S[2*i];
}

int main(){
    ll T;cin>>T;
    while(T--){
        ll N;cin>>N;
        string S;cin>>S;
        ll n = floor(N/2)+1;
        pair<ll,ll> dp[n][n]; //true, false
        for(ll len=1;len<=n;len++){
            ll i = 0;
            ll j = i+len-1;
            while(j<n){
                if(len==1){
                    if(giveBool(S,i)){
                        dp[i][j] = make_pair(1,0);
                    } else {
                        dp[i][j] = make_pair(0,1);
                    }
                } else if(len==2){                    
                    bool exp1 = giveBool(S,i);
                    bool exp2 = giveBool(S,j);                                
                    if(eval(S,i,exp1,exp2)){
                        dp[i][j] = make_pair(1,0);
                    } else {
                        dp[i][j] = make_pair(0,1);
                    }
                } else {
                    ll no_T = 0;
                    ll no_F = 0;                    

                    for(ll k=i;k<=j-1;k++){
                        pair<ll,ll> exp1 = dp[i][k];
                        pair<ll,ll> exp2 = dp[k+1][j];
                        ll T1 = exp1.first;
                        ll T2 = exp2.first;
                        ll F1 = exp1.second;
                        ll F2 = exp2.second;

                        if(S[2*k+1]=='&'){
                            no_T=(no_T+(T1*T2)%MOD)%MOD;
                            no_F=(no_F+(((F1*F2)%MOD+(T1*F2)%MOD)%MOD+(F1*T2)%MOD)%MOD)%MOD;                          
                        } else if(S[2*k+1]=='|'){                            
                            no_T=(no_T+(((T1*T2)%MOD+(T1*F2)%MOD)%MOD+(F1*T2)%MOD)%MOD)%MOD;                          
                            no_F=(no_F+(F1*F2)%MOD)%MOD;
                        } else {
                            no_T=(no_T+((T1*F2)%MOD+(F1*T2)%MOD)%MOD)%MOD;
                            no_F=(no_F+((F1*F2)%MOD+(T1*T2)%MOD)%MOD)%MOD;
                        }
                        
                    }
                                                                                
                    dp[i][j] = make_pair(no_T, no_F);                    
                }
                //cout << "(" << i << "," << j << ")" << "=>" << "(" << dp[i][j].first << "," << dp[i][j].second << ")" << endl;
                i++;
                j++;
            }
        }

        cout << dp[0][n-1].first%MOD << endl;
    }
    return 0;
}