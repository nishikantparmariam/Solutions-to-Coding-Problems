#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int T;cin>>T;
    while(T--){
        long long int C;
        long long int D;
        long long int L;
        cin>>C;cin>>D;cin>>L;
        if(L%4!=0 || L>4*(C+D)){
            cout << "no" << endl;
        } else {
            set<long long int> possibleLegs;
            possibleLegs.insert((C+D)*4);
            long long int prev_legs = (C+D)*4;        
            if(C<D){
                while(C--){
                    prev_legs-=4;
                    possibleLegs.insert(prev_legs);
                }
            } else {
                C = min(2*D, C);
                while(C--){
                    prev_legs-=4;
                    possibleLegs.insert(prev_legs);
                }
            }

            auto it = possibleLegs.find(L);
            if(it!=possibleLegs.end()){
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }                
    }
    return 0;
}