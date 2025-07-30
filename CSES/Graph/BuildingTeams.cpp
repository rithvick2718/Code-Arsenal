#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,u,v;
    cin>>n>>m;
    vector<int> edges[n];
    for(int i=0; i<m; i++){
        cin>>u>>v;
        edges[u-1].push_back(v-1);
        edges[v-1].push_back(u-1);
    }
    vector<int> visited(n,0); //0 means not visited.
    // basically I need to split this into a bipartite graph.
    bool pos = true;
    queue<int> q;
    for(int i = 0; i<n && pos; i++ ){
        if(visited[i] == 0){
            visited[i] = 1;
            q.push(i);
            while(!q.empty() && pos){
                u = q.front();
                q.pop();
                for(auto w : edges[u]){
                    if(visited[w] == 0){
                        if(visited[u] == 1) visited[w] = 2;
                        else if(visited[u] == 2) visited[w] = 1;
                        q.push(w);
                    }
                    else if (visited[w] == visited[u]){
                        pos = false;
                        break;
                    }
                }
            }
        }
    }
    if(pos){
        for(auto visit : visited){
            cout<<visit<<" ";
        }
    }
    else cout<<"IMPOSSIBLE";
}