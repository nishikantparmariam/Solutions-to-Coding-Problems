#include <bits/stdc++.h> 
#include <iostream>
#include <cmath>
using namespace std;
#define mod 1000000007

long long int myFunction(int i, int zero_A, int zero_B, int one_A, int one_B, int N){
    if(i==N) return 1;
    long long int ans1 = 0;
    //1 in XOR    
    //0 in A
    if(zero_A!=0 && one_B!=0){                
        ans1+=(((zero_A*one_B)%mod)*(myFunction(i+1, zero_A-1,zero_B,one_A,one_B-1,N)%mod))%mod;

    }
    //1 in A
    if(zero_B!=0 && one_A!=0){
        ans1+=(((zero_B*one_A)%mod)*(myFunction(i+1, zero_A,zero_B-1,one_A-1,one_B,N)%mod))%mod;                
    }


    long long int ans2 = 0;

    //0 in XOR    
    //0 in A
    if(zero_A!=0 && zero_B!=0){   
             
        ans2+=(((zero_A*zero_B)%mod)*(myFunction(i+1, zero_A-1,zero_B-1,one_A,one_B,N)%mod))%mod;       
    }
    //1 in A
    if(one_A!=0 && one_B!=0){             
        ans2+=(((one_A*one_B)%mod)*(myFunction(i+1, zero_A,zero_B,one_A-1,one_B-1,N)%mod))%mod;    
    }    
    return (ans1+ans2)%mod;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin >> N;
        string A, B;
        cin >> A;
        cin >> B;

        int zero_A = count(A.begin(), A.end(), '0');
        int zero_B = count(A.begin(), A.end(), '0');            
        long long ans = myFunction(0,zero_A,zero_B,N-zero_A,N-zero_B,N);
        cout << ans << endl;
    }
    return 0;
}