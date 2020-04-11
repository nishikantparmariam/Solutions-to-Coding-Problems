#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<int,int> MAP;
    int numProj[5];
    for(int i=0;i<5;i++) cin>>numProj[i];
    for(int i=0;i<5;i++){
        int N = numProj[i];
        for(int j=0;j<N;j++){
            int projectID;cin>>projectID;
            MAP[projectID]++;
        } 
    }

    int ans = 0;
    for(auto it=MAP.begin();it!=MAP.end();it++){
        if(it->second > 2) ans++;
    }

    cout << ans;

    return 0; 
}