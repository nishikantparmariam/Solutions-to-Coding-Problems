#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll timeNeeded(ll arr[], ll N, ll K){
    ll time = 0;
    for(ll i=0;i<N;i++){
        if(arr[i] <= K){
            time+=1;
        } else {
            if(arr[i]%K==0){
                time+=(arr[i]/K);
            } else {
                time+=(int)(floor(arr[i]/K))+1;
            }
        }
    }
    return time;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;cin>>T;
    while(T--){
        ll N;cin>>N;
        ll H;cin>>H;
        ll arr[N];  
        ll max_arr = -INT_MAX;
        for(ll i=0;i<N;i++) {
            cin>>arr[i];
            max_arr = max(max_arr, arr[i]);
        }

        ll low = 1;
        ll high = max_arr;
        ll ans = -1;
        while(low<=high){
            ll mid = low+(high-low)/2;
            ll tn = timeNeeded(arr, N, mid);
            if(tn<=H){
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
    