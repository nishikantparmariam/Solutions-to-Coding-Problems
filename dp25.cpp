#include <bits/stdc++.h>
using namespace std;

bool isPred(string w1,string w2){
    int n1 = w1.size();
    int n2 = w2.size();
    if(n2==n1+1){
        bool shifted = false;
        int i=0;
        int j=0;
        while(i<n1){
            if(w1[i]!=w2[j]){
                if(shifted) return false;
                shifted = true;
                j++;
                
            } else {                
                i++;
                j++;
            }   
        }        
        return true;
    }
    return false;
    
}
bool comp(string &s1, string &s2){
    return s1.size() < s2.size();
}
int longestStrChain(vector<string>& words) {
    int N = words.size();
    sort(words.begin(), words.end(), comp);
    int lsc[N];
    for(int i=0;i<N;i++) lsc[i] = 1;
    int ans = 1;
    cout << lsc[0] << " ";
    for(int i=1;i<N;i++){
        int child = i;
        for(int j=0;j<i;j++){            
            if(isPred(words[j],words[i])){                
                if(lsc[i]<lsc[j]+1){
                    lsc[i] = lsc[j]+1;
                    child = j;            
                }
            }
        }  
        cout << "(" << words[i] << ","<< lsc[i] << "," << child << ") \n";              
        ans = max(ans, lsc[i]);
    }

    return ans;
}

int main(){    
    vector<string> words = {"ksqvsyq","ks","kss","czvh","zczpzvdhx","zczpzvh","zczpzvhx","zcpzvh","zczvh","gr","grukmj","ksqvsq","gruj","kssq","ksqsq","grukkmj","grukj","zczpzfvdhx","gru"};
    cout << longestStrChain(words) << endl;
    return 0;
}