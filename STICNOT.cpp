#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        long long int N;
        cin >> N;
        pair<long long int,vector<pair<long long int, long long int>>> adjList[N];
        /* 
        
            0:ui: pair.first = ai, pair.second  = <vi,bi>, <vi,bi>, <>
            1:
            2:
            3:

        */
        long long int ui;
        long long int vi;
        long long int bi;
        for(long long int i = 1; i<N; i++){            
            cin >> ui >> vi >> bi;
            ui--;vi--;
            (adjList[ui].second).push_back(make_pair(vi, bi));
            (adjList[vi].second).push_back(make_pair(ui, bi));            
        }
        long long int ai;
        for(long long int i = 0; i<N; i++){
            cin >> ai;
            adjList[i].first = ai;
        }   
        //cout << "Working " << endl;
        /*for(long long int i = 0; i<N; i++){
            
            cout << adjList[i].first << ": " ;
            for(pair<long long int, long long int>x : adjList[i].second){
                cout << "(" << x.first  << "," << x.second <<") \t";
            }
            cout << endl;
        } */
    }
    return 0;
}