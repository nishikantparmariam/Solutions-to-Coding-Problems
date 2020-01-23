#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> cost = {{1,100,0,100,100},
                                {100,1,100,100,100},
                                {100,100,1,100,100},
                                {100,100,100,1,100},
                                {0,100,100,100,100},
                                {0,100,1,100,100},
                                {0,100,1,100,100}};


    int N = cost.size();
    int K = cost[0].size();
    int dp[N][K];
    int first_min;
    int second_min;
    for(int i = 0;i<N;i++){
        for(int k=0;k<K;k++){
            if(i==0){
                dp[i][k] = cost[i][k];
            } else {
                dp[i][k] = INT_MAX;             
                if(first_min==dp[i-1][k]) dp[i][k] = second_min+cost[i][k];
                else dp[i][k] = first_min+cost[i][k];                   
            }
            cout << dp[i][k] << " ";
        }
        cout << endl;

        first_min = INT_MAX;
        second_min = INT_MAX;
        for(int k=0;k<K;k++){
            if(dp[i][k] <= first_min){
                second_min = first_min;
                first_min = dp[i][k];
            } else if(dp[i][k] <= second_min){
                second_min = dp[i][k];
            }
        }

      //  cout << "fm = " << first_min << ", sm = " << second_min << endl;

    }   

    int ans = INT_MAX; 

    for(int k=0;k<K;k++){
        ans = min(ans, dp[N-1][k]);
    }

    cout << ans << endl;

    return 0;
}