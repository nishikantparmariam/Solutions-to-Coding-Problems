#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;ll Q;
    cin>>N;cin>>Q;
    ll arr[N];
    for(ll i=0;i<N;i++){
        cin>>arr[i];
    }
    ll inc_start[N];
    ll dec_start[N];
    
    for(ll i=0;i<N;i++){
        if(i==0){
            if(arr[i]<arr[i+1]){
                inc_start[i]=1;
            } else inc_start[i]=0;
            
            if(arr[i]>arr[i+1]){
                dec_start[i]=1;
            } else dec_start[i]=0;

        } else if(i==N-1){
            inc_start[i]=inc_start[i-1];
            dec_start[i]=dec_start[i-1];
        } else {
            if(arr[i]<arr[i+1] && arr[i]<arr[i-1]){
                inc_start[i]=inc_start[i-1]+1;
            } else {
                inc_start[i]=inc_start[i-1];
            } 

            if(arr[i]>arr[i+1] && arr[i]>arr[i-1]){
                dec_start[i]=dec_start[i-1]+1;
            } else {
                dec_start[i]=dec_start[i-1];
            } 
        }        
    }

    while(Q--){
        ll L;ll R;
        cin>>L;cin>>R;
        L--;R--;
        ll maximal_inc_count = 0;     
        if(arr[L]<arr[L+1]) maximal_inc_count++;
        if(R!=N-1){
            if(arr[R]<arr[R+1] && arr[R]<arr[R-1]) maximal_inc_count--;
        }                
        maximal_inc_count+=inc_start[R]-inc_start[L];

        ll maximal_dec_count = 0;     
        if(arr[L]>arr[L+1]) maximal_dec_count++;
        if(R!=N-1){
            if(arr[R]>arr[R+1] && arr[R]>arr[R-1]) maximal_dec_count--;
        }                
        maximal_dec_count+=dec_start[R]-dec_start[L];

        if(maximal_inc_count==maximal_dec_count) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}
