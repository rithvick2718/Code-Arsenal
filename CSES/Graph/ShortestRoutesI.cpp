#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> dijasktra(const vector< vector< pair< int , ll > > > &edges, int src){
    int vertices = edges.size();
    vector<ll> distance(vertices,LLONG_MAX); // yeah we store the distances here
    set<pair<ll,int>> S; // distance of u, u
    int u,v;
    ll w;
    distance[src] = 0;
    S.insert({0,src});
    while(!S.empty()){
        u = S.begin()->second;
        S.erase(S.begin());
        for(auto it : edges[u]){
            v = it.first;
            w = it.second;
            if(distance[v] > distance[u] + w){
                if(distance[v] != LLONG_MAX){
                    S.erase({distance[v],v});
                }
                distance[v] = distance[u] + w;
                S.insert({distance[v],v});
            }
        }
    }
    return distance;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector< vector< pair< int,ll > > > edges(n);
    int u,v;
    ll w;
    for(int i=0; i<m; i++){
        cin>>u>>v>>w;
        edges[u-1].push_back({v-1,w});
    }
    vector<ll> ans = dijasktra(edges,0);
    for(auto x : ans) cout<<x<<" ";
}