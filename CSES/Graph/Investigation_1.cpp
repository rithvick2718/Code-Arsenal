#include<bits/stdc++.h>
#define INF 100'000'000'000'000'000LL
#define MOD 1'000'000'007
using namespace std;
using ll = long long;
using pil = pair<int,ll>;
using pli = pair<ll,int>;
tuple<ll,ll,int,int> dijkstra(int src, int end,const vector<vector<pil>> &edges){
    int n = edges.size();
    vector<tuple<ll,ll,int,int>> distance(n,{INF,0LL,INF,0LL});
    distance[src] = {0,1,0,0};
    set<pli> S;
    S.insert({0,src});
    while(!S.empty()){
        auto [d, u] = *S.begin();
        S.erase(S.begin());
        for(auto [v , w] : edges[u]){
            if(get<0>(distance[v]) > d + w){
                if(get<0>(distance[v]) != INF) S.erase({get<0>(distance[v]),v});
                get<0>(distance[v]) = d + w; // distance
                get<1>(distance[v]) = get<1>(distance[u]); // number of routes
                get<2>(distance[v]) = get<2>(distance[u]) + 1; // minimum flights in the routes
                get<3>(distance[v]) = get<3>(distance[u]) + 1; // maximum flights in the routes
                S.insert({get<0>(distance[v]),v});
            }
            else if(get<0>(distance[v]) == d + w){
                get<1>(distance[v]) =( get<1>(distance[v]) + get<1>(distance[u]) )%MOD; // number of routes
                get<2>(distance[v]) = min(get<2>(distance[v]), get<2>(distance[u]) + 1); // minimum flights in the routes
                get<3>(distance[v]) = max(get<3>(distance[v]), get<3>(distance[u]) + 1); // maximum flights in the routes
            }
        }
    }
    return distance[end];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int a,b;
    ll c;
    vector<vector<pil>> edges(n);
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        edges[a-1].push_back({b-1,c});
    }// collected edges
    tuple<ll,ll,int,int> ans = dijkstra(0, n-1, edges);
    cout<<get<0>(ans)<<" "<<get<1>(ans)<<" "<<get<2>(ans)<<" "<<get<3>(ans);
}