#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,a,b;
    cin>>n>>m;
    vector<vector<int>> dependency(n);
    vector<int> indegree(n,0);
    queue<int> q;
    vector<int> out;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        dependency[a-1].push_back(b-1);
        indegree[b-1]++;
    }// got the dependencies
    for(int i=0; i<n; i++){
        if(indegree[i] == 0) q.push(i);
    }
    int u;
    while(!q.empty()){
        u = q.front();
        q.pop();
        out.push_back(u);
        for(auto v : dependency[u]){
            indegree[v]--;
            if(indegree[v] == 0) q.push(v);
        }
    }
    if((int) out.size() < n) cout<<"IMPOSSIBLE";
    else{
        for(auto t : out) cout<<t + 1<<" ";
    }
}