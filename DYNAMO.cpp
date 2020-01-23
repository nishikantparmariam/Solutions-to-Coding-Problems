#include <bits/stdc++.h>
using namespace std;

long long int _pow(long long int base, long long int power){
    long long int result = 1;
    while(power--){
        result = result*base;
    }
    return result;
}

int main(){    
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        long long int A;
        long long int B;
        long long int C;
        long long int D;
        long long int E;  
        long long int pow_N = _pow(10,N);      
        cin>>A;                
        cout << 2*(pow_N-1)+A+2 << flush;
        cin>>B;             
        cout<< pow_N-B << flush;
        cin>>D;        
        cout<< pow_N-D << flush;
        int one;
        cin>>one;
        if(one==-1){
            return 0;
        }

    }
    return 0;
}