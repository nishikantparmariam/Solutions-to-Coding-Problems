#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool mycmp(const pair<pair<ll,ll>,pair<ll,ll>> &p1, const pair<pair<ll,ll>,pair<ll,ll>> &p2){
    return p1.second.first < p2.second.first;
}

bool mycmp2(const pair<pair<ll,ll>,pair<ll,ll>> &p1, const pair<pair<ll,ll>,pair<ll,ll>> &p2){
    return p1.first.first < p2.first.first;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;cin>>T;
    while(T--){
        ll N;cin>>N;
        vector<pair<pair<ll,ll>,pair<ll,ll>>> arr(N, make_pair(make_pair(0,0),make_pair(0,0)));
        for(ll i=0;i<N;i++){
            ll s;ll e;
            cin>>s;cin>>e;
            arr[i] = make_pair(make_pair(i, 0), make_pair(s, e));
        }

        sort(arr.begin(), arr.end(), mycmp);

        /*for(ll i=0;i<N;i++){
            cout << arr[i].second.first << " " << arr[i].second.second << endl;
        } */

        ll maxEp = -INT_MAX;
        int maxEpColor = 0; 
        //0 for red
        //1 for yellow
        for(ll i=0;i<N;i++){
            ll s = arr[i].second.first;
            ll e = arr[i].second.second;
            if(s >= maxEp){
                maxEp = e;
                arr[i].first.second = 0;
                maxEpColor = 0;
            } else {
                if(e<=maxEp){
                    arr[i].first.second = (maxEpColor==1 ? 0:1);
                } else {
                    arr[i].first.second = (maxEpColor==1 ? 0:1);
                    maxEpColor = arr[i].first.second;
                    maxEp = e;
                }
            }
        }

        sort(arr.begin(), arr.end(), mycmp2);

        for(int i=0;i<N;i++){
            cout << arr[i].first.second;
        }

        cout << endl;
    }
 
    return 0;
}