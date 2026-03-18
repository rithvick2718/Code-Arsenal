#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size(); // we do not know how many unique variables are present
        unordered_map<string,int> mp;
        int curr = 0;
        for(int i=0; i<n; i++){
            if(mp.find(equations[i][0]) == mp.end()){
                mp[equations[i][0]] = curr;
                curr++;
            }
            if(mp.find(equations[i][1]) == mp.end()){
                mp[equations[i][1]] = curr;
                curr++;
            }
        }
        vector<vector<pair<int,double>>> edges(mp.size()); // edges[u] -> {v,multiplier to v}
        for(int i=0; i<n; i++){
            int u = mp[equations[i][0]];
            int v = mp[equations[i][1]];
            edges[u].push_back({v,1.00000/values[i]});
            edges[v].push_back({u,1.00000*values[i]});
        }
        // the graph logic
        int m = edges.size();
        vector<double> vals(m);
        vector<int> component_id(m,-1);
        vector<bool> visited(m,false);
        curr = 0;
        for(int i=0; i<m; i++){
            if(!visited[i]){
                component_id[i] = curr;
                queue<int> q;
                q.push(i);
                vals[i] = 1.00000;
                visited[i] = true;
                while(!q.empty()){
                    int u = q.front();
                    component_id[u] = curr;
                    q.pop();
                    for(auto [v,w] : edges[u]){
                        if(!visited[v]){
                            visited[v] = true;
                            q.push(v);
                            vals[v] = w * vals[u];
                        }
                    }
                }
                curr++;
            }
        }
        int Q = queries.size();
        vector<double> ans;
        for(int q=0; q<Q; q++){
            if(mp.find(queries[q][0]) == mp.end() || mp.find(queries[q][1]) == mp.end()){
                ans.push_back(-1.00000);
                continue;
            }
            int u = mp[queries[q][0]];
            int v = mp[queries[q][1]];
            if(component_id[u] == component_id[v]){
                ans.push_back(vals[u]/vals[v]);
            }
            else{
                ans.push_back(-1.00000);
            }
        }
        return ans;
    }
};