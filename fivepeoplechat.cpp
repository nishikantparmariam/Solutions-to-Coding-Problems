#include <bits/stdc++.h>
using namespace std;

int implies(int A, int B){
    //A->B
    if(A==1 && B==0) return 0;
    return 1;
}

int main(){
    for(int a=0;a<32;a++){
        int K = (a >> 0) & 1;
        int H = (a >> 1) & 1;
        int R = (a >> 2) & 1;
        int V = (a >> 3) & 1;
        int A = (a >> 4) & 1;        
        int f1 = K | H;
        int f2 = (R && !V) | (!R & V);
        int f3 = implies(A,R);
        int f4 = (V & K);
        int f5 = implies(H, A&K);
        int f = f1 & f2 & f3 & f4 & f5;
        if(f) {
            cout << A << " " << V << " " << R << " " << H << " " << K << endl;
        } 
    }    

}