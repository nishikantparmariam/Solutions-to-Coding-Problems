#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        int N;int M;int a;int b;
        cin>>N;cin>>M;cin>>a;cin>>b;
        if(b<a){
            int temp = a;
            a = b;
            b = temp;
        }
        vector<int> arr(N, 0);
        for(int i=0;i<N;i++) cin>>arr[i];
        if(M==0) cout << b-a << endl;
        else if(N==1){
            vector<int> p = {a,arr[0],b};
            sort(p.begin(), p.end());            
            cout << max(p[2]-p[1], p[1]-p[0]) << endl;
        } else {            
            vector<int> A(N, 0);
            for(int i=0;i<N;i++){
                if(arr[i]<=a){
                    A[i] = abs(a-arr[i]);
                } else if(b<=arr[i]){
                    A[i] = abs(b-arr[i]);
                } else {
                    A[i] = max(abs(a-arr[i]), abs(b-arr[i]));
                }                
            }
            for(int i=0;i<N;i++) cout << A[i] << " ";     
            sort(A.begin(), A.end());                                    
            //cout << A[M-1] 
            cout << endl;
        }        
    }

    return 0;
}