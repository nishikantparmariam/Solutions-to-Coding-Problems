#include <bits/stdc++.h>
using namespace std;

int main(){    
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        int M;cin>>M;
        int A[N];
        int B[M];
        for(int i=0;i<N;i++) cin>>A[i];
        for(int j=0;j<M;j++) cin>>B[j];        
        int table[M];
        for(int j=0;j<M;j++) table[j] = 0;
        for(int i=0;i<N;i++){
            int current = 0;
            for(int j=0;j<M;j++){
                if(A[i]==B[j]){
                    if(current + 1 > table[j]){
                        table[j] = current + 1; 
                    }
                }

                if(A[i] > B[j]){
                    if(table[j] > current){
                        current = table[j];
                    }
                }
            }
        }



        int ans = -INT_MAX;
        for(int j=0;j<M;j++) {
            ans = max(ans, table[j]);
            cout << table[j] << endl;
        }

        cout << ans << endl;
    }
    return 0;
}