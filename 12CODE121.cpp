#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    ll N;ll D;ll Q;
    cin>>N;cin>>D;cin>>Q;
    vector<ll> arr(N, 0);
    while(D--){
        ll L;ll R;
        cin>>L;cin>>R;
        L--;R--;
        arr[L]++;
        if(R+1<N) arr[R+1]--;
    }
    for(ll i=0;i<N;i++){
        arr[i] = arr[i]+(i>0?arr[i-1]:0);
        //cout << arr[i] << " ";
    }

    //sort(arr.begin(), arr.end());

    while(Q--){
        ll X;cin>>X;
        ll ans = 0;
        for(ll i=0;i<N;i++){
            if(arr[i]>=X) ans++;
        }
        cout << ans << endl;/*
        if(X<=arr[0]){
            cout << N << endl;
        } else if(X>arr[N-1]){
            cout << 0 << endl;
        } else {
            //bs
            ll low = 0;
            ll high = N-1;
            ll ans = -1;
            while(low<=high){
                ll mid = low+(high-low)/2;
                if(arr[mid]<X){
                    low = mid+1;
                } else {
                    ans = N-mid;
                    high = mid-1;
                }
            }

            cout << ans << endl;
        }*/
    }
    
    return 0;
}
    