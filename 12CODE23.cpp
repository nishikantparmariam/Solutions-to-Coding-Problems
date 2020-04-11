#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        bool family[2][N];
        for(int i=0;i<N;i++){
            char c;cin>>c;
            if(c=='*') family[0][i] = true;
            else family[0][i] = false;
        }

        int walls = 0;
        bool make_horizontal = false;

        for(int i=0;i<N;i++){
            char c;cin>>c;
            if(c=='*') {
                family[1][i] = true;
                if(family[0][i]) make_horizontal = true;
            }
            else family[1][i] = false;
        }

        if(make_horizontal){
            walls++;
            bool pf0 = false;
            bool pf1 = false;
            for(int i=0;i<N;i++){
                if((family[0][i] && pf0) || (family[1][i] && pf1)) {
                    pf0 = family[0][i];
                    pf1 = family[1][i];
                    walls++;
                } else {
                    if(family[0][i]) pf0 = true;
                    if(family[1][i]) pf1 = true;
                }                                
            }

            cout << walls << endl;
        } else {            
            bool pf0 = false;
            bool pf1 = false;

            for(int i=0;i<N;i++){
                
                if(((family[0][i] || family[1][i]) && (pf0 || pf1))) {
                    pf0 = family[0][i];
                    pf1 = family[1][i];
                    walls++;
                } else {
                    if(family[0][i]) pf0 = true;
                    if(family[1][i]) pf1 = true;
                }               
            }

            int walls_2=1;
            pf0 = false;
            pf1 = false;

            for(int i=0;i<N;i++){                
                if((family[0][i] && pf0) || (family[1][i] && pf1)) {
                    pf0 = family[0][i];
                    pf1 = family[1][i];
                    walls_2++;
                } else {
                    if(family[0][i]) pf0 = true;
                    if(family[1][i]) pf1 = true;
                }               
            }

            cout << min(walls, walls_2) << endl;

        }
    }
    return 0;
}