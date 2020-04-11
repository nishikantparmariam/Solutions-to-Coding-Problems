#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;    

12   13  14         94

7-1         6 



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        ll l;ll r;ll g;
        cin>>l;
        cin>>r;
        cin>>g;
        

        ll p = r/g-l/g;
        if(l%g==0) p++;
        if((g<l || g>r) && p==1) p=0;
        cout << p << endl;
    }
    return 0;
}