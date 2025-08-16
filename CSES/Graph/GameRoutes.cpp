#include<bits/stdc++.h>
#define MOD 1'000'000'007
using namespace std;
using ll = long long;
void topo_sort(int u, vector<bool> &vis, const vector<vector<int>> &edges, stack<int> &S){
    vis[u] = true;
    for(int v : edges[u]){
        if(!vis[v]){
            topo_sort(v,vis,edges,S);
        }
    }
    S.push(u);
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int u,v;
    vector<vector<int>> edges(n);
    vector<bool> vis(n,false);
    stack<int> Order;
    vector<ll> ways(n,0LL);
    ways[0] = 1LL;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        edges[u-1].push_back(v-1);
    }
    for(int i=0; i<n; i++){
        if(!vis[i]){
            topo_sort(i,vis,edges,Order);
        }
    }
    while(Order.top() != 0 && !Order.empty()){
        Order.pop();
    }
    while(!Order.empty()){
        u = Order.top();
        Order.pop();
        for(auto w : edges[u]){
            ways[w] = (ways[u] + ways[w]) % MOD;
        }
    }
    cout<<ways[n-1];
}