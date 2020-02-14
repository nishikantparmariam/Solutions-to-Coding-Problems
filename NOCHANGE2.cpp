#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    ll T;cin>>T;
    while(T--){
        ll N;ll P;
        cin>>N;cin>>P;
        ll coins[N];        
        ll i_of_greater = -1;
        ll i_of_rem = -1;
        for(ll i=0;i<N;i++){
            cin>>coins[i];
            if(coins[i]>P) i_of_greater = i; 
            ll rem = P%coins[i];
            if(rem>0){
                i_of_rem = i;
            }                       
        }      

        if(i_of_greater!=-1){
            cout << "YES";
            for(ll i=0;i<N;i++){
                if(i==i_of_greater) cout << " 1";
                else cout << " 0";            
            }
        } else if(i_of_rem!=-1){
            cout << "YES";
            for(ll i=0;i<N;i++){
                if(i==i_of_rem) cout << " " << floor(P/coins[i])+1;
                else cout << " 0";            
            }
        } else {
            cout << "NO";
        }            

        cout << endl;

    }
    return 0;    
}