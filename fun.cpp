#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int lps(int i, int j, string A){
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==j) return 1;
    if(i>j) return 0;
    if(A[i]==A[j]) {
        dp[i][j] = 2+lps(i+1,j-1,A);
        return dp[i][j];
    } else {
        dp[i][j]=max(lps(i,j-1,A),lps(i+1,j,A)); 
        return dp[i][j];   
    }
    
}

int main(){
    for(int i = 0; i<100;i++){
        for(int j = 0; j<100;j++){
            dp[i][j] = -1;
        }   
    }
    string A = "AXABBCBBAA";
    cout << lps(0,A.size()-1,A) << endl;

    int N = A.size();
    int dp2[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) dp2[i][j] = 1;
            else dp2[i][j] = 0;
        }
    }
    int ans = 1;
    for(int length = 2; length<=N;length++){        
        for(int i = 0;i<=N-length;i++){
            int j = i+length-1;
            if(A[i]==A[j]){
                dp2[i][j] = 2+dp2[i+1][j-1];
            } else {
                dp2[i][j] = dp2[i+1][j-1];
            }
            ans = max(ans,dp2[i][j]);
        }
    }

    for(int i = 0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << dp2[i][j] << " ";
        }
        cout << endl;
    }

    cout << ans ;
    return 0;
}