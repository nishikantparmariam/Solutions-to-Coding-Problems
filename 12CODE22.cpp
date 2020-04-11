#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool cmp(const pair<ll, pair<string,string>> &p1, const pair<ll, pair<string,string>> &p2){
    return p1.first > p2.first;
}

ll calScore(string &A, string &B){
    ll ans = 0;
    ll s1 = 0;
    ll s2 = 0;
    ll e1 = A.size()-1;
    ll e2 = B.size()-1;
    while(s1 < min(A.size(), B.size()) && s2 < min(A.size(), B.size()) && e1>=0 && e2>=0){
        if(A[s1]==B[s2] && A[e1]==B[e2]){
            s1++;
            s2++;
            e1--;
            e2--;
            ans++;
        } else {
            break;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        ll N;cin>>N;        
        unordered_map<string, int> MAP;
        for(int i=0;i<N;i++) {
            string S;
            cin>>S;
            MAP[S]++;
        }       

        ll ans = 0;
        vector<string> arr;

        for(auto it=MAP.begin();it!=MAP.end();it++){
            ll count = it->second;
            ans+=((ll)(floor(count/2)))*((it->first).size())*((it->first).size());
            if(count%2==1){
                arr.push_back(it->first);
            }
        }                          

        vector<pair<ll, pair<string,string>>> scores;

        for(ll i=0;i<arr.size()-1;i++){
            for(ll j=i+1;j<arr.size();j++){
                ll s = calScore(arr[i], arr[j]);
                scores.push_back(make_pair(s, make_pair(arr[i],arr[j])));
            }
        }

        sort(scores.begin(), scores.end(), cmp);
            
        unordered_set<string> SET;
        for(pair<ll, pair<string,string>> p:scores){
            
            string s1 = p.second.first;
            string s2 = p.second.second;
            if(SET.find(s1)==SET.end() && SET.find(s2)==SET.end()){
                ans+=(p.first)*(p.first);
                SET.insert(s1);
                SET.insert(s2);
            }     
        }
        cout << ans << endl;
    }
    return 0;
}