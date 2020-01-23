#include <iostream>
#include <set>
using namespace std;


int main(){
    long long int N;
    cin >> N;
    long long int arr[N];
    for(long long int i = 0; i<N; i++) cin >> arr[i];
    long long int ans[N];
    for(long long int i = 1; i<=N; i++){        
        long long int maximum = -1;
        multiset<long long int> pq;
        for(long long int j = 0; j<=N-i;j++){
            long long int minimum = 9999999999;
            if(j==0){
                for(long long int k = j; k<j+i; k++){
                    pq.insert(arr[k]);          
                    minimum = *pq.begin();      
                }
            } else {
                long long int going_ele = arr[j-1];
                long long int comming_ele = arr[j-1+i];
                pq.erase(pq.lower_bound(going_ele));
                pq.insert(comming_ele);                
            }                             
            maximum = max(maximum, *pq.begin());
        }
        ans[i-1] = maximum;
    }

    for(long long int i = 0; i<N; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}