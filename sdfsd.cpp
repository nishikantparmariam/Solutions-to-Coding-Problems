#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int T;cin>>T;
    while(T--){
        long long int N;cin>>N;
        vector<long long int> arr(N, -1);
        for(long long int i = 0;i<N;i++) cin>>arr[i];
        long long int k; cin>>k;
        bool notfound = true;
        for(long long int i=0;i<N;i++){
            if(arr[i]==k){
                notfound = false;
                cout << "i = " << i << endl;
            }
        }        
        if(notfound) cout << "Element " << k << " not found." << ednl;
    }
    return 0;
}