#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;
ll dp[100][420][2];


int gi(char c){
    if(c=='+') return 0;
    return 1;
}

ll ans(ll i, ll sum_now, char c, string str, ll fv, ll index, ll N){
    if(dp[i][sum_now][gi(c)]!=-1){
        return dp[i][sum_now][gi(c)];
    }
    ll ways = 0;
    if(str[i]=='_'){        
        char toPassC = str[i+1];        
        if(c=='+'){
            for(ll j=1;j<=fv;j++){                
                ways+=ans(i+2,sum_now+j,toPassC,str,fv,index,N);
            }
        } else {
            for(ll j=1;j<=fv;j++){                
                ways+=ans(i+2,sum_now-j,toPassC,str,fv,index,N);
            }
        }

    } else {
        if(sum_now==fv){
            return 1;
        }
    }
    dp[i][sum_now][gi(c)] = ways;
    return dp[i][sum_now][gi(c)];
}

ll final_ans(string str){
    int i;
    for(i=str.size()-1; i>=0; i--){
        if(str[i]=='='){
            break;
        }
    }
    return i+1;
}


int main(){
    int T;cin>>T;
    while(T--){        
        for(ll i=0;i<100;i++){
            for(ll j=0;j<420;j++){
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }
        string str;cin>>str;
        ll N = str.size();
        ll index = final_ans(str);
        ll fv = stoi(str.substr(index, N-index));
        cout << ans(0,0,'+',str,fv,index,N) << endl;
    }

    return 0;
}