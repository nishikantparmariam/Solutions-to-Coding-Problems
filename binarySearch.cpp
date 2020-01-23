#include <bits/stdc++.h>
using namespace std;

int lowerbound_binarySearchUtil(int x, int arr[], int n, int s, int e){
    if(s>e) return -1;
    if(s==e){
        if(arr[s]==x) return s;
        return -1;
    }
    int mid = (s+e)/2;
    if(x<=arr[mid]) return lowerbound_binarySearchUtil(x, arr, n, s, mid);
    return lowerbound_binarySearchUtil(x, arr, n, mid+1, e);    
}


void binarySearch(int x, int arr[], int n){   
   cout << lowerbound_binarySearchUtil(x,arr,n,0,n-1) << endl;
}

int main(){
    int arr[] = {1,1,1,1,1,1};
    int n = sizeof(arr)/sizeof(int);
    binarySearch(1, arr, n);
    int s = 0;
    int e = n-1;
    int x = 1;
    int mid = -1;
    while(s<=e){
        if(s==e){
            mid = s;
            break;
        } else {
            if(e-s==2){
                if(arr[s]==arr[e]){
                    mid = e;
                    break;
                }
            }
            mid = (s+e)/2;
            if(arr[mid]<=x){
                s = mid;
            } else {
                e = mid;
            }                       
        }
    }

    cout << mid << endl;
    cout << 5/2 << endl;
    return 0;
}