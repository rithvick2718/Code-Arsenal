#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 100'000'000'000'000LL
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<ll>> edges; // stored roughly, not in adjaceny list
    int u,v,w;
    for(int i=0; i<m; i++){
        cin>>u>>v>>w;
        edges.push_back({u-1,v-1,-w});
    }
    vector<ll> distance(n,INF);
    distance[0] = 0;
    for(int i =1; i<n; i++){
        for(auto edge : edges){
            u = edge[0];
            v = edge[1];
            w = edge[2];
            distance[v] = min(distance[v], distance[u] + w);
        }
    } // n-1 iterations of Flyod-Warshall
    queue<int> q;
    bool neg_cycle = false;
    vector<bool> visited(n,false);
    for(auto edge : edges){ // the n-th iteration
        u = edge[0];
        v = edge[1];
        w = edge[2];
        if(distance[v] > distance[u] + w){
            visited[u] = true;
            visited[v] = true;
            neg_cycle = true;
        }
    }
    if(!neg_cycle){
        cout<<-distance[n-1];
    }
    else{
        vector<vector<int>> adjlist(n);
        for(auto edge : edges){
            adjlist[edge[0]].push_back(edge[1]);
        }// got the adj list
        int temp;
        vector<bool> svisited(n,false); // can be visited by source
        svisited[0] = true;
        q.push(0);
        while(!q.empty()){
            temp = q.front();
            q.pop();
            for(auto node : adjlist[temp]){
                if(!svisited[node]){
                    svisited[node] = true;
                    q.push(node);
                }
            }
        }// bfs from source
        for(int i = 0; i<n; i++){
            visited[i] = visited[i] & svisited[i];
            if(visited[i]) q.push(i);
        }
        while(!q.empty()){
            temp = q.front();
            q.pop();
            for(auto node : adjlist[temp]){
                if(!visited[node]){
                    visited[node] = true;
                    q.push(node);
                }
            }
        }// multi-source bfs to nodes that can be visited by source and are in a negative cycle 
        if(!visited[n-1]) cout<<-distance[n-1];
        else cout<<-1;
    }
}