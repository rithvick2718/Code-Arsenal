#include<bits/stdc++.h>
using namespace std;
#define INF 100'000'000
void topo_sort(int u, vector<bool> &visited, const vector<vector<int>> &edges, stack<int> &S){
    visited[u] = true;
    for(auto v : edges[u]){
        if(!visited[v]){
            topo_sort(v,visited,edges,S);
        }
    }
    S.push(u);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,u,v;
    stack<int> order;
    cin>>n>>m;
    vector<bool> visited(n,false);
    vector<int> distance(n,INF);
    vector<int> parent(n,-1);
    vector<vector<int>> edges(n);
    distance[0] = 0;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        edges[u-1].push_back(v-1);
    }
    for(int i=0; i<n; i++){
        if(!visited[i]){
            topo_sort(i,visited,edges,order);
        }
    }
    while(!order.empty()){ // making better paths and distances
        u = order.top();
        order.pop();
        for(auto v : edges[u]){
            if(distance[u]!=INF && distance[v] > distance[u] - 1){
                distance[v] = distance[u] - 1;
                parent[v] = u;
            }
        }
    }
    if(distance[n-1] != INF){
        order.push(n-1);
        while(parent[order.top()] != -1){
            order.push(parent[order.top()]);
        }
        cout<<1-distance[n-1]<<"\n";
        while(!order.empty()){
            cout<<order.top() + 1<<" ";
            order.pop();
        }
    }
    else cout<<"IMPOSSIBLE";
}