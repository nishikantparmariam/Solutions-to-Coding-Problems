#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        string S;cin>>S;
        string T;cin>>T;
        if(S.size()==1){
            cout << "B" << endl;
        } else {
            unordered_map<char,int> MAPS;
            unordered_map<char,int> MAPT;
            bool A_win = false;
            bool inSnotinT = false;
            for(char c:T){
                MAPT[c]++;                                
            }                 
            for(char c:S){
                MAPS[c]++;   
                if(MAPT[c]==0) inSnotinT = true;                  
            }              
            for(auto it=MAPS.begin();it!=MAPS.end();it++){
                if(it->second>=2){
                    if(MAPT[it->first]==0){
                        A_win = true;
                    }
                }
            }

            bool temp = true;
            for(auto it=MAPT.begin();it!=MAPT.end();it++){
                if(MAPS[it->first]==0) temp = false;
            }       

            if(temp&inSnotinT) A_win = true;

            if(A_win) cout << "A" << endl;
            else cout << "B" << endl;       
        }

    }
    return 0;
}

            


  // bac          caa


//sdfddd      aaabbaa





