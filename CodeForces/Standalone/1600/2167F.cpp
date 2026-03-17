#include<bits/stdc++.h>
using namespace std;
void dfs(const vector<vector<int>> &edges, int node, vector<bool> &visited, vector<int> &val){
    visited[node] = true;
    val[node] = 1;
    for(auto child : edges[node]){
        if(!visited[child]){
            dfs(edges,child,visited,val);
            val[node]+=val[child];
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> edges(n);
        vector<bool> visited(n,false);
        vector<int> val(n,0);
        int u,v;
        for(int i=0; i<n-1; i++){
            cin>>u>>v;
            u--;
            v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        // choose root as 0.
        dfs(edges,0,visited,val);
        long long ans = (long long) n;
        for(int node=0; node<n; node++){
            for(auto child : edges[node]){
                if(val[node] > val[child]){
                    if(n - val[child] >=k) ans+=(long long)(val[child]);
                }
            }
            if(val[node] >=k) ans+=(long long)(n-val[node]);
        }
        cout<<ans<<"\n";
    }
}