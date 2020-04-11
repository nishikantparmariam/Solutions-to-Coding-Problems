#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        string S;cin>>S;        
        int N = S.size();
        vector<vector<int>> freq(26, vector<int> (N, 0));

        for(int i=0;i<N;i++){
            for(int l=0;l<26;l++) freq[l][i] = (i>0 ? freq[l][i-1] : 0); 
            freq[S[i]-'a'][i]++;
        }

        int Q;cin>>Q;
        while(Q--){
            int L;int R;int k;
            cin>>L;cin>>R;cin>>k;
            L--;R--;
            int ans = 0;
            for(int l=0;l<26;l++){
                if((freq[l][R]-(L>0 ? freq[l][L-1] : 0))>=k) ans++;
            }            
            cout << ans << endl;
        }        
    }
    return 0;
}