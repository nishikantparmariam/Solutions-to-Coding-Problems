#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        int value[N];
        int coins[N];
        int maxValue = 0;
        for(int i=0;i<N;i++){
            cin>>value[i];
            value[i] = 2*value[i];
            maxValue = max(maxValue, value[i]);
        }
        for(int i=0;i<N;i++){
            cin>>coins[i];            
        }        
        int dp[N][maxValue+1];
        bool possible[N][maxValue+1];
        for(int i=0;i<N;i++){
            for(int v=0;v<=maxValue;v++){
                if(v==0) dp[i][v] = 0;
                else {
                    if(i==0){
                        if(coins[i] > v){
                            dp[i][v] = -1;
                        } else {                            
                            dp[i][v] = (dp[i][v-coins[i]]!=-1 ? 1+dp[i][v-coins[i]] : -1);                            
                        }
                    } else {
                        if(coins[i] > v){
                            dp[i][v] = dp[i-1][v];
                        } else {
                            if(dp[i][v-coins[i]]!=-1 && dp[i-1][v]!=-1) dp[i][v] = min(dp[i-1][v], 1+dp[i][v-coins[i]]);
                            else if(dp[i][v-coins[i]]==-1 && dp[i-1][v]!=-1) dp[i][v] = dp[i-1][v];
                            else if(dp[i][v-coins[i]]!=-1 && dp[i-1][v]==-1) dp[i][v] = 1+dp[i][v-coins[i]];
                            else dp[i][v] = -1;
                        }
                    }
                }                
            }
            
        }

        int ans = 0;
        for(int i=0;i<N;i++){
            ans+=dp[N-1][value[i]];
        }
        cout << ans << endl;
    }
    return 0;
}