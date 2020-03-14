#include <bits/stdc++.h>
using namespace std;

int main(){
    string S = "TWENTYONE";
    int N = S.size();
    int dp[N][N];
    memset(dp, 0, sizeof(dp));
    for(int len=1;len<=N;len++){
        int i = 0;
        int j = i+len-1;
        while(j<N){
            if(len==1) dp[i][j] = 1; 
            else if(len==2){
                if(S[i]==S[j]) dp[i][j] = 2;
                else dp[i][j] = 3;
            } else {
                if(S[i]==S[j]) dp[i][j] = dp[i+1][j-1]+2;                     
                else dp[i][j] = 2+min(dp[i+1][j], dp[i][j-1]);                
            }
            
            i++;
            j++;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[0][N-1] << endl;
    return 0;;
}