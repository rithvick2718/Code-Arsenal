#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    public :
    vector<int> parent,rank,size;
    int cmps;
    int mx =1;
    DisjointSet(int n){
        cmps = n;
        rank.resize(n+1,0);
        size.resize(n+1,1);
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
            cmps--;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v]+=size[ulp_u];
                mx = max(mx,size[ulp_v]);
            }
            else if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
                size[ulp_u]+=size[ulp_v];
                mx = max(mx,size[ulp_u]);
            }
            else{
                parent[ulp_u] = ulp_v;
                rank[ulp_v]++;
                size[ulp_v]+=size[ulp_u];
                mx = max(mx,size[ulp_v]);
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
    int u,v;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        DSU.Union(u,v);
        cout<<DSU.cmps<<" "<<DSU.mx<<"\n";
    }
}