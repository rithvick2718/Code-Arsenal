#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using tlii = tuple<ll,int,int>;
class DisjointSet{
    vector<int> parent,rank;
    public :
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    int findPar(int u){
        if(parent[u] == u) return u;
        return parent[u] = findPar(parent[u]);
    }
    void Union (int u, int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if(ulp_u != ulp_v){
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_u] = ulp_v;
                rank[ulp_v]++;
            }
        }
        return;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    DisjointSet DSU(n);
    priority_queue<tlii, vector<tlii>, greater<tlii> > q;
    int a,b; ll c;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        q.push({c,a,b});
    }
    ll ans = 0LL;
    int cnt = 0;
    while(!q.empty()){
        auto [w, u, v] = q.top();
        q.pop();
        if(DSU.findPar(u) != DSU.findPar(v)){
            ans += w;
            cnt++;
            DSU.Union(u,v);
        }
    }
    if(cnt == n-1) cout<<ans;
    else cout<<"IMPOSSIBLE";
}