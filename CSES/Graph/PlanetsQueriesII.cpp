#include<bits/stdc++.h>
using namespace std;
void dfs_f(int src, 
    vector<bool> &vis, 
    vector<bool> &pvis, 
    vector<vector<int>> &t, 
    vector<vector<int>> &cycle, 
    vector<int> &d,
    vector<int> &cyc_pos,
    vector<int> &cyc_id)
{
    vis[src] = true;
    pvis[src] = true;
    if(!vis[t[0][src]]){
        dfs_f(t[0][src],vis,pvis,t,cycle,d,cyc_pos,cyc_id);
    }
    else if(pvis[t[0][src]]){
        vector<int> c;
        c.push_back(t[0][src]);
        while(c.back()!=src){
            c.push_back(t[0][c.back()]);
        }
        int m = cycle.size();
        int i =0;
        for(auto x : c){
            d[x] = 0;
            cyc_id[x] = m;
            cyc_pos[x] = i;
            i++;
        }
        cycle.push_back(c);
        return;
    }
    return;
}
void dfs_a(int src,
    vector<vector<int>> &t,
    vector<int> &d,
    vector<int> &cyc_pos,
    vector<int> &cyc_id)
{
    if(d[t[0][src]] == -1){
        dfs_a(t[0][src],t,d,cyc_pos,cyc_id);
    }
    d[src] = 1 + d[t[0][src]];
    cyc_id[src]=cyc_id[t[0][src]];
    cyc_pos[src]=cyc_pos[t[0][src]];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<vector<int>> t(32,vector<int> (n));
    for(int i=0; i<n; i++){
        cin>>t[0][i];
        t[0][i]--;
    }
    for(int r = 1; r<32; r++){
        for(int i=0; i<n; i++){
            t[r][i] = t[r-1][t[r-1][i]];
        }
    }// fine upto here
    vector<int> d(n,-1);
    vector<int> cycle_id(n,-1);
    vector<int> cycle_pos(n,-1);
    vector<bool> vis(n,false);
    vector<vector<int>> cycle;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            vector<bool> pvis(n,false);
            dfs_f(i,vis,pvis,t,cycle,d,cycle_pos,cycle_id);
        }
    }
    for(int i=0; i<n; i++){
        if(d[i] == -1){
            dfs_a(i,t,d,cycle_pos,cycle_id);
        }
    } // fine.
    int a,b;
    while(q--){
        cin>>a>>b;
        a--;b--;
        int ans  = -1;
        if(cycle_id[a] == cycle_id[b]){
            if(cycle_pos[a] == cycle_pos[b]){
                int c = a;
                int k = d[a] - d[b];
                int x = 0;
                while(k>0){
                    if(k&1){
                        c = t[x][c];
                    }
                    k>>=1;
                    x++;
                }
                if(c == b) ans = d[a] - d[b];
            }
            else{
                if(d[b] == 0){
                    ans = d[a];
                    int g = cycle_pos[b] - cycle_pos[a];
                    if(g < 0) g += (int) cycle[cycle_id[a]].size();
                    ans +=g;
                }
            }
        }
        cout<<ans<<"\n";
    }
}