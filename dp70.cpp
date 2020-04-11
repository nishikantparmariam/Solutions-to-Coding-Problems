#include <bits/stdc++.h>
using namespace std;

int go(vector<int> &arr, int i, int j, int K, vector<vector<int>> &dp){
    if(i<=j){        
        if(dp[i][j]!=-1) return dp[i][j];
        if(arr[j]-arr[i]<=K){
            dp[i][j] =  0;
        } else {
            int m = min(go(arr,i+1,j,K,dp),go(arr,i,j-1,K,dp));
            if(m!=INT_MAX) dp[i][j] =  1+m;
            else dp[i][j] =  INT_MAX;
        }

        return dp[i][j];
    } return INT_MAX;
}

int main(){
    vector<int> arr = {1, 5, 6, 2, 8};
    sort(arr.begin(), arr.end());
    int K = 2;
    vector<vector<int>> dp(arr.size(), vector<int> (arr.size(), -1));
    cout << go(arr, 0, arr.size()-1, K, dp);
    return 0;    
}