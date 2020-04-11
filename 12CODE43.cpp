#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
/*
ll calAns(ll liIndex, ll ldIndex, vector<ll> &dp1_index, vector<ll> &dp2_index){
    set<ll> SET;
    SET.insert(liIndex);    
    liIndex = dp1_index[liIndex];

    while(liIndex!=-1){        
        SET.insert(liIndex);
        liIndex = dp1_index[liIndex];
    }

    SET.insert(ldIndex);
    ldIndex = dp2_index[ldIndex];

    while(ldIndex!=-1){        
        SET.insert(ldIndex);
        ldIndex = dp2_index[ldIndex];
    }

    return SET.size();
}
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;cin>>T;
    while(T--){
        string S;cin>>S;
        ll N = S.size();
        vector<ll> arr(N, 0);
        for(ll i=0;i<N;i++){
            arr[i] = (ll)(S[i]-'a');                        
        }         
        vector<ll> dp1(N, 1);
        vector<ll> dp1_index(N, -1);

        vector<ll> dp2(N, 1);
        vector<ll> dp2_index(N, -1);
        ll li = 1;
        ll liIndex = 0;
        ll ld = 1;
        ll ldIndex = 0;
        for(ll i=1;i<N;i++){
            for(ll j=0;j<i;j++){
                if(arr[j]<=arr[i]){
                    if(dp1[i] < dp1[j]+1){
                        dp1[i] = dp1[j]+1;
                        dp1_index[i] = j;
                    }
                }


                if(arr[j]>=arr[i]){
                    if(dp2[i] < dp2[j]+1){
                        dp2[i] = dp2[j]+1;
                        dp2_index[i] = j;
                    }
                }
            }

            if(li < dp1[i]){
                li = dp1[i];
                liIndex = i;
            }

            if(ld < dp2[i]){
                ld = dp2[i];
                ldIndex = i;
            }
        }

        /*ll ans = 1;

        for(ll i=0;i<N;i++){
            if(dp1[i]==li){
                for(ll j=0;j<N;j++){
                    if(dp2[j]==ld){
                        ans = max(ans, calAns(liIndex, ldIndex, dp1_index, dp2_index));
                    }
                }
            }
        }     */                  

        cout << max(li, ld)  << endl;

    }

    return 0;
}
    