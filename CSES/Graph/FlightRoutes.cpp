#include<bits/stdc++.h>
#define INF 1'000'000'000'000'000'000LL
using namespace std;
using ll = long long;
using pil = pair<int,ll>;
using pli = pair<ll,int>;
vector<ll> dijkstra(int src,int tail, int k, const vector<vector<pil>> &edges){
    int n = edges.size();
    priority_queue<pli, vector<pli>, greater<pli> > q;
    vector<int> count(n,0);
    vector<ll> ans;
    q.push({0,src});
    while(!q.empty()){
        auto [d , u] = q.top();
        q.pop();
        count[u]++;
        if(count[u] > k){
            if(u == tail) return ans;
            continue;
        }
        if( u == tail){
            ans.push_back(d);
        }
        for(auto [v , w] : edges[u]){
            q.push({d+w,v});
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k,a,b;
    ll c;
    cin>>n>>m>>k;
    vector<vector<pil>> edges(n);
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        edges[a-1].push_back({b-1,c});
    }
    vector<ll> ans  = dijkstra(0,n-1,k,edges);
    for(auto x : ans){
        cout<<x<<" ";
    }
}