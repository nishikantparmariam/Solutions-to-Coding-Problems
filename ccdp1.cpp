#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;cin>>T;
    while(T--){
        long long int N;cin>>N;   
        long long int arr[N];
        long long int dp[N];
        for(long long int i =0 ;i <N;i++){
            cin>>arr[i];
            dp[i] = 1;
        } 

        for(long long int i=N-2;i>=0;i--){
            if((arr[i]>0 && arr[i+1]<0) || arr[i]<0 && arr[i+1]>0){
                dp[i] = dp[i+1]+1;
            }
        }

        for(long long int i=0;i<N;i++){
            cout << dp[i] << " ";
        }
        cout << endl;

    }    
    return 0;
}