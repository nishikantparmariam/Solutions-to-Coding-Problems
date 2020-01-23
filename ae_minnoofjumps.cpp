#include <bits/stdc++.h>
using namespace std;


int main(){
    int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    //O(n**2)

    long long int dp[n];
    memset(dp,-1,n);
    for(int i=0;i<n;i++){
        if(i==0) dp[i] = 0;
        else {
            for(int k=0;k<=i-1;k++){
                if(k+arr[k]>=i){
                    if(dp[i]==-1){
                        dp[i] = dp[k]+1;
                    } else {
                        dp[i] = min(dp[i], dp[k]+1);
                    }                    
                }
            }
        }
        cout << dp[i] << " -- ";
    }

    //O(n)
    cout << endl;
    int ladder = arr[0];
    int stairs = arr[0];
    int jumps = 1;

    for(int i = 1;i<n;i++){
        if(i==n-1) {            
            break;
        }

        if(i+arr[i] > ladder){
            ladder = i+arr[i]; 
        }

        stairs--;
        if(stairs==0){
            jumps++;
            stairs = ladder - i;
        }
    }
    cout << jumps << " ";     
    
    return 0;
}