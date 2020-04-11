#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;cin>>N;
    int arr[N];
    for(int i=0;i<N;i++) cin>>arr[i];    
    int conse[N];
    int notco[N];
    conse[0] = arr[0]; 
    notco[0] = arr[0]; 
    conse[1] = arr[0]+arr[1]; 
    notco[1] = arr[1];

    for(int i=2;i<N;i++){
        notco[i] = arr[i]+max(notco[i-2], conse[i-2]);
        conse[i] = arr[i]+notco[i-1];
    }

    cout << max(notco[N-1], conse[N-1]) << endl;
    return 0;
}