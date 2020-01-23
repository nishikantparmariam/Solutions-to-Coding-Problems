#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;cin>>T;
    while(T--){
        int S,W1,W2,W3;
        cin>>S;cin>>W1;cin>>W2;cin>>W3;
        if(W1+W2+W3<=S){
            cout << 1 << endl;
        } else if(W1+W2<=S | W2+W3<=S){
            cout << 2 << endl;
        } else {
            cout << 3 << endl;
        } 
    }
    return 0;
}