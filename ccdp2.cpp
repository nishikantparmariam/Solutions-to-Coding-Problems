#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll _max(ll a, ll b, ll c, ll d, ll e){
    return max(a, max(b, max(c, max(d,e))));
}

int main(){
    int T;cin>>T;
    while(T--){
        ll N;cin>>N;
      //  cout << N << endl;
        ll arr[N];
        ll dp_forward[N][2];
        ll dp_backward[N][2];
        ll dp_forward_tillNow[N][2];
        ll dp_backward_tillNow[N][2];             
        ll j = 0;  
        while(j<N){
            ll i = j;
            cin>>arr[i];
            //cout << N;        
            dp_forward[i][0] = arr[i];
            dp_forward[i][1] = arr[i];
            dp_backward[i][0] = arr[i];
            dp_backward[i][1] = arr[i];
            dp_forward_tillNow[i][0] = arr[i];
            dp_forward_tillNow[i][1] = arr[i];    
            dp_backward_tillNow[i][0] = arr[i];
            dp_backward_tillNow[i][1] = arr[i]; 
            j++;
        }                
        for(ll i=1;i<N;i++){            
            dp_forward[i][0] = max(dp_forward[i][0], dp_forward[i][0]+dp_forward[i-1][0]);
            dp_forward[i][1] = min(dp_forward[i][1], dp_forward[i][1]+dp_forward[i-1][1]);
            dp_forward_tillNow[i][0] = max(dp_forward_tillNow[i-1][0], dp_forward[i][0]);
            dp_forward_tillNow[i][1] = min(dp_forward_tillNow[i-1][1], dp_forward[i][1]);
         
        }        
        for(ll i=N-2;i>=0;i--){
            dp_backward[i][0] = max(dp_backward[i][0], dp_backward[i][0]+dp_backward[i+1][0]);
            dp_backward[i][1] = min(dp_backward[i][1], dp_backward[i][1]+dp_backward[i+1][1]);
            dp_backward_tillNow[i][0] = max(dp_backward_tillNow[i+1][0], dp_backward[i][0]);
            dp_backward_tillNow[i][1] = min(dp_backward_tillNow[i+1][1], dp_backward[i][1]);
          
        }        

        int ans = INT_MIN;
        for(ll i=0;i<N-1;i++){            
            ans = _max(ans, abs(dp_forward_tillNow[i][0]-dp_backward_tillNow[i+1][0]), abs(dp_forward_tillNow[i][0]-dp_backward_tillNow[i+1][1]), abs(dp_forward_tillNow[i][1]-dp_backward_tillNow[i+1][0]), abs(dp_forward_tillNow[i][1]-dp_backward_tillNow[i+1][1]));
        }
        cout << ans << endl;

    }
    return 0;
}