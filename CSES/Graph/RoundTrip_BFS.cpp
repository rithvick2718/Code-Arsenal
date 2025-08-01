#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<bool> visited(n,false);
    vector<int> edges[n];
    int x,y;
    for(int i =0; i<m; i++){
        cin>>x>>y;
        edges[x-1].push_back(y-1);
        edges[y-1].push_back(x-1);
    }
    vector<int> parent(n,-1);
    vector<bool> incycle(n,false);
    queue<int> q;
    deque<int> cycle;
    bool found = false;
    int u;
    for(int i=0; i<n && !found; i++){
        if(!visited[i]){
            q.push(i);
            visited[i] = true;
            while(!q.empty() && !found){
                u = q.front();
                q.pop();
                for(auto v : edges[u]){
                    if(!visited[v]){
                        visited[v] = true;
                        parent[v] = u;
                        q.push(v);
                    }
                    else if(v != parent[u]){
                        found = true;
                        cycle.push_back(parent[u]);
                        cycle.push_back(u);
                        cycle.push_back(v);
                        incycle[parent[u]] = true;
                        incycle[u] = true;
                        incycle[v] = true;
                        break;
                    }
                }
            }
        }
    }
    if(found){
        while(parent[cycle.front()]!=-1){
            cycle.push_front(parent[cycle.front()]);
            incycle[cycle.front()] = true;
        }
        while(!incycle[parent[cycle.back()]]){
            cycle.push_back(parent[cycle.back()]);
            incycle[cycle.back()] = true;
        }
        cycle.push_back(parent[cycle.back()]);
        while(cycle.front()!=cycle.back()){
            cycle.pop_front();
        }
        cout<<cycle.size()<<"\n";
        for(auto cy : cycle){
            cout<<cy+1<<" ";
        }
    }
    else cout<<"IMPOSSIBLE";
}