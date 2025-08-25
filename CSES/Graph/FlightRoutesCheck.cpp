#include<bits/stdc++.h>
using namespace std;
void dfs(int src,vector<bool> &vis, const vector<vector<int>> &edges, int &cnt){
    vis[src] = true;
    cnt++;
    for(auto node : edges[src]){
        if(!vis[node]) dfs(node,vis,edges,cnt);
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<bool> vis(n,false);
    vector<vector<int>> edges(n);
    vector<vector<int>> redges(n);
    stack<int> st;
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        a--;
        b--;
        edges[a].push_back(b);
        redges[b].push_back(a);
    }
    int cnt = 0;
    dfs(0,vis,edges,cnt);
    if(cnt == n){
        cnt = 0;
        vis.assign(n,false);
        dfs(0,vis,redges,cnt);
        if(cnt == n) cout<<"YES";
        else{
            int u = -1;
            for(int i=0; i<n; i++){
                if(!vis[i]){
                    u = i;
                    break;
                }
            }
            cout<<"NO\n"<<u+1<<" "<<1;
        }
    }
    else{
        int u = -1;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                u = i;
                break;
            }
        }
        cout<<"NO\n"<<1<<" "<<1+u;
    }
}