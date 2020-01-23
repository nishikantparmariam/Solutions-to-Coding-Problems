#include <bits/stdc++.h>
using namespace std;

int main(){
    string pattern = "ABABCABAB";
    int i = 1;
    int len = 0;    
    int lps[pattern.size()];
    lps[0] = 0;
    cout << lps[0] << " ";
    while(i<pattern.size()){
        if(pattern[i]==pattern[len]){            
            len++;
            lps[i] = len; 
            cout << lps[i] << " ";
            i++;
        } else {
            if(len!=0){
                len = lps[len-1];
            } else {
                lps[i] = 0;
                cout << lps[i] << " ";
                i++;
            }
        }        
    }

    string s = "ABABDABACDABABCABAB";
    i = 0;
    int j = 0;
    while(i<s.size()){
        if(s[i]==pattern[j]){
            i++;
            j++;
        }
        if(j==pattern.size()){
            cout << "Matched at " << i-j ;
            j = lps[j-1];
        } else if(i<s.size() && s[i]!=pattern[j]){
            if(j!=0){
                j = lps[j-1];
            } else 
            {
                i++;
            }
        }
    }
    cout << "Exited";
    return 0;
}