#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll lcm(ll a,ll b){
    return a*b/__gcd(a,b);
}
/*
a = Bob
b = Alice

*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;cin>>T;
    while(T--){
        ll N;ll a;ll b;
        cin>>N;cin>>a;cin>>b;
        ll arr[N];
        ll onlya=0;ll onlyb=0;ll both=0;
        for(ll i=0;i<N;i++) {
            cin>>arr[i];
            if(arr[i]%lcm(a,b)==0) both++;
            else if(arr[i]%a==0) onlya++;
            else if(arr[i]%b==0) onlyb++;
        }
      
        if(a==b) cout << "BOB" << endl;
        else {
            if(both==0 && onlya==0){
                cout << "ALICE" << endl;
            } else if(both!=0 && onlya==0){
                if(onlyb==0) cout << "BOB" << endl;
                else cout << "ALICE" << endl;
            } else if(both==0 && onlya!=0){
                if(onlyb==0) cout << "BOB" << endl;
                else {
                    if(onlya > onlyb) cout << "BOB" << endl;
                    else cout << "ALICE" << endl; 
                }
            } else {
                if(onlyb==0) cout << "BOB" << endl;
                else {
                    if(onlyb > onlya) cout << "ALICE" << endl;
                    else cout << "BOB" << endl;
                }
            }
        }
    }  
    return 0;
}