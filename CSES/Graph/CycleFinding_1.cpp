#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int a,b;
    ll c;
    vector<tuple<int,int,ll>> edges(m);
    vector<ll> distance(n,0);
    vector<int> parent(n,-1);
    deque<int> cycle;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        edges[i] = {a-1,b-1,c};
    }
    for(int run = 1; run <= n; run++){
        for(auto [u, v, w] : edges){
            if(distance[v] > distance[u] + w){
                parent[v] = u;
                if(run == n){
                    cycle.push_back(v);
                    cycle.push_back(u);
                    break;
                }
                distance[v] = distance[u] + w;
            }
        }
    }
    if(cycle.empty()) cout<<"NO";
    else{
        cout<<"YES\n";
        vector<bool> visit(n,false);
        visit[cycle.front()] = true;
        visit[cycle.back()] = true;
        while(cycle.front() != cycle.back() && parent[cycle.back()] != -1){
            cycle.push_back(parent[cycle.back()]);
            if(visit[cycle.back()])
                break;
            visit[cycle.back()] = true;
        }
        while(cycle.front()!=cycle.back() && !cycle.empty()){
            cycle.pop_front();
        }
        reverse(cycle.begin(),cycle.end());
        for(auto c : cycle){
            cout<<c+1<<" ";
        }
    }
}