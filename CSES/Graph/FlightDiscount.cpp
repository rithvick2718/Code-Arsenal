#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 100'000'000'000'000'000LL
vector<ll> dijkstra(const vector< vector<pair<int,ll>> > &edges, int src){
    int n = edges.size();
    vector<ll> distance(n,INF);
    distance[src] = 0;
    set<pair<ll,int>> S;
    S.insert({0,src});
    int u,v;
    ll w;
    while(!S.empty()){
        u = S.begin()->second;
        S.erase(S.begin());
        for(auto p : edges[u]){
            v = p.first;
            w = p.second;
            if(distance[v] > distance[u] + w){
                S.erase({distance[v],v});
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
    int u,v;
    ll w;
    cin>>n>>m;
    vector< vector<pair<int,ll>> > edges(n);
    vector< vector<pair<int,ll>> > redges(n);
    for(int i=0; i<m; i++){
        cin>>u>>v>>w;
        edges[u-1].push_back({v-1,w});
        redges[v-1].push_back({u-1,w});
    }
    vector<ll> distance_0 = dijkstra(edges, 0);
    vector<ll> distance_n = dijkstra(redges, n-1);
    ll ans = INF;
    for(u = 0; u<n; u++){
        for(auto p : edges[u]){
            v = p.first;
            w = p.second;
            ans = min(ans, distance_0[u] + w/2 + distance_n[v]);
        }
    }
    cout<<ans;
}