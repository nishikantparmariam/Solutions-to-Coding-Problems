#include <bits/stdc++.h>
using namespace std;

int threeNum(int a,int b,int c){
    return min(a+b+a+b+c,b+c+b+c+a); 
}

int presum[100];

int sum_of(int i,int j){
    if(i>0) return presum[j]-presum[i-1];
    return presum[j];
}

int main(){
    int N;cin>>N;
    int arr[N];
    for(int i=0;i<N;i++) {
        cin>>arr[i];
        if(i==0) presum[i] = arr[i];
        else presum[i] = arr[i]+presum[i-1];
    }
    int dp[N][N];
    for(int len = 1;len<=N;len++){
        int i = 0;
        int j = i+len-1;
        while(j<N){
            if(len==1){
                dp[i][j] = arr[i];
            } else if(len==2){
                dp[i][j] = arr[i]+arr[j];
            } else {
                dp[i][j] = INT_MAX;
                for(int k=i;k<j;k++){
                    dp[i][j] = min(dp[i][j], (k>i ? dp[i][k] : 0)+(k+1<j ? dp[k+1][j] : 0)+sum_of(i,j));
                }       
                                    
            }
           //  cout << dp[i][j] << " | " << i << "," << j << endl;
            i++;j++;
        }
    }

    cout << dp[0][N-1] << endl;
    return 0;
}