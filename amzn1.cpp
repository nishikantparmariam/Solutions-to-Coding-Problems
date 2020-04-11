#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool cmp(const pair<string, int> &p1, const pair<string, int> &p2){
    if(p1.second==p2.second){
        return p1.first < p2.first;
    } else {
        return p1.second > p2.second; 
    }
}

void dfs(int v, vector<bool> &visited,
    vector<int> &discovery,
    vector<int> &low,
    vector<int> &parent,
    vector<bool> &isCritical, vector<int> adjList[], int *time){
        int num_child = 0;
        (*time)++;
        visited[v] = true;
        discovery[v] = time;
        low[v] = time;
        for(int u:adjList[v]){
            if(!visited[u]){
                num_child++;
                parent[u] = v;
                dfs(u,visited,discovery,low,parent,isCritical,adjList,time);
                low[u] = min(low[u], low[v]);

                if(parent[u]==-1 && num_child > 1){
                    isCritical[u]  = true;
                }

                if(parent[u]!=-1 &&  discovery[u]){
                    isCritical[u] = true;
                }
            } else if(v!=parent[u]){
                low[u] = min(low[u], discovery[v]);
            }
        }

    }

int main(){
    unordered_map<string, int> MAP;
    for(string S:reviews){
        transform(S.begin(), S.end(), S.begin(), ::tolower); 
        for(string S2:competitors){ 
            transform(S.begin(), S.end(), S.begin(), ::tolower); 
            if(S.find(S2)!=string::npos){
                MAP[S2]++;
            
            }
        }
    }

    vector<pair<string, int>> V;
    for(auto it=MAP.begin(); it!=MAP.end(); it++){
        vec.push_back(make_pair(it->first, it->second));
    }

    sort(V.begin(), V.end(), cmp);

    vector<string> ans;

    for(int i=0;i<min((int)ans.size(), topN);i++){
        ans.push_back(V[i]);
    }



    vector<int> adjList[numRouters];
    for(int i=0;i<numLinks;i++){
        int v1 = links[i].first-1;
        int v2 = links[i].second-1;
        if(v1!=v2){
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);   
        }        
    }

    vector<bool> visited(numRouters, false);
    vector<int> discovery(numRooters, 0);
    vector<int> low(numRooters, 0);
    vector<int> parent(numRooters, -1);
    vector<bool> isCritical(numRooters, false);

    dfs(0,visited,discovery,low,parent,isCritical,adjList,&time);
    vector<int> res;
    for(int i=0;i<numRouters;i++){
        if()
    }

    return 0;
}

