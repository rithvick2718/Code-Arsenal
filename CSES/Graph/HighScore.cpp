#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 1'000'000'000'000'000LL
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<ll>> edges[n];
    ll u,v,w;
    for(int i=0; i<m; i++){
        cin>>u>>v>>w;
        edges[u-1].push_back({v-1,-w});
    }
    vector<ll> distance(n,INF);
    distance[0] = 0;
    for(int run = 1; run<n; run++){ // n-1 iterations
        for(int i = 0; i<n; i++){
            for(auto V : edges[i]){
                if(distance[i] != INF) distance[V[0]] = min(distance[V[0]], distance[i] + V[1]);
            }
        }
    }
    int in_neg = 0;
    vector<bool> in_neg_cycle(n,false);
    for(int i = 0; i<n; i++){
        for(auto V : edges[i]){
            if(distance[V[0]] >  distance[i] + V[1]){
                in_neg++;
                in_neg_cycle[i] = true;
                in_neg_cycle[V[0]] = true;
            }
        }
    }
    if(in_neg == 0) cout<<-distance[n-1];
    else{
        vector<bool> visited(n,false);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        int temp;
        while (!q.empty()){
            temp = q.front();
            q.pop();
            for(auto V : edges[temp]){
                if(!visited[V[0]]){
                    visited[V[0]] = true;
                    q.push(V[0]);
                }
            }
        }
        for(int i=0; i<n; i++){
            visited[i] = (in_neg_cycle[i]) & (visited[i]);
            if(visited[i]) q.push(i);
        }
        while (!q.empty()){
            temp = q.front();
            q.pop();
            for(auto V : edges[temp]){
                if(!visited[V[0]]){
                    visited[V[0]] = true;
                    q.push(V[0]);
                }
            }
        }
        if(visited[n-1]) cout<<-1;
        else cout<<-distance[n-1];
    }
}