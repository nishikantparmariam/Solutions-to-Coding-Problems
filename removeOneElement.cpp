#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;cin>>N;
    int arr[N];
    for(int i=0;i<N;i++) cin>>arr[i];
    int starting_here[N];
    int ending_here[N];
    for(int i=0;i<N;i++){
        starting_here[i] = 1;
        ending_here[i] = 1;
    }
    int ans = 1;
    for(int i=1;i<N;i++){
        if(arr[i-1] < arr[i]){
            ending_here[i] = 1+ending_here[i-1];            
        }
        ans = max(ans, ending_here[i]);
    }
    for(int i=N-2;i>=0;i--){
        if(arr[i] < arr[i+1]){
            starting_here[i] = 1+starting_here[i+1];
        }
    }
    for(int i=2;i<N-1;i++){
        if(arr[i-1] < arr[i+1]){
            ans = max(ans, ending_here[i-1]+starting_here[i+1]);
        }
    }
    cout << ans << endl;
    return 0;
}


