#include<bits/stdc++.h>
using namespace std;
class DSU_Size{
    private :
    vector<int> parent;
    vector<int> size;
    public :
    DSU_Size(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    int findPar(int u){
        if(parent[u] == u) return u;
        parent[u] = findPar(parent[u]);
        return parent[u];
    }
    void join(int u, int v){
        int U = findPar(u);
        int V = findPar(v);
        if(U != V){
            if(size[U] >= size[V]){
                size[U]+=size[V];
                parent[V] = U;
            }
            else{
                size[V]+=size[U];
                parent[U] = V;
            }
        }
    }
    bool sameComponent(int u, int v){
        return (findPar(u) == findPar(v));
    }
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DSU_Size DSU(n);
        for(auto edge : edges){
            DSU.join(edge[0],edge[1]);
        }
        return DSU.sameComponent(source,destination);
    }
};