#include <bits/stdc++.h>
using namespace std;

long long int fun(string &str) {
    long long int N = str.size();
    long long int ca = 0;
    long long int cb = 0;
    long long int cc = 0;
    for(long long int i=0;i<N;i++){
        if(str[i]=='a'){
            ca = 2*ca+1;
        } else if(str[i]=='b'){
            if(ca>0){
                cb = 2*cb+ca;
            }
        } else if(str[i]=='c'){
            if(cb>0){
                cc = 2*cc+cb;
            }
        }
        cout << ca << " " << cb << " " << cc << " | ";
    }
    //if(cc==0) return -1;
    return cc;
}

int fun2(string &str) {
    int a=0,b=0,c=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='a'){
            a=1+2*a;
        }
        else if(str[i]=='b'){
            b=2*b+a;
        }
        else if(str[i]=='c'){
            c=2*c+b;
        }
       
        cout << a << " " << b << " " << c << " | ";
    }
    return c;
    //code here
}

int main(){

    string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbccccccccccccccccaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc";    
    cout << fun(str) << endl;   
    cout << endl;
    cout << endl;
    cout << endl; 
    cout << fun2(str) << endl;    
    return 0;
}