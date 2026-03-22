#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:    
    void dfs(vector<vector<int>> &edges, vector<int> &ans, int source){
        // cout<<"dfs called on "<<source<<"\n";
        ans[source] = 1;
        // cout<<"ans["<<source<<"] is set "<<ans[source]<<"\n";
        for(auto node : edges[source]){
            // cout<<node<<" is selected \n";
            if(ans[node] == -1){
                dfs(edges,ans,node);
                ans[source] += ans[node];
                // cout<<"ans["<<source<<"] is set "<<ans[source]<< "by adding "<<ans[node]<<"\n";
            }
        }
        // cout<<"dfs on "<<source<<" is exited \n";
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> edges(n);
        for(int u = 0; u < n; u++){
            for(int v = u + 1; v < n; v++){
                long long dx = (long long)(bombs[u][0] - bombs[v][0]);
                long long dy = (long long)(bombs[u][1] - bombs[v][1]);
                long long d2 = dx*dx + dy*dy;
                long long ru = (long long) bombs[u][2];
                long long rv = (long long) bombs[v][2];
                if(ru*ru >= d2) edges[u].push_back(v);
                if(rv*rv >= d2) edges[v].push_back(u);
            }
        } // The graph is made! This is a directed graph.
        // My idea : Make a condenstation graph and store the number of elements in each node. //O(n+m)
        // Then just apply dfs on the condenstation graph and use dfs[u] = size[u] + sum dfs[v] where (u,v) is an edge of the DAG. (O(edges of condensation graph))
        // take the max of this dfs array
        int mx = -1;
        vector<int> ans(n,-1);
        for(int i=0; i<n; i++){
            dfs(edges,ans,i);
            mx = max(ans[i],mx);
            for(int j = 0; j<n; j++) ans[j] = -1;
        }
        return mx;
    }
};