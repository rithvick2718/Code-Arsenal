#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<set<int>> edges(n);
        int v;
        int u=0;
        for(; u<n; u++){
            cin>>v;
            v--;
            edges[u].insert(v);
            edges[v].insert(u);
        }
        vector<bool> vis(n,false);
        int components=0, complete_components=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                components++;
                vis[i] = true;
                queue<int> q;
                q.push(i);
                bool is_complete = true;
                while(!q.empty()){
                    u = q.front();
                    is_complete&=(edges[u].size() == 2);
                    q.pop();
                    for(int node : edges[u]){
                        if(!vis[node]){
                            vis[node] = true;
                            q.push(node);
                        }
                    }
                }
                if(is_complete) complete_components++;
            }
        }
        if(complete_components<components) complete_components++;
        cout<<complete_components<<" "<<components<<"\n";
    }
}