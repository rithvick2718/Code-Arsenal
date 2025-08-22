#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pil = pair<int,ll>;
using pli = pair<ll,int>;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<pil> edges[n];
    vector<bool> vis(n,false);
    priority_queue<pli, vector<pli>, greater<pli>> q;
    int a,b; ll c;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        a--; b--;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
    ll ans = 0LL;
    int ed = 0;
    q.push({0,0});
    while(!q.empty()){
        auto [w , u] = q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        ans += w;
        ed++;
        for(auto [v , x] : edges[u]){
            if(!vis[v]){
                q.push({x,v});
            }
        }
    }
    if(ed == n) cout<<ans;
    else cout<<"IMPOSSIBLE";
}