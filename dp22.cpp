#include <bits/stdc++.h>
using namespace std;

int go(int i,int j,string S){
    cout << i << "--" << j << endl;
    if(i==S.size()) return 1;
    if(S[i]!=S[j]) return 1+go(i+1,i+1,S);
    else {
        return min(go(i+1,j,S), 1+go(i+1,i+1,S));
    }
}

int main(){
    string S = "abcde";
    cout << go(0,0,S) << endl; 
    return 0;
}