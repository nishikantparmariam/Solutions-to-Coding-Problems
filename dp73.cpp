#include <bits/stdc++.h>
using namespace std;

int main(){
    int N = 4;
    int M = 4;
    int mat[N][M] = 
    { 
        {9, 6, 5, 2}, 
        {8, 7, 6, 5}, 
        {7, 3, 1, 6}, 
        {1, 1, 1, 7}, 
    };

    int dp[N][M];
    int path[N][M];

    int ans = 0;
    for(int i=N-1;i>=0;i--){
        for(int j=M-1;j>=0;j--){
            path[i][j] = 0;
            if(i==N-1 && j==M-1) dp[i][j] = 1;
            else if(i==N-1){
                if(abs(mat[i][j]-mat[i][j+1])==1){
                    dp[i][j] = dp[i][j+1]+1;
                    path[i][j] = 1;
                } else {
                    dp[i][j] = 1;                    
                }
            } else if(j==M-1){
                if(abs(mat[i][j]-mat[i+1][j])==1){
                    dp[i][j] = dp[i+1][j]+1;
                    path[i][j] = -1;
                } else {
                    dp[i][j] = 1;
                }
            } else {
                dp[i][j] = 1;
                if(abs(mat[i][j]-mat[i+1][j])==1 && dp[i+1][j]+1 > dp[i][j]){                    
                    dp[i][j] = dp[i+1][j]+1;        
                    path[i][j] = -1;                         
                } 
                if(abs(mat[i][j]-mat[i][j+1])==1 && dp[i][j+1]+1 > dp[i][j]){
                    dp[i][j] = dp[i][j+1]+1;
                    path[i][j] = 1;
                } 
            }

            ans = max(dp[i][j], ans);
        }
    }

    

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(dp[i][j]==ans){
                int row = i;
                int col = j;
                while(path[row][col]!=0){
                    cout << mat[row][col] << " ";
                    if(path[row][col]==1){
                        col++;
                    } else {
                        row++;
                    }
                }
                cout << mat[row][col];
            }
        }
    }    
    
    return 0;
}