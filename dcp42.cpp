#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {12, 1, 61, 5, 9, 2};
    int K = 24;
    int N = sizeof(arr)/sizeof(arr[0]);
    pair<int,int> dp[N][K+1];    
    for(int i=0;i<N;i++){
        for(int k=0;k<=K;k++){
            dp[i][k] = make_pair(0,0);
        }
    }
    for(int i=0;i<N;i++){
        for(int k=0;k<=K;k++){
            if(arr[i]==k) dp[i][k] = make_pair(0,0);
            else if(arr[i]>k){
                if(i==0) dp[i][k] = make_pair(-1,-1);
                else dp[i][k] = make_pair(i-1,k);
            } else {
                if(i==0){
                    dp[i][k] = make_pair(-1,-1);
                } else {
                    pair<int,int> p1 = dp[i-1][k];
                    pair<int,int> p2 = dp[i-1][k-arr[i]];
                    if(p1.first!=-1){
                        dp[i][k] = p1;
                    } else {
                        dp[i][k] = p2;
                    }                    
                }
            }         
            
        }                   
    }

    if(dp[N-1][K].first!=-1){
        pair<int,int> p = dp[N-1][K];
        while(p.first!=0){   
            cout << arr[p.first] << " ";         
            p = dp[p.first][p.second];                        
        }
        cout << arr[p.first];
    } else cout << "NO!";
    return 0;
}