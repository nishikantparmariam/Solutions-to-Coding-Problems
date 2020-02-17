#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void printAns(int i, int max_, deque<int> &Q){
    if(i==1){        
        for(auto it=Q.begin(); it!=Q.end(); it++){
            cout << (*it) << " ";
        }
        cout << "1 ";// << endl;        
    } else if(i==0) {
        for(auto it=Q.begin(); it!=Q.end(); it++){
            cout << (*it) << " ";
        }
        //cout << endl;       
    } else {
        for(int j=min(max_, i);j>=1;j--){ 
            Q.push_back(j);           
            printAns(i-j,j,Q);
            Q.pop_back();
        }
    }        
}

int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    int N;cin>>N;
        deque<int> Q;
	    printAns(N, N, Q);
	    cout << endl;
	}   
	return 0;
}