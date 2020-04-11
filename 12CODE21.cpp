#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool cmp(const ll a, const ll b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;ll K;
    cin>>N;cin>>K;
    vector<ll> pages(N, 0);
    for(ll i=0;i<N;i++){
        ll a; ll b;
        cin>>a;cin>>b;
        pages[i] = max(a, b);
    }
    sort(pages.begin(), pages.end(), cmp);
    ll ans = 0;
    for(ll i=0;i<K;i++){
        ans+=pages[i];
    }
    cout << 2*ans << endl;
    return 0;
}