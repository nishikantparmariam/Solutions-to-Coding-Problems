#include <bits/stdc++.h>
using namespace std;

bool areSameBSTs(int i1, int i2, int a[], int b[], int _min, int _max, int n){
    int j;
    int k;
    for(j=i1;j<n;j++){
        if(a[j]>_min && a[j]<_max){
            break;
        }
    }
    for(k=i2;k<n;k++){
        if(b[k]>_min && b[k]<_max){
            break;
        }
    }

    if(j==n && k==n) return true;
    if(a[j]!=b[k]) return false;
    if(j==n || k==n) return false;

    return areSameBSTs(j+1,k+1,a,b, a[j], _max,n) && areSameBSTs(j+1,k+1,a,b, _min, a[j],n);
}

int main(){
    int a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13};  
    int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13};

    int n1 = sizeof(a)/sizeof(int);
    int n2 = sizeof(b)/sizeof(int);
    if(areSameBSTs(0,0,a,b, -INT_MAX, INT_MAX, n1)) cout << "YES";
    else cout << "NO";
    return 0;
}