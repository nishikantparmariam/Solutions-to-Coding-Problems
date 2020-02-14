#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;cin>>N;
    vector<int> boys;
    for(int i=0;i<N;i++) {
        int x;cin>>x;
        boys.push_back(x);
    }

    int M;cin>>M;
    vector<int> girls;
    for(int i=0;i<M;i++) {
        int x;cin>>x;
        girls.push_back(x);
    }

    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());
    int i = 0;int j = 0;
    int ans = 0;
    while(i<N && j<M){
        if(abs(boys[i]-girls[j])<=1){
            i++;j++;ans++;
        } else if(boys[i] > girls[j]){
            j++;
        } else {
            i++;
        }
    }

    cout << ans << endl;
    return 0;
}