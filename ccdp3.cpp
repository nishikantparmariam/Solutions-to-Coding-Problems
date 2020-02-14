#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        char grid[N][N];
        int dp[N][N][2]; //right, bottom
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>grid[i][j];                
            }
        }


        int ans = 0;
        for(int i=N-1;i>=0;i--){
            for(int j=N-1;j>=0;j--){
                if(j!=N-1) dp[i][j][0] = dp[i][j+1][0]; 
                else dp[i][j][0] = 0;

                if(i!=N-1) dp[i][j][1] = dp[i+1][j][1];
                else dp[i][j][1] = 0;


                if(grid[i][j]=='#') {
                    dp[i][j][0]++;     
                    dp[i][j][1]++;     
                }

                if(dp[i][j][0]==0 && dp[i][j][1]==0) ans++;
            }
        }

        cout << ans << endl;
    }
    return 0;
}