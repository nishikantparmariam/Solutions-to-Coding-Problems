#include <bits/stdc++.h>
using namespace std;

int power(int x, int y){
    int res = 1;
    while(y>0){
        if(y & 1) res*=x;
        y = y>>1;        
        x = x*x;                
    }
    cout << res << " ";    
}

int power(int x, int y){
    int res = 1;
    while(y>0){
        if(y & 1) res = res*x;
        y = y>>1;
        x = x*x;
    }
    return res;
}

int main(){
    cout << power(2, 3);
    return 0;
}