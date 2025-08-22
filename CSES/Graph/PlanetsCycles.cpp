#include<bits/stdc++.h>
using namespace std;
void dfs(int src, vector<int> &teleport, vector<bool> &vis, vector<int> &d){
    vis[src] = true;
    if(vis[teleport[src]]){
        if(d[teleport[src]] != -1){
            d[src] = 1 + d[teleport[src]];
        }
        else{ // we have a cycle
            int size = 1;
            int nex = teleport[src];
            while(nex!=src){
                size++;
                nex = teleport[nex];
            }
            d[src] = size;
            nex = teleport[src];
            while(nex!=src){
                d[nex] = size;
                nex = teleport[nex];
            }
        }
    }
    else{
        dfs(teleport[src],teleport,vis,d);
        if(d[src] == -1) d[src] = 1 + d[teleport[src]];
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> teleport(n);
    vector<int> d(n,-1);
    vector<bool> vis(n,false);
    for(int i=0; i<n; i++){
        cin>>teleport[i];
        teleport[i]--;
    }
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i,teleport,vis,d);
        }
    }
    for(auto x : d){
        cout<<x<<" ";
    }
}