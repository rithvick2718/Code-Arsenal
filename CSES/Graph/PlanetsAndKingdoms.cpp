#include<bits/stdc++.h>
using namespace std;
void dfs(int src, vector<bool> &vis, const vector<vector<int>> &edges, stack<int> &st){
    vis[src] = true;
    for(auto node : edges[src]){
        if(!vis[node]){
            dfs(node,vis,edges,st);
        }
    }
    st.push(src);
    return;
}
void dfs(int src, vector<bool> &vis, const vector<vector<int>> &edges, vector<int> &T, int t){
    vis[src] = true;
    T[src] = t;
    for(auto node : edges[src]){
        if(!vis[node]){
            dfs(node,vis,edges,T,t);
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int a,b;
    vector<vector<int>> edges(n);
    vector<vector<int>> redges(n);
    vector<int> label(n,-1);
    vector<bool> vis(n,false);
    for(int i=0; i<m; i++){
        cin>>a>>b;
        a--; b--;
        edges[a].push_back(b);
    }
    stack<int> st;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i,vis,edges,st);
        }
    }
    for(int i=0; i<n; i++){
        vis[i] = false;
        for(auto j : edges[i]){
            redges[j].push_back(i);
        }
    }
    int val = 0;
    while(!st.empty()){
        auto u = st.top();
        st.pop();
        if(!vis[u]){
            dfs(u,vis,redges,label,val + 1);
            val++;
        }
    }
    cout<<val<<"\n";
    for(auto x : label){
        cout<<x<<" ";
    }
}