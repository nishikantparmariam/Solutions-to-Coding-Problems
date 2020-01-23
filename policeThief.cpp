#include <bits/stdc++.h>
using namespace std;

int _abs(int x){
    return x>0 ? x:-x;
}

int main(){
    int arr[] = { 'P', 'T', 'T', 'P', 'T' };
    int k = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> police_index;
    vector<int> thief_index;
    for(int i=0;i<n;i++){
        if(arr[i]=='P'){
            police_index.push_back(i);
        } else {
            thief_index.push_back(i);
        }
    }

    int p = 0; int t = 0;
    int ans = 0;
    while(p < police_index.size() && t < thief_index.size()){
        if(_abs(p-t)<=k){
            ans++;  
            p++;
            t++;
        } else if(p<t){
            p++;
        } else {
            t++;
        }
    }

    cout << ans;
    return 0;
}