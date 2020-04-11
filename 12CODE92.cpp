#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        int N;int M;cin>>N;cin>>M;
        vector<vector<int>> val(N, vector<int> (M, 0));
        vector<bool> row(N, false);
        vector<bool> col(M, false);
        bool atleastone = false;
        for(int i=0;i<N;i++){
            string S;cin>>S;
            for(int j=0;j<M;j++){
                val[i][j]=(int)(S[j]-'0');
                if(val[i][j]==1){
                    atleastone = true;
                    row[i] = true;
                    col[j] = true;
                }
            }
        }   

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(atleastone){
                    if(val[i][j]==1){
                        cout << "0 ";
                    } else if(row[i] || col[j]){
                        cout << "1 ";
                    } else {
                        cout << "2 ";
                    }
                } else {
                    cout << "-1 ";
                }
            }
            cout << endl;
        }

    }
    return 0;
}



