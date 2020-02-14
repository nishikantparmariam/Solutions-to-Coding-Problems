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
        ll rem[N];
        unordered_map<ll,int> MAP;
        ll i_of_greater = -1;
        for(ll i=0;i<N;i++){
            cin>>coins[i];
            if(coins[i]>P) i_of_greater = i;
            rem[i] = P%coins[i];
            MAP[coins[i]] = 1;
        }

        if(i_of_greater!=-1){
            cout << "YES ";
            for(ll i=0;i<N;i++){
                if(i!=i_of_greater){
                    cout << "0 ";
                } else {
                    cout << "1 ";
                }
            }
        } else {
            int i_of_nonrem = -1;
            for(ll i=N-1;i>=0;i--){
                if(rem[i]!=0){
                    if(MAP[rem[i]]==0){
                        i_of_nonrem = i;
                        break;
                    }
                }
            }       

            if(i_of_nonrem==-1){
                cout << "NO";
            } else {
                ll D_i_of_nonrem = (ll) floor(P/coins[i_of_nonrem]);
                ll rem_am = P%coins[i_of_nonrem];*/
                if(/*i_of_nonrem==0*/true){
                    cout << "YES ";
                    for(ll i=0;i<N;i++){
                        if(i==i_of_nonrem){
                            cout << D_i_of_nonrem+1 << " ";
                        } else {
                            cout << "0 "; 
                        }
                    }
                }/* else {
                    cout << "YES ";
                    for(ll i=0;i<N;i++){
                        if(i==i_of_nonrem){
                            cout << D_i_of_nonrem << " ";
                        } else if(i==i_of_nonrem-1){
                            if(coins[i] > rem_am){
                                cout << "1 ";
                            } else {
                                cout << rem_am/coins[i]+1 << " ";
                            }                            
                        } else {
                            cout << "0 ";
                        }
                    }
                }*/
            }     
        }                

        cout << endl;

    }
    return 0;    
}