#include<bits/stdc++.h>
using namespace std;
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int T;cin>>T;
	while(T--){
	    long long int N;long long int K;
	    cin>>N;cin>>K;
	    long long int arr[N];
	    for(long long int i=0;i<N;i++) cin>>arr[i];
	    deque<long long int> Q;
	    int max_ans = INT_MIN;
	    for(int i=0;i<K;i++){
	        while(Q.size()>0){
	            if(arr[Q.back()] <= arr[i]){
	                Q.pop_back();
	            } else {
	                break;
	            }
	        }
	        Q.push_back(i);
	    }
	    
	    cout << arr[Q.front()] << " ";
	    
	    for(int i=K;i<N;i++){
	        if(Q.front()==i-K){
	            Q.pop_front();
	        }
	        
	        while(Q.size()>0){
	            if(arr[Q.back()] <= arr[i]){
	                Q.pop_back();
	            } else {
	                break;
	            }
	        }
	        Q.push_back(i);
	        
	        cout << arr[Q.front()] << " ";
	        
	    }
	    
	    cout <<  endl;
	}
	return 0;
}