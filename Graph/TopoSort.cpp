#include<bits/stdc++.h>
using namespace std;
stack<int> topo_sort(const vector<vector<int>> &edges){
    int n = edges.size();
    vector<bool> visited(n,false);
    stack<int> Order;
    stack<int> S;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            S.push(i);
            visited[i] = true;
            while(!S.empty()){
                int u = S.top();
                bool pushed = false;
                for(int v : edges[u]){
                    if(!visited[v]){
                        visited[v] = true;
                        S.push(v);
                        pushed = true;
                        break;
                    }
                }
                if(!pushed){
                    Order.push(u);
                    S.pop();
                }
            }
        }
    }
    return Order;
}
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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(n);
    int u,v;
    for(int i =0; i<m; i++){
        cin>>u>>v;
        edges[u].push_back(v);
    }
    stack<int> ans = topo_sort(edges);
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    cout<<"\n";
    vector<bool> visited(n,false);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            topo_sort(i,visited,edges,ans);
        }
    }
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
}