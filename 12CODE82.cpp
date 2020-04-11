#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)(1e9+7);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    string S;cin>>S;
    int N = S.size();
    
    bool ispossible[N][2];
    memset(ispossible, false, sizeof(ispossible));

    for(int i=0;i<N;i++){
        if(S[i]=='0' || S[i]=='?') ispossible[i][0] = (i>0 ? ispossible[i-1][0] : true);
        else ispossible[i][0] = false;
        if(S[i]=='1' || S[i]=='?') ispossible[i][1] = (i>0 ? ispossible[i-1][1]: true);
        else ispossible[i][1] = false;
    }

    int dp[N][N+1][2];
    memset(dp, 0, sizeof(dp));

    for(int i=0;i<N;i++){
        for(int p=0;p<=N;p++){
            if(p==0){
                dp[i][p][0] = 0;
                dp[i][p][1] = 0;
            } else if(p==1){
                dp[i][p][0] = ((ispossible[i][0]) ? 1:0);
                dp[i][p][1] = ((ispossible[i][1]) ? 1:0);
            }
            else {  
                dp[i][p][0] = ((( i>0 ? dp[i-1][p][0] : 0 )%MOD*((S[i]=='0' || S[i]=='?') ? 1 : 0)%MOD)%MOD+ ((i>0 ? dp[i-1][p-1][1] : 0)%MOD*((S[i]=='0' || S[i]=='?') ? 1 : 0)%MOD)%MOD)%MOD;                          
                dp[i][p][1] = ((( i>0 ? dp[i-1][p][1] : 0 )%MOD*((S[i]=='1' || S[i]=='?') ? 1 : 0)%MOD)%MOD+ ((i>0 ? dp[i-1][p-1][0] : 0)%MOD*((S[i]=='1' || S[i]=='?') ? 1 : 0)%MOD)%MOD)%MOD;                          
            }
        }
    }

    for(int p=1;p<=N;p++){
        cout << (dp[N-1][p][0]%MOD+dp[N-1][p][1]%MOD)%MOD << ((p<N) ? " ":"");
    }
    return 0; 
}