#include <bits/stdc++.h>
using namespace std;

int main(){
    string A = "NISHIKANT";
    string B = "ISpIKA";
    int N = A.size();
    int M = B.size();
    int dp[N][M];
    int ans = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(A[i]==B[j]) {
                if(i>0 && j>0) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = 1;
            }
            else dp[i][j] = 0;            

            ans = max(dp[i][j], ans);
        }
    }    

    cout << ans << endl;
    return 0;
}