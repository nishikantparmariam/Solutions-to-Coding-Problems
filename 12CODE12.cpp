#include <bits/stdc++.h>
using namespace std;

struct Node {
    int start;
    int end;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;int Q;
    cin>>N;cin>>Q;
    int arr[N];
    for(int i=0;i<N;i++) cin>>arr[i];
    vector<struct Node *> map(N, NULL);
    for(int i=0;i<N;i++){
        if(i>0){
            if(arr[i]==arr[i-1]){
                map[i] = map[i-1];
                map[i]->end = i;
            } else {
                struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
                map[i] = newNode;
                map[i]->start = i;
                map[i]->end = i;
            }
        } else {
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
            map[i] = newNode;
            map[i]->start = i;
            map[i]->end = i;
        }        
    }

    
    while(Q--){
        int L;int R;int m;
        cin>>L;cin>>R;cin>>m;
        L--;R--;        
        int mid = L+(R-L)/2;
        int s = max(map[mid]->start, L);
        int e = min(map[mid]->end, R);
        if((e-s+1)>=m){
            cout << arr[mid] << endl;
        } else {
            cout << -1 << endl;
        }                   
    }
    return 0;
}