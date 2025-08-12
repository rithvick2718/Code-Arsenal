#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pil = pair<int,ll>;
#define INF 1'000'000'000'000'000LL

vector<ll> d;
vector<vector<pil>> edges;
deque<int> cycle;

void bellman_ford(){ // works multi source
    int n = d.size();
    vector<int> parent(n,-1);
    int u,v;
    ll w;
    for(int run = 1; run < n; run ++){ // n-1 iterations
        for(u=0; u<n; u++){
            for(auto edge : edges[u]){
                v = edge.first;
                w = edge.second;
                if(d[u]!=INF && d[v] > d[u] + w){
                    d[v] = d[u] + w;
                    parent[v] = u;
                }
            }
        }
    }
    for(u=0; u<n  && cycle.empty() ; u++){ // nth iteration
        for(auto edge : edges[u]){
            v = edge.first;
            w = edge.second;
            if(d[u] != INF && d[v] > d[u] + w){
                parent[v] = u;
                cycle.push_front(v);
                cycle.push_back(u);
                break;
            }
        }
    }
    if(!cycle.empty()){
        vector<bool> visit(n,false);
        visit[cycle.front()] = true;
        visit[cycle.back()] = true;
        while(cycle.size() < n+2 && cycle.back() != cycle.front()){
            cycle.push_back(parent[cycle.back()]);
            if(visit[cycle.back()]) break;
            visit[cycle.back()] = true;
        }
        while(cycle.front() != cycle.back() && !cycle.empty()){
            cycle.pop_front();
        }
    }
    reverse(cycle.begin(),cycle.end());
    return;
}

void bfs(){
    int n = edges.size();
    int u,v;
    queue<int> q;
    vector<bool> visited(n,false);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            d[i] = 0;
            visited[i] = true;
            q.push(i);
            while(!q.empty()){
                u = q.front();
                q.pop();
                for(auto p : edges[u]){
                    v = p.first;
                    if(!visited[v]){
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,u,v;
    ll w;
    cin>>n>>m;
    edges.assign(n,{});
    d.assign(n,INF);
    for(int i=0; i<m; i++){
        cin>>u>>v>>w;
        edges[u-1].push_back({v-1,w});
    }
    bfs();
    bellman_ford();
    if(cycle.empty()){
        cout<<"NO";
    }
    else{
        cout<<"YES\n";
        for(auto c : cycle){
            cout<<c+1<<" ";
        }
    }
}