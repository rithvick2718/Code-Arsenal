#include<bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<bool> path_visited;
vector<vector<int>> edges;
vector<int> parent;
deque<int> cycle;
void dfs(int u){
    if(!cycle.empty()) return;
    visited[u] = true;
    path_visited[u] = true;
    for(auto v : edges[u]){
        if(!visited[v]){
            parent[v] = u;
            dfs(v);
        }
        else if(path_visited[v] && cycle.empty()){
            cycle.push_front(u);
            cycle.push_back(v);
            return;
        }
        if(!cycle.empty()) return;
    }
    path_visited[u] = false;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,u,v;
    cin>>n>>m;
    visited.assign(n,false);
    path_visited.assign(n,false);
    parent.assign(n,-1);
    edges.assign(n,vector<int>(0));
    for(int i = 0; i < m; i++){
        cin>>u>>v;
        edges[u-1].push_back(v-1);
    }
    for(int i =0; i<n && cycle.empty(); i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    if(cycle.empty()) cout<<"IMPOSSIBLE\n";
    else{
        while(cycle.front() != cycle.back()){
            cycle.push_front(parent[cycle.front()]);
        }
        cout<<cycle.size()<<"\n";
        for(auto x : cycle) cout<<x + 1<<" ";
    }
}