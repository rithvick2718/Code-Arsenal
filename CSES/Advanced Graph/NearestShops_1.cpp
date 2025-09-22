#include<bits/stdc++.h>
using namespace std;
#define INF 1'000'000'000
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int input,a,b,c; // I use this as temporary variables
    int n,m,k; // n -> cities, k -> anime cities, m -> roads
    cin>>n>>m>>k;
    vector<int> d(n,-1); // distances
    vector<int> nd(n,INF); // the alternate distances for anime cities
    vector<int> cac(n,-1); // closest anime city (can include itself)
    vector<vector<int>> edges(n);
    queue<int> q; // for multi-source bfs
    for(int i=0; i<k; i++){
        cin>>input;
        input--;
        cac[input] = input;
        d[input] = 0;
        q.push(input);
    } // getting all the anime cities
    for(int i=0; i<m; i++){
        cin>>a>>b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    } // got all the edges
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v : edges[u]){
            if(d[v] == -1){
                d[v] = 1 + d[u];
                cac[v] = cac[u];
                q.push(v);
            }
        }
    } // multi-source bfs
    for(int u =0; u<n; u++){
        for(auto v : edges[u]){
            if(cac[u] != cac[v] && cac[u] != -1 && cac[v] != -1){
                a = cac[u];
                b = cac[v];
                c = 1 + d[u] + d[v];
                nd[a] = min(nd[a],c);
                nd[b] = min(nd[b],c);
            }
        }
    } // I use all the edges and run the logic to get values for anime-cities
    for(int i = 0; i<n; i++){
        if(d[i] == 0){
            if(nd[i] == INF) d[i] = -1;
            else d[i] = nd[i];
        }
        cout<<d[i]<<" ";
    }
}