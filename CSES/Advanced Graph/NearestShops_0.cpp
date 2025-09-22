#include<bits/stdc++.h>
using namespace std;
#define INF 1'000'000'000
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> edges(n);
    vector<int> d(n,-1);
    vector<int> anime_cities(k); //anime_cities
    vector<int> cac(n,-1);
    queue<int> q;
    for(int i=0; i<k; i++){
        cin>>anime_cities[i];
        anime_cities[i]--;
        cac[anime_cities[i]] = anime_cities[i];
        q.push(anime_cities[i]);
        d[anime_cities[i]] = 0;
    } // taking anime cities
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    } // taking edges
    // Now Multi-source BFS to get the shortest distance to all the non anime cities
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v : edges[u]){
            if(d[v] == -1){
                cac[v] = cac[u];
                d[v] = 1 + d[u];
                q.push(v);
            }
        }
    } // done with multi-source bfs
    // for(int i=0; i<k; i++){
    //     d[anime_cities[i]] = INF;
    // }
    vector<int> nd(n,INF);
    for(int u=0; u<n; u++){
        for(auto v : edges[u]){
            if(cac[u]!=cac[v] && cac[u] != -1 && cac[v] != -1){
                int x,y;
                x = cac[u];
                y = cac[v];
                int t = 1 + d[u] + d[v];
                nd[x] = min(t,nd[x]);
                nd[y] = min(t,nd[y]);
            }
        }
    } // running through the edges
    for(auto x : anime_cities){
        if(nd[x] == INF) d[x] = -1;
        else d[x] = nd[x];
    }
    for(auto x : d){
        cout<<x<<" ";
    }
}