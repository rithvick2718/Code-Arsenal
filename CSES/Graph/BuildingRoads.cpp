#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n);
    int u,v;
    vector<bool> visited(n,false);
    vector<int> components;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    queue<int> q;
    int temp;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            components.push_back(i);
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                temp = q.front();
                q.pop();
                for(auto w : graph[temp]){
                    if(!visited[w]){
                        visited[w] = true;
                        q.push(w);
                    }
                }
            }
        }
    }
    temp = components.size();
    cout<<temp-1<<"\n";
    for(int i=0; i+1<temp; i++){
        cout<<components[i]+1<<" "<<components[i+1]+1<<"\n";
    }
}